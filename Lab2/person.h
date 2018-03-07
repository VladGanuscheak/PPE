#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include <iostream>
#include <fstream>

using namespace std;

typedef struct person
{
    string name;                             // ����, ����������� ��� ��������
                                             //
    string surname;                          // ����, ����������� ������� ��������
                                             //
    string middle_name;                      // ����, ����������� �������� ��������
                                             //
    string date_of_birth;                    // ����, ����������� ���� �������� ��������
                                             //
    string address;                          // ����, ����������� ����� ����������

    person()                           // ����������� �� ���������
    :  name("")
    ,  surname("")
    ,  middle_name("")
    ,  date_of_birth("")
    ,  address("")
    {}
    person(                            // ������������������� �����������
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
    string info()                      // ����� ���������� � ���� �������
    {
        return name + " " + surname + " " + middle_name + " " + date_of_birth + "\n";
    }
    friend ifstream &operator>>(ifstream &input, person &p)    // ������������� �������� ���������� � �����
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
