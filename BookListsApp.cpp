#include "Book.h"
#include "BookList.h"
#include "BookNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const char *CATEGORIES_FILE_NAME = "categories.txt";

//Function to open category file and process link list
void open_category(ifstream& input, BookList& list);


int main()
{
   cout <<endl;

	ifstream input;	// to fetch inputs from category file
	BookList list;	// @list is object created for merged linked list

	input.open(CATEGORIES_FILE_NAME);
	if(input.fail())
	{
		cout << "Cannot open " << CATEGORIES_FILE_NAME << endl;
		return -1;
	}

	while(!input.eof()) // read input from category file until end of file
	{
	open_category(input,list);
	}
	input.close();

	cout << "Book list: MERGED" << endl <<endl;
	cout << list;   // print merged list

	list.print_A_to_M(list);
	cout <<endl;	// print list with A to M authors

	list.print_N_to_Z(list);	// print list with N to Z authors
	cout << endl;

    return 0;
}

/*
 * open category file and read the category name
 * According to the category name open its respective file to fetch the books
 * Add each of the book to the list
 * While inserting the new books they are sorted according to their ISBN (insertion sorting)
 *	@input input stream
 *	@list object for creating a linked list
 */
void open_category(ifstream& input, BookList& list)
{
	string category_name,categry_name;
	input >> category_name;				// fetch category name

	categry_name = category_name+".txt";
	const char *category_name_char = categry_name.c_str();

	ifstream inputbook;
	inputbook.open(category_name_char);	// open respective category file

	BookList Ind_list;			// Ind_list object to store all the category books which are sorted
	while(!inputbook.fail())  // repeat until the end of file
	{
	Book book;				// book object to store all the book info (ISBN, first, last, title)
	inputbook >> book;
	if(book.get_isbn().length() == 0)
	{
		cout << "Book list: " << category_name<<endl <<endl
		     << Ind_list;break;
	}
	Ind_list.insert_and_sort (new BookNode(book));   // insertion sorting for individual list
	list.insert_and_sort (new BookNode(book));		// insertion sorting for merged list
	}
	inputbook.close();		// close the sub category file
}

