#include "database.h"

Patient::Patient() {
    name = "";
    age = 0;
    diagnosis = "";
}

ostream& operator<<(ostream& out, const Patient& p) {
    out << p.name << " " << p.age << " " << p.diagnosis;
    return out;
}

istream& operator>>(istream& in, Patient& p) {
    in >> p.name >> p.age >> p.diagnosis;
    return in;
}

string Patient::getName() const {
    return name;
}

int Patient::getAge() const {
    return age;
}

void Patient::edit() {
    cout << "Новое имя: ";
    cin >> name;
    cout << "Новый возраст: ";
    cin >> age;
    cout << "Новый диагноз: ";
    cin >> diagnosis;
}

Database::Database() {
    arr = nullptr;
    size = 0;
    capacity = 0;
}

Database::~Database() {
    delete[] arr;
}

void Database::loadFromFile(const string& filename) {
    ifstream file(filename);
    
    if (!file) {
        return;
    }

    Patient temp;
    int count = 0;
    while (file >> temp) {
        count++;
    }
    
    if (count == 0) {
        return;
    }
    
    delete[] arr;
    size = count;
    capacity = count;
    arr = new Patient[capacity];
    
    file.clear();
    file.seekg(0);
 
    for (int i = 0; i < size; i++) {
        file >> arr[i];
    }
    
    file.close();
}

void Database::saveToFile(const string& filename) {
    ofstream file(filename);
    
    for (int i = 0; i < size; i++) {
        file << arr[i] << endl;
    }
    
    file.close();
}

void Database::print() {
    if (size == 0) {
        cout << "База данных пуста!\n";
        return;
    }
    
    cout << "\n=== СПИСОК ПАЦИЕНТОВ ===\n";
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

void Database::add() {
    if (size == capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Patient* newArr = new Patient[newCapacity];
        
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
    
    cout << "Введите имя, возраст и диагноз через пробел: ";
    cin >> arr[size];
    size++;
    
    cout << "Пациент добавлен!\n";
}

void Database::remove() {
    if (size == 0) {
        cout << "Нет записей для удаления!\n";
        return;
    }
    
    int num;
    cout << "Введите номер для удаления (1-" << size << "): ";
    cin >> num;
    
    if (num < 1 || num > size) {
        cout << "Неверный номер!\n";
        return;
    }
    
    for (int i = num - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    size--;
    cout << "Запись удалена!\n";
}

void Database::edit() {
    if (size == 0) {
        cout << "Нет записей для редактирования!\n";
        return;
    }
    
    int num;
    cout << "Введите номер для редактирования (1-" << size << "): ";
    cin >> num;
    
    if (num < 1 || num > size) {
        cout << "Неверный номер!\n";
        return;
    }
    
    cout << "Редактирование записи " << num << ":\n";
    arr[num - 1].edit();
    cout << "Запись отредактирована!\n";
}

void Database::search() {
    if (size == 0) {
        cout << "База данных пуста!\n";
        return;
    }
    
    int choice;
    cout << "\nПоиск по:\n";
    cout << "1. Имени\n";
    cout << "2. Возрасту\n";
    cout << "Выбор: ";
    cin >> choice;
    
    if (choice == 1) {
        string name;
        cout << "Введите имя: ";
        cin >> name;
        
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i].getName() == name) {
                cout << i + 1 << ". " << arr[i] << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "Пациент с именем '" << name << "' не найден!\n";
        }
    }
    else if (choice == 2) {
        int age;
        cout << "Введите возраст: ";
        cin >> age;
        
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i].getAge() == age) {
                cout << i + 1 << ". " << arr[i] << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "Пациенты с возрастом " << age << " не найдены!\n";
        }
    }
    else {
        cout << "Неверный выбор!\n";
    }
}
