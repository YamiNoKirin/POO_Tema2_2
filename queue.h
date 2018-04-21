//
// Created by chris on 12-Apr-18.
//

#ifndef POO_TEMA2_2_QUEUE_H
#define POO_TEMA2_2_QUEUE_H

#include "stack.h"
#include <stdexcept>
#include <iostream>

namespace util {
//Does not inherit from vector or stack because it's easier to implement a queue as 2 stacks rather than a vector.
    template<typename T>
    class queue {
        friend std::istream &operator>>(std::istream &is, queue &q) {
            q.clear();

            int sz;
            is >> sz;
            for (int i = 0; i < sz; ++i) {
                T x;
                is >> x;
                q.add(x);
            }

            return is;
        }

        friend std::ostream &operator<<(std::ostream &os, const queue &q) {
            os << "Size of queue is " << q.size() << ". Elements: ";
            for (int i = 0; i < q.size(); ++i) {
                os << q[i] << ' ';
            }

            return os;
        }

    private:
        stack <T> add_stack;
        stack <T> pop_stack;

        void dump_to_pop() {
            while (!add_stack.empty()) {
                T most_recent = add_stack.top();
                add_stack.pop();
                pop_stack.add(most_recent);
            }
        }

        T operator[](const int &index) const {
            if (index < pop_stack.size()) {
                int actualIndex = pop_stack.size() - index;
                try {
                    return pop_stack[actualIndex];
                }
                catch (std::runtime_error &RTE) {
                    throw std::runtime_error("Invalid index");
                }
            }

            int actualIndex = index - pop_stack.size();

            try {
                return add_stack[actualIndex];
            }
            catch (std::runtime_error &RTE) {
                throw std::runtime_error("Invalid index");
            }
        }

    public:

        queue() = default;

        queue(int size) {
            add_stack.resize(size);
        }

        queue(const queue &other) = default;

        ~queue() = default;

        void add(T x) {
            add_stack.add(x);
        }

        void pop() {
            if (!pop_stack.empty()) {
                pop_stack.pop();
                return;
            }

            dump_to_pop();

            try {
                pop_stack.pop();
            }
            catch (std::runtime_error &RTE) {
                throw std::runtime_error("Popped empty queue");
            }
        }

        T front() {
            if (!pop_stack.empty()) {
                return pop_stack.top();
            }

            dump_to_pop();

            try {
                return pop_stack.top();
            }
            catch (std::runtime_error &RTE) {
                throw std::runtime_error("Top of empty queue");
            }
        }

        inline void clear() {
            add_stack.clear();
            pop_stack.clear();
        }

        inline int size() const {
            return add_stack.size() + pop_stack.size();
        }

        inline int empty() const {
            return size() == 0;
        }

        queue &operator =(const queue &other) {
            add_stack = other.add_stack;
            pop_stack = other.pop_stack;
            return *this;
        }

        bool operator ==(queue other) const {
            queue thisCpy = *this;

            stack<T> this_dumped;
            stack<T> other_dumped;

            while (!thisCpy.empty()) {
                this_dumped.add(thisCpy.front());
                thisCpy.pop();
            }

            while (!other.empty()) {
                other_dumped.add(other.front());
                other.pop();
            }

            return this_dumped == other_dumped;
        }

        bool operator !=(const queue &other) const {
            return !(*this == other);
        }

        bool operator <(const queue &other) const {
            return size() < other.size();
        }
    };
}

#endif //POO_TEMA2_2_QUEUE_H
