#include "Piano.h"

using namespace std;
Piano::Piano(){}
Piano::~Piano(){}


const double Piano::_values[] = {62.5, 125, 250, 500, 1000, 2000};

const int Piano::_notes[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

 void Piano::play()
{
	
	int herz = 0;
	int sleep = 0;
	
	for(auto t : _melodyVec)
	{
		t.note[0] = toupper(t.note[0]);
		if (t.note == "C") herz = _notes[0];
		else if (t.note == "C#"|| t.note == "D*") herz = _notes[1];
		else if (t.note == "D") herz = _notes[2];
		else if (t.note == "D#"|| t.note == "E*") herz = _notes[3];
		else if (t.note == "E"|| t.note == "F*") herz = _notes[4];
		else if (t.note == "F") herz = _notes[5];
		else if (t.note == "F#"|| t.note == "G*") herz = _notes[6];
		else if (t.note == "G") herz = _notes[7];
		else if (t.note == "G#"|| t.note == "A*") herz = _notes[8];
		else if (t.note == "A") herz = _notes[9];
		else if (t.note == "A#"|| t.note == "H*") herz = _notes[10];
		else if (t.note == "H"|| t.note == "C*") herz = _notes[11];
		else 
		{
			int ia = 0;
			throw ia;
		}

		switch(_tempo)
		{
			case 60: sleep = 500; break;
			case 120: sleep = 100; break;
			case 180: sleep = 50; break;
		};

	
		Beep(herz * stoi(t.height), _values[stoi(t.value) - 1]); Sleep(sleep);
		
	}
	


	
	
	
}
