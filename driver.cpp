#include <bits/stdc++.h>

using namespace std;

class CabRating {
private:
    int cabNumber;
    vector<double> ratings;

public:
    CabRating(int number, double cabRating) : cabNumber(number) {
        ratings.push_back(cabRating);
    }

    int getCabNumber() const {
        return cabNumber;
    }

    const vector<double>& getRatings() const {
        return ratings;
    }

    void addRating(double rating) {
        ratings.push_back(rating);
        sort(ratings.begin(), ratings.end());  // Sort the ratings
    }

    double getAverageRating() const {
        if (ratings.empty()) {
            return 0.0;  
        }

        double sum = 0.0;
        for (double rating : ratings) {
            sum += rating;
        }

        return sum / ratings.size();
    }
};

class CabRatingSystem {
private:
    vector<CabRating> cabRatings;

public:
    void loadRatingsFromCSV(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            int cabNumber;
            double rating;

            if (iss >> cabNumber) {
                while (iss >> rating) {
                    addRating(cabNumber, rating);
                }
            }
        }

        file.close();
    }

    void addRating(int cabNumber, double rating) {
        for (auto& cabRating : cabRatings) {
            if (cabRating.getCabNumber() == cabNumber) {
                cabRating.addRating(rating);
                return;
            }
        }

        cabRatings.emplace_back(cabNumber, rating);
    }

    void saveRatingsToCSV(const string& filename) {
        ofstream file(filename);

        // Write headers
        file << "CabNumber";
        for (size_t i = 1; i <= 5; ++i) {
            file << " Rating " << i;
        }
        file << " Average\n";

        for (const auto& cabRating : cabRatings) {
            file << cabRating.getCabNumber();

            for (double rating : cabRating.getRatings()) {
                file << " " << rating;
            }

            file << " " << fixed << setprecision(2) << cabRating.getAverageRating() << "\n";
        }

        file.close();
    }

            // Function to get average cab rating for a given cab number
            double getAverageCabRating(int cabNumber, const string& filename) {
                ifstream file(filename);
                if (!file.is_open()) {
                    cerr << "Error opening file: " << filename << endl;
                    return -1.0;  // Error code
                }

                string line;
                unordered_map<int, double> cabRatings;  // To store cab ratings based on cab number

                // Read each line from the file
                while (getline(file, line)) {
                    istringstream iss(line);
                    int currentCabNumber;
                    double rating;

                    // Read cab number and ratings from the line
                    iss >> currentCabNumber;

                    while (iss >> rating) {
                        cabRatings[currentCabNumber] = rating;
                    }
                }

                // Close the file
                file.close();

                // Check if the given cab number exists in the map
                auto it = cabRatings.find(cabNumber);
                if (it != cabRatings.end()) {
                    return it->second;  // Return the average cab rating
                } else {
                    cerr << "Cab number not found: " << cabNumber << endl;
                    return -1.0;  // Error code
                }
            }

};