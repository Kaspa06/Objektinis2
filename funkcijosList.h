#ifndef FUNKCIJOSLIST_H
#define FUNKCIJOSLIST_H

#include "studentas.h"
#include <list>

void readDataList(std::list<Studentas>& studentai, const std::string& failoVardas);
void generateStudentFilesList(int size);
void rusiuotiStudentusList(const std::string& failoVardas);
void rusiuotiStudentusList2(const std::string &failoVardas);
void rusiuotiStudentusList3(const std::string &failoVardas);

#endif // FUNKCIJOSLIST_H
