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
  : capacity(other.capacity)  //Copy static data
  //Allocate dynamic array (Deep copy dynamic data)
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
{




  else
  {
    //Copy other's array into new array
  }

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
    for (int pos = 0; pos < capacity; pos++)
    delete [] A;
    A = newA;
    capacity = newcap;
  }
}