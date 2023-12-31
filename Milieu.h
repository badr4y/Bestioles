#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <list>


using namespace std;

class Bestiole;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   list<shared_ptr<Bestiole>>   listeBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };
   const list<shared_ptr<Bestiole>>& getListeBestioles() const{ return listeBestioles; };

   void step( void );

   void addMember( const Bestiole & b );
   int nbVoisins( const Bestiole & b );

};


#endif
