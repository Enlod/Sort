// sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include <set>
#include "Person.h"
#include "PersonComparators.h"
#include <cassert>

template<typename Comparator>
using set = std::set<Person, Comparator>;

template<typename Iterable>
void print(const char* label, const Iterable& iterable)
{
    std::cout << label << "\n";

    auto i{ 1 };
    for (auto& elem : iterable)
    {
        std::cout << i << ": " << elem << "\n";
        ++i;
    }

    std::cout << "\n";
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Person persons[] = {
        { 1, "�����",      "��������",     { 1992, 10, 2 } },
        { 2, "�����",      "��������",     { 1991, 4, 5 } },
        { 3, "�����",      "������",      { 1994, 1, 12 } },
        { 4, "�����",       "�����",        {1995, 6, 22}},
        { 5, "������",      "��������",    { 1989, 12, 10 } },
        { 6, "�����",       "���������",    { 1977, 11, 5 } },
        { 7, "�������",     "�������",      { 1989, 2, 23 } },
        { 8, "�����",       "�������",      { 1981, 3, 18 } },
        { 9, "����",        "������",       { 1975, 7, 25 } },
        { 10, "������",    "�������",     { 1965, 9, 11 } },
        { 11, "�����",      "���������",    { 1990, 2, 5 } },
        { 12, "������",     "����������",   { 2000, 1, 8 } },
        { 13, "�����",     "��������",    { 2001, 4, 10 } },
        { 14, "����",       "����������",  { 1972, 3, 20 } },
        { 15, "�����",      "���������",    { 1988, 2, 26 } },
        { 16, "�����",      "���������",   { 2001, 3, 1 } },
        { 17, "������",     "���������",    { 1999, 10, 5 } },
        { 18, "�����",     "���������",   { 2002, 11, 23 } },
        { 19, "������",    "����������",  { 2003, 12, 17 } },
    };

    set<PersonComparators::ID> idSortedSet{ std::begin(persons), std::end(persons) };
    set<PersonComparators::FirstName> firstNameSortedSet{ std::begin(persons), std::end(persons) };
    set<PersonComparators::SecondName> secondNameSortedSet{ std::begin(persons), std::end(persons) };
    set<PersonComparators::Birth> birthSortedSet{ std::begin(persons), std::end(persons) };

    print("Initial list:", persons);
    print("Sorted by id:", idSortedSet);
    print("Sorted by first name:", firstNameSortedSet);
    print("Sorted by second name:", secondNameSortedSet);
    print("Sorted by birth:", birthSortedSet);

    return 0;
}

/*

void test()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    assert(PersonComparators::compare("", "") == 0);
    assert(PersonComparators::compare("1", "") == 1);
    assert(PersonComparators::compare("", "1") == -1);
    assert(PersonComparators::compare("�������", "�������") == 0);
    assert(PersonComparators::compare("�������", "�������") == 0);
    assert(PersonComparators::compare("�������", "�������") == 0);
    assert(PersonComparators::compare("����", "�����") == 1);
}


�: -91 �: -86 �: -81 �: -78 �: -77 �: -76 �: -70 �: -65
�: -64 �: -63 �: -62 �: -61 �: -60 �: -59 �: -58 �: -57 �: -56 �: -55 �: -54 �: -53 �: -52 �: -51 �: -50 �: -49 �: -48 �: -47 �: -46 �: -45 �: -44 �: -43 �: -42 �: -41 �: -40 �: -39 �: -38 �: -37 �: -36 �: -35 �: -34 �: -33 
�: -32 �: -31 �: -30 �: -29 �: -28 �: -27 �: -26 �: -25 �: -24 �: -23 �: -22 �: -21 �: -20 �: -19 �: -18 �: -17 �: -16 �: -15 �: -14 �: -13 �: -12 �: -11 �: -10 �: -9 �: -8 �: -7 �: -6 �: -5 �: -4 �: -3 �: -2
*/

/*
������� ���� �����, � ����� ���� � ���������� ����:
1) ��������� �������������
2) ���
3) �������
4) �� (��� ���� ����������)
������� ����� ��������� ������ ����� � ������� �� � ������� ��� ��� ���������. �������� ������� ���
������������� �������� ����� �� ���������������, �� ������, �� �������� � �� ����. ��������������� ��
������ � ������� �������. ����� �� ����, �� ��������� ������� ������������� ���������� ������ �����
����������� �����, �� ������ ����� �, �, �, � ��� ��������. �������, ��� ����� ���� ��������� ������ �������
������������� �� ��������� ��������� ������.
������ ������ ��� ������������:
��������, ��������, ������, �����, ��������, ���������, �������, �������, ������, �������, ���������,
����������, ��������, ����������, ���������, ���������, ���������, ���������, ����������.

������������� �� ��������� ���:
��������, ���������, ���������, ���������, ������, �����, ��������, ��������, ��������, �������,
����������, ���������, ����������, �������, ������, ���������, �������, ���������, ����������.
*/