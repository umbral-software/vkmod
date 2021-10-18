CXX=clang++
CXXFLAGS = -std=c++20 -fprebuilt-module-path=.. -fimplicit-modules -fimplicit-module-maps --stdlib=libc++
LDFLAGS = 
LIBRARIES = -lvulkan

EXECUTABLE = vkmod-example

.PHONY: all clean

all: $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE) *.o

$(EXECUTABLE): main.o
	${CXX} ${LDFLAGS} $^ ${LIBRARIES} -o $@

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@