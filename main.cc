//Fill out this comment with your names and which bullet points you did
//Partners: Kwabe
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include <cmath>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <cmath> //NEED TO ADD THIS TO MAIN
#include <limits> //NEED TO ADD THIS TO MAIN
#include <iomanip> //NEED TO ADD THIS TO MAIN
#include <unistd.h>

using namespace std;

//COLOR MAP: Player=YELLOW Raze=CYAN Enemy=RED Basic=WHITE
/// movecursor(5, 20);
// setcolor(6, 7, 67);
// setbgcolor(67, 67, 67);
// set_raw_mode(true);
//char ch =


bool RazeMissionBrief() {//change dialogue
	cout << CYAN << "[Incoming Call: RAZE]\n"
	     << "Raze: Yo, Vex — you online ? Good. The city’s humming tonight, all neon and lies.\n"
	     << "Syntek’s got their claws deep in every brain on the block. ECHO’s whispering through implants like a ghost in the code.\n"
	     << "Yeah, I hear it. Static in every frequency. We shut it down tonight.\n"
	     << "You get in, I keep the line open. We’re hitting Syntek Tower — center of the storm.\n"
	     << "You’ll need to crack five ICE walls, dance past the patrols, and drop the liberation virus into their mainframe.\n"
	     << "I’ll be your eyes in the net. You handle the ground work, I’ll ghost the signal.\n"
	     << "Raze: Remember, stay low, and don’t fry your deck." << RESET << endl;

	cout << WHITE << "\nRun BD-tacticalSim? (y/n): " << RESET;

	string ans;
	if (!std::getline(cin, ans)) ans.clear();
	while (!ans.empty() && (ans.back() == ' ' || ans.back() == '\t' || ans.back() == '\r')) ans.pop_back();
	if (!ans.empty() && (ans[0] == 'Y' || ans[0] == 'y')) {
		cout << YELLOW << "You: Plugged in. Running the BD now.\n" << RESET;
		return true;
	} else {
		cout << CYAN << "Raze: Your loss, choom.\n" << RESET;
		return false;
	}
}

//First convo with Raze
void RazeReplyMenu() {
	cout << WHITE << "\n[Reply options]" << RESET << endl;
	cout << WHITE << "  1) \"Always ready. Feed me intel.\"\n"
	     << "  2) \"Hold up—what’s the plan?\"\n"
	     << "  3) \"Quit the chatter, gotta focus up.\"\n"
	     << "  4) Type my own reply\n" << RESET;
	string choice;
	while (true) {
		cout << WHITE << "Choose 1-4: " << endl << RESET;
		choice = readline(cin);
		if (choice == "1" || choice == "2" || choice == "3" || choice == "4") break;
		cout << WHITE << "(Invalid. Try again.)\n" << endl << RESET;
	}

	if (choice == "1") {
		cout << YELLOW << "You: Always ready. Feed me intel." << RESET << endl;
		cout << CYAN   << "Raze: Copy. Patrol drone east, guards sweeping da streets. Keep low, choom.\n"
		     "You're going to need to find a terminal to get started." << RESET << endl;
	} else if (choice == "2") {
		cout << YELLOW << "You: Hold up—what’s the plan?" << RESET << endl;
		cout << CYAN   << "Raze: Crack the alley terminal, slide past the Syntek gaurds, head to Syntek tower. Clean and quiet." << RESET << endl;
	} else if (choice == "3") {
		cout << YELLOW << "You: Quit the chatter, gotta focus up." << RESET << endl;
		cout << CYAN   << "Raze: Heh - deres dat edgerunner attitude. Best of Luck choom\n"
		     "You're going to need to find a terminal to get started." << RESET << endl;
	} else { // "Type my own reply"
		cout << WHITE << "Type your reply: " << RESET;
		string freeReply = readline(cin);
		if (freeReply.empty()) freeReply = "...";
		cout << YELLOW << "You: " << freeReply << RESET << endl;

		// easter egg line from Raze based on input
		if (freeReply.find("?") != string::npos) {
			cout << CYAN << "Raze: Questions later—hit the terminal first, should be around here. I’ll keep the feed hot." << RESET << endl;
		} else if (freeReply.size() <= 6) {
			cout << CYAN << "Raze: Short and sweet. Moving you a route ping now.\n"
			     "You're lookin for a terminal." << RESET << endl;
		} else {
			cout << CYAN << "Raze: Logged. I’ll patch in updates while you move. Optics up.\n"
			     "Got a ping on somethin in the alley!" << RESET << endl;
		}
	}
}

//START
bool firstPuzzle() {
	cout << WHITE << endl << "You approach a humming street treminal in a dark alleyway.\n"
	     << "Its screen seems to be cracked from an impact of some sort. Next to it stands you and Raze's old apartment, #2077." << RESET << endl << endl;
	cout << CYAN << "[Incming Call: RAZE]\n"
	     << "Raze: Yoo choom ... \n"
	     << "You right next to our old livin space!\n"
	     << "Good old #2077! Treated us well.!\n"
	     << "Man times were simpler way back then...I miss it sometimes" << RESET << endl << endl;

	string ans;
	cout << "Interact with terminal? (y/n): " << RESET;
	getline(cin, ans);
	while (!ans.empty() && (ans.back() == ' ' || ans.back() == '\t' || ans.back() == '\r')) ans.pop_back();
	if (!ans.empty() && (ans[0] == 'n' || ans[0] == 'N')) {
		cout << CYAN << "Raze: Yo Choom! Giving up already?!.\n" << RESET;
		cout << YELLOW << "You: Yeah, sorry I'm out." << endl;
		cout << CYAN << "Your loss, choom. We coulda made history..." << RESET << endl;
		return false;
	}
	cout << WHITE << "Terminal: ENTER 4-DIGIT ACCESS CODE (3 attempts till locked out).\n";

	//Terminal puzzle
	const string code = "2077";
	for (int attempt = 1; attempt < 4; ++attempt) {
		cout << WHITE << "Attempt " << attempt << "/3 — code: " << RESET;
		string guess;
		getline(cin, guess);
		if (guess == code) {
			cout << GREEN << endl << "Terminal: ACCESS GRANTED. CAMERAS  TEMPORARILY DISABLED." << endl;
			cout << CYAN << "Raze: Knew you had it. Keep movin’...Syntek patrol’s nearby." << endl;
			return true;
		}
		if (attempt < 3) {
			if (attempt == 1) {
				cout << CYAN << "Raze: Ooo a code...wonder if it has anything to do with our old apartment?" << endl;
				cout << WHITE << "INCORRECT...TRY AGAIN" << endl;
			} else if (attempt == 2) {
				cout << CYAN << "Raze: You know I always thought we got lucky with our apartment number." << endl
				     << "Maybe that's somethin?" << endl;
			}
		}
	}
	cout << RED << endl << "Terminal: ACCESS DENIED. Firewall locked you out.\n"
	     "*You hear boots on wet chrome*" << endl;
	cout << CYAN << "Raze: Damnit, they locked it. Patrol spotted you on the cameras. Be ready for some action!" << RESET << endl;
	return false;
}

bool secondPuzzle() {
	// Show scene
	cout << WHITE << "\nYou reach a sealed door. A neon mural flickers beside the panel.\n" << RESET;
	cout << CYAN  << "[Incoming Call: RAZE] This isn't a keypad, choom. Read the wall. Each row hides the path.\n" << RESET;

	// The “image” — look for the only doubled arrow per row.
	cout << MAGENTA <<    "\n/==================== NEON GLITCH MURAL =====================\\\n" << RESET;
	cout << YELLOW <<    "  Row 1:   >   <  ^   <   <   V   <   <<    <   <   ^   ^   <  \n"
	     "  Row 2:   >   >   >  >   <<   <   V   ^    >   <   >   V   V\n"
	     "  Row 3:   v   ^   V   <   >   <   ^   >    V  ^^   >   <   <\n"
	     "  Row 4:   ^   VV  ^   <   <   <   >   V    ^   ^   >   <   >\n"
	     "  Row 5:   <   V   <    <    ^    ^    V    <   >  >>   <   ^\n" << RESET;
	cout << MAGENTA <<  "\\============================================================/\n" << RESET;
	cout << WHITE  << "Enter the 5-step path (use L/R/U/D, e.g., L R D U L or LRDUL):\n" << RESET << endl;

	// Solution based on doubled arrows:
	// Row1: <<  = L
	// Row2: <<  = L
	// Row3: ^^  = U
	// Row4: VV  = D
	// Row5: >>  = R
	string solution = "LLUDR";

	int attempts = 3;
	for (int a = 1; a <= attempts; ++a) {
		cout << WHITE << "Attempt " << a << "/" << attempts << " - " << RESET;

		string raw;
		getline(cin, raw);

		// Normalize input to only the letters L/R/U/D (uppercase)
		string guess;
		for (size_t i = 0; i < raw.size(); ++i) {
			char c = raw[i];
			if (c >= 'a' && c <= 'z') c = c - 'a' + 'A'; // to upper
			if (c == 'L' || c == 'R' || c == 'U' || c == 'D') {
				guess.push_back(c);
			}
		}

		// If user entered spaces or fewer/more letters, keep only first 5 valid chars
		if (guess.size() > 5) guess = guess.substr(0, 5);

		// Basic check: must be 5 directions
		if (guess.size() != 5) {
			cout << CYAN << "[Raze] Needs FIVE steps, choom. One for each row.\n" << RESET;
		} else if (guess == solution) {
			cout << GREEN << endl << "Door: *CLACK* Pattern verified. Bolts retract.\n" << RESET;
			cout << CYAN  << "[Raze] Clean read. You’re getting the eye for this.\n"
			     << "Keep it moving!\n" << RESET;
			return true;
		} else {
			// Wrong 5-letter path
			if (a == 1) {
				cout << CYAN << "[Raze] Look CLOSE — in each row, ONE arrow is doubled. That’s the answer for that row.\n" << RESET;
			} else if (a == 2) {
				cout << CYAN << "[Raze] Translate the doubles, row by row: LEFT, RIGHT, DOWN, UP, LEFT.\n" << RESET;
			}
		}
	}


// Lockout after all tries
	cout << RED << endl << "Door: Pattern invalid. Lockdown engaged... *vents hiss with cold air.*\n" << RESET;
	cout << CYAN  << "[Raze] They iced it. We’ll find another route.\n" << RESET;
	return false;
}

bool thirdPuzzle() {
	srand(static_cast<unsigned>(time(nullptr)));
	double target = 90 + rand() % 30; // random 90–120 MHz
	double guess;
	int tries = 0;
	double diff = fabs(guess - target);

	cout << WHITE << "\n*You reach the comms hub. The console flickers with static.*" << RESET << endl;
	cout << CYAN << "[Incoming Call: RAZE] You’re near the jammer node. Tune the signal between 80.0 and 120.0 MHz." << RESET << endl;
	cout << CYAN << "Raze: Get within one meg of the sweet spot and I’ll lock it down." << RESET << endl;

	while (tries < 5) {
		cout << WHITE << "\nAttempt " << (tries + 1) << "/5 — Enter frequency: " << RESET;
		cin >> guess;
		tries++;

		if (fabs(guess - target) < 0.5) {
			cout << GREEN << endl << "Signal locked. Connection stabilized." << RESET << endl;
			cout << CYAN << "Raze: Boom! You’re on their grid, choom. Let's give ourselves a little heads up...shall we?" << RESET << endl;
			cout << YELLOW << "You: Don't mind if I do." << RESET << endl;
			return true;
		} else if (diff <= 2.0) {
			// Assisted success — close enough, Raze helps fix it
			cout << GREEN << "Signal unstable... recalibrating...\n" << RESET;
			cout << CYAN  << "Raze: You were close...I gave it a nudge. Signal locked, but that’s my assist, choom.\n"
			     "Let's see what those gear heads are up to" << RESET << endl;
			return true;
		} else if (guess < target) {
			cout << CYAN << "Raze: Too low. Static’s deep — raise the band." << RESET << endl;
		} else if (guess > target) {
			cout << CYAN << "Raze: Too high. You’re past the signal; bring it down." << RESET << endl;
		}
	}

	cout << RED << "\nStatic overwhelms the channel. You lose the feed completely." << RESET << endl;
	cout << CYAN << "Raze: Damn. We’re flying blind, keep your optics sharp." << RESET << endl;
	return false;
}

//extra dialogue ideas
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

//=================================================================================================
struct Player {
	int level = 1;
	int xp = 0;

	int dmg = 10;
	int health = 50;
	int ram = 2;
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
	cout << "\tPrecision: " << Vex.critChance << "%" <<  endl;
	cout << "\tSwiftness: " << Vex.dodgeChance << "%" << endl;
	cout << "\tArmor: " << abs(Vex.armor * 100 - 100) << "%"  << endl;
	cout << endl;
}
//=================================================================================================

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
	int randLvl, randDmg, randHealth, randRam, randCrit, randDodge, randEnemies;
	float randArmor;

	cout << fixed << setprecision(2);
	//Enemy bot{1, 5, 10, 3, 10, 5, 1.00, true, true, 0, false, false, false}; //Sets Enemy stats
	//Enemy bot{randLvl, randDmg, randHealth, randRam, randCrit, randDodge, randArmor, true, true, 0, false, false, false}; //Sets Enemy stats
	//Enemy bot{1, 75, 150, 9, 50, 5, 0.50, true, true, 0, false, false, false}; // BUFFED OUT ENEMY
	//Enemy bot{1, 75, 150, 9, 50, 5, 0.50, true, true, 0, false, false, false}; // BUFFED OUT ENEMY
	if (Vex.level <= 4) { //Adds an enemy based on level
		randEnemies = rand() % 2 + 1;
		for (int i = 0; i < randEnemies; i++) {
			randLvl = rand() % 5 + 1;
			randDmg = rand() % 5 + 11;
			randHealth = rand() % 10  + 11;
			randRam = rand() % 3  + 1;
			randCrit = rand() % 10  + 1;
			randDodge = rand() % 5  + 1;
			randArmor = 1.00 - fmodf(static_cast <float>(rand()), 0.05);  //fmodf from cmath lib doing modulo work on floats / static_cast since rand() is an int
			Enemy bot{randLvl, randDmg, randHealth, randRam, randCrit, randDodge, randArmor, true, true, 0, false, false, false}; //Sets Enemy stats
			foes.push_back(bot);
		}
	} else if (Vex.level <= 9) {
		randEnemies = rand() % 2 + 2;
		for (int i = 0; i < randEnemies; i++) {
			randLvl = rand() % 5 + 6;
			randDmg = rand() % 5 + 21;
			randHealth = rand() % 10  + 21;
			randRam = rand() % 3  + 1;
			randCrit = rand() % 10  + 1;
			randDodge = rand() % 5  + 1;
			randArmor = 1.00 - fmodf(static_cast <float>(rand()), 0.05);  //fmodf from cmath lib doing modulo work on floats / static_cast since rand() is an int
			Enemy bot{randLvl, randDmg, randHealth, randRam, randCrit, randDodge, randArmor, true, true, 0, false, false, false}; //Sets Enemy stats
			foes.push_back(bot);
		}
		//foes.push_back(bot);
		//foes.push_back(bot);
	} else {
		//foes.push_back(bot);
		//foes.push_back(bot);
		//foes.push_back(bot);
	}

}
//=================================================================================================

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
			cout << RED << "Enemy " << i + 1 << ": DEAD" << RESET << endl;
		} else {
			cout << RED << "Enemy " << i + 1 << ": " << foes.at(i).health << " hp" << RESET << endl;
		}
	}
}
//=================================================================================================

void BattleControls() {
	cout << YELLOW << endl;
	cout << "\t1: Use Melee\n";
	cout << "\t2: Use Gun\n";
	cout << "\t3: Take Cover\n";
	cout << "\t4: CyberHack\n";
	cout << "\t5: Analyze Enemy\n";
	cout << RESET << endl;
}
//=================================================================================================

void BattleWon(vector<Enemy> &foes) { //If won distribute xp and raise lvl if needed (if lvl is raised then ask to add stat points
	int battleXp = 25 * foes.size();
	int playerChoice;
	int lvlTimes;

	cout << endl;
	cout << YELLOW << "Vex: 'That was tooo easy'" << RESET << endl;
	cout << endl;
	cout << "BATTLE OVER:\n";
	//Vex.xp += 25 * foes.size();
	for (int i = 0; i < foes.size(); i++) {
		Vex.xp += 20;
		Vex.xp = Vex.xp + foes.at(i).level * 5;
	}
	lvlTimes = Vex.xp / 100;
	cout << GREEN << "\t(" << battleXp << " Exp earned)\n";
	cout << "\tCurrent lvl: " << Vex.level << endl;
	cout << "\tCurrent xp: " << Vex.xp << endl;
	if (Vex.xp >= 100) {
		for (int i = 0; i < lvlTimes; i++) {
			cout << "\tLEVEL INCREASED\n";
			Vex.level += 1; // lvl increase
			Vex.xp = 0; //Resets xp to 0 if lvls up
			playerChoice = read("Choose a stat to upgrade: {1-Damage, 2-Max Health, 3-RAM, 4- Precision, 5-Swiftness, 6-Armor}\n");
			cout << RESET;
			if (playerChoice == 1) {
				Vex.dmg += 5;
			} else if (playerChoice == 2) {
				Vex.health += 5;
			} else if (playerChoice == 3) {
				Vex.ram += 1;
			} else if (playerChoice == 4) {
				Vex.critChance += 5;
			} else if (playerChoice == 5) {
				Vex.dodgeChance += 5;
			} else if (playerChoice == 6) {
				Vex.armor -= 0.02;
			}

			ViewStats(Vex); //Displays new stats
		}
	}
	cout << endl;
}
//=================================================================================================
void Die() {
	cout << BLUE << "You Flatlined." << RESET << endl;
	exit(0);
}
//START OF COMBAT
//=================================================================================================
bool Fight(bool enemyGoesFirst) {
	int hp = Vex.health; //Sets players new health for every battle
	int dmg; //Used to print out dmg output for enemy and player
	int randNum;
	int randCrit;
	int randDodge;
	int randHack;
	int randControl;
	int playerInput, secondInput;
	int turnCount = 1; //Iterator / turn count
	int turnPlayerHackEnds; //Holds the value(turn) in which the hack should end
	int turnEnemyHackEnds;  //
	string input; // 1 2 3 4 or 5
	bool playerNotInCover = true;
	bool playerIsStunned = false;
	bool playerIsHacked = false;
	bool hackLanded = false;
	bool battleEnds = true;

	//movecursor(0,0);

	if (enemyGoesFirst) {
		cout << RED << "ENEMY GOES FIRST\n" << RESET;    //Test to see if enemy is supposed to go first or not
	} else {
		cout << GREEN << "PLAYER GOES FIRST\n" << RESET;
	}

	//Enemy bot{1, 5, 10, 3, 10, 5, 1.00, true, true}; //Sets Enemy stats
	vector<Enemy> foes;   //Holds the foes in battle
	SetEnemies(foes);     //Sets Amount of foes through function
	vector<Enemy> foesCopy = foes; //Use to reset the stats back to original

	EnemyCheck(foes);

	if (enemyGoesFirst == true and turnCount == 1) {
		cout << "Player Turn 1:\n" << endl;
		cout << "(PLAYER TURN SKIPPED) \n";
	} else {
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
							} else if (randCrit <= Vex.critChance) {
								cout << YELLOW << "Vex: 'Jackpot' (CRIT)" << RESET << endl;
								foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor;
								dmg = 2 * Vex.dmg * foes.at(i).armor;
								cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
								CombatDialogue(true, false);
							} else {
								foes.at(i).health -= Vex.dmg * foes.at(i).armor;
								dmg = Vex.dmg * foes.at(i).armor;
								cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
								CombatDialogue(true, false);
							}
						} else {
							cout << RED << "'BZZT INCOMING THREATS EVADED' (IN COVER)\n" << RESET;   //Dialogue if enemy is taking cover
						}
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
						cout << WHITE << "You Hesitate (TURN SKIPPED)" << RESET << endl;
						break;
					}

					if (playerInput == i + 1) {
						clearscreen(); //Clears the screen
						cout << YELLOW << "Vex: 'FIRIINGGG'" << RESET <<  endl;
						if (foes.at(i).notInCover) {
							if (randDodge <= foes.at(i).dodgeChance) {
								cout << RED << "'BZZZT EVASIVE MODE ACTIVATED' (Atk Dodged)" << RESET << endl;
							} else if (randCrit <= Vex.critChance) {
								cout << YELLOW << "Vex: 'Jackpot' (CRIT)" << RESET << endl;
								foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor;
								dmg = 2 * Vex.dmg * foes.at(i).armor;
								cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
								CombatDialogue(true, false);
							} else {
								foes.at(i).health -= Vex.dmg * foes.at(i).armor;
								dmg = Vex.dmg * foes.at(i).armor;
								cout << YELLOW << "\t" << dmg << "-DMG" << RESET << endl;
								CombatDialogue(true, false);
							}
						} else {
							cout << RED << "'BZZT INCOMING THREATS EVADED' (IN COVER)\n" << RESET;   //Dialogue if enemy is taking cover
						}
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
				cout << WHITE << "Choose a target" << RESET << endl;

				cin >> playerInput;
				for (int i = 0; i < foes.size(); i++) {
					if (!cin) {  //IF INPUT IS NOT AN INTEGER
						cin.clear();
						string s;
						cin >> s;
						cout << endl;
						clearscreen(); //Clears the screen
						cout << WHITE << "You Hesitate (TURN SKIPPED)" << RESET << endl;
						break;
					}

					if (playerInput == i + 1) {
						if (foes.at(i).hacked) {
							clearscreen(); //Clears the screen
							cout << "Enemy is already currently hacked.\n";
							break;
						} else if (Vex.ram >= foes.at(i).ram) {
							hackLanded = true;
							cout << "Hack has a 100" << "%" << " Chance of landing.\n";
						} else if (Vex.ram >= foes.at(i).ram * 2 / 3) {
							//cout << foes.at(i).ram * 2/3 << endl; //Test
							if (randHack <= 50) {
								hackLanded = true;
							}
							cout << "Hack has a 50" << "%" << " Chance of landing.\n";
						} else {
							clearscreen(); //Clears the screen
							cout << "Enemy cyberware is too hard to decrypt. \n";
							break;
						}

						cout << "Choose a CyberHack: {1-Armor Strip, 2-Visual Overload, 3-Mind Control}\n\n";
						cin >> secondInput;
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
						if (secondInput == 1 && hackLanded) { //Armor Strip
							foes.at(i).armor = 1.00;  //Resets the value or armor
							foes.at(i).hacked = true; //Sets the enemy as currently hacked
							turnEnemyHackEnds = turnCount + 7; //Should hold the value the turn that the hack should end
							foes.at(i).turnHacked = turnEnemyHackEnds;
						} else if (secondInput == 2 && hackLanded) { //Visual Overload
							foes.at(i).stunned = true;
							foes.at(i).hacked = true; //Sets the enemy as currently hacked
							turnEnemyHackEnds = turnCount + 7; //Should hold the value the turn that the hack should end  TODO: ADJUST THIS VARIABLE TO LAST LONGER
							foes.at(i).turnHacked = turnEnemyHackEnds;
						} else if (secondInput == 3 && hackLanded) { //Mind Control
							if (foes.size() == 1) {
								clearscreen(); //Clears the screen
								hackLanded = false;
								cout << "Enemy has no allies to attack.\n";
								break;
							} else {
								foes.at(i).controlled = true;
								foes.at(i).hacked = true; //Sets the enemy as currently hacked
								turnEnemyHackEnds = turnCount + 7; //Should hold the value the turn that the hack should end
								foes.at(i).turnHacked = turnEnemyHackEnds;
							}
						}
						//=================================================================================================

					}
					clearscreen(); //Clears the screen
				}
				//=================================================================================================
				if (hackLanded) {
					clearscreen(); //Clears the screen
					cout << YELLOW << "Vex: 'IM HACKKIN IT' (SUCCESS)\n" << RESET;
					cout << "Hack ends in Turn " << turnEnemyHackEnds << ":\n";
					hackLanded = false; //Resets it once used
				} else {
					cout << "Hack unsuccessful. (MISSED)\n";
				}
				//=================================================================================================
			} else if (input == "5") {
				clearscreen(); //Clears the screen
				ViewEnemyStats(foes);
				cout << YELLOW << "Vex: 'Hmm I See'" << RESET << endl;
				cout << "Player Turn " << turnCount << ":\n\n";
				BattleControls(); //Displays Controls
				cin >> input;
				continue;
			} else {
				cout << WHITE << "You Hesitate (TURN SKIPPED)" << RESET << endl;
			}
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
			randControl = rand() % foes.size();
			randCrit = rand() % 100 + 1;  //For enemy crit
			randHack = rand() % 100 + 1;  //For enemy cyberhack
			randDodge = rand() % 100 + 1; //For player dodge
			//cout << randNum << endl; //Test

			//==================================================================================================
			if (foes.at(i).alive == false) {
				//NEEDED SINCE if statements below will skip the statement causing them to print below
			} else if (foes.at(i).stunned) { //If enemy is stunned
				cout << RED << "BZZZZT OPTICAL SYSTEM MALFUNCTION (STUNNED)\n" << RESET;
			} else if (foes.at(i).controlled) {
				cout << RED << "BZZZT TARGETTING SYSTEM MALFUNCTION (MIND CONTROLLED)\n" << RESET;
				//cout << "TEST PRINTING OUT : RANDCONTROL " << randControl << endl;
				for (int j = 0; j < foes.size(); j++) {
					if (randControl == i) {
						randControl = rand() % foes.size();
						continue;
					}
					if (i == j) {
						//SKIP (DONT LET THEM ATTACK THEMSELVE)
					} else if (randControl == j) {
						cout << GREEN << "BZZZZT IM BOUTTA ATTACK (ATTACKED ENEMY " << j + 1 << ")" << RESET;
						foes.at(j).health = foes.at(j).health - (foes.at(i).dmg * foes.at(j).armor);
						dmg = (foes.at(i).dmg * foes.at(j).armor);
						cout << GREEN << " (" << dmg << "-DMG)" << RESET << endl;
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
					cout << RED << "'BZZZT TARGET FOUND: FIRING' " << RESET;
					if (playerNotInCover) { //If player is not in cover then attack lands
						if (randDodge <= Vex.dodgeChance) {
							cout << YELLOW << "Vex: 'Phew, close one' (Atk Dodged)" << RESET << endl;
						} else if (randCrit <= foes.at(i).critChance) {
							cout << endl << RED << "'BZZT WEAKPOINT DETECTED' (CRIT)" << RESET;
							hp = hp - 2 * (foes.at(i).dmg * Vex.armor);
							dmg = 2 * foes.at(i).dmg * Vex.armor;
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						} else {
							hp = hp - (foes.at(i).dmg * Vex.armor);
							dmg = foes.at(i).dmg * Vex.armor;
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						}
					} else {
						cout << YELLOW  << "Vex: 'Not a chance' (IN COVER)\n" << RESET;   //Dialogue if player is taking cover
					}
				}
				//==================================================================================================
				else { //Attacking
					cout << RED << "'BZZZZT TARGET FOUND: ATTACKING' " << RESET;
					if (playerNotInCover) {
						if (randDodge <= Vex.dodgeChance) {
							cout << YELLOW << "Vex: 'Phew, close one' (Atk Dodged)" << RESET << endl;
						} else if (randCrit <= foes.at(i).critChance) {
							cout << endl << RED << "'BZZT WEAKPOINT DETECTED' (CRIT)" << RESET;
							hp = hp - 2 * (foes.at(i).dmg * Vex.armor);
							dmg = 2 * foes.at(i).dmg * Vex.armor;
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						} else {
							hp = hp - (foes.at(i).dmg * Vex.armor);
							dmg = foes.at(i).dmg * Vex.armor;
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						}
					} else {
						cout << YELLOW << "Vex: 'Not a chance' (IN COVER)\n" << RESET;   //Dialogue if player is taking cover
					}
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

		if (hp <= 0) {
			hp = 0;
		}
		cout << YELLOW << "Vex: " << GREEN << hp << " hp" << RESET << endl; //Test
		//Win/loss conditions
		if (hp <= 0) { //If Player dies
			//return false;a
			Die();
		} else if (battleEnds) { //If all enemies are dead
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
//END OF COMBAT

int main() {

	bool breif = RazeMissionBrief();
	if (!breif) return 0;
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
    cout << CYAN << "Raze: Yo, choom... you ready to dance?\n" << RESET << endl;
	RazeReplyMenu();
	bool puzzle = firstPuzzle();
	if (!puzzle) return 0;
	Fight(false); //TRUE FOR ENEMY TURN FIRST / FALSE FOR PLAYER TURN FIRST
	puzzle = secondPuzzle();
	Fight(true);
	puzzle = thirdPuzzle();



	return 0;
}
