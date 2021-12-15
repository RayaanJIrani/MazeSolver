//
// Created by Ray Irani on 2/23/21.
//
#include <iostream>
#include "catch.hpp"
#include "DSString.h"
#include "DSVector.h"

using namespace std;

TEST_CASE("The DSVector class implements all of the principal functions of std::vector","[DSVector]"){
    DSVector<int> vector_of_ints(0);
    DSVector<bool> vector_of_bool{};
    DSVector<int> second_vector_of_ints(vector_of_ints);
    DSVector<DSString> vectors_of_DSStrings{};
    DSVector<DSVector<int>> vector_of_vectors_of_ints{};

    SECTION("DSVectors have a property of size which indicates the amount of elements in the vector. This property can be accessed using the get_size method."){
        //Verifies that the size of all of the initial vectors is either 0 (default) or 1 (value input)
        REQUIRE(vector_of_ints.get_size() == 1);
        REQUIRE(vector_of_bool.get_size() == 0);
        REQUIRE(second_vector_of_ints.get_size() == 1);
        REQUIRE(vectors_of_DSStrings.get_size() == 0);
        REQUIRE(vector_of_vectors_of_ints.get_size() == 0);

    }

    SECTION("DSVectors have a property of capacity which indicates the size of the array which the vector is stored in. Capcity can be acessed using the get_capcity method."){
        //Ensures that the capacity is initialized as 10
        REQUIRE(vector_of_ints.get_capcity() == 10);
        REQUIRE(vector_of_bool.get_capcity() == 10);
        REQUIRE(second_vector_of_ints.get_capcity() == 10);
        REQUIRE(vectors_of_DSStrings.get_capcity() == 10);
        REQUIRE(vector_of_vectors_of_ints.get_capcity() == 10);

    }

    SECTION("DSVectors can have items appended to it using the push_back operator") {
        for(int i = 0; i < 20; i++){
            vector_of_ints.push_back(i); //Appends an integer of value i at location i + 1
        }
        REQUIRE(vector_of_ints[0] == 0); //Makes sure that the first item is still 1
        for(int i = 0; i < 20; i++){
            REQUIRE(vector_of_ints[i + 1] == i); //Verifies that the value at location i + 1 is i
        }
        REQUIRE(vector_of_ints.get_size() == 21); //Makes sure that the size is accurately updated
        REQUIRE(vector_of_ints.get_capcity() == 40); //Ensures that the array is resized and capacity is updated
        DSVector<int> new_int_vector{};
        new_int_vector.push_back(125);
        REQUIRE(new_int_vector[0] == 125);
    }

    SECTION("The Subscript Operator can be used to access and mutate individual items in the vector"){
        for(int i = 0; i < 21; i++){
            vector_of_ints.push_back(i); //Makes items 1 to 20 values 0 to 19 respectively
            REQUIRE(vector_of_ints[i+1] == i); //Verifies that the accessor can accurately read values
        }
        for(int i = 0; i < 21; i++){
            vector_of_ints[i] = 2 * i + 1; //Reassigns the values of the items
            REQUIRE(vector_of_ints[i] == 2 * i + 1); //verifies that the reassignment was done correctly
        }
        for(int i = 0; i < 21; i++){
            vector_of_ints[i] = i; //Makes sure that the items can be reassigned
            REQUIRE((vector_of_ints[i] == i) == 1); //Verifies reassignment done correctly
        }
        for(int i = 0; i < 21; i++){
            vector_of_ints[i] = 4 * vector_of_ints[i]; //Verifies that items can be accessed them reassigned
            REQUIRE((vector_of_ints[i] == 4 * i) == 1); //Verifies that the reassignment was done correctly
        }
        REQUIRE_THROWS_AS(vector_of_ints[277],std::out_of_range); //Verifies tests if index too large
        REQUIRE_THROWS_AS(vector_of_ints[-147],std::out_of_range);//And too small
        vectors_of_DSStrings.push_back(DSString("hello"));
        REQUIRE(vectors_of_DSStrings[0][3] == 'l'); //Calls to the Subscript operator can be nested
    }

    SECTION("The overloaded copy assignment operator can be used to create deep copies of vectors"){
        for(int i = 1; i < 20; i++){
            vector_of_ints.push_back(i);
        }
        DSVector<int> new_ints = vector_of_ints;
        for(int i = 0; i < 20; i++){
            REQUIRE(vector_of_ints[i] == new_ints[i]);
            new_ints[i] = 2 * i + 1;
            REQUIRE(vector_of_ints[i] != new_ints[i]);
        }
        DSVector<int> holder{};
        new_ints = holder;
        REQUIRE(new_ints.get_size() == 0);
        REQUIRE(new_ints.get_capcity() == 10);
        holder.push_back(24);
        REQUIRE_THROWS(new_ints[0]);
        for(int i = 0; i < 20; i++){
            new_ints.push_back(i);
        }
        new_ints = new_ints;
        REQUIRE((new_ints == new_ints) == 1);
        REQUIRE(new_ints.get_size() == 20);
    }

    SECTION("The Overloaded Comparison Operator compares two DSVectors to verify they have identical contents"){
        for(int i = 1; i < 20; i++){
            vector_of_ints.push_back(i);
        }
        DSVector<int> holder = vector_of_ints;
        for(int i = 0; i < 20; i++){
            REQUIRE(holder[i] == vector_of_ints[i]);
        }
        REQUIRE((holder == vector_of_ints) == 1);
        holder.push_back(224);
        REQUIRE((holder == vector_of_ints) == 0);
        vector_of_ints.push_back(224);
        REQUIRE((vector_of_ints == holder) == 1);
        holder[0] = 13;
        REQUIRE((vector_of_ints == holder) == 0);
        DSVector<bool> bools{};
        REQUIRE((bools == vector_of_bool) == 1);
    }

    SECTION("The Inset method can be used to insert an item at a specified index in the vector"){
        REQUIRE_THROWS_AS(vector_of_ints.insert(256,14),std::out_of_range);
        REQUIRE_THROWS_AS(vector_of_ints.insert(205,-13),std::out_of_range);
        vector_of_ints.insert(256,1);
        REQUIRE(vector_of_ints[1] == 256);
        for(int i = 0; i < 20; i++){
            vector_of_ints.insert(4 * i, i);
            REQUIRE(vector_of_ints[i] == 4 * i);
        }
        REQUIRE(vector_of_ints[21] == 256);
        REQUIRE(vector_of_ints.get_capcity() == 40);
        REQUIRE(vector_of_ints.get_size() == 22);
        vector_of_ints.insert(1056,22);
        REQUIRE(vector_of_ints[22] == 1056);
    }

    SECTION("The Remove method can remove an item at a specified index in the vector"){
        REQUIRE_THROWS_AS(vector_of_ints.remove(14),std::out_of_range);
        REQUIRE_THROWS_AS(vector_of_ints.remove(-13),std::out_of_range);
        for(int i = 1; i < 20; i++){
            vector_of_ints.push_back(5 * i);
        }
        for(int i = 0; i < 20; i++){
            vector_of_ints.remove(0);
        }
        REQUIRE(vector_of_ints.get_size() == 0);
        REQUIRE_THROWS_AS(vector_of_ints.remove(0),std::out_of_range);
        for(int i = 0; i < 100; i++){
            vector_of_ints.push_back(i);
        }
        for(int i = 23; i < 27; i++){
            vector_of_ints.remove(i);
        }
        for(int i = 23; i < 27; i++){
            REQUIRE(vector_of_ints[i] == 2 * (i - 23) + 24);
        }

    }

    SECTION("The Swap function allows for the swapping of the items at indexes within the vector"){
        DSVector<int> two_num{};
        two_num.push_back(0);
        two_num.push_back(1);
        two_num.swap(0,1);
        REQUIRE(two_num[0] == 1);
        REQUIRE(two_num[1] == 0);
        DSVector<DSString> three_DSString{};
        DSString ABC("ABC");
        DSString DEF("DEF");
        DSString HIJ("HIJ");
        three_DSString.push_back(ABC);
        three_DSString.push_back(DEF);
        three_DSString.push_back(HIJ);
        three_DSString.swap(0,2);
        REQUIRE((three_DSString[0] == HIJ) == 1);
        REQUIRE((three_DSString[2] == ABC) == 1);
        REQUIRE_THROWS_AS(three_DSString.swap(0,3),std::out_of_range);
    }

    SECTION("The DSVector sort function sorts the elements of the DSVector in ascending order using selection sort"){
        DSVector<int> descending{};
        for(int i = 0; i < 20; i++){
            descending.push_back(20-i);
        }
        descending.sort();
        for(int i = 0; i < 20; i++){
            REQUIRE(descending[i] == i + 1);
        }
        DSVector<DSString> unordered_set{};
        unordered_set.push_back(DSString("Ni Hao"));
        unordered_set.push_back(DSString("Hello"));
        unordered_set.push_back(DSString("Hola"));
        unordered_set.push_back(DSString("Bonjour"));
        unordered_set.push_back(DSString("Namaste"));
        unordered_set.sort();
        REQUIRE((unordered_set[0] == "Bonjour") == 1);
        REQUIRE((unordered_set[1] == "Hello") == 1);
        REQUIRE((unordered_set[2] == "Hola") == 1);
        REQUIRE((unordered_set[3] == "Namaste") == 1);
        REQUIRE((unordered_set[4] == "Ni Hao") == 1);
    }

    SECTION("The DSVector has an iterator which allows one to traverse the object with ease"){
        DSVector<int> int_vector{};
        for(int i = 0; i < 25; i++){
            int_vector.push_back(i);
        }
        int num_actions = 0;
        for(auto &c : int_vector){
            c *= 5;
            num_actions++;
        }
        REQUIRE(num_actions == int_vector.get_size());
        REQUIRE(num_actions != int_vector.get_capcity()); //Verifies goes through size rather than capacity
        for(int i = 0; i < 25; i++){
            REQUIRE(int_vector[i] == 5 * i);
            int_vector.push_back(i);
        }
        num_actions = 0;
        for(auto &c: int_vector){
            num_actions++;
        }
        REQUIRE(num_actions == int_vector.get_size());
        REQUIRE(num_actions != int_vector.get_capcity());
    }

    SECTION("DSVector can find the location of an item using the find method"){
        DSVector<int> int_vetor{};
        for(int i = 0; i < 20; i++){
            int_vetor.push_back(i);
        }
        for(int i = 0; i < 20; i++){
            REQUIRE(int_vetor.find(i) == i);
        }
        REQUIRE(int_vetor.find(57) == -1);
        DSVector<DSString> word_vector{};
        word_vector.push_back(DSString("hello"));
        REQUIRE(word_vector.find(DSString("hello")) == 0);
        REQUIRE(word_vector.find(DSString("goodbye")) == -1);
    }

    SECTION("The remove_duplicates frunctions removes all duplicates from any vector"){
        DSVector<int> only_0{};
        for(int i = 0; i < 20; i++){
            only_0.push_back(0);
        }
        only_0.remove_duplicates();
        REQUIRE(only_0.get_size() == 1);
        for(int i = 0; i < 20; i++){
            if(i % 2 == 0){
                only_0.push_back(0);
            } else {
                only_0.push_back(1);
            }
        }
        only_0.remove_duplicates();
        REQUIRE(only_0[0] == 0);
        REQUIRE(only_0[1] == 1);
        DSVector<DSString> keywords{};
        keywords.push_back(DSString("hello"));
        keywords.push_back(DSString("goodbye"));
        keywords.push_back(DSString("hello"));
        keywords.push_back(DSString("hello"));
        keywords.remove_duplicates();
        REQUIRE(keywords.get_size() == 2);
        REQUIRE((keywords[0] == "goodbye") ==1 );
        DSVector<int> empty{};
        empty.remove_duplicates();
        REQUIRE(empty.get_size() == 0);

    }

}


