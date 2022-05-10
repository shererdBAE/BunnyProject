#include <iostream>
#include <list>
#include <unistd.h>
#include <conio.h>
#include <utility> 
#include <vector>

#include "../include/bunny.h"
#include "../include/unifuncs.h"

int main()
{
    char keyin;
    srand(time(NULL));
    bool alivebunnies = true; 

    bunny startbunnies[5] = {bunny(), bunny(), bunny(), bunny(), bunny()};
    for (int i=4; i>=1; i--) {
    for (int j=4; j>=5-i; j--)
    { if (startbunnies[j].getage() > startbunnies[j-1].getage() ) 
    {
        std::swap(startbunnies[j], startbunnies[j-1]);
    }
    }}
    
    std::list<bunny> mybunnies (std::begin(startbunnies), std::end(startbunnies));

    while (alivebunnies) 
    {
        int mumcolour[4] = {0, 0, 0, 0};
        bool istheredad = false;
        int infectedbunnies = 0;
        int numofdeadbunnies = 0;
        std::vector<std::string> deadbunnies;

        uni::newlines(1);
        std::list<bunny>::iterator it  = mybunnies.begin();

        while( it != mybunnies.end())
        {   
            //std::vector<std::string> deadbunnies;
            //if (it->getname() == "")
            //{int test = 0;}
            std::string isinfected;
            

            if (it->getradioactive()) isinfected = " infected";
            else isinfected = "";
            std::cout << it->getname() << ",    " << it->getage() << " yrs,    " 
            << it->getbunnycolourname() << " " << it->getbunnysexname() 
            << isinfected << std::endl;
 
            if (it->isfertilemale()) istheredad = true; //returns true if there is an uninfected male 2 or older
            if (it->isfertilefemale()) mumcolour[int (it->getbunnycolour())]++; //adds 1 to the colour of a fertile female
            if (it->getradioactive()) infectedbunnies++; //adds 1 to the number of infected bunnies

            it->age1year(); //ages the bunny

            if (it->getage() > 10 && it->getradioactive() == false){
                deadbunnies.push_back(it->getname());
                mybunnies.erase (it++);
                numofdeadbunnies++;
                ;}
            else if (it->getage() > 50 && it->getradioactive() == true){
                deadbunnies.push_back(it->getname());
                mybunnies.erase (it++);
                infectedbunnies--;
                numofdeadbunnies++; }
            else {it++;}
            
        }
//            mybunnies.remove_if (mybunnies.tooold());  
        
        if (istheredad){ //creates bunnies from birth
            for (int a = 0; a < 4; a++) {
                for (int b = 0; b < mumcolour[a]; b++) mybunnies.push_back(bunny(a));
            }
        }
        

        for (int i = 0; i<numofdeadbunnies; i++){
        std::cout << "Bunny " << deadbunnies[i] << " has died!" << std::endl;
        usleep(1000000);
        }

        if (mybunnies.begin() == mybunnies.end()) alivebunnies = false;

/*
        for ( std::list<bunny>::iterator it = mybunnies.begin(); it != mybunnies.end(); it++)
        {
            

        }
*/      
//         keyin = uni::waitforcharinput(2);
//         if (keyin == 'p') uni::cont();
//       else if (keyin == 'k') cull();


        usleep(2000000);
    } 



}
