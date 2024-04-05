#ifndef QUERY_H_
#define QUERY_H_

#include<string>
#include<vector>
class Query{
    public:
    std::string userQuery;
    std::string guessIntent;
    double matchScore;
    double netflixScore;
    double paramountScore;
    std::vector<std::string> words;
    std::vector<std::string> comparison;
    bool companyFind;

    // //Part 1 intents
    // std::string intentsBusiness = "What is the company's business";
    // std::string intentsRiskFactors = "What are the risk factors";
    // std::string intentsProperties = "What properties do they own";
    // std::string intentsLegal = "What are the legal statements for the company";
    
    // //Part 2 intents
    // std::string intentsPart2 = "where does the company operate in";
    // std::string intentsMarket = "What markets do they operate in";
    
    // //Part 3 intents
    // std::string intentsPart3 = "What is the structure of the company";
    // std::string intentsDirectors = "Who are the board of directors";
    // std::string intentsCompensation = "How much are the directors paid";
    // std::string intentsStatements = "What financial statements do they make";
    
    void splitQuery(std::string userQuery);
    //void splitIntent(std::string intent);
    //std::string matchIntent(std::string userQuery, std::string intent);
    std::string matchCompany(std::string userQuery);
    void determineIntent();
};

#endif //QUERY_H_