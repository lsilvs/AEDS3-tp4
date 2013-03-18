# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc -lpthread

#Objetos
OBJS1 =  tp4-seq.c achaClique.c funcao.c list.c
OBJS2 =  tp4-par.c achaClique.c funcao.c list.c

# Nome do aplicativo
APPNAME1 = tp4-seq
APPNAME2 = tp4-par

#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = input.txt
OUTPUTFILE = output.txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS1) -o $(APPNAME1)
	$(GCC) $(OPTMIZE) $(LIBS) $(OBJS2) -o $(APPNAME2)

clean:
	rm -rf $(APPNAME1) $(APPNAME2) $(OUTPUTFILE) *.o *.dSYM

run:
	make
	./$(APPNAME2) $(INPUTFILE) $(OUTPUTFILE) 2

time:
	make
	time ./$(APPNAME2) $(INPUTFILE) $(OUTPUTFILE) 2

analysis:
	make
	$(VALGRIND) ./$(APPNAME2) $(INPUTFILE) $(OUTPUTFILE)
