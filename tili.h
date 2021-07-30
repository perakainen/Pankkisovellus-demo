#include<string>

#ifndef TILI_H
#define TILI_H

class Tili
{

public:

    // Konstruktorit

    Tili();
    Tili(double summa, std::string tyyppi, std::string omistaja);


    // Getterit & Setterit

    double getSumma() const;
    void setSumma(double newSumma);

    double getKorko() const;

    const std::string &getNimi() const;

    const std::string &getTyyppi() const;
    void setTyyppi(const std::string &newTyyppi);

    const std::string &getOmistaja() const;
    void setOmistaja(const std::string &newOmistaja);

protected:
    double summa = 0;
    double korko = 0.5;
    std::string nimi = "Pankkitili";
    std::string tyyppi = "";
    std::string omistaja = "";
};

#endif // TILI_H
