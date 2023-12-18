.PHONY = clean

OBJECTS = calc.h main.c calc.c
calc: $(OBJECTS)
	@gcc $(OBJECTS) -o calc
	
clean:
	@rm -rf *.gch *.out calc 
