#pragma once

#include <memory>
#include <iostream>

namespace myds {

    template <typename T>
    struct Node{
        T data;
        std::shared_ptr<Node<T>> next = nullptr;
    };

    template <typename T>
    class LinkedList {
    public:

        void add(const T& data) {
            add(size, data);
        }

        void add(const int idx, const T& data) {
            if (idx > size || idx < 0) {
                std::cerr << "Index out of bounds." << std::endl;
                return;
            }
            auto newNode = std::make_shared<Node<T>>();
            newNode->data = data;
            auto currentNode = head;
            if (idx == 0) {
                newNode->next = head;
                head = newNode;
            } else {
                for (int i=0; i<idx-1; i++) {
                    currentNode = currentNode->next;
                }
                newNode->next = currentNode->next;
                currentNode->next = newNode;
            }
            size++;
        }

        void addFirst(const T& data) {
            add(0, data);
        }

        void addLast(const T& data) { add(data);}

        T get(const int idx) const{
            if (idx > size || idx < 0)  {
                std::cerr << "Index out of bounds." << std::endl;
                return NULL;
            } else {
                auto currentNode = head;
                for (int i=0; i<idx; i++) {
                    currentNode = currentNode->next;
                }
                return currentNode->data;
            }
        }

        void deleteAt(const int idx) {
            if (idx >= size || idx < 0)  {
                std::cerr << "Index out of bounds." << std::endl;
                return;
            } else if (idx == 0){
                head = head->next;
            } else {
                auto currentNode = head;
                for (int i=0; i<idx - 1; i++) {
                    currentNode = currentNode->next;
                }
                auto nextNode = currentNode->next->next;
                currentNode->next = nextNode;
            }
            size--;
        }

        [[nodiscard]] int getSize() const { return size;}

        [[nodiscard]] bool isEmpty() const { return size==0;}

    private:
        std::shared_ptr<Node<T>> head = nullptr;
        int size = 0;
    };
}