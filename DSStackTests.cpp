//
// Created by Ray Irani on 3/24/21.
#include <iostream>
#include "catch.hpp"
#include "DSString.h"
#include "DSVector.h"
#include "DSList.h"
#include "DSListNode.h"
#include "DSStack.h"

using namespace std;
TEST_CASE("The DSStack class has the ability to emulate a First in Last Out Data Strcture"){
    SECTION("The copy constructor of the DSStack creates a constructs a new DSStack which is a deep copy of another list"){
        DSStack<int> test{};
        DSStack<int> test_2(test);
        REQUIRE((test_2 == test) == 1);
        test.push(5);
        test_2.push(17);
        REQUIRE(test.peek() == 5);
        DSStack<int> test_3(test_2);
        REQUIRE((test_3 == test_2) == 1);
        REQUIRE((test_3 == test) == 0);
    }
    SECTION("The Overloaded assignment operator allows for the creation of a deep copy of DSStacks"){
        DSStack<int> test{};
        DSStack<int> test_2 = test;
        REQUIRE((test_2 == test) == 1);
        REQUIRE(test_2.is_empty());
        for(int i = 0; i < 100; i++){
            test.push(i);
        }
        REQUIRE((test_2 == test) == 0);
        test_2 = test;
        REQUIRE((test_2 == test) == 1);
        test = DSStack<int>{};
        REQUIRE(test.is_empty());
        REQUIRE(!test_2.is_empty());
    }

    SECTION("The Overloaded Comparison Operator allows for a comparison of the contents of two stacks"){
        DSStack<int> test{};
        DSStack<int> test_2{};
        REQUIRE((test == test) == 1);
        REQUIRE((test_2 == test_2) == 1);
        REQUIRE((test == test_2) == 1);
        test.push(5);
        REQUIRE((test == test_2) == 0);
        test = DSStack<int>{};
        for(int i = 0; i < 20; i++){
            test.push(i);
        }
        for(int i = 0; i < 21; i++){
            test_2.push(i);
        }
        REQUIRE((test == test_2) == 0);
        REQUIRE((test_2 == test) == 0);
    }

    SECTION("The is empty method determines if a Stack has elements within it"){
        DSStack<int> empty{};
        REQUIRE(empty.is_empty());
        empty.push(0);
        REQUIRE(!empty.is_empty());
        empty.pop();
        REQUIRE(empty.is_empty());
        for(int i = 0; i < 20; i++){
            empty.push(i);
        }
        REQUIRE(!empty.is_empty());
        empty.pop();
        REQUIRE(!empty.is_empty());
    }

    SECTION("The push method appends items at the end of the stack"){
        DSStack<int> test{};
        for(int i = 0; i < 20; i++){
            test.push(i);
            REQUIRE(test.peek() == i);
        }
        for(int j = 19; j > 0; j--){
            REQUIRE(test.pop() == j);
        }
        test.push(57);
        REQUIRE(test.peek() == 57);
        test = DSStack<int>{};
        for(int i = 0; i < 20; i++){
            test.push(5*i);
            REQUIRE(test.peek() == 5*i);
        }
        for(int j = 19; j > 0; j--){
            REQUIRE(test.pop() == 5*j);
        }
        test.push(57);
        REQUIRE(test.peek() == 57);
    }

    SECTION("The peek method allows for seeing the top of a particular stack without removing that item") {
        DSStack<int> test{};
        REQUIRE_THROWS_AS(test.peek(), std::out_of_range);
        for (int i = 0; i < 20; i++) {
            test.push(i);
            REQUIRE(test.peek() == i);
        }
        int i = 19;
        while(!test.is_empty()){
            REQUIRE(test.peek() == i);
            test.pop();
            i--;
        }
        REQUIRE_THROWS_AS(test.peek(),std::out_of_range);
        for(int i = 0; i < 100; i++){
            test.push(5*i);
            REQUIRE(test.peek() == 5*i);
            test.pop();
            REQUIRE_THROWS_AS(test.peek(),std::out_of_range);
        }
    }

    SECTION("The pop method removes the top item from the stack and returns its value"){
        DSStack<int> test{};
        REQUIRE_THROWS_AS(test.pop(),std::out_of_range);
        for (int i = 0; i < 20; i++) {
            test.push(i);
            int pop = test.pop();
            REQUIRE(pop == i);
        }
        REQUIRE_THROWS_AS(test.pop(),std::out_of_range);
        for(int i = 0; i < 100; i++){
            test.push(5*i);
            int pop = test.pop();
            REQUIRE(pop == 5*i);
            REQUIRE_THROWS_AS(test.pop(),std::out_of_range);
        }
    }

    SECTION("The contains method determines if a stack contains a given element"){
        DSStack<int> test{};
        REQUIRE(!test.contains(5));
        for(int i = 100; i < 125; i++){
            test.push(i);
        }
        REQUIRE(test.contains(100));
        REQUIRE(!test.contains(0));
        for(int i = 0; i < 100; i++){
            test.push(i);
        }
        REQUIRE(test.contains(0));
        REQUIRE(test.contains(100));
        REQUIRE(!test.contains(500));
        test = DSStack<int>{};
        REQUIRE(!test.contains(5));
    }

    SECTION("The get_len() method returns the number of elements within the stack"){
        DSStack<int> test{};
        REQUIRE(test.get_len() == 0);
        for(int i = 0; i < 25; i++){
            test.push(i);
        }
        REQUIRE(test.get_len() == 25);
        REQUIRE(test.get_len() == 25);
        for(int i = 0; i < 10; i++){
            test.pop();
        }
        REQUIRE(test.get_len() == 15);
        for(int i = 100; i < 125; i++){
            test.push(i);
        }
        REQUIRE(test.get_len() == 40);
    }

    SECTION("The DSStack has an iterator which gives it the ability to traverse itself in two directions"){
        DSStack<int> test{};
        REQUIRE_THROWS_AS(test.begin(),std::out_of_range);
        REQUIRE_THROWS_AS(test.end(),std::out_of_range);
        test.push(5);
        REQUIRE(*test.begin() == 5);
        REQUIRE(*test.end() == 5);
        DSStack<int> test_2{};
        for(int i = 100; i > 0; i--){
            test_2.push(i);
        }
        REQUIRE(*test_2.begin() == 1);
        REQUIRE(*test_2.end() == 100);
        int i = 1;
        for(auto it = test_2.begin(); it != nullptr; it++){
            REQUIRE(*it == i);
            i++;
        }
        i = 100;
        for(auto it = test_2.end(); it != nullptr; it--){
            REQUIRE(*it == i);
            i--;
        }

    }
}
