//
//  main.cpp
//  Prims
//
//  Created by Devin Lee on 11/28/15.
//  Copyright (c) 2015 Devin Lee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "graphNode.h"
#include "edgeNode.h"
#include "LinkedList_graph.h"
#include "LinkedList_edge.h"
#include "primMST.h"
using namespace std;

class LinkedList_graph;
class LinkedList_edge;
class primMST;
class graphNode;
class edgeNode;

int main(int argc, const char * argv[])
{
    try{
        
        if (argc < 2) {
            throw argc; //throws exception when less than 2 arguments
        }
        
        ifstream the_input;
        string input_file_name = argv[1]; //name of data input file
        the_input.open(input_file_name); //opens data input file
        
        ofstream the_output2; //output file
        string output_file_name2 = argv[3]; //name of output file
        the_output2.open(output_file_name2,std::ios_base::app); //opens output data file
        
        //step 0: Get N from input file and initialize primMST class
        int number_of_nodes;
        the_input >> number_of_nodes;
        primMST prim(number_of_nodes);
        
        
        //step 1: Read data from input file for new edgeNode, then insert. Increment NodeID array.
        int num;
        while (the_input >> num) {
            int num2;
            the_input >> num2;
            int num3;
            the_input >> num3;
            edgeNode *edgeN = new edgeNode(num, num2, num3);
            prim.getedgeList()->insert(edgeN);
            prim.get_nodeID_array()[num]++;
            prim.get_nodeID_array()[num2]++;
        }
        //step 3: Print graphNodeID array and edgeList
        prim.print_list(the_output2);
        prim.getedgeList()->printList(the_output2);
        
        //steps 4,5,6,7,8,9,10
        prim.PrimsMST(the_output2);

        the_output2.close();
        
        //step 11: Output MSTofG and the totalCost
        ofstream the_output1; //output file for information in Linked List (point data)
        string output_file_name1 = argv[2]; //name of output file
        the_output1.open(output_file_name1,std::ios_base::app); //opens output data file
        
        the_output1 << "MST of G: " << endl << prim.get_N() << endl;
        prim.getMST()->printList(the_output1);
        the_output1 << endl << endl << "Total Cost: " << prim.getCost();
        

        the_output2.close();
        the_input.close();
        
    }
    
    
    catch (int e) {
        std::cout << "Not enough arguments provided! Argument(s) used: ";
        for (int i = 0; i < argc; ++i)
            std::cout << "argv["<< i << "] : " << argv[i] << "\n";
    }
    
    return 0;
};