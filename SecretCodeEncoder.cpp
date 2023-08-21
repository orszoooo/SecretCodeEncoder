// SecretCodeEncoder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

std::map<char, int> GenerateSecretCode(std::string keys)
{
    std::map<char, int> dictionary;
    const int generator_rows = 7;
    const int generator_columns = 4;
    
    int string_pointer = 0;
    for (int i = 0; i < generator_rows; i++) {
        for (int j = 0; j < generator_columns; j++) {
            if (i == generator_rows - 1) {
                if (j >= 2)
                    continue;
            }
            dictionary.insert(std::pair<char, int>(keys.at(string_pointer++), 10 * (i + 1) + (j + 1)));
        }
    }
    return dictionary;
}

int main(int argc, char* argv[])
{
    const std::string keys{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

    std::map<char, int> secret_code = GenerateSecretCode(keys);

    std::string sentence = "";
    std::string output_sentence = "";
    
    if (argc < 2) {
        std::cout << "Please provide sentence to encode: ";
        std::getline(std::cin, sentence);
    }
    else {
        sentence = argv[1];
    }

    for (char& ch : sentence) {
        ch = toupper(ch);
        if (keys.find(ch) != std::string::npos)
            output_sentence += std::to_string(secret_code[ch]);
        
        if (ch == ' ')
            output_sentence += " ";

        output_sentence += " ";
    }

    std::cout << "Encoded sentence: " << output_sentence << std::endl;
}
