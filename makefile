all:	algo
	
algo:	sort.o
	g++ -g sort.o 	-o algo
	
sort:	sort.cpp
	g++ -g	sort.cpp	-o sort.o
	
clean:	
	rm -f *.o algo




