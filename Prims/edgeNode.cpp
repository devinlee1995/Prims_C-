//
//  edgeNode.cpp
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include "edgeNode.h"

edgeNode::edgeNode(int i, int j, int cost) {
    Ni = i;
    Nj = j;
    edgeCost = cost;
    next = NULL;
}

void edgeNode::insertEdge(int i, int j, int cost){
    next = new edgeNode(i, j, cost);
}

void edgeNode::deleteEdge(){
    delete this;
}

void edgeNode::printEdgeNode(ostream& outputfile) {
    outputfile << Ni << " " << Nj << " " << edgeCost << endl;
}

edgeNode::~edgeNode() {
    delete next;
}

