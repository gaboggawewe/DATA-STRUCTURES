output: main.o catalogue.o dungeon.o monster.o room.o player.o
	g++ main.o catalogue.o dungeon.o monster.o room.o player.o -o output

main.o: main.cpp catalogue.h dungeon.h monster.h room.h player.h templates/arbolbinario.h templates/template_doble_ligadas.h monsters.csv
	g++ -c main.cpp

catalogue.o: catalogue.cpp catalogue.h templates/arbolbinario.h templates/template_doble_ligadas.h monsters.csv
	g++ -c catalogue.cpp

dungeon.o: dungeon.cpp templates/graphos.h dungeon.h templates/arbolbinario.h templates/template_doble_ligadas.h monsters.csv
	g++ -c dungeon.cpp

monster.o: monster.cpp monster.h templates/arbolbinario.h templates/template_doble_ligadas.h monsters.csv
	g++ -c monster.cpp

room.o: room.cpp room.h templates/arbolbinario.h templates/template_doble_ligadas.h monsters.csv
	g++ -c room.cpp

player.o: player.cpp player.h templates/arbolbinario.h templates/template_doble_ligadas.h monsters.csv
	g++ -c player.cpp

clean:
	rm *.o output

valgrind: output
	valgrind --leak-check=full ./output