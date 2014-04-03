all:
	clang++ -c pass_test.cpp -emit-llvm
	clang++ -c pass.cpp `llvm-config --cxxflags`
	clang++ -shared -o pass.so pass.o `llvm-config --ldflags --libs`

run:
	opt -load=./pass.so -hello pass_test.bc -o pass_test_output.bc

time:
	opt -load=./pass.so -hello pass_test.bc -time-passes -o pass_test_output.bc

run_osx:
	opt -load=/opt/local/libexec/llvm-3.4/lib/LLVMHello.dylib -hello pass_test.bc -o pass_test_output.bc

time_osx:
	opt -load=/opt/local/libexec/llvm-3.4/lib/LLVMHello.dylib -hello pass_test.bc -time-passes -o pass_test_output.bc

clean:
	rm -fr *.{o,bc,so}
