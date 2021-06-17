#ifndef LIBRARYSYSTEM_DATE_HPP
#define LIBRARYSYSTEM_DATE_HPP

#include <iostream>
using namespace std;

class Date {
public:

    Date();
    Date(const int& d,const int& m, const int& y);
    Date(const Date &d);
    void printDate();
    int getDay() const;
    void setDay(const int& day);
    int getMonth() const;
    void setMonth(const int& month);
    int getYear() const;
    void setYear(const int& year);
    void increment(); 

private:
    int day;
    int month;
    int year;
};

#endif //LIBRARYSYSTEM_DATE_HPP
