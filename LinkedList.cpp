// LinkedList.cpp
// Modified by Ben Howe
// COSC 2030
// September 29, 2018


// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "LinkedList.h"
#include <utility>


List::List()
  : first_(NULL)
{
  stored_size = 0;
  stored_sum = 0;
}


List::List(const List & other)
  : first_(clone(other.first_))
{
  stored_size = other.stored_size;
  stored_sum = other.stored_sum;
}


List::~List()
{
  while (!empty())
  {
    removeFirst();
  }
}

const List & List::operator=(const List & other)
{
  // check for list = list
  if (&other != this)
  {
    // clear the current contents of this List
    this -> ~List();
    // and get a copy of other
    first_ = clone(other.first_);
    stored_size = other.stored_size;
    stored_sum = other.stored_sum;
  }

  return *this;
}
/*
bool List::operator==(const List &rhs) {
  if(size() == 0 && rhs.size() == 0){return true;}//both empty
  if(size() != rhs.size()){return false;}//sizes not the same

  Node * lptr = this->next_;
  Node * rptr = rhs->next_;
  Double lEntry = lptr->entry_;
  Double rEntry = rptr->entry_;
  while (lptr != NULL && rptr != NULL)
  {
    if(lEntry != rEntry){
      return false;
    }
    lptr = lptr->next_;
    rptr = rptr->next_;
    lEntry = lptr->entry_;
    rEntry = rptr->entry_;
  }

  return true;
}
*/

bool List::empty() const
{
  return first_ == NULL;
}


void List::insertAsFirst(double x)
{
  first_ = new Node(x, first_);
  stored_size++;
  stored_sum = stored_sum + x;
}

void List::insertAsLast(double x)
{
  if (empty())
  {
    // object is empty, no need to re-invent the wheel.
    insertAsFirst(x);
  }
  else
  {
    // object is not empty
    Node * freshNode = new Node(x);  // create the new node
    Node * ptr = first_->next_;
    // Check to see if the next item in the linked list is a null pointer
    // If it is, you're on the last node!
    while (ptr->next_ != NULL)
    {
      ptr = ptr->next_; //iterate to next item in linked list
    }
    // Now we've arrived at the last node
    // update the next_ from "null" to the location of our new node
    ptr->next_ = freshNode;
    stored_size++;
    stored_sum = stored_sum + x;
  }
}


double List::removeFirst()
{
  double item = first_->entry_;
  Node * tempPtr = first_;
  first_ = first_->next_;
  stored_size--;
  stored_sum = stored_sum - item;
  delete tempPtr;
  return item;
}

void List::print(ostream & outfile) const
{
  outfile << "[ ";
  if (!empty())
  {
    // The first entry is printed separately because no comma
    // is needed.
    outfile << first_->entry_;
    Node * ptr = first_->next_;
    while (ptr != NULL)
    {
      outfile << ", " << ptr->entry_;
      ptr = ptr->next_;
    }
  }
  outfile << " ]" << endl;

  // Added additional reporting of information for the assignment to verify
  // that everything is working.
  outfile << "Size (dynamic, stored): " << size() << ", " << stored_size << endl;
  outfile << "Sum (dynamic, stored): " << sum() << ", " << stored_sum << endl;
}

int List::size() const // Dynamically calculates the size
{
  int temp = 0;
  if (!empty())
  {
    temp++;
    Node * ptr = first_->next_;
    while (ptr != NULL)
    {
      temp++;
      ptr = ptr->next_;
    }
  }
  return temp;
}

double List::sum() const  // Dynamically calculates the sum
{
  double total = 0;
  if (!empty())
  {
    total = total + first_->entry_;
    Node * ptr = first_->next_;
    while (ptr != NULL)
    {
      total = total + ptr->entry_;
      ptr = ptr->next_;
    }
  }
  return total;
}
// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
  if (ptr == NULL)
  {
    return NULL;
  }
  Node * first = new Node(ptr->entry_);
  Node * last = first;
  ptr = ptr->next_;
  while (ptr != NULL)
  {
    last->next_ = new Node(ptr->entry_);
    last = last->next_;
    ptr = ptr->next_;
  }
  return first;
}

//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
  list.print(outfile);
  return outfile;
}
