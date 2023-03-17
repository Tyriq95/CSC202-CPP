#include <iostream>
#include <cstdlib>
#include "Player.cpp"
#include "Monster.cpp"
#include "Weapon.cpp"
#include "Armor.cpp"
using namespace std;

// Function for displaying the monster's health, name, and if they are dead or not
void monsterInfo (string monsterName1, double monsterHealth1, string monsterName2, double monsterHealth2, string monsterName3, double monsterHealth3)
{
  cout << "**************************************\n";
  if (monsterHealth1 <= 0)
  {
    cout << "Enemy Number 1:\n";
    cout << "*****     ******      **      *****\n";
    cout << "**   **   **         *  *     **   **\n";
    cout << "**   **   ******    ******    **   **\n";
    cout << "**   **   **       ** ** **   **   **\n";
    cout << "*****     ******  **      **  *****\n\n";
  }
  else
  {
    cout << "Enemy Number 1:\n";
    cout << endl << monsterName1 << endl;
    cout << endl << "Health: " << monsterHealth1 << "\n";
  }
  cout << "**************************************\n";
  cout << "**************************************\n";
  if (monsterHealth2 <= 0)
  {
    cout << "Enemy Number 2:\n";
    cout << "*****     ******      **      *****\n";
    cout << "**   **   **         *  *     **   **\n";
    cout << "**   **   ******    ******    **   **\n";
    cout << "**   **   **       ** ** **   **   **\n";
    cout << "*****     ******  **      **  *****\n\n";
  }
  else
  {
    cout << "Enemy Number 2:\n";
    cout << endl << monsterName2 << endl;
    cout << endl << "Health: " << monsterHealth2 << "\n";
  }
  cout << "**************************************\n";
  cout << "**************************************\n";
  if (monsterHealth3 <= 0)
  {
    cout << "Enemy Number 3:\n";
    cout << "*****     ******      **      *****\n";
    cout << "**   **   **         *  *     **   **\n";
    cout << "**   **   ******    ******    **   **\n";
    cout << "**   **   **       ** ** **   **   **\n";
    cout << "*****     ******  **      **  *****\n\n";
  }
  else
  {
    cout << "Enemy Number 3:\n";
    cout << endl << monsterName3 << endl;
    cout << endl << "Health: " << monsterHealth3 << "\n";
  }
  cout << "**************************************\n";
}

/*
Function to displays the player's info such as Name, Health, Attack, Defense, Weapon Name, and Armor Tier
*/
void playerInfo (string playerName, double playerHealth, double playerAttack, double playerDefense, string weaponName, string armorName)
{
  cout << "\nPlayer 1: " << playerName << "         Max Health: " << playerHealth << endl << "\nAttack: " << playerAttack << "             Defense:    " << playerDefense << endl << "\nWeapon: " << weaponName << "         Armor: " << armorName << endl;
}

// Struct to keep track of the info for each level including damage dealt, damage received, and monsters defeated.
struct LevelInfo
{
  double damageDealt;
  double damageReceived;
  int monstersDefeated;
};

int main() {

  // Declares variables
  double damageDealt = 0, damageReceived = 0, damageDealtTotal, damageReceivedTotal;
  int monstersDefeated = 0,level = 1, weaponAssigned, armorAssigned, monstersDefeatedTotal, miss;
  string weaponChoice, armorChoice;

  srand(time(NULL));

  // Creates the players name and sets their health, base attack, and base defense
  Player player1 = Player("Tyriq", 500, 100, 100);

  // Creates 3 different tiers of armor and the amount of defense bonus that they provide
  Armor lightArmor = Armor("Light Armor", 50);
  Armor mediumArmor = Armor("Medium Armor", 100);
  Armor heavyArmor = Armor("Heavy Armor", 150);

  //Creates 5 different types of weapons with different attack and defense bonuses 
  Weapon sword = Weapon("Sword  ", 40, 15);
  Weapon axe = Weapon("Axe    ", 50, 10);
  Weapon shield = Weapon("Shield ", 10, 60);
  Weapon staff = Weapon("Staff  ", 60, 5);
  Weapon rayGun = Weapon("Ray Gun", 75, 0);
  
  // Creates 5 different types of monsters with different health, attack, and defense values.
  Monster mutatedRat = Monster("Mutated Rat", 150, 15, 5);
  Monster zombie = Monster("Zombie", 250, 25, 10);
  Monster ogre = Monster("Ogre", 350, 35, 25);
  Monster giant = Monster("Giant", 400, 40, 30);
  Monster dragon = Monster("Dragon", 500, 50, 40);

  // Creates an array for the different armor types
  Armor armor[3] {{lightArmor}, {mediumArmor}, {heavyArmor}};

  // Creates an array for the different weapon types
  Weapon weapon[5] {{sword}, {axe}, {shield}, {staff}, {rayGun}};

  // Creates an array for the monster types for each level
  Monster level1[3] {{mutatedRat}, {zombie}, {ogre}};
  Monster level2[3] {{zombie}, {ogre}, {giant}};
  Monster level3[3] {{ogre}, {giant}, {dragon}};

/*
*
* START OF LEVEL 1
*
*/

  int turn = 1;

  // Passes proper parameters to the monsterInfo function and displays the necessary info
  monsterInfo(level1[0].getName(),level1[0].getHealth(),level1[1].getName(),level1[1].getHealth(), level1[2].getName(), level1[2].getHealth());
  
  // Selects and assigns random armor at the start of level 1

  //int a;
  armorAssigned = rand()%(3);
  player1.setDefense(player1.getDefense() + armor[armorAssigned].getDefenseBonus());
  armorChoice = armor[armorAssigned].getName();

  // Selects and assigns a rand weapon at the start of level 1

  //int w;
  weaponAssigned = rand()%(5);
  player1.setBaseAttack(player1.getBaseAttack() + weapon[weaponAssigned].getAttackBonus());
  weaponChoice = weapon[weaponAssigned].getName();

  // Passes parameters to the playerInfo function and displays the relevant info
  playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weapon[weaponAssigned].getName(), armor[armorAssigned].getName());

  // Loops until the player dies, or all three monsters die
  while (player1.getHealth() > 0 && (level1[0].getHealth() > 0 || level1[1].getHealth() > 0 || level1[2].getHealth() > 0))
  {
    // If turn == 1, then it is the players turn to attack
    if (turn == 1)
    {
      int enemyChoice;

      // Asks which enemy the user wants to attack
      cout << "\nPlease enter which enemy you would like to attack.\n";

      // Saves the users entry as enemyChoice and subtracts 1 to get the correct enemy from the array
      cin >> enemyChoice;
      enemyChoice = enemyChoice - 1;

      // Executes while cin fails, the choice is not between 1 and 3, or the enemy chose is already dead
      while (cin.fail() || enemyChoice < 0 || enemyChoice > 2 || level1[enemyChoice].getHealth() <= 0)
      {  
        // Tells the user the enemy is already dead if they chose to attack an enemy with no health remaining
        if (level1[enemyChoice].getHealth() <= 0)
        {
          cin.clear();
          cin.ignore();
          cout << "\nThat enemy has already been defeated. Please choose another enemy.\n";
          cin >> enemyChoice;
          enemyChoice = enemyChoice - 1;
        } 

        //Executes for all other reasons and tells the user that their entry was invalid
        else
        {
          cin.clear();
          cin.ignore();
          cout << "\nThat was an invalid entry. Please select the number corresponding to the enemy you would like to attack.\n";
          cin >> enemyChoice;
          enemyChoice = enemyChoice - 1;
        }
      }

      // The corresponding monster's health is set to whatever their current health is, minus the players current attack stat. Player has a 10% chance to miss.
      miss = rand()%(10);
      if (miss == 0)
      {
        cout << "\nYou Missed!\n";
      }
      else
      {
      level1[enemyChoice].setHealth(level1[enemyChoice].getHealth() - player1.getBaseAttack());
      }

      // Redisplays monster info after the attack takes place
      monsterInfo(level1[0].getName(),level1[0].getHealth(),level1[1].getName(),level1[1].getHealth(), level1[2].getName(), level1[2].getHealth());

      // Redisplays the player's info 
      playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weapon[weaponAssigned].getName(), armor[armorAssigned].getName());

      // Increments turn, indicating end of player's turn
      turn++;
    }
    else 
    {
      // If monster 1 is not dead, set players health to player's current health minus monster 1's attack. Each monster has a 25% chance to miss.
      if (level1[0].getHealth() > 0)
      {
        miss = rand()%(4);
        if (miss == 0)
        {
          cout << level1[0].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level1[0].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }

      // If monster 2 is not dead, set players health to player's current health minus monster 2's attack
      if (level1[1].getHealth() > 0)
      {
       miss = rand()%(4);
        if (miss == 0)
        {
          cout << level1[1].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level1[1].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }

      // If monster 3 is not dead, set players health to player's current health minus monster 3's attack
      if (level1[2].getHealth() > 0)
      {
        miss = rand()%(4);
        if (miss == 0)
        {
          cout << level1[2].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level1[2].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }

      //Redisplays monster info after enemy turn
      monsterInfo(level1[0].getName(),level1[0].getHealth(),level1[1].getName(),level1[1].getHealth(), level1[2].getName(), level1[2].getHealth());
    
      //Redisplays the player's info after the enemy turn
      playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weapon[weaponAssigned].getName(), armor[armorAssigned].getName());
      
      // Decrements turn, indicating the end of the enemy turn
      turn--;
    }
  }

  // If monster 1 is dead, increment monsters defeated
  if (level1[0].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // If monster 2 is dead, increment monsters defeated
  if (level1[1].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // If monster 3 is dead, increment monsters defeated
  if (level1[2].getHealth() <= 0)
  {
    monstersDefeated++;
  }
  
  /**
  * Damage dealt is found by taking the corresponding monster's 
  * max health minus their current health, and adding all the sums
  * together to find the total damage dealt for that round
  */
  damageDealt = (150 - level1[0].getHealth()) + (250 - level1[1].getHealth()) + (350 - level1[2].getHealth());

  // Damage received takes the players max health minus their current health  
  damageReceived = 500 - player1.getHealth();

  // Passes the information to the LevelInfo struct
  LevelInfo levelOne = {damageDealt, damageReceived, monstersDefeated};

  // Sets the level 1 info to the totals info
  damageDealtTotal = levelOne.damageDealt;
  damageReceivedTotal = levelOne.damageReceived;
  monstersDefeatedTotal = monstersDefeated;

  // Displays level 1's results
  cout << "\nLevel One Results\n" << "**********************\n" << "Damage Dealt: " << levelOne.damageDealt << endl << "Damage Received: " << levelOne.damageReceived << endl << "Monsters Defeated: " << levelOne.monstersDefeated << endl;

  // Displays "YOU DIED" if the player's health reaches 0 and closes the program
  if (player1.getHealth() <= 0)
  {
    cout << endl;
    cout << "**  **  ******  **  **\n";
    cout << " *  *   **  **  **  **\n";
    cout << "  **    **  **  **  **\n";
    cout << "  **    **  **  **  **\n";
    cout << "  **    ******  ******\n\n";

    cout << "*****     **   ******  *****\n";
    cout << "**   **   **   **      **   **\n";
    cout << "**   **   **   ******  **   **\n";
    cout << "**   **   **   **      **   **\n";
    cout << "*****     **   ******  *****\n\n";
    return 0;
  }

  // If the player is not dead, displays a congratulations message and that they are moving on to level 2
  else
  {
    cout << "\nCongratulations! You have completed Level " << level << "!\n";
    cout << "\nMoving on to level 2...\n";
  }
  
  // increments level
  level++;

  char newWeapon;

  // Asks the user if they would like to reroll for a chance to receive a new weapon
  cout << "\nWould you like to reroll for a new weapon before the next level? (Y/N)\n";
  cin >> newWeapon;
  newWeapon = toupper(newWeapon);

  // If user entry is not Y or N, then continues to asks the user until they enter a correct entry
  while (newWeapon != 'Y' && newWeapon != 'N')
  {
    //cin.clear();
    cin.ignore();
    cout << "\nPlease enter either a Y for Yes or N for No.\n";
    cin >> newWeapon;
    newWeapon = toupper(newWeapon);
  }

  // If the user enters Y, picks a new weapon at rand and assigns it to the player 
  if (newWeapon == 'Y')
  {
    weaponAssigned = rand()%(5);
    player1.setBaseAttack(100);
    player1.setBaseAttack(player1.getBaseAttack() + weapon[weaponAssigned].getAttackBonus());

    //Tells the user what weapon they received, along with the weapons attack and the players new total attack
    cout << "\nYour new weapon is a " << weapon[weaponAssigned].getName() << " with " << weapon[weaponAssigned].getAttackBonus() << " attack. Bringing your total attack to " << player1.getBaseAttack() << endl;

    //Makes weapon choice the name of the new weapon that was chosen
    weaponChoice = weapon[weaponAssigned].getName();
  }
  // If the player selects N, will output a message saying they will continue on with the same weapon
  else
  {
    cout << "\nYou will continue on to Level 2 with the same weapon.\n";
  }

  char newArmor;

  // Asks the user if they would like to reroll for a chance to get different armor
  cout << "\nWould you like to reroll for new armor before the next level? (Y/N)\n";
  cin >> newArmor;
  newArmor = toupper(newArmor);

  // If the user's entry is not a Y or N, then continues to ask for a correct entry 
  while (newArmor != 'Y' && newArmor != 'N')
  {
    cin.clear();
    cin.ignore();
    cout << "\nPlease enter either a Y for Yes or N for No.\n";
    cin >> newArmor;
    newArmor = toupper(newArmor);
  }

// If the user selects Y, picks a new armor at rand and assigns it to the player
if (newArmor == 'Y')
  {
    armorAssigned = rand()%(3);
    player1.setDefense(100);
    player1.setDefense(player1.getDefense() + armor[armorAssigned].getDefenseBonus());

    /*
    * Tells the user what their new armor is as well as the
    * defense stat or the armor, and the new total defense of 
    * the player with that armor
    */
    cout << "\nYour new armor is " << armor[armorAssigned].getName() << " with " << armor[armorAssigned].getDefenseBonus() << " defense. Bringing your total defense to " << player1.getDefense() << endl;
    armorChoice = armor[armorAssigned].getName();
  }

  //If the user enters N, displays a message telling the user they will continue on with the same armor
  else
  {
    cout << "\nYou will continue on to Level 2 with the same armor.\n";
  }

/*
*
* START OF LEVEL 2
*
*/
  turn = 1;
  monstersDefeated = 0;

  //Refills the players health back to max
  player1.setHealth(500);

  // Displays current level 2 monster info
  monsterInfo(level2[0].getName(),level2[0].getHealth(),level2[1].getName(),level2[1].getHealth(), level2[2].getName(), level2[2].getHealth());

  // Displays current player info
  playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weaponChoice, armorChoice);

  // Executes until either the player dies, or all monster's are killed
  while (player1.getHealth() > 0 && (level2[0].getHealth() > 0 || level2[1].getHealth() > 0 || level2[2].getHealth() > 0))
  {
    // Indicates the player's turn
    if (turn == 1)
    {
      int enemyChoice;

      // Asks the user which enemy they would like to attack
      cout << "\nPlease enter which enemy you would like to attack.\n";

      // Stores user input as enemyChoice and subracts 1 to corrsepond to the correct enemy
      cin >> enemyChoice;
      enemyChoice = enemyChoice - 1;

      // Loops while user input is invalid
      while (cin.fail() || enemyChoice < 0 || enemyChoice > 2 || level2[enemyChoice].getHealth() <= 0)
      {  
        // Executes if the enemy chosen is already dead
        if (level2[enemyChoice].getHealth() <= 0)
        {
          cin.clear();
          cin.ignore();
          cout << "\nThat enemy has already been defeated. Please choose another enemy.\n";
          cin >> enemyChoice;
          enemyChoice = enemyChoice - 1;
        } 
        // Executes if anything is entered besides 1, 2, or 3
        else
        {
          cin.clear();
          cin.ignore();
          cout << "\nThat was an invalid entry. Please select the number corresponding to the enemy you would like to attack.\n";
          cin >> enemyChoice;
          enemyChoice = enemyChoice - 1;
        }
      }
 
      // Sets the enemy's health to their current health minus the player's attack. Player has a 10% chance to miss.
      miss = rand()%(10);
      if (miss == 0)
      {
        cout << "\nYou Missed!\n";
      }
      else
      {
      level2[enemyChoice].setHealth(level2[enemyChoice].getHealth() - player1.getBaseAttack());
      }

      // Displays current monster info
      monsterInfo(level2[0].getName(),level2[0].getHealth(),level2[1].getName(),level2[1].getHealth(), level2[2].getName(), level2[2].getHealth());
      
      // Displays current player info
      playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weaponChoice, armorChoice);

      // Increments turn; end of player's turn
      turn++;
    }
    //Monster turn
    else 
    {
      //As long as monsters' health is > 0, each monster attacks the player. Damage is reduced based on player defense. Each monster has a 25% chance to miss
      if (level2[0].getHealth() > 0)
      {
        miss = rand()%(4);
        if (miss == 0)
        {
          cout << level2[0].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level2[0].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }
      if (level2[1].getHealth() > 0)
      {
       miss = rand()%(4);
        if (miss == 0)
        {
          cout << level2[1].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level2[1].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }
      if (level2[2].getHealth() > 0)
      {
        miss = rand()%(4);
        if (miss == 0)
        {
          cout << level2[2].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level2[2].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }

      // Displays current monsters' info
      monsterInfo(level2[0].getName(),level2[0].getHealth(),level2[1].getName(),level2[1].getHealth(), level2[2].getName(), level2[2].getHealth());
    
      //Displays current player's info
      playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weaponChoice, armorChoice);
      
      // Decrements turn; end of monsters' turn
      turn--;
    }
  }
  // If monster 1 is dead, increment monsters defeated
  if (level2[0].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // If monster 2 is dead, increment monsters defeated
  if (level2[1].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // If monster 3 is dead, increment monsters defeated
  if (level2[2].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // Determines the damage dealt this level by subtracting the monsters' current health from their max health, and adding all the totals together
  damageDealt = (250 - level2[0].getHealth()) + (350 - level2[1].getHealth()) + (400 - level2[2].getHealth());

  // Determines damage received by subtracting the player's current health from the max health
  damageReceived = 500 - player1.getHealth();

  // Passes the variables to LevelInfo struct for level two
  LevelInfo levelTwo = {damageDealt, damageReceived, monstersDefeated};

  // Displays level two results
  cout << "\nLevel Two Results\n" << "**********************\n" << "Damage Dealt: " << levelTwo.damageDealt << endl << "Damage Received: " << levelTwo.damageReceived << endl << "Monsters Defeated: " << levelTwo.monstersDefeated << endl;

  // Determines totals
  damageDealtTotal = damageDealtTotal + levelTwo.damageDealt;
  damageReceivedTotal = damageReceivedTotal + levelTwo.damageReceived;
  monstersDefeatedTotal = monstersDefeatedTotal + monstersDefeated;

  // Displays total from all completed levels
  cout << "\nTotal Results\n" << "**********************\n" << "Damage Dealt: " << damageDealtTotal << endl << "Damage Received: " << damageReceivedTotal << endl << "Monsters Defeated: " << monstersDefeatedTotal << endl;

  // Displays message if player dies
  if (player1.getHealth() <= 0)
  {
    cout << endl;
    cout << "**  **  ******  **  **\n";
    cout << " *  *   **  **  **  **\n";
    cout << "  **    **  **  **  **\n";
    cout << "  **    **  **  **  **\n";
    cout << "  **    ******  ******\n\n";

    cout << "*****     **   ******  *****\n";
    cout << "**   **   **   **      **   **\n";
    cout << "**   **   **   ******  **   **\n";
    cout << "**   **   **   **      **   **\n";
    cout << "*****     **   ******  *****\n\n";
    return 0;
  }
  // Congratulates the player and lets them know they are moving on to level 3
  else
  {
    cout << "\nCongratulations! You have completed Level " << level << "!\n";
    cout << "\nMoving on to level 3...\n";
  }

  level++;

  //Asks the user if they would like to reroll for a chance at a new weapon
  cout << "\nWould you like to reroll for a new weapon before the next level? (Y/N)\n";
  cin >> newWeapon;
  newWeapon = toupper(newWeapon);

  // Makes sure the user enters a valid entry (Y/N)
  while (newWeapon != 'Y' && newWeapon != 'N')
  {
    cin.clear();
    cin.ignore();
    cout << "\nPlease enter either a Y for Yes or N for No.\n";
    cin >> newWeapon;
    newWeapon = toupper(newWeapon);
  }

  // If the user enters Y, selects a new rand weapon and assigns it to the player
  if (newWeapon == 'Y')
  {
    weaponAssigned = rand()%(5);
    player1.setBaseAttack(100);
    player1.setBaseAttack(player1.getBaseAttack() + weapon[weaponAssigned].getAttackBonus());

    // Tells the user their new weapon, the attack for the weapon, and the player's new total attack
    cout << "\nYour new weapon is a " << weapon[weaponAssigned].getName() << " with " << weapon[weaponAssigned].getAttackBonus() << " attack. Bringing your total attack to " << player1.getBaseAttack() << endl;

    // Stores the weapons name as weapon choice
    weaponChoice = weapon[weaponAssigned].getName();
  }
  // If user enters N, Displays that the player will continue on with their current weapon
  else
  {
    cout << "\nYou will continue on to Level 3 with the same weapon.\n";
  }

  // Asks the user if they would like to reroll for a chance at new armor
  cout << "\nWould you like to reroll for new armor before the next level? (Y/N)\n";
  cin >> newArmor;
  newArmor = toupper(newArmor);

  // Makes sure the user's entry is valid, re-prompts user until valid
  while (newArmor != 'Y' && newArmor != 'N')
  {
    cin.clear();
    cin.ignore();
    cout << "\nPlease enter either a Y for Yes or N for No.\n";
    cin >> newArmor;
    newArmor = toupper(newArmor);
  }

// If user enters Y, assigns a new rand armor to the player and assigns it to them
if (newArmor == 'Y')
  {
    armorAssigned = rand()%(3);
    player1.setDefense(100);
    player1.setDefense(player1.getDefense() + armor[armorAssigned].getDefenseBonus());

    // Tells the user the name of their new armor and the defense of that armor, as well as the player's new defense total
    cout << "\nYour new armor is " << armor[armorAssigned].getName() << " with " << armor[armorAssigned].getDefenseBonus() << " defense. Bringing your total defense to " << player1.getDefense() << endl;
    armorChoice = armor[armorAssigned].getName();
  }
  // Executes if user enters N
  else
  {
    cout << "\nYou will continue on to Level 3 with the same armor.\n";
  }

/*
*
* START OF LEVEL 3
*
*/
  turn = 1;
  monstersDefeated = 0;

  // Refills player health back to max
  player1.setHealth(500);

  // Displays current monsters' info
  monsterInfo(level3[0].getName(),level3[0].getHealth(),level3[1].getName(),level3[1].getHealth(), level3[2].getName(), level3[2].getHealth());

  // Displays current player info
  playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weaponChoice, armorChoice);

  // Executes until either the player dies, or all monsters die
  while (player1.getHealth() > 0 && (level3[0].getHealth() > 0 || level3[1].getHealth() > 0 || level3[2].getHealth() > 0))
  {
    // Player's turn
    if (turn == 1)
    {
      int enemyChoice;

      // Asks the user for which enemy they would like to attack
      cout << "\nPlease enter which enemy you would like to attack.\n";
      cin >> enemyChoice;
      enemyChoice = enemyChoice - 1;

      // Loops if entry is invalid until user enters a valid enemy
      while (cin.fail() || enemyChoice < 0 || enemyChoice > 2 || level3[enemyChoice].getHealth() <= 0)
      {  
        if (level3[enemyChoice].getHealth() <= 0)
        {
          cin.clear();
          cin.ignore();
          cout << "\nThat enemy has already been defeated. Please choose another enemy.\n";
          cin >> enemyChoice;
          enemyChoice = enemyChoice - 1;
        } 
        else
        {
          cin.clear();
          cin.ignore();
          cout << "\nThat was an invalid entry. Please select the number corresponding to the enemy you would like to attack.\n";
          cin >> enemyChoice;
          enemyChoice = enemyChoice - 1;
        }
      }
 
      // Sets the health of the enemy choen to their current health minus the player's attack. Player has a 10% chance to miss.

      miss = rand()%(10);
      if (miss == 0)
      {
        cout << "\nYou Missed!\n";
      }
      else
      {
      level3[enemyChoice].setHealth(level3[enemyChoice].getHealth() - player1.getBaseAttack());
      }

      // Displays the current monsters' info
      monsterInfo(level3[0].getName(),level3[0].getHealth(),level3[1].getName(),level3[1].getHealth(), level3[2].getName(), level3[2].getHealth());
      
      // Displays the current player info
      playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weaponChoice, armorChoice);

      // End of player's turn
      turn++;
    }
    // Start of monsters' turn
    else 
    {
      // Each monster attacks the player as long as their health is greater than 0. Each monster has a 25% chance to miss.
      if (level3[0].getHealth() > 0)
      {
        miss = rand()%(4);
        if (miss == 0)
        {
          cout << level3[0].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level3[0].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }
      if (level3[1].getHealth() > 0)
      {
       miss = rand()%(4);
        if (miss == 0)
        {
          cout << level3[1].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level3[1].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }
      if (level3[2].getHealth() > 0)
      {
        miss = rand()%(4);
        if (miss == 0)
        {
          cout << level3[2].getName() << " Missed!\n";
        }
        else
        {
          player1.setHealth(player1.getHealth() - (level3[2].getAttack() * (1 - (player1.getDefense() / 1000))));
        }
      }

      // Displays current monster info
      monsterInfo(level3[0].getName(),level3[0].getHealth(),level3[1].getName(),level3[1].getHealth(), level3[2].getName(), level3[2].getHealth());
    
      // Displays current player info
      playerInfo(player1.getName(), player1.getHealth(), player1.getBaseAttack(), player1.getDefense(), weaponChoice, armorChoice);
      
      // End of monsters' turn
      turn--;
    }
  }
  // If monster 1 is dead, increment monsters defeated
  if (level3[0].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // If monster 2 is dead, increment monsters defeated
  if (level3[1].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // If monster 3 is dead, increment monsters defeated
  if (level3[2].getHealth() <= 0)
  {
    monstersDefeated++;
  }

  // Determines damage dealth during current level
  damageDealt = (250 - level3[0].getHealth()) + (350 - level3[1].getHealth()) + (400 - level3[2].getHealth());

  // Determines damage received during current level
  damageReceived = 500 - player1.getHealth();

  // Passes damage dealt, damage received, and monsters defeated to LevelInfo struct
  LevelInfo levelThree = {damageDealt, damageReceived, monstersDefeated};

  // Displays Level 3 results
  cout << "\nLevel Three Results\n" << "**********************\n" << "Damage Dealt: " << levelThree.damageDealt << endl << "Damage Received: " << levelThree.damageReceived << endl << "Monsters Defeated: " << levelThree.monstersDefeated << endl;

  // Calculates the total damage dealt, total damage received, and total number of monsters defeated
  damageDealtTotal = damageDealtTotal + levelThree.damageDealt;
  damageReceivedTotal = damageReceivedTotal + levelThree.damageReceived;
  monstersDefeatedTotal = monstersDefeatedTotal + monstersDefeated;

  // Displays the total levels results
  cout << "\nTotal Results\n" << "**********************\n" << "Damage Dealt: " << damageDealtTotal << endl << "Damage Received: " << damageReceivedTotal << endl << "Monsters Defeated: " << monstersDefeatedTotal << endl;

  // Displays message if player dies
  if (player1.getHealth() <= 0)
  {
    cout << endl;
    cout << "**  **  ******  **  **\n";
    cout << " *  *   **  **  **  **\n";
    cout << "  **    **  **  **  **\n";
    cout << "  **    **  **  **  **\n";
    cout << "  **    ******  ******\n\n";

    cout << "*****     **   ******  *****\n";
    cout << "**   **   **   **      **   **\n";
    cout << "**   **   **   ******  **   **\n";
    cout << "**   **   **   **      **   **\n";
    cout << "*****     **   ******  *****\n\n";
    return 0;
  }
  // Displays victory message if player is alive and all level 3 monsters are defeated
  else
  {
    cout << "\nCongratulations! You have completed my game! I hope this will earn me a decent grade!\n\n";
    cout << "**  **    ******    **  **\n";
    cout << " *  *     **  **    **  **\n";
    cout << "  **      **  **    **  **\n";
    cout << "  **      **  **    **  **\n";
    cout << "  **      ******    ******\n\n";

    cout << "**      **      **  **  ***    **\n";
    cout << " **    ****    **   **  ** **  **\n";
    cout << "  **  **  **  **    **  **  ** **\n";
    cout << "   ****    ****     **  **   ****\n";
    cout << "    **      **      **  **    ***\n\n";
  }
system("pause");
return 0;
} 