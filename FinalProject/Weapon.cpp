#include <iostream>
using namespace std;

class Weapon 
{
  private: 

  string weaponName;
  double attackBonus;
  double defenseBonus;

  public:
  
  // Sets default values
  Weapon (string tempWeaponName = "No name has been entered", double tempAttackBonus = 0, double tempDefenseBonus = 0)
  {
    weaponName = tempWeaponName;
    attackBonus = tempAttackBonus;
    defenseBonus = tempDefenseBonus;
  }

  // Setters
  void setName (string weaponName)
    {weaponName = weaponName;}

  void setAttackBonus (double weaponAttackBonus)
    {attackBonus = weaponAttackBonus;}

  void setDefenseBonus (double weaponDefenseBonus)
    {defenseBonus = weaponDefenseBonus;}

  // Getters
  string getName() const
    {return weaponName;}

  double getAttackBonus() const
    {return attackBonus;}

  double getDefenseBonus() const
    {return defenseBonus;}
};