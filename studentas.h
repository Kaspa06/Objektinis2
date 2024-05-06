#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <string>
#include <vector>

class Studentas
{
public:
    // Constructor
    Studentas();
    // Constructor with parameters
    Studentas(const std::string &vardas, const std::string &pavarde);
    //Destructor
    ~Studentas();
    // Copying constructor
    Studentas(const Studentas &copy);

    // Copy assignment
    Studentas& operator=(const Studentas& copy);

    // Move assignment operator
    Studentas& operator=(Studentas&& copy) noexcept;

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

    friend std::ostream &operator<<(std::ostream &output, const Studentas &student);
    friend std::istream &operator>>(std::istream &input, Studentas &student);

    
private:
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd_rezultatai;
    int egzaminas;
};

#endif // STUDENTAS_H
