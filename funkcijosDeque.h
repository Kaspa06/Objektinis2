#ifndef FUNKCIJOSDEQUE_H
#define FUNKCIJOSDEQUE_H

#include "studentas.h"
#include <deque>

void readDataDeque(std::deque<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesDeque(int size);
void rusiuotiStudentusDeque(const std::string& fileName);
void rusiuotiStudentusDeque2(const std::string& fileName);
void rusiuotiStudentusDeque3(const std::string &failoVardas);

#endif // FUNKCIJOSDEQUE_H
