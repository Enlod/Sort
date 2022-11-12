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
        { 1, "Андрій",      "Іваненко",     { 1992, 10, 2 } },
        { 2, "Сергій",      "Їжаченко",     { 1991, 4, 5 } },
        { 3, "Леонід",      "Ґалаґан",      { 1994, 1, 12 } },
        { 4, "Ольга",       "Дзюба",        {1995, 6, 22}},
        { 5, "Степан",      "Єремійчук",    { 1989, 12, 10 } },
        { 6, "Жанна",       "Григорчук",    { 1977, 11, 5 } },
        { 7, "Наталка",     "Козачук",      { 1989, 2, 23 } },
        { 8, "Роман",       "Олексюк",      { 1981, 3, 18 } },
        { 9, "Ігор",        "Петрюк",       { 1975, 7, 25 } },
        { 10, "Евгеній",    "Пилип’юк",     { 1965, 9, 11 } },
        { 11, "Марта",      "Чумаченко",    { 1990, 2, 5 } },
        { 12, "Степан",     "Костюченко",   { 2000, 1, 8 } },
        { 13, "Андрій",     "Андрійчук",    { 2001, 4, 10 } },
        { 14, "Ігор",       "Яворівський",  { 1972, 3, 20 } },
        { 15, "Ольга",      "Пилипенко",    { 1988, 2, 26 } },
        { 16, "Ганна",      "Бур’яненко",   { 2001, 3, 1 } },
        { 17, "Степан",     "Буряченко",    { 1999, 10, 5 } },
        { 18, "Леонід",     "Лук’яненко",   { 2002, 11, 23 } },
        { 19, "Евгеній",    "Лук’янченко",  { 2003, 12, 17 } },
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
    assert(PersonComparators::compare("Пилип’юк", "Пилип’юк") == 0);
    assert(PersonComparators::compare("Пилипюк", "Пилип’юк") == 0);
    assert(PersonComparators::compare("Пилип’юк", "Пилипюк") == 0);
    assert(PersonComparators::compare("Ігор", "Андрій") == 1);
}


Ґ: -91 Є: -86 Ї: -81 І: -78 і: -77 ґ: -76 є: -70 ї: -65
А: -64 Б: -63 В: -62 Г: -61 Д: -60 Е: -59 Ж: -58 З: -57 И: -56 Й: -55 К: -54 Л: -53 М: -52 Н: -51 О: -50 П: -49 Р: -48 С: -47 Т: -46 У: -45 Ф: -44 Х: -43 Ц: -42 Ч: -41 Ш: -40 Щ: -39 Ъ: -38 Ы: -37 Ь: -36 Э: -35 Ю: -34 Я: -33 
а: -32 б: -31 в: -30 г: -29 д: -28 е: -27 ж: -26 з: -25 и: -24 й: -23 к: -22 л: -21 м: -20 н: -19 о: -18 п: -17 р: -16 с: -15 т: -14 у: -13 ф: -12 х: -11 ц: -10 ч: -9 ш: -8 щ: -7 ъ: -6 ы: -5 ь: -4 э: -3 ю: -2
*/

/*
Створіть клас Особи, в якому були б передбачені поля:
1) унікальний ідентифікатор
2) ім’я
3) прізвище
4) вік (або дата народження)
Створіть кілька примірників такого класу і додайте їх в зручний для вас контейнер. Розробіть функції для
впорядкування елементів класу за ідентифікатором, за іменем, за прізвищем і за віком. Продемонструйте їх
роботу в основній програмі. Майте на увазі, що стандартні функції впорядкування контейнерів можуть хибно
розставляти слова, що містять букви ї, є, і, ґ або апостроф. Можливо, вам треба буде розробити власну функцію
впорядкування за правилами української абетки.
Список прізвищ для самоперевірки:
Іваненко, Їжаченко, Ґалаґан, Дзюба, Єремійчук, Григорчук, Козачук, Олексюк, Петрюк, Пилип’юк, Чумаченко,
Костюченко, Андрійчук, Яворівський, Пилипенко, Бур’яненко, Буряченко, Лук’яненко, Лук’янченко.

Впорядкований має виглядати так:
Андрійчук, Бур’яненко, Буряченко, Григорчук, Ґалаґан, Дзюба, Єремійчук, Іваненко, Їжаченко, Козачук,
Костюченко, Лук’яненко, Лук’янченко, Олексюк, Петрюк, Пилипенко, Пилип’юк, Чумаченко, Яворівський.
*/