#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function declaration
void askQuestion(const string& question, const vector<string>& options, char correctAnswer, int& score);

int main() {
    // Variables of different data types
    int score = 0;
    int totalQuestions = 3;
    string playerName;

    // Prompt for player name
    cout << "Enter your name: ";
    getline(cin, playerName);

    // Welcome message
    cout << "\nWelcome, " << playerName << "! Let's start the quiz.\n\n";

    // Nested loops to manage questions and retries
    for (int attempt = 1; attempt <= 2; ++attempt) { // Outer loop for retries
        cout << "Attempt " << attempt << ":\n";

        // Questions stored in arrays/lists
        vector<string> questions = {
            "What is the capital of France?",
            "Which planet is known as the Red Planet?",
            "Who wrote 'Romeo and Juliet'?"
        };

        vector<vector<string>> options = {
            {"a) Berlin", "b) Madrid", "c) Paris", "d) Rome"},
            {"a) Venus", "b) Mars", "c) Jupiter", "d) Saturn"},
            {"a) Charles Dickens", "b) William Shakespeare", "c) Mark Twain", "d) Jane Austen"}
        };

        vector<char> correctAnswers = {'c', 'b', 'b'};

        // Reset score for each attempt
        score = 0;

        // Nested loop to ask each question
        for (size_t i = 0; i < questions.size(); ++i) {
            askQuestion(questions[i], options[i], correctAnswers[i], score);
        }

        // Nested decision structure to evaluate performance
        if (score == totalQuestions) {
            cout << "\nExcellent, " << playerName << "! You got all questions correct!\n";
            break; // Exit after perfect score
        } else if (score > 0) {
            cout << "\nGood job, " << playerName << "! You scored " << score << " out of " << totalQuestions << ".\n";
        } else {
            cout << "\nBetter luck next time, " << playerName << ".\n";
        }
        cout << "---------------------------------\n";
    }

    cout << "\nThank you for playing, " << playerName << "!\n";

    return 0;
}

// Function definition
void askQuestion(const string& question, const vector<string>& options, char correctAnswer, int& score) {
    cout << question << "\n";

    // Display options
    for (const string& option : options) {
        cout << option << "\n";
    }

    // Get player's answer
    char answer;
    cout << "Your answer: ";
    cin >> answer;
    answer = tolower(answer); // Ensure case-insensitivity

    // Check answer
    if (answer == correctAnswer) {
        cout << "Correct!\n\n";
        score++;
    } else {
        cout << "Incorrect. The correct answer was " << correctAnswer << ".\n\n";
    }
}
