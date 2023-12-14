#include "Nageoire.h"
#include <stdlib.h>
#include <cmath>

const double Nageoire::NU_MAX = 3;

// CONSTRUCTEUR
Nageoire::Nageoire() {
    double randomNumber = (rand() % 1000) / 1000;
    Nageoire::nu = 1 + (NU_MAX - 1) * randomNumber;
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

bool Nageoire::isOreilles() {
    return false;
}

double Nageoire::getNu() {
    return nu;
}
