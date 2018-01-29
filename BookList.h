/*
 * BookList.h
 *
 *  Created on: Oct 15, 2017
 *      Author: navee
 */

#ifndef BOOKLIST_H_
#define BOOKLIST_H_
#include "BookNode.h"
#include <string>
using namespace std;

/**
 * A linked list which contains all the book nodes.
 */
class BookList {

public:

	// Default constructor
	BookList();

    void insert_and_sort(BookNode *node);  // function to do insertion sorting
    void print_A_to_M(BookList& list);	   // function to print books of authors from A to M
    void print_N_to_Z(BookList& list);     // function to print books of authors from N to Z

    // Overloaded output operator
    friend ostream& operator << (ostream& outs, const BookList& list);

private:
    BookNode *head;   // head of the list of book nodes
};

#endif /* BOOKLIST_H_ */
