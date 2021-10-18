CXX=clang++
CXXFLAGS = -std=c++20 -fprebuilt-module-path=.. -fimplicit-modules -fimplicit-module-maps --stdlib=libc++
LDFLAGS = 
LIBRARIES = -lvulkan

.PHONY: all clean

all: vkmod-example

clean:
	rm -f vkmod-example *.o

vkmod-example: main.o
	${CXX} ${LDFLAGS} $^ ${LIBRARIES} -o vkmod-example

