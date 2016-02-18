//
//  LinkedList_graph.h
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#ifndef __Prims__LinkedList_graph__
#define __Prims__LinkedList_graph__

#include <iostream>
class graphNode;

class LinkedList_graph {
    friend class main;
    
public:
    LinkedList_graph ();
    void insert(graphNode * point);
    void delete_node(int x);
    void printList(std::ostream& outputfile);
    bool isEmpty();
    graphNode * get_ListHead();
    ~LinkedList_graph();
    
private:
    graphNode * ListHead;
    
};

#endif /* defined(__Prims__LinkedList_graph__) */
