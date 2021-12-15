#pragma once
#include "DSListNode.h"
#include <iostream>
#include <stdexcept>
//DSList.h
template<class T>
class DSList {
private:
    DSListNode<T> *front, *back;
public:
    //constructors / destructor
    DSList(); // default constructor
    DSList(const DSList<T>& clone); //copy constructor
    ~DSList(); // destructor

    //Overloaded Operators
    DSList<T>& operator= (const DSList<T>& list); // Copy Assignment Operator
    bool operator== (const DSList<T>& list) const; //Comparison Operator

    //Mutating actions on the Linked List
    DSList<T>* clone(); //method returns a deep copy of the List
    bool is_empty() const; //returns true the function has a node in it
    void push_back(const T& v); //Appends a node to the end of the list
    bool contains(const T& v) const; //Returns true if node of value v in list
    T erase_back(); //removes the last node from the list and returns it's value
    T erase_front(); //removes the first node from the list and returns it's value

    //acessor
    DSListNode<T>* get_front() const; //returns the pointer of the first node
    DSListNode<T>* get_back() const; //returns the pointer of the last node



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
            nodePtr = nodePtr->next; //increments by going to next node
            return temp;
        }

        iterator operator--(int){
            iterator temp = *this;
            nodePtr = nodePtr->prev; //decrements by going to previous node
            return temp;
        }

    }; // End of inner class iterator

    //iterator front/back acess
    iterator begin() const{
        if(this->front != nullptr) {
            return iterator(this->front); //returns the pointer of front node
        }
        throw std::out_of_range("nullptr used for front -- begin DSList"); //throws if first node is null pointer
    }

    iterator end() const{
        if(this->back != nullptr) {
            return iterator(this->back); //returns the pointer of last node
        }
        throw std::out_of_range("nullptr used for back -- end DSList "); //throws if last node is null pointer
    }

};


    template<class T>
    DSList<T>::DSList(){
        this->front = this->back = nullptr; //sets all to nullptr
    }

    template<class T>
    DSList<T>::DSList(const DSList<T>& clone) {
        if(clone.front == nullptr){ //if clone is empty list then use defualt
            front = back = nullptr;
        } else {
            this->front = new DSListNode<T>( clone.front->data); //front is clone's front
            DSListNode<T>* tempOther = clone.front->next; //next node in clone
            DSListNode<T>* temp = this->front;
            while (tempOther != nullptr){ //sees if clone has more data
                temp->next = new DSListNode<T>( tempOther->data, nullptr, temp ); //dynamically allocates next w/ next as null
                temp = temp->next; // increments to next
                tempOther = tempOther->next; //increments to next
            }
            this->back = temp; //sets back as last item
        }
    }

    template<class T>
    DSList<T>::~DSList() {
        DSListNode<T>* curr = this->front; //sets curr node to front
        while(curr != nullptr){ //goes through all nodes
            DSListNode<T>* next = curr->next; //finds next node
            delete curr; //deletes curr
            curr = next; //goes to next node
        }
        this->front = this->back = nullptr; //sets all values to nullptr
    }

    template<class T>
    DSList<T>& DSList<T>::operator= (const DSList<T>& list){
        if(this == &list){ //Checks to see if self = self
            return *this;
        }

        if(this->front != nullptr){
            this->~DSList<T>(); //dealloctes if this has any data
        }

        if(list.front == nullptr){ //if list is empty use default constructor
            front = back = nullptr;
        } else {
            this->front = new DSListNode<T>( list.front->data); //front is dynamically allocated an equal to list front
            DSListNode<T>* tempOther = list.front->next; //list's next node
            DSListNode<T>* temp = this->front; //curr node being looked at
            while (tempOther != nullptr){ //iterates through list
                temp->next = new DSListNode<T>( tempOther->data, nullptr, temp ); //dynamically allocates next node as list's next
                temp = temp->next; //goes to next node
                tempOther = tempOther->next; //goes to next node
            }
            this->back = temp; //sets back as the last node
        }

        return *this; //returns self
    }

    template <class T>
    bool DSList<T>::operator== (const DSList<T>& list) const{
        if(this->front == nullptr || list.front == nullptr){ //if either is empty
            return (this->front == nullptr) && (list.front == nullptr); //return if both are empty
        }

        DSListNode<T>* curr = this->front; //curr is the front
        for(auto it = list.begin(); it != nullptr; it++){ //iterates through list
            if(curr == nullptr || *it != curr->data){ //if a node does not exist of it's value is diffrent from curr
                return false; //the two lists are not equal
            }
            curr = curr->next; //go to next node
        }
        return curr == nullptr; //is the curr list the same size as the list DSList? if so they are equal
    }

    template<class T>
    DSList<T>* DSList<T>::clone(){
        DSList<T>* clone = new DSList{}; //create an empty list
        if(this->front == nullptr || this->back == nullptr){
            return clone; //if the this list is empty, return empty list
        }
        DSListNode<T>* curr = this->front; //set curr node to front
        while(curr != nullptr){ //iterate through list
            clone->push_back(curr->data); //adds the allocates the curr node to list
            curr = curr->next; //goes to next node
        }

        return clone; //returns clone
    }

    template<class T>
    bool DSList<T>::is_empty() const{
        return this->front == nullptr; //If the front is empty, then the list has no nodes. Therefore, it must be empty
    }

    template<class T>
    void DSList<T>::push_back(const T& v){
        DSListNode<T>* new_node = new DSListNode<T>(v); //creates a new DSNode with data of v (prev and next = nullptr)
        if(front == nullptr || back == nullptr){ //if the list is empty
            front = new_node; //set the front as the new_node
            back = new_node; //set the back as new_node

        } else {
            this->back->next = new_node; //makes the prev node point to new_node
            new_node->prev = this->back; //the prev node was the last node in the list
            this->back = new_node; //sets back to new_node
        }
    }

    template<class T>
    bool DSList<T>::contains(const T &v) const{
        if(front == nullptr){ //if list is empty cannot contain any elements
            return false;
        }
        DSListNode<T>* curr = this->front; //sets curr to front
        while(curr != nullptr){ //iterates through list
            if(curr->data == v){ //if node is found
                return true; //returns true
            }
            curr = curr->next; //go to next node
        }
        return false; //return false if not found in list
    }

    template<class T>
    T DSList<T>::erase_back() {
        if(front != nullptr){
            DSListNode<T>* condemed = this->back; //last item (to be deleted)
            T output = condemed->data; //output is the last's data
            if(this->back->prev != nullptr){ //If there is another node in the list
                this->back = condemed->prev; //set back as the second to last node
                delete condemed;
                this->back->next = nullptr; //set new back's pointer as null
            } else {
                delete condemed;
                this->front = this->back = nullptr; //set everything to null
            }
            return output;
        }
        throw std::out_of_range("empty DLList erase_back DLList"); //If list is empty
    }

    template<class T>
    T DSList<T>::erase_front(){
        if(front != nullptr){ //if list not empty
            DSListNode<T>* condemed = this->front; //identify condemed as front (to be deleted)
            if(this->front->next != nullptr){ //if another node exists
                this->front = this->front->next; //set front as second node
                this->front->prev = nullptr; //make front's previous nullptr
            } else {
                this->front = this->back = nullptr; //makes list empty
            }
            T output = condemed->data; //out is the first's data
            delete condemed;
            return output;
        }
        throw std::out_of_range("empty DLList erase_front DLList"); //If list is empty
    }

    template<class T>
    DSListNode<T>* DSList<T>::get_front() const{
        if(this->front != nullptr) { //if list isn't empty
            return this->front; //return pointer to first node
        }
        throw std::out_of_range("nullptr used for front -- begin DSList");
    }

    template<class T>
    DSListNode<T>* DSList<T>::get_back() const{
        if(this->back != nullptr) { //if list isn't empty
            return this->back; //return pointer to first node
        }
        throw std::out_of_range("nullptr used for front -- begin DSList");
    }




