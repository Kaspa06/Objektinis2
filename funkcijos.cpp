#include "funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

bool sortByVardas(const Studentas &a, const Studentas &b)
{
    return a.vardas < b.vardas;
}

bool sortByPavarde(const Studentas &a, const Studentas &b)
{
    return a.pavarde < b.pavarde;
}

bool sortByVidurkis(const Studentas &a, const Studentas &b)
{
    double vidurkisA = 0.4 * vidurkis(a.nd_rezultatai) + 0.6 * a.egzaminas;
    double vidurkisB = 0.4 * vidurkis(b.nd_rezultatai) + 0.6 * b.egzaminas;
    return vidurkisA < vidurkisB;
}

bool sortByMediana(const Studentas &a, const Studentas &b)
{
    double medianaA = 0.4 * mediana(a.nd_rezultatai) + 0.6 * a.egzaminas;
    double medianaB = 0.4 * mediana(b.nd_rezultatai) + 0.6 * b.egzaminas;
    return medianaA < medianaB;
}

void spausdintiGalutiniusBalus(const std::vector<Studentas> &studentai, const std::string &isvedimoFailoVardas, int rusiavimoTipas)
{
    std::ostream *out;
    std::ofstream fileOut;

    if (!isvedimoFailoVardas.empty())
    {
        fileOut.open(isvedimoFailoVardas);
        out = &fileOut;
    }
    else
    {
        out = &std::cout;
    }

    std::vector<Studentas> surusiuotiStudentai = studentai;

    switch (rusiavimoTipas)
    {
    case 1:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVardas);
        break;
    case 2:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByPavarde);
        break;
    case 3:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByVidurkis);
        break;
    case 4:
        sort(surusiuotiStudentai.begin(), surusiuotiStudentai.end(), sortByMediana);
        break;
    }

    *out << std::fixed << std::setprecision(2);
    *out << "Studentų galutiniai balai:\n";
    *out << "----------------------------------------------------------------\n";
    *out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << std::endl;
    *out << "----------------------------------------------------------------\n";

    for (const Studentas &studentas : surusiuotiStudentai)
    {
        double galutinisVidurkis = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        double galutineMediana = 0.4 * mediana(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
        *out << std::left << std::setw(15) << studentas.vardas << std::setw(15) << studentas.pavarde << std::setw(20) << galutinisVidurkis << std::setw(20) << galutineMediana << "\n";
    }
    *out << "----------------------------------------------------------------\n";

    if (!isvedimoFailoVardas.empty())
    {
        fileOut.close();
    }
}

void manualInput(std::vector<Studentas> &studentai)
{
    char testi = 't';
    while (testi == 't' || testi == 'T')
    {
        Studentas naujasStudentas;
        std::string temp;

        std::cout << "Įveskite studento vardą: ";
        std::cin >> naujasStudentas.vardas;
        std::cout << "Įveskite studento pavardę: ";
        std::cin >> naujasStudentas.pavarde;

        std::cout << "Įveskite namų darbų pažymius (0 norint baigti): ";
        int pazymys;
        while (true)
        {
            std::cin >> pazymys;
            if (std::cin.fail() || pazymys < 0 || pazymys > 10)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Neteisingai įvestas pažymys. Turi būti sveikasis skaičius nuo 0 iki 10." << std::endl;
                continue;
            }
            if (pazymys == 0)
            {
                break;
            }
            naujasStudentas.nd_rezultatai.push_back(pazymys);
        }

        std::cout << "Įveskite egzamino rezultatą: ";
        while (true)
        {
            std::cin >> naujasStudentas.egzaminas;
            if (std::cin.fail() || naujasStudentas.egzaminas < 0 || naujasStudentas.egzaminas > 10)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Neteisingai įvestas egzamino rezultatas. Turi būti sveikasis skaičius nuo 0 iki 10." << std::endl;
                continue;
            }
            break;
        }

        studentai.push_back(naujasStudentas);

        std::cout << "Ar norite įvesti dar vieną studentą? (t/n): ";
        std::cin >> testi;
    }
}

void generateGradesOnly(std::vector<Studentas> &studentai)
{
    for (Studentas &studentas : studentai)
    {
        generateRandomGrades(studentas);
    }
}

void readFileDataFromFile(std::vector<Studentas> &studentai, const std::string &failoVardas)
{
    std::ifstream failas(failoVardas);
    if (!failas.is_open())
    {
        throw std::runtime_error("Nepavyko atidaryti failo: " + failoVardas);
    }

    Studentas studentas;
    std::string eilute;

    while (getline(failas, eilute))
    {
        std::istringstream eilutesSrautas(eilute);
        eilutesSrautas >> studentas.vardas >> studentas.pavarde;

        int pazymys;
        studentas.nd_rezultatai.clear();
        while (eilutesSrautas >> pazymys && pazymys != -1)
        {
            studentas.nd_rezultatai.push_back(pazymys);
        }

        studentas.egzaminas = pazymys;
        studentai.push_back(studentas);
    }

    failas.close();
}

void generateStudentFiles(const std::vector<int> &sizes) //padarius su istringstream laikai pamazes (pataisysiu)
{
    for (int size : sizes)
    {
        std::string fileName = "studentai" + std::to_string(size) + ".txt";
        std::ofstream outFile(fileName);

        outFile << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavardė";
        for (int i = 1; i <= 15; ++i)
        {
            outFile << std::setw(10) << "ND" + std::to_string(i);
        }
        outFile << std::setw(10) << "Egz." << std::endl;

        for (int i = 1; i <= size; i++)
        {
            outFile << std::left << std::setw(15) << "Vardas" + std::to_string(i)
                    << std::setw(15) << "Pavardė" + std::to_string(i);
            for (int j = 0; j < 15; j++)
            {
                outFile << std::setw(10) << (rand() % 10 + 1);
            }
            outFile << std::setw(10) << (rand() % 10 + 1);
            outFile << std::endl;
        }

        outFile.close();
    }
}

void rusiuotiStudentus(const std::vector<int>& sizes) {
    for (size_t index = 0; index < sizes.size(); ++index) {
        std::string fileName = "studentai" + std::to_string(sizes[index]) + ".txt";
        std::ifstream inFile(fileName);

        if (!inFile) {
            std::cerr << "Nepavyko atidaryti failo: " << fileName << std::endl;
            continue;
        }

        std::vector<Studentas> studentai, kietiakiai, vargsiukai;
        Studentas tempStudentas;
        std::string eilute;
        std::getline(inFile, eilute); // Praleidžiame antraštę

        auto startRead = std::chrono::high_resolution_clock::now();

        while (std::getline(inFile, eilute)) {
            std::istringstream eiluteStream(eilute);
            eiluteStream >> tempStudentas.vardas >> tempStudentas.pavarde;
            tempStudentas.nd_rezultatai.clear();
            int pazymys;

            while (eiluteStream >> pazymys) {
                tempStudentas.nd_rezultatai.push_back(pazymys);
            }
            
            if (!tempStudentas.nd_rezultatai.empty()) {
                tempStudentas.egzaminas = tempStudentas.nd_rezultatai.back();
                tempStudentas.nd_rezultatai.pop_back();
            }

            studentai.push_back(tempStudentas);
        }

        inFile.close();

        auto endRead = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedRead = endRead - startRead;
        std::cout << "Duomenų nuskaitymas iš " << fileName << " užtruko: " << elapsedRead.count() << " sekundžių." << std::endl;

        auto startSort = std::chrono::high_resolution_clock::now();

        std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
            return (0.4 * vidurkis(a.nd_rezultatai) + 0.6 * a.egzaminas) < (0.4 * vidurkis(b.nd_rezultatai) + 0.6 * b.egzaminas);
        });

        for (const auto& studentas : studentai) {
            double galutinisBalas = 0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas;
            if (galutinisBalas < 5.0) {
                vargsiukai.push_back(studentas);
            } else {
                kietiakiai.push_back(studentas);
            }
        }

        auto endSort = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsedSort = endSort - startSort;
        std::cout << "Studentų rūšiavimas užtruko: " << elapsedSort.count() << " sekundžių." << std::endl;

        // Išvedimas į failus
        std::ofstream kietiakiaiFile("kietiakiai.txt"), vargsiukaiFile("vargsiukai.txt");

        for (const auto &studentas : kietiakiai) {
            kietiakiaiFile << studentas.vardas << " " << studentas.pavarde << " " << std::fixed << std::setprecision(2) << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas) << std::endl;
        }

        for (const auto &studentas : vargsiukai) {
            vargsiukaiFile << studentas.vardas << " " << studentas.pavarde << " " << std::fixed << std::setprecision(2) << (0.4 * vidurkis(studentas.nd_rezultatai) + 0.6 * studentas.egzaminas) << std::endl;
        }

        kietiakiaiFile.close();
        vargsiukaiFile.close();

        std::cout << "Studentai iš " << fileName << " buvo sėkmingai išrūšiuoti ir išsaugoti į atitinkamus failus." << std::endl;
    }
}
