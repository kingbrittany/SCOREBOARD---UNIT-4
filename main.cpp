//Programmer: Brittany King
//Class: COSC 1427-58112
//Date: April 23, 2021
//Professor: Dr. T. McMillian

#include <iostream>
#include <string> 
#include <unistd.h>
#include "Input_Validation_Extended.h"
using namespace std; 

class Team 
{
  private:
    int score; 
    bool homeStatus; 
    string name; 
    int quarter; 
    int downs;
    string coachName; 
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        name = "DefaultTeamName"; 
        quarter = 0; 
        coachName = "DefaultCoachName"; 
        downs = 0;
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setName(string n) { name = n; }
      void setQuarter(int qtr) { quarter = qtr; }
      void setDowns(int dwn) { downs = dwn; }
      void setCoachName(string sCN) { coachName = sCN; }
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getName() const { return name; }
      int getQuarter() const { return quarter; }
      int getDowns() const { return downs; }
      string getCoachName() const { return coachName; }
};

class Scoreboard
{
  private:
    int half; 
    int time; 
    int quarter;
    int downs;
    Team home; //object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    void setQuarter(int q) { quarter = q; }
    void setDowns(int d) { downs = d;}
    int getHalf() const { return half; }
    int getTime() const {return time; }
    int getQuarter() const {return quarter;}
    int getDowns() const {return downs;}
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[36;1m"; //score color 
      cout << color << "Football Scoreboard" << reset << endl; 
      cout << home.getName() << "\t\t" << visitor.getName() << endl; 
      cout << "\t" << score << home.getScore() << reset << "\t\t\t\t\t\t" << visitor.getScore() << endl; 
      cout << "\t" << downs << home.getDowns() << reset << "\t\t\t\t\t\t" << visitor.getDowns() << endl; 
      cout << score << home.getCoachName() << reset << "\t\t" << visitor.getCoachName() << endl;
      for(int i = 0; i < 47; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << "Home> \t"; 
       if(home.getHomeStatus() == true)
       {
         cout << "Team 1: " << home.getName() << "*"; 
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Team 2: " << visitor.getName() << "*"; 
       }
       else
       {
         cout << "Error: "; 
       }
       
       cout  << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName = ""; 
  string userChoice = ""; 
  string newCoachName = ""; 
  int homeTeamQuestion = 0; 
  int newScore = 0; 
  int quarter = 0;
  int downs = 0;

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Coach Name" << endl; 
      cout << "C = Update Home Team Score" << endl; 
      cout << "D = Update Home Team Status" << endl; 
      cout << "E = Update Visiting Team Name" << endl;
      cout << "F = Update Visiting Team Coach Name" << endl;
      cout << "G = Update Visiting Team Score" << endl;
      cout << "Z = Exit" << endl;
      cout << ">"; 
      userChoice = validateString(userChoice);
      //cin >> userChoice; 

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team name module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        newName = validateString(newName);
        //cin >> newName; 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
          cout << "\nUpdate Home Coach name Module****" << endl; 
          cout << "\nPlease enter the home coach Name: ";newCoachName = validateString(newCoachName); 
          //cin >> newCoachName; 
          tOne.setCoachName(newCoachName); 
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        newScore = validateInt(newScore);
        //cin >> newScore; 
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "D" || userChoice == "d")
      {
        cout << "\nUpdate Home Status Module****" << endl; 
        cout << "\nWho is the home team: 1 = T1, 2=T2: "; 
        homeTeamQuestion = validateInt(homeTeamQuestion); 
       // cin >> homeTeamQuestion; 
        if(homeTeamQuestion == 1)
        {
          tOne.setHomeStatus(true); 
          tTwo.setHomeStatus(false); 
        }
        else if(homeTeamQuestion == 2)
        {
          tOne.setHomeStatus(false); 
          tTwo.setHomeStatus(true);
        }
        else
        {
          cout << "\nInvalid Input!" << endl;
          sleep(2); 
        }
      }
      if(userChoice == "E" || userChoice == "e")
      {
        //Dr_T challenge Accept a new name for s's Visiting team
        cout << "****Update Visiting Team Name module*** " << endl; 
        cout << "\nPlease enter a new name for the visiting team: ";
        newName = validateString(newName);
        //cin >> newName; 
        //change that visiting team's default name
        tTwo.setName(newName); //set tTwo's data to the new desired name
        }
        else if(userChoice == "F" || userChoice == "f")
      {
          cout << "\nUpdate Visitor Coach Module****" << endl; 
          cout << "\nPlease enter the visitor coach Name: ";newCoachName = validateString(newCoachName); 
          //cin >> newCoachName; 
          tTwo.setCoachName(newCoachName); 
      }
      else if(userChoice == "G" || userChoice == "g")
      {
        cout << "\nUpdate Visting Team Score****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        newScore = validateInt(newScore);
        //cin >> newScore; 
        tTwo.setScore(newScore);  //set the new score for tOne        
      }
      
      else if(userChoice == "Z" || userChoice == "z")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }
      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo); //refresh the data
  
  }while(userChoice != "Z" && userChoice != "z");


  return 0; 
}