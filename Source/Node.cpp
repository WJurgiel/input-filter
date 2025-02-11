//
// Created by Wojtek on 10.02.2025.
//

#include "Node.h"

Node::Node(const int id, const int value) {
    this->id = id;
    this->value = value;
}

bool Node::operator<(const Node &other) const {
    return this->id < other.id;
}

int Node::getValue() const {
    return this->value;
}

int Node::getId() const {
    return this->id;
}
