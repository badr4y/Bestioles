main : main.cpp Aquarium.o Bestiole.o Milieu.o Capteur.o Yeux.o Oreilles.o Camouflage.o Carapace.o Nageoire.o BestioleFactory.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o PersonnalitesMultiples.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Capteur.o Yeux.o Oreilles.o Camouflage.o Carapace.o Nageoire.o BestioleFactory.o Gregaire.o Kamikaze.o Peureuse.o Prevoyante.o PersonnalitesMultiples.o -I . -lX11 -lpthread

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

Gregaire.o : comportements/Gregaire.h comportements/Gregaire.cpp
	g++ -Wall -std=c++11 -c comportements/Gregaire.cpp -I .

Kamikaze.o : comportements/Kamikaze.h comportements/Kamikaze.cpp
	g++ -Wall -std=c++11 -c comportements/Kamikaze.cpp -I .

Peureuse.o : comportements/Peureuse.h comportements/Peureuse.cpp
	g++ -Wall -std=c++11 -c comportements/Peureuse.cpp -I .

Prevoyante.o : comportements/Prevoyante.h comportements/Prevoyante.cpp
	g++ -Wall -std=c++11 -c comportements/Prevoyante.cpp -I .

PersonnalitesMultiples.o : comportements/PersonnalitesMultiples.h comportements/PersonnalitesMultiples.cpp
	g++ -Wall -std=c++11 -c comportements/PersonnalitesMultiples.cpp -I .

clean:
	rm -rf *.o main
