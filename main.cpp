#include <iostream>
#include <cstdio>  // For fopen()
#include <windows.h> // For PlaySound
#include <mmsystem.h> // Multimedia Sound
#include "cab.cpp"
#include "login.cpp"

using namespace std;

// Function to display a cab ASCII art
void displayCabArt() {
    cout << R"(
          ______
         /|_||_\`.__
        (   _    _ _\
        =`-(_)--(_)-'
    )" << endl;
}

int main() {
    // Display the cab art
    displayCabArt();

    // Use the absolute path to the sound file
    string soundPath = "C:\\DSA-Project-main\\DSA-Project-main\\welcome .wav";

    // Check if the WAV file exists by opening it
    FILE* file = fopen(soundPath.c_str(), "rb");
   
    // Play the welcome sound using PlaySound
    if (!PlaySound(TEXT(soundPath.c_str()), NULL, SND_ASYNC | SND_FILENAME)) {
        DWORD error = GetLastError();
        cerr << "Error: Could not play " << soundPath << ". Windows Error Code: " << error << endl;
    } else {
        
        Sleep(3000); // Wait for 3 seconds to let the sound play
    }

    Login login;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Welcome to the Marine Cab Services !" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    login.start();

    Graph g1;
    // Create an instance of the cabBooking class
    cabBooking bookingSystem;

    string userLocation;
    g1.printLocations();
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Enter user location (If new User Enter 2 times(Captcha)): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, userLocation);
    bookingSystem.cabsAvailable(userLocation);
    cout << "------------------------------------------------------------------------------" << endl;
    cin.ignore();

    float amountNew = bookingSystem.getAmount();
    float people = bookingSystem.getPeople();
    float amountPerPerson = amountNew / people;

    if(login.getPremiumPoints() == 0){
        cout << "Total Amount: " << amountNew << endl;
        cout << "Amount per person: " << amountPerPerson << endl;
        cout << "Payment in process !!" << endl;
        cout << "Payment done!" << endl;
        cout << "------------------------------------------------------------------------------" << endl;
        cout << "Thank you for choosing S-CUBE Cabs\nWe Hope You continue to avail our service " << endl;
        cout << "------------------------------------------------------------------------------" << endl;
    }
    else {
        login.updatePremiumPoints();
        cout << "You got a premium discount!!\n18%* off for you :)\n";
        amountNew = amountNew - (amountNew * (0.18));
        amountPerPerson = amountNew / people;
        cout << "Total Amount: " << amountNew << endl;
        cout << "Amount per person: " << amountPerPerson << endl;
    }

    cout << "Payment in process !!" << endl;
    cout << "Payment done!" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << "Thank you for choosing S-CUBE Cabs\nWe Hope You continue to avail our service " << endl;
    cout << "------------------------------------------------------------------------------" << endl;

    // Play the "Thank.wav" sound after payment
    string thankSoundPath = "C:\\DSA-Project-main\\DSA-Project-main\\Thank.wav";
    
    if (!PlaySound(TEXT(thankSoundPath.c_str()), NULL, SND_ASYNC | SND_FILENAME)) {
        DWORD error = GetLastError();
        cerr << "Error: Could not play " << thankSoundPath << ". Windows Error Code: " << error << endl;
    } else {
       
        Sleep(3000); // Wait for 3 seconds to let the thank sound play
    }

    return 0;
}
