#ifndef BASE_EMAIL_H_
#define BASE_EMAIL_H_

#include <regex>

class BaseEmailHheaderType{
    public:
    std::string received;
    std::string from;
    std::string to;
    std::string subject;
    std::string messageID;
    std::string inReplyTo;
    std::string contentType;
    std::string date;

    std::string extractMessage();


};

#endif /* BASE_EMAIL_H_ */