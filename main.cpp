#include <algorithm>  //To lowercase string
#include <fstream>    //For input
#include <iostream>   //For output
#include <string>     //For std::string
#include <vector>     //For std::vector

// Values necessary for operations depending on direction
const int dir_right[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dir_down[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

//
// ─────────────────────────────────────────────────────────────────────────────
//   :::::: W O R D   S E A R C H   S O L V E R : :  :   :    :     :        : :
// ─────────────────────────────────────────────────────────────────────────────
//

class WordSearch {
   private:
    std::vector<std::string> letter_table;
    std::vector<std::string> word_list;
    std::vector<std::vector<bool>> display_table;
    size_t table_lines;
    size_t table_columns;
    size_t word_count;

    bool WordFits(size_t line, size_t column, int length, size_t dir) {
        length--;
        int word_end_line = line + length * dir_down[dir];
        int word_end_column = column + length * dir_right[dir];
        if (word_end_line < 0 || word_end_line >= table_lines) return 0;
        if (word_end_column < 0 || word_end_column >= table_columns) return 0;
        return 1;
    }

    void ClearDisplayTable() {
        for (size_t line = 0; line < table_lines; line++)
            for (size_t column = 0; column < table_columns; column++)
                display_table[line][column] = 0;
    }

    void DisplayWord(std::string word) {
        std::cout << "Found word \"" << word << "\":" << std::endl;
        for (size_t line = 0; line < table_lines; line++) {
            for (size_t column = 0; column < table_columns; column++) {
                if (!display_table[line][column])
                    std::cout << '+' << ' ';
                else
                    std::cout << (char)toupper(letter_table[line][column])
                              << ' ';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Press any key to continue...";
        std::cin.get();
        std::cout << std::endl;
    }

    // Checks location for word
    void SearchAtLocation(size_t line, size_t column, std::string word,
                          bool &word_found) {
        for (size_t dir = 0; dir < 8; dir++) {
            if (!WordFits(line, column, word.length(), dir)) {
                continue;  // Word not found!
            }
            int letter_line = line, letter_column = column;
            word_found = true;  // Assume we've found the word
            display_table[letter_line][letter_column] = true;
            for (int i = 1; i < word.length(); i++) {
                letter_line = line + i * dir_down[dir];
                letter_column = column + i * dir_right[dir];
                display_table[letter_line][letter_column] = 1;
                if (letter_table[letter_line][letter_column] != word[i]) {
                    word_found = false;
                    break;  // Word not found!
                }
            }
            if (!word_found) {
                ClearDisplayTable();
                continue;  // Word not found!
            }
            DisplayWord(word);
            ClearDisplayTable();
            return;  // Word found!
        }
    }

    // Searches for a specific word
    void SearchForWord(size_t word_i) {
        std::string word = word_list[word_i];
        bool word_found = false;

        for (size_t line = 0; line < table_lines; line++) {
            for (size_t column = 0; column < table_columns; column++) {
                if (letter_table[line][column] == word_list[word_i][0]) {
                    SearchAtLocation(line, column, word, word_found);
                    if (word_found) return;  // Word found!
                }
            }
        }
    }

   public:
    void Read() {
        // Opens the file, creates an object called "puzzle" for the file.
        std::ifstream puzzle;
        puzzle.open("puzzle.txt");
        // Creates another object, now for the words
        std::ifstream words;
        words.open("words.txt");

        // Check for error,
        if (puzzle.fail()) {
            std::cerr << "There was an error opening the file, did you use "
                         "puzzle.txt?"
                      << std::endl;
            return;
        }
        if (words.fail()) {
            std::cerr
                << "There was an error opening the file, did you use words.txt?"
                << std::endl;
            return;
        }

        // Input the table
        while (!puzzle.eof()) {
            std::string temp;
            puzzle >> temp;
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            letter_table.push_back(temp);
        }

        // Calculate the height and width
        table_lines = letter_table.size(),
        table_columns = letter_table[0].size();

        // Initialize display table
        std::vector<bool> blank_bool_vector;
        for (size_t column = 0; column < table_columns; column++)
            blank_bool_vector.push_back(false);
        for (size_t line = 0; line < table_lines; line++)
            display_table.push_back(blank_bool_vector);

        // Input the words
        while (!words.eof()) {
            std::string temp;
            words >> temp;
            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            word_list.push_back(temp);
        }
        word_count = word_list.size();
    }

    // Simple function that searches for each word, using the SearchForWord
    // function.
    void Solve() {
        for (size_t word_i = 0; word_i < word_count; word_i++) {
            SearchForWord(word_i);
        }
    }
};

int main(int argc, char const *argv[]) {
    // Creates an object from class WordSearch called puzzle.
    WordSearch puzzle;

    puzzle.Read();
    puzzle.Solve();

    return 0;
}