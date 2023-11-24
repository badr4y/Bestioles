#ifndef _UPGRADE_H_
#define _UPGRADE_H_

using namespace std;


class Upgrade
{

private :

public :
	
	bool virtual isYeux( void )=0;
	bool virtual isOreilles( void )=0;
	bool virtual isNageoire( void )=0;
	bool virtual isCarapace( void )=0;
    bool virtual isCamouflage( void )=0;

    virtual ~Upgrade() = default;

};

#endif
