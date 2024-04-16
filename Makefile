# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall # Updated to C++17

# Program name
TARGET = run

# Object files list - added funkcijos.o
OBJS = main.o containers.o funkcijosVECTOR.o funkcijosLIST.o funkcijosDEQUE.o studentas.o funkcijos.o

# Main rule for program compilation
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Individual file compilation rules
main.o: main.cpp containers.h
	$(CXX) $(CXXFLAGS) -c main.cpp

containers.o: containers.cpp containers.h funkcijosVECTOR.h funkcijosLIST.h funkcijosDEQUE.h studentas.h
	$(CXX) $(CXXFLAGS) -c containers.cpp

funkcijosVector.o: funkcijosVECTOR.cpp funkcijosVECTOR.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijosVECTOR.cpp

funkcijosList.o: funkcijosLIST.cpp funkcijosLIST.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijosLIST.cpp

funkcijosDeque.o: funkcijosDEQUE.cpp funkcijosDEQUE.h studentas.h
	$(CXX) $(CXXFLAGS) -c funkcijosDEQUE.cpp

studentas.o: studentas.cpp studentas.h
	$(CXX) $(CXXFLAGS) -c studentas.cpp

# Added compilation rule for funkcijos.cpp
funkcijos.o: funkcijos.cpp funkcijos.h
	$(CXX) $(CXXFLAGS) -c funkcijos.cpp

# Clean rule
clean:
	rm -f $(TARGET) $(OBJS)
