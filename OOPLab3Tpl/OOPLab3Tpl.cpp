#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructors
    Date() : day(1), month(1), year(2023) {}
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    // Member functions for setting day, month, and year with input validation
    void setDay(int day) {
        if (day < 1 || day > 31) {
            std::cout << "Error! Invalid day value." << std::endl;
            return;
        }
        this->day = day;
    }

    void setMonth(int month) {
        if (month < 1 || month > 12) {
            std::cout << "Error! Invalid month value." << std::endl;
            return;
        }
        this->month = month;
    }

    void setYear(int year) {
        this->year = year;
    }

    // Member functions for getting day, month, and year
    int getDay() const {
        return day;
    }

    int getMonth() const {
        return month;
    }

    int getYear() const {
        return year;
    }

    // Member functions for printing the date in "day month year" and "day.month.year" formats
    void printDate1() const {
        std::string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        std::cout << day << " " << monthNames[month - 1] << " " << year << " year" << std::endl;
    }

    void printDate2() const {
        std::cout << (day < 10 ? "0" : "") << day << "." << (month < 10 ? "0" : "") << month << "." << year << std::endl;
    }
};

int main() {
    // Testing the Date class
    Date d1; // Using the default constructor, date will be January 1, 2023
    std::cout << "Date 1: ";
    d1.printDate1();
    std::cout << "Date 2: ";
    d1.printDate2();

    Date d2(5, 1, 2019); // Using the parameterized constructor, date will be January 5, 2019
    std::cout << "Date 3: ";
    d2.printDate1();
    std::cout << "Date 4: ";
    d2.printDate2();

    // Testing setting day, month, and year
    d1.setDay(15);
    d1.setMonth(6);
    d1.setYear(2022);
    std::cout << "Updated Date 1: ";
    d1.printDate1();
    std::cout << "Updated Date 2: ";
    d1.printDate2();

    return 0;
}

