#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include "location.cpp"
#include "driver.cpp"
using namespace std;

// A class to represent a cab object
class Cab
{
    // Private attributes
private:
    int cabNumber;     // A unique number for each cab
    string driverName; // The name of the driver
    string location;   // The current location of the cab
    bool availability; // The availability status of the cab

    // Public methods
public:
    // A constructor to initialize the cab object
    Cab(int number, string name, string loc, bool avail)
    {
        cabNumber = number;
        driverName = name;
        location = loc;
        availability = avail;
    }

    // A method to get the cab number
    int getCabNumber()
    {
        return cabNumber;
    }

    // A method to get the driver name
    string getDriverName()
    {
        return driverName;
    }

    // A method to get the location
    string getLocation()
    {
        return location;
    }

    // A method to get the availability
    bool getAvailability()
    {
        return availability;
    }

    // A method to set the location
    void setLocation(string newLoc)
    {
        location = newLoc;
    }

    // A method to set the availability
    void setAvailability(bool newAvail)
    {
        availability = newAvail;
    }

    // A method to display the cab details
    void displayCab()
    {
        cout << "Driver name: " << driverName << endl;
        cout << "Cab number: " << cabNumber << endl;
        cout << "Location: " << location << endl;
        cout << "Availability: " << (availability ? "Yes" : "No") << endl;
    }

    void displayForBilling()
    {
        cout << "Driver name : " << driverName << endl;
        cout << "Cab number : " << cabNumber << endl;
    }

    virtual ~Cab() {}
};

// A subclass to represent a sedan cab object
class Sedan : public Cab
{
    // Private attributes
private:
    int seats;   // The number of seats in the sedan
    double fare; // The fare per kilometer for the sedan

    // Public methods
public:
    // A constructor to initialize the sedan object
    Sedan(int number, string name, string loc, bool avail) : Cab(number, name, loc, avail)
    {
        seats = 4;
        fare = 10.5;
    }

    // A method to get the number of seats
    int getSeats()
    {
        return seats;
    }

    // A method to get the fare
    double getFare()
    {
        return fare;
    }

    // A method to display the sedan details
    void display()
    {
        displayCab(); // Call the base class method
        cout << "Seats: " << seats << endl;
        cout << "Fare: " << fare << endl;
    }

    virtual ~Sedan() {}
};

// A subclass to represent a Intercity cab object
class Intercity : public Cab
{
    // Private attributes
private:
    int seats;   // The number of seats in the Intercity
    double fare; // The fare per kilometer for the Intercity

    // Public methods
public:
    // A constructor to initialize the Intercity object
    Intercity(int number, string name, string loc, bool avail) : Cab(number, name, loc, avail)
    {
        seats = 3;
        fare = 8.25;
    }

    // A method to get the number of seats
    int getSeats()
    {
        return seats;
    }

    // A method to get the fare
    double getFare()
    {
        return fare;
    }

    // A method to display the Intercity details
    void display()
    {
        displayCab(); // Call the base class method
        cout << "Seats: " << seats << endl;
        cout << "Fare: " << fare << endl;
    }

    virtual ~Intercity() {}
};

// A subclass to represent a SUV cab object
class SUV : public Cab
{
    // Private attributes
private:
    int seats;   // The number of seats in the SUV
    double fare; // The fare per kilometer for the SUV

    // Public methods
public:
    // A constructor to initialize the SUV object
    SUV(int number, string name, string loc, bool avail) : Cab(number, name, loc, avail)
    {
        seats = 7;
        fare = 15.75;
    }

    // A method to get the number of seats
    int getSeats()
    {
        return seats;
    }

    // A method to get the fare
    double getFare()
    {
        return fare;
    }

    // A method to display the SUV details
    void display()
    {
        displayCab(); // Call the base class method
        cout << "Seats: " << seats << endl;
        cout << "Fare: " << fare << endl;
    }
    virtual ~SUV() {}
};

class cabBooking
{
public:
    Graph g;
    int dist = 0;
    double fare = 0;
    int people = 0;
    int peoplePass = 0;
    int maxPerson = 0;
    float amount = 0;
    float amountPass = 0;
    float amountPerPerson = 0;
    CabRatingSystem ratingSystem;
    // locations
    vector<string> locations = {"Art Gallery Haven", "Beachfront Resort", "Bookworm's Cafe", "Cafe Harmony", "Central Market", "Cinema Paradiso", "City Center", "Cricket Stadium", "Fitness Junction", "Green Oasis Park", "Hotel Plaza", "Park", "Restaurant Elegance", "Shopping Mall Deluxe", "Sky Lounge", "Tech Hub Plaza"};
    vector<Cab *> allCabs;

    // constructor to add all the cabs with their details
    cabBooking()
    {
         allCabs.push_back(new Intercity(535454, "Ahmed Khan", locations[rand() % locations.size()], true));
    allCabs.push_back(new Sedan(876123, "Fatima Ali", locations[rand() % locations.size()], true));
    allCabs.push_back(new SUV(342567, "Bilal Malik", locations[rand() % locations.size()], true));
    allCabs.push_back(new Intercity(998877, "Sana Tariq", locations[rand() % locations.size()], true));
    allCabs.push_back(new Sedan(111222, "Hassan Shah", locations[rand() % locations.size()], true));
    allCabs.push_back(new Intercity(654321, "Zainab Iqbal", locations[rand() % locations.size()], true));
    allCabs.push_back(new SUV(777888, "Ali Raza", locations[rand() % locations.size()], true));
    allCabs.push_back(new Sedan(444555, "Mariam Butt", locations[rand() % locations.size()], true));
    allCabs.push_back(new Intercity(123456, "Usman Javed", locations[rand() % locations.size()], true));
    allCabs.push_back(new Sedan(987654, "Sobia Khan", locations[rand() % locations.size()], true));
    allCabs.push_back(new SUV(234567, "Arslan Ahmed", locations[rand() % locations.size()], true));
    allCabs.push_back(new Intercity(876543, "Nida Hussain", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new SUV(345678, "Muneeb Akhtar", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Sedan(567890, "Kiran Saleem", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Intercity(432109, "Rehan Nawaz", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new SUV(555666, "Ayesha Bashir", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Sedan(678901, "Kamran Shah", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Intercity(210987, "Muneeba Shahid", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Sedan(789012, "Farhan Malik", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new SUV(890123, "Sana Riaz", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Intercity(321098, "Adeel Ali", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Sedan(654323, "Asma Bukhari", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new SUV(111999, "Shahzad Hussain", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Intercity(222333, "Rana Yasir", locations[rand() % locations.size()], rand() % 2));
    allCabs.push_back(new Sedan(333444, "Nadia Javed", locations[rand() % locations.size()], rand() % 2));
    }

    // Function to display available cabs in a given location
    void cabsAvailable(string userLocation)
    {
        cout << "Available Cabs at " << userLocation << ":" << endl;
        int check = 1;
        int cabCounter = 0;
        for (Cab *cab : allCabs)
        {
            if (cab->getLocation() == userLocation && cab->getAvailability())
            {
                cabCounter++;
                cout << "Cab Option : " << cabCounter << ") ->" << endl;
                cab->displayCab();
                // input cab->getNumber // for jab tak cab->getNumber == csv file number if equal then print avg 
                if (Sedan *sedan = dynamic_cast<Sedan *>(cab))
                {
                    cout << "Cab Type: Sedan\nSeats: " << sedan->getSeats() << "\nFare per KM: " << sedan->getFare() << endl;
                    int cabNumb = cab->getCabNumber();
                    cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                }
                else if (Intercity *intercity = dynamic_cast<Intercity *>(cab))
                {
                    cout << "Cab Type: Intercity \nSeats: " << intercity->getSeats() << "\nFare per KM: " << intercity->getFare() << endl;
                    int cabNumb = cab->getCabNumber();
                    cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                }
                else if (SUV *suv = dynamic_cast<SUV *>(cab))
                {
                    cout << "Cab Type: SUV" << endl << "Seats: " << suv->getSeats() << "\nFare per KM: " << suv->getFare() << endl;
                    int cabNumb = cab->getCabNumber();
                    cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                }
                cout << "------------------------------------------------------------------------------" << endl;
                check = 0;
            }
        }

        if (check == 1)
        {
            cout << "NO cabs available right now at your location, \nWe are sending nearbly cab to you wait for " << rand() % 10 + 1 << " Minutes!!" << endl;
            allCabs.push_back(new Intercity(535451, "Rahul Kumar", userLocation, 1));

            for (Cab *cab : allCabs)
            {
                if (cab->getLocation() == userLocation && cab->getAvailability())
                {
                    cabCounter++;
                    // cout<<"Cab Option : "<< cabCounter <<") ->"<<endl;
                    cab->displayCab();
                    // cab->getNumber agar equal hua toh print avg
                    if (Sedan *sedan = dynamic_cast<Sedan *>(cab))
                    {
                        cout << "Cab Type: Sedan\nSeats: " << sedan->getSeats() << "\nFare per KM: " << sedan->getFare() << endl;
                        int cabNumb = cab->getCabNumber();
                        cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                    }
                    else if (Intercity *intercity = dynamic_cast<Intercity *>(cab))
                    {
                        cout << "Cab Type: Intercity \nSeats: " << intercity->getSeats() << "\nFare per KM: " << intercity->getFare() << endl;
                        int cabNumb = cab->getCabNumber();
                        cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                        
                    }
                    else if (SUV *suv = dynamic_cast<SUV *>(cab))
                    {
                        cout << "Cab Type: SUV" << endl << "Seats: " << suv->getSeats() << "\nFare per KM: " << suv->getFare() << endl;
                        int cabNumb = cab->getCabNumber();
                        cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                        
                    }
                    cout << "------------------------------------------------------------------------------" << endl;
                    check = 0;
                }
            }
            cout << "Select a cab (Enter Cab Number) : ";
            int cabNum = 0;
            fare = 0;
            people = 0;
            maxPerson = 0;
            cin >> cabNum;
            cout << "------------------------------------------------------------------------------" << endl;
            cout << "Selected Cab is : " << endl;

            for (Cab *cab : allCabs)
            {
                if (cab->getCabNumber() == cabNum && cab->getAvailability())
                {
                    cab->displayCab();
                    if (Sedan *sedan = dynamic_cast<Sedan *>(cab))
                    {
                        fare = sedan->getFare();
                        maxPerson = sedan->getSeats();
                        cout << "Cab Type: Sedan\nSeats: " << sedan->getSeats() << "\nFare per KM: " << sedan->getFare() << endl;
                        int cabNumb = cab->getCabNumber();
                        cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                        
                    }
                    else if (Intercity *intercity = dynamic_cast<Intercity *>(cab))
                    {
                        fare = intercity->getFare();
                        maxPerson = intercity->getSeats();
                        cout << "Cab Type: Intercity \nSeats: " << intercity->getSeats() << "\nFare per KM: " << intercity->getFare() << endl;
                        int cabNumb = cab->getCabNumber();
                        cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                        
                    }
                    else if (SUV *suv = dynamic_cast<SUV *>(cab))
                    {
                        fare = suv->getFare();
                        maxPerson = suv->getSeats();
                        cout << "Cab Type: SUV" << endl << "Seats: " << suv->getSeats() << "\nFare per KM: " << suv->getFare() << endl;
                        int cabNumb = cab->getCabNumber();
                        cout<<"Ratings : "<<ratingSystem.getAverageCabRating(cabNumb, "cab_ratings.csv")<< endl;
                        
                    }
                    cout << "------------------------------------------------------------------------------" << endl;
                    check = 0;
                }
            }

            cout << "Enter the destination location : ";
            string destinationLocation;
            cin.ignore();
            getline(cin, destinationLocation);
            cout << "------------------------------------------------------------------------------" << endl;
            // enter the destination location
            int dist = g.printShortestPath(userLocation, destinationLocation);
            cout << "The total distance is : " << dist << endl;
            // put the source and destination location in the shortest path finder
            // enter the number of persons
            while(1){
            cout << "Enter the number of persons : ";
            cin >> people;
            cout << "------------------------------------------------------------------------------" << endl;
            if(people <= maxPerson)
            {
                break;
            }
            cout<< "The maximum capacity is : " <<maxPerson<< " Please select accordingly!"<<endl;
            }
            // generate the details of the bill

            for (Cab *cab : allCabs)
            {
                if (cab->getCabNumber() == cabNum && cab->getAvailability())
                {
                    cab->displayForBilling();
                    if (Sedan *sedan = dynamic_cast<Sedan *>(cab))
                    {
                        fare = sedan->getFare();
                        cout << "Cab Type: Sedan " << endl;
                    }
                    else if (Intercity *intercity = dynamic_cast<Intercity *>(cab))
                    {
                        fare = intercity->getFare();
                        cout << "Cab Type: Intercity " << endl;
                    }
                    else if (SUV *suv = dynamic_cast<SUV *>(cab))
                    {
                        fare = suv->getFare();
                        cout << "Cab Type: SUV " << endl;
                    }
                }
            }
            amount = fare * dist;
            amountPerPerson = (fare * dist)/ people ;
            cout << "Total Amount: " << amount << endl;
            cout << "Amount per person: " << amountPerPerson << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            CabRatingSystem ratingSystem;
            int userRating;
            cout << "Kindly evaluate your experience: Choose 1 for less satisfactory, 5 for highly satisfactory" <<endl;
            cin>>userRating;
            ratingSystem.loadRatingsFromCSV("cab_ratings.csv");
            ratingSystem.addRating(cabNum,userRating);
            ratingSystem.saveRatingsToCSV("cab_ratings.csv");

        }
        else
        {
            cout << "Select a cab : ";
            int cabNum = 0;
            fare = 0;
            people = 0;
            maxPerson = 0;
            cin >> cabNum;
            cout << "------------------------------------------------------------------------------" << endl;
            cout << "Selected Cab is : " << endl;

            for (Cab *cab : allCabs)
            {
                if (cab->getCabNumber() == cabNum && cab->getAvailability())
                {
                    cab->displayCab();
                    if (Sedan *sedan = dynamic_cast<Sedan *>(cab))
                    {
                        fare = sedan->getFare();
                        maxPerson = sedan->getSeats();
                        cout << "Cab Type: Sedan\nSeats: " << sedan->getSeats() << "\nFare per KM: " << sedan->getFare() << endl;
                    }
                    else if (Intercity *intercity = dynamic_cast<Intercity *>(cab))
                    {
                        fare = intercity->getFare();
                        maxPerson = intercity->getSeats();
                        cout << "Cab Type: Intercity \nSeats: " << intercity->getSeats() << "\nFare per KM: " << intercity->getFare() << endl;
                    }
                    else if (SUV *suv = dynamic_cast<SUV *>(cab))
                    {
                        fare = suv->getFare();
                        maxPerson = suv->getSeats();
                        cout << "Cab Type: SUV" << endl << "Seats: " << suv->getSeats() << "\nFare per KM: " << suv->getFare() << endl;
                    }
                    cout << "------------------------------------------------------------------------------" << endl;
                    check = 0;
                }
            }

            cout << "Enter the destination location : ";
            string destinationLocation;
            cin.ignore();
            getline(cin, destinationLocation);
            cout << "------------------------------------------------------------------------------" << endl;
            // enter the destination location
            dist = g.printShortestPath(userLocation, destinationLocation);
            cout << "The total distance is : " << dist << endl;
            // put the source and destination location in the shortest path finder
            // enter the number of persons
            while(1){
            cout << "Enter the number of persons : ";
            cin >> people;
            cout << "------------------------------------------------------------------------------" << endl;
            if(people <= maxPerson)
            {
                break;
            }
            cout<< "The maximum capacity is : " <<maxPerson<< " Please select accordingly!"<<endl;
            }
            // generate the details of the bill

            for (Cab *cab : allCabs)
            {
                if (cab->getCabNumber() == cabNum && cab->getAvailability())
                {
                    cab->displayForBilling();
                    if (Sedan *sedan = dynamic_cast<Sedan *>(cab))
                    {
                        fare = sedan->getFare();
                        cout << "Cab Type: Sedan " << endl;
                    }
                    else if (Intercity *intercity = dynamic_cast<Intercity *>(cab))
                    {
                        fare = intercity->getFare();
                        cout << "Cab Type: Intercity " << endl;
                    }
                    else if (SUV *suv = dynamic_cast<SUV *>(cab))
                    {
                        fare = suv->getFare();
                        cout << "Cab Type: SUV " << endl;
                    }
                    // cout << "------------------------------------------------------------------------------" << endl;
                }
            }
            
            amount = fare * dist;
            amountPass = amount;
            amountPerPerson = (fare * dist)/ people ;
            peoplePass = people;
            cout << "Total Amount: " << amount << endl;
            cout << "Amount per person: " << amountPerPerson << endl;
            cout << "------------------------------------------------------------------------------" << endl;
            int userRating;
            cout << "Kindly evaluate your experience: Choose 1 for less satisfactory, 5 for highly satisfactory" <<endl;
            cin>>userRating;
            ratingSystem.loadRatingsFromCSV("cab_ratings.csv");
            ratingSystem.addRating(cabNum,userRating);
            ratingSystem.saveRatingsToCSV("cab_ratings.csv");
        }
        
    }

    float getAmount(){
        return amount;
    }

    float getPeople(){
        return people;
    }
};