#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas
{
public:
    Studentas();
    Studentas(const std::string &vardas, const std::string &pavarde);

    void setVardas(std::string vardas);
    std::string getVardas() const;

    void setPavarde(std::string pavarde);
    std::string getPavarde() const;

    void setNamuDarbai(const std::vector<int> &nd);
    std::vector<int> getNamuDarbai() const;

    void addNamuDarbai(int pazymys);

    void setEgzaminas(int egzaminas);
    int getEgzaminas() const;

    double calcVidurkis() const;
    double calcMediana() const;
    double calcGalutinis(bool useVidurkis) const;
    void randomND();
    void randomStudentai();

    ~Studentas();
    
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_rezultatai;
    int egzaminas;
};

#endif // STUDENTAS_H
