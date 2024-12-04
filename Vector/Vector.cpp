#include "Vector.h"
#include <iostream>

//the constructor create a new Vector with size n
//n - the size of the new vector
Vector::Vector(int n)
{
	if (n < 2)
	{
		n = 2;
	}
	this->_elements = new int[n];
	this->_capacity = n;
	this->_size = 0;
	this->_resizeFactor = n;
}

//the function copy a vector
//other - the vector to copy
//return a vector
Vector::Vector(const Vector& other)
{
	this->_size = other._size;
	this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;
	this->_elements = new int[this->_size];
	for (int i = 0;i < this->_size;i++)
	{
		this->_elements[i] = other._elements[i];
	}
}

//the function delete the vector
Vector::~Vector()
{
	delete[](this->_elements);
}

//the function return the current size of the array that used
int Vector::size() const
{
	return this->_size;
}

//the function the size of the array
int Vector::capacity() const
{
	return this->_capacity;
}

//the function growing rate of the array
int Vector::resizeFactor() const
{
	return this->_resizeFactor;
}

//the function check if the Vector is empty
//return true- if empty else return false
bool Vector::empty() const
{
	if (this->_size == 0)
	{
		return true;
	}
	return false;
}

//the function add a variable to the array
void Vector::push_back(const int& val)
{
	//check if the array reach his limits
	if(this->_size == this->_capacity)
	{ 
		this->_capacity += this->_resizeFactor;//creating the new limit
		int* temp = new int[this->_capacity];
		for (int i = 0;i < this->_size;i++)
		{
			temp[i] = this->_elements[i];//saving the elements in the array
		}
		delete[](this->_elements);//delete previos array
		this->_elements = temp;
	}
	this->_elements[this->_size] = (val);//add a new variable to the array
	this->_size++;//the current size using add by 1
}

//the function remove the last variable in the list and return him
//else if the array is empty return -9999
int Vector::pop_back()
{
	if (!this->empty())
	{
		int val = this->_elements[this->_size-1];
		this->_elements[this->_size-1] = 0;
		this->_size--;
		return val;
	}
	std::cout << "error: pop from empty vector" << std::endl;
	return -9999;
}

//the function change the size of the array to at least n
//n - the new at least size of the array
void Vector::reserve(const int n)
{
	if (this->_capacity < n)
	{
		int numOfReSize = (n - this->_capacity) / this->_resizeFactor;//came from the equation -> capasity + (resizeFactor * nomOfReSize) = n
		this->_capacity += numOfReSize * this->_resizeFactor;
		if (this->_capacity < n)//for the case where n does not full divide by resizeFactor like if numOfReSiZE 
								//suppose to be 1.25 it round the number down to 1 so we need to add one more time
		{
			this->_capacity += this->_resizeFactor;
		}
	}
}

//the function change the size of the array to at least n 
//but can delete places to the array in some cases
void Vector::resize(const int n)
{
	if (n <= this->_capacity)
	{
		while (n < this->_size)
		{
			this->pop_back();
			this->_size--;
		}
	}
	else
	{
		this->reserve(n);
	}
}

//the function put the variable "var" into all the open places in the array(element)
void Vector::assign(const int val)
{
	for (int i = 0;i < this->_size;i++)
	{
		this->_elements[i] = val;
	}
}

//the function change the size of the array to at least n and  
//put the variable "var" into all the open places in the array(element)
void Vector::resize(const int n, const int& val)
{
	this->resize(n);
	for (int i = this->_size;i < this->_capacity-1;i++)
	{
		this->_elements[i] = val;
	}
	this->_size = this->_capacity;
}

//the operator copy one vector to another
//other - the vector to copy
//return to the second vector the refrence for him
Vector& Vector::operator=(const Vector& other)
{
	this->_size = other._size;
	this->_capacity = other._capacity;
	this->_resizeFactor = other._resizeFactor;
	this->_elements = new int[this->_size];
	for (int i = 0;i < this->_size;i++)
	{
		this->_elements[i] = other._elements[i];
	}
	return *this;
}

//the operator help us use the vector as a list of numbers
//return the value in the index requested if the index in the array size
//if not return the first variable in the array and print "out of range"
int& Vector::operator[](int n) const
{
	if (n >= this->_size || n < 0)
	{
		std::cout << "out of range" << std::endl;
		return this->_elements[0];
	}
	return this->_elements[n];
}
