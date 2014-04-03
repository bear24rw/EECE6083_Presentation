all: hello_world.ll hello_world_gen

hello_world.ll: hello_world.cpp
	clang++ $< -o $@ -S -emit-llvm

hello_world_gen: hello_world_gen.cpp
	clang++ $< -o $@ `llvm-config --cxxflags --ldflags --libs`
	./hello_world_gen 2> hello_world_gen.ll

clean:
	rm -fr hello_world
	rm -fr hello_world.ll
	rm -fr hello_world_gen
	rm -fr hello_world_gen.ll
	rm -fr hello_world_gen.dSYM
