#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int licznik = 0;
    unsigned int l_zag = 0;
    
    Stocznia stocznia{};                    // generuje stocznię do tworzenia statków

    while(licznik<=towar)
    {
        if(towar==0){
            return 0;                       // warunek gdy towar jest rowny 0
        }
        else{
            Statek* s1 = stocznia();        // tworzy statek ze stoczni

            licznik += s1->transportuj();   // statek transportuje towar

            if (Zaglowiec* z = dynamic_cast<Zaglowiec*>(s1)) {
                l_zag++;                    // jezeli s1 to zaglowiec, warunek jest spelniony
            } 

            delete s1;
        }
    }
    return l_zag;
}