CXX = clang++
CXXFLAGS = -std=c++20 -fprebuilt-module-path=. -fimplicit-modules -fimplicit-module-maps --stdlib=libc++ -Iinclude
LDFLAGS = 
LIBRARIES = -lvulkan

.PHONY: all clean ALL_MODULES
.SUFFIXES: .cppm .pcm

all: ALL_MODULES vfighter

clean:
	rm -f *.o *.pcm

vfighter: main.o
	${CXX} ${LDFLAGS} $^ ${LIBRARIES} -o vfighter

ALL_MODULES: vulkan.pcm

.cppm.pcm:
	${CXX} ${CXXFLAGS} --precompile $< -o $@

.cppm.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@


