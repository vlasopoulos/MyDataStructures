#pragma once

#include <memory>
#include <iostream>
#include "LinkedList.h"

namespace myds {

    template <typename T>
    class Queue {
    public:
        Queue() {
            queue = std::make_unique<LinkedList<T>>();
        }

        void push(const T& data) {
            queue->addFirst(data);
        }

        T pop() {
            if ( isEmpty() ) {
                std::cerr << "Nothing to pop." << std::endl;
                return NULL;
            }
            T data = queue->get(queue->getSize() - 1);
            queue->deleteAt(queue->getSize() -1 );
            return data;
        }

        T peek() const {
            if ( isEmpty() ) {
                std::cerr << "Nothing to peek." << std::endl;
                return NULL;
            }
            return queue->get(queue->getSize() - 1);
        }

        void clear() {
            while (!isEmpty()) pop();
        }

        [[nodiscard]] int getSize() const{
            return queue->getSize();
        }

        [[nodiscard]] bool isEmpty() const{
            return queue->isEmpty();
        }

    private:
        std::unique_ptr<LinkedList<T>> queue;
    };
}


