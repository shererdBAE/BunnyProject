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
    srand(time(NULL)); //set seed to null to initialise time functions
    bool alivebunnies = true; 

    bunny startbunnies[5] = {bunny(), bunny(), bunny(), bunny(), bunny()}; //make 5 bunnies in array
    for (int i=4; i>=1; i--) {
    for (int j=4; j>=5-i; j--)
    { if (startbunnies[j].getage() > startbunnies[j-1].getage() ) //sort bunnies by age starting from the back
    {
        std::swap(startbunnies[j], startbunnies[j-1]); //swap bunny if the bunny lower in list has a larger age
    }
    }}
    
    std::list<bunny> mybunnies (std::begin(startbunnies), std::end(startbunnies)); //move bunnies to a list

    while (alivebunnies) 
    {
        int mumcolour[4] = {0, 0, 0, 0}; //create counter for colours of mums
        bool istheredad = false; //set dad to false before checking
        int infectedbunnies = 0; //set number of infected bunnies to 0 before checking
        int numofdeadbunnies = 0; //set number of dead bunnies to 0 before checking
        int totalbunnies = 0; //set total bunnies in list to 0 before checking
        std::vector<std::string> deadbunnies; //make vector to store dead bunny names

        std::cout<< std::endl; //make newline
        std::list<bunny>::iterator it  = mybunnies.begin(); //make iterator and start to start element

        while( it != mybunnies.end()) //iterate till last bunny element
        {   
            std::string isinfected; //reset infected message before checking if bunny is infected
            totalbunnies++; //add 1 to total number of bunnies in list
            

            if (it->getradioactive()) isinfected = " infected"; //if infected store infected to be printed with data
            else isinfected = "";
            std::cout << it->getname() << ",    " << it->getage() << " yrs,    " 
            << it->getbunnycolourname() << " " << it->getbunnysexname()  //print data 
            << isinfected << std::endl;
 
            if (it->isfertilemale()) istheredad = true; //returns true if there is an uninfected male 2 or older
            if (it->isfertilefemale()) mumcolour[int (it->getbunnycolour())]++; //adds 1 to the colour of a fertile female
            if (it->getradioactive()) infectedbunnies++; //adds 1 to the number of infected bunnies
            

            it->age1year(); //ages the bunny

            if (it->getage() > 10 && it->getradioactive() == false){
                deadbunnies.push_back(it->getname()); //remove bunny if normal and over 10
                mybunnies.erase (it++);
                numofdeadbunnies++; //add 1 to bunnies that have been killed
                ;}
            else if (it->getage() > 50 && it->getradioactive() == true){
                deadbunnies.push_back(it->getname()); //remove bunny if infected and over 50
                mybunnies.erase (it++);
                infectedbunnies--;  //take 1 away from number of nfected bunnies as it has been killed
                numofdeadbunnies++; } //add 1 to bunnies that have been killed
            else {it++;}
            
        }
//            mybunnies.remove_if (mybunnies.tooold());  
        
        if (istheredad){ //creates bunnies from birth
            for (int a = 0; a < 4; a++) { //goes through colours and adds new bunny
                for (int b = 0; b < mumcolour[a]; b++) mybunnies.push_back(bunny(a));
            }
        }
        

        for (int i = 0; i<numofdeadbunnies; i++){ //for loop lasts as long as number of new dead bunnies
        std::cout << "Bunny " << deadbunnies[i] << " has died!" << std::endl;//outputs dead bunnies
        usleep(1000000);
        }

        if (mybunnies.begin() == mybunnies.end()) alivebunnies = false; //if list is empty end

        int numofbunniesalive = totalbunnies - numofdeadbunnies;
        int bunnniestoinfect[infectedbunnies];
        int bunnycheck = 0;
        

        for (int i=0; i<infectedbunnies; i++){    bunnniestoinfect[infectedbunnies]=rand() % numofbunniesalive;
        } //assign a random number betwween 0 and the number of bunnies alive

        std::list<bunny>::iterator it2  = mybunnies.begin(); //iterate through bunnies
        while( it2 != mybunnies.end())
        {
            for (int i=0; i<infectedbunnies; i++){ //check array of dead bunnies
            if (bunnycheck == bunnniestoinfect[infectedbunnies]) it->makeradioactive();
        }                             //when iterator reaches random value, bunny is infected
            bunnycheck++;
            it2++;
        }

   
        //  keyin = uni::waitforcharinput(2);
//         if (keyin == 'p') uni::cont();
//       else if (keyin == 'k') cull();
      


        usleep(2000000);
    } 



}
