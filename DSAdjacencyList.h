//
// Created by Ray Irani on 3/28/21.
// Mid Term Submission Final
#pragma once
#include "DSListNode.h"
#include "DSList.h"
#include <iostream>
#include <stdexcept>

template<class T>
class DSAdjacencyList{
private:
    DSList<DSList<T>> list;
public:
    //constructors
    DSAdjacencyList(); //default constructor

    //core functionality
    //NOTE: As the portal's are one directional,
    // it is not the case that if there exists a edge between A and B, then there exists a edge between B and A.
    void add_edge(const T& source, const T& destination); //Adds a connection between source and destination
    DSList<T> get_adjacent_nodes(const T& node) const; //returns all of the nodes which a given node can go to.
    DSListNode<T>* get_first_edge(const T& node) const; //returns the first node which shares an edge with node.

    //source http://www2.lawrence.edu/fast/GREGGJ/CMSC270/linked/iterators.html
    // Inner class iterator
    class iterator {
    private:
        DSListNode<T> *nodePtr; //the pointer of the node being used
    public:
        iterator() : nodePtr(nullptr) {}
        iterator(DSListNode<T> *newPtr) : nodePtr(newPtr) {} //Creates an iterator using the pointer of a node

        bool operator==(const iterator& itr) const {
            return nodePtr == itr.nodePtr; //Compares two nodes to see if their pointers are the same
        }

        // Overload for the comparison operator !=
        bool operator!=(const iterator& itr) const {
            return nodePtr != itr.nodePtr; //Compares two nodes to see if their pointers are the same
        }

        // Overload for the dereference operator *
        T& operator*() const {
            return nodePtr->data; //returns the data of the node (by reference)
        }

        // Overload for the postincrement operator ++
        iterator operator++(int) {
            if(*this == nullptr){ //if iteraotr is nullptr keep nullptr
                return iterator();
            }
            iterator temp = *this; //save for return
            nodePtr = nodePtr->next; //increments by going to next node
            return temp;
        }

        iterator operator--(int){
            if(*this == nullptr){ //if iteraotr is nullptr
                return iterator(); //return nullptr
            }
            iterator temp = *this; //save for return
            nodePtr = nodePtr->prev; //decrements by going to next prev node
            return temp;
        }

    }; // End of inner class iterator

    //iterator front/back acess
    iterator begin(const T& node) const{
        try{
            iterator holder(this->get_first_edge(node)); //gets the node which connects to node
            holder--; //gets the previous item to that node (ie the node that is input)
            return holder; //returns the iterator which is the first node in the list of edges
        } catch(std::invalid_argument){ //if node has no edges
            return iterator(); //return iterator of val nullptr
        }
    }
};

    template<class T>
    DSAdjacencyList<T>::DSAdjacencyList() {
        list = DSList<DSList<T>>{}; //sets list to empty linked list of linked lists
    }

    template<class T>
    void DSAdjacencyList<T>::add_edge(const T &source, const T &destination) {
        if(list.is_empty()){
            DSList<T> new_list{}; //creates new list
            new_list.push_back(source); //adds source as first item
            new_list.push_back(destination); //adds destination as second item
            list.push_back(new_list); //appends new_list to list
            return; //leaves the method
        }

        for(auto it = list.begin(); it != nullptr; it++){ //iterates through list
            if((*it).get_front()->data == source){ //if the first node in the list is the same as source
                /*
                for(auto is = (*it).begin(); is != nullptr; is++){ //go through all of the nodes that connect to source
                    if(*is == destination){ //if edge already noted do nothing
                        return;
                    }
                }
                 */
                (*it).push_back(destination); //add connection to list
                return;
            }
        }
        //this is only reached if source is not noted as having any connections
        DSList<T> new_list{};  //creates new list
        new_list.push_back(source); //adds source first
        new_list.push_back(destination); //adds desitination second
        list.push_back(new_list); //appends new list to list
    }

    template<class T>
    DSList<T> DSAdjacencyList<T>::get_adjacent_nodes(const T& node) const{
        if(list.is_empty()){ //if list is empty
            throw std::invalid_argument("Empty list - get adjacent nodes DSAdjacencyList"); //node not in list
        }
        for(auto it = list.begin(); it != nullptr; it++){ //iterates through list
            if((*it).get_front()->data == node){ //if the first node in the list has the value of node
                DSList<T> out = (*it); //make a copy of the set the list
                out.erase_front(); //remove the first item (the node)
                return out; //return the edited list
            }
        }
        throw std::invalid_argument("Node not in list - get adjacent nodes DSAdjacencyList"); //node is not in list
    }

    template<class T>
    DSListNode<T>* DSAdjacencyList<T>::get_first_edge(const T& node) const{
        if(list.is_empty()){ //if list is empty
            throw std::invalid_argument("Empty list - get adjacent nodes DSAdjacencyList"); //node not in list
        }
        for(auto it = list.begin(); it != nullptr; it++){ //iterates through list
            if((*it).get_front()->data == node){ //if the first node in the list has the value of node
                DSListNode<T>* first = (*it).get_front();
                return first->next;
            }
        }
        throw std::invalid_argument("Node not in list - get adjacent nodes DSAdjacencyList"); //node is not in list
    }


