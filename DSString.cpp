//
// Created by Ray Irani on 2/3/21.
//
#include "DSString.h"
#include <cstring>
#include <stdexcept>

    //Private method
    bool DSString::is_substr(int start, DSString& substr){
        int substr_len = std::strlen(substr.data); //The portion of the string which is being compared is the same as the size of the substr
        for(int i = 0; i < substr_len; ++i) {
            if (std::tolower(substr.data[i]) != std::tolower(data[start+i])) { //If any char is different not substr
                return false;
            }
        }
        return true;
    }

    //constructors
    DSString::DSString(){
        data = new char[1];
        data[0] = '\0'; //Ensures that data is not nullptr.
    }

    DSString::DSString(const char* input){
        int len = std::strlen(input);
        data = new char[len + 1]; //This allows for space for the "\0"
        std::strcpy(data, input);
        data[len] = '\0'; //Ensures that '\0' is added

    }

    DSString::DSString(const DSString& input){
        int len = std::strlen(input.data);
        data = new char[len + 1]; //This allows space for the "\0"
       std::strcpy(data,input.data);
        data[len] = '\0'; //Ensures that '\0' is added
    }

    // Destructor
    DSString::~DSString(){
        delete[] data; //deletes the data from the heap
    }

    //overloaded operators

    //asignment operator
    DSString& DSString::operator= (const char* assigner){
        if(data != nullptr){
            delete[] data;
        }
        int len = std::strlen(assigner);
        data = new char[len + 1]; //allocates data to be the same as assigner.
        std::strcpy(data,assigner);
        data[len] = '\0';
        return *this;
    }

    DSString& DSString::operator= (const DSString& assigner){
        if (this == &assigner) {
            return *this;
        }

        if(data != nullptr){ //Sees if data needs to be used
            delete[] data; //deallocates the data
        }
        int len = std::strlen(assigner.data);
        data = new char[len + 1]; //This causes a deep copy of the assigner
        std::strcpy(data, assigner.data);
        data[len] = '\0';
        return *this;
    }

    //appends the values of assigneer data to output
    DSString operator+ (const DSString& str1, const DSString& str2){
        //Creates new_data which is the combined size of str1 and str2
        char* new_data;
        new_data = new char[std::strlen(str1.data) + std::strlen(str2.data) + 1];
        if(str1.data != nullptr){
            std::strcpy(new_data,str1.data); //Adds str1 to new_data
        }
        if(str2.data != nullptr){
            std::strcat(new_data,str2.data); //Appends str2 to new data
        }
        DSString output(new_data); //Creates DSString output from new_data
        delete[] new_data; //deallocates new_data
        return output; //returns output
    }

    //comparison
    bool DSString::operator== (const char* comparee){
        return std::strcmp(data, comparee) == 0; //The values of two strings are equivalent when strcmp == 0
    }

    bool DSString::operator== (const DSString& comparee){
        //If either is null, both must be null
        if(data == nullptr || comparee.data == nullptr){
            return (data == nullptr && comparee.data == nullptr);
        }
        return std::strcmp(data,comparee.data) == 0;
    }

    bool DSString::operator!= (const DSString& comparee){
        //If either is null, both shouldn't be (XOR)
        if(data == nullptr || comparee.data == nullptr){
            return !(data == nullptr && comparee.data == nullptr);
        }
        return std::strcmp(data,comparee.data) != 0; //Values return a diffrence
    }

    bool DSString::operator< (const DSString& comparee) const{
        try {
            return this->to_int() < comparee.to_int();
        } catch (std::invalid_argument){
            //returns true if this.data is before comparee.data alphabetically.
            return std::strcmp(data,comparee.data) < 0;
        }
    }

    bool DSString::operator> (const DSString& comparee) const{
        try {
            return this->to_int() > comparee.to_int();
        } catch (std::invalid_argument){
            //returns true if this.data is after comparee.data alphabetically.
            return std::strcmp(data,comparee.data) > 0;
        }
    }

    //overloads [] operator allows me to element in a DSString
    char& DSString::operator[] (const int i) const{
        if(data != nullptr && i >= 0 && i < std::strlen(data)) { //checks range
            return data[i];
        }
        throw std::out_of_range("Out of Range Exception from [] operator call -- DSString");
    }

    //public length function
    int DSString::getLength(){
        if(data != nullptr) {
            return std::strlen(data);
        }
        return 0; //DSStrings with no data in data have length of 0.
    }

    //find method
    int DSString::find(DSString& substr){
        int sub_str_len = std::strlen(substr.data);
        int len = std::strlen(data);
        int len_diff = len - sub_str_len; //finds diffrence between the length of *this and substr
        if( data != nullptr && substr.data != nullptr && len_diff >= 0){ //makes sure that there is data in both places and substring len is longer than
            for(int i = 0; i <= len_diff; ++i){
                if(is_substr(i, substr)){ //is_substr checks if a substr
                    return i;
                }
            }
        }
        return -1;
    }

    //This creates a susbtring the string in question (num chars does not include '\0' which is added at end
    DSString DSString::substring(int start, int numChars){
        if(data == nullptr || numChars == 0){ //checks for edge cases
            return DSString("");
        }
        if(this->getLength() < start+numChars){ //makes sure substr request does not cause a out of range exception
            throw std::out_of_range("Out of Range Exception from substring -- DSString");
        }
        char new_data [numChars + 1];
        for(int i = 0; i < numChars; ++i){
            new_data[i] = std::tolower(data[i+start]); //all substrings are returned in lowercase
        }
        new_data[numChars] = '\0'; //ensures null-char added at end
        return DSString(new_data);
    }

    //Returns Null terminated string of data
    char* DSString::c_str() const{
        if(data != nullptr){
            return data;
        }
        char* out; // ensures that in an edge case a null char is returned
        out[0] = '\0';
        return out;
    }

    int DSString::to_int() const{
        if(data == nullptr){ //Throws an error is data doesn't have a refrence
            throw std::invalid_argument("to_int -- DSString");
        }
        int atoi_out = std::atoi(data); //Converts char* to int using atoi (returns 0 for error)
        if(atoi_out == 0 && data[0] != '0'){
            throw std::invalid_argument("to_int() -- DSString");
        }
        return atoi_out;
    }


    void DSString::clean() {
        if(data != nullptr){
            int len = std::strlen(data);
            if(len == 0){
                return;
            }
            //Checks if last element is punctuation
            while(data[len-1] == '!' || data[len-1] == '.' || data[len-1] == '?' || data[len-1] == ' '){
                len--; //removes one from internal length
            }
            char new_data[len + 1];
            new_data[len] = '\0';
            for(int i = 0; i < len; i++){
                new_data[i] = std::tolower(data[i]); //decapitalizies every character in data
            }
            delete[] data; //deletes data
            data = new char[len + 1]; //This causes a deep copy of the assigner
            std::strcpy(data, new_data); //makes data = new_data
            data[len] = '\0'; //last element of data is '\0'
        }
    }

    void DSString::to_uppercase() {
        if(data == nullptr){ //throws error is data is nullpter
            throw std::invalid_argument("to_uppercase -- DSString empty data");
        }
        for(int i = 0; i < std::strlen(data);i++){ //iterates through string
            data[i] = std::toupper(data[i]); //makes every char uppercase
        }
    }

    //Prints out string
    std::ostream& operator<< (std::ostream& os, const DSString& str){
        os << str.c_str();
        return os;
    }

    DSVector<DSString> DSString::split(char divider){
    //NOTE: for reasons of Algorithmic efficency this function only returns words with character lengths greater than 3.
    //(The above note has been removed) to fix remove comments
        int last_split = 0;
        int len = std::strlen(data);
        DSVector<DSString> words; //This stores all of the words which have been split
        for(int i = 0; i < len; ++i){
            if(data[i] == divider){ //Notices the divider char
                DSString word = this->substring(last_split,i-last_split); //Creates substring wihtout divider chr
             //   if(i-last_split > 3) { //Removes words of length <= 3 (As per the recommendation of DR. F)
                    words.push_back(word);
            //    }
                last_split = i+1;
            }
        }
      //  if(len-last_split > 3) { //removes words len <= 3.
            DSString word = this->substring(last_split, len - last_split); //DSString from last split to end
            words.push_back(word);
     //   }
        return words;
    }














