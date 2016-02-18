//
//  graphNode.h
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef __Prims__graphNode__
#define __Prims__graphNode__

#include <iostream>
using namespace std;

class graphNode {
    friend class primMST;
    friend class LinkedList_graph;
    friend class main;
    
    
public:
    graphNode (int x);
    void insertGraph(int x);
    void deleteGraph();
    ~graphNode();
    void printNode(ostream& outputfile);
    bool isEmpty();
    
    
    
private:
    int nodeID;
    graphNode * next;
};


#endif /* defined(__Prims__graphNode__) */
