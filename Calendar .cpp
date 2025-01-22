#include <iostream>
#include <string>
using namespace std;

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to print the calendar of a specific month
void printCalendar(int month, int year) {
    // Array with the number of days in each month (index 0 is for January)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap year (February has 29 days in a leap year)
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    // Names of the months
    string monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Days of the week
    string daysOfWeek[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    // Print month name and year
    cout << "\n" << monthNames[month - 1] << " " << year << "\n";

    // Print day names
    for (int i = 0; i < 7; i++) {
        cout << daysOfWeek[i] << " ";
    }
    cout << endl;

    // Calculate the starting day of the month (0 = Sunday, 1 = Monday, etc.)
    // Zeller's congruence algorithm for calculating the first day of the month
    int m = month;
    int d = 1; // First day of the month
    if (m == 1 || m == 2) {
        m += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int f = d + (13 * (m + 1)) / 5 + k + k / 4 + j / 4 + 5 * j;
    int firstDay = f % 7;  // First day of the month (0 = Saturday, 1 = Sunday, etc.)

    // Print the spaces for the first week
    for (int i = 0; i < firstDay; i++) {
        cout << "    ";
    }

    // Print the days of the month
    int days = daysInMonth[month - 1];
    for (int i = 1; i <= days; i++) {
        cout << (i < 10 ? " " : "") << i << "  ";
        if ((firstDay + i) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    int year, month;
    char choice;

    do {
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter month (1-12): ";
        cin >> month;

        // Check for valid input
        if (month < 1 || month > 12) {
            cout << "Invalid month! Please enter a number between 1 and 12." << endl;
            continue;  // Skip the rest of the code and ask for input again
        }

        // Print the calendar for the given month
        printCalendar(month, year);

        // Ask if the user wants to enter another month
        cout << "\nDo you want to enter another month? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');  // Continue if the user enters 'Y' or 'y'

    cout << "Thank you for using the calendar program!" << endl;

    return 0;
}