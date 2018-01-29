/*
 * BookNode.h
 *
 *  Created on: Oct 14, 2017
 *      Author: navee
 */

#ifndef BOOKNODE_H_
#define BOOKNODE_H_

#include "Book.h"

/**
 * A book node in a linked list.
 */
class BookNode
{
public:

	// Constructors
	BookNode();
    BookNode(Book book);

    //Getters
    Book get_bk() const;
    BookNode * get_next() const;

	// Public pointer to next node in a list
	BookNode *next;

private:
   Book bk;	// Book object (which contains all the info related to a book)
};

#endif /* BOOKNODE_H_ */
