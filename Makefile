# Trois modeles : 1 2 et 3 respectivement
#MODELE = ErdosRenyi
# MODELE = BenderCanfield
 MODELE = AlbertBarabasi

# Nombre de sommets du graphe généré
# N = 10

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
	valgrind --track-origins=yes ./$(EXEC) $(MODELE)
else
	./$(EXEC) $(MODELE)
endif

$(EXEC) : $(OBJ)
	@gcc -o $@ $^
	
#Compilation des .c
main.o : Graphe.h

%.o : %.c %.h
	@gcc $(CFLAGS) -o $@ -c $<
	
#Générations des courbes et du graphe
plot:
ifeq ($(MODELE),ErdosRenyi)
	gnuplot -persist GnuModele1.gnp
else ifeq ($(MODELE),BenderCanfield)
	gnuplot -persist GnuModele2.gnp
else
	gnuplot -persist GnuModele3.gnp
endif
	

graph:
	neato -Tpdf -o $@$(MODELE).pdf $@$(MODELE)


#Nettoyage du projet
.PHONY : $(EXEC) plot graph clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf mode
