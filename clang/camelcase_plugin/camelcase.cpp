#include <iostream>
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"

using namespace clang;

namespace
{

class MyClassVisitor : public RecursiveASTVisitor<MyClassVisitor>
{
   private:
    ASTContext *context;

   public:
    void setContext(ASTContext &context)
    {
        this->context = &context;
    }

    bool VisitCXXMethodDecl(CXXMethodDecl *declaration)
    {
        StringRef name = declaration->getName();

        size_t underscorePos = name.find('_');
        if (underscorePos != StringRef::npos) {

            std::string tempName = name;
            tempName[0] = toUppercase(tempName[0]);

            while (underscorePos != StringRef::npos) {
                tempName[underscorePos + 1] = toUppercase(tempName[underscorePos + 1]);
                tempName.erase(underscorePos,1);
                underscorePos = tempName.find('_');
            }

            StringRef replacement(tempName);

            SourceLocation nameStart = declaration->getLocation();
            SourceLocation nameEnd = nameStart.getLocWithOffset(name.size());
            std::cout << "size: " << name.size() << "\n";

            FixItHint fixItHint =
                FixItHint::CreateReplacement(SourceRange(nameStart, nameEnd),
                                             replacement);

            DiagnosticsEngine &diagEngine = context->getDiagnostics();
            unsigned diagID =
                diagEngine.getCustomDiagID(DiagnosticsEngine::Error,
                                           "Method names must be CamelCase");
            SourceLocation location =
                declaration->getLocation().getLocWithOffset(underscorePos);
            diagEngine.Report(location, diagID).AddFixItHint(fixItHint);
        }

        return true;
    }
};

class MyConsumer : public ASTConsumer
{
   public:
    void HandleTranslationUnit(ASTContext &context)
    {
        visitor.setContext(context);
        visitor.TraverseDecl(context.getTranslationUnitDecl());
    }

   private:
    MyClassVisitor visitor;
};

class MyASTAction : public PluginASTAction
{
   public:
    virtual clang::ASTConsumer *CreateASTConsumer(CompilerInstance &Compiler,
                                                  llvm::StringRef InFile)
    {
        return new MyConsumer;
    }

    bool ParseArgs(const CompilerInstance &CI,
                   const std::vector<std::string> &args)
    {
        return true;
    }
};
}

static clang::FrontendPluginRegistry::Add<MyASTAction> X(
    "camelcase", "checks that method names are camelcase");

