#include <iostream>
using namespace std;

class Monster 
{
  private: 

  string name;
  double health;
  double attack;
  double defense;

  public:
  
  // Sets default values
  Monster (string tempName = "No name has been entered", double tempHealth = 0, double tempAttack = 0, double tempDefense = 0)
  {
    name = tempName;
    health = tempHealth;
    attack = tempAttack;
    defense = tempDefense;
  }

  // Setters
  void setName (string monsterName)
    {name = monsterName;}  

  void setHealth ( double monsterHealth)
    {health = monsterHealth;}

  void setBaseAttack (double monsterAttack)
    {attack = monsterAttack;}

  void setDefense (double monsterDefense)
    {defense = monsterDefense;}

  // Getters
  string getName() const
    {return name;}

  double getHealth() const
    {return health;}

  double getAttack() const
    {return attack;}

  double getDefense() const
    {return defense;}
};