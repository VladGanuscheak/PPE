#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

typedef struct person
{
    string name;                             // поле, указывающее имя человека
                                             //
    string surname;                          // поле, указывающее фамилию человека
                                             //
    string middle_name;                      // поле, указывающее отчество человека
                                             //
    string date_of_birth;                    // поле, указывающее дату рпждения человека
                                             //
    string address;                          // поле, указывающее адрес проживания

    person()                           // конструктор по умолчанию
    :  name("")
    ,  surname("")
    ,  middle_name("")
    ,  date_of_birth("")
    ,  address("")
    {}
    person(                            // параметризированный конструктор
           string new_name,
           string new_surname,
           string new_middle_name,
           string new_date_of_birth,
           string new_address
           )
    :  name(new_name)
    ,  surname(new_surname)
    ,  middle_name(new_middle_name)
    ,  date_of_birth(new_date_of_birth)
    {}
    string info()                      // вывод информации в одну строчку
    {
        return name + " " + surname + " " + middle_name + " " + date_of_birth + "\n";
    }
    friend ifstream &operator>>(ifstream &input, person &p)    // перегруженный оператор считывания с файла
    {
        input >> p.name >> p.surname >> p.middle_name >> p.date_of_birth >> p.address;
        return input;
    }
    friend bool operator>(const person& p1, const person& p2)
    {
        string s1 = p1.name + p1.surname + p1.middle_name;
        string s2 = p2.name + p2.surname + p2.middle_name;
        for(int i = 0; i < min(s1.size(), s2.size()); i++)
        if (s1[i] > s2[i]) return true;
        else if (s1[i] < s2[i]) return false;
        return true;
    }
}pers;

#endif // PERSON_H_INCLUDED
