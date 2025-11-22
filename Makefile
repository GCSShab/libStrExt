all: lib test

# Construction des librairies (statique et dynamique)
lib: tools.c tools.h
	@gcc -c -fPIC tools.c -o tools.o
	@gcc -shared -o libstrtools.so tools.o
	@echo "La librairie dynamique libstrtools.so est disponible."
	@rm tools.o
	@gcc -c tools.c -o tools.o
	@ar rcs libstrtools.a tools.o
	@echo "La librairie statique libstrtools.a est disponible."
	@rm tools.o

# Construction du programme de test
test: main.c tools.c tools.h lib
	@gcc main.c -L. -lstrtools -Wl,-rpath=. -o test
	@echo "Le programme de test est disponible : ./test"

# Installation dans les répertoires systèmes
install: lib
	@echo "Installation de la librairie et du header..."
	@sudo cp libstrtools.so /usr/local/lib/
	@sudo cp libstrtools.a /usr/local/lib/
	@sudo cp tools.h /usr/local/include/
	@sudo ldconfig
	@echo "Installation terminée : libstrtools.a -> /usr/local/lib, libstrtools.so -> /usr/local/lib, tools.h -> /usr/local/include"

# Nettoyage
clean:
	-@rm libstrtools.a 2>/dev/null
	-@rm libstrtools.so 2>/dev/null
	-@rm test 2>/dev/null
	@echo "Nettoyage terminé"
