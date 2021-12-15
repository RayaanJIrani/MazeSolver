//
// Created by Ray Irani on 3/29/21.
//
#pragma once
#include "DSString.h"
#include <iostream>
#include <fstream>

class Room {
private:
    int row;
    int col;
    int cost;
public:
    //constructor
    Room(int first = 0, int second = 0, int third = 1); //default constructor takes in three values, two for the cords and one for the cost to get to the node
    Room(const Room& other); //copy constructor

    //overloaded operators
    Room& operator= (const Room& other); // Copy Assignment Operator
    bool operator== (const Room& other) const; //Comparison Operator
    bool operator!= (const Room& other) const; //overloaded not equals operator

    //acessor methods
    int get_row() const; //return row by value
    int get_col() const; //return col by value
    int get_cost() const; //return cost by value

    //print
    void print(ofstream& outFS) const; //prints the content Room (row, col, cost) to a ofstream
    void println() const; //prints out the content of Room (row, col, cost) to std::cout

};

