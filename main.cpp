#include "studentas.h"
#include <algorithm>
#include <cstdlib> 
#include <fstream>
#include <iostream>

// Constructor
Studentas::Studentas() : egzaminas(0) {}

// Constructor
Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vardas(vardas), pavarde(pavarde), egzaminas(0) {}

// Destructor
Studentas::~Studentas() {
    nd_rezultatai.clear();
    vardas.clear();
    pavarde.clear();
    egzaminas = 0;
}

//Copying constructor
Studentas::Studentas(const Studentas &copy)
: vardas(copy.vardas), pavarde(copy.pavarde), nd_rezultatai(copy.nd_rezultatai), egzaminas(copy.egzaminas) {}

//Copy assignment
Studentas& Studentas::operator=(const Studentas& copy) 
{
    if(this !=&copy)
    {
        vardas = copy.vardas;
        pavarde = copy.pavarde;
        nd_rezultatai = copy.nd_rezultatai;
        egzaminas = copy.egzaminas;
    }
    return *this;
}

 // Move assignment operator
    Studentas& Studentas::operator=(Studentas&& copy) noexcept {
        if (this!= &copy) {
            // Swap the members of the current object with the members of the other object
            std::swap(vardas, copy.vardas);
            std::swap(pavarde, copy.pavarde);
            std::swap(nd_rezultatai, copy.nd_rezultatai);
            std::swap(egzaminas, copy.egzaminas);
        }
        return *this;
    }

// Public member functions
void Studentas::setVardas(std::string vardas) {
    this-> vardas = vardas;
}
std::string Studentas::getVardas() const {
    return vardas;
}

void Studentas::setPavarde(std::string pavarde) {
    this -> pavarde = pavarde;
}

std::string Studentas::getPavarde() const {
    return pavarde;
}

void Studentas::setNamuDarbai(const std::vector<int>& nd) {
    nd_rezultatai = nd;
}

std::vector<int> Studentas::getNamuDarbai() const {
    return nd_rezultatai;
}

void Studentas::setEgzaminas(int egzaminas) {
    this->egzaminas = egzaminas;
}

void Studentas::addNamuDarbai(int pazymys)
{
    nd_rezultatai.push_back(pazymys);
}

int Studentas::getEgzaminas() const {
    return egzaminas;
}

double Studentas::calcVidurkis() const {
    double suma = 0.0;
    for (int pazymys : nd_rezultatai) {
        suma += pazymys;
    }
    return nd_rezultatai.empty() ? 0.0 : suma / nd_rezultatai.size();
}

double Studentas::calcMediana() const {
    if (nd_rezultatai.empty()) return 0.0;
    std::vector<int> tempNamuDarbai = nd_rezultatai;
    std::sort(tempNamuDarbai.begin(), tempNamuDarbai.end());
    int dydis = tempNamuDarbai.size();
    return (dydis % 2 == 0) ? (tempNamuDarbai[dydis / 2 - 1] + tempNamuDarbai[dydis / 2]) / 2.0 : tempNamuDarbai[dydis / 2];
}

double Studentas::calcGalutinis(bool useVidurkis) const {
    double galutinis = useVidurkis ? (0.4 * calcVidurkis() + 0.6 * egzaminas) : (0.4 * calcMediana() + 0.6 * egzaminas);
    return galutinis;
}

void Studentas::randomND() {
    nd_rezultatai.resize(rand() % 10 + 1);
    for (int& pazymys : nd_rezultatai) {
        pazymys = rand() % 10 + 1;
    }
    egzaminas = rand() % 10 + 1;
}

void Studentas::randomStudentai() {
    const char* vardai[] = {"Jonas", "Petras", "Antanas", "Juozas", "Kazimieras"};
    const char* pavardes[] = {"Jonaitis", "Petraitis", "Antanaitis", "Juozaitis", "Kazimieraitis"};
    int vardasIndex = rand() % 6;
    int pavardeIndex = rand() % 6;
    vardas = vardai[vardasIndex];
    pavarde = pavardes[pavardeIndex];
    randomND();
}

// Output Operator (Serialization)
std::ostream& operator<<(std::ostream& output, const Studentas &student) {
    output << student.vardas << " " << student.pavarde << " " << student.egzaminas << " ";
    for (int pazymys : student.nd_rezultatai) {
        output << std::to_string(pazymys) << " "; // Convert integer to string before output
    }
    return output;
}

// Input Operator (Deserialization)
std::istream& operator>>(std::istream& input, Studentas &student) {
    input >> student.vardas >> student.pavarde;
    input >> student.egzaminas;
    student.nd_rezultatai.clear();
    int pazymys;
    while (input >> pazymys) {
        student.nd_rezultatai.push_back(pazymys);
    }
    return input;
}
