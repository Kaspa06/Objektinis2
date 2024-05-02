#include "funkcijosDeque.h"
#include "funkcijosVector.h"
#include "funkcijosList.h"
#include "funkcijos.h"
#include "studentas.h"
#include <iostream>
#include <vector>
#include <limits>
#include <deque>
#include <list>
#include <string>
#include <chrono>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <stdexcept>
#include <cstring>
#include <dirent.h>

enum class ContainerType { None, Vector, List, Deque };
enum class Action { None, Generate, Sort };

ContainerType getContainerChoice() {
    int choice;
    while (true) {
        std::cout << "Pasirinkite konteinerio tipa:\n"
                  << "1. Vector\n"
                  << "2. List\n"
                  << "3. Deque\n"
                  << "Pasirinkimas: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "iveskite skaiciu.\n";
        } else if (choice >= 1 && choice <= 3) {
            break;
        } else {
            std::cout << "Netinkamas pasirinkimas. Prasome bandyti dar karta.\n";
        }
    }

    switch (choice) {
        case 1: return ContainerType::Vector;
        case 2: return ContainerType::List;
        case 3: return ContainerType::Deque;
        default: return ContainerType::None;
    }
}

Action getActionChoice() {
    int choice;
    while (true) {
        std::cout << "Pasirinkite veiksma:\n"
                  << "1. Generuoti studentu failus\n"
                  << "2. Rusiuoti esamus studentu failus\n"
                  << "Pasirinkimas: ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "iveskite skaiciu.\n";
        } else if (choice == 1 || choice == 2) {
            break;
        } else {
            std::cout << "Netinkamas pasirinkimas. Prasome bandyti dar karta.\n";
        }
    }

    switch (choice) {
        case 1: return Action::Generate;
        case 2: return Action::Sort;
        default: return Action::None;
    }
}

std::string getSortingFileChoice() {
    std::vector<std::string> files;

    std::cout << "Turimi failai:\n";
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(".")) != NULL) {
        int fileIndex = 1;
        while ((ent = readdir(dir)) != NULL) {
            std::string filename = ent->d_name;
            if (filename.find("studentai") != std::string::npos && filename.find(".txt") != std::string::npos) {
                files.push_back(filename);
                std::cout << fileIndex++ << ". " << filename << "\n";
            }
        }
        closedir(dir);
    } else {
        std::cerr << "Could not open the directory.\n";
    }

    if (files.empty()) {
        std::cout << "Nerasti studentu failai.\n";
        return "";
    }

    std::cout << "Pasirinkite faila, kuri norite rusiuoti: ";
    int choice;
    std::cin >> choice;

    if (std::cin.fail() || choice < 1 || choice > files.size()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Netinkamas pasirinkimas. iveskite is naujo.\n";
        return "";
    }

    return files[choice - 1];
}

void performAction(ContainerType containerChoice, Action actionChoice, const std::vector<int>& sizes) {
if (actionChoice == Action::Generate) {
        for (int size : sizes) {
            auto start = std::chrono::high_resolution_clock::now();
            switch (containerChoice) {
                case ContainerType::Vector:
                    generateStudentFilesVector(size);
                    break;
                case ContainerType::List:
                    generateStudentFilesList(size);
                    break;
                case ContainerType::Deque:
                    generateStudentFilesDeque(size);
                    break;
                default:
                    std::cout << "Nepasirinktas tinkamas konteinerio tipas.\n";
                    break;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Uzimtas laikas generuojant sio dydzio faila: " << size << ": " << elapsed.count() << "s\n";
        }
    } else if (actionChoice == Action::Sort) {
        // Get the sorting method choice
        std::cout << "Pasirinkite rusiavimo metoda:\n"
                  << "1. Strategija (Du nauji to paties tipo konteineriai)\n"
                  << "2. Strategija (Tik vienas to paties tipo konteineris)\n"
                  << "3. Strategija (Du to paties tipo konteineriai su efektyviais metodais)\n"
                  << "Pasirinkimas: ";
        int sortingMethod;
        std::cin >> sortingMethod;
        if (std::cin.fail() || sortingMethod < 1 || sortingMethod > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Netinkamas pasirinkimas. iveskite is naujo.\n";
            return;
        }

        std::string filename = getSortingFileChoice();
        if (!filename.empty()) {
            auto start = std::chrono::high_resolution_clock::now();
            switch (containerChoice) {
                case ContainerType::Vector:
                    switch (sortingMethod) {
                        case 1:
                            rusiuotStudentusVector(filename);
                            break;
                        case 2:
                            rusiuotStudentusVector2(filename);
                            break;
                        case 3:
                            rusiuotStudentusVector3(filename);
                            break;
                        default:
                            std::cout << "Netinkamas rusiavimo metodo pasirinkimas.\n";
                            break;
                    }
                    break;
                case ContainerType::List:
                    switch (sortingMethod) {
                        case 1:
                            rusiuotiStudentusList(filename);
                            break;
                        case 2:
                            rusiuotiStudentusList2(filename);
                            break;
                        case 3:
                            rusiuotiStudentusList3(filename);
                            break;
                        default:
                            std::cout << "Netinkamas rusiavimo metodo pasirinkimas.\n";
                            break;
                    }
                    break;
                case ContainerType::Deque:
                    switch (sortingMethod) {
                        case 1:
                            rusiuotiStudentusDeque(filename);
                            break;
                        case 2:
                            rusiuotiStudentusDeque2(filename);
                            break;
                        case 3:
                            rusiuotiStudentusDeque3(filename);
                            break;
                        default:
                            std::cout << "Netinkamas rusiavimo metodo pasirinkimas.\n";
                            break;
                    }
                    break;
                default:
                    std::cout << "Netinkamas konteinerio pasirinkimas.\n";
                    break;
            }
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            std::cout << "Uzimtas laikas rusiojant ir skaidant studentus: " << filename << ": " << elapsed.count() << "s\n";
        }
    }
}

void runApp() {
    std::vector<int> sizes = {1000, 10000, 100000, 1000000, 10000000};
    bool exitProgram = false;

    while (!exitProgram) {
        ContainerType containerChoice = getContainerChoice();
        if (containerChoice == ContainerType::None) {
            continue;
        }

        Action actionChoice = getActionChoice();
        if (actionChoice == Action::None) {
            continue;
        }

        performAction(containerChoice, actionChoice, sizes);

        std::cout << "Ar norite testi?? (Y/N): ";
        char userChoice;
        std::cin >> userChoice;
        if (userChoice == 'N' || userChoice == 'n') {
            exitProgram = true;
        }
    }
}
