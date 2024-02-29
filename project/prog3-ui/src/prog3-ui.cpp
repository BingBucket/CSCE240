#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "../header/Part.h"
#include "../header/Part1.h"
#include "../header/Part2.h"
#include "../header/Part3.h"
#include "../header/Part4.h"
using namespace std;


int main(){
    bool loop = true;
    Part part;
    Part1 part1;
    Part2 part2;
    Part3 part3;
    Part4 part4;
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
                part.determineProcess("part1");
                part.readFile("ParamountGlobal-10k.txt");
                part.writeFile();
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
