#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "../header/Part.h"

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

void defaultMessage(std::string input){
    std::cout << "You asked: \n\n" << input << "\n\n" << "I do not know the answer to this information. Sorry! " << std::endl;
}

int main(){
    std::string filetoRead = "Netflix-10k.txt";
    bool loop = true;
    bool ispart = false;
    Part part;
    std::string userResponse;
    std::cout << "Welcome to the Text Processor!\nI have information on both Paramount and Netflix's 10-K Reports. \nIf you do not specify a company or the company is not one of the two, then we will take information from your previous query, or from Netflix's 10-k." << std::endl;

    do {
        ispart = false;
        std::cout << "\nWhat would you like to know?" << std::endl;
        getline(cin, userResponse);
        if(regex_match(userResponse, quit) || regex_match(userResponse, goodbye))
        {
            std:: cout << "Goodbye!" << std:: endl;
            ispart = true;
            loop = false;
        }
        else if(regex_match(userResponse, hello))
        {
            std::cout << "Hello!" << std::endl;
            ispart = true;
        }
        else if(regex_search(userResponse, part1))
            {
                part.determineProcess("part1");
                ispart = true;
                std::cout << "I have written everything from Part I to the output file." << std::endl;
            }
        else if(regex_search(userResponse, business)){
            part.determineProcess("business");
            std::cout << "Here is the business information. I have written everything from business to the output file." << std::endl;
                
        }
        else if(regex_search(userResponse, riskFactors)){
            part.determineProcess("riskfactors");
            std::cout << "Here is the information about risk factors. I have also written the information to the output file!\n\n" << std::endl;
                
            }
        else if(regex_search(userResponse, property)){
            part.determineProcess("properties");
            std::cout << "Here is the information about properties. I have also written the information to the output file!\n\n" << std::endl;
                
            }
        else if(regex_search(userResponse, legalstatement)){
            part.determineProcess("legal");
            std::cout << "Here is the information about legal statements. I have written additional information to the output file. Please check it out!\n\n" << std::endl;
            }
            
        else if(regex_search(userResponse, part2)){
            part.determineProcess("part2");
            ispart = true;
            std::cout << "I have written everything from Part II to the output file.\n\n" << std::endl;
            }

        else if(regex_search(userResponse, market)){
            part.determineProcess("market");
            std::cout << "Here is the information about markets. I have also written the information to the output file!\n\n" << std::endl;
            }
        else if(regex_search(userResponse, disclosure)){
            part.determineProcess("disclosure");
            std::cout << "Here is the information about disclosure statements. I have also written additional information to the output file. Please check it out!\n\n" << std::endl;
            }
        else if(regex_search(userResponse, part3))
            {
            part.determineProcess("part3");
            ispart = true;
            std::cout << "I have written everything from Part III to the output file.\n\n" << std::endl;
            }

        else if(regex_search(userResponse, directorslist)){
            part.determineProcess("directors");
            std::cout << "Here is the information about directors. I have also written additional information to the output file. Please check it out!\n\n" << std::endl;
            }

        else if(regex_search(userResponse, compensation)) {
            part.determineProcess("compensation");
            std::cout << "Here is the information about compensation statements. I have also written the information to the output file!\n\n" << std::endl;
            }
        else if(regex_search(userResponse, part4))
            {
            part.determineProcess("part4");
            ispart = true;
            std::cout << "I have written everything from Part IV to the output file.\n\n" << std::endl;
            }

        else if(regex_search(userResponse, financialstatement)) {
            part.determineProcess("financialstatement");
            std::cout << "Here is the information about financial statements. I have also written additional referenced information to the output file. Please check it out!\n\n" << std::endl;
            }
        else if(regex_search(userResponse, partAll))
            {
            part.determineProcess("partAll");
            ispart = true;
            std::cout << "I have written everything from all parts to the output file. Good luck with all that info!" << std::endl;
            }
        else{
            defaultMessage(userResponse);
            ispart = true;
        }
        if(regex_search(userResponse, paramountIdentifier))
        {
            filetoRead="ParamountGlobal-10k.txt";
        }

        else if(regex_search(userResponse, netflixIdentifier))
        {
            filetoRead="Netflix-10k.txt";
            part.readFile(filetoRead);
        }
        else{
            part.readFile(filetoRead);
        }

        if(!ispart) {
            std::cout << part.output << std::endl;
        }

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
        part.writeFile();
        part.output = "";


    }
    while(loop == true);
    return 0;
}