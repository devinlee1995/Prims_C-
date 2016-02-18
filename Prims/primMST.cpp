//
//  primMST.cpp
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "primMST.h"
#include "graphNode.h"
#include "edgeNode.h"
#include "LinkedList_graph.h"
#include "LinkedList_edge.h"


primMST::primMST(int n) {
    N = n;
    graphNodeIDarray = new int[N+1];
    for (int i = 0; i < N+1; i++) {
        graphNodeIDarray[i] = 0;
    }
    edgeList = new LinkedList_edge();
    setA = new LinkedList_graph();
    setB = new LinkedList_graph();
    MSTofG = new LinkedList_edge();
}

void primMST::PrimsMST(ostream& outputfile) {
    //steps 4,5,6
    int value = 0;
    //step 4:Find the first non zero graphNodeIDarray[k] and create a new graphNode to be inserted in setA
    for (int i = 1; i < N+1; i++) {
        if (graphNodeIDarray[i] != 0) {
            graphNode* graphN = new graphNode(i);
            setA->insert(graphN);
            value = i+1;
            break;
        }
    }
    //step 5:Get the next non zero graphNodeIDarray[k] and create new graphNodes to be inserted in setB
    for (int j = value; j < N+1; j++) {
        if (graphNodeIDarray[j]!= 0) {
            graphNode* graphN2 = new graphNode(j);
            setB->insert(graphN2);
        }
    }
    
    while (!setB->isEmpty()) { //step 10: Repeat until setB is empty
        //step 7: Find edge where Ni and Nj are in different sets
        edgeNode* newEdge = edgeList->get_ListHead()->next;
        while (newEdge != NULL && !sameSet(newEdge->Ni, newEdge->Nj)) {
            newEdge = newEdge->next;
        }
        
        if (newEdge != NULL) {
        //step 8: Insert newEdge into MSTofG, add cost to totalCost
        MSTofG->insert(newEdge);
        totalCost = totalCost + newEdge->edgeCost;
        //step 8 (Contin.): Make a deletion in setB and make an insertion in setA of graphNode Ni or Nj.
        findValue(newEdge->Ni, newEdge->Nj);
        }
        
        //step 9: Print setA, setB, and MST of G
        outputfile << endl << "PrimsMST: " << endl << "Set A: " << endl;
        setA->printList(outputfile);
        outputfile << endl;
        outputfile << "Set B: " << endl;
        setB->printList(outputfile);
        outputfile << endl;
        outputfile << "MST of G: " << endl;
        MSTofG->printList(outputfile);
        outputfile << endl;
   }
    
}

int primMST::get_N(){
    return N;
}

LinkedList_edge* primMST:: getedgeList() {
    return edgeList;
}

int* primMST::get_nodeID_array() {
    return graphNodeIDarray;
}

void primMST:: print_list(ostream& outputfile) {
    for (int i = 0; i < N+1; i++) {
        outputfile << graphNodeIDarray[i] << " "; 
    }
    outputfile << endl; 
}

bool primMST::sameSet(int i, int j) { //tests to see if Ni and Nj are in the same set
    graphNode* A = setA->get_ListHead()->next;
    graphNode* B = setB->get_ListHead()->next;
    
    bool setA_Yes = false;
    bool setB_Yes = false;
    
    while (A != NULL) {
        if (A->nodeID == i || A->nodeID == j) {
            setA_Yes = true;
        }
        A = A->next;
    }
    
    while (B != NULL) {
        if (B->nodeID == i || B->nodeID == j){
            setB_Yes = true;
        }
        B = B->next;
    }
    
    if (setA_Yes == true && setB_Yes == true) {
        return true;
    }
    else {
        return false;
    }
}

//Makes a deletion in setB and make an insertion in setA of graphNode Ni or Nj.
void primMST:: findValue(int x, int y) {
    graphNode* B = setB->get_ListHead()->next;
    while (B != NULL && B->nodeID != x && B->nodeID != y) {
        B = B->next;
    }
    graphNode* insert = new graphNode(B->nodeID);
    setA->insert(insert);
    setB->delete_node(B->nodeID);
}

LinkedList_edge* primMST:: getMST() {
    return MSTofG;
}

int primMST:: getCost() {
    return totalCost; 
}