#include <iostream>
#include <cstdint>
#include <string>


class Note{
    private:
    std::string* text;

    public:

    Note(std::string input){
        text = new std::string;
        *text = input;
    }

    Note(const Note &otherNote){
        text = new std::string;
        *text = *otherNote.text;
    }

    ~Note(){
        delete text;
        text = nullptr;
        std::cout << "Memory released. \n";
    }

    void display();

};


void Note::display(){
    std::cout << *text << std::endl;
}

int main(){

    Note text1("Hallo was geht");
    text1.display();

    Note text2(text1);
    text2.display();

    return 0;
}