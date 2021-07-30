#include "tili.h"
#include<string>


// Konstruktorit

Tili::Tili()
{

}

Tili::Tili(double summa, std::string tyyppi, std::string omistaja)
{
    this->summa = summa;
    this->tyyppi = tyyppi;
    this->omistaja = omistaja;
}

double Tili::getSumma() const
{
    return summa;
}

void Tili::setSumma(double newSumma)
{
    summa = newSumma;
}

double Tili::getKorko() const
{
    return korko;
}

const std::string &Tili::getNimi() const
{
    return nimi;
}

const std::string &Tili::getTyyppi() const
{
    return tyyppi;
}

void Tili::setTyyppi(const std::string &newTyyppi)
{
    tyyppi = newTyyppi;
}

const std::string &Tili::getOmistaja() const
{
    return omistaja;
}

void Tili::setOmistaja(const std::string &newOmistaja)
{
    omistaja = newOmistaja;
}
