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

    bunnymanager bunnyman;
    
    int alivebunnies = bunnyman.getnumofstartbunnies(); 
    std::list<bunny> mybunnies = bunnyman.initialisebunnylist();

    int infectedbunnies = 0; //set number of infected bunnies to 0 before checking
    while (alivebunnies) 
    {
        bunnyman.printbunnies(mybunnies);

        bunnyman.setmumbirthdata(mybunnies);

        bunnyman.ageallbunnies(mybunnies);            

        alivebunnies = mybunnies.size();
        
        mybunnies = bunnyman.keepalivebunnies(mybunnies);//checks if too old and removes if so

        bunnyman.setnumberofinfected(mybunnies);

        if (bunnyman.getinfectnumber() > 0 && bunnyman.getinfectnumber() != mybunnies.size() ){
        bunnyman.makeinfectedbunnies(mybunnies);
        }        
        
        bunnyman.birthbunnies(mybunnies);
         
        int bunnieskilled = bunnyman.printdeadbunnynames();
        
        alivebunnies = bunnyman.isendcondition(bunnieskilled, alivebunnies);

        if (bunnyman.isculltime(playoption, mybunnies)){
            bunnyman.cull(mybunnies);
        }
        usleep(1000000);
    }   
return 0;
}
