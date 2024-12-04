// Pip-Boy Style Controller Simulation in C++
// This program simulates a console-based Pip-Boy UI for educational purposes.
// It demonstrates multiple C++ concepts, fulfilling course requirements.

#include <iostream>
#include <vector>
#include <iomanip> // For formatted output
using namespace std;

// Function prototypes
void displayMainMenu();
void handleJoystick(int &x, int &y);
void displayRobot(const vector<vector<char> > &robot);
void togglePower(bool &powerState);
void displaySettings();
void optimizeExample();
int getTabChoice();

// Constants for joystick limits
const int MAX_X = 10;
const int MAX_Y = 10;

int main() {
    // Variables for the controller's state
    bool powerState = false; // Power toggle state
    int joystickX = 0, joystickY = 0; // Joystick coordinates
    int tabIndex = 0; // Tracks the current tab (menu option)

    // Simulated robot represented as a 2D grid (ASCII art)
    vector<vector<char> > robot(5, vector<char>(5, '.'));

    // Main program loop
    while (true) {
        // Check if the system is powered off
        if (!powerState) {
            cout << "\n[Pip-Boy is OFF] Press 1 to turn ON or 0 to quit.\n";
            int input;
            cin >> input;
            if (input == 1) {
                togglePower(powerState);
            } else {
                cout << "Goodbye!\n";
                break;
            }
        } else {
            // Show the main menu and get user's choice
            tabIndex = getTabChoice();
            switch (tabIndex) {
                case 1:
                    cout << "\n-- Joystick Control --\n";
                    handleJoystick(joystickX, joystickY);
                    break;
                case 2:
                    cout << "\n-- Robot Display --\n";
                    displayRobot(robot);
                    break;
                case 3:
                    cout << "\n-- Settings --\n";
                    displaySettings();
                    break;
                case 4:
                    cout << "\n-- Turn OFF Pip-Boy --\n";
                    togglePower(powerState);
                    break;
                default:
                    cout << "\nInvalid choice. Try again.\n";
            }
        }
    }

    return 0;
}

// Function definitions

// Displays the main menu and returns the user's choice
int getTabChoice() {
    cout << "\n--- Pip-Boy Main Menu ---\n";
    cout << "1. Joystick Control\n";
    cout << "2. Robot Display\n";
    cout << "3. Settings\n";
    cout << "4. Turn OFF\n";
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}

// Toggles the power state of the Pip-Boy
void togglePower(bool &powerState) {
    powerState = !powerState;
    cout << "\n[Pip-Boy is now " << (powerState ? "ON" : "OFF") << "]\n";
}

// Simulates joystick control by modifying x and y values
void handleJoystick(int &x, int &y) {
    cout << "Current Position: (" << x << ", " << y << ")\n";
    cout << "Enter new X (-" << MAX_X << " to " << MAX_X << "): ";
    cin >> x;
    cout << "Enter new Y (-" << MAX_Y << " to " << MAX_Y << "): ";
    cin >> y;

    // Clamp values to stay within the valid range
    x = max(-MAX_X, min(x, MAX_X));
    y = max(-MAX_Y, min(y, MAX_Y));
    cout << "Joystick updated to: (" << x << ", " << y << ")\n";
}

// Displays the robot as a 2D ASCII representation
void displayRobot(const vector<vector<char> > &robot) {
    cout << "\n-- Hexapod Robot --\n";
    for (const auto &row : robot) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << '\n';
    }
}

// Placeholder for settings menu
void displaySettings() {
    cout << "Settings menu is under construction. Customize your Pip-Boy soon!\n";
}

// Demonstrates a simple optimization example (e.g., reusable functionality)
void optimizeExample() {
    cout << "This function is optimized for reuse.\n";
    // Example: Add a real operation here as the project evolves
}