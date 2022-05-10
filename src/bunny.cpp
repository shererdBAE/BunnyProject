#include "../include/bunny.h"
#include "../include/names.h"

#include <stdlib.h>
#include <unistd.h>

bunny::bunny()
{
    bunnysex = sex (rand() % 2 );
    bunnycolour = colour (rand() % 4 );
    age = rand() % 9 + 0 ; 
    if (bunnysex == sex::Male) name = maleBunnyNames[rand() % 1000];
    else name = femaleBunnyNames[rand() % 1000];
    if (rand() % 50 == 0) infected = true;
    else infected = false;

}

bunny::bunny(int mumscolourcode)
{
    bunnysex = sex (rand() % 2 );
    bunnycolour = colour (mumscolourcode);
    age = 0;
    if (bunnysex == sex::Male) name = maleBunnyNames[rand() % 999 + 0];
    else name = femaleBunnyNames[rand() % 999 + 0];
    if (rand() % 50 == 0) { infected = true; std::cout << "Infected "; }
    else infected = false;
    std::cout << "Bunny " << name << " was born!" << std::endl;

    usleep(1000000);
}

std::string bunny::getbunnysexname()     
{
    switch (bunnysex)
    {
    case sex::Male: 
        return "Male";

    case sex::Female: 
        return "Female";
    }
return "";
}

std::string bunny::getbunnycolourname()     
{
    switch (bunnycolour)
    {
    case colour::white: 
        return "White";

    case colour::brown: 
        return "Brown";
        
    case colour::black: 
        return "Black";   

    case colour::spotted: 
        return "Spotted";          
    
    }
return "";
}

std::string bunny::getname(){   return name;      }

int bunny::getage(){    return age;     }

bool bunny::getradioactive(){     return infected;    }

bunny::sex bunny::getbunnysex(){    return bunnysex;     }

bunny::colour bunny::getbunnycolour(){    return bunnycolour;   }

bool bunny::isfertilemale()
{
    if (bunnysex == bunny::sex::Male && age > 1 && infected == false ) return true;
    else return false;
}

bool bunny::isfertilefemale()
{
    if (bunnysex == bunny::sex::Female && age > 1 && infected == false ) return true;
    else return false;
}

void bunny::age1year()
{
    age++;
}

bool bunny::tooold()
{
    if (getage() > 50 && getradioactive()) return true;
    else if (getage() > 10 && !getradioactive()) return true;
    else return false;
}