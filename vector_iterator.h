//
// Created by chris on 21-Apr-18.
//

#ifndef POO_TEMA2_2_VECTOR_ITERATOR_H
#define POO_TEMA2_2_VECTOR_ITERATOR_H

#include "vector"

namespace util {
    template<typename T>
    class iterator {
        friend class vector<T>;
    private:
        T *mPtr;
        int mIndex;

        iterator() {
            mPtr = nullptr;
        }

        iterator(const vector<T> &vect) {
            *this = vect.begin();
        }

        iterator(const vector<T> &vect, T *ptr) {
            mPtr = ptr;
            mIndex = ptr - vect.vect;
        }

    public:
        iterator(const iterator &other) {
            *this = other;
        }

        ~iterator() {}

        T &operator*() {
            return *mPtr;
        }

        T *operator->() {
            return mPtr;
        }

        iterator &operator=(const iterator &other) {
            mPtr = other.mPtr;
            mIndex = other.mIndex;
            return *this;
        }

        iterator &operator++() {
            ++mPtr;
            ++mIndex;
            return *this;
        }

        iterator operator++(int) {
            iterator it = *this;
            ++(*this);
            return it;
        }

        iterator &operator--() {
            --mPtr;
            --mIndex;
            return *this;
        }

        iterator operator--(int) {
            iterator it = *this;
            --(*this);
            return it;
        }

        bool operator==(const iterator &other) const {
            return mIndex == other.mIndex;
        }

        bool operator!=(const iterator &other) const {
            return mIndex < other.mIndex;
        }

        bool operator<(const iterator &other) const {
            return mIndex < other.mIndex;
        }
    };
}

#endif //POO_TEMA2_2_VECTOR_ITERATOR_H
