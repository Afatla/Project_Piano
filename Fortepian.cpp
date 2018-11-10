//by Helak Maria and Fatla Agnieszka
//January 2017
//AGH
#include <iostream>
#include <fstream>
#include <stdexcept>  
#include <limits>
#include "Melody.h"
#include "Piano.h"

using namespace std;

// function of type void, which takes string of filename, where melody is contained and a vector of type string
void load_txt(const string &filepath, vector<string > &melody);

// function of type void, which takes nothing and draws a piano and returns nothing
void draw_piano();

// function of type void, which takes a vector of type string and welcomes an user. Also it modifies a vector inside
void print_welcome_text(vector<string> &melody);

// function of type void, which takes a vector of type string and returns nothing
void melody_choose(vector<string> &melody);

// function of type void, which takes a vector of type string and returns nothing
void own_melody(vector<string> &melody);

// function of type void, which takes variable of type int and returns nothing
void tempo_choose(int &tempo);
/* function of type bool, which takes nothing and returns true, 
   when user wants to play again, and returns false when user wants to finish. 
   Then the function say goodbye to the user*/
bool print_end_text();

// function of type vector<Melody> which takes vector of type string and returns vector with melody
vector<Melody> createMelodyClasses(const vector<string> &melody);

// function of type void which takes nothing and return value from cin
int IntCin();

// controls operation of the program
int main()
{
	draw_piano();

	
	bool end = false;

	do
	{
		vector<string> melody;
		vector<Melody> MelodyVector;
		int tempo;

		print_welcome_text(melody);
		
		MelodyVector = createMelodyClasses(melody);
		tempo_choose(tempo);
		Piano piano(MelodyVector,tempo);
		
		// try-block to provide a way to react to expections like wrong format of notes to play
		try
		{
			piano.play();
		}
		catch (const std::invalid_argument& ia)
		{
			//standard error output
			cerr << "Invalid argument. You write wrong melody. Try one more time with more careful!"  << '\n';
		}
		catch (int a)
		{
			
			cerr << "Invalid argument. You write wrong melody. Try one more time with more careful!"  << '\n';
		}


		end = print_end_text();

	}
	// loop that ends when an user wants to quit (when the print_end_text returns false)
	while(end);
	
		
	return 0;
}

void draw_piano()
{
	cout<<"____________________________"<<endl;
	cout<<"|  ##  ##  ##   |  ##  ##  |"<<endl;
	cout<<"|  ##  ##  ##   |  ##  ##  |"<<endl;
	cout<<"|   |   |   |   |   |   |  |"<<endl;
	cout<<" *************************** "<<endl;
	// yes, that is a piano. Use your imagination
}

void load_txt(const string &filepath, vector<string> &melody)
{
	string note;
	ifstream ifile;
	// we open the file with song
	ifile.open(filepath);
	for(size_t i = 0; ifile.good(); i++)
	{
		// our vector is pushed_back with the notes from file (notes are separated with " ")
		ifile >> note;
		melody.push_back(note);
	}
	// we close the file
	ifile.close();
}

void print_welcome_text(vector<string> &melody)
{
	int choice;

	cout << "Hello! Welcome to our userfriendly, high definition audio and the best piano player! \n";
	

	cout << "Now, choose 1 if you want melody from file or 2 if that is gonna be your melody, The Composer\n";

	do
	{
		// an user writes his choice
		choice = IntCin();
		
		switch(choice)
		{
			case 1: melody_choose(melody); 
					break;
			case 2: own_melody(melody);
					break;
			default: // if an user chooses wrong number he can try again
				cout << "Wrong number\n Try again\n"; 
				

		
					 
		}
		
	} while(choice != 1 && choice != 2); 
	// loop that ends if an user chooses 1 or 2
	         
}

void melody_choose(vector<string> &melody)
{
	int melodyChoose;

	// our files with songs
	cout << "Melody to choose: 1 - Mario, 2 - Tetris, 3 - Star Wars, 4 - Wlazl Kotek na plotek\n";
	
	do
	{
		melodyChoose = IntCin();

		switch(melodyChoose)
		{
			
			case 1: load_txt("Mario.txt", melody); break;
			case 2: load_txt("Tetris.txt", melody); break;
			case 3: load_txt("StarWars.txt", melody); break;
			case 4: load_txt("Kotek.txt", melody); break;
			default: cout << "Wrong number\n Try again\n";
		}
	}
	// loop that ends when an user chooses 1, 2, 3, or 4 
	
	while (melodyChoose < 1 || melodyChoose > 4);
}

void own_melody(vector<string> &melody)
{
	
	string note;
	// we need to tell an user how to write his melody
	cout << "Write your melody with these rules:\n - value: 1 - 32, 2 - 16, 3 - 8, 4 - quart, 5 - half, 6 - whole note\n - notes - C, D, E, F, G, A, H. You can add sharp - # or flat - *\n - height: 1 - first octave, 2 - second octave and so on.\n - press enter if you want to write another note\n - write '.' if it's end of your melody\n"; 
	
	do
	{
		// an user writes his notes
		cin>>note;

		// our melody can't contain the "."
  		if(note!=".")
		
		{
		  	melody.push_back(note);
		}
	
	}
	// loop that ends when an user writes "."
	while(note!=".");
}

vector<Melody> createMelodyClasses(const vector<string> &melody)
{
	// temporary vector 
	vector<Melody> tmp;

	// we create a vector of class Melody, where all notes are separated objects 
	for (const auto &melodyName : melody) 
	{
		tmp.emplace_back(melodyName);
	}

	return tmp;
}


void tempo_choose(int &tempo)
{
	// we give an user three tempos to choose
	cout << "\nChoose the tempo: 60,120,180\n";
	// an user chooses his tempo
	tempo = IntCin(); 
	
	if(tempo != 180 && tempo != 120 && tempo != 60)
	{
		// if an user chooses wrong tempo he can try again
		cout << "Wrong number\n Try again\n";
		tempo_choose(tempo);
	}

}

bool print_end_text()
{
	string end;
	char end2 = 0;

	cout << "Do you want to finish? Y/N\n";
	cin >> end;
	// check if end is 1 character
	if (end.size() == 1)
		end2 = toupper(end[0]); // we change the small letter to capital when an user writes "y" or "n"
	
	if (end2 != 'N' && end2 != 'Y')
	{
		// when an user writes wrong letter he can try again
		cout << "Wrong letter, try again\n\n";
		return print_end_text(); //rekurencja nie wskazana-komentarz prowadz¹cego
	}
	
	// if an user writes "N" the end = true and then the program starts again
	return end2 == 'N' ? true : false;
}

int IntCin()
{
	int choice;
	cin >> choice;

	// operation to clear cin not to make bugs
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

	return choice;

}