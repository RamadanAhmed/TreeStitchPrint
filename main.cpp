// Program To Stitch neighbour nodes in the same level
// Date         : 12 - 3 - 2018
// Written By   : Ramadan Ahmed

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using std::vector;
using std::queue;

struct Node {
    explicit Node(int _value) : value(_value), left(nullptr),
                                right(nullptr), NextBrother(nullptr) {}

    // data member
    int value;
    Node *left;
    Node *right;
    Node *NextBrother;

};

void stitchTree(Node *parent) {
    queue<Node *> NodesQueue;
    NodesQueue.push(parent);

    // add marker after parent
    NodesQueue.push(nullptr);

    while (!NodesQueue.empty()) {
        Node *current = NodesQueue.front();
        NodesQueue.pop();
        // if you didn't hit marker (end of level)
        if (current != nullptr) {
            // for printing tree
            std::cout << current->value << "--->";
            // next brother is the top node in queue
            current->NextBrother = NodesQueue.front();

            // add the left of current node to queue if exists
            if (current->left) {
                NodesQueue.push(current->left);
            }
            // add the right of current node to queue if exists
            if (current->right) {
                NodesQueue.push(current->right);
            }
        }
            // if hit marker -> add marker at the end of queue
        else if (!NodesQueue.empty()) {
            NodesQueue.push(nullptr);
            // for printing tree
            std::cout << std::endl;
        }
    }
}

int main() {
    vector<Node> vectorNode = {Node(5), Node(7), Node(10), Node(15), Node(17),
                               Node(20), Node(25), Node(27), Node(30)};
    // create Tree
    vectorNode[0].left = &vectorNode[1];
    vectorNode[0].right = &vectorNode[2];
    vectorNode[1].left = &vectorNode[3];
    vectorNode[1].right = &vectorNode[4];
    vectorNode[2].left = &vectorNode[5];
    vectorNode[2].right = &vectorNode[6];
    vectorNode[3].left = &vectorNode[7];
    vectorNode[3].right = &vectorNode[8];
    std::cout << "Stitching Tree and Printing ....\n";
    // stitch Tree and print it
    stitchTree(&vectorNode[0]);

    return 0;
}