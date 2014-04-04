CXX = clang++
CFLAGS = -fno-rtti

all:
	$(CXX) -shared camelcase.cpp $(CFLAGS) -o camelcase.so `llvm-config --cxxflags --ldflags --libs`

run:
	clang++ -cc1 -load ./camelcase.so -plugin camelcase test.cpp -fcolor-diagnostics

clean:
	rm -rf *.so
