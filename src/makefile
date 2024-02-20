.PHONY = clean 
.PHONY = run

CC = gcc
OBJECTS =  stack.c main.c calc.c
CFLAGS =  -I../include/ -g
TARGET = calc

$(TARGET): $(OBJECTS)
	@$(CC) $(CFLAGS)  $^ -o $@
clean:
	@rm -rf *.gch *.out calc 
