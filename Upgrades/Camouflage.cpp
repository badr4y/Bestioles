#include "Camouflage.h"
#include <stdlib.h>
#include <cmath>

const double Camouflage::PSI_MIN = 0.15;
const double Camouflage::PSI_MAX = 0.85;
double psi;


// CONSTRUCTEUR
Camouflage::Camouflage() {
    double randomNumber = (rand() % 1000) / 1000;  // rand() est entre 0 et RAND_MAX ; (rand() % 1000) est entre 0 et 1000 ; (rand() % 1000)/1000 est entre 0.000 et 1.000
    psi =PHI_MIN + (PSI_MAX - PSI_MIN) * randomNumber;
}

bool Camouflage::isYeux() {
    return false;
}

bool Camouflage::isCamouflage() {
    return true;
}

bool Camouflage::isCarapace() {
    return false;
}

bool Camouflage::isNageoire() {
    return false;
}

bool Camouflage::isOreille() {
    return false;
}