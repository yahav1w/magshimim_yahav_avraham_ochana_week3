

//the class represent a vector
class Vector
{
private:
	int* _element;//an array of int variables
	int _size;//the current size that use of the element
	int _capacity;//the size of the array
	int _resizeFactor;//the growing size that the array can grow with
public:
	Vector(int n);//constructor
	Vector(const Vector& other);//copy constructor
	~Vector();//destructor
	int size() const;//return size
	int capacity() const;//return capacity
	int resizeFactor() const;//return resizeFactor
	bool empty();//check if element is clean
	void push_back(const int& val);//add variable to the array(element)
	int pop_back();//remove the last variable of the array
	void reserve(int n);//change the size of the array to at least n
	void resize(int n);//same like reserve but can delete or add variable to the array(element)
	void assign(int val);//put the variable "var" into all the open places in the array(element) 
	void resize(int n, const int& val);//change the size of the array to at least n and put the variable "var" into all the open places in the array(element)
	Vector& operator=(const Vector& other);//copy operator 
	int operator[](int var) const;//operator to use vector as a array of elements with index
};