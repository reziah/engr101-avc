#include<stdio.h>
#include<time.h>
#include<iostream>
#include"E101.h"
#include"camera.h"
#include"maze.h"
#include"node.h"

using namespace std;

/*
 * Storing values to construct nodes:
 *
 * 2d char array - each row represents a Node
 *
 * Columns:
 * 0 -> Node ID
 * 1 -> Northern neighbour's ID
 * 2 -> Eastern neighbour's ID
 * 3 -> Southern neighbour's ID
 * 4 -> Western neighbour's ID
 */

class Maze {
private:
    int mazeType; // 3 == Line Maze, 4 == Wall Maze
    char nodeValues [][];
    map<char, Node> nodeMap;

public:
    Maze(int mazeType) {
        if (mazeType == 3) {
            nodeValues = {
                    // id,N,E,S,W
                    {'A','D','C','','B'},
                    {'B','','A','',''},
                    {'C','A','','',''},
                    {'D','F','','A','E'},
                    {'E','','D','',''},
                    {'F','H','','D','G'},
                    {'G','','F','',''},
                    {'H','','J','F','I'},
                    {'I','K','H','',''},
                    {'J','L','','','H'},
                    {'K','','M','I',''},
                    {'L','','N','J',''},
                    {'M','O','','','K'},
                    {'N','P','','R','L'},
                    {'O','','S','M','Q'},
                    {'P','','','N',''},
                    {'Q','T','O','',''},
                    {'R','N','','',''},
                    {'S','','','','O'},
                    {'T','','','Q',''}
            };

            for (int i = 0; i < (sizeof(nodeValues)/ sizeof(nodeValues[0])); i++) {
                //TODO: may run into a problem with pointers here
                Node newNode(nodeValues[i][0],nodeValues[i][1],nodeValues[i][2],nodeValues[i][3],nodeValues[i][4]);

                nodeMap.insert(pair<char, Node>(nodeValues[i][0], newNode));
            }
        }
    }

    Node getNode(char id) {
        return nodeMap[id];
    };

};

int lineMaze(char previousNode, char destinationNode, int confused, int currentDirection){
    // confused -- 0 = not confused, 1 = confused
    // currentDirection -- 0 = unknown, 1 = north, 2 = east, 3 = south, 4 = west

    int dir = currentDirection;
    Node destination = Maze.getNode(destinationNode);
    Node previous = Maze.getNode(previousNode);


    //TODO: Drive forwards so that previous junction is no longer in sight

    while () { //TODO: check that we are not at a junction
        followLine(); //TODO: implement this
    }

    if (confused == 0) {

        if (destination) {}
    } else if (confused == 1) {

    }
}

