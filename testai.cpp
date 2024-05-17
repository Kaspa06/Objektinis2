#include <gtest/gtest.h>
#include "studentas.h"
#include <vector>
#include <numeric>
#include <algorithm>

// Test default constructor
TEST(StudentasTest, DefaultConstructor) {
    Studentas student;
    EXPECT_EQ(student.getVardas(), "");
    EXPECT_EQ(student.getPavarde(), "");
    EXPECT_EQ(student.getEgzaminas(), 0);
    EXPECT_EQ(student.getNamuDarbai().size(), 0);
}

// Test parameterized constructor
TEST(StudentasTest, ParameterizedConstructor) {
    Studentas student("Jonas", "Jonaitis");
    EXPECT_EQ(student.getVardas(), "Jonas");
    EXPECT_EQ(student.getPavarde(), "Jonaitis");
}

// Test set and get Vardas
TEST(StudentasTest, SetGetVardas) {
    Studentas student;
    student.setVardas("Jonas");
    EXPECT_EQ(student.getVardas(), "Jonas");
}

// Test set and get Pavarde
TEST(StudentasTest, SetGetPavarde) {
    Studentas student;
    student.setPavarde("Jonaitis");
    EXPECT_EQ(student.getPavarde(), "Jonaitis");
}

// Test set and get NamuDarbai
TEST(StudentasTest, SetGetNamuDarbai) {
    Studentas student;
    std::vector<int> nd = { 8, 9, 10 };
    student.setNamuDarbai(nd);
    EXPECT_EQ(student.getNamuDarbai(), nd);
}

// Test add NamuDarbai
TEST(StudentasTest, AddNamuDarbai) {
    Studentas student;
    student.addNamuDarbai(8);
    student.addNamuDarbai(9);
    student.addNamuDarbai(10);
    std::vector<int> expected = { 8, 9, 10 };
    EXPECT_EQ(student.getNamuDarbai(), expected);
}

// Test set and get Egzaminas
TEST(StudentasTest, SetGetEgzaminas) {
    Studentas student;
    student.setEgzaminas(9);
    EXPECT_EQ(student.getEgzaminas(), 9);
}

// Test calculation of Vidurkis
TEST(StudentasTest, CalcVidurkis) {
    Studentas student;
    std::vector<int> nd = { 8, 9, 10 };
    student.setNamuDarbai(nd);
    double expected_average = std::accumulate(nd.begin(), nd.end(), 0.0) / nd.size();
    EXPECT_DOUBLE_EQ(student.calcVidurkis(), expected_average);
}

// Test calculation of Mediana
TEST(StudentasTest, CalcMediana) {
    Studentas student;
    std::vector<int> nd = { 10, 8, 9 };
    student.setNamuDarbai(nd);
    std::sort(nd.begin(), nd.end());
    double expected_median = nd[1]; // Since sorted: {8, 9, 10}
    EXPECT_DOUBLE_EQ(student.calcMediana(), expected_median);
}

// Test calculation of Galutinis with Vidurkis
TEST(StudentasTest, CalcGalutinisVidurkis) {
    Studentas student;
    std::vector<int> nd = { 8, 9, 10 };
    student.setNamuDarbai(nd);
    student.setEgzaminas(9);
    double expected_final = 0.4 * (std::accumulate(nd.begin(), nd.end(), 0.0) / nd.size()) + 0.6 * 9;
    EXPECT_DOUBLE_EQ(student.calcGalutinis(true), expected_final);
}

// Test calculation of Galutinis with Mediana
TEST(StudentasTest, CalcGalutinisMediana) {
    Studentas student;
    std::vector<int> nd = { 8, 9, 10 };
    student.setNamuDarbai(nd);
    student.setEgzaminas(9);
    std::sort(nd.begin(), nd.end());
    double expected_final = 0.4 * 9 + 0.6 * 9;
    EXPECT_DOUBLE_EQ(student.calcGalutinis(false), expected_final);
}

// Test randomND (You might want to add specific tests for randomness)
TEST(StudentasTest, RandomND) {
    Studentas student;
    student.randomND();
    EXPECT_GT(student.getNamuDarbai().size(), 0);
}

// Test randomStudentai (You might want to add specific tests for randomness)
TEST(StudentasTest, RandomStudentai) {
    Studentas student;
    student.randomStudentai();
    EXPECT_NE(student.getVardas(), "");
    EXPECT_NE(student.getPavarde(), "");
    EXPECT_GT(student.getNamuDarbai().size(), 0);
}
// Test the copy constructor
TEST(StudentasTest, CopyConstructor) {
    Studentas student1("Jonas", "Jonaitis");
    student1.setEgzaminas(8);
    student1.addNamuDarbai(7);
    student1.addNamuDarbai(9);

    Studentas student2(student1);
    EXPECT_EQ(student2.getVardas(), "Jonas");
    EXPECT_EQ(student2.getPavarde(), "Jonaitis");
    EXPECT_EQ(student2.getEgzaminas(), 8);
    EXPECT_EQ(student2.getNamuDarbai(), student1.getNamuDarbai());
}

// Test the copy assignment operator
TEST(StudentasTest, CopyAssignmentOperator) {
    Studentas student1("Jonas", "Jonaitis");
    student1.setEgzaminas(8);
    student1.addNamuDarbai(7);
    student1.addNamuDarbai(9);

    Studentas student2;
    student2 = student1;

    EXPECT_EQ(student2.getVardas(), "Jonas");
    EXPECT_EQ(student2.getPavarde(), "Jonaitis");
    EXPECT_EQ(student2.getEgzaminas(), 8);
    EXPECT_EQ(student2.getNamuDarbai(), student1.getNamuDarbai());
}

// Test the move constructor
TEST(StudentasTest, MoveConstructor) {
    Studentas student1("Jonas", "Jonaitis");
    student1.setEgzaminas(8);
    student1.addNamuDarbai(7);
    student1.addNamuDarbai(9);

    Studentas student2(std::move(student1));
    EXPECT_EQ(student2.getVardas(), "Jonas");
    EXPECT_EQ(student2.getPavarde(), "Jonaitis");
    EXPECT_EQ(student2.getEgzaminas(), 8);
    EXPECT_EQ(student2.getNamuDarbai().size(), 2);

    EXPECT_EQ(student1.getVardas(), ""); // moved-from state
    EXPECT_EQ(student1.getPavarde(), ""); // moved-from state
    EXPECT_EQ(student1.getEgzaminas(), 0); // moved-from state
    EXPECT_TRUE(student1.getNamuDarbai().empty()); // moved-from state
}

// Test the move assignment operator
TEST(StudentasTest, MoveAssignmentOperator) {
    Studentas student1("Jonas", "Jonaitis");
    student1.setEgzaminas(8);
    student1.addNamuDarbai(7);
    student1.addNamuDarbai(9);

    Studentas student2;
    student2 = std::move(student1);

    EXPECT_EQ(student2.getVardas(), "Jonas");
    EXPECT_EQ(student2.getPavarde(), "Jonaitis");
    EXPECT_EQ(student2.getEgzaminas(), 8);
    EXPECT_EQ(student2.getNamuDarbai().size(), 2);

    EXPECT_EQ(student1.getVardas(), ""); // moved-from state
    EXPECT_EQ(student1.getPavarde(), ""); // moved-from state
    EXPECT_EQ(student1.getEgzaminas(), 0); // moved-from state
    EXPECT_TRUE(student1.getNamuDarbai().empty()); // moved-from state
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
