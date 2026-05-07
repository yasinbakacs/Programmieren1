#include <iostream>
#include <string>

class AudioFile
{
public:
    virtual void play() const //should be virtual
    {
        std::cout << "Playing generic audio file\n";
    }

    virtual void print_info() const
    {
        std::cout << "Generic audio file\n";
    }

    virtual ~AudioFile()  //should be virtual
    {
        std::cout << "AudioFile destroyed\n";
    }
};

class MP3File : public AudioFile
{
private:
    std::string artist;

public:
    MP3File(const std::string& artist_name)
        : artist(artist_name)
    {
    }

    void play() const override //override to check if implementation successful const missing
    {
        std::cout << "Playing MP3 by " << artist << "\n";
    }

    void print_info() const override //same as above
    {
        std::cout << "MP3 file by " << artist << "\n";
    }

    ~MP3File()  override //override, but destructor in derived class not necessary when base destructor is virtual
    {
        std::cout << "MP3File destroyed\n";
    }
};

class WAVFile : public AudioFile
{
public:
    void play() const override // override
    {
        std::cout << "Playing WAV file\n";
    }

    void print_info() const override // override
    {
        std::cout << "Uncompressed WAV file\n";
    }

    ~WAVFile() override
    {
        std::cout << "WAVFile destroyed\n";
    }
};

int main()
{
    constexpr int LISTSIZE = 2; 
    AudioFile* playlist[LISTSIZE]; //(magic Number)

    playlist[0] = new MP3File("Daft Punk");
    playlist[1] = new WAVFile();

    for (int index = 0; index < LISTSIZE; index++)
    {
        playlist[index]->print_info(); //output from Methods of parent class AudioFIle
        playlist[index]->play();
    }

    for (int index = 0; index < LISTSIZE; index++)
    {
        delete playlist[index];
    }

    return 0;
}