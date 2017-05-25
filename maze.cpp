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

            if (mazeType == 4) {
                nodeValues = {
                        // id,N,E,S,W
                        {'A','B','','',''},
                        {'B','','C','A',''},
                        {'C','','','D','B'},
                        {'D','C','E','',''},
                        {'E','F','G','','D'},
                        {'F','','I','E','H'},
                        {'G','I','','','E'},
                        {'H','','F','',''},
                        {'I','J','','','F'},
                        {'J','L','','I','K'},
                        {'K','','J','',''},
                        {'L','','','J',''}
                };
            }
        }
    }

    Node getNode(char id) {
        return nodeMap[id];
    };

};

boolean hasRelativePaths(Node node, String junctionpaths, int direction){
    char paths[4] = new char[];
    if (direction != 0) {
        if (node.getNeighbour('N') != null) {
            paths[0] = 'N';
        }
        if (node.getNeighbour('E') != null) {
            paths[1] = 'E';
        }
        if (node.getNeighbour('S') != null) {
            paths[2] = 'S';
        }
        if (node.getNeighbour('W') != null) {
            paths[3] = 'W';
        }

        // change true direction to relative direction.
        for (int i = 1; i < direction; i++) {
            char x = paths[0];
            paths[0] = paths[1];
            paths[1] = paths[2];
            paths[2] = paths[3];
            paths[3] = x;
        }

    }
    if (junctionpaths.find("N") != std::string::npos && paths[0] = null) {
        return false;
    }
    if (junctionpaths.find("E") != std::string::npos && paths[1] = null) {
        return false;
    }
    if (junctionpaths.find("W") != std::string::npos && paths[3] = null) {
        return false;
    }

    return true;
}


int lineMaze(char previousNode, char destinationNode, int confused, int currentDirection){
    // confused -- 0 = not confused, 1 = confused
    // currentDirection -- 0 = unknown, 1 = north, 2 = east, 3 = south, 4 = west

    int dir = currentDirection;
    Node destination = Maze.getNode(destinationNode);
    Node previous = Maze.getNode(previousNode);
    String junctionPaths = "";


    //TODO: Drive forwards so that previous junction is no longer in sight

    while () { //TODO: check that we are not at a junction
        followLine(); //TODO: implement this
    }

    junctionPaths = identifyPaths();

    if (confused == 0) {

        if (hasRelativePaths(destination, junctionPaths, dir)) {
            if (next node in route is north) {
                lineMaze();
            } else if (next node east) {
                rotate(-90);
                lineMaze();
            } else if (next node south) {
                rotate(180);
                lineMaze();
            } else if (next node west) {
                rotate(90);
                lineMaze();
            }

        } else if (prevNode == node before end) {
            wallMaze();
        }

        else {
            lineMaze('','',1,0); // we are lost
        }
    } else if (confused == 1) {

        if (QUADRANT == 2) { //TODO:keep track of current quadrant, be able to identify that we've gone back into 2
            rotate(180); //TODO: implement rotate
            followLine();
        } else if (junction) {
            //TODO: implement something to either find direction and location or find start (time dependant)
        } else {
            // We can't see a line
            while(cant see line) {
                reverse();
            }
        }

    }
}

