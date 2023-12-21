//
// Created by oo024999 on 12/21/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include "src/List/Graph/Graph.h"
#include "src/List/LinkedList.h"
#include "src/List/Node.h"
using namespace std;

int main(){
    //list::Graph graph = list::Graph(100000);
    LinkedList threeList = LinkedList();
    LinkedList fourList = LinkedList();
    LinkedList fiveList = LinkedList();
    int threeLetter = 0;
    int fourLetter = 0;
    int fiveLetter = 0;
    std::ifstream newFile ("C:\\Users\\TEMP\\CLionProjects\\graph-puzzle-game-omerozmeteler\\turkish_dictionary");
    if(newFile.is_open()){
        std::string tmp;
        while(getline(newFile,tmp)){
            if(tmp.length() == 3){
                threeLetter++;
            }else if(tmp.length() == 4){
                fourLetter++;
            }else if(tmp.length() == 5){
                fiveLetter++;
            }
        }
    }
    list::Graph graph3 = list::Graph(threeLetter);
    list::Graph graph4 = list::Graph(fourLetter);
    list::Graph graph5 = list::Graph(fiveLetter);



    cout << "Hello";








    return 0;
}
