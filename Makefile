run:
	gnuplot -persist text.gnp

graph:
	neato -Tpdf -o graphe.pdf graphe.dot
