//
// Created by chris on 12-Apr-18.
//

#ifndef POO_TEMA2_2_STACK_H
#define POO_TEMA2_2_STACK_H

#include <iostream>
#include <stdexcept>
#include "vector.h"

template <typename T>
class queue;

template <typename T>
class stack: public vector <T> {
    friend class queue<T>;

    friend std::istream &operator >>(std::istream &is, stack &stk) {
        stk.clear();

        int sz;
        is >> sz;
        for (int i = 0; i < sz; ++i) {
            T x;
            is >> x;
            stk.add(x);
        }

        return is;
    }

    friend std::ostream &operator <<(std::ostream &os, const stack &stk) {
        os << "Size of stack is " << stk.size() << ". Elements: ";
        for (int i = 0; i < stk.size(); ++i) {
            os << stk[i] << ' ';
        }

        return os;
    }

public:
    stack() {}

    explicit stack(int n) : vector <T> (n) {}

    stack(const stack &other) {
        *this = other;
    }

    ~stack() {}

    virtual void add(T x) {
        vector<T>::push_back(x);
    }

    virtual void pop() {
        try {
            vector<T>::pop_back();
        }
        catch(std::runtime_error &RTE) {
            throw std::runtime_error("Popped empty stack");
        }
    }

    virtual T top() const {
        try {
            return vector<T>::back();
        }
        catch (std::runtime_error &RTE) {
            throw std::runtime_error("Top of empty stack");
        }
    }

    stack &operator =(const stack &other) {
        vector<T>::operator=(other);
        return *this;
    };

    bool operator ==(const stack &other) const {
        return vector<T>::operator==(other);
    }

    bool operator !=(const stack &other) const {
        return vector<T>::operator!=(other);
    }

    bool operator <(const stack &other) const {
        return vector<T>::operator<(other);
    }
};

#endif //POO_TEMA2_2_STACK_H
