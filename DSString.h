#ifndef STRING
#define STRING
#pragma once

#include <iostream>
#include <cstring>
#include "DSVector.h"

class DSString{

    private:
        char* data; //stores the c-string
        bool is_substr(int start, DSString& substr); //Helper function of find. Are the next n digits from start of *this the same as substr

    public:

       //Constructors / Destructor
        DSString(); //default constructor sets value of data to "\0"
        DSString(const char* input); //Takes *char and generates DSString
        DSString(const DSString& input); //Copy Constructor
        ~DSString(); //Destructor -- deallocates data

        //overloaded operators
        DSString& operator= (const char* assigner); //An assignment operator -- Allows for the creation of DSStrings using char*
        DSString& operator= (const DSString& assigner); //Assignment operator
        friend  DSString operator+ (const DSString& str1, const DSString& str2); //'+' operator not '+='
        bool operator== (const char* comparee); //Comparison Operator against char*
        bool operator== (const DSString& comparee); //Comparison Operator for DSStrings
        bool operator!= (const DSString& comparee); //Comparison which determines if two quantites are not equal
        bool operator< (const DSString& comparee) const; //Allows for comparisons needed for std::map
        bool operator> (const DSString& comparee) const; //Allows for comparisons needed for sort
        char& operator[] (const int i) const; //returns a single char at specific location

        //Public methods
        int getLength(); //Public strlen() method
        int find(DSString& substr); //finds if substr is a substring of *this -- returns index
        DSString substring(int start, int numChars); //Returns substring of *this -- checks for overflow errors
        char* c_str() const; //ToString() for the DSString
        int to_int() const; //Returns the integer represented in the DSString()
        void clean(); //Converts all letters to lowercase and removes trailing punctuation
        void to_uppercase(); //Converts all letters to uppercase
        friend std::ostream& operator<< (std::ostream& os, const DSString& str); //Prints out DSStrings
        DSVector<DSString> split(char divider); //Splits the DSString based upon divider -- lowercase only
};


#endif
