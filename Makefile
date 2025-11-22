all: tools.c tools.h
	@gcc -c -fPIC tools.c -o tools.o
	@gcc -shared -o libstrtools.so tools.o
	@echo "La librairie libstrtools.so est dispnible."
	@rm tools.o
	@gcc -c tools.c -o tools.o
	@ar rcs libstrtools.a tools.o
	@echo "La librairie statique libstrtools.a est disponible."
	@rm tools.o

clean:
	-@rm libstrtools.a 2>/dev/null
	-@rm libstrtools.so 2>/dev/null


