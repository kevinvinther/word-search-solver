#include <algorithm>
#include <fstream>  //For input output
#include <iostream>
#include <string>
#include <vector>

//
// ─────────────────────────────────────────────────────────────────────────────────────────
//   :::::: W O R D   S E A R C H   S O L V E R : :  :   :    :     :        : :
// ──────────────────────────────────────────────────────────────────────────────────────
//

class WordSearch {
	private:

	std::vector<std::string> letter_table;
	std::vector<std::string> word_list;
    size_t table_height;
    size_t table_width;
    size_t word_count;

    void SearchForWordAtGivenLocation(size_t location_height, size_t location_width, std::string word) {
        for (size_t directions = 0; directions < 8; directions++) {
            // LookForWord
        }
    }

    void SearchForWord(size_t word_index) {
        std::string word = word_list[word_index];
        bool word_found = false;
        std::cout << "Searching for word " << word << std::endl;

        if (word_found != true) {
            for (size_t height_progress = 0; height_progress < table_height; height_progress++) {
                for (size_t width_progress = 0; width_progress < table_width; width_progress++) {
                    if (letter_table[height_progress][width_progress] == word_list[word_index][0]) {
                        // Test output, temporary
                        std::cout << "Found "
                                  << letter_table[height_progress][width_progress]
                                  << " at " << height_progress << ","
                                  << width_progress << std::endl;
                        
                        // Search on for word
                        SearchForWordAtGivenLocation(height_progress, width_progress, word);
                        continue;
                    }
                }
            }
        }
    }

    public:

    void ReadPuzzle () {
        // Opens the file, creates an object called "puzzle" for the file.
        std::ifstream puzzle;
        puzzle.open("puzzle.txt");
        std::ifstream words;
        words.open("words.txt");

        // Check for error, to return either false or true - temporarily disabled bc i broke it
        /*
        if (puzzle.fail()) {
            std::cerr
                << "There was an error opening the file, did you use puzzle.txt?"
                << std::endl;
            return 1;
        }
        if (words.fail()) {
            std::cerr
                << "There was an error opening the file, did you use words.txt?"
                << std::endl;
            return 1;
        }
        */

        // Input the table
        while (!puzzle.eof()) {
            std::string temp;
            puzzle >> temp;
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            letter_table.push_back(temp);
        }

        // Calculate the height and width
        table_height = letter_table.size(),
        table_width = letter_table[0].size();

        // Input the words
        while (!words.eof()) {
            std::string temp;
            words >> temp;
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            word_list.push_back(temp);
        }
        word_count = word_list.size();
    }

    void PrintPuzzle () {
        std::cout << std::endl << "Words: " << std::endl;
        for (int i = 0; i < word_count; i++) {
            std::cout << word_list[i] << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < letter_table.size(); i++) {
            std::cout << letter_table[i] << std::endl;
        }
    }

    void Solve () {
        for (size_t word_index = 0; word_index < word_count; word_index++) {
            SearchForWord(word_index);
        }
    }

};

int main(int argc, char const *argv[]) {
    WordSearch puzzle;

    puzzle.ReadPuzzle();
    puzzle.PrintPuzzle();
    puzzle.Solve();

    return 0;
}