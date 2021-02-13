//***************************************************************
// dynarr.h (Project 2)
//
// Written by Steven Smail for COP4530
//
//***************************************************************

#include <cassert>
#include <iostream>
#include <string>

class RuntimeException  //Generic run-time exception
{
  protected:
    std::string errorMsg;
  public:
    RuntimeException(const std::string &err)
      { errorMsg = err; }
    std::string getMessage() const
      { return errorMsg; }
};

class InvalidIndex : public RuntimeException
{
  public:
    InvalidIndex(const std::string &err) : RuntimeException(err) {};
};

template <class dynElem>
class dynarr
{
  private:
    int capacity;
    dynElem *A;
  public:
    dynarr() : capacity(0), A(NULL) {};
    dynarr(int N) : capacity(N), A(new dynElem[N]) {};

    //Copy Constructor
    dynarr(const dynarr<dynElem> &other);

    //Destructor
    ~dynarr();

    //Overloaded = Operator
    dynarr<dynElem> & operator = (const dynarr<dynElem> &other);

    dynElem & operator [] (int ndx) throw(InvalidIndex);

    //Accessor
    int getCapacity();

    //Reserve function
    void reserve(int newcap);
};

//Copy Constructor
template <class dynElem>
dynarr<dynElem>::dynarr(const dynarr<dynElem> &other)
  : capacity(other.capacity)  //Copy static data{
  //Allocate dynamic array (Deep copy dynamic data)  A = new (std::nothrow) dynElem[capacity];  if (A == 0)  {    std::cerr << "*** Stack memory allocate failed ***\n";    exit(1);  }  else  {    //Copy other's array into new array    for (int pos = 0; pos < capacity; pos++)      A[pos] = other.A[pos];  }
}

//Destructor
template <class dynElem>
dynarr<dynElem>::~dynarr()
{
  delete [] A;
}

//Overloaded = Operator
template <class dynElem>
dynarr<dynElem> & dynarr<dynElem>::operator = (const dynarr<dynElem> &other)
{  if (this == &other)  //Check for obj == obj    return *this;
  //Copy static data  capacity = other.capacity;
  //Delete current dynamic array  delete [] A;
  //Allocate dynamic array (Deep copy dynamic data)  A = new (std::nothrow) dynElem[capacity];
  if (A == 0)  {    std::cerr << "*** Inadequate memory ***\n";    exit(1);  }
  else
  {
    //Copy other's array into new array    for (int pos = 0; pos < capacity; pos++)      A[pos] = other.A[pos];    return *this;
  }}

template <class dynElem>
dynElem & dynarr<dynElem>::operator [] (int ndx) throw(InvalidIndex)
{
  if (ndx < 0 || ndx > capacity)
    throw InvalidIndex("Error: Outside capacity of array");
  else
    return A[ndx];
}

//Accessor
template <class dynElem>
int dynarr<dynElem>::getCapacity()
{
  return capacity;
}

//Reserve function
template <class dynElem>
void dynarr<dynElem>::reserve(int newcap)
{
  if (newcap <= capacity)
    return;
  if (capacity == 0)
  {
    A = new dynElem[newcap];
    capacity = newcap;
  }
  else
  {
    dynElem *newA = new dynElem[newcap];
    for (int pos = 0; pos < capacity; pos++)      newA[pos] = A[pos];
    delete [] A;
    A = newA;
    capacity = newcap;
  }
}