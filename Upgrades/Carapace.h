#ifndef _CARAPACE_H_
#define _CARAPACE_H_

#include "Accessoire.h"

class Carapace : public Accessoire {
private:
    static const double OMEGA_MAX;
    static const double ETA_MAX;

private:
    double eta;
    double omega;

public:
    Carapace();

    bool isYeux();
    bool isCamouflage();
    bool isCarapace();
    bool isNageoire();
    bool isOreilles();

    double getEta();
    double getOmega();
};

#endif