//
// Created by Wojtek on 10.02.2025.
//

#ifndef NODE_H
#define NODE_H



class Node {
private:
    int id, value;
public:
    Node(int id, int value);
    bool operator<(const Node& other) const;
    [[nodiscard]] int getValue() const;
    [[nodiscard]] int getId() const;
};



#endif //NODE_H
