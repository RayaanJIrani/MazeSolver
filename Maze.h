//
// Created by Ray Irani on 3/29/21.
//
#pragma once
#include <iostream>
#include <fstream>
#include <climits>
#include "DSListNode.h"
#include "DSList.h"
#include "DSStack.h"
#include "DSVector.h"
#include "DSString.h"
#include "DSAdjacencyList.h"
#include "Room.h"


class Maze {
private:
    ifstream* inFS; //stores the ifstream for the data input
    DSAdjacencyList<Room> adj_list{}; //stores the adjacency list
    Room start{}; //the room of the starting cords
    Room end{}; //the room of the ending cords

    //add_all_nodes helpers
    DSVector<int> get_first_line(); //reads the first line and returns a vector with the num of rows and cols
    DSVector<DSVector<int>> get_matrix(); //turns the matrix char input into vector of vector of ints
    void add_matrix_edges(const DSVector<DSVector<int>>& matrix); //adds an edge between all live adjacent points in the matrix
    void add_portals(); //goes through the portal list and adds edges between the points of all portals
    void add_start_end(); //notes the value of the start and end room

    //solve helpers
    DSVector<DSStack<Room>> backtrack(); //returns a vector of the set of all unique paths between the begin and end nodes
    int get_cost(const DSStack<Room>& room); //determines the cost of a path
    //generates the output file for the minimum path including cost, num nodes, and actual path
    void make_file1(ofstream& outFS, char* filename, const int min_val = 0, const DSStack<Room>& min_path = DSStack<Room>{});
    //generates the output file for the maximum path including cost and num nodes
    void make_file2(ofstream& outFS, char* filename, const int max_val = 0, const DSStack<Room>& max_path = DSStack<Room>{});

public:
    //constructors
    Maze(ifstream& inFS); //default maze constructor

    //core functionality
    void add_all_nodes(const char* filename); //adds all of the connections from the input file and sets the start and end rooms
    void solve(ofstream& outFS, char* filename1, char* filename2); //determines the shortest and longest solution to the maze
};


