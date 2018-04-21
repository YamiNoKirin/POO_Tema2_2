#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include "stack.h"
#include "queue.h"
#include "vector_iterator.h"

std::ifstream fin("test.in");
std::ofstream fout("test.out");

class complex {
    friend std::istream &operator >>(std::istream &is, complex &z) {
        char ch = 0;
        is >> z.re >> ch;
        if (ch == '+') {
            is >> ch >> z.im;
        }

        return is;
    }

    friend std::ostream &operator <<(std::ostream &os, const complex &z) {
        os << z.re << "+i" << z.im;
        return os;
    }

private:
    double re, im;

public:
    complex() {
        re = 0;
        im = 0;
    }

    complex(double n) {
        re = n;
        im = 0;
    }

    complex(double _re, double _im) {
        re = _re;
        im = _im;
    }

    complex(const complex &other) {
        *this = other;
    }

    virtual ~complex() {

    }

    complex &operator =(const complex &other) {
        re = other.re;
        im = other.im;
        return *this;
    }

    bool operator ==(const complex &other) const {
        const double eps = 1e-6;
        return (re - other.re < eps and re - other.re > -eps) and (im - other.im < eps and im - other.im > -eps);
    }

    bool operator !=(const complex &other) const {
        return !(*this == other);
    }

    bool operator <(const complex &other) const {
        if (re == other.re) {
            return im < other.im;
        }

        return re < other.re;
    }
};

int main() {
    util::stack<complex> s1;
    util::stack<complex> s2;

    //stack ">>" and "<<"
    fin >> s1;
    fout << s1 << "\n\n";

    //iterator
    util::stack<complex>::iterator it = s1.begin();

    for (auto it = s1.begin(); it != s1.end(); ++it) {
        std::cout << *it << '\n';
    }

    //stack "top()" and "pop()"
    fout << "Checking top and pop for stack:\n";
    while (!s1.empty()) {
        fout << s1.top() << ' ';
        s1.pop();
    }
    fout << "\n\n";

    //stack "="
    s2.add(complex(100, 100));
    s1=s2;
    fout << s1 << "\n\n";

    //stack "=="
    fout << std::boolalpha << "s1 == s1 returns " << (s1 == s1) << "\n\n";

    util::queue <complex> q1;
    util::queue <complex> q2;

    fin >> q1;
    fout << q1 << "\n\n";

    q2.add(5.3);
    q2.add(complex(32.2, 14));

    try {
        q1 = q2;
    }
    catch (std::runtime_error &RTE) {
        std::cout << RTE.what();
    }
    fout << "q2 and q1 after q1 = q2:\n" << q2 << '\n' << q1 << "\n\n";

    //queue "=="
    try {
        fout << std::boolalpha << "q1 == q2 returns " << (q1 == q2) << "\n\n";
    }
    catch (std::runtime_error &RTE) {
        std::cout << RTE.what();
    }

    fout << q1 << '\n';

    //queue "front()" and "pop()"
    while (!q1.empty()) {
        try {
            fout << q1.front() << ' ';
            q1.pop();
        }
        catch(std::runtime_error &RTE) {
            std::cout << RTE.what() << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}