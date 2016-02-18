//
//  LinkedList_graph.cpp
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "LinkedList_graph.h"
#include "graphNode.h"
#include<iostream>
#include<fstream>
using namespace std;

class graphNode;

LinkedList_graph::LinkedList_graph() {
    ListHead = new graphNode(-9999);
}

void LinkedList_graph::insert(graphNode* point) {
    graphNode* spot = ListHead;
    while (spot->next!= NULL) {
        spot = spot->next;
    }
    spot->next = point;
}

bool LinkedList_graph::isEmpty() {
    return (ListHead->next == NULL);
}

void LinkedList_graph::delete_node(int x) {
    if (!isEmpty()) {
        graphNode * spot = ListHead;
        while (spot->next->nodeID != x && spot->next != NULL) {
            spot = spot->next;
        }
        spot->next = spot->next->next;
    }
    else {
        throw "no!";
    }
}

void LinkedList_graph:: printList(ostream& outputfile) {
    graphNode* spot = ListHead->next;
    while (spot!= NULL) {
        spot->printNode(outputfile);
        spot = spot->next;
    }
    
}

graphNode* LinkedList_graph:: get_ListHead() {
    return ListHead;
}


LinkedList_graph::~LinkedList_graph() {
    graphNode *q = ListHead;
    while (q != NULL) {
        ListHead = ListHead->next;
        q = ListHead;
    }
}
