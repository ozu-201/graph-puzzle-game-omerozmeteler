//
// Created by Olcay Taner YILDIZ on 6.03.2023.
//

#ifndef DATASTRUCTURES_CPP_NODE_H
#define DATASTRUCTURES_CPP_NODE_H
#include <string>

using namespace  std;

class NodeString {
private:
    NodeString(string string2);

    string string1;
    NodeString* next;
public:
    explicit NodeString(int data);
    void setNext(NodeString* _next);
    NodeString* getNext();
    string getString();
};


#endif //DATASTRUCTURES_CPP_NODE_H
