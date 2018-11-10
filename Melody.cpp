#include "Melody.h"
using namespace std;

Melody::Melody(){}
Melody::~Melody(){}

Melody::Melody(std::string m)
{
 	value =  m[0];
	note = m[1];
	 if (m[2] == '#' || m[2] == '*') 
	{	
		note = note + m[2]; 
	 	height = m[3];
	}

	 else height = m[2];
}