#include <iostream>
#include <fstream>
using namespace std;

int z = 0;
int e = 0;

void mainmenu();
class trainregistration;

class Management
{
public:
    Management()
    {
        mainmenu();
    }
};

class Details
{
public:
    static int nextcustomerid;
    static string name, gender;
    long long phoneNumber;
    int age;
    string add;     // adress
    int customerid; // customer id.
    char arr[100];

    Details() : customerid(nextcustomerid++) {}
    void inputinformation()
    {
        // cout<<"Enter the customer ID :";
        // cin>>customerid;

        cout << "Enter your name : ";
        cin.ignore(25, '\n');
        getline(cin, name);

        cout << "Enter your Adress : ";
        getline(cin, add);

        bool validNumber = false;
        while (!validNumber)
        {
            cout << "Enter your contact number (10 digits): ";
            cin >> phoneNumber;
            if (to_string(phoneNumber).length() == 10)
            {
                validNumber = true;
            }
            else
            {
                cout << "Invalid phone number. Please enter a 10-digit number." << endl;
            }
        }
        cout << "Your Gender (Male / Female): ";
        cin >> gender;
        cout << endl;
        cout << "Your details are saved with us ." << endl;
        z++;
    }

    void displayInformation()
    {
        cout << "Customer ID: " << customerid << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << add << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Gender: " << gender << endl;
    }
};

class payment
{
private:
    long long cardNumber; // Changed to long long for 16-digit card numbers
    string expiryDate;
    int cvv;
    int bank;
    int userId;
    string password;

public:
    void processPayment()
    {
        cout << "\nHow would you like to pay?\n";
        cout << "1. Debit Card\n";
        cout << "2. Credit Card\n";
        cout << "3. Net Banking\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            payWithDebitCard();
            break;
        case 2:
            payWithCreditCard();
            break;
        case 3:
            payWithNetBanking();
            break;
        default:
            cout << "\nInvalid choice. Please try again.\n";
            break;
        }
    }

private:
    void payWithDebitCard()
    {
        while (true)
        {
            cout << "Enter card number: ";
            cin >> cardNumber;
            if (!isValidCardNumber(cardNumber))
            {
                cout << "Invalid card number. Please enter a 16-digit number.\n";
            }
            else
            {
                break;
            }
        }

        cout << "Enter expiry date (DD/MM): ";
        cin >> expiryDate;
        while (!isValidExpiryDate(expiryDate))
        {
            cout << "Invalid expiry date format. Please enter in DD/MM format.\n";
            cout << "Enter expiry date (DD/MM): ";
            cin >> expiryDate;
        }

        while (true)
        {
            cout << "Enter CVV: ";
            cin >> cvv;
            if (!isValidCVV(cvv))
            {
                cout << "Invalid CVV. Please enter a 3-digit number.\n";
            }
            else
            {
                break;
            }
        }

        cout << "\nTransaction Successful.\n";
    }

    void payWithCreditCard()
    {
        while (true)
        {
            cout << "Enter card number: ";
            cin >> cardNumber;
            if (!isValidCardNumber(cardNumber))
            {
                cout << "Invalid card number. Please enter a 16-digit number.\n";
            }
            else
            {
                break;
            }
        }

        cout << "Enter expiry date (DD/MM): ";
        cin >> expiryDate;
        while (!isValidExpiryDate(expiryDate))
        {
            cout << "Invalid expiry date format. Please enter in DD/MM format.\n";
            cout << "Enter expiry date (DD/MM): ";
            cin >> expiryDate;
        }

        cout << "Enter password: ";
        cin >> password;
        // Additional validation for password
        cout << "\nTransaction Successful.\n";
    }

    void payWithNetBanking()
    {
        cout << "Banks Available: \n";
        cout << "1. Bank Alfalah\n";
        cout << "2. Meezan Bank\n";
        cout << "3. Punjab Bank\n";
        cout << "4. Allied Bank\n";
        cout << "5. Others\n";
        cout << "Select your bank: ";
        cin >> bank;
        cout << "Enter user ID: ";
        cin >> userId;
        cout << "Enter password: ";
        cin >> password;
        cout << "\nTransaction Successful.\n";
    }

    bool isValidCardNumber(long long number)
    {
        return to_string(number).length() == 16;
    }

    bool isValidExpiryDate(const string &date)
    {
        if (date.length() != 5) // Check if the length is not 5 characters
            return false;

        if (date[2] != '/') // Check if the third character is '/'
            return false;

        for (int i = 0; i < 5; ++i)
        {
            if (i != 2 && !isdigit(date[i])) // Check if all characters are digits except '/'
                return false;
        }

        return true;
    }

    bool isValidCVV(int cvv)
    {
        return cvv >= 100 && cvv <= 999;
    }
};

int Details::nextcustomerid = 1;
string Details::name;
string Details::gender;

class registration : public payment
{
public:
    static int choice;
    int choice1;
    int back;
    static float charges;

    void flights()
    {
        string flightN[] = {"Dubai", "Canada", "Uk", "USA", "Australia", "Europe"};
        for (int i = 0; i < 6; i++)
        {
            cout << (i + 1) << ". Flight to " << flightN[i] << endl; // increment in the countries one by one .
        }
        cout << endl;
        cout << "Welcome to the Pakistan Airlines!" << endl;
        cout << "Press the number of the country of wich you want to book flight :";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("CLS");
            cout << "_____________________Welcome to Emirates_________________________________" << endl;
            cout << "Your comfort is our priority , Enjoy the Journey !" << endl;
            cout << endl;
            cout << "\t \t \tFlights Found" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.DUB - 498(1)\t08:00\t\t11:05\t\tRs.50000\tRefundable\n";
            cout << "\2.DUB - 658(2)\t14:00\t\t17:05\t\tRs.55000\tRefundable\n";
            cout << "\3.DUB - 508(3)\t19:00\t\t22:05\t\tRs.60000\tRefundable\n";
            cout << endl;
            cout << "Select the flight you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 50000;
                cout << "Ticket Confirmed : DUB - 498" << endl;
                cout << "Departure Time: 08:00" << endl;
                cout << "Arrival Time: 11:05" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 55000;
                cout << "Ticket Confirmed : DUB - 658" << endl;
                cout << "Departure Time: 14:00" << endl;
                cout << "Arrival Time: 17:05" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 60000;
                cout << "Ticket Confirmed : DUB - 508" << endl;
                cout << "Departure Time : 19:00" << endl;
                cout << "Arrival Time: 22:05" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                flights();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }

        case 2:
        {
            system("CLS");
            cout << "_____________________Welcome to Air Canada_________________________________" << endl;
            cout << "Your comfort is our priority , Enjoy the Journey !" << endl;
            cout << endl;
            cout << "\t \t \tFlights Found" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.CA - 198 (1)\t08:00\t\t11:05\t\tRs.50000\tRefundable\n";
            cout << "\2.CA - 158(2)\t14:00\t\t17:05\t\tRs.55000\tRefundable\n";
            cout << "\3.CA - 208(3)\t19:00\t\t22:05\t\tRs.60000\tRefundable\n";
            cout << endl;
            cout << "Select the flight you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 50000;
                cout << "Ticket Confirmed : CA - 198" << endl;
                cout << "Departure Time: 08:00" << endl;
                cout << "Arrival Time: 11:05" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 55000;
                cout << "Ticket Confirmed : CA - 158" << endl;
                cout << "Departure Time: 14:00" << endl;
                cout << "Arrival Time: 17:05" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 60000;
                cout << "Ticket Confirmed : CA - 208" << endl;
                cout << "Departure Time : 19:00" << endl;
                cout << "Arrival Time: 22:05" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                flights();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }

        case 3:
        {
            system("CLS");
            cout << "_____________________Welcome to British Airways_________________________________" << endl;
            cout << "Your comfort is our priority , Enjoy the Journey !" << endl;
            cout << endl;
            cout << "\t \t \tFlights Found" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.UK - 798 (1)\t08:00\t\t11:05\t\tRs.50000\tRefundable\n";
            cout << endl;
            cout << "Select the flight you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 50000;
                cout << "Ticket Confirmed : UK - 798" << endl;
                cout << "Departure Time: 08:00" << endl;
                cout << "Arrival Time: 11:05" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                flights();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }

        case 4:
        {
            system("CLS");
            cout << "_____________________Welcome to American Airline_________________________________" << endl;
            cout << "Your comfort is our priority , Enjoy the Journey !" << endl;
            cout << endl;
            cout << "\t \t \tFlights Found" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.US - 367 (1)\t08:00\t\t11:05\t\tRs.50000\tRefundable\n";
            cout << "\2.US - 458(2)\t14:00\t\t17:05\t\tRs.55000\tRefundable\n";
            cout << "\3.US - 508(3)\t19:00\t\t22:05\t\tRs.60000\tRefundable\n";
            cout << endl;
            cout << "Select the flight you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 50000;
                cout << "Ticket Confirmed : US - 367" << endl;
                cout << "Departure Time: 08:00" << endl;
                cout << "Arrival Time: 11:05" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 55000;
                cout << "Ticket Confirmed : US - 458" << endl;
                cout << "Departure Time: 14:00" << endl;
                cout << "Arrival Time: 17:05" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 60000;
                cout << "Ticket Confirmed : US - 508" << endl;
                cout << "Departure Time : 19:00" << endl;
                cout << "Arrival Time: 22:05" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                flights();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }
        case 5:
        {
            system("CLS");
            cout << "_____________________Welcome to Australian Airlines_________________________________" << endl;
            cout << "Your comfort is our priority , Enjoy the Journey !" << endl;
            cout << endl;
            cout << "\t \t \tFlights Found" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.AS - 176 (1)\t08:00\t\t11:05\t\tRs.50000\tRefundable\n";
            cout << "\2.AS - 134(2)\t14:00\t\t17:05\t\tRs.55000\tRefundable\n";
            cout << endl;
            cout << "Select the flight you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 50000;
                cout << "Ticket Confirmed : AS - 176" << endl;
                cout << "Departure Time: 08:00" << endl;
                cout << "Arrival Time: 11:05" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 55000;
                cout << "Ticket Confirmed : AS - 134" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                flights();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                mainmenu();
            }
            else
            {
                mainmenu();
            }
        }
        case 6:
        {
            system("CLS");
            cout << "_____________________Welcome to Air France_________________________________" << endl;
            cout << "Your comfort is our priority , Enjoy the Journey !" << endl;
            cout << endl;
            cout << "\t \t \tFlights Found" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "\1.EU - 898 (1)\t08:00\t\t11:05\t\tRs.50000\tRefundable\n";
            cout << "\2.EU - 798(2)\t14:00\t\t17:05\t\tRs.55000\tRefundable\n";
            cout << "\3.EU - 777(3)\t19:00\t\t22:05\t\tRs.60000\tRefundable\n";
            cout << endl;
            cout << "Select the flight you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 50000;
                cout << "Ticket Confirmed : EU - 898" << endl;
                cout << "Departure Time: 08:00" << endl;
                cout << "Arrival Time: 11:05" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 55000;
                cout << "Ticket Confirmed : EU - 798" << endl;
                cout << "Departure Time: 14:00" << endl;
                cout << "Arrival Time: 17:05" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 60000;
                cout << "Ticket Confirmed : EU - 777" << endl;
                cout << "Departure Time : 19:00" << endl;
                cout << "Arrival Time: 22:05" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                flights();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }
        default:
        {
            cout << "Invalid Input , shifting to the Main Menu !" << endl;
            mainmenu();
            break;
        }
        }
    }
};

float registration::charges;
int registration::choice;

class trainregistration : public payment
{
public:
    static int choice;
    int choice1;
    int back;
    static float charges;

    void trains()
    {
        string trainN[] = {"Multan", "Peshawar", "Rawalpindi", "Karachi", "Quetta", "Faisalabad"};
        for (int i = 0; i < 6; i++)
        {
            cout << (i + 1) << ". Train to " << trainN[i] << endl; // increment in the cities one by one .
        }
        cout << endl;
        cout << "Welcome to the Pakistan Railway!" << endl;
        cout << "Press the number of the City of wich you want to book train :";
        cin >> choice;

        cout << "_____________________Welcome to Pak Railway Lahore_________________________________" << endl;
        cout << "Your comfort is our priority , Enjoy the Journey !" << endl;

        switch (choice)
        {
        case 1:
        {
            system("CLS");

            cout << endl;
            cout << "\t \t \tTrains Found on way to Multan" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "2DN Khyber Mail\t07:35\t\t13:20";
            cout << "1.Economy (Seat)\t\tRs.1150\tRefundable\n";
            cout << "2.Economy (Birth)\t\tRs.1200\tRefundable\n";
            cout << "3.AC Business\t\tRs.3000\tRefundable\n";
            cout << endl;
            cout << "Select the seat you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 1150;
                cout << "Ticket Confirmed : 2DN Khyber Mail" << endl;
                cout << "Departure Time: 07:35" << endl;
                cout << "Arrival Time: 13:20" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 1200;
                cout << "Ticket Confirmed : 2DN Khyber Mail" << endl;
                cout << "Departure Time: 07:35" << endl;
                cout << "Arrival Time: 13:20" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 3000;
                cout << "Ticket Confirmed : 2DN Khyber Mail" << endl;
                cout << "Departure Time: 07:35" << endl;
                cout << "Arrival Time: 13:20" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                trains();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }

        case 2:
        {
            system("CLS");

            cout << endl;
            cout << "\t \t \tTrains Found on way to Peshawar" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "1UP Khyber Mail\t20:35\t\t05:14";
            cout << "1.Economy (Seat)\t\tRs.1350\tRefundable\n";
            cout << "2.Economy (Birth)\t\tRs.1400\tRefundable\n";
            cout << "3.AC Business\t\tRs.3400\tRefundable\n";
            cout << endl;
            cout << "Select the seat you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 1350;
                cout << "Ticket Confirmed : 1UP Khyber Mail" << endl;
                cout << "Departure Time: 20:35" << endl;
                cout << "Arrival Time: 05:14" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 1400;
                cout << "Ticket Confirmed : 1UP Khyber Mail" << endl;
                cout << "Departure Time: 20:35" << endl;
                cout << "Arrival Time: 05:14" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 3400;
                cout << "Ticket Confirmed : 1UP Khyber Mail" << endl;
                cout << "Departure Time: 20:35" << endl;
                cout << "Arrival Time: 05:14" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                trains();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }

        case 3:
        {
            system("CLS");

            cout << endl;
            cout << "\t \t \tTrains Found on way to Rawalpindi" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "107UP Islamabad Express\t18:00\t\t22:30";
            cout << "1.Economy (Seat)\t\tRs.950\tRefundable\n";
            cout << "2.Economy (Birth)\t\tRs.1550\tRefundable\n";
            cout << "3.AC Business\t\tRs.1750\tRefundable\n";
            cout << endl;
            cout << "Select the seat you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 950;
                cout << "Ticket Confirmed : 107UP Islamabad Express" << endl;
                cout << "Departure Time: 18:00" << endl;
                cout << "Arrival Time: 22:30" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 1550;
                cout << "Ticket Confirmed : 107UP Islamabad Express" << endl;
                cout << "Departure Time: 18:00" << endl;
                cout << "Arrival Time: 22:30" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 1750;
                cout << "Ticket Confirmed : 107UP Islamabad Express" << endl;
                cout << "Departure Time: 18:00" << endl;
                cout << "Arrival Time: 22:30" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                trains();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }

        case 4:
        {
            system("CLS");

            cout << endl;
            cout << "\t \t \tTrains Found on way to Karachi" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "6DN Green Line\t20:40\t\t14:45";
            cout << "1.Economy (Seat)\t\tRs.4650\tRefundable\n";
            cout << "2.Economy (Birth)\t\tRs.4750\tRefundable\n";
            cout << "3.AC Business\t\tRs.11700\tRefundable\n";
            cout << endl;
            cout << "Select the seat you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 4650;
                cout << "Ticket Confirmed : 6DN Green Line" << endl;
                cout << "Departure Time: 20:40" << endl;
                cout << "Arrival Time: 14:45" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 4750;
                cout << "Ticket Confirmed : 6DN Green Line" << endl;
                cout << "Departure Time: 20:40" << endl;
                cout << "Arrival Time: 14:45" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 11700;
                cout << "Ticket Confirmed : 6DN Green Line" << endl;
                cout << "Departure Time: 20:40" << endl;
                cout << "Arrival Time: 14:45" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                trains();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }
        case 5:
        {
            system("CLS");

            cout << endl;
            cout << "\t \t \tTrains Found on way to Quetta" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "40DN Jaffar Express\t16:15\t\t16:30";
            cout << "1.Economy (Seat)\t\tRs.3900\tRefundable\n";
            cout << "2.Economy (Birth)\t\tRs.4000\tRefundable\n";
            cout << "3.AC Business\t\tRs.8200\tRefundable\n";
            cout << endl;
            cout << "Select the seat you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 3900;
                cout << "Ticket Confirmed : 40DN Jaffar Express" << endl;
                cout << "Departure Time: 16:15" << endl;
                cout << "Arrival Time: 16:30" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 4000;
                cout << "Ticket Confirmed : 40DN Jaffar Express" << endl;
                cout << "Departure Time: 16:15" << endl;
                cout << "Arrival Time: 16:30" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 8200;
                cout << "Ticket Confirmed : 40DN Jaffar Express" << endl;
                cout << "Departure Time: 16:15" << endl;
                cout << "Arrival Time: `16:30" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                trains();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }
        case 6:
        {
            system("CLS");

            cout << endl;
            cout << "\t \t \tTrains Found on way to Faisalabad" << endl
                 << endl;
            cout << "Airline:\tDeparture:\tArrival:\tPrice:\t\tCategory:\n";
            cout << "42DN Karakoram Express\t15:00\t\t17:00";
            cout << "1.Economy (Seat)\t\tRs.3900\tRefundable\n";
            cout << "2.Economy (Birth)\t\tRs.4000\tRefundable\n";
            cout << "3.AC Business\t\tRs.8200\tRefundable\n";
            cout << endl;
            cout << "Select the seat you want to to book :";
            cin >> choice1;
            if (choice1 == 1)
            {
                charges = 900;
                cout << "Ticket Confirmed : 42DN Karakoram Express" << endl;
                cout << "Departure Time: 15:00" << endl;
                cout << "Arrival Time: 17:00" << endl;
            }
            else if (choice1 == 2)
            {
                charges = 950;
                cout << "Ticket Confirmed : 42DN Karakoram Express" << endl;
                cout << "Departure Time: 15:00" << endl;
                cout << "Arrival Time: 17:00" << endl;
            }
            else if (choice1 == 3)
            {
                charges = 1700;
                cout << "Ticket Confirmed : 42DN Karakoram Express" << endl;
                cout << "Departure Time: 15:00" << endl;
                cout << "Arrival Time: `17:00" << endl;
            }
            else
            {
                cout << "Invalid input , shifting to the previous menu " << endl;
                system("CLS");
                trains();
            }
            payment::processPayment();
            cout << "You can go back to menu and take the ticket " << endl;
            cout << endl;
            cout << "Press any key to go back to the Main Menu :" << endl;
            cin >> back;
            if (back == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }
        }
        }
    }
};

float trainregistration::charges;
int trainregistration::choice;

class ticket : public registration, public Details, public trainregistration
{
public:
    void Bill()
    {
        int f = 0;
        string destination = " ";
        ofstream outf("records.txt"); // write data of the flights (stored)
        {
            outf << "**********************************************\n";
            outf << "************** E-Ticket *****************\n";
            outf << "**********************************************\n";
            outf << "Customer ID:          " << Details::customerid << "\n";
            outf << "Customer Name:        " << Details::name << "\n";
            outf << "Customer Gender:      " << Details::gender << "\n";

            if (registration::choice >= 1 && registration::choice <= 6)
            {
                if (registration::choice == 1)
                {
                    destination = "Dubai";
                }
                else if (registration::choice == 2)
                {
                    destination = "Canada";
                }
                else if (registration::choice == 3)
                {
                    destination = "UK";
                }
                else if (registration::choice == 4)
                {
                    destination = "USA";
                }
                else if (registration::choice == 5)
                {
                    destination = "Australia";
                }
                else if (registration::choice == 6)
                {
                    destination = "Europe";
                }
                outf << "Destination:          " << destination << "\n";
                outf << "Flight Cost (Rs.):    " << registration::charges << " (APPROVED :))\n";
            }
            else if (trainregistration::choice >= 1 && trainregistration::choice <= 6)
            {
                if (trainregistration::choice == 1)
                {
                    destination = "Multan";
                }
                else if (trainregistration::choice == 2)
                {
                    destination = "Peshawar";
                }
                else if (trainregistration::choice == 3)
                {
                    destination = "Rawalpindi";
                }
                else if (trainregistration::choice == 4)
                {
                    destination = "Karachi";
                }
                else if (trainregistration::choice == 5)
                {
                    destination = "Quetta";
                }
                else if (trainregistration::choice == 6)
                {
                    destination = "Faisalabad";
                }
                outf << "Destination:          " << destination << "\n";
                outf << "Train Cost (Rs.):     " << trainregistration::charges << " (APPROVED :))\n";
            }

            outf << "**********************************************\n\n";
        }
        outf.close(); // file closed.
    }
    void cancelticket(int x) // function to cancel ticket
    {
        Details d;
        // ticket t;
        int f = 0;
        int backset;

        ifstream fout("records.txt");     // for reading file
        ofstream fin("records1.txt");     // for writing to a new file
        fout.read((char *)&d, sizeof(d)); // reading file
        while (fout)
        {
            if (d.customerid != x)
                fin.write((char *)&d, sizeof(d)); // writing to file
            else
            {
                dispbill(); // display details
                cout << "\nYour Above ticket is being canceled:\n"
                     << "Amount refunded: Rs 45000(fixed)\n";
                f++; // incrementing f if pnr found
            }
            fout.read((char *)&d, sizeof(d)); // reading another record from file
        }
        if (f == 0) // if f==0,pnr not found
            cout << "Ticket not found\n";
        fout.close();                        // closing file
        fin.close();                         // closing file
        remove("records.txt");               // deleting old file
        rename("record1.txt", "record.txt"); // renaming new file
        cout << "Press any key to go back to main menu " << endl;
        cin >> backset;
        if (backset == 1)
        {
            system("CLS");
            mainmenu();
        }
        else
        {
            system("CLS");
            mainmenu();
        }
    }

    virtual void generateBill()
    {
        cout << "Base class generateBill()" << endl;
    }
    void dispbill()
    {
        ifstream ifs("records.txt"); // to read from a file which we created.
        {
            if (!ifs)
            {
                cout << "File Error!" << endl;
            }
            while (!ifs.eof()) /// checking all the file till end;
            {
                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }
        ifs.close();
    }
};

class flightTicket : public ticket
{
public:
    void generateBill() override
    {
        cout << "Generating flight ticket bill..." << endl;
        ifstream ifs("records.txt"); // to read from a file which we created.
        {
            if (!ifs)
            {
                cout << "File Error!" << endl;
            }
            while (!ifs.eof()) /// checking all the file till end;
            {
                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }
        ifs.close();
    }
};

// Derived class for train tickets
class trainTicket : public ticket
{
public:
    void generateBill() override
    {
        cout << "Generating train ticket bill..." << endl;
        ifstream ifs("records.txt"); // to read from a file which we created.
        {
            if (!ifs)
            {
                cout << "File Error!" << endl;
            }
            while (!ifs.eof()) /// checking all the file till end;
            {
                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }
        ifs.close();
    }
};
void mainmenu()
{
    int litchoice;
    int schoice;
    int backset;
    int n;

    cout << "****************************************************" << endl;
    cout << "\tWelcome to E-Ticketing Wonderland, Pakistan! ( ^ -^)" << endl;
    cout << "\t\tEmbark on Your Journey with Us!" << endl;
    cout << "****************************************************" << endl;
    cout << "\tBook your tickets hassle-free & at great prices!" << endl;
    cout << "****************************************************" << endl;
    cout << "1. Enroll Customer Details" << endl;
    cout << "2. Avail Flight Adventure" << endl;
    cout << "3. Board Train Odyssey" << endl;
    cout << "4. Verify Your Ticket" << endl;
    cout << "5. Wave Goodbye to Tickets" << endl;
    cout << "6. Share Your Voyage" << endl;
    cout << "7. Depart from Here" << endl;
    cout << "\n\t\t Please enter your choice:";
    cin >> litchoice;

    Details d;
    registration r;
    trainregistration tr;
    ticket t;
    payment p;

    switch (litchoice)
    {
    case 1:
    {
        system("CLS");
        cout << "__________________Customers______________________" << endl;
        cout << endl;
        d.inputinformation();
        cout << endl;
        cout << "Press 1 to go back to the Main Menu ";
        cin >> backset;
        if (backset == 1)
        {
            system("CLS");
            mainmenu();
        }
        else
        {
            system("CLS");
            mainmenu();
        }
        break;
    }
    case 2:
    {
        system("CLS");
        int again;
        cout << "______________Book a Flight Using This System__________________________" << endl;
        cout << endl;
        if (z == 1)
        {
            e++;
            r.flights();
            flightTicket ft;
            ft.generateBill();
        }
        else
        {
            cout << "Firstly Complete the customer details (Thanks) " << endl;
            cout << "press 1 to go back to customer detail : ";
            cin >> again;
            if (again == 1)
            {
                system("CLS");
                cout << "__________________Customers______________________" << endl;
                d.inputinformation();
                z = 1;
                cout << "Press 1 to go back to the Main Menu ";
                cin >> backset;
                if (backset == 1)
                {
                    system("CLS");
                    mainmenu();
                }
                else
                {
                    system("CLS");
                    mainmenu();
                }
            }
            else
            {
                mainmenu();
            }
        }

        break;
    }
    case 3:
    {
        system("CLS");
        int again;
        cout << "______________Book a Train Using This System__________________________" << endl;
        cout << endl;
        if (z == 1)
        {
            e++;
            tr.trains();
            trainTicket tt;
            tt.generateBill();
        }
        else
        {
            cout << "Firstly Complete the customer details (Thanks) " << endl;
            cout << "press 1 to go back to customer detail : ";
            cin >> again;
            if (again == 1)
            {
                system("CLS");
                cout << "__________________Customers______________________" << endl;
                d.inputinformation();
                z = 1;
                cout << "Press 1 to go back to the Main Menu ";
                cin >> backset;
                if (backset == 1)
                {
                    system("CLS");
                    mainmenu();
                }
                else
                {
                    system("CLS");
                    mainmenu();
                }
            }
            else
            {
                mainmenu();
            }
        }

        break;
    }
    case 4:
    {
        system("CLS");
        cout << "_______________Get Your Ticket____________" << endl;
        cout << endl;
        if (z == 1 && e == 1)
        {
            t.Bill();
        }
        else
        {
            cout << "first complete the data ..........." << endl;
            cout << "Press 1 to go back to main menu " << endl;
            cin >> backset;
            if (backset == 1)
            {
                system("CLS");
                mainmenu();
            }
            else
            {
                system("CLS");
                mainmenu();
            }

            break;
        }
        cout << endl;
        cout << "Your Ticket is printed , You can collect it " << endl;
        cout << "Press 1 to display your ticket :";
        cin >> backset;
        if (backset == 1)
        {
            t.dispbill();
        }
        else
        {
            cout << "ticket not found !" << endl;
        }
        cout << endl;
        cout << "Press 1 to go back to main menu " << endl;
        cin >> backset;
        if (backset == 1)
        {
            system("CLS");
            mainmenu();
        }
        else
        {
            system("CLS");
            mainmenu();
        }

        break;
    }
    case 5:
    {
        system("CLS");
        cout << "______________________________Cancel Ticket__________________________________" << endl;
        cout << endl;
        cout << "Please enter your ID :";
        cin >> n;
        t.cancelticket(n);
        cout << "Press any key to go back to main menu " << endl;
        cin >> backset;
        if (backset == 1)
        {
            system("CLS");
            mainmenu();
        }
        else
        {
            system("CLS");
            mainmenu();
        }
        break;
    }
    case 6:
    {
        system("CLS");
        string feed;
        cout << "______________________________Feedback__________________________________" << endl;
        cout << endl;
        cout << "         \n\t\t\t\4 WELCOME TO FEEDBACK BOX \1       \n";
        cout << endl;
        cout << "-------------------------------------------" << endl;
        cout << "\n\t\t\4 ";
        cin.ignore(500, '\n');
        getline(cin, feed);
        cout << "-------------------------------------------" << endl;
        cout << endl;
        cout << "Sucessfully submitted :) " << endl;
        cout << "Press any key to go back to main menu " << endl;
        cin >> backset;
        if (backset == 1)
        {
            system("CLS");
            mainmenu();
        }
        else
        {
            system("CLS");
            mainmenu();
        }
        break;
    }
    case 7:
    {
        system("CLS");
        cout << "\n\n\t_____________Thank-You_______________" << endl;
        break;
    }
    default:
    {
        cout << "Invalid Input ! Please try again........." << endl;
        mainmenu(); //// user can try for once more.
        break;
    }
    }
    while (litchoice == 6)
        ;
};

int main()
{
    Management mobj;
}