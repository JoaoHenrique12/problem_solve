CC := g++
FLAGS := -std=c++14
SRCFILES := $(wildcard src/*.cpp)

all: $(SRCFILES:src/%.cpp=obj/%.o)
	$(CC) $(FLAGS) obj/*.o -o bin/prog

obj/%.o: src/%.cpp
	$(CC) $(FLAGS) -c -o $@ $< -Iinc/

run: bin/prog
	bin/prog

.PHONY: clean

clean:
	rm -f obj/*
	rm -f bin/prog
