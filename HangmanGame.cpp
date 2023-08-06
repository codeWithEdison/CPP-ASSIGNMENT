
//C++ assignment 3
//contributors:
//1.DUSHIME Dieudonne 222008981
// 2.UWIHANGANYE Edison 222013008 3.
// MUKAGASIRABO Beatrice 222004462



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

std::string get_random_word() {
    std::vector<std::string> words = {"apple", "banana", "orange", "grape", "cherry", "kiwi", "mango", "watermelon"};
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(words.begin(), words.end(), generator);
    return words[0];
}

std::string display_word(const std::string& word, const std::vector<char>& guessed_letters) {
    std::string displayed_word;
    for (char letter : word) {
        if (std::find(guessed_letters.begin(), guessed_letters.end(), letter) != guessed_letters.end()) {
            displayed_word += letter;
        } else {
            displayed_word += '-';
        }
    }
    return displayed_word;
}

bool is_valid_input(char input_char) {
    return isalpha(input_char);
}

bool is_vowel(char letter) {
    char lower_case_letter = tolower(letter);
    return (lower_case_letter == 'a' || lower_case_letter == 'e' || lower_case_letter == 'i' ||
            lower_case_letter == 'o' || lower_case_letter == 'u');
}

int main() {
    std::string word_to_guess = get_random_word();
    std::vector<char> guessed_letters;
    int warnings = 3;
    int guesses_remaining = 6;

    std::cout << "Welcome to Hangman!\n";
    std::cout << "Guess the word one character at a time.\n";
    std::cout << "You start with 6 guesses.\n";
    std::cout << "Let's begin!\n";

    while (guesses_remaining > 0) {
        std::cout << "\nGuesses remaining: " << guesses_remaining << std::endl;
        std::cout << "Letters not yet used: ";
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (std::find(guessed_letters.begin(), guessed_letters.end(), ch) == guessed_letters.end()) {
                std::cout << ch;
            }
        }
        std::cout << std::endl;

        std::string displayed_word = display_word(word_to_guess, guessed_letters);
        std::cout << displayed_word << std::endl;

        char user_input;
        std::cout << "Enter a letter: ";
        std::cin >> user_input;
        user_input = tolower(user_input);

        if (!is_valid_input(user_input)) {
            if (warnings > 0) {
                --warnings;
                std::cout << "Invalid input! You have " << warnings << " warning(s) left.\n";
            } else {
                --guesses_remaining;
                std::cout << "Invalid input! You lost a guess.\n";
            }
        } else if (std::find(guessed_letters.begin(), guessed_letters.end(), user_input) != guessed_letters.end()) {
            if (warnings > 0) {
                --warnings;
                std::cout << "You already guessed that letter! You have " << warnings << " warning(s) left.\n";
            } else {
                --guesses_remaining;
                std::cout << "You already guessed that letter! You lost a guess.\n";
            }
        } else {
            guessed_letters.push_back(user_input);
            if (word_to_guess.find(user_input) != std::string::npos) {
                if (std::count(guessed_letters.begin(), guessed_letters.end(), user_input) == std::count(word_to_guess.begin(), word_to_guess.end(), user_input)) {
                    int score = guesses_remaining * std::set<char>(word_to_guess.begin(), word_to_guess.end()).size();
                    std::cout << "\nCongratulations! You guessed the word '" << word_to_guess << "' correctly!\n";
                    std::cout << "Your score is: " << score << std::endl;
                    return 0;
                }
            } else {
                if (is_vowel(user_input)) {
                    guesses_remaining -= 2;
                } else {
                    --guesses_remaining;
                }
            }
        }
    }

    std::cout << "\nGame Over! The word was '" << word_to_guess << "'. Better luck next time!\n";

    return 0;
}
