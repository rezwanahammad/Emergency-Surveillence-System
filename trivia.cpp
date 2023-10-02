

//EMERGENCY SERVICE MANAGEMENT SYSTEM
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
using namespace std;
// Base class for emergency services
class EmergencyService
{
protected:
    int type;
    int location;
public:
    EmergencyService(int type, int location) {}
    // Pure virtual functions for different locations
    virtual void showDetailsMirpur()=0;
    virtual void showDetailsUttara()=0;
    virtual void showDetailsGulshan()=0;
};

// Derived class for the details of  Ambulance service

class Ambulance : public EmergencyService
{
public:
    Ambulance(int type, int location): EmergencyService(type, location) {}

    void showDetailsMirpur()
    {
        cout << "\t\t Ambulance is available at Mirpur.\n \t\t Name: Desh Ambulance Service " << endl;
        cout << "\t\t Keypad dialer: 999" << endl;
        cout << "\t\t Cell phone: 01723890065" << endl;
        cout << "\t\t Email: deshambulance@gmail.com" << endl;
        cout << "\t\t Equipment available: First aid kit, Oxygen cylinder, Bandages, Sedatives.\n\n" << endl;
    }

    void showDetailsUttara()
    {
        cout << "\t\t Ambulance is  available at Uttara.\n\t\t Name: Shadhin Ambulance Assistance" << endl;
        cout << "\t\t Keypad dialer: 998" << endl;
        cout << "\t\t Cell phone: 01723890066" << endl;
        cout << "\t\t Email: shadhinambulance@gmail.com" << endl;
        cout << "\t\t Equipment available: First aid kit, Bandages, Oxygen cylinder, Sedatives.\n\n" << endl;
    }

    void showDetailsGulshan()
    {
        cout << "\t\t Ambulance is available at Gulshan.\n \t\t Name: Tesla Rapid Response " << endl;
        cout << "\t\t Keypad dialer: 987" << endl;
        cout << "\t\t Cell phone: 01723890067" << endl;
        cout << "\t\t Email: teslarapidresponse@gmail.com" << endl;
        cout << "\t\t Equipment available: First aid kit, Scissors, Bandages, Oxygen cylinder, Sedatives.\n\n" << endl;
    }
};

// Derived class for the details of  Fireservice
class Firetruck : public EmergencyService
{
public:
    Firetruck(int type, int location): EmergencyService(type, location) {}

    void showDetailsMirpur()
    {
        cout << "\t\t Firetruck is available at Mirpur.\n\t\t Name: Desco Fire Squad " << endl;
        cout << "\t\t Keypad dialer: 201" << endl;
        cout << "\t\t Cell phone: 01723890068" << endl;
        cout << "\t\t Email: descofiresquad@gmail.com" << endl;
        cout << "\t\t Equipment available: Ladders, Fire hoses, Foam, Nozzles, Extinguisher" << endl;
        cout << "\t\t Water tank capacity: 5000L\n\n" << endl;
    }

    void showDetailsUttara()
    {
        cout << "\t\t Firetruck is available at Uttara.\n\t\t Name: TTT Fire Brigade" << endl;
        cout << "\t\t Keypad dialer: 202" << endl;
        cout << "\t\t Cell phone: 01723890069" << endl;
        cout << "\t\t Email: tttfirebrigade@gmail.com" << endl;
        cout << "\t\t Equipment available: Ladders, Fire hoses, Foam, Nozzles, Extinguisher" << endl;
        cout << "\t\t Water tank capacity: 6000L\n\n" << endl;
    }

    void showDetailsGulshan()
    {
        cout << "\t\t Firetruck is available at Gulshan.\n\t\t Name: Delta Fire Force " << endl;
        cout << "\t\t Keypad dialler: 203" << endl;
        cout << "\t\t Cell phone: 01723890060" << endl;
        cout << "\t\t Email: deltafireforce@gmail.com" << endl;
        cout << "\t\t Equipment available: Ladders, Fire hoses, Foam, Nozzles, Extinguisher" << endl;
        cout << "\t\t Water tank capacity: 7000L\n\n" << endl;
    }
};

// Derived class for the details of  nearby police stations
class Police : public EmergencyService
{
public:
    Police(int type, int location): EmergencyService(type, location) {}

    void showDetailsMirpur()
    {
        cout << "\t\t Police officer is available at Mirpur." << endl;
        cout << "\t\t Keypad dialler: 901" << endl;
        cout << "\t\t Cell phone: 01723890061" << endl;
        cout << "\t\t Email: policelocation1@gmail.com" << endl;
        cout << "\n\n" << endl;
    }

    void showDetailsUttara()
    {
        cout << "\t\t Police officer is available at Uttara." << endl;
        cout << "\t\t Keypad dialler: 902" << endl;
        cout << "\t\t Cell phone: 01723890062" << endl;
        cout << "\t\t Email: policelocation2@gmail.com" << endl;
        cout << "\n\n" << endl;
    }

    void showDetailsGulshan()
    {
        cout << "\t\t Police officer is available at Gulshan." << endl;
        cout << "\t\t Keypad dialer: 903" << endl;
        cout << "\t\t Cell phone: 01723890063" << endl;
        cout << "\t\t Email: policeGulshan@gmail.com" << endl;
        cout << "\n\n" << endl;
    }
};
// Derived class for the details of  Rescueplatoon

class RescuePlatoon : public EmergencyService
{
public:
    RescuePlatoon(int type, int location): EmergencyService(type, location) {}

    void showDetailsMirpur()
    {
        cout << "\t\t Rescue platoon is available at Mirpur." << endl;
        cout << "\t\t Keypad dialer: 401" << endl;
        cout << "\t\t Cell phone: 01723890064" << endl;
        cout << "\t\t Email: rescueplatoonmirpur@gmail.com" << endl;
        cout << "\n\n" << endl;
    }

    void showDetailsUttara()
    {
        cout << "\t\t Rescue platoon is available at Uttara." << endl;
        cout << "\t\t Keypad dialer: 402" << endl;
        cout << "\t\t Cell phone: 01723890096" << endl;
        cout << "\t\t Email: rescueplatoonuttara@gmail.com" << endl;
        cout << "\n\n" << endl;
    }

    void showDetailsGulshan()
    {
        cout << "\t\t Rescue platoon is available at Gulshan." << endl;
        cout << "\t\t Keypad dialer: 403" << endl;
        cout << "\t\t Cell phone: 01723890065" << endl;
        cout << "\t\t Email: rescueplatoonGulshan@gmail.com" << endl;
        cout << "\n\n" << endl;
    }
};
//Use of Operator Overloading
class Overload
{
public:
    //Overloaded << operator to display text
    void operator<< (string line)
    {
        cout << line << endl;
    }

    // Display instructions for choosing location
    void memfunc()
    {
        Overload over;
        over << "Enter your location:\tPress 1 for Mirpur";
        over << "\t\t\tPress 2 for Uttara";
        over << "\t\t\tPress 3 for Gulshan";
    }
};

// Display advice based on the chosen service type

inline void advice(int a)
{
    if(a==1)
    {
        cout << "You can call Ambulance through the info provided below:" << endl;
    }
    if(a==2)
    {
        cout << "You can call Fire Service through the info provided below:" << endl;
    }
    if(a==3)
    {
        cout << "You can call Police through the info provided below:" << endl;
    }
    if(a==4)
    {
        cout << "You can call Rescue Platoon through the info provided below:" << endl;
    }
}

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
    vector<EmergencyService*> services; // Vector to store instances of EmergencyService
    Overload over;
    int mirpur = 1,uttara = 2,gulshan = 3;
    int choice;
    // Load existing user and feedback data from files
    loadUsersFromFile(users);
    loadFeedbacksFromFile(feedbacks);
    do
    {
        // Display menu options
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
        // Handle different user choices (1-9)
        switch (choice)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        {
            over.memfunc();
            int location;
            cin >> location;
            EmergencyService* service = nullptr;

            if (choice == 1)
                service = new Ambulance(choice, location);
            else if (choice == 2)
                service = new Firetruck(choice, location);
            else if (choice == 3)
                service = new Police(choice, location);
            else if (choice == 4)
                service = new RescuePlatoon(choice, location);

            if (service)
            {
                services.push_back(service);

                if ((location == mirpur) || (location == uttara) || (location == gulshan))
                    advice(choice);

                for (auto service : services)
                {
                    if (location == mirpur)
                        service->showDetailsMirpur();
                    else if (location == uttara)
                        service->showDetailsUttara();
                    else if (location == gulshan)
                        service->showDetailsGulshan();
                    else
                        cout << "Enter only 1/2/3 for your location. Try again" << endl;
                }

                // Clean up the dynamically allocated memory
                for (auto service : services)
                {
                    delete service;
                }

                services.clear();  // Clear the vector for the next iteration
            }

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
    }
    while (choice != 9);

    return 0;
}
