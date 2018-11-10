#ifndef _M
#define _M

#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <windows.h>

class Melody
{
public:
	//default constructors
	Melody();
	// constructor which takes std::string and assingments defferent values to private parametes of the class
	Melody(std::string m);
	//destructor
	~Melody();

	// we allow the class Piano to use functions of class Melody
	friend class Piano; 

private:
	// private variables which describes the note - value, height and sound
	 std::string value;  
	 std::string height; 
	 std::string note;
};

#endif