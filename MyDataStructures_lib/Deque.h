#pragma once

#include <memory>
#include <iostream>
#include "LinkedList.h"

namespace myds {

    template<typename T>
    class Deque {
    public:
        Deque(){
            deque = std::make_unique<LinkedList<T>>();
        }

        void pushFront(T data) {
            deque->addFirst(data);
        }

        void pushBack(T data) {
            deque->addLast(data);
        }

        T popFront() {
            if ( isEmpty() ) {
                std::cerr << "Nothing to pop." << std::endl;
                return NULL;
            }
            T data = deque->get(0);
            deque->deleteAt(0);
            return data;
        }

        T popBack() {
            if ( isEmpty() ) {
                std::cerr << "Nothing to pop." << std::endl;
                return NULL;
            }
            T data = deque->get(deque->getSize() - 1);
            deque->deleteAt(deque->getSize() -1 );
            return data;
        }

        T peekFront() {
            if ( isEmpty() ) {
                std::cerr << "Nothing to peek." << std::endl;
                return NULL;
            }
            return deque->get(0);
        }

        T peekBack() {
            if ( isEmpty() ) {
                std::cerr << "Nothing to peek." << std::endl;
                return NULL;
            }
            return deque->get(deque->getSize() - 1);
        }

        void clear() {
            while (!isEmpty()) popFront();
        }

        int getSize(){
            return deque->getSize();
        }

        bool isEmpty(){
            return deque->isEmpty();
        }

    private:
        std::unique_ptr<LinkedList<T>> deque;
    };
}
