/*
 * BookNode.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: navee
 */

#include "BookNode.h"
#include<iostream>
#include<iomanip>
using namespace std;

//Default constructor
BookNode::BookNode()
{
	next = NULL;
}

/**
 * Constructor.
 * @param book is an individual book extracted from a file
 */
BookNode::BookNode(Book book)
{
	bk = book;
	next = NULL;
}

/*
 * Getter
 * @return book object (bk)
 */
Book BookNode::get_bk() const
{
	return bk;
}

/*
 * Getter
 * @return pointer next of a respective book node
 */
BookNode *BookNode::get_next() const
{
	return next;
}
