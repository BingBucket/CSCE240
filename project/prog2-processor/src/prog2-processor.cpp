#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>

using namespace std;

//regex paranum is used mainly for the ParamountGlobal text file, as it outlines page numbers in the following manner.
//All three regex will be used to check if the line is simply for a page number, so it can be skipped.
regex paramountnum("^[I-Z]+[I-Z]?-[0-9]+");
//regex tableofcontents and netflixnum are for the Netflix file, as the text file puts the page number in one line, and the string "Table of Contents" on the next line.
regex tableofcontents("Table of Contents");
regex netflixnum("^[0-9]+");
std::string output;
//These variables are used for the determineProcess function below.
//finder is used in the readFile to determine what line to look for to determine what to read and print out.
std::string finder;
//ender and enderalt are used to determine when the file reader should stop printing lines. There are two variables since Paramount and Netflix have slight differences in the way they format the items.
std::string ender;
std::string enderalt;

//These regex statements are used for specific items in the text files. They are meant to be specific enough to access the required information for each specific item.
regex statement("CONSOLIDATED STATEMENTS OF OPERATIONS");
regex directors("^(\\*\\		)?[A-Z][a-z]{1,}-?[a-zA-Z]*.+(	)(January|February).+202(3|4)$");
regex marketrisk("^Market Risk");
regex legal("^Legal [A-Z][a-z]{6,}");

//These strings are used for specific functions, namely the readLegal, readDisclosure, readDirectors, and readConsolidatedStatement functions
std:: string legalStatement;
std::string financialStatements;
std::string directorsList;
std:: string process;
std:: string disclosureStatement;

//This function is used to set the finder, ender, and enderalt variables.
//Depending on the string process parameter that is passed, the finder, ender, and enderalt variables will change accordingly for the readFile.
//This is called prior to the readFile or else the readFile will not function correctly.s
void determineProcess(std:: string process) {
    if(process == "part1"){
        finder= "PART I";
        ender= "PART II";
        enderalt = "PART II";
    }
    else if(process == "business"){
        finder = "Item 1.";
        ender = "Item 1A.";
        enderalt = "Item 1A.Risk Factors";
    }
    else if(process == "riskfactors"){
        finder = "Item 1A.";
        ender = "Item 1B.";
        enderalt = "Item 1B.Unresolved Staff Comments";
    }
    else if(process == "properties") {
        finder = "Item 2.";
        ender = "Item 3.";
        enderalt = "Item 3.Legal Proceedings";
    }
    else if(process == "legal") {
        finder = "Item 3.";
        ender = "Item 4.";
        enderalt = "Item 4.Mine Safety Disclosures";
    }
    else if (process == "part2"){
        finder = "PART II";
        ender = "PART III";
        enderalt = "PART III";
    }
    else if (process == "market"){
        finder = "Item 5.";
        ender = "Item 6.[Reserved]";
        enderalt = "Item 7.";
    }
    else if (process == "disclosure"){
        finder = "Item 7A.";
        ender = "Item 8.";
        enderalt = "Item 8.Financial Statements and Supplementary Data";

    }
    else if (process == "part3"){
        finder = "PART III";
        ender = "PART IV";
        enderalt = "PART IV";
    }
    if (process == "directors"){
        finder = "Item 10.";
        ender = "Item 11.Executive Compensation";
        enderalt = "Item 11.";
    }
    else if (process == "compensation"){
        finder = "Item 11.";
        ender = "Item 12.Security Ownership of Certain Beneficial Owners and Management and Related Stockholder Matters";
        enderalt = "Item 12.";
    }
    else if (process == "financialstatement"){
        finder = "Item 15.";
        ender = "Item 16.";
        enderalt = "Item 16. Form 10–K Summary";
    }

    
}

//This function is used to read the text file and print out the relevant information.
void readFile(std::string filename){
    string line;
    int count = 0;
    bool skip = false;
    std::ifstream inputFile("../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            //This is used to 'skip' the first instance of the finder variable, which is found in the Table of Contents in each file.
            //This way, the readFile method will return the actual item section.
            if (line.find(finder) != std::string::npos )
            {
                count++;

            }
            //When it finds the second instance of the finder variable, then it will start printing out the lines of the file.
            if(count == 2)
                {
                    while(getline(inputFile, line))
                    {
                        //skip boolean is turned to false every iteration in case the boolean is true from a past iteration.
                        skip = false;
                        //This if statement is to stop the output when it reaches the next section.
                        //Whenever it finds the line with the corresponding string, it will increment the count by 1 and return to stop the loop.
                        if (line == ender || line == enderalt)
                        {
                            count ++;
                            return;
                        }
                        //Checks if the line matches any of the three outlined regex patterns. If it does, then it changes the boolean to true and skips the line.
                        if (regex_match(line, paramountnum) || regex_match(line, tableofcontents) || regex_match(line, netflixnum)){
                            skip = true;

                        }
                        //If skip is false, then it will concatenate the line to the output string.
                        if (!skip){
                            output += "\n" + line;
                        }
                    }
                }
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
    }

//A simple writeFile method that takes in the output variable and writes it to the output file.
void writeFile() {
    ofstream outputFile("../txt/output.txt");
    if (outputFile.is_open()) {
        outputFile << output << endl;
        outputFile.close();

    }
    else cout << "File could not be opened!" << endl;
 }

//This function is used to read the legal statements, as the corresponding item section does not contain the following statements, but rather refers to a different section of the file with the relevant information.
void readLegal(string filename){
    int count = 0;
    string line;
    std::ifstream inputFile("../../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            //If the line matches the corresponding regex pattern, it increments the count by 1. This is again to skip certain similar patterns.
            if (regex_match(line, legal))
            {
                count++;

            }
            if(count == 2)
                {
                    legalStatement += "\n"+ line;
                    while(getline(inputFile, line))
                    {

                        if (line == "" || line == " ")
                        {
                            count ++;
                            //When it reaches a blank line, then it adds the whole legalStatement string to output.
                            output += legalStatement;
                            return;
                        }
                        legalStatement += "\n" + line;
                        
                    }
                }
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
}
//This function is only used for the Paramount file, since it refers to a disclosure statement from a different section.
//The Netflix file does not do this, so it is unnecessary for it to use this function.
void readDisclosure(std::string filename){
    string line;
    std::ifstream inputFile("../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (regex_match(line, marketrisk))
            {
                disclosureStatement += "\n" + line;
                while(getline(inputFile, line))
                    {

                        if (line == "" || line == " ")
                        {
                            output += disclosureStatement;
                            return;
                        }
                        disclosureStatement += "\n" + line;
                        
                    }
            }
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
}
//Although the directors are outlined in a different file, the directors are referred to in a different part of the file. This function is used to find that part of the file with the directors.
void readDirectors(std:: string filename){
    std::string line;
    std::ifstream inputFile("../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (regex_match(line, directors))
            {
                getline(inputFile, line);
                directorsList += "\n" + line;
            }
        }
        output += directorsList;
        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
}

//This function is used to read the consolidated statement, as the corresponding item section does not contain the following information.
void readConsolidatedStatement(std::string filename){
    string line;
    bool skip = false;
    std::ifstream inputFile("../txt/" + filename);
    if (inputFile.is_open()) {
        while (getline(inputFile, line))
        {
            if (line == "CONSOLIDATED STATEMENTS OF OPERATIONS")
            {
                while(getline(inputFile, line))
                    {
                        skip = false;

                        if (line == "NOTES TO CONSOLIDATED FINANCIAL STATEMENTS")
                        {
                            output += financialStatements;
                            return;
                        }
                        if (regex_match(line, paramountnum) || regex_match(line, tableofcontents) || regex_match(line, netflixnum)){
                            skip = true;

                        }
                        if (!skip){
                            financialStatements += "\n" + line;
                        }
                        
                    }
            }
            
        }

        inputFile.close();
    }
    else{
        cout << "Unable to open file";
    }
}

int main(){
    bool loop = true;
    std::string userResponse;
    std::string paramountSearch;
    std::string netflixSearch;
    cout << "Welcome to the Text Processor!\nI have information on both Paramount and Netflix's 10-K Reports.\nWhich would you like to access?" << endl;

//A do while loop so that the program will only terminate when the user commands it to.
    do {
        //First asks the user which file they want to access.
        cout << "Which file would you like to access?" << endl;
        getline(cin, userResponse);
        if(userResponse =="hi" || userResponse =="hello" || userResponse == "hey"){
            cout << "Hello there!" << endl;
        }
        //else if statement that determines whether the loop ends depending on the user's response.
        else if(userResponse == "exit" || userResponse == "done"|| userResponse == "bye"){
            cout << "Goodbye!" << endl;
            loop = false;
        }

        //If the user responds with "paramount", then it will ask for further information on what they want
        else if(userResponse == "Paramount" || userResponse == "paramount")
        {
            cout << "What would you like to find in the Paramount file?\n" << endl;
            getline(cin, paramountSearch);
            if(paramountSearch == "part 1" || paramountSearch == "Part 1"){
                determineProcess("part1");
                readFile("ParamountGlobal-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from part 1 into the output file.\n" << endl;
            }
            else if(paramountSearch == "business"){
                determineProcess("business");
                readFile("ParamountGlobal-10k.txt");
                writeFile();
                cout << "Here is the following business information for Paramount Global:" << output << endl;
                cout << "I have gotten and written all the data from business into the output file.\n" << endl;
            }
            else if(paramountSearch == "risk factors"){
                determineProcess("riskfactors");
                readFile("ParamountGlobal-10k.txt");
                writeFile();
                cout << "Here are the following risk factors for Paramount:" << output << endl;
                cout << "I have gotten and written all the data from risk factors into the output file.\n" << endl;
            }
            else if(paramountSearch == "properties"){
                determineProcess("properties");
                readFile("ParamountGlobal-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from properties into the output file.\n" << endl;
            }
            else if(paramountSearch == "market" || paramountSearch == "markets" || paramountSearch == "market information"){
                determineProcess("market");
                readFile("ParamountGlobal-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from market information into the output file.\n" << endl;
            }
            else if(paramountSearch == "legal" || paramountSearch == "legal statement" || paramountSearch == "legal information"){
                determineProcess("legal");
                readFile("ParamountGlobal-10k.txt");
                readLegal("ParamountGlobal-10k.txt");
                writeFile();
                cout << "Here is the following from the legal section of the Netflix document. Please check the output file for the referenced statements\n" << output << endl;
                cout << "I have gotten and written all the data from legal information into the output file.\n" << endl;
            }
            else if(paramountSearch == "part 2" || paramountSearch == "part II"){
                determineProcess("part2");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from part 2 into the output file.\n" << endl;
            }
            else if(paramountSearch == "disclosure" || paramountSearch == "disclosure statement" || netflixSearch == "disclosure information"){
                determineProcess("disclosure");
                readFile("ParamountGlobal-10k.txt");
                readDisclosure("ParamountGlobal-10k.txt");
                writeFile();
                cout << "Here is the following from the disclosure section of the Netflix document. Please check the output file for the referenced statements.\n" << output << endl;
                cout << "I have gotten and written all the relevant data from disclosure information into the output file.\n" << endl;
            }
            else if(paramountSearch == "part 3" ||paramountSearch == "part III") {
                determineProcess("part3");
                readFile("ParamountGlobal-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from part 3 into the output file.\n" << endl;
            }
            else if(paramountSearch == "directors" || paramountSearch == "director"){
                determineProcess("directors");
                readFile("ParamountGlobal-10k.txt");
                readDirectors("ParamountGlobal-10k.txt");
                writeFile();
                cout << "Here is the following from the directors section of the Netflix document. Please check the output file for the referenced statements.\n" << output << endl;
                cout << "I have gotten and written all the relevant data from directors into the output file.\n" << endl;
            }

            else if(paramountSearch == "compensation"){
                determineProcess("compensation");
                readFile("ParamountGlobal-10k.txt");
                writeFile();
                cout << "Unfortunately, the exact information of compensation is not found in this 10K file. Check the output file for more information" << endl;
            }
            else if (paramountSearch == "finance" || paramountSearch == "financial statements"){
                determineProcess("finance");
                readFile("ParamountGlobal-10k.txt");
                readConsolidatedStatement("ParamountGlobal-10k.txt");
                writeFile();
                cout << "Here is the following from the financial statements section of the Netflix document. Please check the output file for the referenced consolidated statements.\n" << output << endl;
                cout << "I have gotten and written all the relevant data from financial statements into the output file.\n" << endl;
            }

        }
        //If the user responds with "netflix", then it will ask for further information on what they want.
        else if(userResponse == "Netflix" || userResponse == "netflix")
        {
            cout << "What would you like to find in the Netflix file?\n" << endl;
            getline(cin, netflixSearch);
            if(netflixSearch == "part 1" || netflixSearch == "Part 1"){
                determineProcess("part1");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from part 1 into the output file.\n" << endl;
            }
            else if(netflixSearch == "business"){
                determineProcess("business");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "Here is the following business information for Netflix:" << output << endl;
                cout << "I have gotten and written all the data from business into the output file.\n" << endl;
            }
            else if(netflixSearch == "risk factors"){
                determineProcess("riskfactors");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "Here is the following risk factors for Netflix:" << output << endl;
                cout << "I have gotten and written all the data from risk factors into the output file.\n" << endl;
            }
            else if(netflixSearch == "properties"){
                determineProcess("properties");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from properties into the output file.\n" << endl;
            }
            else if(netflixSearch == "market" || netflixSearch == "markets" || netflixSearch == "market information"){
                determineProcess("market");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from market information into the output file.\n" << endl;
            }
            else if(netflixSearch == "legal" || netflixSearch == "legal statement" || netflixSearch == "legal information"){
                determineProcess("legal");
                readFile("Netflix-10k.txt");
                readLegal("Netflix-10k.txt");
                writeFile();
                cout << "Here is the following from the legal section of the Netflix document. Please check the output file for the referenced statements\n" << output << endl;
                cout << "I have gotten and written all the data from legal information into the output file.\n" << endl;
            }
            else if(netflixSearch == "part 2" || netflixSearch == "part II"){
                determineProcess("part2");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from part 2 into the output file.\n" << endl;
            }
            else if(netflixSearch == "disclosure" || netflixSearch == "disclosure statement" || netflixSearch == "disclosure information"){
                determineProcess("disclosure");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "Here is the following from the disclosure section of the Netflix document. Please check the output file for the referenced statements.\n" << output << endl;
                cout << "I have gotten and written all the relevant data from disclosure information into the output file.\n" << endl;
            }
            else if(netflixSearch == "part 3" ||netflixSearch == "part III") {
                determineProcess("part3");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "I have gotten and written all the data from part 3 into the output file.\n" << endl;
            }
            else if(netflixSearch == "directors" || netflixSearch == "director"){
                determineProcess("directors");
                readFile("Netflix-10k.txt");
                readDirectors("Netflix-10k.txt");
                writeFile();
                cout << "Here is the following from the directors section of the Netflix document. Please check the output file for the referenced statements.\n" << output << endl;
                cout << "I have gotten and written all the relevant data from directors into the output file.\n" << endl;
            }

            else if(netflixSearch == "compensation"){
                determineProcess("compensation");
                readFile("Netflix-10k.txt");
                writeFile();
                cout << "Unfortunately, the exact information of compensation is not found in this 10K file. Check the output file for more information" << endl;
            }
            else if (netflixSearch == "finance" || netflixSearch == "financial statements"){
                determineProcess("finance");
                readFile("Netflix-10k.txt");
                readConsolidatedStatement("Netflix-10k.txt");
                writeFile();
                cout << "Here is the following from the financial statements section of the Netflix document. Please check the output file for the referenced consolidated statements.\n" << output << endl;
                cout << "I have gotten and written all the relevant data from financial statements into the output file.\n" << endl;
            }

        }

    }
    while (loop = true);
    return 0;
}
