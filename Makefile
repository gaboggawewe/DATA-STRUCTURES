output: main.o numeros_rand.o
	g++ main.o numeros_rand.o -o output

main.o: main.cpp numeros_rand.h
	g++ -c main.cpp

numeros_rand.o: numeros_rand.cpp numeros_rand.h
	g++ -c numeros_rand.cpp
clean:
	rm *.o output

valgrind: output
	valgrind --leak-check=full ./output