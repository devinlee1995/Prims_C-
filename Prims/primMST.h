//
//  primMST.h
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//
/*
 - N (integer)//number of nodes in G
 - totalCost (integer) // initially set to zero
 - graphNodeIDarray (a 1-D array of integer, size N, dynamically allocated)
 // to mark node ID in the graph G,   initialize to 0
 - edgeList(the head of a linked list of edgeNode, should point to a dummy node)
 - setA (the head of a linked list of graphNode should point to a dummy node)
 - setB (the head of a linked list of graphNode should point to a dummy node)
 - MSTofG (the head of a linked list of edgeNode, should point to a dummy node)
 - PrimsMST method // the Prim’s algorithm
 
*/
#ifndef __Prims__primMST__
#define __Prims__primMST__

#include <iostream>
using namespace std;

class graphNode;
class edgeNode;
class LinkedList_graph;
class LinkedList_edge;

class primMST {
    friend class main;
    
    
public:
    primMST (int n);
    void PrimsMST(std::ostream& outputfile); //steps 4,5,6,7,8,9,10
    int get_N();
    LinkedList_edge* getedgeList();
    int getCost(); 
    int* get_nodeID_array();
    LinkedList_edge* getMST(); 
    void print_list(std::ostream& outputfile);
    bool sameSet(int i, int j); //checks if Ni and Nj of the edgeNode is in the same set
    void findValue(int x, int y); //inserts the node from setB to setA, then deletes that node in setB.
    
    
    
private:
    int N; //number of Nodes in G
    int totalCost = 0;
    int* graphNodeIDarray;
    LinkedList_edge* edgeList;
    LinkedList_graph* setA;
    LinkedList_graph* setB;
    LinkedList_edge* MSTofG;
    
    
};

#endif /* defined(__Prims__primMST__) */
