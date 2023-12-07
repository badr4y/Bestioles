main : main.cpp Aquarium.o Bestiole.o Milieu.o Capteur.o Yeux.o Oreilles.o Camouflage.o Carapace.o Nageoire.o CreatureFactory.o BestioleFactory.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Capteur.o Yeux.o Oreilles.o Camouflage.o Carapace.o Nageoire.o CreatureFactory.o BestioleFactory.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11 -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11 -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11 -c Milieu.cpp -I .

Capteur.o : Upgrades/Capteur.h Upgrades/Capteur.cpp
	g++ -Wall -std=c++11 -c Upgrades/Capteur.cpp -I .

Yeux.o : Upgrades/Yeux.h Upgrades/Yeux.cpp
	g++ -Wall -std=c++11 -c Upgrades/Yeux.cpp -I .

Oreilles.o : Upgrades/Oreilles.h Upgrades/Oreilles.cpp
	g++ -Wall -std=c++11 -c Upgrades/Oreilles.cpp -I .

Camouflage.o : Upgrades/Camouflage.h Upgrades/Camouflage.cpp
	g++ -Wall -std=c++11 -c Upgrades/Camouflage.cpp -I .

Carapace.o : Upgrades/Carapace.h Upgrades/Carapace.cpp
	g++ -Wall -std=c++11 -c Upgrades/Carapace.cpp -I .

Nageoire.o : Upgrades/Nageoire.h Upgrades/Nageoire.cpp
	g++ -Wall -std=c++11 -c Upgrades/Nageoire.cpp -I .

BestioleFactory.o : factories/BestioleFactory.h factories/BestioleFactory.cpp factories/CreatureFactory.h
	g++ -Wall -std=c++11 -c factories/BestioleFactory.cpp -I .

clean:
	rm -rf *.o main
