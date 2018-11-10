#ifndef _P
#define _P 
#include "Melody.h"


class Piano
{

public:
	//Default constructor
	Piano();

	//constructor which takes std::string and int and assignments it to private variables
	Piano(std::vector<Melody> melodyVec, int tempo) : _melodyVec(melodyVec), _tempo(tempo){}
	~Piano();

	// function of type void which takes nothing and plays the melody which depends on value of private variables 
	 void play();

private:
    // vector of class Melody, which contains notes
	std::vector<Melody> _melodyVec;
	int _tempo; 
	// we use static type of vector to initialize this in a class
	const static double _values[]; 
	const static int _notes[];

};





#endif