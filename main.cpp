#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

// Structure to store user reservation details
struct Reservation {
    string name;
    string timeSlot;
    string gymSection;
};

// Function to display available time slots
void displayTimeSlots(const vector<string>& timeSlots) {
    cout << "\nAvailable Time Slots:\n";
    for (int i = 0; i < timeSlots.size(); i++) {
        cout << i + 1 << ". " << timeSlots[i] << endl;
    }
}

// Function to display gym sections
void displayGymSections(const vector<string>& gymSections) {
    cout << "\nAvailable Gym Sections:\n";
    for (int i = 0; i < gymSections.size(); i++) {
        cout << i + 1 << ". " << gymSections[i] << endl;
    }
}

// Function to take and validate user input
int getUserChoice(int maxOption) {
    int choice;
    while (true) {
        cout << "Enter your choice (1-" << maxOption << "): ";
        cin >> choice;
        if (choice >= 1 && choice <= maxOption) {
            return choice;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

// Function to recommend a time slot using a simple "AI" logic
string recommendTimeSlot(const vector<string>& timeSlots, const vector<Reservation>& reservations) {
    vector<int> slotCount(timeSlots.size(), 0);
    for (const auto& res : reservations) {
        auto it = find(timeSlots.begin(), timeSlots.end(), res.timeSlot);
        if (it != timeSlots.end()) {
            slotCount[it - timeSlots.begin()]++;
        }
    }
    int recommendedSlot = min_element(slotCount.begin(), slotCount.end()) - slotCount.begin();
    return timeSlots[recommendedSlot];
}

int main() {
    // Predefined data
    vector<string> timeSlots = {"6:00 AM - 7:00 AM", "7:00 AM - 8:00 AM", "8:00 AM - 9:00 AM", "5:00 PM - 6:00 PM"};
    vector<string> gymSections = {"Cardio Zone", "Weightlifting", "Yoga Room", "Swimming Pool"};
    vector<Reservation> reservations;

    cout << "Welcome to the Gym Reservation Bot!\n";

    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Make a Reservation\n";
        cout << "2. View Existing Reservations\n";
        cout << "3. Get AI Recommendation\n";
        cout << "4. Exit\n";

        int mainChoice = getUserChoice(4);

        if (mainChoice == 1) {
            // Make a reservation
            cin.ignore();
            string name;
            cout << "Enter your name: ";
            getline(cin, name);

            displayTimeSlots(timeSlots);
            int timeChoice = getUserChoice(timeSlots.size());
            string chosenTimeSlot = timeSlots[timeChoice - 1];

            displayGymSections(gymSections);
            int sectionChoice = getUserChoice(gymSections.size());
            string chosenGymSection = gymSections[sectionChoice - 1];

            reservations.push_back({name, chosenTimeSlot, chosenGymSection});
            cout << "Reservation confirmed for " << name << " at " << chosenTimeSlot << " in " << chosenGymSection << ".\n";

        } else if (mainChoice == 2) {
            // View reservations
            if (reservations.empty()) {
                cout << "No reservations yet.\n";
            } else {
                cout << "\n--- Existing Reservations ---\n";
                for (const auto& res : reservations) {
                    cout << "Name: " << res.name << ", Time: " << res.timeSlot << ", Section: " << res.gymSection << endl;
                }
            }

        } else if (mainChoice == 3) {
            // Get AI recommendation
            if (reservations.empty()) {
                cout << "No reservations found. The first slot is recommended.\n";
            } else {
                string recommendedSlot = recommendTimeSlot(timeSlots, reservations);
                cout << "AI recommends the time slot: " << recommendedSlot << ".\n";
            }

        } else if (mainChoice == 4) {
            // Exit
            cout << "Thank you for using the Gym Reservation Bot. Goodbye!\n";
            break;
        }
    }

    return 0;
}
