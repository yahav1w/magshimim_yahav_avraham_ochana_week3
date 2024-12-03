#include "Vector.h"
#include <iostream>


using std::cout;
using std::endl;

#define TEST_FAILED "Test Failed :(\n"
#define TESTS_PASSED "Tests Passed :)\n"

bool vectorsEqual(Vector v1, Vector v2)	// vectors passed as copy
{
	// compares attributes
	if (v1.capacity() != v2.capacity() ||
		v1.size() != v2.size() ||
		v1.resizeFactor() != v2.resizeFactor())
	{
		return false;
	}

	// compares values
	for (int i = 0; i < v1.size(); i++)
	{
		if (v1.pop_back() != v2.pop_back())
		{
			return false;
		}
	}

	return true;
}

/**
 * checks first and second part of the exercise:
 * basic constructor, size(), capacity(), push_back(),
 * pop_back(), reserve(), resize(), assign()
**/
void test1()
{
	// initial capacity is 4
	Vector v(4);

	// push values {1,2,3,4,5}
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i + 1);
	}

	// pops 2 elements
	for (int i = 0; i < 2; i++)
	{
		v.pop_back();
	}

	// checks capacity and size
	if (v.capacity() != 8 || v.size() != 3)
	{
		cout << TEST_FAILED;
		return;
	}

	// checks values
	for (int i = 0; i < v.size(); i++) {
		if (v.pop_back() != 3 - i) {
			cout << TEST_FAILED;
			return;
		}
	}

	// checks initial capacity & size
	Vector v2(-7);
	if (v2.capacity() != 2 || v2.size() != 0)
	{
		cout << TEST_FAILED;
		return;
	}

	// checks reserve
	Vector v3(5);
	v3.reserve(23);
	if (v3.capacity() != 25)
	{
		cout << TEST_FAILED;
		return;
	}

	// checks resize & assign
	v3.resize(50);
	//v3.assign(7);

	for (int i = 0; i < v3.size(); i++)
	{
		if (v3.pop_back() != 7)
		{
			cout << TEST_FAILED;
			return;
		}
	}

	cout << TESTS_PASSED;
}

/**
 * checks second part of the exercise:
 * copy ctor, copy operator
 **/
void test2()
{
	Vector v1(10);

	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	// checks copy constructor
	Vector v2 = v1;

	if (vectorsEqual(v1, v2) == false)
	{
		cout << TEST_FAILED;
		return;
	}

	Vector v3(10);
	v3.push_back(2999);
	v3.push_back(3999);
	v3.push_back(4999);

	// checks copy operator
	v2 = v3;
	if (vectorsEqual(v2, v3) == false)
	{
		cout << TEST_FAILED;
		return;
	}

	v2.push_back(100);

	// checks for independency - deep copy
	if (v3.pop_back() != 4999)
	{
		cout << TEST_FAILED;
		return;
	}

	cout << TESTS_PASSED;
}

/**
 * checks element access operator
 **/
void test3()
{
	Vector v1(10);

	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);

	// checks valid access
	if (v1[0] != 20 || v1[1] != 30 || v1[2] != 40)
	{
		cout << TEST_FAILED;
		return;
	}

	// checks out of bounds access
	if (v1[-3] != v1[0] || v1[v1.size() + 1] != v1[0])
	{
		cout << TEST_FAILED;
		return;
	}

	cout << TESTS_PASSED;
}

///**
// * checks bonus part of the exercise
// * '+' '+=' '-' '-=' '<<'
// **/
//void test4()
//{
//	Vector v1(10);
//	v1.push_back(20);
//	v1.push_back(30);
//	v1.push_back(40);
//
//	Vector v2(10);
//	v2.push_back(2);
//	v2.push_back(3);
//	v2.push_back(4);
//
//	// operator +
//	Vector v3 = v1 + v2;
//	if (v3[0] != 22 || v3[1] != 33 || v3[2] != 44)
//	{
//		cout << TEST_FAILED;
//		return;
//	}
//
//	// operator -
//	v3 = v2 - v1;
//	if (v3[0] != -18 || v3[1] != -27 || v3[2] != -36)
//	{
//		cout << TEST_FAILED;
//		return;
//	}
//
//	// operator +=
//	Vector v4(10);
//	v4.push_back(100);
//	v4.push_back(200);
//	v4.push_back(300);
//	v4 += v1;
//	if (v4[0] != 120 || v4[1] != 230 || v4[2] != 340)
//	{
//		cout << TEST_FAILED;
//		return;
//	}
//
//	// operator -=
//	Vector v5(10);
//	v5.push_back(0);
//	v5.push_back(0);
//	v5.push_back(0);
//	v5 -= v1;
//	if (v5[0] != -20 || v5[1] != -30 || v5[2] != -40)
//	{
//		cout << TEST_FAILED;
//		return;
//	}
//
//	cout << TESTS_PASSED;
//
//	cout << "\n\n" << "Testing operator <<\n" << endl;
//
//	// operator <<
//	Vector v6(10);
//	for (int i = 0; i < 10; i++)
//	{
//		v6.push_back(i + 1);
//	}
//
//	cout << v6;
//	cout << "\nThe output should show {1,2,3,4,5,6,7,8,9,10}\n" << endl;
//
//}

int main()
{
	cout << "\n*******************************" << endl;
	cout << "******** Basic Tests **********" << endl;
	cout << "*******************************" << endl;
	test1();

	cout << "\n******************************" << endl;
	cout << "*********** Copy *************" << endl;
	cout << "******************************" << endl;
	test2();

	cout << "\n******************************" << endl;
	cout << "*********** Access ************" << endl;
	cout << "******************************" << endl;
	test3();

	////cout << "\n******************************" << endl;
	////cout << "********** Bonuses ***********" << endl;
	////cout << "******************************" << endl;
	////test4();


	system("pause");
	return 0;
}