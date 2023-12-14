#include "Carapace.h"
#include <stdlib.h>
#include <cmath>

const double Carapace::ETA_MAX = 5;
const double Carapace::OMEGA_MAX = 8;
double eta;
double omega;

// CONSTRUCTEUR
Carapace::Carapace() {
    double randomNumber = (rand() % 1000) / 1000;
    eta = 1 + (ETA_MAX - 1) * randomNumber;
    omega = 1 + (OMEGA_MAX - 1) * randomNumber;
}

bool Carapace::isYeux() {
    return false;
}

bool Carapace::isCamouflage() {
    return false;
}

bool Carapace::isCarapace() {
    return true;
}

bool Carapace::isNageoire() {
    return false;
}

bool Carapace::isOreilles() {
    return false;
}

double Carapace::getEta() {
    return eta;
}

double Carapace::getOmega() {
    return omega;
}
