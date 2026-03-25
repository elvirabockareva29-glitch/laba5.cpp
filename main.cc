#include "database.h"

int main() {
    Database db;
    std::string filename;

    std::cout << "Введите имя файла: ";
    std::cin >> filename;

    db.loadFromFile(filename);

    int choice;

    while (true) {
        std::cout << "\n1. Показать\n2. Добавить\n3. Удалить\n4. Редактировать\n5. Поиск\n0. Выход\n";
        std::cin >> choice;

        if (choice == 1) db.print();
        else if (choice == 2) { db.add(); db.saveToFile(filename); }
        else if (choice == 3) { db.remove(); db.saveToFile(filename); }
        else if (choice == 4) { db.edit(); db.saveToFile(filename); }
        else if (choice == 5) db.search();
        else if (choice == 0) break;
        else std::cout << "Ошибка\n";
    }
}
