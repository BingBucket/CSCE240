#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <chrono>
#include "../header/Part.h"
#include "../header/Query.h"

using namespace std;


//Regex for simple responses. The first two, quit and goodbye, are used to terminate the program.
std::regex quit("[q|Q](uit)?");
std::regex goodbye("((g|G)ood)?(b|B)ye");
std::regex hello("(h|H)(i*|(ello))$");

//This regex is used to find which file the user wants to search
std::regex paramountIdentifier("(p|P)aramount( (g|G)lobal)?");
std::regex netflixIdentifier("(n|N)et(f|F)lix");

//Regex for all four parts of the file
std::regex part1("(p|P)art (1|I)$");
std::regex part2("(p|P)art (2|II)$");
std::regex part3("(p|P)art (3|III)$");
std::regex part4("(p|P)art (4|IV)$");

//Regex for the special query of asking for all information
std::regex partAll("((T|t)ell|(g|G)ive) (me|all) (everything|info(rmation)?)");

//Regex for asking for a specific part
std::regex business("((b|B)usiness)|((o|O)verview)");
std::regex riskFactors("((r|R)isk)s?( (f|F)actors?)?");
std::regex property("((p|P)ropert(ys?|i?e?s))");
std::regex market("(m|M)arkets?");
std::regex legalstatement("(l|L)egal( statements?)?");
std::regex disclosure("(d|D)isclosure( statements?)?");
std::regex directorslist("(((b|B)oa?rd( of)? ?))?(d|D)irectors?");
std::regex compensation("((e|E)xecs?(utive)?)? ?(c|C)ompensations?");
std::regex financialstatement("(f|F)in+anc(es?|(ial))( (s|S)tatements?)?");


//Initializing variables needed for the data logger text file and the .csv file.
//Responses is used to store the responses.
//Logger is used to store all responses from the user, and the output from the program.
std::stringstream responses;
std::string logger;
std::string fileData;
int userResponseCount = 0;
int progResponseCount = 0;
double elapsedTime = 0;

//Small method basically to repeat the below process so that the program can both take in a response into logger and output it to the terminal.
//This also clears out the stringstream so that it does not repeat the same information.
void printClearStream() {
    logger += responses.str();
    std::cout << responses.str() << std::endl;
    responses.str("");

}

void defaultMessage(std::string input){
    responses << "You asked: \n\n" << input << "\n\n" << "I do not know the answer to this information. Sorry! " << std::endl;
    printClearStream();
}

std::string getCurrentDateTime() {
    auto current = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(current);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&currentTime), "%Y_%m_%d%_%H");
    return ss.str();
}

std::string writeToFile(std::string output){
    fileData = "sessionData" + getCurrentDateTime() + ".txt";
    std::ofstream file("../../data/chat_sessions/" + fileData);
    file << output;
    file.close();
    return fileData;
}

//Appends the chat data to the csv file in the following format: sessionName, user response count, program response count, elapsed time.
void appendToCSV() {
    std::ofstream file("../../data/chat_statistics.csv", std::ios::app);
    if (file.is_open()) {
        file << "\n" << fileData << "," << userResponseCount << "," << progResponseCount << "," << elapsedTime;
        file.close();
    } else {
        std::cerr << "Unable to open file: " << std::endl;
    }
}

int main(){
    std::string filetoRead = "Netflix-10k.txt";
    bool loop = true;
    //ispart boolean is used to check if an output to terminal is needed. This is used mainly for the larger outputs, especially the parts, but is also used for miscellaneous options like saying hi or quitting.
    bool ispart = false;
    Part part;
    Query query;
    std::string userResponse;
    auto start = std::chrono::system_clock::now();
    responses << "Welcome to the Text Processor!\nI have information on both Paramount and Netflix's 10-K Reports. \nIf you do not specify a company or the company is not one of the two, then we will take information from your previous query, or from Netflix's 10-k." << std::endl;
    printClearStream();
    //do while loop to begin the chatbot process.
    do {
        ispart = false;
        responses << "\nWhat would you like to know?" << std::endl;
        printClearStream();
        getline(cin, userResponse);
        logger += userResponse + "\n";
        userResponseCount++;
        responses.str("");

        //The first if statement is what exits the loop if the user inputs a goodbye or quit command
        if(regex_match(userResponse, quit) || regex_match(userResponse, goodbye))
        {
            responses << "Goodbye!" << std:: endl;
            printClearStream();
            progResponseCount++;
            ispart = true;
            loop = false;
        }
        //A simple hello command if the user inputs hello
        else if(regex_match(userResponse, hello))
        {
            responses << "Hello!" << std::endl;
            printClearStream();
            progResponseCount++;
            ispart = true;
        }

        //These else if statements are used to determine what parts of the file that the readFile command should read from.
        else if(regex_search(userResponse, part1))
            {
                part.determineProcess("part1");
                ispart = true;
                responses << "I have written everything from Part I to the output file." << std::endl;
                printClearStream();
                progResponseCount++;
            }
        else if(regex_search(userResponse, business)){
            part.determineProcess("business");
            responses << "Here is the business information. I have written everything from business to the output file." << std::endl;
            printClearStream();
            progResponseCount++;
        }
        else if(regex_search(userResponse, riskFactors)){
            part.determineProcess("riskfactors");
            responses << "Here is the information about risk factors. I have also written the information to the output file!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }
        else if(regex_search(userResponse, property)){
            part.determineProcess("properties");
            responses << "Here is the information about properties. I have also written the information to the output file!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }
        else if(regex_search(userResponse, legalstatement)){
            part.determineProcess("legal");
            responses << "Here is the information about legal statements. I have written additional information to the output file. Please check it out!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }
            
        else if(regex_search(userResponse, part2)){
            part.determineProcess("part2");
            ispart = true;
            responses << "I have written everything from Part II to the output file.\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }

        else if(regex_search(userResponse, market)){
            part.determineProcess("market");
            responses << "Here is the information about markets. I have also written the information to the output file!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }
        else if(regex_search(userResponse, disclosure)){
            part.determineProcess("disclosure");
            responses << "Here is the information about disclosure statements. I have also written additional information to the output file. Please check it out!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }
        else if(regex_search(userResponse, part3))
            {
            part.determineProcess("part3");
            ispart = true;
            responses << "I have written everything from Part III to the output file.\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }

        else if(regex_search(userResponse, directorslist)){
            part.determineProcess("directors");
            responses << "Here is the information about directors. I have also written additional information to the output file. Please check it out!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }

        else if(regex_search(userResponse, compensation)) {
            part.determineProcess("compensation");
            responses << "Here is the information about compensation statements. I have also written the information to the output file!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }
        else if(regex_search(userResponse, part4))
            {
            part.determineProcess("part4");
            ispart = true;
            responses << "I have written everything from Part IV to the output file.\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }

        else if(regex_search(userResponse, financialstatement)) {
            part.determineProcess("financialstatement");
            responses << "Here is the information about financial statements. I have also written additional referenced information to the output file. Please check it out!\n\n" << std::endl;
            printClearStream();
            progResponseCount++;
            }
        else if(regex_search(userResponse, partAll))
            {
            part.determineProcess("partAll");
            ispart = true;
            responses << "I have written everything from all parts to the output file. Good luck with all that info!" << std::endl;
            printClearStream();
            progResponseCount++;
            }
        
        //If none of the above is found, then the terminal will output the default error message and ask again.
        //The default message does not increment the program response count by 1.
        else{
            defaultMessage(userResponse);
            ispart = true;
        }


        //Instead of using the paramountIdentifier and netflixIdentifier regexes, the matchCompany method is used to determine which file to read from first.
        part.readFile(query.matchCompany(userResponse));

        //After using the matchCompany method, the paramountIdentifier and netflixIdentifier regexes are used if needed.
        if(regex_search(userResponse, paramountIdentifier) && query.companyFind == false)
        {
            filetoRead="ParamountGlobal-10k.txt";
            part.readFile(filetoRead);
        }

        else if(regex_search(userResponse, netflixIdentifier) && query.companyFind == false)
        {
            filetoRead="Netflix-10k.txt";
            part.readFile(filetoRead);
        }

        //This if statement is to check if the boolean ispart is false. If it is, then it outputs the information from the readFile to the terminal.
        if(!ispart) {
            responses << part.output << std::endl;
            printClearStream();
        }

        /*These last if statements are used to call the specific functions if the user's request is for a
        * legal statement, disclosure statement, list of directors, or compensation statement.
        * The readFile method is not enough to output the required information for each statement, so these extra methods are needed.
        */
        if(regex_search(userResponse, legalstatement))
        {
            part.readLegal(filetoRead);
        }
        else if(regex_search(userResponse, disclosure))
        {
            part.readDisclosure(filetoRead);
        }
        else if(regex_search(userResponse, directorslist))
        {
            
            part.readDirectors(filetoRead);
        }
        else if(regex_search(userResponse, compensation))
        {
            part.readConsolidatedStatement(filetoRead);
        }

        //Writes the output to the file, and erases anything left in the output to ensure it is clean for the next readFile method.
        part.writeFile();
        part.output = "";


    }
    while(loop == true);
    auto end = std::chrono::system_clock::now();
    elapsedTime = std::chrono::duration<double>(end - start).count();
    responses << "\nThe user inputted " << userResponseCount << " responses." << std::endl;
    responses << "\nThe program outputted " << progResponseCount << " valid responses." << std::endl;
    responses << "\nThe program ran for " << elapsedTime << " seconds." << std::endl;
    logger += responses.str();

    //Writes session data to a file and appends the necessary data to the CSV file.
    writeToFile(logger);
    appendToCSV();
    //Clears the responses stringstream to ensure that it is clean just in case.
    responses.str("");
    return 0;
}