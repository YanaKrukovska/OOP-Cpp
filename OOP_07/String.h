#ifndef C_STRING_H
#define C_STRING_H

#include <utility>
#include <string>
#include <iostream>

#define NDEBUG


using namespace std;

class String {

private:

    size_t _len;

    char *_allocator;


public:

    class BadString;

    class BadIndex;

    String();

    explicit String(const char *);

    explicit String(const char);

    explicit String(const string &);

    String(const String &source, int multiplayer = 1);

    ~String();

    const string STL_string() const;

    const char *c_str() const;

    size_t length() const;


    bool empty() const;

    void clear();


    char &operator[](size_t);

    const char operator[](size_t) const;


    bool operator==(const String &) const;

    bool operator!=(const String &) const;


    bool operator<(const String &) const;

    bool operator<=(const String &) const;

    bool operator>(const String &) const;

    bool operator>=(const String &) const;


    String operator+(const String &) const;

    String &operator=(const String &);

    String &operator=(const string &);

    String &operator+=(const char *);

    String &operator+=(const String &);

    String &operator+=(const string &);

    String &operator=(const char *);

    String &operator=(const char);

};


class String::BadString {
private:
    string _reason;
public:
    explicit BadString(string reason = "") :
            _reason(reason) {

#ifndef NDEBUG
        cout << "Threw bad string error: " << endl;
#endif
    };

    ~BadString() {
#ifndef NDEBUG
        cout << "Deleted bad string error: " << endl;
#endif

    };

    void showMessage() const {
        cerr << "Bad String error: " << _reason << endl;
    }
};

class String::BadIndex {
    size_t _index;

public:
    BadIndex(size_t index = 0) :
            _index(index) {
#ifndef NDEBUG
        cout << "Threw bad index error: " << endl;
#endif
    };

    ~BadIndex() {
#ifndef NDEBUG
        cout << "Deleted bad string error: " << endl;
#endif
    };

    void showMessage() const {
        cerr << "Out of bounds: " << _index << endl;
    };
};


ostream &operator<<(ostream &, const String &);

#endif //C_STRING_H
