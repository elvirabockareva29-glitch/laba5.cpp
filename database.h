#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Patient {
private:
    string name;
    int age;
    string diagnosis;
    
public:
    Patient();
    friend ostream& operator<<(ostream& out, const Patient& p);
    friend istream& operator>>(istream& in, Patient& p);
    
    string getName() const;
    int getAge() const;

    void edit();
};
class Database {
private:
    Patient* arr; 
    int size;
    int capacity;
    
public:
    Database();
    ~Database(); 
    void loadFromFile(const string& filename);
    void saveToFile(const string& filename);
    void print();
    void add();
    void remove();
    void edit();
    void search();
};

#endif
