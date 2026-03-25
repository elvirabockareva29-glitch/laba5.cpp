#include "database.h"
Patient::Patient() {
    age = 0;
}
std::ostream& operator<<(std::ostream& out, const Patient& p) {
    out << p.name << " " << p.age << " " << p.diagnosis;
    return out;
}
std::istream& operator>>(std::istream& in, Patient& p) {
    std::cout << "Имя: ";
    in >> p.name;

    std::cout << "Возраст: ";
    in >> p.age;

    std::cout << "Диагноз: ";
    in >> p.diagnosis;

    return in;
}
std::string Patient::getName() const {
    return name;
}
int Patient::getAge() const {
    return age;
}
void Patient::edit() {
    std::cout << "Новое имя: ";
    std::cin >> name;

    std::cout << "Новый возраст: ";
    std::cin >> age;

    std::cout << "Новый диагноз: ";
    std::cin >> diagnosis;
}
void Database::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) return;

    Patient p;
    while (file >> p) {
        data.push_back(p);
    }
}

void Database::saveToFile(const std::string& filename) {
    std::ofstream file(filename);

    for (int i = 0; i < data.size(); i++) {
        file << data[i] << std::endl;
    }
}

void Database::print() {
    if (data.empty()) {
        std::cout << "База пустая\n";
        return;
    }

    for (int i = 0; i < data.size(); i++) {
        std::cout << i + 1 << ") " << data[i] << std::endl;
    }
}

void Database::add() {
    Patient p;
    std::cin >> p;
    data.push_back(p);
}

void Database::remove() {
    int n;
    std::cout << "Номер: ";
    std::cin >> n;

    if (n < 1 || n > data.size()) {
        std::cout << "Ошибка\n";
        return;
    }

    data.erase(data.begin() + n - 1);
}

void Database::edit() {
    int n;
    std::cout << "Номер: ";
    std::cin >> n;

    if (n < 1 || n > data.size()) {
        std::cout << "Ошибка\n";
        return;
    }

    data[n - 1].edit();
}

void Database::search() {
    int choice;
    std::cout << "1. Имя\n2. Возраст\n";
    std::cin >> choice;

    if (choice == 1) {
        std::string name;
        std::cout << "Имя: ";
        std::cin >> name;

        for (int i = 0; i < data.size(); i++) {
            if (data[i].getName() == name) {
                std::cout << data[i] << std::endl;
            }
        }
    } else if (choice == 2) {
        int age;
        std::cout << "Возраст: ";
        std::cin >> age;

        for (int i = 0; i < data.size(); i++) {
            if (data[i].getAge() == age) {
                std::cout << data[i] << std::endl;
            }
        }
    }
}
