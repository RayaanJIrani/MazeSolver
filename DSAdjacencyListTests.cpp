//
// Created by Ray Irani on 3/28/21.
// Mid Term Submission Final
#include <iostream>
#include "catch.hpp"
#include "DSString.h"
#include "DSVector.h"
#include "DSListNode.h"
#include "DSList.h"
#include "DSStack.h"
#include "DSAdjacencyList.h"


TEST_CASE("The DSAdjacencyList is a object which effectivly stroes the connections between nodes in a graph"){
    SECTION("The add_edge method creates a connction between a source and a destination node"){
        //NOTE: As the 'portals' will be one directional, an edge from A to B does not imply an edge from B to A
        DSAdjacencyList<int> test{};
        test.add_edge(51,7);
        DSList<int> vals{};
        vals.push_back(7);
        REQUIRE((test.get_adjacent_nodes(51) == vals) == 1);
        test.add_edge(51,247);
        vals.push_back(247);
        REQUIRE((test.get_adjacent_nodes(51) == vals) == 1);
        DSAdjacencyList<int> test_2 = DSAdjacencyList<int>{};
        for(int i = 0; i < 50; i++){
            test_2.add_edge(51,i);
        }
        vals = test_2.get_adjacent_nodes(51);
        int i = 0;
        for(auto it = vals.begin(); it != nullptr; it++){
            REQUIRE(*it == i);
            i++;
        }
        vals = DSList<int>{};
        for(int i = 100; i < 150; i++){
            test_2.add_edge(270,i);
            vals.push_back(i);
        }
        REQUIRE((test_2.get_adjacent_nodes(270) == vals) == 1);
        vals = DSList<int>{};
        for(int i = 0; i < 100; i++){
            test_2.add_edge(350,11);
            vals.push_back(11);
        }
        REQUIRE((test_2.get_adjacent_nodes(350) == vals) == 1);
    }

    SECTION("The get adjacent nodes finds all of the nodes which share an edge with a given node"){
        DSAdjacencyList<int> test{};
        REQUIRE_THROWS_AS(test.get_adjacent_nodes(5),std::invalid_argument);
        DSList<int> vals{};
        for(int i = 0; i < 100; i++){
            test.add_edge(157,i);
            vals.push_back(i);
        }
        REQUIRE((test.get_adjacent_nodes(157) == vals) == 1);
        REQUIRE((test.get_adjacent_nodes(157)).contains(157) == 0);
        for(int i = 170; i < 500; i++){
            test.add_edge(157,i);
            vals.push_back(i);
        }
        REQUIRE((test.get_adjacent_nodes(157) == vals) == 1);
        REQUIRE((test.get_adjacent_nodes(157)).contains(157) == 0);
        REQUIRE_THROWS_AS(test.get_adjacent_nodes(2978),std::invalid_argument);
    }

    SECTION("The get_first_edge method returns the pointer to the first edge connected to a node"){
        DSAdjacencyList<int> test{};
        REQUIRE_THROWS_AS(test.get_first_edge(5),std::invalid_argument);
        DSList<int> vals{};
        for(int i = 0; i < 100; i++){
            test.add_edge(157,i);
            vals.push_back(i);
        }
        DSListNode<int>* curr_node = test.get_first_edge(157);
        for(auto it = vals.begin(); it != vals.end(); it++){
            REQUIRE(*it == curr_node->data);
            curr_node = curr_node->next;
        }
        curr_node = test.get_first_edge(157);
        for(auto it = curr_node; it != nullptr; it = it->next){
            REQUIRE(it->data != 157);
        }
        for(int i = 170; i < 500; i++){
            test.add_edge(157,i);
            vals.push_back(i);
        }
        curr_node = test.get_first_edge(157);
        for(auto it = vals.begin(); it != vals.end(); it++){
            REQUIRE(*it == curr_node->data);
            curr_node = curr_node->next;
        }
        curr_node = test.get_first_edge(157);
        for(auto it = curr_node; it != nullptr; it = it->next){
            REQUIRE(it->data != 157);
        }
        REQUIRE_THROWS_AS(test.get_first_edge(2978),std::invalid_argument);
    }

    SECTION("The DSAdjacency List iterator allows for the traversal of the Adjacency List"){

        DSAdjacencyList<int> list;
        auto iter = list.begin(157);
        REQUIRE(iter == nullptr);
        DSVector<int> holder;
        holder.push_back(123);
        for(int i = 0; i < 100; i++){
            list.add_edge(123,i);
            holder.push_back(i);
        }

        auto vectr = holder.begin();
        for(auto it = list.begin(123); it != nullptr; it++){
            REQUIRE(*it == *vectr);
            vectr++;
        }
        DSVector<int> holder_2;
        holder_2.push_back(347);
        for(int i = 500; i < 600; i++){
            list.add_edge(347,i);
            holder_2.push_back(i);
        }
        auto vectr_2 = holder_2.begin();
        for(auto it = list.begin(347); it != nullptr; it++){
            REQUIRE(*it == *vectr_2);
            vectr_2++;
        }
        DSStack<DSAdjacencyList<int>::iterator> iterator_stack{};
        iterator_stack.push(list.begin(123));
        REQUIRE(*iterator_stack.peek() == 123);
        iterator_stack.push(list.begin(347));
        auto vectr_3 = holder_2.begin();
        while(iterator_stack.peek() != nullptr){
            REQUIRE(*vectr_3 == *iterator_stack.peek());
            vectr_3++;
            iterator_stack.peek()++;
        }
        iterator_stack.pop();
        REQUIRE(*iterator_stack.peek() == 123);
        iterator_stack.pop();
        auto it = list.begin(257);
        REQUIRE(it == nullptr);
        it--;
        REQUIRE(it == nullptr);
        it++;
        REQUIRE(it == nullptr);
    }

}



