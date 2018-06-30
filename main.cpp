#include <iostream>
#include <fstream> //For input output
#include <string>
#include <vector>
#include <algorithm>

//
// ──────────────────────────────────────────────────────────────────────────── I ──────────
//   :::::: W O R D   S E A R C H   S O L V E R : :  :   :    :     :        :          :
// ──────────────────────────────────────────────────────────────────────────────────────
//

int main(int argc, char const *argv[]) {
	//Opens the file, creates an object called "puzzle" for the file.
	std::ifstream puzzle;
	puzzle.open("puzzle.txt");
	std::ifstream words;
	words.open("words.txt");

	//Check for error, to return either false or true
	if (puzzle.fail()) {
		std::cerr << "There was an error opening the file, did you use puzzle.txt?" << std::endl;
		return 1;
	}
	if (words.fail()) {
		std::cerr << "There was an error opening the file, did you use words.txt?" << std::endl;
		return 1;
	}

	//Input the table
	std::vector<std::string> letter_table;
	while (!puzzle.eof()) {
		std::string temp;
		puzzle >> temp;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		letter_table.push_back(temp);
	}

	//Calculate the height and width
	const int table_height = letter_table.size(),
		table_width = letter_table[0].size();


	//Input the words
	std::vector<std::string> word_list;
	int word_count;
	while(!words.eof()) {
		std::string temp;
		words >> temp; 
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		word_list.push_back(temp); 
	}
	word_count = word_list.size();
	char crt_word_starting_letter;

	//Main loop
	for (size_t crt_word_index = 0; crt_word_index < word_count; crt_word_index++) {
		std::cout << "Finding word: " << word_list[crt_word_index] << std::endl;
		crt_word_starting_letter = word_list[crt_word_index][0];
		for (int direction_tested = 0; direction_tested < 8; direction_tested++) {
				// CODE WHOMST SEARCHES FOR THE WORD IN THAT DIRECTION
				// and then
				// CODE WHOMST DISPLAYS THE FOUND WORD AND ITS LOCATION
		}
	}

	//Tests
	std::cout << "Table width: " << table_width << std::endl
			  << "Table height: " << table_height << std::endl
			  << "Chosen directions: " << std::endl;
	/*
	for (int i = 0; i < 8; i++) {
		std::cout << valid_directions[i] << ' ';
	}
	*/
	std::cout << std::endl 
			  << "Words: " << std::endl; 
	for(int i = 0; i < word_list.size(); i++) {
		std::cout << word_list[i] << std::endl; 
	}

	return 0;
}
