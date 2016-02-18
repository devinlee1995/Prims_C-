//
//  LinkedList_edge.cpp
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "LinkedList_edge.h"
#include "edgeNode.h"
#include<iostream>
#include<fstream>
using namespace std;

class edgeNode;

LinkedList_edge::LinkedList_edge() {
    ListHead = new edgeNode(-9999,-9999,-9999);
}

void LinkedList_edge::insert(edgeNode* point) {
        edgeNode *spot = ListHead;
        
        if (isEmpty()) {
            edgeNode* insert1 = new edgeNode(point->Ni, point->Nj, point->edgeCost);
            ListHead->next = insert1;
        }
        
        else {
            while ((spot->next != NULL) && (spot->next->edgeCost < point->edgeCost)) {
                spot = spot->next;
            }
                edgeNode* insert = new edgeNode(point->Ni, point->Nj, point->edgeCost);
                insert->next = spot->next;
                spot->next = insert;
        }
}

bool LinkedList_edge::isEmpty() {
    return (ListHead->next == NULL);
}

void LinkedList_edge::delete_node(int i, int j, int c) {
    if (!isEmpty()) {
        edgeNode * spot = ListHead;
        while (spot->next->Ni != i && spot->next->Nj != j && spot->next->edgeCost != c && spot->next != NULL) {
            spot = spot->next;
        }
        spot->next = spot->next->next;
    }
    else {
        throw "no!";
    }
    
}

void LinkedList_edge:: printList(ostream& outputfile) {
    edgeNode* spot = ListHead->next;
    while (spot!= NULL) {
        spot->printEdgeNode(outputfile);
        spot = spot->next;
    }
    
}

edgeNode* LinkedList_edge:: get_ListHead() {
    return ListHead;
}


LinkedList_edge::~LinkedList_edge() {
    edgeNode *q = ListHead;
    while (q != NULL) {
        ListHead = ListHead->next;
        q = ListHead;
    }
}
