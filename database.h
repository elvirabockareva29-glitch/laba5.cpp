#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <fstream>

class Patient {
private:
    std::string name;
    int age;
    std::string diagnosis;

public:
    Patient();

    friend std::ostream& operator<<(std::ostream& out, const Patient& p);
    friend std::istream& operator>>(std::istream& in, Patient& p);

    std::string getName() const;
    int getAge() const;

    void edit();
};

class Database {
private:
    std::vector<Patient> data;

public:
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);

    void print();
    void add();
    void remove();
    void edit();
    void search();
};

#endif
