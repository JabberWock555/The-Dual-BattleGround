#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

//---------------------Base Player 
class Player{
private:
int Health;
int BaseDamage;
int TotalDamage;
int HealCapacity;
int ExtraDamage;
int MaxHealth;

public:
//-------------------RandomNo.
int Randno (int min, int max){
  int Randno = min+(rand() % max);
  return Randno;
}

Player(int _Health, int _BaseDamage){
  Health = _Health;
  MaxHealth = _Health;
  BaseDamage = _BaseDamage;
}

//-------------------Getter

virtual int Get_Health() { return Health;}
virtual int Get_TotalDamage()= 0;
virtual int Get_HealCapacity()= 0;
int Get_BaseDamage() {return BaseDamage;}
int Get_ExtraDamage(){
  ExtraDamage = Get_TotalDamage() - BaseDamage;
  return ExtraDamage;
  }

//-------------------Setter

void Set_Health(int x){
  Health += x;
}

void Heal(int x){
  if (Health < MaxHealth){
  Health += x;
    if(Health > MaxHealth){
    Health = MaxHealth;
      }
    }
}
void Damage(int x){
  Health = Health - x;
}


};


//----------------------PlayerTypes
class KingLion: public Player
{
public:
KingLion(int _Health, int _BaseDamage):Player(_Health, _BaseDamage)
{
  cout<<"\n You Choose THE LION KING!!!!\n";
  cout<<"The leader of the pride, the Lion King is a fierce and majestic fighter. With his sharp claws and powerful roar, he dominates the battlefield and inspires fear in his enemies."<<endl;
  
  cout<<"Health : 100 HP "<<endl;
  cout<<"Base Damage : 20 HP"<<endl;
  cout<<"Special Damage : 15 - 20 HP "<<endl;
  cout<<"Healing Power : 5 - 10 HP"<<endl;
}
private: 

int TotalDamage;
int HealCapacity = Randno(5,5);


public :

//-------------------Getter

int Get_TotalDamage(){
  int Damage = Get_BaseDamage() + Randno(15,5);
  TotalDamage = Damage;
  return TotalDamage;
  }
int Get_HealCapacity(){
  return HealCapacity;
}


};

class FuriousBear: public Player
{
public:
FuriousBear(int _Health, int _BaseDamage):Player(_Health, _BaseDamage)
{
  cout<<"\n You Choose THE FURIOUS BEAR!!!!\n";
  cout<<"A force to be reckoned with, the Furious Bear is a master of hand-to-hand combat. With his massive paws and relentless determination, he will stop at nothing to defeat his opponents."<<endl;
  
  cout<<"Health : 150 HP "<<endl;
  cout<<"Base Damage : 20 HP"<<endl;
  cout<<"Special Damage : 10 - 15 HP "<<endl;
  cout<<"Healing Power : 10 - 15 HP"<<endl;
}
private: 

int TotalDamage;
int HealCapacity = Randno(10,5);

public :


int Get_TotalDamage(){
  int Damage = Get_BaseDamage() + Randno(10,5);
  TotalDamage = Damage;
  return TotalDamage;
}
int Get_HealCapacity(){
  return HealCapacity;
}

};

class RagingBull: public Player
{
public:
RagingBull(int _Health, int _BaseDamage):Player(_Health, _BaseDamage)
{
  cout<<"\n You Choose THE RAGING BULL!!!!\n";
  cout<<"A fierce and unyielding fighter, the Raging Bull charges into battle with his head held high. With his massive horns and unbridled strength, he is a formidable opponent that should not be underestimated."<<endl;
  
  cout<<"Health : 75 HP "<<endl;
  cout<<"Base Damage : 20 HP"<<endl;
  cout<<"Special Damage : 15 - 20 HP "<<endl;
  cout<<"Healing Power : 2 - 8 HP"<<endl;
}
private: 

int TotalDamage;
int HealCapacity = Randno(2,6);

public :

int Get_TotalDamage(){
  int Damage = Get_BaseDamage() + Randno(15,5);
  TotalDamage = Damage;
  return TotalDamage;
}
int Get_HealCapacity(){
  return HealCapacity;
}

};

//----------------------Game Class
class Game 
{

private:
Player *p1;
Player *p2;
string p1Name;
string p2Name;


//---------------------PlayerSetup
void PlayerSetup(int PlayerNo, int option){
  
  switch (PlayerNo){
    case 1:
    switch(option){
    case 1:
      p1 = new KingLion(100,20) ;
      p1Name = "The King Lion";
      break;
    case 2:
      p1 = new FuriousBear(150,15);
      p1Name = "The Furious Bear";
      break;
    case 3:
      p1 = new RagingBull(75,20) ;
      p1Name = "The Raging Bull";
      break;
  
      
    }
    break;

    case 2:
    switch(option){
    case 1:
      p2 = new KingLion(100,20) ;
      p2Name = "The King Lion";
      break;
    case 2:
      p2 = new FuriousBear(150,15);
      p2Name = "The Furious Bear";
      break;
    case 3:
      p2 = new RagingBull(75,20) ;
      p2Name = "The Raging Bull";
      break;
      }
    break;
  }

  }

void AssignPlayer(){
   int PlayerOption;
  cout<<"\nPlayer 1 choose your character.\n";
  cin>> PlayerOption;
  PlayerSetup(1,PlayerOption);
  cout<<"\nPlayer 2 choose your character.\n";
    cin>>PlayerOption;
  PlayerSetup(2,PlayerOption);

}


public:
//----------------Game System

void GameManager(){
cout<<"\n\n******************************************************\n\n";
  
  AssignPlayer();
  
   usleep(3000000);
 
  cout<<"\n\n************   Let The Game Begin   *********"<<endl<<endl;
  
  usleep(2000000);
  
  bool Player1turn = true;
  char input;
  srand(time(0));

  while(p1->Get_Health() > 0 && p2->Get_Health() > 0){    
    if(Player1turn == true){
    cout<<endl<<p1Name<<" turn:\nPress 'A' to Attack or 'H' to Heal:\n";
    cin>>input;
      if (input == 'a'||input == 'A'){    //--------p1 Attack
        p2->Damage(p1-> Get_TotalDamage());
        if(p2->Get_Health()>0){
        cout<<p1Name<<" Attack Power = "<<p1->Get_TotalDamage()<<endl;
           cout<<p1Name<<" Special Attack Power = "<<p1->Get_ExtraDamage()<<endl;
        cout<<p2Name<<" Health after Attack = "<<p2->Get_Health()<<endl;
        Player1turn = false;
          }
      } 
      else if(input == 'h'||input == 'H'){     //--------p1 Heal
        p1->Heal(p1->Get_HealCapacity());
        cout<<p1Name<<" Healed"<<endl
          <<p1Name<<" health = "<<p1 -> Get_Health()<<endl;
        Player1turn = false;
      }
    }
    else if (Player1turn == false){
       cout<<endl<<p2Name<<" turn:\nPress 'A' to Attack or 'H' to Heal:\n";
    cin>>input;
      if (input == 'a'||input == 'A'){        //--------p2 Attack
        p1->Damage(p2-> Get_TotalDamage());
        if(p1->Get_Health()>0){
        cout<<p2Name<<" Attack Power = "<<p2->Get_TotalDamage()<<endl;
          cout<<p2Name<<" Special Attack Power = "<<p2->Get_ExtraDamage()<<endl;
        cout<<p1Name<<" Health after Attack = "<<p1->Get_Health()<<endl;
        Player1turn = true;
          }
      }
      else if(input == 'h'||input == 'H'){    //--------p2 Heal
        p2->Heal(p2->Get_HealCapacity());
        cout<<p2Name<<" Healed"<<endl
          <<p2Name<<" health = "<<p2 -> Get_Health()<<endl;
        Player1turn = true;
      }
      
    }
  }
  if (p1->Get_Health() <= 0){
  cout<<"CONGRATULATIONS!!!\n "<<p2Name <<" Wins!!!!!\n";
    p1 = NULL;
    p2 = NULL;
} 
  else if (p2->Get_Health() <= 0){
  cout<<"\nCONGRATULATIONS!!!\n"<<p1Name <<" Wins!!!!!\n";
    p1 = NULL;
    p2 = NULL;
}
  
  }



//----------------Game Intro
void GameIntro(){
  cout<<"---------Welcome to the DUAL BATTLEGROUND------\n\nWelcome to the ultimate text-based battle game! In this game, you can choose to be one of three mighty champions:";
  
  cout<<" \n\n 1. The King Lion\n The King Lion is a majestic and regal beast, known for its strength and intelligence. This noble animal is a formidable opponent, with powerful claws and a mighty roar that can strike fear into the hearts of even the bravest warriors.";
  
cout<<"\n\n2. the Furious Bear\nThe Furious Bear is a fierce and relentless fighter, with a fierce temper and unmatched strength. This powerful creature will stop at nothing to emerge victorious, using its sharp claws and incredible endurance to overpower its enemies.";
  
cout<<"\n\n3. the Raging Bull\nThe Raging Bull is a relentless and unyielding force, with a fierce determination and unbreakable will. This massive animal charges into battle with a fierce determination, using its powerful horns and sheer brute force to take down its opponents.";
  
cout<<"\n\nEach of these amazing animals brings unique skills and abilities to the battle, making them all formidable opponents. Which one will you choose?\n";
  
 
}

~Game(){
  delete p1;
  delete p2;
}

};


int main() {
  
bool *Playing = new bool;
  *Playing = true;

Game *Start = new Game;
  Start -> GameIntro();
  do{
    
    Start -> GameManager();
  
    cout<<"\nTo Play again press : P\n";
    cout<<"\nTo Quit the game press : Q\n";
    
    char *PlayerChoice = new char;
    cin>>*PlayerChoice;
    if (*PlayerChoice == 'p' || *PlayerChoice == 'P'){
      *Playing = true;
      cout<<endl<<endl;
      usleep(2000000);
    }
    else if(*PlayerChoice == 'q' || *PlayerChoice == 'Q'){
      *Playing = false;
      usleep(2000000);
    }
   delete PlayerChoice;
    }while (*Playing == true);
   
  delete Playing;
  delete Start;

  cout<<"\n\n**********   The End   **********\n\n";
}