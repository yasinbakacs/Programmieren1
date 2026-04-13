#include <iostream>
#include <cstdint>
#include <string>


class Note{
    private:
    std::string* text;

    public:

    Note(std::string text_input){
        text = new std::string;
        *text = text_input;
    }


}
