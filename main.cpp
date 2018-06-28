#include <iostream>
#include <fstream> //For input output
#include <string>
#include <vector>
//
// ──────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: W O R D   S E A R C H   S O L V E R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────
//

	using namespace std; 

int main(int argc, char const *argv[]) {
	//Opens the file, creates an object called "puzzle" for the file.
	std::ifstream puzzle;
	puzzle.open("puzzle.txt");

	//Check for error, to return either false or true
	if (puzzle.fail())
	{
		std::cerr << "There was an error opening the file, did you use puzzle.txt?" << std::endl;
		return 1;
	}

	int table_height = 0, table_width = 0; 

	std::string item;

	std::string input_row;
	std::vector<std::string> letter_table; 

	int table_height, table_width;
	string *arr;

	puzzle >> table_height, table_width;
	arr = new string[table_height];

	std::cout << arr[2][2]; 
	
	

	//std::cout << height << " total lines." << std::endl;

	// point wherest the height and width should be known		

	return 0;
}
