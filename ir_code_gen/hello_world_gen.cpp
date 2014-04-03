#include "llvm/ADT/ArrayRef.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/IRBuilder.h"
#include <vector>
#include <string>

int main()
{
    llvm::LLVMContext &context = llvm::getGlobalContext();
    llvm::Module *module = new llvm::Module("hello_world", context);
    llvm::IRBuilder<> builder(context);

    // define main() as void
    llvm::FunctionType *funcType = llvm::FunctionType::get(builder.getVoidTy(), false);
    llvm::Function *mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", module);

    llvm::BasicBlock *entry = llvm::BasicBlock::Create(context, "entrypoint", mainFunc);
    builder.SetInsertPoint(entry);

    // define the 'hello world' string constant
    llvm::Value *helloWorld = builder.CreateGlobalStringPtr("Hello world!");

    // define the args to puts()
    std::vector<llvm::Type*> putsArgs;
    putsArgs.push_back(builder.getInt8Ty()->getPointerTo());
    llvm::ArrayRef<llvm::Type*> argsRef(putsArgs);

    llvm::FunctionType *putsType = llvm::FunctionType::get(builder.getInt32Ty(), // return type
                                                           argsRef,              // argument vector
                                                           false);               // no variable number of args

    llvm::Constant *putsFunc = module->getOrInsertFunction("puts", putsType);

    // call puts(hello_world)
    builder.CreateCall(putsFunc, helloWorld);
    builder.CreateRetVoid();

    module->dump();
}
