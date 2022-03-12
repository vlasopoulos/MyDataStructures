#pragma once

#include <memory>
#include <iostream>

namespace myds{

    enum class Traversal { INORDER, PREORDER, POSTORDER };

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
                    } else if (data > currentNode->data){
                        currentNode = currentNode->rightChild;
                    } else { //duplicate entry
                        if (!allowDuplicates) return;
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

        void remove(const T& data) {
            std::shared_ptr<TreeNode<T>> parentNode = nullptr;
            auto currentNode = root;
            while (currentNode != nullptr && currentNode->data != data) {
                parentNode = currentNode;
                if (data < currentNode->data) {
                    currentNode = currentNode->leftChild;
                } else {
                    currentNode = currentNode->rightChild;
                }
            }
            if (currentNode == nullptr) {
                std::cerr << "Data not found." << std::endl;
                return;
            //if node has 0 to 1 children
            } else if ( currentNode->leftChild == nullptr || currentNode->rightChild == nullptr) {
                std::shared_ptr<TreeNode<T>> temp;
                if (currentNode->leftChild == nullptr) {
                    temp = currentNode->rightChild;
                } else {
                    temp = currentNode->leftChild;
                }
                if (parentNode == nullptr) {
                    //we changed the root
                    return;
                } else if ( currentNode == parentNode->leftChild) {
                    parentNode->leftChild = temp;
                } else {
                    parentNode->rightChild = temp;
                }
            //node has 2 children
            } else {
                parentNode = nullptr;
                std::shared_ptr<TreeNode<T>> temp;

                temp = currentNode->rightChild;
                while (temp->leftChild != nullptr) {
                    parentNode = temp;
                    temp = temp->leftChild;
                }
                if (parentNode != nullptr) {
                    parentNode->leftChild = temp->rightChild;
                } else {
                    currentNode->rightChild = temp->rightChild;
                }
                currentNode->data = temp->data;
            }
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

        void setAllowDuplicates(bool b) {
            allowDuplicates = b;
        }

        void print() {
            printInOrder(root);
        }

        void print(Traversal t) {
            switch (t) {
                case Traversal::INORDER:
                    printInOrder(root);
                    break;
                case Traversal::PREORDER:
                    printPreOrder(root);
                    break;
                case Traversal::POSTORDER:
                    printPostOrder(root);
                    break;
                default:
                    printInOrder(root);
                    break;
            }
            std::cout << std::endl;
        }

        void printInOrder(std::shared_ptr<TreeNode<T>> currentNode) {
            if (currentNode != nullptr) {
                printInOrder(currentNode->leftChild);
                std::cout << currentNode->data << ' ';
                printInOrder(currentNode->rightChild);
            }
        }

        void printPreOrder(std::shared_ptr<TreeNode<T>> currentNode) {
            if (currentNode != nullptr) {
                std::cout << currentNode->data << ' ';
                printPreOrder(currentNode->leftChild);
                printPreOrder(currentNode->rightChild);
            }
        }

        void printPostOrder(std::shared_ptr<TreeNode<T>> currentNode) {
            if (currentNode != nullptr) {
                printPostOrder(currentNode->leftChild);
                printPostOrder(currentNode->rightChild);
                std::cout << currentNode->data << ' ';
            }
        }

    private:
        std::shared_ptr<TreeNode<T>> root = nullptr;
        bool allowDuplicates = false;
    };
}

