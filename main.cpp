#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <fstream>
#include <iostream>
#include "DSString.h"
#include "DSVector.h"
#include "DSList.h"
#include "DSListNode.h"
#include "Room.h"
#include "Maze.h"

int main(int argc, char* argv[]) {
        if(argc == 1){
            Catch::Session session{};
            session.run(); //Runs the Catch test for DSVector and DSString
        } else {

            ifstream inFS;
            ofstream outFS;
            Maze maze(inFS);
            maze.add_all_nodes(argv[1]);
            maze.solve(outFS,argv[2],argv[3]);
        }
    return 0;
}
