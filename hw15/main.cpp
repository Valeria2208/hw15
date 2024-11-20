//
//  main.cpp
//  hw15
//
//  Created by Valeria Dudinova on 20.11.2024.
//

#include <iostream>
using namespace std;

class Employer
{
public:
    virtual void Print() const = 0; // Чисто віртуальна функція
    virtual ~Employer() {}         // Віртуальний деструктор
};

// Клас President
class President : public Employer
{
    string name; // Власна характеристика
public:
    President(const string& name) : name(name) {}
    void Print() const override
    {
        cout << "President: " << name << endl;
    }
};

// Клас Manager
class Manager : public Employer
{
    string department; // Власна характеристика
public:
    Manager(const string& department) : department(department) {}
    void Print() const override
    {
        cout << "Manager of department: " << department << endl;
    }
};

// Клас Worker
class Worker : public Employer
{
    string position; // Власна характеристика
public:
    Worker(const string& position) : position(position) {}
    void Print() const override
    {
        cout << "Worker, position: " << position << endl;
    }
};

int main()
{
    President president("John Doe");
    Manager manager("Sales");
    Worker worker("Technician");

    // Масив вказівників на базовий клас
    Employer* staff[] = { &president, &manager, &worker };

    // Виклик перевизначених функцій Print()
    for (int i = 0; i < 3; ++i)
    {
        staff[i]->Print();
    }

    return 0;
}

