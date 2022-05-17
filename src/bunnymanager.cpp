#include "../include/bunnnymanager.h"
#include <vector>
#include <memory>
#include <conio.h>


bunnymanager::bunnymanager(){}

void bunnymanager::initialisebunnylist()
{
    std::vector<bunny> startbunnies (numofstartbunnies);
    // startbunnies[5] = {bunny(), bunny(), bunny(), bunny(), bunny()}; //make 5 bunnies in array
    for (int i=4; i>=1; i--) {
        for (int j=4; j>=5-i; j--){
             if (startbunnies[j].getage() > startbunnies[j-1].getage() ) //sort bunnies by age starting from the back
    {
        std::swap(startbunnies[j], startbunnies[j-1]); //swap bunny if the bunny lower in list has a larger age
    }
    }}
    std::list<bunny> mybunnies (std::begin(startbunnies), std::end(startbunnies)); //move bunnies to a list
   
}

std::list<bunny> bunnymanager::initialisebunnylist1()
{
    std::vector<bunny> startbunnies (numofstartbunnies);
//    bunny startbunnies[5] = {bunny(), bunny(true), bunny(), bunny(), bunny()}; //manual bunny initilisation for starting with infected bunnies
    for (int i=4; i>=1; i--) {
        for (int j=4; j>=5-i; j--){
             if (startbunnies[j].getage() > startbunnies[j-1].getage() ) //sort bunnies by age starting from the back
    {
        std::swap(startbunnies[j], startbunnies[j-1]); //swap bunny if the bunny lower in list has a larger age
    }
    }}
    std::list<bunny> bunnylist (std::begin(startbunnies), std::end(startbunnies)); //move bunnies to a list
    return bunnylist;
}

void bunnymanager::printbunnies(std::list<bunny> bunnylist)
{
    std::cout << "There are " << bunnylist.size() << " alive bunnies" << std::endl << std::endl;

    for (bunny & thisbunny : bunnylist)
    {
    std::string isinfected; //reset infected message before checking if bunny is infected

    if (thisbunny.getinfected()) isinfected = " infected"; //if infected store infected to be printed with data
        else isinfected = "";
        std::cout << thisbunny.getname() << ",    " << thisbunny.getage() << " yrs,    " 
        << thisbunny.getbunnycolourname() << " " << thisbunny.getbunnysexname()  //print data 
        << isinfected << std::endl;

}
     std::cout << std::endl;
}

void bunnymanager::ageallbunnies(std::list<bunny> &bunnylist)
{
    for  (bunny & thisbunny : bunnylist){
        thisbunny.age1year(); }
}

bool bunnymanager::isthereadad(std::list<bunny> bunnylist)
{
    for  (bunny & thisbunny : bunnylist){
        if (thisbunny.isfertilemale()){
            return true; }//returns true if there is an uninfected male 2 or older
    }
    return false;
}
  
void bunnymanager::setmumbirthdata(std::list<bunny> bunnylist)
{   
    mumcolour.fill(0); //create counter or colours of mums
    for  (bunny & thisbunny : bunnylist){
        if (thisbunny.isfertilefemale()){
             mumcolour[int (thisbunny.getbunnycolour())]++; //adds 1 to the colour of a fertile female
        }
    } 
}
 



void bunnymanager::birthbunnies(std::list<bunny> &bunnylist)
{
    if (isthereadad(bunnylist)){ //creates bunnies from birth
            for (int a = 0; a < 4; a++) { //goes through colours and adds new bunny
                for (int b = 0; b < mumcolour[a]; b++){ 
                    bunnylist.push_back(bunny(a));
                    totalbunnies++;
                    }
            }
        }
    std::cout << std::endl;
}

bool bunnymanager::istooold(bunny &thisbunny)
{
    if ((thisbunny.getinfected() == false && thisbunny.getage() > maxage )
    || (thisbunny.getinfected() == true  && thisbunny.getage() > maxinfectedage)){
            numofdeadbunnies++;
            deadbunnynames.push_back(thisbunny.getname()); //remove bunny if normal and over 10 or infected and over 50       
        return true; }
    else return false;

}

void bunnymanager::removetopbunny(std::list<bunny> &bunnylist)
{
    bool i = false;
    for (bunny & thisbunny : bunnylist)
    {
        if (i) {
        bunnylist.pop_front(); 
        i = false;}
        if (istooold(thisbunny)) {
        i = true;
        }
            
    }
}

/*void bunnymanager::removedeadbunnies(std::list<bunny> &bunnylist)
{
    std::list<bunny>::iterator it;
    while( it != bunnylist.end()) //iterate till last bunny element
    {
        if (istooold(it){
            bunnylist.erase (it++);
        }
        else it++;
    }

}

/*void bunnymanager::removedeadbunnies(std::list<bunny> &bunnylist)
{
    bunnylist.remove_if (istooold);
}
*/




void bunnymanager::printdeadbunnynames()
{
    for (int i = 0; i<numofdeadbunnies; i++){ //for loop lasts as long as number of new dead bunnies
        std::cout << "Bunny " << deadbunnynames[i] << " has died!" << std::endl;//outputs dead bunnies
        deadbunnynames.erase(deadbunnynames.begin());
        usleep(1000000);
    } 
    numofdeadbunnies = 0;
    std::cout << std::endl;
}

bool bunnymanager::isendcondition()
{
      return mybunnies.begin() != mybunnies.end(); //if list is empty end
}

bool bunnymanager::isculltime(int playoption, std::list<bunny> bunnylist)
{
        if (playoption == 0) {
            if ( bunnylist.size() > maxbunnies){
                std::cout << "Over " << maxbunnies << " now alive, time to cull." << std::endl << std::endl; 
                return true;}
            else return false; 
        }
        else {
/*            std::cout << "Press K to cull." << std::endl; 
            float timer = 0;
            while (timer < 2)
            {
                if (_kbhit())
                {
                    char keypress = getch();
                    if (keypress == 'k' || keypress == 'K'){
                        return true;
                    }
                }
                usleep (100000);
                timer += 0.1;
            }
*/        return false;    
        }
}

void bunnymanager::cull(std::list<bunny> &bunnylist)
{
    std::list<bunny>::iterator it;
    int cullnum = bunnylist.size()/2;
    for (int i=0; i < cullnum; i++){
        int randombunny = rand() % bunnylist.size();
        it = bunnylist.begin();
        std::advance(it, randombunny);
        std::cout << "Bunny " << it->getname() << " has been culled!" << std::endl;//outputs dead bunnies
        bunnylist.erase(it);
    }
    std::cout << std::endl;
}

void bunnymanager::setnumberofinfected(std::list<bunny> bunnylist)
{   
    numberofinfected = 0;
    for  (bunny & thisbunny : bunnylist){
        if (thisbunny.getinfected()){
             numberofinfected++; //adds 1 to the number of infected bunnies             mumcolour[int (thisbunny.getbunnycolour())]++; //adds 1 to the colour of a fertile female
        }
    } 
//    return numberofinfected;
}

void bunnymanager::makeinfectedbunnies(std::list<bunny> &bunnylist)
{   
    int bunniesnotinfected = bunnylist.size() - numberofinfected;

    if (numberofinfected > bunniesnotinfected){
        for  (bunny & thisbunny : bunnylist){
            if (!thisbunny.getinfected()){
                thisbunny.makeradioactive();
            }
        } return;
    }    
    else {
        int toinfect = rand() % 2;
        while (numberofinfected != 0){
            for  (bunny & thisbunny : bunnylist){
                if (!thisbunny.getinfected()){
                    if (toinfect == 1){
                    thisbunny.makeradioactive();
                    toinfect=0;
                    numberofinfected--; 
                    std::cout << numberofinfected << "more bunnies to infect" <<std::endl;
                    if (numberofinfected == 0) {return;}
                    }
                    else { toinfect=1;} 
                }
            }
        } return;            
    }
}

int bunnymanager::getinfectnumber()
{
    return numberofinfected;
}

void bunnymanager::printmumcolurs()
{
      std::cout << "mumcolour contains:";
  for ( int& x : mumcolour) { std::cout << ' ' << x; }
    std::cout << std::endl;
}

void bunnymanager::printnumberofdeadbunnies()
{
    std::cout<< std::endl <<numofdeadbunnies << std::endl;
//    return numofdeadbunnies;
}

void bunnymanager::printtotalbunnies(std::list<bunny> bunnylist)
{
    std::cout<< std::endl << bunnylist.size() << std::endl;
//    return numofdeadbunnies;
}