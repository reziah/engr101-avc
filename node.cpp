#include "node.h"

class Node {
private:
    char ID;
    char northNode;
    char eastNode;
    char southNode;
    char westNode;
    int paths;

public:
    Node(char id, char north, char east, char south, char west) {
        ID = id;
        northNode = north;
        eastNode = east;
        southNode = south;
        westNode = west;
    }
    char getNeighbour(char direction);
};