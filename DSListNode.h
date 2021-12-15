#pragma once
//DSListNode.h
template<class T>
class DSListNode {

public:
    DSListNode<T> *next, *prev;
    T data;
    DSListNode(T val, DSListNode*n = nullptr, DSListNode*p = nullptr) {
        next = n;
        prev = p;
        data = val;
    }


};

