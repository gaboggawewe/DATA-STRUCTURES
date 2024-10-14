output: main.o 
	g++ main.o -o output

main.o: main.cpp FunctionLoad.h FunctionLoad.cpp episode.h episode.cpp movie.h movie.cpp video.h video.cpp 
	g++ -c main.cpp

clean:
	rm *.o output

valgrind: output
	valgrind --leak-check=full ./output