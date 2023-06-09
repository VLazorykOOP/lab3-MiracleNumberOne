﻿#include <iostream>
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


class Vector {
private:
    int* pointer;
    int size;
    int state;

public:
    static int numObjects;

    // Constructors
    Vector() {
        pointer = new int[1];
        size = 1;
        pointer[0] = 0;
        state = 0;
        numObjects++;
    }

    Vector(int n) {
        pointer = new int[n];
        size = n;
        for (int i = 0; i < n; i++) {
            pointer[i] = 0;
        }
        state = 0;
        numObjects++;
    }

    Vector(int n, int value) {
        pointer = new int[n];
        size = n;
        for (int i = 0; i < n; i++) {
            pointer[i] = value;
        }
        state = 0;
        numObjects++;
    }

    Vector(const Vector& other) {
        size = other.size;
        pointer = new int[size];
        for (int i = 0; i < size; i++) {
            pointer[i] = other.pointer[i];
        }
        state = other.state;
        numObjects++;
    }

    // Destructor
    ~Vector() {
        delete[] pointer;
        numObjects--;
    }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        delete[] pointer;
        size = other.size;
        pointer = new int[size];
        for (int i = 0; i < size; i++) {
            pointer[i] = other.pointer[i];
        }
        state = other.state;
        return *this;
    }

    // Setter function
    void setValue(int index, int value = 0) {
        if (index < 0 || index >= size) {
            state = -1;
            return;
        }
        pointer[index] = value;
    }

    // Getter function
    int getValue(int index) {
        if (index < 0 || index >= size) {
            state = -1;
            return 0;
        }
        return pointer[index];
    }

    // Print function
    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << pointer[i] << " ";
        }
        std::cout << std::endl;
    }

    // Arithmetic operations
    Vector operator+(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.pointer[i] = pointer[i] + other.pointer[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.pointer[i] = pointer[i] - other.pointer[i];
        }
        return result;
    }

    Vector operator*(short value) {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.pointer[i] = pointer[i] * value;
        }
        return result;
    }
// Comparison operations
    bool operator>(const Vector& other) {
        for (int i = 0; i < size; i++) {
            if (pointer[i] <= other.pointer[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator<(const Vector& other) {
        for (int i = 0; i < size; i++) {
            if (pointer[i] >= other.pointer[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator==(const Vector& other) {
        for (int i = 0; i < size; i++) {
            if (pointer[i] != other.pointer[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector& other) {
        return !(*this == other);
    }

    // Static member variable
    static int getNumObjects() {
        return numObjects;
    }

private:
    // Helper function to display error messages
    void displayError() {
        std::cerr << "Error: ";
        if (state == -1) {
            std::cerr << "Index out of range." << std::endl;
        }
        else {
            std::cerr << "Unknown error." << std::endl;
        }
    }

};

// Initialize static member variable
int Vector::numObjects = 0;


class Matrix {
private:
    int* data; // pointer to int array
    int rows; // number of rows
    int cols; // number of columns
    int errorCode; // error code for error handling
    static int count; // static variable to count the number of objects

public:
    // Constructors
    Matrix() : rows(3), cols(3), errorCode(0) {
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = 0; // Initialize with zeros
        }
        count++;
    }

    Matrix(int n) : rows(n), cols(n), errorCode(0) {
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = 0; // Initialize with zeros
        }
        count++;
    }

    Matrix(int n, int m, int value) : rows(n), cols(m), errorCode(0) {
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = value; // Initialize with given value
        }
        count++;
    }

    // Copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), errorCode(other.errorCode) {
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = other.data[i]; // Copy data from other Matrix object
        }
        count++;
    }

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this; // Self-assignment check
        }
        delete[] data; // Deallocate old memory
        rows = other.rows;
        cols = other.cols;
        errorCode = other.errorCode;
        data = new int[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = other.data[i]; // Copy data from other Matrix object
        }
        return *this;
    }

    // Destructor
    ~Matrix() {
        delete[] data;
        count--;
    }

    // Member functions
    void setValue(int value = 0) {
        for (int i = 0; i < rows * cols; i++) {
            data[i] = value; // Set all elements to given value (default is 0)
        }
    }

    int getElement(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            errorCode = 1; // Set error code for out of bounds access
            return 0;
        }
        return data[i * cols + j];
    }

    // Static function to get the count of Matrix objects
    static int getObjectCount() {
        return count;
    }
};

// Initialize static count variable to 0
int Matrix::count = 0;


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


    // Test the Vector class
    Vector v1; // Default constructor
    Vector v2(5); // Constructor with size argument
    Vector v3(3, 2); // Constructor with size and value arguments

    // Assignment operator
    v1 = v3;
    v1.print(); // Expected output: 2 2 2

    // Setter and getter functions
    v2.setValue(2, 10);
    std::cout << v2.getValue(2) << std::endl; // Expected output: 10

    // Arithmetic operations
    Vector v4 = v2 + v3;
    v4.print(); // Expected output: 12 12 12 2 2

    Vector v5 = v4 - v3;
    v5.print(); // Expected output: 10 10 10 0 0

    Vector v6 = v3 * 3;
    v6.print(); // Expected output: 6 6 6

    // Comparison operations
    if (v2 > v3) {
        std::cout << "v2 is greater than v3" << std::endl;
    }
    else {
        std::cout << "v2 is not greater than v3" << std::endl;
    }

    if (v2 < v3) {
        std::cout << "v2 is less than v3" << std::endl;
    }
    else {
        std::cout << "v2 is not less than v3" << std::endl;
    }

    if (v2 == v3) {
        std::cout << "v2 is equal to v3" << std::endl;
    }
    else {
        std::cout << "v2 is not equal to v3" << std::endl;
    }

    if (v2 != v3) {
        std::cout << "v2 is not equal to v3" << std::endl;
    }
    else {
        std::cout << "v2 is equal to v3" << std::endl;
    }

    // Static member variable
    std::cout << "Number of Vector objects created: " << Vector::getNumObjects() << std::endl;


    // Test Matrix class
    // Test default constructor
    Matrix matrix1;
    std::cout << "Matrix 1: " << matrix1.getElement(0, 0) << std::endl;

    // Test constructor with size parameter
    Matrix matrix2(4);
    matrix2.setValue(2);
    std::cout << "Matrix 2: " << matrix2.getElement(0, 0) << std::endl;

    // Test constructor with size and value parameters
    Matrix matrix3(3, 5, 7);
    std::cout << "Matrix 3: " << matrix3.getElement(1, 2) << std::endl;

    // Test copy constructor
    Matrix matrix4 = matrix3;
    std::cout << "Matrix 4: " << matrix4.getElement(1, 2) << std::endl;

    // Test assignment operator
    matrix1 = matrix3;
    std::cout << "Matrix 1 (after assignment): " << matrix1.getElement(1, 2) << std::endl;

    // Test getObjectCount() static function
    std::cout << "Number of Matrix objects: " << Matrix::getObjectCount() << std::endl;

    return 0;
}