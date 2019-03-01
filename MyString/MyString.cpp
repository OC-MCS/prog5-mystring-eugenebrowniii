// MyString implementation file

#include <iostream>	
#include <cstring>
using namespace std;

#include "MyString.h"
void deepCopystr(char * &addressString, char * otherString);

// default constructor
MyString::MyString()
{
	str = nullptr;
}

// constructor that takes a char* parameter
MyString::MyString(const char* s)
{
	int strSize = strlen(s) + 1; // +1 for null byte
	str = new char[strSize];
	strcpy_s(str, strSize, s);
}

// copy constructor
MyString::MyString(const MyString &other)
{
	//cout << "Copy constructor ran" << endl;
	deepCopystr(str, other.str);
}

// destructor
MyString::~MyString()
{
	//cout << "Destructor ran" << endl;
	delete[] str;
}

// assignment operator to do a = b
MyString MyString::operator=(const MyString &other)
{
	if (this != &other)
	{
		delete[] str;
		deepCopystr(str, other.str);
	}

	return *this;
}

// operater concats two strings
MyString MyString::operator+(const MyString &other)
{
	int size = strlen(str) + strlen(other.str) + 2; // 1 for null byte, 1 for space char

	char *strcopy;
	strcopy = new char[size];
	strcpy_s(strcopy, size, str);
	strcat_s(strcopy, size, " ");
	strcat_s(strcopy, size, other.str);

	return strcopy;
}


// getter function for operator<<
char* MyString::c_str() const
{
	return str;
}

// compares two strings
bool MyString::operator==(const MyString &other)
{
	bool isEqual = false;
	if (strcmp(str, other.str) == 0)
	{
		isEqual = true;
	}
	return isEqual;
}



//the deepCopyStr function does a deep copy of a string
//the parameter is the address string and string to copy
//no returns
void deepCopystr(char * &addressString, char * other)
{
	int otherSize = strlen(other) + 1; // +1 for null byte
	addressString = new char[otherSize];
	strcpy_s(addressString, otherSize, other);
}


//operator to output MyString
ostream &operator << (ostream &strm, const MyString &s)
{
	strm << s.c_str();
	return strm;
}




