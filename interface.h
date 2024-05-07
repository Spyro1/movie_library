#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::cerr;
using std::ofstream;
using std::ifstream;

enum Menu_Options {
    LOG_OUT,
    ADD,
    EDIT,
    SEARCH,
    DELETE,
    LIST_ALL
};

class IOStreamInterface {
public:
    virtual void write(const string& message) = 0;
    virtual void writeLine(const string& message) = 0;
    virtual void read(const string& container) = 0;
    virtual void readLine(const string& container) = 0;
    virtual ~IOStreamInterface() = default;
};

class ConsoleOutputStream : public IOStreamInterface {
public:
    void write(const string& message) override {
        cout << message;
    }
    void writeLine(const string& message) override {
        cout << message << endl;
    }
};

class ConsoleInputStream : public IOStreamInterface {
public:
    void read(const string& message) override {
        //cin >> message;
    }
    void readLine(const string& message) override {
        //cin >> message << endl;
    }
};

class FileOutputStream : public IOStreamInterface {
private:
    ofstream fileStream;
public:
    FileOutputStream(const string& filename) {
        fileStream.open(filename);
        if (!fileStream.is_open()) {
            cerr << "Error opening file: " << filename << endl;
        }
    }
    void write(const char* data, std::streamsize size) {
        if (fileStream.is_open()) {
            fileStream.write(data, size);
        }
    }
    void writeLine(const char* data, std::streamsize size) {
        if (fileStream.is_open()) {
            fileStream.write(data, size);
            fileStream << endl;
        }
    }
    ~FileOutputStream() {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }
};

class FileInputStream : public IOStreamInterface {
private:
    ifstream fileStream;
public:
    FileInputStream(const string& filename) {
        fileStream.open(filename);
        if (!fileStream.is_open()) {
            cerr << "Error opening file: " << filename << endl;
        }
    }
    void readLine(const string& container) override {
        /*if (fileStream.is_open()) {
            std::string line;
            std::getline(fileStream, line);
            container = line;
        }*/
    }
    ~FileInputStream() {
        if (fileStream.is_open()) {
            fileStream.close();
        }
    }
};

bool menu();

void print_start();

void print_menu();

bool function_selector(int menu_num);

int read_number_with_limits(const Menu_Options min, const Menu_Options max);

#endif // INTERFACE_H_INCLUDED
