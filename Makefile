SRC_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(patsubst src/%.cpp, obj/%.o, $(SRC_FILES))
LD_FLAGS :=
CXX_FLAGS := -Wall -g --std=c++11

.PHONY: all clean

.FORCE:

all: bin/cipher9

bin/cipher9: bin $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $(OBJ_FILES) $(LIB_FILES)

bin:
	-mkdir bin

obj:
	-mkdir obj

obj/%.o: src/%.cpp | obj
	g++ $(CXX_FLAGS) -c -o $@ $<

clean:
	rm -rf obj bin
