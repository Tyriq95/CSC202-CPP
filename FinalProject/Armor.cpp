#include <iostream>
using namespace std;

class Armor 
{
  private: 

  string armorName;
  double defenseBonus;

  public:
  
  // Sets default values
  Armor (string tempArmorName = "No name has been entered", double tempDefenseBonus = 0)
  {
    armorName = tempArmorName;
    defenseBonus = tempDefenseBonus;
  }

  // Setters
  void setName (string armorName)
    {armorName = armorName;}

  void setDefenseBonus (double armorDefenseBonus)
    {defenseBonus = armorDefenseBonus;}

  // Getters
  string getName() const
    {return armorName;}

  double getDefenseBonus() const
    {return defenseBonus;}
};