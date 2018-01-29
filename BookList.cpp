/*
 * BookList.cpp
 *
 *  Created on: Oct 15, 2017
 *      Author: navee
 */

#include "BookList.h"
#include<iostream>

/*
 * Default constructor
 */
BookList::BookList()
{
	 head = NULL;
}

/**
 * Insert a new node into the list while sorting the list at the same time.
 * Sorting is made on comparing the ISBN (ascending order)
 * @param node is a pointer which points to the node to be inserted
 */
void BookList::insert_and_sort (BookNode *node)
{

	// Check for the Head node to be empty and add the new node.
	// I'm performing head append here
   if (head == NULL)
    {
        head=node;
    }

    // If the head node is not empty
       else
       {
    	   // Check for the new incoming book nodes isbn number
    	   // to be greater than the isbn number of head node
    	   if (node->get_bk().get_isbn() < head->get_bk().get_isbn())
    	   	   {
    		   	   node->next = head;	// point the new node's next to nead
    		   	   head = node;		//swap the head with the new node
    	   	   }

    	   else  // if new node ISBN is greater than the head node ISBN
    	   {
    		   BookNode* iter_front;	// pointer iterator to traverse the list
    		   BookNode* iter_back;        //pointer iterator stay one node behind iter_front
    		   iter_front = head;    // start the iterator from head

    		   bool dupcheck=true;
    		   //Loop until iter_front is null(last node)
    		   // or until a greater isbn node is found
    		   while ((iter_front != NULL) && (node->get_bk().get_isbn() > iter_front->get_bk().get_isbn()))
    		    {
    			   iter_back = iter_front;
    			   iter_front = iter_front->get_next();

    			   // check if two nodes have same isbn number
    			   if((iter_front != NULL) && (node->get_bk().get_isbn() == iter_front->get_bk().get_isbn()))
    			   {
                		dupcheck=false;
                		break;
    			   }
    		     }
    		   	   if(dupcheck)  // if no two node's ISBN is equal
    		   	   {
    		   		iter_back->next = node;		// insert new node after the iter_back node
    		   		node->next = iter_front;    // assign new node next to point to iter_front node
    		   	    }
    	   	   }
       	   }

}

/*
 * Overloaded output stream operator
 * @param ostream the output stream
 * @param list the sorted book list to output
 * @return the output stream
 */
ostream& operator << (ostream& outs, const BookList& list)
{
	int count = 0;		// to count the number of books in the list
	BookNode *iter;		// pointer iterator to traverse the list
	for(iter = list.head; iter != NULL; iter =  iter->get_next())
		{
		cout<< "  Book{ISBN="<<iter->get_bk().get_isbn()
					<<", last="<< iter->get_bk().get_last_name()
					<<", first="<< iter->get_bk().get_first_name()
					<<", title="<< iter->get_bk().get_title()<<"}" << endl;
		count++;
		}
	cout << "    ("<<count <<" books)"<<endl<<endl;
	return outs;
}

/*
 *	Print the books of authors of last name from A to M
 *	Create an iterator pointer pointing to the head node of the list
 *	compare first character of author's last name to be less than N
 *	print its respective book
 *	@param list is the sorted book list to output
 */
void BookList::print_A_to_M(BookList& list)
{
	cout << "Book list: AUTHORS A-M" << endl<< endl;
	int count = 0;  // to count the number of books
		BookNode *iter;  // pointer iterator to traverse the list
		for(iter = list.head; iter != NULL; iter =  iter->get_next())
			{
				string name = iter->get_bk().get_last_name();
				name=name.substr(0,1);	// extract the first character of the author's last name

				if(name <= "M")
				{
				 cout<< "  Book{ISBN="<<iter->get_bk().get_isbn()
							<<", last="<< iter->get_bk().get_last_name()
							<<", first="<< iter->get_bk().get_first_name()
							<<", title="<< iter->get_bk().get_title()<<"}" << endl;
					count++;
				}
			}
		cout << "    ("<<count <<" books)" <<endl;
}

/*
 *	Print the books of authors of last name from N to Z
 *	Create an iterator pointer pointing to the head node of the list
 *	compare first character of author's last name to be greater than M
 *	print its respective book
 *	@param list is the sorted book list to output
 */
void BookList::print_N_to_Z(BookList& list)
{
	cout << "Book list: AUTHORS N_Z" <<endl <<endl;
	int count = 0;	// to count the number of books
		BookNode *iter;	// pointer iterator to traverse the list
		for(iter = list.head; iter != NULL; iter =  iter->get_next())
			{
				string name = iter->get_bk().get_last_name();
				name=name.substr(0,1);	// extract the first character of the author's last name

				if(name > "M")
				{
				cout<< "  Book{ISBN="<<iter->get_bk().get_isbn()
							<<", last="<< iter->get_bk().get_last_name()
							<<", first="<< iter->get_bk().get_first_name()
							<<", title="<< iter->get_bk().get_title()<<"}" << endl;
					count++;
				}
			}
		cout << "    ("<<count <<" books)" << endl;
}

