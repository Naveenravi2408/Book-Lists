/*
 * Book.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: navee
 */

#include "Book.h"
#include<string>
#include<iostream>

using namespace std;

//Default constructor
Book::Book()
{
	isbn = "";
	last_name = "";
	first_name = "";
	title = "";
}

/*
 * Getter
 * @return the isbn
 */
string Book::get_isbn() const
{
	return isbn;
}

/*
 * Getter
 * @return the last name
 */
string Book::get_last_name() const
{
	return last_name;
}

/*
 * Getter
 * @return the first name
 */
string Book::get_first_name() const
{
	return first_name;
}

/*
 * Getter
 * @return the title
 */
string Book::get_title() const
{
	return title;
}


/*
 * Overloaded input stream extraction operator. Reads from a .in file
 * @param istream the input stream
 * @param book the book to input
 * @return the input stream
 */
istream& operator >> (istream& ins, Book& book)
{
	string str;
	getline(ins, str, ',');
	book.isbn = str;

	getline(ins,str, ',');
	book.last_name = str;

	getline(ins,str, ',');
	book.first_name = str;

	getline(ins,str);
	str=str.substr(0,str.length()-1); // to skip the blank spaces at the end of the line
	book.title = str;

	return ins;
}
