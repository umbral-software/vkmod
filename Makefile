CXX = clang++
CXXFLAGS = -std=c++20 --stdlib=libc++

.PHONY: all clean ALL_MODULES
.SUFFIXES: .cppm .pcm

all: ALL_MODULES
	$(MAKE) -C example

clean:
	$(MAKE) -C example clean
	rm -f *.pcm

ALL_MODULES: vulkan.pcm

.cppm.pcm:
	${CXX} ${CXXFLAGS} --precompile $< -o $@

.cppm.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@


