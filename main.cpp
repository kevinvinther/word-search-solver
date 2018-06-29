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

	int table_height, table_width; 
	std::vector<std::string> letter_table;

	while (!puzzle.eof()) 
	{
		std::string input_line;
		getline(puzzle, input_line);
		letter_table.push_back(input_line);
	}

	table_height = letter_table.size();
	table_width = letter_table[0].length();

	return 0;
}
