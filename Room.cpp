//
// Created by Ray Irani on 3/29/21.
//

#include "Room.h"

    //constructors
    Room::Room(int first, int second, int third){
        row = first; //sets row to first
        col = second; //sets col to second
        cost = third; //sets
    }

    Room::Room(const Room& other){
        this->row = other.row;
        this->col = other.col;
        this->cost = other.cost;
    }

    //overloaded operators
    Room& Room::operator= (const Room& other){
        this->row = other.row;
        this->col = other.col;
        this->cost = other.cost;
        return *this;
    }

    bool Room::operator== (const Room& other) const{
        //compares the cordinates only
        return (this->row == other.row) && (this->col == other.col);
    }

    bool Room::operator!=(const Room &other) const {
        //reverse of ==
        return !(*this == other);
    }

    //acessor methods
    int Room::get_row() const{
        return row; //returns the val of row
    }

    int Room::get_col() const{
        return col; //returns the val of col
    }

    int Room::get_cost() const{
        return cost; //returns the val of cost
    }

    //print method
    void Room::print(ofstream& outFS) const{
        /*
         * Prints out row, col, and cost with spaces in between
         * Shifts row and col by one to adjust my code's origin of (0,0)
         * to output file specs that have origin as (1,1)
         */
        outFS << row+1 << " "  << col+1 << " " << cost << std::endl;
    }

    //println
    void Room::println() const{
        /*
         * Prints out row, col, and cost with spaces in between
         * Shifts row and col by one to adjust my code's origin of (0,0)
         * to output file specs that have origin as (1,1)
         */
        std::cout << row+1 << " "  << col+1 << " " << cost << std::endl;
    }



