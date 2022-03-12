#pragma once

#include <memory>

namespace myds{

    template <typename T>
    struct TreeNode {
        T data;
        std::shared_ptr<TreeNode<T>> leftChild = nullptr;
        std::shared_ptr<TreeNode<T>> rightChild = nullptr;
    };

    template <typename T>
    class BinarySearchTree {
    public:

        void insert(const T& data) {
            if (root == nullptr) {
                root = std::make_shared<TreeNode<T>>();
                root->data = data;
            } else {
                std::shared_ptr<TreeNode<T>> parentNode = nullptr;
                auto currentNode = root;
                while (currentNode != nullptr) {
                    parentNode = currentNode;
                    if (data < currentNode->data) {
                        currentNode = currentNode->leftChild;
                    } else {
                        currentNode = currentNode->rightChild;
                    }
                }
                if (data < parentNode->data) {
                    parentNode->leftChild = std::make_shared<TreeNode<T>>();
                    parentNode->leftChild->data = data;
                } else {
                    parentNode->rightChild = std::make_shared<TreeNode<T>>();
                    parentNode->rightChild->data = data;
                }
            }
        }

        //Variadic overload of insert
        template <std::same_as<T> ... Ts>
        void insert(const T& data, const Ts& ... ts) {
            insert(data);
            insert(ts...);
        }

        bool contains(const T& data) const{
            auto currentNode = root;
            while (currentNode != nullptr && currentNode->data != data) {
                if (data < currentNode->data) {
                    currentNode = currentNode->leftChild;
                } else {
                    currentNode = currentNode->rightChild;
                }
            }
            if (currentNode == nullptr) return false;
            else return true;
        }

    private:
        std::shared_ptr<TreeNode<T>> root = nullptr;
    };
}

