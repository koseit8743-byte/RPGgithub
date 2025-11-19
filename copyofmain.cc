//Fill out this comment with your names and which bullet points you did
//Partners: Kwabe
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <cmath> //NEED TO ADD THIS TO MAIN
#include <limits> //NEED TO ADD THIS TO MAIN
#include <unistd.h>
using namespace std;

//COLOR MAP: Player=YELLOW Raze=CYAN Enemy=RED Basic=WHITE
/// movecursor(5, 20);
// setcolor(6, 7, 67);
// setbgcolor(67, 67, 67);
// set_raw_mode(true);
//char ch =

//START
void CombatDialogue(bool playerAttacking, bool enemyattacking) {
	vector<string> RazeResponses = {
		"Raze: PREEM! nice shot",
		"Raze: That hunk of scraps's gonna need some serious repairs!",
		"Raze: Their hacks are worse than my GrandMa's",
		"Raze: Another corpo bites the digital dust"
	};
	if (playerAttacking) {
		setbgcolor(0, 0, 80);
		int Razerand =  rand() % RazeResponses.size();
		cout << CYAN << RazeResponses.at(Razerand) << RESET << endl;
	}

	vector<string> enemyresponse  = {
		"SYNTEX BOT: SYNTEX Property, FREEZE!",
		"SYNTEX BOT: INTRUDER WARNING, PREPARE TO BE NEUTRALIZED",
		"SYNTEX BOT: CORPORATE PROPERTY, DO NOT ENGAGE ANY FURTHER",
		"SYNTEX BOT: INTRUDER WARNING, LETHAL FORCE IS AUTHORIZED"
	};

	vector<string> enemyattackRaze  = {
		"INCOMING! Netrunner attack",
		"Raze: Watch out choom, dont make me have to find a new partner",
		"Raze: Hard chrome hit choom, dont flatline on me",
		"Raze: Security getting a little tough, look alive",
		"Raze: Ouch, try not to get zeroed"
	};

	if (enemyattacking) {
		int enemyrand = rand() %  enemyresponse.size();
		cout << RED <<  enemyresponse.at(enemyrand) << RESET << endl;

		int razeresponse = rand() % enemyattackRaze.size();
		cout << CYAN << enemyattackRaze.at(razeresponse) << RESET << endl;


	}
}
struct Player {		
	int level = 1;
	int xp = 0;
	
	int dmg = 50;
	int health = 100;
	int ram = 9;
	int critChance = 30;
	int dodgeChance = 20;
	float armor = 0.50; //DMG REDUCTION DO NOT RAISE TO BUFF, INSTEAD LOWER
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
	cout << "\tPrecision: " << Vex.critChance << "%" <<  endl;
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
	
	int turnHacked;
	bool hacked;
	bool stunned;
	bool controlled;
};

void SetEnemies(vector<Enemy> &foes) {
	//Enemy bot{1, 5, 10, 3, 10, 5, 1.00, true, true}; //Sets Enemy stats
	Enemy bot{1, 20, 150, 9, 50, 5, 0.05, true, true, 0, false, false, false}; // BUFFED OUT ENEMY
	if (Vex.level <= 4) { //Adds an enemy based on level
		foes.push_back(bot);
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

void EnemyCheck(vector<Enemy> &foes) {
	for (int i = 0; i < foes.size(); i++) { //Loop checks if enemy is dead
		if (foes.at(i).health <= 0) {
			foes.at(i).alive = false;
			cout << "Enemy " << i + 1 << ": DEAD" << endl;
		}
		else {
			cout << "Enemy " << i + 1 << ": " << foes.at(i).health << " hp" << endl;
		}
	}
}

void BattleControls() {
	cout << YELLOW << endl;
	cout << "\t1: Use Melee\n";
	cout << "\t2: Use Gun\n";
	cout << "\t3: Take Cover\n";
	cout << "\t4: CyberHack\n";
	cout << "\t5: Analyze Enemy\n";
	cout << RESET << endl;
}

void BattleWon(vector<Enemy> &foes) { //If won distribute xp and raise lvl if needed (if lvl is raised then ask to add stat points
	int battleXp = 25 * foes.size(); 
	int playerChoice;

	cout << endl;
	cout << YELLOW << "Vex: 'That was tooo easy'" << RESET << endl;
	CombatDialogue(true, false);  
	cout << endl;
	cout << "BATTLE OVER:\n";
	Vex.xp += 25 * foes.size();
	cout << "\t" << GREEN << battleXp << " Exp earned\n";
	cout << "\tCurrent lvl: " << Vex.level << endl;
	cout << "\tCurrent xp: " << Vex.xp << endl;
	if (Vex.xp >= 100) {
		cout << "\tLEVEL INCREASED\n";
		Vex.level += 1; // lvl increase
		Vex.xp = 0; //Resets xp to 0 if lvls up
		playerChoice = read("Choose a stat to upgrade: {1-Damage, 2-Max Health, 3-RAM, 4- Precision, 5-Swiftness, 6-Armor}\n");
		cout << RESET;
		if (playerChoice == 1) {
			Vex.dmg += 5;
		}
		else if (playerChoice == 2) {
			Vex.health += 5;
		}
		else if (playerChoice == 3) {
			Vex.ram += 1;
		}
		else if (playerChoice == 4) {
			Vex.critChance += 5;
		}
		else if (playerChoice == 5) {
			Vex.dodgeChance += 5;
		}
		else if (playerChoice == 6) {
			Vex.armor -= 0.02;
		}
		
		ViewStats(Vex); //Displays new stats
	}
	cout << endl;
}

void Die() {
	cout << BLUE << "You Flatlined." << RESET << endl;
	exit(0);
}

//                               START OF COMBAT
//=================================================================================================
bool Fight(bool enemyGoesFirst) {
	int hp = Vex.health; //Sets players new health for every battle
	int dmg; //Used to print out dmg output for enemy and player
	int randNum;
	int randCrit;
	int randDodge;
	int randHack;
	int randControl;
	int playerInput;
	int turnCount = 1; //Iterator / turn count
	int turnPlayerHackEnds; //Holds the value(turn) in which the hack should end
	int turnEnemyHackEnds;  //
	string input; // 1 2 3 4 or 5
	bool playerNotInCover = true;
	bool playerIsStunned = false;
	bool playerIsHacked = false;
	bool hackLanded = false;
	bool battleEnds = true;

	if (enemyGoesFirst) { cout << RED << "ENEMY GOES FIRST\n" << RESET; } //Test to see if enemy is supposed to go first or not
	else { cout << GREEN << "PLAYER GOES FIRST\n" << RESET; }

	//Enemy bot{1, 5, 10, 3, 10, 5, 1.00, true, true}; //Sets Enemy stats
	vector<Enemy> foes;   //Holds the foes in battle
	SetEnemies(foes);     //Sets Amount of foes through function
	vector<Enemy> foesCopy = foes; //Use to reset the stats back to original
	
	EnemyCheck(foes);

	if (enemyGoesFirst == true and turnCount == 1) {
		cout << "Player Turn 1:\n" << endl;
		cout << "(PLAYER TURN SKIPPED) \n";
	}
	else {
		cout << "Player Turn " << turnCount << ":\n\n";
		BattleControls(); //Displays Controls
		cin >> input;
	}
	//=================================================================================================
	while (true) { //Start of Battle
		//cout << "At top of turn (TEST)\n"; //Test
	if (enemyGoesFirst == true and turnCount == 1) {
	} // Skips players turn if enemy goes first is true and it is turn 1
		
	else {
		//BattleControls(); //Displays Controls
		//cin >> input;

		randNum = rand() % 10 + 1;    //For player attack (NOT NEEDED YET)
		randCrit = rand() % 100 + 1;  //For player crit
		randHack = rand() % 100 + 1;  //For player cyberhack
		randDodge = rand() % 100 + 1; //For enemy dodge
		
		//=================================================================================================
		if (input == "1") { //Melee Choice
			cout << "\tChoose a target" << endl;
		 
			//playerInput = read("\tChoose a target\n");
			cin >> playerInput;
			for (int i = 0; i < foes.size(); i++) {
				if (!cin) {  //IF INPUT IS NOT AN INTEGER           //TODO I NEEEEED HELP WIT DIS IT DONT WORK
					cin.clear();
					string s;
					cin >> s;
					cout << endl;
					clearscreen(); //Clears the screen
					cout << "You Hesitate or somethin" << endl;
					break; 
				}

				if (playerInput == i + 1) {
					clearscreen(); //Clears the screen
					cout << YELLOW << "Vex: 'HYAHHHHH'" << RESET <<  endl;
					if (foes.at(i).notInCover) {
						if (randDodge <= foes.at(i).dodgeChance) {
							cout << RED << "'BZZZT EVASIVE MODE ACTIVATED' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= Vex.critChance) {
							cout << YELLOW << "Vex: 'Jackpot' (CRIT)" << RESET << endl;
							foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor; 
							dmg = 2 * Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
							CombatDialogue(true, false);  
						} 
						else { 
							foes.at(i).health -= Vex.dmg * foes.at(i).armor; 
							dmg = Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
							CombatDialogue(true, false);  
						}
					}
					else { cout << RED << "'BZZT INCOMING THREATS EVADED' (IN COVER)\n" << RESET;} //Dialogue if enemy is taking cover
				}
			}
		}
		//=================================================================================================
		else if (input == "2") { //Shoot Choice
			cout << "\tChoose a target" << endl;
			
			cin >> playerInput;
			for (int i = 0; i < foes.size(); i++) {
				if (!cin) {             //TODO I NEEEEED HELP WIT DIS IT DONT WORK
					cin.clear(); //clears the variable I think
					string s;    //New variable type to move the cin into
					cin >> s;    //cin is located in new variable
					cout << endl;
					clearscreen(); //Clears the screen
					cout << "You Hesitate or somethin" << endl;
					break; 
				}
				
				if (playerInput == i + 1) {
					clearscreen(); //Clears the screen
					cout << YELLOW << "Vex: 'FIRIINGGG'" << RESET <<  endl;
					if (foes.at(i).notInCover) {
						if (randDodge <= foes.at(i).dodgeChance) {
							cout << RED << "'BZZZT EVASIVE MODE ACTIVATED' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= Vex.critChance) {
							cout << YELLOW << "Vex: 'Jackpot' (CRIT)" << RESET << endl;
							foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor; 
							dmg = 2 * Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
							CombatDialogue(true, false);  
						} 
						else { 
							foes.at(i).health -= Vex.dmg * foes.at(i).armor; 
							dmg = Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
							CombatDialogue(true, false);  
						}
					}
					else { cout << RED << "'BZZT INCOMING THREATS EVADED' (IN COVER)\n" << RESET;} //Dialogue if enemy is taking cover
				}
			}
		}
		//=================================================================================================
		else if (input == "3") { //Take Cover Choice
			clearscreen(); //Clears the screen
			cout << YELLOW << "Vex: 'Gotta take cover'" << RESET << endl;
			playerNotInCover = false;
		}
		//=================================================================================================
		else if (input == "4") { //CyberHack Choice
			cout << "Choose a target" << endl;

			cin >> playerInput;
			for (int i = 0; i < foes.size(); i++) {
				if (!cin) {  //IF INPUT IS NOT AN INTEGER         
					cin.clear();
					string s;
					cin >> s;
					cout << endl;
					clearscreen(); //Clears the screen
					cout << "You Hesitate or somethin" << endl;
					break; 
				}

				if (playerInput == i + 1) {
					if (foes.at(i).hacked) {
						clearscreen(); //Clears the screen
						cout << "Enemy is already currently hacked.\n";
						break;
					}
					else if (Vex.ram >= foes.at(i).ram) {
						hackLanded = true;
						cout << "Hack has a 100" << "%" << " Chance of landing.\n";
					}
					else if (Vex.ram >= foes.at(i).ram * 2/3) {
						//cout << foes.at(i).ram * 2/3 << endl; //Test
						if (randHack <= 50) { hackLanded = true; }
						cout << "Hack has a 50" << "%" << " Chance of landing.\n";
					}
					else {
						clearscreen(); //Clears the screen
						cout << "Enemy cyberware is too hard to decrypt. \n";
						break;
					}

					cout << "Choose a CyberHack: {1-Armor Strip, 2-Visual Overload, 3-Mind Control}\n\n";
					cin >> playerInput;
					if (!cin) {  //IF INPUT IS NOT AN INTEGER         
						cin.clear();
						string s;
						cin >> s;
						cout << endl;
						clearscreen(); //Clears the screen
						cout << "You Hesitate or somethin" << endl;
						break; 
					}
					//=================================================================================================
					if (playerInput == 1 && hackLanded) { //Armor Strip
						foes.at(i).armor = 1.00;  //Resets the value or armor
						foes.at(i).hacked = true; //Sets the enemy as currently hacked
						turnEnemyHackEnds = turnCount + 5; //Should hold the value the turn that the hack should end 
						foes.at(i).turnHacked = turnEnemyHackEnds;
					}
					else if (playerInput == 2 && hackLanded) { //Visual Overload
						foes.at(i).stunned = true;
						foes.at(i).hacked = true; //Sets the enemy as currently hacked
						turnEnemyHackEnds = turnCount + 5; //Should hold the value the turn that the hack should end  TODO: ADJUST THIS VARIABLE TO LAST LONGER
						foes.at(i).turnHacked = turnEnemyHackEnds;
					}
					else if (playerInput == 3 && hackLanded) {//Mind Control
						if (foes.size() == 1) {
							clearscreen(); //Clears the screen
							hackLanded = false;
							cout << "Enemy has no allies to attack.\n";
							break;	
						}
						else {
							foes.at(i).controlled = true;
							foes.at(i).hacked = true; //Sets the enemy as currently hacked
							turnEnemyHackEnds = turnCount + 5; //Should hold the value the turn that the hack should end 
							foes.at(i).turnHacked = turnEnemyHackEnds;
						}
					}
					//=================================================================================================

				}
			} 
			//=================================================================================================
			if (hackLanded) { 
				clearscreen(); //Clears the screen
				cout << YELLOW << "Vex: 'IM HACKKIN IT' (SUCCESS)\n" << RESET; 
				cout << "Hack ends in Turn "<< turnEnemyHackEnds << ":\n";
				hackLanded = false; //Resets it once used 
			} 
			else {
				cout << "Hack unsuccessful. (MISSED)\n";
			}
			//=================================================================================================
		}
		else if (input == "5") { 
					clearscreen(); //Clears the screen
					ViewEnemyStats(foes);
					cout << YELLOW << "Vex: 'Hmm I See'" << RESET << endl;
					cout << "Player Turn " << turnCount << ":\n\n";
					BattleControls(); //Displays Controls
					cin >> input;
					continue;
		}
		else { cout << "You Hesitate or somethin" << endl; }
	//End of Player Turn	
	

	}
		//=================================================================================================
		EnemyCheck(foes); //Checks if enemy hp drops to 0 or below
		for (int i = 0; i < foes.size(); i++) { //Checks if hack effects should end and then revert stats back to original
			foesCopy.at(i).health = foes.at(i).health;
			foesCopy.at(i).alive = foes.at(i).alive;
			foesCopy.at(i).notInCover = foes.at(i).notInCover;
			
			if (foes.at(i).turnHacked == turnCount) {
				foes.at(i) = foesCopy.at(i);
				cout << "Enemy " << i + 1 << " Status effect reverted\n";
			}
			
			if (foes.at(i).alive) { 
				battleEnds = false; 
			}
			foes.at(i).notInCover = true; //Sets enemies out of cover
		}
		turnCount++;
		cout << endl << "Enemy Turn " << turnCount << ":\n\n";
		//==================================================================================================

	
		

	//Start of Enemy Turn
		
		for (int i = 0; i < foes.size(); i++) { 
			randNum = rand() % 10 + 1;    //For enemy attack
			randControl = rand() % foes.size() + 1;
			randCrit = rand() % 100 + 1;  //For enemy crit
			randHack = rand() % 100 + 1;  //For enemy cyberhack
			randDodge = rand() % 100 + 1; //For player dodge
			//cout << randNum << endl; //Test
			
			//==================================================================================================
			if (foes.at(i).stunned) { //If enemy is stunned 
				cout << RED << "BZZZZT OPTICAL SYSTEM MALFUNCTION (STUNNED)\n" << RESET;
			}
			else if (foes.at(i).controlled) {
				cout << RED << "BZZZT TARGETTING SYSTEM MALFUNCTION (MIND CONTROLLED)\n" << RESET; 
				cout << "TEST PRINTING OUT : RANDCONTROL " << randControl << endl;
				for (int j = 0; j < foes.size(); j++) {
					if (i == j) {
						//SKIP (DONT LET THEM ATTACK THEMSELVE)
					}
					else if (randControl == j) {
						cout << GREEN << "BZZZZT IM BOUTTA ATTACK (ATTACKED ENEMY " << j + 1 << ")\n" << RESET;
					}
				}
			}
			//==================================================================================================
			else if (foes.at(i).alive) { //If enemy is alive
				if (randNum == 1) { //CyberHack
					cout << RED << "'BZZZZT IM TERMINATING IT' (NOT IMPLEMENTED)" << RESET << endl;
				}
				//==================================================================================================
				else if (randNum == 2 or randNum == 3) { //Taking Cover
					cout << RED << "'BZZZZZT OPTIMAL COVER FOUND'" << RESET << endl;
					foes.at(i).notInCover = false;
				}
				//==================================================================================================
				else if (randNum >= 4 and randNum <= 6) { //Shooting
					CombatDialogue(false, true);  
					cout << RED << "'BZZZT TARGET FOUND: FIRING'" << RESET << endl;
					if (playerNotInCover) { //If player is not in cover then attack lands
						if (randDodge <= Vex.dodgeChance) {
							cout << YELLOW << "Vex: 'Phew, close one' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= foes.at(i).critChance) {
							cout << RED << "'BZZT WEAKPOINT DETECTED' (CRIT)" << RESET << endl;
							hp -= 2 * foes.at(i).dmg * Vex.armor; 
							dmg = 2 * foes.at(i).dmg * Vex.armor; 
							cout << RED << "\t" << dmg << "-DMG" << RESET << endl;
						} 
						else { 
							hp -= foes.at(i).dmg * Vex.armor; 
							dmg = foes.at(i).dmg * Vex.armor; 
							cout << RED << "\t" << dmg << "-DMG" << RESET << endl;
						}
					}
					else { cout << YELLOW  << "Vex: 'Not a chance' (IN COVER)\n" << RESET;} //Dialogue if player is taking cover
				}
				//==================================================================================================
				else { //Attacking
					CombatDialogue(false, true);  
					cout << RED << "'BZZZZT TARGET FOUND: ATTACKING'" << RESET << endl;
					if (playerNotInCover) {
						if (randDodge <= Vex.dodgeChance) {
							cout << YELLOW << "Vex: 'Phew, close one' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= foes.at(i).critChance) {
							cout << RED << "'BZZT WEAKPOINT DETECTED' (CRIT)" << RESET << endl;
							hp -= 2 * foes.at(i).dmg * Vex.armor; 
							dmg = 2 * foes.at(i).dmg * Vex.armor; 
							cout << RED << "\t" << dmg << "-DMG" << RESET << endl;
						} 
						else { 
							hp -= foes.at(i).dmg * Vex.armor; 
							dmg = foes.at(i).dmg * Vex.armor; 
							cout << RED << "\t" << dmg << "-DMG" << RESET << endl;
						}
					}
					else { cout << YELLOW << "Vex: 'Not a chance' (IN COVER)\n" << RESET;} //Dialogue if player is taking cover
				}
				//==================================================================================================
			}
		}
		//==================================================================================================
		for (int i = 0; i < foes.size(); i++) {
			foesCopy.at(i).health = foes.at(i).health;
			foesCopy.at(i).alive = foes.at(i).alive;
			foesCopy.at(i).notInCover = foes.at(i).notInCover;
			
			if (foes.at(i).turnHacked == turnCount) {
				foes.at(i) = foesCopy.at(i);
				cout << "Enemy " << i + 1 << " Status effect reverted\n";
			}
		}
		
		turnCount++; //End of Enemy Turn;
		
		for (int i = 0; i < foes.size(); i++) {
			foesCopy.at(i).health = foes.at(i).health;
			foesCopy.at(i).alive = foes.at(i).alive;
			foesCopy.at(i).notInCover = foes.at(i).notInCover;
			
			if (foes.at(i).turnHacked == turnCount) {
				foes.at(i) = foesCopy.at(i);
				cout << "Enemy " << i + 1 << " Status effect reverted\n";
			}
		}
		//==================================================================================================

		if (hp <= 0) { hp = 0; }
		cout << YELLOW << "Vex: " << GREEN << hp << " hp" << RESET << endl; //Test
		//Win/loss conditions
		if (hp <= 0) { //If Player dies
			//return false;a
			Die();
		}
		else if (battleEnds) { //If all enemies are dead
			break;
		}

	    playerNotInCover = true;
		battleEnds = true;
		cout << endl << "Player Turn " << turnCount << ":\n";
		BattleControls(); //Displays Controls
		cin >> input;
	}
	//If won then distribute xp
	BattleWon(foes);
	return true;
}
//==================================================================================================
//                                END OF COMBAT



bool RazeMissionBrief() { //change dialogue
//	setbgcolor(40, 0, 60); // bluish pruple;
	setbgcolor(60, 0, 50); //pinkish purple ;
	cout << CYAN << "[Incoming Call: RAZE]\n";
	cout << "Raze: Yo, Vex — you online ? Good. The city’s buzzin tonight, all neon wrappin straight lies in vibrant colors.\n";
	cout << "Syntek’s messin with heads again, They got their claws deep in every brain on the block.\n";
	cout << "Hear that Static? It's in every damn frequency. We're pullin the plug on this shit tonight.\n";
	cout << "Heres the plan, you get in and get your hands dirty. I'll keep you from getting caught. We’re hitting Syntek Tower at it's core.\n";
	cout << "You’ll need to break down those ICE walls, dance past the patrols, and drop the liberation virus into their mainframe.\n";
	cout << "I'll net-guide, you ground-pound. I'll ghost our presence - got that?.\n";
	cout  << "Remember, stay low, and don’t fry your deck." << RESET << endl;
	setbgcolor(30, 30, 30); // dark gray

	cout << WHITE << "\nRun a tactical simulation of Mission 1 now? (y/n): " << RESET;

	string ans;
	if (!std::getline(cin, ans)) ans.clear();
	while (!ans.empty() && (ans.back() == ' ' || ans.back() == '\t' || ans.back() == '\r')) ans.pop_back();
	setbgcolor(30, 30, 30);
	if (!ans.empty() && (ans[0] == 'Y' || ans[0] == 'y')) {
		cout << YELLOW << "You: Plugged in. Running the BD now.\n" << RESET;
		return true;
	} else {
		setbgcolor(30, 30, 30);
		cout << CYAN << "Raze: Your loss, choom.\n" << RESET;
		return false;
	}
}
//extra dialogue ideas
/*
void CombatDialogue(bool playerAttacking, bool enemyattacking) {
	vector<string> RazeResponses = {
		"Raze: PREEM! nice shot",
		"Raze: That hunk of scraps's gonna need some serious repairs!",
		"Raze: Their hacks are worse than my GrandMa's",
		"Raze: Another corpo bites the digital dust"
	};
	if (playerAttacking) {
		setbgcolor(0, 0, 80);
		int Razerand =  rand() % RazeResponses.size();
		cout << CYAN << RazeResponses.at(Razerand) << endl;
	}

	vector<string> enemyresponse  = {
		"SYNTEX BOT: SYNTEX Property, FREEZE!",
		"SYNTEX BOT: INTRUDER WARNING, PREPARE TO BE NUETRALIZED",
		"SYNTEX BOT: CORPORATE PROPERTY, DO NOT ENGANGE ANY FURTHER",
		"SYNTEX BOT: INTRUDER WARNING, LETHAL FORCE IS AUTHORIZED"
	};

	vector<string> enemyattackRaze  = {
		"INCOMING! Netrunner attack",
		"Raze: Watch out choom, dont make me have to find a new partner",
		"Raze: Hard chrome hit choom, dont flatline on me",
		"Raze: Security getting a little tough, look alive",
		"Raze: Ouch, try not to get zeroed"
	};

	if (enemyattacking) {
		int enemyrand = rand() %  enemyresponse.size();
		cout << RED <<  enemyresponse.at(enemyrand) << endl;

		int razeresponse = rand() % enemyattackRaze.size();
		cout << CYAN << enemyattackRaze.at(razeresponse) << endl;


	}
}
*/
int main() {

	RazeMissionBrief();
//	CombatDialogue(true, false);  >>>> ADD THIS LATER






	cout << YELLOW << "\n*Holo-screen flickers to life...*" << RESET << endl;
// INTRO Banner
	cout << MAGENTA << R"(
/---------------------------------------------------------------------\
/-                                                                   -\
\-                      W E L C O M E   T O   T H E                 -/
 /-                                                                 -\
)" << RESET;


    cout << YELLOW << R"(
             _____   ___   _   _   _____  ______
            |  _  \ / _ \ | \ | | /  __ \ |  ___|
            | |  | | /_\ \|  \| | | /  \/ |_|__
            | | | |   _  || . ` | | |     |____|
            | |/ / | | | || |\  | | \__/\ | |___
            |___/  \_| |_/\_| \_/  \____/ |_____|
)" << RESET;


    cout << MAGENTA << R"(
 \-                                                                 -/
 /-                     E  D  G  E  R  U  N  N  E  R                -\
\-                                                                   -/
\---------------------------------------------------------------------/
)" << RESET << endl;

    // START OF RPG
    cout << CYAN << "[Incoming Call: RAZE]" << RESET << endl;
    cout << CYAN << "Raze: Yo, choom... you ready to dance?" << RESET << endl;

	Fight(true);



return 0;
}
