#include "database.h"

int main() {
    Database db;
    string filename;
    
    cout << "Введите имя файла: ";
    cin >> filename;
    
    db.loadFromFile(filename);
    
    int choice;
    
    while (true) {
        cout << "\n1. Показать все\n";
        cout << "2. Добавить\n";
        cout << "3. Удалить\n";
        cout << "4. Редактировать\n";
        cout << "5. Поиск\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        
        if (choice == 1) {
            db.print();
        }
        else if (choice == 2) {
            db.add();
            db.saveToFile(filename);
        }
        else if (choice == 3) {
            db.remove();
            db.saveToFile(filename);
        }
        else if (choice == 4) {
            db.edit();
            db.saveToFile(filename);
        }
        else if (choice == 5) {
            db.search();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Неверный выбор!\n";
        }
    }
    
    return 0;
}
