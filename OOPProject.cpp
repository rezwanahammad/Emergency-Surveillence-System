#include <iostream>
#include<fstream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold location-specific details
struct LocationDetails
{
    string name;
    string locationName;
    string dialer;
    string phoneNumber;
    string email;
    string equipment;
};

// Base class for emergency services
class EmergencyService
{
protected:
    int type;
    int location;

public:
    EmergencyService(int type, int location) {}

    //template function to show details
    template <typename Location>
    void showDetails(const Location& loc)
    {
        cout << "\t\t " << loc.name << " is available at " << loc.locationName << ".\n";
        cout << "\t\t Name: " << loc.name << endl;
        cout << "\t\t Keypad dialer: " << loc.dialer << endl;
        cout << "\t\t Cell phone: " << loc.phoneNumber << endl;
        cout << "\t\t Email: " << loc.email << endl;
        cout << "\t\t Equipment available: " << loc.equipment << "\n\n";
    }
};
// Class to store user information
class User
{
private:
    string username;
    string password;
    string email;

public:
    User(string username, string password, string email)
        : username(username), password(password), email(email) {}

    string getUsername() const
    {
        return username;
    }

    string getPassword() const
    {
        return password;
    }

    string getEmail() const
    {
        return email;
    }
};

// Class to store feedback information
class Feedback
{
private:
    string username;
    string serviceType;
    string feedbackText;

public:
    Feedback(string username, string serviceType, string feedbackText)
        : username(username), serviceType(serviceType), feedbackText(feedbackText) {}

    string getUsername() const
    {
        return username;
    }

    string getServiceType() const
    {
        return serviceType;
    }

    string getFeedbackText() const
    {
        return feedbackText;
    }

    // Friend functions to save and load feedbacks from file
    friend void saveFeedbacksToFile(const vector<Feedback>& feedbacks);
    friend void loadFeedbacksFromFile(vector<Feedback>& feedbacks);

    void displayFeedback() const
    {
        cout << "User: " << username << endl;
        cout << "Service Type: " << serviceType << endl;
        cout << "Feedback: " << feedbackText << endl << endl;
    }
};

vector<User> users; // Vector to store instances of User
vector<Feedback> feedbacks; // Vector to store instances of Feedback

// Function to register a user
void registerUser()
{
    string username, password, email;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter email: ";
    cin >> email;

    users.push_back(User(username, password, email));
    cout << "Registration successful!" << endl;
}

// Function to authenticate a user
void loginUser()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    for (const auto& user : users)
    {
        if (user.getUsername() == username && user.getPassword() == password)
        {
            cout << "Welcome, " << username << "!" << endl;
            return;
        }
    }

    cout << "Invalid username or password. Please try again." << endl;
}

// Function to leave feedback
void leaveFeedback()
{
    string username, serviceType, feedbackText;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter the service type (Ambulance, Firetruck, Police, or Rescue Platoon): ";
    cin >> serviceType;
    cout << "Enter your feedback: ";
    cin.ignore();
    getline(cin, feedbackText);

    feedbacks.push_back(Feedback(username, serviceType, feedbackText));
    cout << "Thank you for your feedback!" << endl;
}

// Function to display feedbacks
void displayFeedbacks()
{
    cout << "Feedbacks:" << endl;
    for (const auto& feedback : feedbacks)
    {
        feedback.displayFeedback();
    }
}

// Functions to save and load data to/from files
void saveUsersToFile(const vector<User>& users)
{
    ofstream file("users.txt");
    if (file.is_open())
    {
        for (const auto& user : users)
        {
            file << user.getUsername() << " " << user.getPassword() << " " << user.getEmail() << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file for writing." << endl;
    }
}

void loadUsersFromFile(vector<User>& users)
{
    ifstream file("users.txt");
    if (file.is_open())
    {
        string username, password, email;
        while (file >> username >> password >> email)
        {
            users.push_back(User(username, password, email));
        }
        file.close();
    }
    else
    {
        cout << "No previous user data found." << endl;
    }
}

void saveFeedbacksToFile(const vector<Feedback>& feedbacks)
{
    ofstream file("feedbacks.txt");
    if (file.is_open())
    {
        for (const auto& feedback : feedbacks)
        {
            file << feedback.getUsername() << " " << feedback.getServiceType() << " " << feedback.getFeedbackText() << endl;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file for writing." << endl;
    }
}

void loadFeedbacksFromFile(vector<Feedback>& feedbacks)
{
    ifstream file("feedbacks.txt");
    if (file.is_open())
    {
        string username, serviceType, feedbackText;
        while (file >> username >> serviceType)
        {
            getline(file, feedbackText);
            feedbacks.push_back(Feedback(username, serviceType, feedbackText));
        }
        file.close();
    }
    else
    {
        cout << "No previous feedback data found." << endl;
    }
}

int main()
{
    int mirpur = 1, uttara = 2, gulshan = 3;
    int choice;
    int locationChoice;  // Added variable to store location choice

    // Load existing user and feedback data from files
    loadUsersFromFile(users);
    loadFeedbacksFromFile(feedbacks);

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Ambulance" << endl;
        cout << "2. Firetruck" << endl;
        cout << "3. Police" << endl;
        cout << "4. Rescue Platoon" << endl;
        cout << "5. Register User" << endl;
        cout << "6. Login" << endl;
        cout << "7. Enter Feedback" << endl;
        cout << "8. View Feedbacks" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            {
                cout << "Choose your location (1 for Mirpur, 2 for Uttara, 3 for Gulshan): ";
                cin >> locationChoice;

                if (locationChoice < 1 || locationChoice > 3)
                {
                    cout << "Invalid location choice. Please try again." << endl;
                    continue;
                }

                LocationDetails details;

                if (choice == 1)
                {
                    if (locationChoice == mirpur)
                    {
                        details = { "Desh Ambulance Service", "Mirpur", "999", "01723890065", "deshambulance@gmail.com", "First aid kit, Oxygen cylinder, Bandages, Sedatives" };
                    }
                    else if (locationChoice == uttara)
                    {
                        details = { "Shadhin Ambulance Assistance", "Uttara", "998", "01723890066", "shadhinambulance@gmail.com", "First aid kit, Bandages, Oxygen cylinder, Sedatives" };
                    }
                    else if (locationChoice == gulshan)
                    {
                        details = { "Tesla Rapid Response", "Gulshan", "987", "01723890067", "teslarapidresponse@gmail.com", "First aid kit, Scissors, Bandages, Oxygen cylinder, Sedatives" };
                    }
                }
                else if (choice == 2)
                {
                    if (locationChoice == mirpur)
                    {
                        details = { "Desco Fire Squad", "Mirpur", "201", "01723890068", "descofiresquad@gmail.com", "Ladders, Fire hoses, Foam, Nozzles, Extinguisher" };
                    }
                    else if (locationChoice == uttara)
                    {
                        details = { "TTT Fire Brigade", "Uttara", "202", "01723890069", "tttfirebrigade@gmail.com", "Ladders, Fire hoses, Foam, Nozzles, Extinguisher" };
                    }
                    else if (locationChoice == gulshan)
                    {
                        details = { "Delta Fire Force", "Gulshan", "203", "01723890060", "deltafireforce@gmail.com", "Ladders, Fire hoses, Foam, Nozzles, Extinguisher" };
                    }
                }
                else if (choice == 3)
                {
                    if (locationChoice == mirpur)
                    {
                        details = { "Police officer", "Mirpur", "901", "01723890061", "policelocation1@gmail.com", "" };
                    }
                    else if (locationChoice == uttara)
                    {
                        details = { "Police officer", "Uttara", "902", "01723890062", "policelocation2@gmail.com", "" };
                    }
                    else if (locationChoice == gulshan)
                    {
                        details = { "Police officer", "Gulshan", "903", "01723890063", "policeGulshan@gmail.com", "" };
                    }
                }
                else if (choice == 4)
                {
                    if (locationChoice == mirpur)
                    {
                        details = { "Rescue platoon", "Mirpur", "401", "01723890064", "rescueplatoonmirpur@gmail.com", "" };
                    }
                    else if (locationChoice == uttara)
                    {
                        details = { "Rescue platoon", "Uttara", "402", "01723890096", "rescueplatoonuttara@gmail.com", "" };
                    }
                    else if (locationChoice == gulshan)
                    {
                        details = { "Rescue platoon", "Gulshan", "403", "01723890065", "rescueplatoonGulshan@gmail.com", "" };
                    }
                }

                EmergencyService service(choice, locationChoice);
                service.showDetails(details);
                break;
            }
        case 5:
            registerUser();
            break;
        case 6:
            loginUser();
            break;
        case 7:
            leaveFeedback();
            break;
        case 8:
            displayFeedbacks();
            break;
        case 9:
            // Save user and feedback data before exiting
            saveUsersToFile(users);
            saveFeedbacksToFile(feedbacks);
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (choice != 9);

    return 0;
}
