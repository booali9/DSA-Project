#include <bits/stdc++.h>
#include <ctime>
using namespace std;

class Login {
private:
    string name;
    string email;
    string phoneNumber;
    int premiumPoints;

    // Function to generate a random 4-digit OTP
    int generateOTP() {
        srand(time(NULL));
        return rand() % 8998 + 1000;
    }

    // Function to check if the phone number is in the CSV file
    bool isPhoneNumberInFile(const string& phone) {
        ifstream file("users.csv");
        string line, cell;
        getline(file, line); // Skip the header row
        while (getline(file, line)) {
            stringstream lineStream(line);
            getline(lineStream, cell, ',');
            if (cell == phone) {
                // If phone number is found read the rest of the line for name email, and premium points
                getline(lineStream, name, ',');
                getline(lineStream, email, ',');
                lineStream >> premiumPoints;
                return true;
            }
        }
        return false;
    }

    // Function to add a new user to the CSV file
    void addUserToFile(const string& phone, const string& name, const string& email) {
        ofstream file("users.csv", ios::app);
        if (file.tellp() == 0) { // If the file is empty, write the header
            file << "Phone Number,Name,Email,PremiumPoints" << endl;
        }
        premiumPoints = 1;  // New users get 1 premium point automatically
        file << phone << "," << name << "," << email << "," << premiumPoints << endl;
        cout << "One premium point added to your account!" << endl;
    }

    // Function to update premium points in the CSV file
    void updatePremiumPointsInFile(const string& phone, int points) {
        ifstream inFile("users.csv");
        ofstream outFile("temp.csv");

        string line;
        getline(inFile, line); // Copy header to the new file
        outFile << line << endl;

        while (getline(inFile, line)) {
            stringstream lineStream(line);
            string cell;
            getline(lineStream, cell, ',');
            if (cell == phone) {
                // If phone number is found, update the premium points
                outFile << phone << "," << name << "," << email << "," << points << endl;
            } else {
                outFile << line << endl;
            }
        }

        inFile.close();
        outFile.close();

        // Rename the new file to the original file
        remove("users.csv");
        rename("temp.csv", "users.csv");
    }

public:
    // Function to start the login or signup process
    void start() {
        cout << "Enter your phone number: ";
        cin >> phoneNumber;

        int otp = generateOTP();
        cout << "Your OTP is: " << otp << endl;

        int userOTP;
        cout << "Enter the OTP: ";
        cin >> userOTP;

        while(1){
            if (userOTP != otp)
            {
                cout << "Incorrect OTP. Please try again." << endl;
                cin >> userOTP;
            }
            else break;
        }

        if (userOTP == otp) {
            if (isPhoneNumberInFile(phoneNumber)) {
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "Here are your details:\n";
                cout << "Name: " << name << "\nEmail: " << email << "\nPhone Number: " << phoneNumber << "\nPremium Points: " << premiumPoints << endl;
                cout << "------------------------------------------------------------------------------" << endl;
            } else {
                cout << "It seems you are a new user. Please enter your details.\n";
                cout << "Enter your name: ";
                cin.ignore(); // Ignore the newline left in the input stream
                getline(cin, name); // Use getline to handle spaces in names
                cout << "Enter your email: ";
                getline(cin, email);
                addUserToFile(phoneNumber, name, email);
                cout << "Here are your details:\n";
                cout << "Name: " << name << "\nEmail: " << email << "\nPhone Number: " << phoneNumber << "\nPremium Points: " << premiumPoints << endl;
                cout << "------------------------------------------------------------------------------" << endl;
            }
        }

        // if premiumPoints are zero
        if(premiumPoints == 0){
            cout<< "Your premium points are over. \nDo you want to recharge(press 1) or continue(press 0)"<<endl;
            int key = 0;
            cin>> key;
            if(key == 1){
                int otp = generateOTP();
                cout << "Your OTP is: " << otp << endl;
                int userOTP;
                cout << "Enter the OTP: ";
                cin >> userOTP;
                while(1){
                    if (userOTP != otp)
                    {
                        cout << "Incorrect OTP. Please try again." << endl;
                        cin >> userOTP;
                    }
                    else break;
                }
                cout<<"Payment done!!"<<endl;
                premiumPoints = 7;
                cout << "------------------------------------------------------------------------------" << endl;
                cout << "Name: " << name << "\nPremium Points: "<< premiumPoints << endl;
                cout << "------------------------------------------------------------------------------" << endl;
            }
        }
    }

    // Function to get the user's name
    string getName() const {
        return name;
    }

    // Function to get the user's email
    string getEmail() const {
        return email;
    }

    // Function to get the user's premium points
    int getPremiumPoints() const {
        return premiumPoints;
    }

    // Function to update premium points
    void updatePremiumPoints() {
        premiumPoints--;
        updatePremiumPointsInFile(phoneNumber, premiumPoints);
    }
};
