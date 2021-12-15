#ifndef VECTOR
#define VECTOR
#include <iostream>
#include <stdexcept>
#pragma once

using namespace std;

template<typename T>
class DSVector{
    private:
        T* d; //This is the vector in which the data is stored.
        int size; //This is the amount of elements which are stored in the vector
        int capacity; //This is the size of the array T* d
        void resize(); //Doubles the capacity of the vector

    public:

        //Constructors
        DSVector(); //This is the default constructor
        DSVector(const T& data); //This constructs a vector with one value of type T as input
        DSVector(const DSVector<T>& vector); //Copy constructor

        //Destructor
        ~DSVector(); //Destructor

        //Overloaded Operators
        DSVector<T>& operator= (const DSVector<T>& vector); // Copy Assignment Operator
        T& operator[](int index) const; //Returns the object at the index
        bool operator== (const DSVector<T>& comparee) const;

        //Insertion / Deletion
        void insert(const T& new_item, int index); //Inserts an object T at the index index
        void remove(int index); //Removes the object at index -- moves object directly afterwards to index
        void push_back(const T& new_item); //Appends the object to the back of the working memory

        //Organization
        void sort(); //Sorts the items using bubble sort
        int find(const T& item) const; //Returns the index of where the item is located or -1 if not found
        void remove_duplicates();
        void swap(int i, int j); //Swaps two elements at location i and j

        //Accessors
        int get_size() const; //returns the size of the Vector
        int get_capcity() const; //returns the capacity of the Vector



        //Iterators -- Source: https://internalpointers.com/post/writing-custom-iterators-modern-cpp
        struct Iterator
        {
            // Iterator tags
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = T;
            using pointer           = T*;  // or also value_type*
            using reference         = T&;  // or also value_type&

            Iterator(pointer ptr) : m_ptr(ptr) {} //Iterator default constructor

            T& operator*() const { return *m_ptr;}

            T* operator->() { return m_ptr;}

            // Prefix increment
            Iterator& operator++() { m_ptr++; return *this;}

            // Postfix increment
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp;}

            friend bool operator== (const Iterator& a, const Iterator& b) {
                return a.m_ptr == b.m_ptr;
            };

            friend bool operator!= (const Iterator& a, const Iterator& b) {
                return a.m_ptr != b.m_ptr;
            };

        private:
            T* m_ptr;
        };

        Iterator begin() const{ return Iterator(&d[0]); }
        Iterator end()   const{ return Iterator(&d[this->size]); } // Item at size
};

    template<typename T>
    DSVector<T>::DSVector() {
        this->d = new T[10]; //Creates array of size 10 on heap
        this->capacity = 10; //Makes capacity 10
        this->size = 0; //Sets size to 0
    }

    template<typename T>
    DSVector<T>::DSVector(const T& data) {
        this->d = new T[10]; //Creates array of size 10 on heap
        this->capacity = 10; //Sets capacity to 10
        this->size = 1; //Sets size to 1
        d[0] = data; //Makes the first element of the array data
    }

    template<typename T>
    DSVector<T>::DSVector(const DSVector<T>& vector) {
        this->d = new T[vector.capacity]; //Sets d to array of size of the vector's capacity
        this->capacity = vector.capacity; //Sets the capacity to the vector's capacity
        this->size = vector.size; //Sets the size to the vectors size
        for(int i = 0; i < this->size; i++){ //Iterates through the vector
            d[i] = vector.d[i]; //Sets every element of the vector equal to the element of the
        }
    }

    template<typename T>
    DSVector<T>::~DSVector() {
        delete[] d; //deletes the dynamically allocated d
    }

    template<typename T>
    DSVector<T>& DSVector<T>::operator=(const DSVector<T> &vector) {
        if(this == &vector){ //Checks to see if self = self
            return *this;
        }

        if(d != nullptr){
            delete[] d; //Deletes d if it has data on it
        }
        this->d = new T[vector.capacity]; //Allocates d to an array of one of size vector capacity
        this->capacity = vector.capacity; //Sets the capacity to vector capacity
        this->size = vector.size; //Sets the size to vector size
        for(int i = 0; i < vector.size; i++){ //Iterates through the vector
            d[i] = vector.d[i]; //Sets the elements at i equal to the vector at i
        }
        return *this; //Returns this object
    }

    template<typename T>
    T& DSVector<T>::operator[](int index) const{
        if(index >= this->size || index < 0){ //Checks to see if index is within reasonable range
            throw std::out_of_range("overloaded [] out of range -- DSVEctor"); //Throws error if not
        }
        return d[index]; //Returns the pointer to d[index]
    }

    template<typename T>
    bool DSVector<T>::operator==(const DSVector<T>& comparee) const{
        if(this->size != comparee.size){ //Checks to see if size is the same
            return false; //If the sizes are not the same then the two vetors cannot be the same
        }
        for(int i = 0; i < this->size; i++){ //iterates through both vectors
            if(this->d[i] != comparee.d[i]){
                return false;
            }
        }
        return true;
    }


    template<typename T>
    void DSVector<T>::insert(const T& new_item, int index) {
        if(index >= 0 && index <= this->size){ //Checks to make sure that index is correct
            if(this->size == this->capacity){
                this->resize(); //Doubles the size of the array if the size == capacity
            }
            T holder = this->d[index]; //Holds the current value of the index
            this->d[index] = new_item; //Sets the value at index to new_item
            for(int i = index + 1; i < size+1; i++){ //Iterates through the array from index back
                //Pushes displaced back one loaction
                T displaced = this->d[i];
                this->d[i] = holder;
                holder = displaced;
            }
            size++; //Increeases size by one
        } else {
            throw std::out_of_range("inset out of range -- DSVector"); //Throws out of range error
        }
    }

    template<typename T>
    void DSVector<T>::remove(int index) {
        if(index >= 0 && index < this->size) { //Checks to make sure that index is within size
           // delete d[index];
            for (int i = index; i < this->size - 1; i++) { //Iterates through the array following the deleted item
                d[i] = d[i + 1]; //Moves every item back one slot
            }
            size--; //Decreases size by one
        } else {
            throw std::out_of_range("remove out of range -- DSVector"); //Throws an out of range error
        }
    }

    template<typename T>
    void DSVector<T>::push_back(const T& new_item) {
        if(this->size == this->capacity){ //Checks to see if there is space for a new element
            this->resize(); //Resizes the array to double capacity
        }
        d[size] = new_item; //Places new_item at location size
        size++; //Increases size by one
    }

    template<typename T>
    void DSVector<T>::sort(){
        for (int i = 0; i < this->size-1; i++) { //Iterates through the array n times
            for (int j = 0; j < this->size - i - 1; j++){ //Goes through every element
                if (d[j] > d[j + 1]) { //If the previous element is larger than the next one swap
                    swap(j, j+1);
                }
            }
        }
    }

    template<typename T>
    void DSVector<T>::remove_duplicates(){
        if(size > 0) {
            sort(); //Sorts the array
            T *new_d = new T[this->capacity]; //Creates a new array of length capacity
            int used = 1; //initalizes used to 1 (for the first element being added to array)
            new_d[0] = d[0]; //adds first element to new_d
            for (int i = 1; i < this->size; i++) { //iterates through rest of array
                if (d[i] != d[i - 1]) { //If two adjactent items are diffrent
                    new_d[used] = d[i]; //Add item to new_d
                    used++; //increase size of new_d
                }
            }
            delete[] d; //deletes d
            d = new_d; //sets new_d equal to d
            this->size = used; //sets size to used
        }
    }

    template<typename T>
    int DSVector<T>::find(const T& item) const{
        for(int i = 0; i < this->size; i++){ //Iterates through array
            if(d[i] == item){ //This is a value based comparison
                return i;
            }
        }
        return -1; //returns -1 if not found
    }

    template<typename T>
    void DSVector<T>::swap(int i, int j){
        //If i and j are not in reasonable ranged throws an error
        if(i >= this->size || i < 0 || j >= this->size || j < 0){
            throw std::out_of_range("Out of Range Swap --DSVector");
        }
        if(i != j){ //if i == j then no swap is necessary
            T holder = d[i];
            d[i] = d[j];
            d[j] = holder;
        }
    }

    template<typename T>
    int DSVector<T>::get_size() const{
        return this->size; //returns size
    }

    template<typename T>
    int DSVector<T>::get_capcity() const{
        return this->capacity; //returns capacity
    }

    template<typename T>
    void DSVector<T>::resize() {
        T* new_array = new T[capacity*2]; //Creates an array double the size of capacity
        for(int i = 0; i < this->capacity; i++){ //Iterates through the current array
            new_array[i] = this->d[i]; //Copies all items to new array
        }
        delete[] d; //deletes old array
        this->d = new_array; //makes new array this->d
        capacity *= 2; //doubles capacity
    }


#endif
