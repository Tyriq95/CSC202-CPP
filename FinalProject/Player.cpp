#include <iostream>
using namespace std;

class Player 
{
  private: 

  string name;
  double health;
  double baseAttack;
  double defense;

  public:
  
  // Sets default values
  Player (string tempName = "No name has been entered", double tempHealth = 0, double tempBaseAttack = 0, double tempDefense = 0)
  {
    name = tempName;
    health = tempHealth;
    baseAttack = tempBaseAttack;
    defense = tempDefense;
  }

  // Setters
  void setName (string playerName)
    {name = playerName;}  

  void setHealth ( double playerHealth)
    {health = playerHealth;}

  void setBaseAttack (double playerBaseAttack)
    {baseAttack = playerBaseAttack;}

  void setDefense (double playerDefense)
    {defense = playerDefense;}

  // Getters
  string getName() const
    {return name;}

  double getHealth() const
    {return health;}

  double getBaseAttack() const
    {return baseAttack;}

  double getDefense() const
    {return defense;}
};