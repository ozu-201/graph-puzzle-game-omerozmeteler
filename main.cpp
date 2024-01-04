//
// Created by oo024999 on 12/21/2023.
//
#include <iostream>
#include <fstream>
#include <string>
#include "src/Array/Graph/Graph.h"
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool differByOne(string& word1, string& word2){ //METHOD THAT CHECKS IF 2 STRINGS ONLY DIFFER BY ONE.
    int diffCount = 0;
    for(int i = 0; i < word1.length();i++){
        if(word1[i] != word2[i]){
            diffCount++;
        }
    }
    if(diffCount == 1){
        return true;
    }else{
        return false;
    }
}

int main(){
    string number;
    cout << "How many letters does your words have? (VALID INPUTS ARE (three) (four) (five))" << endl; //TAKE INPUT AS TO SEE HOW MANY LETTERS DOES THE START AND TARGET WORD HAVE.
    getline(cin,number); //VALID INPUTS ARE "three" "four" "five".
    if(number == "three"){  //CASE FOR "three".
        cout << "Enter Starting Word: " << endl;
        string start3;
        string target3;
        getline(cin,start3);
        cout << "Enter Target Word: " << endl;
        getline(cin,target3);   //TAKE THE START AND TARGET WORD AS INPUTS.
        std::vector<string> threeLetter;
        std::ifstream newFile ("../english_dictionary"); //PRESET AS ENGLISH DICTIONARY.
        if(newFile.is_open()){ //READ THE FILE.
            std::string tmp;
            while(getline(newFile,tmp)){
                if(tmp.length() == 3){ //PUT THE THREE LETTER WORDS INTO THE VECTOR.
                    threeLetter.push_back(tmp);
                }
            }
        }
        array::Graph graph3 = array::Graph(threeLetter.size()); //CREATE THE GRAPH.
        for(int i = 0; i < threeLetter.size() ; i++){
            for(int j = i + 1; j < threeLetter.size();j++){
                if(differByOne(threeLetter[i],threeLetter[j])){ //ADD THE NECESSARY EDGES.
                    graph3.addEdge(i,j);
                    graph3.addEdge(j,i);
                }
            }
        }
        graph3.search(threeLetter,start3,target3); //START SEARCH



    }else if(number == "four"){ //CASE FOR "four".
        cout << "Enter Starting Word: " << endl;
        string start4;
        string target4;
        getline(cin,start4);
        cout << "Enter Target Word: " << endl;
        getline(cin,target4); //TAKE THE START AND TARGET WORD AS INPUTS.
        std::vector<string> fourLetter;
        std::ifstream newFile ("../english_dictionary"); //PRESET AS ENGLISH DICTIONARY.
        if(newFile.is_open()){
            std::string tmp;
            while(getline(newFile,tmp)){
                if(tmp.length() == 4){ //PUT THE FOUR LETTER WORDS INTO THE VECTOR.
                    fourLetter.push_back(tmp);
                }
            }
        }
        array::Graph graph4 = array::Graph(fourLetter.size()); //CREATE THE GRAPH.
        for(int i = 0; i < fourLetter.size() ; i++){
            for(int j = i + 1; j < fourLetter.size();j++){
                if(differByOne(fourLetter[i],fourLetter[j])){ //ADD THE NECESSARY EDGES.
                    graph4.addEdge(i,j);
                    graph4.addEdge(j,i);
                }
            }
        }
        graph4.search(fourLetter,start4,target4); //START SEARCH



    }else if(number == "five"){
        cout << "Enter Starting Word: " << endl;
        string start5;
        string target5;
        getline(cin,start5);
        cout << "Enter Target Word: " << endl;
        getline(cin,target5); //TAKE THE START AND TARGET WORD AS INPUTS.
        std::vector<string> fiveLetter;
        std::ifstream newFile ("../english_dictionary"); //PRESET AS ENGLISH DICTIONARY.
        if(newFile.is_open()){
            std::string tmp;
            while(getline(newFile,tmp)){
                if(tmp.length() == 5){ //PUT THE FIVE LETTER WORDS INTO THE VECTOR.
                    fiveLetter.push_back(tmp);
                }
            }
        }
        array::Graph graph5 = array::Graph(fiveLetter.size()); //CREATE THE GRAPH.
        for(int i = 0; i < fiveLetter.size() ; i++){
            for(int j = i + 1; j < fiveLetter.size();j++){
                if(differByOne(fiveLetter[i],fiveLetter[j])){ //ADD THE NECESSARY EDGES.
                    graph5.addEdge(i,j);
                    graph5.addEdge(j,i);
                }
            }
        }
        graph5.search(fiveLetter,start5,target5); //START SEARCH

    }else{
        cout << "Wrong Input" << endl;
    }

    return 0;
}
