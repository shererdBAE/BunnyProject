#include <string>
#include <iostream>
#include <unistd.h>

class bunny
{   
    enum class sex {
        Male,
        Female
    }; 
    sex bunnysex;
    enum class colour {
        white,
        brown,
        black,
        spotted
    };
    colour bunnycolour;
    int age;
    std::string name;
    bool infected;


    public:

    bunny();
    bunny(bool);
    bunny(int mumscolourcode);

    std::string getname();
    int getage();
    bool getinfected();
    sex getbunnysex();
    colour getbunnycolour();

    std::string getbunnysexname();
    std::string getbunnycolourname();

    bool isfertilemale();
    bool isfertilefemale();

    void age1year();
    void makeradioactive();
    bool tooold();
};