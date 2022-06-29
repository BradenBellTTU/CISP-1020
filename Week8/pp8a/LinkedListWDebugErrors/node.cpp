#include <cstdlib>
#include "node.h"
#include "book.h"

/* default constructor
 */
Node::Node()  { 
	nextPtr = (Node*)&prevPtr;
}

/* 1-arg copy constructor doesn't copy the pointer
 */
Node::Node( const Node& n ) : nextPtr( NULL ) {
   setBook( n.book ); 
}

/* 1-arg constructor
 * Parameter  the book data
 */
Node::Node( const Book& b ) : nextPtr( NULL ), prevPtr(NULL) {}

/* setBook sets the Book data values
 * Parameter the book data
 * Returns: nothing
 */
void Node::setBook( const Book& b ) {
   book.setIsbn( b.isbn );
   book.setAuthor( b.author ); 
   book.setTitle( b.title );
   book.setPublisher( b.publisher );
   book.setYear( b.year );
   book.setEdition( b.edition );
}

