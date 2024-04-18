#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

std::string sessionFile;
int userResponseCount, progResponseCount = 0;
double elapsedTime = 0;
fstream fin;

int countLinesCSV() {
    fin.open("../data/chat_statistics.csv");
    int lines = 0;
    string line;
    while (getline(fin, line)) {
        lines++;
    }
    return lines;

}//Using code from Geeks4Geeks' "CSV file management using C++" article.
void readFromCSV(int rowNum) {
    sessionFile = "";
    userResponseCount = 0;
    progResponseCount = 0;
    elapsedTime = 0;
    ifstream statistics("../data/chat_statistics.csv");
    rowNum = rowNum - 1;
    vector<string> row;
    string line, item;
    int currentRow = 0;
    while (getline(statistics, line)) {
        if(currentRow == rowNum){
        istringstream s(line);
        while (getline(s, line, ',')) {
            row.push_back(line);
        }
        sessionFile = row[0];
        userResponseCount = stoi(row[1]);
        progResponseCount = stoi(row[2]);
        elapsedTime = stod(row[3]);
        }
        currentRow++;
        
    }
    statistics.close();
    
}

string getSessionFileFromCSV(int sessionNum) {
    sessionFile = "";
    userResponseCount = 0;
    progResponseCount = 0;
    elapsedTime = 0;
    ifstream statistics("../data/chat_statistics.csv");
    sessionNum = sessionNum - 1;
    vector<string> row;
    string line, item;
    int currentRow = 0;

    while (getline(statistics, line)) {
        if(currentRow == sessionNum){
        istringstream s(line);
        while (getline(s, line, ',')) {
            row.push_back(line);
        }
        sessionFile = row[0];
        }
        currentRow++;
        
    }
    statistics.close();
    return sessionFile;
    
}

void readChatFromSessionFile(string fileName) {
    ifstream readFile("../data/chat_sessions/" + fileName);
    if(!readFile.is_open()){
        cout << "Error opening file." << endl;
    }
    else{
    string line;
    while (getline(readFile, line)) {
        cout << line << endl;
    }
    }
    readFile.close();
}

int main() {
    int rowNum;
    int lines = countLinesCSV();
    bool loop = true;
    do {
        int totalUserResponseCount = 0;
        int totalProgResponseCount = 0;
        double totalElapsedTime = 0;
        cout << "Welcome to the session logger! What would you like to do?" << "\n"
        << "1. Read a session from the CSV file." << "\n"
        << "2. Show chat from a session." << "\n"
        << "3. Show summary of all sessions." << "\n"
        << "4. Exit." << endl;
        
        int userResponse;
        cin >> userResponse;
        if(userResponse == 1){
            cout << "Enter the row number of the session you would like to know the statistics of: ";
            cin >> rowNum;
            if(rowNum > lines){
                cout << "Invalid row number. Please enter a valid row number." << endl;
            }
            else{
            readFromCSV(rowNum);
            cout << "Session File Name: " << sessionFile << endl;
            cout << "User Response Count: " << userResponseCount << endl;
            cout << "Program Response Count: " << progResponseCount << endl;
            cout << "Elapsed Time: " << elapsedTime << endl;
            }
        }
        else if(userResponse == 2){
            cout << "Enter the session number you would like to read. There are currently " << countLinesCSV() << " sessions logged." << endl;
            cin >> rowNum;
            if(rowNum > lines){
                cout << "Invalid session number. Please enter a valid session number." << endl;
            }
            else{
            sessionFile = getSessionFileFromCSV(rowNum);
            readChatFromSessionFile(sessionFile);
            cout << "Chat from session " << rowNum << " has been displayed." << endl;
            }
        }
        else if(userResponse == 3){
            cout << "Summary of all sessions:" << endl;
            for(int i = 1; i < lines+1; i++){
                readFromCSV(i);
                totalUserResponseCount += userResponseCount;
                totalProgResponseCount += progResponseCount;
                totalElapsedTime += elapsedTime;
            }
            cout << "Total User Responses: " << totalUserResponseCount << endl;
            cout << "Total Program Responses: " << totalProgResponseCount << endl;
            cout << "Total Elapsed Time: " << totalElapsedTime << " seconds" << endl;
        }
        else if(userResponse == 4){
            cout << "Goodbye!" << endl;
            loop = false;
        }
        else{
            cout << "Invalid input. Please enter a valid option." << endl;
        }
    } while (loop == true);
    return 0;
}