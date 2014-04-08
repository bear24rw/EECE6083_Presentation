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
	$(CXX) -shared camelcase.cpp $(CFLAGS) $(CLANGLIBS) -o camelcase.so `llvm-config --cxxflags --ldflags --libs`

run:
	clang++ -cc1 -load ./camelcase.so -plugin camelcase test.cpp -fcolor-diagnostics

clean:
	rm -rf *.so
