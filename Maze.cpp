//
// Created by Ray Irani on 3/29/21.
//

#include "Maze.h"

    //Returns the first line of the input file
    DSVector<int> Maze::get_first_line() {
        char buffer[80]; //string buffer
        inFS->getline(buffer,80); //gets first line
        DSString first_line(buffer); //DString of the first line
        DSVector<DSString> both_str = first_line.split(' '); //splits the two ints of the first line by ' '
        int row = both_str[0].to_int(); //converts the first val to an int
        int col = both_str[1].to_int(); //converts the second val to an int
        DSVector<int> out;
        out.push_back(row); //first item in vector is row
        out.push_back(col); //second is column
        return out;
    }

    //add_all_nodes helper methods
    DSVector<DSVector<int>> Maze::get_matrix() {
        DSVector<int> both_ints = get_first_line(); //gets the value of row and col in vector form
        int row = both_ints[0]; //row is the first num
        int col = both_ints[1]; //col is the second num
        DSVector<DSVector<int>> out{}; //out is the matrix represented in int form
        for(int i = 0; i < row; i++){ //iterates through every row
            DSVector<int> this_row{};
            char buffer_2[col];
            inFS->getline(buffer_2,col+1); //reads the values of all of the data in the row
            for(int j = 0; j < col; j++){ //iterates through the char array
                int val = (buffer_2[j] == '1'); //if the val at location '1' then is 1 else is 0
                this_row.push_back(val);
            }
            out.push_back(this_row); //appends the row to the matrix
        }
        return out;
    }


    void Maze::add_matrix_edges(const DSVector<DSVector<int>>& matrix){
        for(int i = 0; i < matrix.get_size(); i++){ //iterates through the row
            for(int j = 0; j < matrix[i].get_size(); j++){ //iterates through the column
                if(!matrix[i][j]) { //if matrix[i][j] is valid
                    Room curr(i, j, 1); //creates a holder room
                    if (i - 1 >= 0 && !matrix[i - 1][j]) { //is the value to the left valid
                        Room new_room(i - 1, j); //create another holder room (with cost of 1 b/c adjacent rooms)
                        adj_list.add_edge(curr, new_room); //add connection between curr and new_room to adj_list
                    }
                    if (i + 1 < matrix.get_size() && !matrix[i + 1][j]) { //is room to the right valid
                        Room new_room(i + 1, j); //create another holder room (w/ cost 1)
                        adj_list.add_edge(curr, new_room); //add connection between curr and new_room to adj_list
                    }
                    if (j - 1 >= 0 && !matrix[i][j - 1]) { //determines if room above is valid
                        Room new_room(i, j - 1); //create another holder room (w/ cost 1)
                        adj_list.add_edge(curr, new_room);
                    }
                    if (j + 1 < matrix[i].get_size() && !matrix[i][j + 1]) { //determines if room below is valid
                        Room new_room(i, j + 1); //create another holder room (w/ cost 1)
                        adj_list.add_edge(curr, new_room); //add connection between curr and new_room to adj_list
                    }
                }
            }
        }
    }

    void Maze::add_portals() {
        char buffer[80];
        inFS->getline(buffer,80);
        int num_portals = DSString(buffer).to_int(); //reads in number of portals
        for(int i = 0; i < num_portals; i++){ //iterates through number of portals
            inFS->getline(buffer,80); //sets buffer value as line
            DSString line(buffer);
            DSVector<DSString> ints = line.split(' '); //splits the line into five ints
            Room from(ints[0].to_int() - 1,ints[1].to_int() - 1); //first room row and col is vals 0 and 1
            Room to(ints[2].to_int() - 1,ints[3].to_int() - 1,ints[4].to_int()); //second room row, col, and cost is vals 2, 3, 4
            adj_list.add_edge(from,to); //creates edge from to to
        }
    }

    void Maze::add_start_end() {
        char buffer[80];
        inFS->getline(buffer,80); //reads in line
        DSString line(buffer);
        DSVector<DSString> begin_cords = line.split(' '); //splits list based on space
        this->start = Room(begin_cords[1].to_int() - 1,begin_cords[2].to_int() - 1); //vals 1 and 2 are row and col respectivly
        inFS->getline(buffer,80); //reads in below line
        DSString line_2(buffer);
        DSVector<DSString> end_cords = line_2.split(' '); //divides based on space
        this->end = Room(end_cords[1].to_int() - 1,end_cords[2].to_int() - 1); //
    }

    //solve helper functions
    DSVector<DSStack<Room>> Maze::backtrack(){
         DSVector<DSStack<Room>> output{}; //the set of all solutions to the maze
         DSStack<Room> curr{}; //the current stack of moves
         DSStack<DSAdjacencyList<Room>::iterator> pointers{}; //the current state of the pointers for the vals in the curr stack
         curr.push(start); //adds the start node to the curr stack
         pointers.push(adj_list.begin(curr.peek())); //adds the iterator of the start node at begin to pointers stack
         while(!curr.is_empty()){
             if(curr.peek() == end){ //if the stack is a solution
                 output.push_back(curr); //save the stack to the set of solutions
                 curr.pop(); //remove the last step from the stack
                 pointers.pop(); //remove the last pointer from the stack
             } else {
                 pointers.peek()++; //incrament the pointer by one
                if(pointers.peek() == nullptr){ //if the pointer is a nullptr (ie no more connections exist)
                    curr.pop(); //remove the top step
                    pointers.pop(); //remove the top pointer
                } else if(curr.contains(*pointers.peek())){ //if the locaiton the pointer wants to move to is in the stack
                    continue; //go to the next step of the loop (this causes the pointer to incrament by one)
                } else {
                    curr.push(*pointers.peek()); //ads the defrenced value of the pointer (ie a Room) to the curr stack
                    pointers.push(adj_list.begin(curr.peek())); //pushes the pointer of the recently added Room
                }
             }
         }
         return output; //returns the set of all solutions
    }

    int Maze::get_cost(const DSStack<Room>& room){
        int cost = 0;
        for(auto it = room.begin(); it != room.end(); it++){ //iterates through the stack (backwards)
            cost += (*it).get_cost(); //adds the cost of each step to total
        }
        return cost;
    }

    void Maze::make_file1(ofstream& outFS, char* filename, const int min_val, const DSStack<Room>& min_path){
        outFS.open(filename);
        if(min_path == DSStack<Room>{}){ //if the set of solutions is empty
            outFS << "Exit cannot be located" << endl; //return the text that an exit couldn't be located
        } else {
            outFS << min_val << endl; //return the minimum cost on line
            int path_len = min_path.get_len();
            outFS << path_len << endl; //return the path length on a line
            for(auto it = min_path.end(); it != min_path.begin(); it--){ //iterate through the stack backwards
                (*it).print(outFS); //print out the steps
            }
            min_path.peek().print(outFS); //print out the first step
        }
        outFS.close(); //close file
    }

    void Maze::make_file2(ofstream& outFS, char* filename,  const int max_val, const DSStack<Room>& max_path){
        outFS.open(filename);
        if(max_path == DSStack<Room>{}){ //if the set of solutions is empty
            outFS << "Exit cannot be located" << endl; //return the text that an exit couldn't be located
        } else {
            outFS << max_val << endl; //print out max cost
            int path_len = max_path.get_len();
           outFS << path_len << endl; //print out max len
        }
        outFS.close(); //close file
    }


    Maze::Maze(ifstream& inFS){
            this->inFS = &inFS; //set the ifstream stored as the ifstream given
        }

    void Maze::add_all_nodes(const char* filename) {
        inFS->open(filename); //opens file
        DSVector<DSVector<int>> matrix = get_matrix(); //returns the matrix read in int form
        add_matrix_edges(matrix); //adds all the edges of the matrix
        add_portals(); //adds portals
        add_start_end(); //adds start and end rooms
        inFS->close(); //closes file

    }

    void Maze::solve(ofstream& outFS, char* filename1, char* filename2) {
        DSVector<DSStack<Room>> paths = backtrack(); //gets the set of all solutions
        if(paths.get_size() > 0) { //if a solution exists
            int min_cost = INT_MAX; //initalize the min_cost to the largest int
            DSStack<Room> min_path{}; //set the min_path to an empty Stack
            int max_cost = INT_MIN; //set the max cost to the smallest int
            DSStack<Room> max_path{}; //set the max_path to an empty stack
            for (int i = 0; i < paths.get_size(); i++) { //iterates through all solutions
                int curr_cost = get_cost(paths[i]); //curr_cost is the cost of curr path
                if (curr_cost < min_cost) { //if curr is min path
                    min_cost = curr_cost; //set min val to curr val
                    min_path = paths[i]; //record curr as the min path
                }
                if (curr_cost > max_cost) { //if curr is max path
                    max_cost = curr_cost; //set the max cost to curr cost
                    max_path = paths[i]; //record the curr path as longest path
                }
            }
            make_file1(outFS, filename1 ,min_cost,min_path); //make output01 (about min path)
            make_file2(outFS, filename2 ,max_cost, max_path); //make output02 (about max path)
        } else {
            make_file1(outFS,filename1); //generate output files when there is no solution
            make_file2(outFS,filename2); //generate output files when there is no solution
        }

    }

