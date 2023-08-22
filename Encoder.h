#pragma once
#include <map>
#include <string>

class Encoder {
private:
    //Members
    const std::string m_keys{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    std::map<char, int> m_secret_code;
    std::string m_input_sentence;
    std::string m_output_sentence;

    //Methods
    std::map<char, int> GenerateSecretCode(); 
    
public:
    //Constructors
    Encoder();

    //Methods
    void EncodeMembers();
    std::string Encode(std::string);
    std::string GetOutputSentence();
    void SetInputSentence(std::string sentence);
};

