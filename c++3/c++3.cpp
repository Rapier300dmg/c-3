#include <iostream>
#include <cstring>

class String {
private:
    char* str;         
    size_t length;     
    static size_t count; 

public:
    String() : String(80) {} /


    String(size_t size) : length(size) {
        str = new char[length + 1];
        str[0] = '\0';
        ++count;
    }

    String(const char* input) : length(strlen(input)) {
        str = new char[length + 1];
        strcpy(str, input);
        ++count;
    }

    String(const String& other) : length(other.length) {
        str = new char[length + 1];
        strcpy(str, other.str);
        ++count;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    ~String() {
        delete[] str;
        --count;
    }

    void input() {
        std::cout << "Enter a string: ";
        char buffer[1024];
        std::cin.getline(buffer, 1024);
        delete[] str;
        length = strlen(buffer);
        str = new char[length + 1];
        strcpy(str, buffer);
    }

    void print() const {
        std::cout << str << std::endl;
    }

    static size_t getCount() {
        return count;
    }

    size_t getLength() const {
        return length;
    }
};

size_t String::count = 0;

int main() {
    String s1; 
    s1.input();
    s1.print();

    String s2("Hello, world!"); 
    s2.print();

    String s3(50); 
    s3.input();
    s3.print();

    std::cout << "Total String objects created: " << String::getCount() << std::endl;

    return 0;
}
