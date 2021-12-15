//
// Created by Ray Irani on 3/24/21.
#include <iostream>
#include "catch.hpp"
#include "DSString.h"
#include "DSVector.h"
#include "DSList.h"
#include "DSListNode.h"

using namespace std;

TEST_CASE("The DSList functions similar to a doubly linked list"){

    SECTION("The copy constructor of the DSList creates a constructs a new DSList which is a deep copy of another list"){
        DSList<int> test{};
        DSList<int> copy(test);
        REQUIRE_THROWS_AS(copy.begin(),std::out_of_range);
        REQUIRE_THROWS_AS(copy.end(),std::out_of_range);
        for(int i = 0; i < 20; i++){
            test.push_back(i);
        }
        REQUIRE_THROWS_AS(copy.begin(),std::out_of_range);
        DSList<int> copy2(test);
        int i = 0;
        for(auto it = copy2.begin(); it != nullptr; it++){
            REQUIRE(*it == i);
            i++;
        }
        REQUIRE(i == 20);
        i = 19;
        for(auto it = copy2.end(); it != nullptr; it--){
            REQUIRE(*it == i);
            i--;
        }
        REQUIRE(i == -1);
        *test.end() = 57;
        REQUIRE(*copy2.end() == 19);
    }

    SECTION("The Overloaded assignment operator allows for the creation of a deep copy of lists"){
        DSList<int> test{};
        DSList<int> copy = test;
        DSVector<int> test_vals{};
        for(int i = 0; i < 20; i++){
            test.push_back(5*i);
            test_vals.push_back(5*i);
        }
        REQUIRE_THROWS_AS(copy.begin(),std::out_of_range);
        REQUIRE_THROWS_AS(copy.end(),std::out_of_range);
        test = test;
        int i = 0;
        for(auto it = test.begin(); it != nullptr; it++){
            REQUIRE(*it == 5*i);
            i++;
        }
        DSList<int> copy2 = test;
        i = 0;
        for(auto it = copy2.begin(); it != nullptr; it++){
            REQUIRE(*it == test_vals[i]);
            i++;
        }
        test.push_back(5);
        i = 0;
        for(auto it = copy2.begin(); it != nullptr; it++){
            REQUIRE(*it == test_vals[i]);
            i++;
        }
        test = copy2;
        REQUIRE(*test.end() == 95);
        test = DSList<int>{};
        REQUIRE_THROWS_AS(copy.begin(),std::out_of_range);
        REQUIRE_THROWS_AS(copy.end(),std::out_of_range);
    }

    SECTION("The Overloaded Comparison Operator determines if the values of all nodes are the same between two DLLists"){
        DSList<int> test{};
        DSList<int> other{};
        REQUIRE((test == other) == 1);
        REQUIRE((test == test) == 1);
        REQUIRE((other == other) == 1);
        for(int i = 0; i < 20; i++){
            test.push_back(i);
        }
        REQUIRE((test == other) == 0);
        REQUIRE((other == test) == 0);
        for(int i = 0; i < 20; i++){
            other.push_back(i);
        }
        REQUIRE((test == other) == 1);
        DSList<int> test_2{};
        for(int i = 0; i < 20; i++){
            test_2.push_back(5*i);
        }
        REQUIRE((test == test_2) == 0);
        test = DSList<int>{};
        other = DSList<int>{};
        for(int i = 0; i < 20; i++){
            test.push_back(i);
            other.push_back(i);
        }
        other.push_back(20);
        REQUIRE((test == other) == 0);
        REQUIRE((other == test) == 0);
    }

    SECTION("The clone method generates an deep copy of a DLList"){
        DSList<int> test{};
        DSList<int> other = *test.clone();
        REQUIRE((test == other) == 1);
        for(int i = 20; i > 0; i--){
            test.push_back(i);
        }
        REQUIRE((other == test) == 0);
        REQUIRE_THROWS_AS(other.begin(),std::out_of_range);
        REQUIRE_THROWS_AS(other.end(),std::out_of_range);
        DSList<int> other2 = *test.clone();
        REQUIRE((other2 == test) == 1);
        REQUIRE((other == other2) == 0);
    }

    SECTION("The is empty method determines if a DSList has no nodes"){
        DSList<int> test{};
        REQUIRE(test.is_empty());
        test.push_back(5);
        REQUIRE(test.is_empty() == 0);
        test = DSList<int>{};
        REQUIRE(test.is_empty() == 1);
        for(int i = 0; i < 100; i++){
            test.push_back(i);
        }
        REQUIRE(test.is_empty() == 0);
        test.push_back(5);
        REQUIRE(test.is_empty() == 0);
    }

    SECTION("The push back method appends a DSListNode to the end of a DSList"){
        DSList<int> test{};
        for(int i = 0; i < 20; i++){
            test.push_back(i);
            REQUIRE(*test.end() == i);
            REQUIRE(*test.begin() == 0);
        }
        int j = 19;
        for(auto it = test.end(); it != nullptr; it-- ){
            REQUIRE(*it == j);
            j--;
        }
        j = 0;
        for(auto it = test.begin(); it != nullptr; it++){
            REQUIRE(*it == j);
            j++;
        }
        test.push_back(57);
        REQUIRE(*test.end() == 57);
    }

    SECTION("The contains method determines if a node has a certain data item"){
        DSList<int> test{};
        REQUIRE(test.contains(5) == 0);
        for(int i = 0; i < 20; i++){
            test.push_back(i);
        }
        REQUIRE(test.contains(5) == 1);
        REQUIRE(test.contains(57) == 0);
        REQUIRE(test.contains(*test.begin()));
        REQUIRE(test.contains(*test.end()));
    }


    SECTION("The erase_back method removes the last node from the list"){
        DSList<int> test{};
        REQUIRE_THROWS_AS(test.erase_back(),std::out_of_range);
        test.push_back(5);
        test.push_back(6);
        REQUIRE(test.erase_back() == 6);
        REQUIRE(test.erase_back() == 5);
        DSList<int> test_2{};
        for(int i = 0; i < 20; i++){
            test_2.push_back(i);
        }
        int i = 19;
        while(!test_2.is_empty()){
            REQUIRE(test_2.erase_back() == i);
            i--;
        }
        REQUIRE_THROWS_AS(test_2.erase_back(),std::out_of_range);
    }

    SECTION("The erase_front method removes the first node from the list"){
        DSList<int> test{};
        REQUIRE_THROWS_AS(test.erase_front(),std::out_of_range);
        test.push_back(5);
        test.push_back(6);
        REQUIRE(test.erase_front() == 5);
        REQUIRE(test.erase_front() == 6);
        DSList<int> test_2{};
        for(int i = 0; i < 20; i++){
            test_2.push_back(i);
        }
        int i = 0;
        while(!test_2.is_empty()){
            REQUIRE(test_2.erase_front() == i);
            i++;
        }
        REQUIRE_THROWS_AS(test_2.erase_front(),std::out_of_range);
    }

    SECTION("The get_front method returns the pointer for the first node in the list"){
        DSList<int> test{};
        REQUIRE_THROWS_AS(test.get_front(),std::out_of_range);
        test.push_back(5);
        REQUIRE(test.get_front()->data == 5);
        for(int i = 0; i < 20; i++){
            test.push_back(i);
        }
        REQUIRE(test.get_front()->data == 5);
        test = DSList<int>{};
        REQUIRE_THROWS_AS(test.get_front(),std::out_of_range);
        test.push_back(157);
        REQUIRE(test.get_front()->data == 157);
    }

    SECTION("The get_back method returns the pointer for the last node in the list"){
        DSList<int> test{};
        REQUIRE_THROWS_AS(test.get_back(),std::out_of_range);
        test.push_back(5);
        REQUIRE(test.get_back()->data == 5);
        for(int i = 0; i < 20; i++){
            test.push_back(i);
        }
        REQUIRE(test.get_back()->data == 19);
        test = DSList<int>{};
        REQUIRE_THROWS_AS(test.get_back(),std::out_of_range);
        test.push_back(157);
        REQUIRE(test.get_back()->data == 157);
    }

    SECTION("The DSList has an iterator which gives it the ability to traverse itself in two directions"){
        DSList<int> test{};
        REQUIRE_THROWS_AS(test.begin(),std::out_of_range);
        REQUIRE_THROWS_AS(test.end(),std::out_of_range);
        test.push_back(5);
        REQUIRE(*test.begin() == 5);
        REQUIRE(*test.end() == 5);
        DSList<int> test_2{};
        for(int i = 100; i > 0; i--){
            test_2.push_back(i);
        }
        REQUIRE(*test_2.begin() == 100);
        REQUIRE(*test_2.end() == 1);
        int i = 100;
        for(auto it = test_2.begin(); it != nullptr; it++){
            REQUIRE(*it == i);
            i--;
        }
        i = 1;
        for(auto it = test_2.end(); it != nullptr; it--){
            REQUIRE(*it == i);
            i++;
        }

    }

}

