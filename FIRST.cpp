#include<iostream>
#include<vector>
#include<numeric>
#include <chrono>


using namespace std;

bool isValidDateFormat(string date); //Declare a function to verified the date format.
bool isVacationDate(string date); //Declate a function to verified vacation date.

int main(){
    auto start = chrono::high_resolution_clock::now(); // to compute the excution time

    
    vector<int>Tram{23,25,25,25,25,0,0}; //create an int vector for each transport. 
    vector<int>Bus{30,30,30,30,30,30,30};
    vector<int>Boat{40,40,0,40,40,0,0};
    vector<int>Train{50,50,50,50,50,35,35};
    int trip_Number; //declare the variables
    int Trans_Num,week_Day;
    int total_Price = 0;
    string date,user_Name, user_ID;

    cout << "                            Welcome To Fare Calculor for Public Transport." << endl;
    cout << "                           Bellow the price for each transport (Tram, Bus, Boat, Train) From Monday-to-Sunday" << endl << endl;



    cout << "Tram\t";
    for (auto price : Tram) {
        cout << price << " \t";
    }
    cout << endl;

    cout << "Bus\t";
    for (auto price : Bus) {
        cout << price << " \t";
    }
    cout << endl;

    cout << "Boat\t";
    for (auto price : Boat) {
        cout << price << " \t";
    }
    cout << endl;

    cout << "Train\t";
    for (auto price : Train) {
        cout << price << " \t";
    }
    cout << endl;
    while(true) { //while true will be inside the loop otherwise by typing exit will quit out of the loop.
        cout<<"Enter Your Name: "<<"\n";
        cin>>user_Name;
        cout<<"Enter your ID: "<<"\n";
        cin>>user_ID;
        cout << "Enter a date (YYYY-MM-DD) for your trip: (or type 'exit' to quit): ";
        cin >> date;
        
        if (date == "exit") {
            break;
        } else if (!isValidDateFormat(date)) {
            cout << "Invalid date format." << endl;
            continue;
        }
        
        if (isVacationDate(date)) {
            cout << date << " Congratulation! Your Ticket is Free in public Holiday!" << endl;
        } else {
            cout << "How many trips will you have: ";
            cin >> trip_Number;
    
            for(int i=0; i<trip_Number; i++) {
                cout << "Trip " << i+1 << endl; 
                cout << "Enter the day of the week (1-7):\n"
                    << "1. Monday\n2. Tuesday\n3. Wednesday\n4. Thursday\n5. Friday\n6. Saturday\n7. Sunday\n";
                
                if (!(cin >> week_Day) || week_Day < 1 || week_Day > 7) {
                    cout << "Invalid day of the week." << endl;
                    --i;
                    continue;
                }
            cout << "How many Transport will you have: ";
            cin >> Trans_Num;
    
            for(int i=0; i<Trans_Num; i++) {
                int choice;
                cout << "Enter your choice (1-4):\n"
                    << "1. Tram\n2. Bus\n3. Boat\n4. Train\n";
                
                if (!(cin >> choice) || choice < 1 || choice > 4 ) {
                    cout << "Invalid choice." << endl;
                    --i;
                    continue;
                }

                switch(choice) {
                    case 1:
                        total_Price += Tram[week_Day-1]; //calculate the total. 
                        break;
                    case 2:
                        total_Price += Bus[week_Day-1];
                        break;
                    case 3:
                        total_Price += Boat[week_Day-1];
                        break;
                    case 4:
                        total_Price += Train[week_Day-1];
                        break;
                }
            }
            }
            if(total_Price>200){
              
                cout << "Dear"<<user_Name<<" Your Total Price is: 200 Kr with:"<<user_ID<< endl;
           }
            else {
                cout << "Dear "<<user_Name<<" Your Total is : "<<total_Price<<" Kr with your ID : "<<user_ID<< endl;
            }
        }
        
        total_Price = 0;
    }
      // Get the ending timepoint
    auto end = chrono::high_resolution_clock::now();

    // Compute the duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Print the duration
    cout << "Execution time: " << duration.count() << " microseconds" << endl; // 16347884 microseconds

    return 0;
}
   bool isValidDateFormat(string date) {
    if (date.size() != 10) { // check the length of the input
        return false;
    }
    for (int i = 0; i < 10; i++) { // check each character of the input
        if (i == 4 || i == 7) { // check the positions of the hyphens
            if (date[i] != '-') {
                return false;
            }
        } else {
            if (!isdigit(date[i])) { // check if the characters between the hyphens are digits
                return false;
            }
        }
    }

    return true;
}


bool isVacationDate(string date) {
    // Define the vacation dates as a vector of pairs containing the start and end dates
    std::vector<std::pair<std::string, std::string>> vacationDates = {
        {"2023-02-20", "2023-02-24"}, // Winter break
        {"2023-04-15", "2023-04-21"}, // Easter break
        {"2023-06-10", "2023-08-21"}, // Summer break
        {"2023-10-30", "2023-11-03"}  // Autumn break
    };

    // Check if the entered date falls within any of the vacation periods
    for (const auto& vacation : vacationDates) {
        if (date >= vacation.first && date <= vacation.second) {
            return true;
        }
    }

    return false;
    
}
