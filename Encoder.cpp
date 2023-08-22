#include "Encoder.h"

std::map<char, int> Encoder::GenerateSecretCode()
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
            dictionary.insert(std::pair<char, int>(m_keys.at(string_pointer++), 10 * (i + 1) + (j + 1)));
        }
    }
    return dictionary;
}

void Encoder::EncodeMembers() {
    for (char& ch : m_input_sentence) {
        char CH = toupper(ch);
        if (m_keys.find(CH) != std::string::npos)
            m_output_sentence += std::to_string(m_secret_code[CH]);
        else if (ch == ' ')
            m_output_sentence += " ";
        else
            m_output_sentence += ch;

        m_output_sentence += " ";
    }
}

std::string Encoder::Encode(std::string sentence) {
    SetInputSentence(sentence);
    
    if (m_input_sentence != "")
        EncodeMembers();
    else
        m_output_sentence = "";

    return GetOutputSentence();
}

std::string Encoder::GetOutputSentence() {
    return m_output_sentence;
}

void Encoder::SetInputSentence(std::string sentence) {
    m_input_sentence = sentence;
}

Encoder::Encoder() {
    m_secret_code = GenerateSecretCode();
    m_input_sentence = "";
    m_output_sentence = "";
}