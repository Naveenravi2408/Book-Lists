/*
 * Book.h
 *
 *  Created on: Oct 14, 2017
 *      Author: navee
 */


#ifndef BOOK_H_
#define BOOK_H_
#include <string>

using namespace std;

/**
 * The Book class.
 */
class Book {

public:

	// Constructor
	Book();

	//Getters
	string get_isbn()  const;
	string get_last_name()  const;
	string get_first_name()  const;
	string get_title()  const;

	//Overloaded input operator
	friend istream& operator >> (istream& ins, Book& book);

private:
	string isbn;	// ISBN-number
	string last_name;	// Last name
	string first_name;	// First name
	string title;		// Book title
};

#endif /*BOOK_H_*/

