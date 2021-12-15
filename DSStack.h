//
// Created by Ray Irani on 3/24/21.
#pragma once
#include "DSListNode.h"
#include "DSList.h"
#include <iostream>
#include <stdexcept>

template<class T>
class DSStack{
private:
    DSList<T> stack;

public:
    //constructors / destructor
    DSStack(); //default constructor
    DSStack(const DSStack<T>& clone); //copy constructor

    //overloaded operators
    DSStack<T>& operator= (const DSStack<T>& stack); // Copy Assignment Operator
    bool operator== (const DSStack<T>& stack) const; //Comparison Operator

    //Core Functionality
    bool is_empty() const; //returns if the stack is empty
    void push(const T& data); //appends item to list
    T& peek() const; //sees the top of stack
    T pop(); //removes the top item from stack
    bool contains(const T& val) const; //returns true if a node on stack has the same data as T.

    //Properties
    int get_len() const; //returns the number of elements in the stack


    //source http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html
    // Inner class iterator
    class iterator {
    private:
        DSListNode<T> *nodePtr; //the pointer of the node being used
    public:
        iterator() : nodePtr(nullptr) {}
        iterator(DSListNode<T> *newPtr) : nodePtr(newPtr) {} //Creates an iterator using the pointer of a node

        // Overload for the comparison operator !=
        bool operator!=(const iterator& itr) const {
            return nodePtr != itr.nodePtr; //Compares two nodes to see if their pointers are the same
        }

        // Overload for the dereference operator *
        T& operator*() const {
            return nodePtr->data; //returns the data of the node (by reference)
        }

        // Overload for the postincrement operator ++
        iterator operator++(int) {
            iterator temp = *this;
            nodePtr = nodePtr->prev; //increments by going to prev node (down the stack)
            return temp;
        }

        iterator operator--(int){
            iterator temp = *this;
            nodePtr = nodePtr->next; //decrements by going to next node (up the stack)
            return temp;
        }

    }; // End of inner class iterator

    //iterator front/back acess
    iterator begin() const{
        if(this->stack.get_back() != nullptr) {
            return iterator(this->stack.get_back()); //starts at last item in the stack
        }
        throw std::out_of_range("nullptr used for front -- begin DSStack"); //throws if first node is null pointer
    }

    iterator end() const{
        if(this->stack.get_front() != nullptr) {
            return iterator(this->stack.get_front()); //ends at first item
        }
        throw std::out_of_range("nullptr used for back -- end DSStack"); //throws if last node is null pointer
    }

};

    template<class T>
    DSStack<T>::DSStack(){
        stack = DSList<T>{}; //sets the stack as equal to an empty list
    }

    template<class T>
    DSStack<T>::DSStack(const DSStack<T>& clone){
        stack = clone.stack; //stack is the deep copy of clone's stack
    }

    template<class T>
    DSStack<T>& DSStack<T>::operator=(const DSStack<T> &stack) {
        this->stack = stack.stack; //this->stack is the deep copy of stack's stack
        return *this; //return self
    }

    template<class T>
    bool DSStack<T>::operator== (const DSStack<T>& stack) const{
        return this->stack == stack.stack; //compare the stack's of this and stack using the overloaded list comparison operator
    }

    template<class T>
    bool DSStack<T>::is_empty() const {
        return this->stack.is_empty(); //see if the stack's list is empty
    }

    template<class T>
    void DSStack<T>::push(const T& data) {
        this->stack.push_back(data); //append an item to the stack's list
    }

    template<class T>
    T& DSStack<T>::peek() const {
        if(!this->is_empty()){ //if the stack is not empty
            return *stack.end(); //return the value of the last item of the stack list
        }
        throw std::out_of_range("Stack empty -- peek DSStack"); //throw an error as the stack doesn't have a node to peek at
    }

    template<class T>
    T DSStack<T>::pop() {
        if(!this->is_empty()){ //check if the stack list is empty
            return this->stack.erase_back(); //delete the last item of the stack -- which also returns the value of the last item
        }
        throw std::out_of_range("Stack empty -- pop DSStack"); //if stack is empty, nothing to pop -- error
    }

    template<class T>
    bool DSStack<T>::contains(const T &val) const{
        if(!this->is_empty()){
            for(auto it = stack.begin(); it != nullptr; it++){
                if(val == *it){
                    return true;
                }
            }
        }
        return false;
    }

    template<class T>
    int DSStack<T>::get_len() const {
        if(this->is_empty()){
            return 0;
        }
        int len = 0;
        for(auto it = stack.begin(); it != nullptr; it++){
            len++;
        }
        return len;
    }



