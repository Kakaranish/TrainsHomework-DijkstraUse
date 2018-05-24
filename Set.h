#ifndef _SET_H
#define _SET_H
#include <iostream>
#include <cstdio>
#include <stdexcept>
#include <string>

template <typename T>
class Set
{
  private:
    //Helper class definition
    template <typename U>
    class Node
    {
      public:
        U value;
        Node<U> *nextNode = nullptr;

        Node(U _value, Node<U> *_nextNode = nullptr) : value(_value), nextNode(_nextNode) {}
    };

    //Fields
    Node<T> *headNode = nullptr;
    unsigned size = 0;

  public:
    Set() = default;

    inline bool isEmpty() const { return !headNode ? true : false; }
    inline unsigned getSize() const { return size; }

    T get(unsigned index)
    {
        if (index >= size)
            throw std::runtime_error("Out of range in method .get()");

        Node<T> *tempNode = headNode;
        for (int i = 0; i < index; i++)
            tempNode = tempNode->nextNode;

        return tempNode->value;
    }

    void add(T value)
    {
        if (isEmpty())
        {
            headNode = new Node<T>(value);
            size++;
            return;
        }

        Node<T> *tempNode = headNode, *prev_tempNode = nullptr;

        while (tempNode)
        {
            if (tempNode->value == value)
                return;
            prev_tempNode = tempNode;
            tempNode = tempNode->nextNode;
        }

        prev_tempNode->nextNode = new Node<T>(value);
        size++;
    }

    void remove(T value)
    {
        if (isEmpty())
            throw std::runtime_error("Given value has not been found in set. Unable to remove it!");

        Node<T> *tempNode = headNode, *prev_tempNode = nullptr;

        while (tempNode)
        {
            if (tempNode->value == value)
            {
                if (tempNode == headNode)
                {
                    tempNode = tempNode->nextNode;
                    delete headNode;
                    headNode = tempNode;
                }
                else
                {
                    prev_tempNode->nextNode = tempNode->nextNode;
                    delete tempNode;
                }

                size--;
                return;
            }
            prev_tempNode = tempNode;
            tempNode = tempNode->nextNode;
        }
        throw std::runtime_error("Given value has not been found in set. Unable to remove it!");
    }

    void show()
    {
        if (isEmpty())
        {
            std::cout << "Set is empty" << std::endl;
            return;
        }

        Node<T> *tempNode = headNode;

        while (tempNode != nullptr)
        {
            std::cout << tempNode->value << "\t";
            tempNode = tempNode->nextNode;
        }
        std::cout << std::endl;
    }

    bool contains(T value)
    {
        if (isEmpty())
            return false;

        Node<T> *tempNode = headNode;

        while (tempNode)
        {
            if (tempNode->value == value)
                return true;
            tempNode = tempNode->nextNode;
        }

        return false;
    }
};

#endif