#include "../include/bunnnymanager.h"
#include <vector>
#include <memory>
#include <conio.h>


bunnymanager::bunnymanager(){}

int bunnymanager::getnumofstartbunnies()
{
    return numofstartbunnies;
}

std::list<bunny> bunnymanager::initialisebunnylist()
{ 
    std::vector<bunny> startbunnies (numofstartbunnies);
//    bunny startbunnies[5] = {bunny(true), bunny(true), bunny(true), bunny(), bunny()}; //manual bunny initilisation for starting with infected bunnies
    for (int i=numofstartbunnies-1; i>=1; i--) {
        for (int j=numofstartbunnies-1; j>=numofstartbunnies-i; j--){
             if (startbunnies[j].getage() > startbunnies[j-1].getage() )//sort bunnies by age starting from the back
            {
                std::swap(startbunnies[j],  startbunnies[j-1]);                
            }
        }
    }
    std::list<bunny> bunnylist (std::begin(startbunnies), std::end(startbunnies)); //move bunnies to a list
    return bunnylist;
}

void bunnymanager::printbunnies(std::list<bunny> bunnylist)
{   
    int size = bunnylist.size();
    if (size > 1){
        std::cout << "There are " << size << " alive bunnies" << std::endl << std::endl; }
    else {std::cout << "There's only " << size << " bunny alive!" << std::endl;}
    
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
    if (isthereadad(bunnylist)){ //creates bunnies only if there is a dad
            for (int a = 0; a < 4; a++) { //goes through colours and adds new bunny
                for (int b = 0; b < mumcolour[a]; b++){ 
                    bunnylist.push_back(bunny(a));
                    totalbunnies++;
                    }
            }
    std::cout << std::endl;        
    }
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

std::list<bunny> bunnymanager::keepalivebunnies(std::list<bunny> bunnylist)
{
    std::list<bunny> newbunnylist;
    for (bunny & thisbunny : bunnylist){
        if (!istooold(thisbunny)){
            newbunnylist.push_back(thisbunny);    
        }    
    }
    return newbunnylist;
}

int bunnymanager::printdeadbunnynames()
{
    if (numofdeadbunnies>0){    
        for (int i = 0; i<numofdeadbunnies; i++){ //for loop lasts as long as number of new dead bunnies
            std::cout << "Bunny " << deadbunnynames[0] << " has died!" << std::endl;//outputs dead bunnies
            deadbunnynames.erase(deadbunnynames.begin());
            usleep(1000000);
        }
    int deadbunniesprinted = numofdeadbunnies;     
    numofdeadbunnies = 0;
    std::cout << std::endl;    
    return deadbunniesprinted;
}
    return 0;
}

bool bunnymanager::isendcondition(int killedbuns, int alivebuns)
{   
    return alivebuns !=  killedbuns;//if list is empty end
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
            std::cout << "Press K to cull." << std::endl; 
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
        return false;    
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
}

int bunnymanager::gettotalbunnies(std::list<bunny> bunnylist)
{
    return bunnylist.size();
}