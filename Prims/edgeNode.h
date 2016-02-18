//
//  edgeNode.h
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef __Prims__edgeNode__
#define __Prims__edgeNode__

#include <iostream>
using namespace std;

class edgeNode {
    friend class primMST;
    friend class LinkedList_edge; 
    friend class main;
    
    
public:
    edgeNode (int i, int j, int cost);
    void insertEdge(int i, int j, int cost);
    void deleteEdge();
    ~edgeNode();
    void printEdgeNode(ostream& outputfile);
    
    
    
private:
    int Ni;
    int Nj;
    int edgeCost;
    edgeNode * next;
};


#endif /* defined(__Prims__edgeNode__) */
