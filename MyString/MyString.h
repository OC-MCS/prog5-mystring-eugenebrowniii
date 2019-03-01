#pragma once
// MyString class declaration goes here
class MyString
{
private:
	char * str;
public:
	MyString();										// default constructor
	MyString(const char* s);						// constructor that takes a char* parameter
	~MyString();									// destructor 	
	MyString(const MyString &other);				// copy constructor
	char* c_str() const;							// getter function for operator<<
	bool operator==(const MyString &other);			// ==operator to compare two strings
	MyString operator+(const MyString &other);		// +operator to concat two strings
	MyString operator=(const MyString &other);		// assignment operator to do a = b
	
};
