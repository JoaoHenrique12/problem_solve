CC := gcc
SRCFILES := $(wildcard src/*.c)

all: $(SRCFILES:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/prog
obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc
run: bin/prog
	bin/prog

.PHONY: clean
OBJFILES := $(wildcard obj/*.o)

clean: $(OBJFILES:obj/%.o=remove_%.o)
	rm -f bin/prog
remove_%.o:
	rm -f obj/$@
