//
//  LinkedList_edge.h
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef __Prims__LinkedList_edge__
#define __Prims__LinkedList_edge__

#include <iostream>
class edgeNode;

class LinkedList_edge {
    friend class main;
    
public:
    LinkedList_edge ();
    void insert(edgeNode * point);
    void delete_node(int i, int j, int c);
    void printList(std::ostream& outputfile);
    bool isEmpty();
    edgeNode * get_ListHead();
    ~LinkedList_edge();
    
private:
    edgeNode * ListHead;
    
};

#endif /* defined(__Prims__LinkedList_edge__) */
