
#option -g debug pour exécuter avec valgrind : yes / no
DEBUG = no

ifeq ($(DEBUG),yes)
	CFLAGS = -g
else
	CFLAGS =
endif

#Nom de l'exécutable
EXEC = mode

#Liste des fichiers sources et objets
SRC = $(wildcard *.c)
OBJ = $(SRC:.o=.c)

#Edition de liens / génération de l'exécutable
all: $(EXEC)
ifeq ($(DEBUG),yes)
	valgrind --track-origins=yes ./$(EXEC)
else
	./$(EXEC)
endif

$(EXEC) : $(OBJ)
	@gcc -o $@ $^
	
#Compilation des .c
main.o : Graphe.h

%.o : %.c %.h
	@gcc $(CFLAGS) -o $@ -c $<
	
#Générations des courbes et du graphe
plot:
	gnuplot -persist text.gnp

graph:
	neato -Tpdf -o graphe.pdf graphe.dot


#Nettoyage du projet
.PHONY : $(EXEC) plot graph clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf mode
