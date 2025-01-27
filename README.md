# Gym-Reservation-bot
This project is a simple Gym Reservation Bot implemented in C++ that allows users to book time slots and gym sections, view existing reservations, and get AI recommendations for the least crowded time slot.

1.Features-->

Make Reservations:
Users can choose a time slot and gym section to book.
View Reservations:
Displays all existing reservations with user details.
AI Recommendation:
Recommends the least crowded time slot using a simple AI-based logic.
User-Friendly Interface:
Text-based menu system for easy navigation.

2.How It Works-->

Time Slots: Predefined time slots like 6:00 AM - 7:00 AM, 7:00 AM - 8:00 AM, etc.
Gym Sections: Includes "Cardio Zone", "Weightlifting", "Yoga Room", and "Swimming Pool".
AI Logic: Counts reservations in each time slot and recommends the slot with the least bookings.

Functions:

displayTimeSlots(): Displays available time slots.
displayGymSections(): Displays gym sections.
getUserChoice(): Validates user input.
recommendTimeSlot(): Provides AI-based slot recommendation.

3.How to Run-->

Compile the program:
g++ main.cpp -o gym_bot
Run the program:
./gym_bot

Future Enhancements

Persistence:
Save reservations to a file or database for permanent storage.
Advanced AI:
Use a pre-trained machine learning model for smarter recommendations.
GUI:
Create a graphical interface using Qt or another GUI library.
