#include "Milieu.h"

#include <cstdlib>
#include <ctime>
#include <list>
#include <factories/BestioleFactory.h>

#include "Bestiole.h"


const T    Milieu::white[] = { (T)255, (T)255, (T)255 };


Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

   std::srand( time(NULL) );

}


Milieu::~Milieu( void )
{

   cout << "dest Milieu" << endl;

}


void Milieu::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   Bestiole
   for (list<shared_ptr<Bestiole>>::iterator it = listeBestioles.begin(); it != listeBestioles.end();)
   {
	   (*it)->action(*this);

	   if ((*it)->getIsDead() == true) {
		   it = listeBestioles.erase(it);
	   }
	   else {
		   (*it)->draw(*this);
		   ++it;
	   }
   }

}

void Milieu::addMember(const Bestiole& b) {
	std::cout << "Appel à addMember lancé" << std::endl;
	listeBestioles.push_back(std::make_shared<Bestiole>(b));
	listeBestioles.back()->initCoords(width, height);
}



int Milieu::nbVoisins(const Bestiole& b) {
	int nb = 0;

	for (std::list<std::shared_ptr<Bestiole>>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
		if (!(b == *(*it)) && b.jeTeVois(**it))
			++nb;

	return nb;
}




