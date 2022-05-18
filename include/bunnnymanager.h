#include "../include/bunny.h"
#include <list>
#include <vector>
#include <array>

class bunnymanager {

    const int numofstartbunnies = 5;
    const int maxage = 10;
    const int maxinfectedage = 50;
    const int maxbunnies = 60;

    std::array<int,4> mumcolour; //create counter of colours of mums and fill with 0

    int numofdeadbunnies = 0;
    int numberofinfected = 0;
    bool istheredad;
    int totalbunnies = 0;
    
    std::vector<std::string> deadbunnynames; //make vector to store dead bunny names
    std::list<bunny> mybunnies;

public:
    bunnymanager();

    std::list<bunny> initialisebunnylist();
    void printbunnies(std::list<bunny>);
    void ageallbunnies(std::list<bunny>&);
    bool isthereadad(std::list<bunny>);
    void setmumbirthdata(std::list<bunny>);
    void setnumberofinfected(std::list<bunny>);
    void birthbunnies(std::list<bunny>&);

    bool istooold(bunny&);
    void removeoldbunnies(std::list<bunny>&);
    std::list<bunny> keepalivebunnies(std::list<bunny>);

    int printdeadbunnynames();
    bool isendcondition(int, int);
    bool isculltime(int playoption, std::list<bunny>);
    void cull(std::list<bunny>&);
    void removetopbunny(std::list<bunny>&);
    void makeinfectedbunnies(std::list<bunny>&);

    int getnumofstartbunnies();
    int getinfectnumber();   
    void printmumcolurs();
    void printnumberofdeadbunnies();
    int gettotalbunnies(std::list<bunny>);

};