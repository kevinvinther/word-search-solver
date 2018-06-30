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

void SearchForWordAtGivenLocation(std::vector<std::string> table,
                                  std::string word) {
    for (size_t word_progress = 0; word_progress < word.size();
         word_progress++) {
        // Search for word in one direction
    }
}

int main(int argc, char const *argv[]) {
    // Opens the file, creates an object called "puzzle" for the file.
    std::ifstream puzzle;
    puzzle.open("puzzle.txt");
    std::ifstream words;
    words.open("words.txt");

    // Check for error, to return either false or true
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

    // Input the table
    std::vector<std::string> letter_table;
    while (!puzzle.eof()) {
        std::string temp;
        puzzle >> temp;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        letter_table.push_back(temp);
    }

    // Calculate the height and width
    const int table_height = letter_table.size(),
              table_width = letter_table[0].size();

    // Input the words
    std::vector<std::string> word_list;
    int word_count;
    while (!words.eof()) {
        std::string temp;
        words >> temp;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        word_list.push_back(temp);
    }
    word_count = word_list.size();

    // Print the puzzle
    for (int i = 0; i < letter_table.size(); i++) {
        std::cout << letter_table.at(i) << std::endl;
    }

    // Main loop
    for (size_t word_progress = 0; word_progress < word_count;
         word_progress++) {
        std::string word = word_list[word_progress];
        bool word_found = false;
        std::cout << "Searching for word " << word << std::endl;

        if (word_found != true) {
            for (size_t height_progress = 0; height_progress < table_height;
                 height_progress++) {
                for (size_t width_progress = 0; width_progress < table_width;
                     width_progress++) {
                    if (letter_table.at(height_progress).at(width_progress) ==
                        word_list[word_progress].at(0)) {
                        std::cout << "Found "
                                  << letter_table.at(height_progress)
                                         .at(width_progress)
                                  << " at " << height_progress << ","
                                  << width_progress << std::endl;
                        // Search on for word
                        for (size_t directions = 0; directions < 8;
                             directions++) {
                            // LookForWord
                        }

                        continue;
                    }
                }
            }
        }
    }

    // Tests
    std::cout << "Table width: " << table_width << std::endl
              << "Table height: " << table_height << std::endl
              << "Chosen directions: " << std::endl;

    std::cout << std::endl << "Words: " << std::endl;
    for (int i = 0; i < word_list.size(); i++) {
        std::cout << word_list[i] << std::endl;
    }

    return 0;
}