//
//  graphNode.cpp
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "graphNode.h"
#include<iostream>
#include <string>

graphNode::graphNode(int x) {
    nodeID = x;
    next = NULL;
}

void graphNode::insertGraph(int x){
    next = new graphNode(x);
}

void graphNode::deleteGraph(){
    delete this;
}

void graphNode::printNode(ostream& outputfile) {
    outputfile << "ID: " << nodeID << endl;
    
}

graphNode::~graphNode() {
    delete next;
}

bool graphNode::isEmpty() {
    return (next == NULL);
}