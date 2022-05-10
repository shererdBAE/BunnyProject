#include <string>
#include <iostream>

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
    bunny(int mumscolourcode);

    std::string getname();
    int getage();
    bool getradioactive();
    sex getbunnysex();
    colour getbunnycolour();

    std::string getbunnysexname();
    std::string getbunnycolourname();

    bool isfertilemale();
    bool isfertilefemale();

    void age1year();

    bool tooold();
};