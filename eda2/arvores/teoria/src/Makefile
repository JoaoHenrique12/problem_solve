name_project=arvore

# .c files
c_source=$(wildcard ./src/*.c)

# .h files
h_source=$(wildcard ./inc/*.h)

# .o files
o_source=$(c_source:.c=.o)

#compiler
cc=gcc
cc_flags= -lm
RM=rm -rf

all: $(name_project)

$(name_project): $(o_source)
	$(cc) -o $@ $^

%.o: %.c  %.h
	$(cc) -o $@ $< $(cc_flags)

init.o: init.c $(h_source)
    $(cc) -o $@ $< $(cc_flags)
