//
// Created by Olcay Taner YILDIZ on 6.03.2023.
//

#include "NodeString.h"

NodeString::NodeString(string string2) {
    this->string1 = string2;
    this->next = nullptr;
}

void NodeString::setNext(NodeString *_next) {
    this->next = _next;
}

NodeString *NodeString::getNext() {
    return next;
}

string NodeString::getString() {
    return this->string1;
}

