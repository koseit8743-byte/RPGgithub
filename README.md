# RPGgithub
RPG project
Combat 
Romero

1.Variables
    -I am using numerous amount of variables such as (ints,bools,floats) to hold player data in my struct which define how the character could be used in battle such as
     damage, health, chance to crit and dodge, etc. In the case of enemies, they hold similar characteristic variables as the player but also holds the bools of whether 
     certain actions happen in battle. This differs because the enemies are being created through a vector which holding these bools would make it easier to access if that
     specific enemy is effected.

2.Algebra
    -I am using Algebra to calculate whether how much damage should be outputted based on player and enemy characteristics. 
     For Example: hp = hp - foe.at(i).dmg * Vex.armor
                This equation would calculate how much health the player should be after being hit by the enemy accessed through a for loop.
                That dmg would then be multiplied by a float that could only go under 1.00 meaning when multiplied the amount of damage would then be reduced
                acting as armor or a way to reduce incoming damage.

3.Input and Output
    -I have as of now designed the combat system to print out a chunk of information at the started of the battle function depending on whether it is the players 
     starting turn or the enemies. It would be followed by enemies health bars which differ based on current enemy hp. If either the enemy or the player makes a move then
     dialogue would be outputted based on the actions that may occur followed by a notified of what happened in parenthesize.
     For Example:

        Vex: 'HYAHHHHH' (9-DMG)
    Raze: Their hacks are worse than my GrandMa's

    Enemy 1: 6 hp |======--------------|
    Enemy 2: 13 hp |====================|

    If the player decides to use their melee then that piece of dialogue would be displayed followed by the amount of damage
    then the enemies health would be reprinted and then that turn would end moving onto the next turn.

4.Branches
    -I won't lie there is a sea of branches in my combat system.
    For Example:

        -----------------
        1: Use Melee    |
        2: Use Gun      |
        3: Take Cover   |
        4: CyberHack    |
        5: Analyze Enemy|
        -----------------

    At the start of the players turn the above will always be printed
    1.If you were to input 1, then it would then ask to choose target, if at all any of the inputs are bad or incorrect inputs then turn is skipped.
    2.The same goes for the gun choice.
    3.Taking cover would cause the player to switch a bool statement sending the enemies attacking statements to be ignored
    4.Cyberhacking asks to choose a target and then choose one out of three cyberhacks (each have their own way of affecting enemies characteristics
      in their struct/vector.
    5.Option 5 prints out all the characteristics of all enemies in the vector currently and then continues the players turn setting them back to the first input of
      the while loop.

5.Loop
    -The whole combat system will loop inside of a while loop iterating the turn of the battle. The loop is broken if either all hp of enemies in the vector are dropped to
     zero, or if the players own health drops to zero.

6.For most the most part, everything is put into their own function such as the combat system in order to reduce the load of main(). 
  For Example;

    void ViewEnemyStats(vector<Enemy> foes) {
        for (int i = 0; i < foes.size(); i++) {
            cout << RED << endl;
            cout << "Enemy " << i + 1 << ":\n";
            cout << "\tLevel: " << foes.at(i).level << endl;
            cout << endl;
            cout << "\tDamage: " << foes.at(i).dmg << endl;
            cout << "\tCurrent Health: " << foes.at(i).health << endl;
            cout << "\tRAM: " << foes.at(i).ram << endl;
            cout << "\tPrecision: " << foes.at(i).critChance << "%" << endl;
            cout << "\tSwiftness: " << foes.at(i).dodgeChance << "%" << endl;
            cout << "\tArmor: " << abs(foes.at(i).armor * 100 - 100) << "%"  << endl;
            cout << RESET << endl;
        }
    }

    This is a short but simple function that is used when the player wants to do Action 5 (Analyze Enemy) in which this is called in the combat systems function
    to print all the enemies characteristics as of currently in battle. This matters so far since the enemies stats are unknown to the player until they access this
    function. From there they can decide if whether they need to cyberhack the enemy to armor strip them, or stun them if they have way too much damage to handle.


