#include "Nageoire.h"
#include <stdlib.h>
#include <cmath>

const double Nageoire::NU_MAX = 3;
double nu;

// CONSTRUCTEUR
Nageoire::Nageoire() {
    double randomNumber = (rand() % 1000) / 1000;  // rand() est entre 0 et RAND_MAX ; (rand() % 1000) est entre 0 et 1000 ; (rand() % 1000)/1000 est entre 0.000 et 1.000
    nu = 1 + (NU_MAX - 1) * randomNumber;
}

bool Nageoire::isYeux() {
    return false;
}

bool Nageoire::isCamouflage() {
    return false;
}

bool Nageoire::isCarapace() {
    return false;
}

bool Nageoire::isNageoire() {
    return true;
}

bool Nageoire::isOreille() {
    return false;
}