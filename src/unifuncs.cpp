#include "../include/unifuncs.h"
#include <unistd.h>
#include <conio.h>

#undef max

int uni::checknum(){
    int i;
    while(!(std::cin >> i))
    {
        std::cout << "Incorrect data type. Please enter an integer" << std::endl;
        std::cout << std::endl;
        
        uni::buffclear();
    }    
    return i;
}

int uni::checkrange(int min, int max){
    int i;
    i = uni::checknum();
    while(!(i >= min && i <= max))//check if int is between min and max, if not, run code below 
    {
    
        std::cout << "Number must be between " << min << " and " << max << std::endl;
        std::cout << "Please try again" << std::endl;

        i = uni::checknum();
    }        
    buffclear();
    std::cout << std::endl;

    return i;
}

int uni::checkpositive(){

    int i;
    i = uni::checknum();
    while(!(i < 0))//check if int is positve, if not, run code below 
    {
     
        std::cout << "Number must be greater than 0" << std::endl;
        std::cout << "Please try again" << std::endl;
          
        i = uni::checknum();
    }    
    return i;
}

void uni::cont(){
    char c;
    usleep(1000000);
    uni::buffclear();
    std::cout <<"\n\nEnter any key to continue\n";
    std::cin >> c; 
}

std::string uni::firstwordin()
{
    std::string word;
    uni::buffclear();
    std::getline (std::cin, word);
    return word.substr(0, word.find(' '));
}

std::string uni::getline (){
    std::string line;
    uni::buffclear();
    std::getline (std::cin, line);
    return line;
} 

void uni::buffclear(){
    std::cin.clear();
    std::cin.ignore();
}

std::string uni::reverse_string (std::string str){      
    int num = str.length();      
    for (int i=0; i<num/2; i++ ) 
    { std::swap(str[i],str[num-1-i]); }
    return str;   
}

std::string uni::reverse_string (){   
    std::string str;
    uni::buffclear();
    std::cin >> str;
    int num = str.length();      
    for (int i=0; i<num/2; i++ ) 
    { std::swap(str[i],str[num-1-i]); }
    return str;;  
}

void uni::newlines(int lines){
    for (int a = 0; a < lines; a++ ) std::cout << std::endl;
}

char uni::waitforcharinput(int seconds) {
    char c = '1';
    while (seconds != 0) {
        if (kbhit()) {
            c = getch();
            break;
        }
        usleep(1000);
        --seconds;

    }

    return c;

}