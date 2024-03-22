#include "../header/Query.h"
#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

void Query::splitQuery(std::string userQuery){
    //string userQuery is first converted to lowercase to make it easier to compare with the intents.
    std::transform(userQuery.begin(), userQuery.end(), userQuery.begin(), ::tolower);

    //The userQuery is then split into words and stored in a vector.
    std::stringstream query(userQuery);
    std::string word;

    while(std::getline(query, word, ' ')){
        words.push_back(word);
    }

}

// void Query::splitIntent(std::string intent){
//     //The intent is split into words and stored in a vector.
//     std::stringstream query(intent);
//     std::string word;

//     while(std::getline(query, word, ' ')){
//         comparison.push_back(word);
//     }
// }

std::string Query::matchCompany(std::string userQuery){
    //The userQuery is split into words and stored in a vector.
    splitQuery(userQuery);

    //Initialize companyFind boolean
    companyFind = true;

    //Initializes the scores for the companies to 0.
    netflixScore = 0;
    paramountScore = 0;

    //For loop compares each word in the vector to the company names and increments the score if there is a match.
    for(int i = 0; i < words.size(); i++){
        if(words[i] == "netflix"){
            netflixScore++;
        }
        if(words[i] == "paramount"){
            paramountScore++;
        }

    }
    //Whichever of the two scores is higher is the company file that is returned.    
        if(paramountScore > netflixScore){
            return "ParamountGlobal-10k.txt";
            words.clear();
        }
        else if(netflixScore > paramountScore){
            return "Netflix-10k.txt";
            words.clear();
        }
        //Otherwise, the default file is returned.
        else{
            companyFind = false;
            return "Netflix-10k.txt";
            words.clear();
        }
}



