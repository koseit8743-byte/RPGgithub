#include <iostream>
#include <vector>
#include <string>
#include <cmath> //NEED TO ADD THIS TO MAIN
#include <limits> //NEED TO ADD THIS TO MAIN
#include "/public/read.h"
using namespace std;

struct Player {		
	int level = 1;
	int xp = 0;
	
	int dmg = 10;
	int health = 100;
	int ram = 3;
	int critChance = 10;
	int dodgeChance = 5;
	float armor = 1.00; //DMG REDUCTION DO NOT RAISE TO BUFF, INSTEAD LOWER
};

Player Vex; //<-------- Player

void ViewStats(Player Vex) {
	cout << endl;
	cout << "\tLevel: " << Vex.level << endl;
	cout << "\tXP: " << Vex.xp << endl;
	cout << endl;
	cout << "\tDamage: " << Vex.dmg << endl;
	cout << "\tMax Health: " << Vex.health << endl;
	cout << "\tRAM: " << Vex.ram << endl;
	cout << "\tPrecision: " << Vex.critChance << endl;
	cout << "\tSwiftness: " << Vex.dodgeChance << "%" << endl;
	cout << "\tArmor: " << abs(Vex.armor * 100 - 100) << "%"  << endl;
	cout << endl;
}

struct Enemy {
	int level;
	int dmg;
	int health;
	int ram;
	int critChance;
	int dodgeChance;
	float armor;
	bool alive;
	bool notInCover;
};

void SetEnemies(vector<Enemy> &foes) {
	Enemy bot{1, 5, 10, 3, 10, 5, 1.00, true, true}; //Sets Enemy stats
	if (Vex.level <= 4) { //Adds an enemy based on level
		foes.push_back(bot);
	}
	else if (Vex.level <= 9) {
		foes.push_back(bot);
		foes.push_back(bot);
	}
	else {
		foes.push_back(bot);
		foes.push_back(bot);
		foes.push_back(bot);
	}
	
}

void EnemyCheck(vector<Enemy> &foes) {
	for (int i = 0; i < foes.size(); i++) { //Loop checks if enemy is dead
		if (foes.at(i).health <= 0) {
			foes.at(i).alive = false;
			cout << "Enemy " << i + 1 << ": DEAD" << endl;
		}
		else {
			cout << "Enemy " << i + 1 << ": " << foes.at(i).health << endl;
		}
	}
}

void BattleControls() {
	cout << endl;
	cout << "\t1: Use Melee\n";
	cout << "\t2: Use Gun\n";
	cout << "\t1: Take Cover\n";
	cout << "\t1: CyberHack\n";
	cout << "\t1: Analyze Enemy\n";
	cout << endl;
}

void BattleWon(vector<Enemy> &foes) { //If won distribute xp and raise lvl if needed (if lvl is raised then ask to add stat points
	int battleXp = 25 * foes.size(); 

	cout << endl;
	cout << "That was tooo easy" << endl;
	cout << endl;
	Vex.xp += 25 * foes.size();
	cout << "\t" << battleXp << " Exp earned\n";
	if (Vex.xp >= 100) {
		cout << "\tLEVEL INCREASED\n";
		Vex.level += 1; // lvl increase
		Vex.xp = 0; //Resets xp to 0 if lvls up
		ViewStats(Vex); //Displays new stats
	}
	cout << endl;
}

void Die() {
	cout << "You Flatlined." << endl;
	exit(0);
}

bool Fight() {
	int hp = Vex.health; //Sets players new health for every battle
	int randNum;
	int randCrit;
	int randDodge;
	int playerInput;
	string input; // 1 2 3 4 or 5
	bool playerNotInCover = true;
	bool battleEnds = true;
	
	//Enemy bot{1, 5, 10, 3, 10, 5, 1.00, true, true}; //Sets Enemy stats
	vector<Enemy> foes;   //Holds the foes in battle
	SetEnemies(foes);     //Sets Amount of foes through function
	
	EnemyCheck(foes);
	BattleControls(); //Displays Controls
	cin >> input;
	while (true) { //Start of Battle (Always starts off with player)
	
		randNum = rand() % 10 + 1;    //For player attack (NOT NEEDED YET)
		randCrit = rand() % 100 + 1;  //For player crit
		randDodge = rand() % 100 + 1; //For enemy dodge

		if (input == "1") { //Melee Choice
			cout << "\tChoose a target" << endl;
			cin >> playerInput;
			for (int i = 0; i < foes.size(); i++) {
				if (cin.fail()) {             //TODO I NEEEEED HELP WIT DIS IT DONT WORK
					cout << "You Hesitate or somethin" << endl;
					break; 
				}
				if (playerInput == i + 1) {
					cout << "Vex: HYAHHHHH" << endl;
					if (foes.at(i).notInCover) {
						if (randDodge <= foes.at(i).dodgeChance) {
							cout << "BZZZT EVASIVE MODE ACTIVATED (Atk Dodged)" << endl;
						}
						else if (randCrit <= Vex.critChance) {
							cout << "Vex: Jackpot (CRIT)" << endl;
							foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor; 
						} 
						else { foes.at(i).health -= Vex.dmg * foes.at(i).armor; }
					}
					else { cout << "BZZT INCOMING THREATS EVADED\n";} //Dialogue if enemy is taking cover
				}
			}
		}
		else if (input == "2") { //Shoot Choice
			cout << "\tChoose a target" << endl;
			cin >> playerInput;
			for (int i = 0; i < foes.size(); i++) {
				if (cin.fail()) {             //TODO I NEEEEED HELP WIT DIS IT DONT WORK
					cout << "You Hesitate or somethin" << endl;
					break; 
				}
				if (playerInput == i + 1) {
					cout << "Vex: FIRIINGGG" << endl;
					if (foes.at(i).notInCover) {
						if (randDodge <= foes.at(i).dodgeChance) {
							cout << "BZZZT EVASIVE MODE ACTIVATED (Atk Dodged)" << endl;
						}
						else if (randCrit <= Vex.critChance) {
							cout << "Vex: Jackpot (CRIT)" << endl;
							foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor; 
						} 
						else { foes.at(i).health -= Vex.dmg * foes.at(i).armor; }
					}
					else { cout << "BZZT INCOMING THREATS EVADED\n";} //Dialogue if enemy is taking cover
				}
			}
		}
		else if (input == "3") { //Take Cover Choice
			cout << "Vex: Gotta take cover" << endl;
			playerNotInCover = false;
		}
		else if (input == "4") { //CyberHack Choice
			cout << "Choose a target" << endl;
			cout << "Vex: IM HACKKIN IT" << endl;
		}
		else if (input == "5") { 
			cout << "Vex: Hmm I See" << endl;
		}
		else { cout << "You Hesitate or somethin" << endl; }
	//End of Player Turn	
		
		EnemyCheck(foes); //Checks if enemy hp drops to 0 or below
		for (int i = 0; i < foes.size(); i++) {

			if (foes.at(i).alive) { battleEnds = false; }
			foes.at(i).notInCover = true; //Sets enemies out of cover
		}
		

	//Start of Enemy Turn
		for (int i = 0; i < foes.size(); i++) { 
			randNum = rand() % 10 + 1;    //For enemy attack
			randCrit = rand() % 100 + 1;  //For enemy crit
			randDodge = rand() % 100 + 1; //For player dodge
			//cout << randNum << endl; //Test
			if (foes.at(i).alive) {
				if (randNum == 1) { //CyberHack
					cout << "BZZZZT IM TERMINATING IT" << endl;
				}
				else if (randNum == 2 or randNum == 3) { //Taking Cover
					cout << "BZZZZZT OPTIMAL COVER FOUND" << endl;
					foes.at(i).notInCover = false;
				}
				else if (randNum >= 4 and randNum <= 6) { //Shooting
					cout << "BZZZT TARGET FOUND: FIRING" << endl;
					if (playerNotInCover) { //If player is not in cover then attack lands
						if (randDodge <= Vex.dodgeChance) {
							cout << "Phew, close one (Atk Dodged)" << endl;
						}
						else if (randCrit <= foes.at(i).critChance) {
							cout << "BZZT WEAKPOINT DETECTED (CRIT)" << endl;
							hp -= 2 * foes.at(i).dmg * Vex.armor; 
						} 
						else { hp -= foes.at(i).dmg * Vex.armor; }
					}
					else { cout << "Vex: Not a chance\n";} //Dialogue if player is taking cover
				}
				else { //Attacking
					cout << "BZZZZT TARGET FOUND: ATTACKING" << endl;
					if (playerNotInCover) {
						if (randDodge <= Vex.dodgeChance) {
							cout << "Phew, close one (Atk Dodged)" << endl;
						}
						else if (randCrit <= foes.at(i).critChance) {
							cout << "BZZT WEAKPOINT DETECTED (CRIT)" << endl;
							hp -= 2 * foes.at(i).dmg * Vex.armor; 
						} 
						else { hp -= foes.at(i).dmg * Vex.armor; }
					}
					else { cout << "Vex: Not a chance\n";} //Dialogue if player is taking cover
				}
			}
		}
		
		if (hp <= 0) { hp = 0; }
		cout << "Vex: " << hp << " hp" << endl; //Test
		//Win/loss conditions
		if (hp <= 0) { //If Player dies
			//return false;
			Die();
		}
		else if (battleEnds) { //If all enemies are dead
			break;
		}

	    playerNotInCover = true;
		battleEnds = true;
		BattleControls(); //Displays Controls
		cin >> input;
	}
	//If won then distribute xp
	BattleWon(foes);
	return true;
}

int main() {
	int battleCount = 1;
	cout << "1, 2, 3, 4, 5: are the only valid commands" << endl;
	while (true) { //Test: Loops forever
		cout << "Battle " << battleCount << endl;
		Fight();
		battleCount += 1;
	}
}
