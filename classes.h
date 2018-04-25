#include <algorithm>
#include <random>


// Key class one for each position on the keyboard
class key{

    public:
    char charcter;
    int  startDist;
    key *adjList[4];
    int altdist[4];
    //...more maybe

};

//Keyboard class fo
class keyboard {
    // Access specifier
    public:
    //keyboard array 
    key board[32]; 
    double fitness;
    keyboard();

};
    
    //constructor
    keyboard::keyboard(){
        //array to be shuffled
        char to_shuffle[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 
        'w', 'x', 'y', 'z',' ',':','"','<','>','?'};
        std::random_shuffle(&to_shuffle[0],&to_shuffle[31]);

        //adding charcters  and distances to board
        for (int i = 0; i<32 ; i++){

            //setting charcters on board
            board[i].charcter = to_shuffle[i];

            //setting startDistances
            if (i <= 3 || (i >= 6 && i<= 9))
                board[i].startDist = 92;
            if (i == 4 || i == 10)
                board[i].startDist = 100;
            if (i == 5)
                board[i].startDist = 150;
            if ((i >= 11 && i <= 14) || (i >= 17 && i<= 20))
                board[i].startDist = 0;
            if ((i >= 15 && i <= 16) || (i == 21))
                board[i].startDist = 90;
            if ((i >= 22 && i <= 25) || (i >= 27 && i<= 31))
                board[i].startDist = 97;               
            if (i == 26)
                board[i].startDist = 155;

            //setting adj matrices and alt distances
            if (i == 3){
                board[i].adjList = {board[4],board[15],NULL,NULL};
                board[i].altdist = {90, 170, 1000, 1000};
            }
             if (i == 4){
                board[i].adjList = {board[3],board[15],NULL,NULL};
                board[i].altdist = {90, 92, 1000, 1000;
            }
             if (i ==5){
                board[i].adjList = {board[6],board[16],NULL,NULL};
                board[i].altdist = {90, 92, 1000, 1000};
            }
             if (i == 6){
                board[i].adjList = {board[5],board[16],NULL,NULL};
                board[i].altdist = {90, 150, 1000, 1000};
            }
             if (i == 15){
                board[i].adjList = {board[3],board[4],board[25],board[26]};
                board[i].altdist = {170, 92, 97, 97};
            }
             if (i == 16){
                board[i].adjList = {board[5],board[6],board[27]};
                board[i].altdist = {92, 150, 97, NULL};               
            }
             if (i == 25){
                board[i].adjList = {board[15],board[26], NULL, NULL};
                board[i].altdist = {97, 90};
            }
             if (i == 26){
                board[i].adjList = {board[15],board[25], NULL, NULL};
                board[i].altdist = {97, 90};
                                
            }
             if (i == 27){
                board[i].adjList = {board[16],board[26], NULL, NULL};
                board[i].altdist = {97, 90};
            }

        }
    }
};


// a class for fingers. We can store:
// (1)there position (what key they are on)
// (2)There strength
// (3)Times it has been used
// more...
class finger{

    public:
        key curPosition;
        int str;
        int pressCount;


    void setPos(key pos){
        curPosition = pos;
    }
    void keyTouch(){
        pressCount++;
    }

};

//all types of fingers inherate the finger class, and have different strengths. 
//(This is kinda bulky, but I don't know any other way to do it)
//Once we have a keyboard object we can make 2 of each call set position on each of them
// to the starting "asdfjkl;" position, and then start typing

class pinky : public finger{

    public:
        pinky();
};
pinky::pinky(){
    str = 1; 
    pressCount = 0;
}
class ring : public finger{
    public:
        ring();
};
ring::ring(){
    str = 2;
    pressCount = 0; 
}
class middle : public finger{
    public:
        middle();
};
middle::middle(){
    str = 4;
    pressCount = 0;
}
class index : public finger{
    public:
        index();
};
index::index(){
    str = 4;
    pressCount = 0;
}



//class that has all of the fingers
class hands{

    pinky rp;
    pinky lp;
    ring rr;
    ring lr;
    middle rm;
    middle lm;
    index ri;
    index li;


    // The constructor of hands requires a keyboard, to set positions on.
    hands(keyboard instance){

        //set position of finger by taking instance of keyboard object, getting board and then finding
        //spot in array.
        rp.setPos(instance.board[20])
        lp.setPos(instance.board[11])
        rr.setPos(instance.board[19])
        lr.setPos(instance.board[12])
        rm.setPos(instance.board[18])
        lm.setPos(instance.board[13])
        ri.setPos(instance.board[17])
        li.setPos(instance.board[14])
    }
};
