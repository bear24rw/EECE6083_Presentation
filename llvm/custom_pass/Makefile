all:
	clang++ -c pass.cpp `llvm-config --cxxflags`
	clang++ -shared -o pass.so pass.o `llvm-config --ldflags`
	clang++ -c pass_test.cpp -emit-llvm
	opt -load=./pass.so -hello pass_test.bc -o pass_test_output.bc

time:
	opt -load=./pass.so -hello pass_test.bc -time-passes -o pass_test_output.bc

clean:
	rm -fr *.{o,bc,so}
