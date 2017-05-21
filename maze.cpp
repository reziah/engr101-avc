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
    int type; // 1 == Line Maze, 2 == Wall Maze
    char nodeValues [][];
    map<char, Node> nodeMap;

public:
    Maze(int type) {
        if (type == 1) {
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
        }
    }

};

