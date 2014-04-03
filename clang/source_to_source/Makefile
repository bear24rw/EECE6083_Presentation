CXX = clang++
CFLAGS = -fno-rtti

CLANGLIBS = \
  -lclangFrontendTool -lclangFrontend -lclangDriver \
  -lclangSerialization -lclangCodeGen -lclangParse \
  -lclangSema -lclangStaticAnalyzerFrontend \
  -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore \
  -lclangAnalysis -lclangARCMigrate -lclangRewriteCore -lclangRewriteFrontend \
  -lclangEdit -lclangAST -lclangLex -lclangBasic

all:
	$(CXX) main.cpp $(CFLAGS) -o main $(CLANGLIBS) `llvm-config --cxxflags --ldflags --libs`

osx:
	$(CXX) main.cpp $(CFLAGS) -o main -I`llvm-config --includedir` $(CLANGLIBS) `llvm-config --cxxflags --ldflags --libs`

clean:
	rm -rf main
