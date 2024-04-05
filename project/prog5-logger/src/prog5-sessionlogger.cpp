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
}
//Using code from Geeks4Geeks' "CSV file management using C++" article.
int countLinesCSV() {
    fin.open("../data/chat_statistics.csv");
    int lines = 0;
    string line;
    while (getline(fin, line)) {
        lines++;
    }
    return lines;
}
//Using code from Geeks4Geeks' "CSV file management using C++" article.
void readFromCSV(int rowNum) {
    fin.open("../data/chat_statistics.csv");
    vector<string> row;
    string line, word, temp;
    int currentRow = 0;
    userResponseCount = 0;
    progResponseCount = 0; 
    elapsedTime = 0;

    while (getline(fin, line)) {
        if(currentRow == rowNum){
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        sessionFile = row[0];
        userResponseCount = stoi(row[1]);
        progResponseCount = stoi(row[2]);
        elapsedTime = stod(row[3]);
        break;
        }
        else if(currentRow > countLinesCSV()){
            cout << "Row number exceeds number of rows in CSV file. No such data exists. There are only " << countLinesCSV() << " sessions logged." << endl;
        break;
        }
        currentRow++;
        
    }
    fin.close();
    
}

string getSessionFileFromCSV(int sessionNum) {
    fin.open("../data/chat_statistics.csv");
    sessionFile = "";
    vector<string> row;
    string line, word, temp;
    int currentRow = 0;

    while (getline(fin, line)) {
        if(currentRow == sessionNum){
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        sessionFile = row[0];
        cout << "Session File Name: " << sessionFile << endl;
        }
        currentRow++;
        
    }
    if(currentRow > countLinesCSV()){
        cout << "Row number exceeds number of rows in CSV file. No such data exists. There are only " << countLinesCSV() << " sessions logged." << endl;
    }
    fin.close();
    return sessionFile;
    
}

void readChatFromSessionFile(string fileName) {
    fin.open("../data/chat_sessions/" + fileName);
    if(!fin.is_open()){
        cout << "Error opening file." << endl;
    }
    else{
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    }
    fin.close();
}

int main() {
    int rowNum = 0;
    bool loop = true;
    do {
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
            readFromCSV(rowNum);
            cout << "Session File Name: " << sessionFile << endl;
            cout << "User Response Count: " << userResponseCount << endl;
            cout << "Program Response Count: " << progResponseCount << endl;
            cout << "Elapsed Time: " << elapsedTime << endl;
        }
        else if(userResponse == 2){
            cout << "Enter the session number you would like to read. There are currently" << countLinesCSV() << " sessions logged." << endl;
            cin >> rowNum;
            readFromCSV(rowNum);
            readChatFromSessionFile(sessionFile);
            cout << "Chat from session " << rowNum << " has been displayed." << endl;
        }
        else if(userResponse == 3){
            int totalUserResponseCount = 0;
            int totalProgResponseCount = 0;
            double totalElapsedTime = 0;
            cout << "Summary of all sessions:" << endl;
            for(int i = 0; i < countLinesCSV(); i++){
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