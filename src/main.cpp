#include <iostream>
#include <list>
#include <unistd.h>
#include <conio.h>
#include <utility> 
#include <vector>
#include <memory>

#include "../include/bunnnymanager.h"
#include "../include/unifuncs.h"

int main()
{
    int playoption = 0;
    srand(time(NULL)); //set seed to null to initialise time functions
    bool alivebunnies = true; 
/*    bool cull = false, cullthis = false;
    int whencull; 
*/
   
    bunnymanager bunnyman;
//    bunnyman.initialisebunnylist();


/*    bunny startbunnies[5] = {bunny(), bunny(), bunny(), bunny(), bunny()}; //make 5 bunnies in array
    for (int i=4; i>=1; i--) {
    for (int j=4; j>=5-i; j--)
    { if (startbunnies[j].getage() > startbunnies[j-1].getage() ) //sort bunnies by age starting from the back
    {
        std::swap(startbunnies[j], startbunnies[j-1]); //swap bunny if the bunny lower in list has a larger age
    }
    }}
    std::list<bunny> mybunnies (std::begin(startbunnies), std::end(startbunnies)); //move bunnies to a list
*/
    std::list<bunny> mybunnies = bunnyman.initialisebunnylist1();

/*    std::cout << "Would you like auto(0) or manual cull(1) mode? \n"; //pick between havin
    playoption = uni::checkrange(0, 1);
*/    
//    int infectedbunnies = 0; //set number of infected bunnies to 0 before checking
    while (alivebunnies) 
    {
        bunnyman.printbunnies(mybunnies);
/*  for (bunny & thisbunny : mybunnies)
    {
    std::string isinfected; //reset infected message before checking if bunny is infected

    if (thisbunny.getinfected()) isinfected = " infected"; //if infected store infected to be printed with data
        else isinfected = "";
        std::cout << thisbunny.getname() << ",    " << thisbunny.getage() << " yrs,    " 
        << thisbunny.getbunnycolourname() << " " << thisbunny.getbunnysexname()  //print data 
        << isinfected << std::endl;
    }
*/    
 //   while (alivebunnies) 
 //   {


//        int mumcolour[4] = {0, 0, 0, 0}; //create counter or colours of mums
//        bool istheredad = false; //set dad to false before checking
//        int numofdeadbunnies = 0; //set number of dead bunnies to 0 before checking
//        int totalbunnies = 0; //set total bunnies in list to 0 before checking
//        std::vector<std::string> deadbunnies; //make vector to store dead bunny names
//        int infectedbunnies = 0;
//        std::cout<< std::endl; //make newline

    


 /*        std::list<bunny>::iterator it  = mybunnies.begin(); //make iterator and start to start element
        while( it != mybunnies.end()) //iterate till last bunny element
        {   
  
/*          if (cull && cullthis) { //if cull is true(more than 1000 bunnies) and whencull is 1 (randomly 1 or 0) kill bunny then skip next
                deadbunnies.push_back(thisbunny.getname()); //remove bunny
                mybunnies.erase (it++); //iterate and then continue as normal, now every othe bunny will be targeted 
                numofdeadbunnies++; //add 1 to bunnies that have been killed
            }
            

            totalbunnies++; //add 1 to total number of bunnies in list
            std::string isinfected; //reset infected message before checking if bunny is infected
            
//            std::cout << totalbunnies << " " << infectedbunnies;
            if (it->getinfected()) isinfected = " infected"; //if infected store infected to be printed with data
            else isinfected = "";
            std::cout << it->getname() << ",    " << it->getage() << " yrs,    " 
            << it->getbunnycolourname() << " " << it->getbunnysexname()  //print data 
            << isinfected << std::endl;
            it++;
        }
 */ 
          
//            bunnyman.isthereadad(mybunnies);
            bunnyman.setmumbirthdata(mybunnies);
/*
*/
//            if (it->isfertilemale()) istheredad = true; //returns true if there is an uninfected male 2 or older
//            if (it->isfertilefemale()) mumcolour[int (it->getbunnycolour())]++; //adds 1 to the colour of a fertile female
//            if (it->getinfected()) infectedbunnies++; //adds 1 to the number of infected bunnies
            

            bunnyman.ageallbunnies(mybunnies);            
//            it->age1year(); //ages the bunny
/*            bool i = false;
            for (bunny & thisbunny : mybunnies)
    {
            if (i) {
            mybunnies.pop_front(); 
            i = false;}
            if (bunnyman.istooold(thisbunny)) {
            i = true;
            }
    }*/
            bunnyman.removetopbunny(mybunnies);
//            bunnyman.removedeadbunnies(mybunnies);//checks if too old and removes if so

/*          if (it->getage() > 10 && it->getinfected() == false){
                deadbunnies.push_back(it->getname()); //remove bunny if normal and over 10
                mybunnies.erase (it++);
                numofdeadbunnies++; //add 1 to bunnies that have been killed
                ;}
            else if (it->getage() > 50 && it->getinfected() == true){
                deadbunnies.push_back(it->getname()); //remove bunny if infected and over 50
                mybunnies.erase (it++);
                infectedbunnies--;  //take 1 away from number of nfected bunnies as it has been killed
                numofdeadbunnies++; } //add 1 to bunnies that have been killed
            else {it++;}
*/            
    //        !cullthis;
    //    }
    //    cull = false;
            bunnyman.setnumberofinfected(mybunnies);        
//            mybunnies.remove_if (mybunnies.tooold());  
            bunnyman.birthbunnies(mybunnies);

/*        if (istheredad){ //creates bunnies from birth
            for (int a = 0; a < 4; a++) { //goes through colours and adds new bunny
                for (int b = 0; b < mumcolour[a]; b++){ mybunnies.push_back(bunny(a));
                totalbunnies++;}
            }
        }
*/
            bunnyman.printdeadbunnynames();


            
            if (bunnyman.getinfectnumber() > 0 && bunnyman.getinfectnumber() != mybunnies.size() ){
            bunnyman.makeinfectedbunnies(mybunnies);
            }


//            bunnyman.printtotalbunnies(mybunnies);

/*        for (int i = 0; i<numofdeadbunnies; i++){ //for loop lasts as long as number of new dead bunnies
        std::cout << "Bunny " << deadbunnies[i] << " has died!" << std::endl;//outputs dead bunnies
        usleep(1000000);
        }
*/
//         alivebunnies = bunnyman.isendcondition();
//       if (mybunnies.begin() == mybunnies.end()) alivebunnies = false; //if list is empty end

//        int numofbunniesalive = totalbunnies - numofdeadbunnies;
//        int bunnniestoinfect[numberofinfected];
//        int bunnycheck = 0;

        if (bunnyman.isculltime(playoption, mybunnies)){
            bunnyman.cull(mybunnies);
        }
        
/*        if (numofbunniesalive > 100 && playoption == 0) {
            cull = true;
            whencull = rand() % 2;
            if (whencull == 1) cullthis = false;
        }
*/
//        std::list<bunny>::iterator it  = mybunnies.begin(); //iterate through bunnies


//        for (int i=0; i<infectedbunnies; i++){    bunnniestoinfect[infectedbunnies] = rand() % numofbunniesalive;
         //assign a random number betwween 0 and the number of bunnies alive
//    alivebunnies = false;
        usleep(1000000);
    }

/*        while (infectedbunnies>0 && totalbunnies >0)// && infectedbunnies != totalbunnies)
        {
            advance (it, rand() % 5 );
            if (it2->getinfected() == false){
                it2->makeradioactive();   //when iterator reaches random value and bunny hasnt been infected, bunny is infected
                infectedbunnies--;
            }
            if (it == mybunnies.end()) it = mybunnies.begin();
            totalbunnies--;
        }

       
 /*       while( it2 != mybunnies.end())
        {
            for (int i=0; i<infectedbunnies; i++){ //check array of dead bunnies
                        std::cout << bunnycheck; 
            if (bunnycheck == bunnniestoinfect[infectedbunnies] && it2->getinfected() == false) it2->makeradioactive();   //when iterator reaches random value and bunny hasnt been infected, bunny is infected
            else if (bunnycheck == bunnniestoinfect[infectedbunnies] && it2->getinfected() == true) bunnniestoinfect[infectedbunnies]++;   //when iterator reaches random value and bunny is infected, a bunny later in the list is infected           
        }              
            bunnycheck++; //bunny to be checked is iterated
            it2++;
        }

*/
/*        if (playoption == 0) usleep(2000000); //if automode is selcted wait 2 seconds
        else { std::cout << "\n\nEnter K for cull or anything else to continue ";
        std::cin >> keyin;       //if cull mode is selected enter K to cull or anything else to progress
        if (keyin == 'K') { cull=true;
        whencull = rand() % 2;
        if (whencull == 1) cullthis = true;
        
        }
        
    }
*/    
return 0;
}
