#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++0x

__start__: obroty_3D
	./obroty_3D

obroty_3D: obj obj/main.o obj/Prostopadloscian.o obj/Macierz3x3.o obj/Wektor3D.o obj/Scena.o obj/Rotor.o obj/Dron.o obj/Obj_Sc.o obj/Obstacle.o obj/Obj_Geo.o\
           obj/lacze_do_gnuplota.o
	g++ -Wall -pedantic -std=c++0x -o obroty_3D obj/main.o obj/Wektor3D.o\
                        obj/Macierz3x3.o obj/Prostopadloscian.o obj/lacze_do_gnuplota.o obj/Scena.o obj/Obj_Geo.o obj/Rotor.o obj/Dron.o obj/Obstacle.o  obj/Obj_Sc.o

obj:
	mkdir obj

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp

obj/main.o: src/main.cpp inc/Prostopadloscian.hh inc/Macierz3x3.hh inc/Macierz.hh\
           inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh\
         inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Macierz3x3.o: src/Macierz3x3.cpp inc/Macierz3x3.hh inc/Macierz.hh inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Macierz3x3.o src/Macierz3x3.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
	g++ -c ${CXXFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/Scena.o src/Scena.cpp

obj/Obj_Geo.o: src/Obj_Geo.cpp inc/Obj_Geo.hh inc/Obj_Geo.hh
	g++ -c ${CXXFLAGS} -o obj/Obj_Geo.o src/Obj_Geo.cpp

obj/Rotor.o: src/Rotor.cpp inc/Rotor.hh inc/Rotor.hh
	g++ -c ${CXXFLAGS} -o obj/Rotor.o src/Rotor.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh inc/Dron.hh
	g++ -c ${CXXFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Obstacle.o: src/Obstacle.cpp inc/Obstacle.hh inc/Obstacle.hh
	g++ -c ${CXXFLAGS} -o obj/Obstacle.o src/Obstacle.cpp

obj/Obj_Sc.o: src/Obj_Sc.cpp inc/Obj_Sc.hh inc/Obj_Sc.hh
	g++ -c ${CXXFLAGS} -o obj/Obj_Sc.o src/Obj_Sc.cpp

clean:
	rm -f obj/*.o obroty_3D
