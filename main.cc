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
#include <iomanip> //NEED TO ADD THIS TO MAIN
#include <unistd.h>
using namespace std;

//COLOR MAP: Player=YELLOW Raze=CYAN Enemy=RED Basic=WHITE
/// movecursor(5, 20);
// setcolor(6, 7, 67);
// setbgcolor(67, 67, 67);
// set_raw_mode(true);
//char ch =

//FIRST DIALOG W RAZE
void RazeReplyMenu() {
    cout << WHITE << "\n[Reply options]" << RESET << endl;
    cout << WHITE << "  1) \"Always ready. Feed me intel.\"\n"
         << "  2) \"Hold up—what’s the plan?\"\n"
         << "  3) \"Quit the chatter, gotta focus up.\"\n"
         << "  4) Type my own reply\n" << RESET;
    string choice;
    while (true) {
        cout << WHITE;
        choice = readline("Choose 1-4: ");
        cout << RESET;
        if (choice == "1" || choice == "2" || choice == "3" || choice == "4") break;
        cout << WHITE << "(Invalid. Try again.)\n" << RESET;
    }

    if (choice == "1") {
        cout << YELLOW << "You: Always ready. Feed me intel." << RESET << endl;
        cout << CYAN   << "Raze: Copy. Patrol drone east, guard on the roof. Keep low, choom." << RESET << endl;
    } else if (choice == "2") {
        cout << YELLOW << "You: Hold up—what’s the plan?" << RESET << endl;
        cout << CYAN   << "Raze: Crack the alley terminal, slide past the ICE, then sprint south. Clean and quiet." << RESET << endl;
    } else if (choice == "3") {
        cout << YELLOW << "You: Quit the chatter, gotta focus up." << RESET << endl;
        cout << CYAN   << "Raze: Heh - deres dat edgerunner attitude. Best of Luck choom" << RESET << endl;
    } else { // "Type my own reply"
        cout << WHITE;
        string freeReply = readline("Type your reply: ");
        cout << RESET;
        if (freeReply.empty()) freeReply = "...";
        cout << YELLOW << "You: " << freeReply << RESET << endl;

        // easter egg line from Raze based on input
        if (freeReply.find("?") != string::npos) {
            cout << CYAN << "Raze: Questions later—hit the terminal first. I’ll keep the feed hot." << RESET << endl;
        } else if (freeReply.size() <= 6) {
            cout << CYAN << "Raze: Short and sweet. Moving you a route ping now." << RESET << endl;
        } else {
            cout << CYAN << "Raze: Logged. I’ll patch in updates while you move. Optics up." << RESET << endl;
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
		cout << CYAN << "Your loss, choom. We coulda made history..." << endl;
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
			cout << WHITE << "Terminal: ACCESS GRANTED. CAMERAS  TEMPORARILY DISABLED." << endl;
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
	cout << WHITE << "Terminal: ACCESS DENIED. Firewall locked you out. You hear boots on wet chrome..." << endl;
	cout << CYAN << "Raze: Damnit, they locked it. Patrol spotted you on the cameras. Be ready for some action!" << RESET << endl;
	return false;
}

bool RazeMissionBrief() { //change dialogue
//	setbgcolor(40, 0, 60); // bluish pruple;
//	setbgcolor(60, 0, 50); //pinkish purple ;
	setbgcolor(0, 0, 80);
	cout << CYAN << "[Incoming Call: RAZE]\n"
	     << "Raze: Yo, Vex — you online ? Good. The city's buzzin tonight, all neon wrappin straight lies in vibrant colors.\n"
	     << "Syntek's messin with heads again, They got their claws deep in every brain on the block.\n"
	     << "Hear that Static? It's in every damn frequency. We're pullin the plug on this shit tonight.\n"
	     << "Heres the plan, you get in and get your hands dirty. I'll keep you from getting caught. We're hitting Syntek Tower at its core.\n"
	     << "You'll need to break down those ICE walls, dance past the patrols, and drop the liberation virus into their mainframe.\n"
	     << "I'll net-guide, you ground-pound. I'll ghost our presence - got that?.\n"
	     << "Remember, stay low, and don't fry your deck." << RESET << endl;
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

//extra dialogue ideas      Starts with the options 1-5 for combat
void CombatDialogue(bool playerAttacking, bool enemyattacking, int attackType = 0) {
	vector<string> RazeResponses = {
		"Raze: PREEM! nice shot",
		"Raze: That hunk of scraps's gonna need some serious repairs!",
		"Raze: Their hacks are worse than my GrandMa's",
		"Raze: Another corpo bites the digital dust"
	};


	vector<string> melee = {
		"Raze: Sharo swing choom, they def felt that in their twisted  circuits!",
		"Raze: Sliced like butter, smoothe as my fav digital cake!",
		"Raze: That hunk of scraps's gonna need some serious repairs!",
		"Raze: Another corpo bites the digital dust"

	};

	vector<string> gunResponses = {
		"Raze: Preem shot! Right through that corporate motherboard!",
		"Raze: Hey bot!, like the smell of systems frying huh?",
		"Raze: Perfect aim, nothing like a binary headshot!",
		"Raze: PREEM! nice shot",
		"Raze: That hunk of scraps's gonna need some serious repairs!"

	};



	vector<string> takecover = {
		"You: Yo Raze, I'm laying low, watch my back",
		"You: Taking heavy fire!, gotta get down NOW!",
		"You: Chrome neeeds a lil refrsher",
		"You: Waoh, gotta hunker down a bit, cant let the corpos scan me"
	};

	vector<string> RazeCoverResponse = {
		"Raze: Smart move choom! I'm clearing your vitals from their scanners!",
		"Raze: Copy that!"
	};



	vector<string> cyberhack = {
		"Raze: Systems compromiseddd!  Their firewall is crumbling!",
		"Raze: All files corrupted! They're locked out!",
		"Raze: Virus injection complete! Good lucking curing that one!"
	};



	vector<string> analyze = {
		"Raze: Sending you enemy  data now... aim for that weak point!",
		"Raze: Analysis complete!, make sure to fry that main processor",
		"Raze: Encryption scan complete, their motherboard's growing cobwebs!",
		"Raze : Scaning complete, their low on power and got a fried CPU"
	};




	vector<string> heziresponses = {
		"Raze: Focus, choom! This ain't the time to space out!",
		"Raze: You having second thoughts? We need to move!",
		"Raze: The Net doesnt for anyone pal, make a decision!",
		"Raze: Binary Clocks' ticking, Vex! Make a call!",
		"Raze: You freeze up now, its game over for all of us"
	};



	if (playerAttacking) {
		setbgcolor(0, 0, 80);

		int Razerand =  rand() % RazeResponses.size();
		cout << CYAN << RazeResponses.at(Razerand) << RESET << endl;

		if (attackType == 1) { // melee
			int mellerand = rand() % melee.size();
			cout << CYAN << melee.at(mellerand) << RESET << endl;
		}  else if (attackType == 2) { // da gun
			int gunrand = rand() % gunResponses.size();
			cout << CYAN << gunResponses.at(gunrand) << RESET << endl;
		}

		else if (attackType == 3) {
			int coverrand = rand() % takecover.size();
			int razeIndex = rand() % RazeCoverResponse.size();

			setbgcolor(40, 0, 80);
			cout << YELLOW << takecover.at(coverrand) << RESET << endl;
			cout << CYAN << RazeCoverResponse.at(razeIndex) << RESET << endl;
			setbgcolor(0, 0, 0);
		}

		else if (attackType == 4) {
			setbgcolor(40, 0, 80);
			int cyberrand = rand() % cyberhack.size();
			cout << CYAN << cyberhack.at(cyberrand);
			setbgcolor(0, 0, 0);

		}

		else if (attackType == 5) {
			setbgcolor(40, 0, 80);
			int analyzrand = rand() % analyze.size();
			cout << CYAN << analyze.at(analyzrand);
			setbgcolor(0, 0, 0);

		} else {
			setbgcolor(40, 0, 80);
			int hezirand = rand() % heziresponses.size();
			cout << CYAN << heziresponses.at(hezirand) << RESET << endl;
			setbgcolor(0, 0, 0);
		}

	}



	vector<string> enemyresponse = {
		"SYNTEX BOT: SYNTEX Property, FREEZE!",
		"SYNTEX BOT: INTRUDER WARNING, PREPARE TO BE NUETRALIZED",
		"SYNTEX BOT: CORPORATE PROPERTY, DO NOT ENGAGE ANY FURTHER",
		"SYNTEX BOT: INTRUDER WARNING, LETHAL FORCE IS AUTHORIZED"
	};

	vector<string> enemyattackRaze = {
		"INCOMING! Netrunner attack",
		"Raze: Watch out choom, dont make me have to find a new partner",
		"Raze: Hard chrome hit choom, dont flatline on me",
		"Raze: Security getting a little tough, look alive",
		"Raze: Ouch, try not to get zeroed"
	};

	if (enemyattacking) {
		int enemyrand = rand() % enemyresponse.size();
		cout << RED << enemyresponse.at(enemyrand) << endl;

		int razeresponse = rand() % enemyattackRaze.size();
		cout << CYAN << enemyattackRaze.at(razeresponse) << endl;

	}

}

void Healthwarnings(int hp) {
	vector<string> allhurtraze = {
		"Raze:  whats going on? you should  take cover and fall back",
		"Raze: I'm sensing system failure in your circuits, recalibrate!",
		"Raze: Your viatals ar spiking!",
		"Raze: Critical systems alert!, dont push it!!",
		"Raze: Yo, I'm starting to loose your signal, recover NOW"
	};
	vector<string> allHurt = {
		"You: Yo, raze! Systems taking critical damage!",
		"You: That stings as bad as an electric shock!",
		"You: I'm taking heavy damag yo, I gotta charge systems up a bit"
	};

	if (hp < 25) {
		setbgcolor(100, 0, 0);
		cout << YELLOW << "You: If I take another hit, i might not see that neon light again!" << RESET << endl;
		setbgcolor(80, 20, 0);
		cout << CYAN << "Raze: Get down, befoe you get us all ZEROED!" << RESET << endl;
	} else if (hp < 50) {
		int hurtrandr = rand() % allhurtraze.size();
		int hurtrandpl = rand() % allHurt.size();
		setbgcolor(100, 0, 0);
		cout << YELLOW << allHurt.at(hurtrandpl) << RESET << endl;
		setbgcolor(100, 0, 0);
		cout << CYAN << allhurtraze.at(hurtrandr) << RESET << endl;
	}

}


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
	int randLvl, randDmg, randHealth, randRam, randCrit, randDodge , randEnemies;
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
			randArmor = 1.00 - fmodf(static_cast <float> (rand()), 0.05); //fmodf from cmath lib doing modulo work on floats / static_cast since rand() is an int
			Enemy bot{randLvl, randDmg, randHealth, randRam, randCrit, randDodge, randArmor, true, true, 0, false, false, false}; //Sets Enemy stats
			foes.push_back(bot);
		}
	}
	else if (Vex.level <= 9) {
		randEnemies = rand() % 2 + 2;
		for (int i = 0; i < randEnemies; i++) {
			randLvl = rand() % 5 + 6;
			randDmg = rand() % 5 + 21;
			randHealth = rand() % 10  + 21;
			randRam = rand() % 3  + 1;
			randCrit = rand() % 10  + 1;
			randDodge = rand() % 5  + 1;
			randArmor = 1.00 - fmodf(static_cast <float> (rand()), 0.05); //fmodf from cmath lib doing modulo work on floats / static_cast since rand() is an int
			Enemy bot{randLvl, randDmg, randHealth, randRam, randCrit, randDodge, randArmor, true, true, 0, false, false, false}; //Sets Enemy stats
			foes.push_back(bot);
		}
		//foes.push_back(bot);
		//foes.push_back(bot);
	}
	else {
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
void EnemyCheck(vector<Enemy> &foes, vector<Enemy> healthCheck) {
	cout << endl;
	for (int i = 0; i < foes.size(); i++) { //Loop checks if enemy is dead
		if (foes.at(i).health <= 0) {
			foes.at(i).alive = false;
			cout << RED << "Enemy " << i + 1 << ": FLATLINED" << RESET << endl;
		}
		else {
			cout << RED << "Enemy " << i + 1 << ": " << foes.at(i).health << " hp ";
			if (foes.at(i).health == healthCheck.at(i).health) {
				cout << "|====================|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 90) {
				cout << "|==================--|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 80) {
				cout << "|================----|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 70) {
				cout << "|==============------|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 60) {
				cout << "|============--------|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 50) {
				cout << "|==========----------|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 40) {
				cout << "|========------------|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 30) {
				cout << "|======--------------|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 20) {
				cout << "|====----------------|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health >= 10) {
				cout << "|==------------------|" << RESET;
			}
			else if (foes.at(i).health * 100 / healthCheck.at(i).health <= 10) {
				cout << "|=------------------|" << RESET;
			}
			cout << endl;
			//cout << "TEST: " << foes.at(i).health / healthCheck.at(i).health * 100 << endl;
		}
	}
}
//=================================================================================================

void BattleControls() {

	cout << YELLOW << endl;
	//setbgcolor(60, 60, 0);
	cout << "\t-----------------\n";
	cout << "\t1: Use Melee    |\n";
	cout << "\t2: Use Gun      |\n";
	cout << "\t3: Take Cover   |\n";
	cout << "\t4: CyberHack    |\n";
	cout << "\t5: Analyze Enemy|\n";
	cout << "\t-----------------\n";
	cout << RESET << endl;
}
//=================================================================================================

void BattleWon(vector<Enemy> &foes) { //If won distribute xp and raise lvl if needed (if lvl is raised then ask to add stat points
	int battleXp = 25 * foes.size(); 
	int playerChoice;
	int lvlTimes;

	cout << endl;
	cout << YELLOW << "You: 'That was tooo easy'" << RESET << endl;
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
	}
	cout << RESET << endl;
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
	
	if (enemyGoesFirst) { cout << RED << "ENEMY GOES FIRST\n" << RESET; } //Test to see if enemy is supposed to go first or not
	else { cout << GREEN << "PLAYER GOES FIRST\n" << RESET; }
	cout << endl <<  WHITE << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << endl;
	//Enemy bot{1, 5, 10, 3, 10, 5, 1.00, true, true}; //Sets Enemy stats
	vector<Enemy> foes;   //Holds the foes in battle
	SetEnemies(foes);     //Sets Amount of foes through function
	vector<Enemy> foesCopy = foes; //Use to reset the stats back to original
	vector<Enemy> healthCheck = foes; //Use to compare original health to current
	
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
					cout << YELLOW << "You: 'HYAHHHHH' " << RESET;
					if (foes.at(i).notInCover) {
						if (randDodge <= foes.at(i).dodgeChance) {
							cout << endl << RED << "'BZZZT EVASIVE MODE ACTIVATED' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= Vex.critChance) {
							cout << endl << YELLOW << "You: 'Jackpot' (CRIT) " << RESET;
							foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor; 
							dmg = 2 * Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "(" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(true, false, 1);
						} 
						else { 
							foes.at(i).health -= Vex.dmg * foes.at(i).armor; 
							dmg = Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "(" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(true, false, 1);
						}
					}
					else { cout << endl << RED << "'BZZT INCOMING THREATS EVADED' (IN COVER)\n" << RESET;} //Dialogue if enemy is taking cover
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
					cout << YELLOW << "You: 'FIRIINGGG' " << RESET;
					if (foes.at(i).notInCover) {
						if (randDodge <= foes.at(i).dodgeChance) {
							cout << endl << RED << "'BZZZT EVASIVE MODE ACTIVATED' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= Vex.critChance) {
							cout << endl << YELLOW << "You: 'Jackpot' (CRIT) " << RESET;
							foes.at(i).health -= 2 * Vex.dmg * foes.at(i).armor; 
							dmg = 2 * Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "(" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(true, false, 2);
						} 
						else { 
							foes.at(i).health -= Vex.dmg * foes.at(i).armor; 
							dmg = Vex.dmg * foes.at(i).armor; 
							cout << YELLOW << "(" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(true, false, 2);
						}
					}
					else { cout << endl << RED << "'BZZT INCOMING THREATS EVADED' (IN COVER)\n" << RESET;} //Dialogue if enemy is taking cover
				}
			}
		}
		//=================================================================================================
		else if (input == "3") { //Take Cover Choice
			clearscreen(); //Clears the screen
			//cout << YELLOW << "You: 'Gotta take cover'" << RESET << endl;
			playerNotInCover = false;
			CombatDialogue(true, false, 3);
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
					cin >> secondInput;
					if (!cin) {  //IF INPUT IS NOT AN INTEGER         
						cin.clear();
						string s;
						cin >> s;
						cout << endl;
						clearscreen(); //Clears the screen
						cout << WHITE << "You Hesitate (TURN SKIPPED)" << RESET << endl; 
						break; 
					}
					//=================================================================================================
					if (secondInput == 1 && hackLanded) { //Armor Strip
						foes.at(i).armor = 1.00;  //Resets the value or armor
						foes.at(i).hacked = true; //Sets the enemy as currently hacked
						turnEnemyHackEnds = turnCount + 7; //Should hold the value the turn that the hack should end 
						foes.at(i).turnHacked = turnEnemyHackEnds;
					}
					else if (secondInput == 2 && hackLanded) { //Visual Overload
						foes.at(i).stunned = true;
						foes.at(i).hacked = true; //Sets the enemy as currently hacked
						turnEnemyHackEnds = turnCount + 7; //Should hold the value the turn that the hack should end  TODO: ADJUST THIS VARIABLE TO LAST LONGER
						foes.at(i).turnHacked = turnEnemyHackEnds;
					}
					else if (secondInput == 3 && hackLanded) {//Mind Control
						if (foes.size() == 1) {
							clearscreen(); //Clears the screen
							hackLanded = false;
							cout << "Enemy has no allies to attack.\n";
							break;	
						}
						else {
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
				cout << YELLOW << "You: 'IM HACKKIN IT' (SUCCESS)\n" << RESET; 
				CombatDialogue(true, false, 4);
				cout << endl << "Hack ends in Turn "<< turnEnemyHackEnds << ":\n";
				hackLanded = false; //Resets it once used 
			} 
			else {
				cout << "Hack unsuccessful. (MISSED)\n";
			}
			//=================================================================================================
		}
		else if (input == "5") { 
					clearscreen(); //Clears the screen
					EnemyCheck(foes, healthCheck);
					ViewEnemyStats(foes);
					CombatDialogue(true, false, 5);
					cout << endl << YELLOW << "You: 'Hmm I See'" << RESET << endl;
					cout << endl <<  WHITE << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
					cout << "Player Turn " << turnCount << ":\n\n";
					BattleControls(); //Displays Controls
					cin >> input;
					continue;
		}
		else { 
			clearscreen(); //Clears the screen
			cout << WHITE << "You Hesitate (TURN SKIPPED)" << RESET << endl; 
		}
	//End of Player Turn	
	

	}
		//=================================================================================================
		EnemyCheck(foes, healthCheck); //Checks if enemy hp drops to 0 or below
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
		cout << WHITE << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
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
					//STATEMENT NEEDED so the if statements in this section willed be skipped if the enemy is dead
			}
			else if (foes.at(i).stunned) { //If enemy is stunned 
				cout << RED << "BZZZZT OPTICAL SYSTEM MALFUNCTION (STUNNED)\n" << RESET;
			}
			else if (foes.at(i).controlled) {
				cout << RED << "BZZZT TARGETTING SYSTEM MALFUNCTION (MIND CONTROLLED)\n" << RESET; 
				//cout << "TEST PRINTING OUT : RANDCONTROL " << randControl << endl;
				for (int j = 0; j < foes.size(); j++) {
					if (randControl == i) {
						randControl = rand() % foes.size();
						continue;
					}
					if (i == j) {
						//SKIP (DONT LET THEM ATTACK THEMSELVE)
					}
					else if (randControl == j) {
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

				
				// TODO: HAVE TO USE AI IN MY CODE
				//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
				//																 AI GENERATED CODE
				//																-------------------


			




				//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

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
							cout << YELLOW << "You: 'Phew, close one' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= foes.at(i).critChance) {
							cout << endl << RED << "'BZZT WEAKPOINT DETECTED' (CRIT)" << RESET;
							hp = hp - 2 * (foes.at(i).dmg * Vex.armor); 
							dmg = 2 * foes.at(i).dmg * Vex.armor; 
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						} 
						else { 
							hp = hp - (foes.at(i).dmg * Vex.armor); 
							dmg = foes.at(i).dmg * Vex.armor; 
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						}
					}
					else { cout << endl << YELLOW  << "You: 'Not a chance' (IN COVER)\n" << RESET;} //Dialogue if player is taking cover
				}
				//==================================================================================================
				else { //Attacking
					cout << RED << "'BZZZZT TARGET FOUND: ATTACKING' " << RESET;
					if (playerNotInCover) {
						if (randDodge <= Vex.dodgeChance) {
							cout << YELLOW << "You: 'Phew, close one' (Atk Dodged)" << RESET << endl;
						}
						else if (randCrit <= foes.at(i).critChance) {
							cout << endl << RED << "'BZZT WEAKPOINT DETECTED' (CRIT)" << RESET;
							hp = hp - 2 * (foes.at(i).dmg * Vex.armor); 
							dmg = 2 * foes.at(i).dmg * Vex.armor; 
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						} 
						else { 
							hp = hp - (foes.at(i).dmg * Vex.armor); 
							dmg = foes.at(i).dmg * Vex.armor; 
							cout << RED << " (" << dmg << "-DMG)" << RESET << endl;
							CombatDialogue(false, true);
						}
					}
					else { cout << endl << YELLOW << "You: 'Not a chance' (IN COVER)\n" << RESET;} //Dialogue if player is taking cover
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
		
		EnemyCheck(foes, healthCheck);
		if (hp <= 0) { hp = 0; }
			cout << YELLOW << "You: " << GREEN << hp << " hp "; //Test
			if (hp == Vex.health) {
				setbgcolor(0, 60, 0);
				cout << "|====================|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 90) {
				setbgcolor(0, 60, 0);
				cout << "|==================--|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 80) {
				setbgcolor(0, 60, 0);
				cout << "|================----|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 70) {
				setbgcolor(0, 60, 0);
				cout << "|==============------|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 60) {
				setbgcolor(0, 60, 0);
				cout << "|============--------|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 50) {
				setbgcolor(0, 60, 0);
				cout << "|==========----------|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 40) {
				setbgcolor(0, 60, 0);
				cout << "|========------------|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 30) {
				setbgcolor(0, 60, 0);
				cout << "|======--------------|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 20) {
				setbgcolor(30, 0, 0);
				cout << "|====----------------|" << RESET;
			}
			else if (hp * 100 / Vex.health >= 10) {
				setbgcolor(60, 0, 0);
				cout << "|==------------------|" << RESET;
			}
			else if (hp * 100 / Vex.health <= 10 and hp * 100 / Vex.health >= 1) {
				setbgcolor(90, 0, 0);
				cout << "|=-------------------|" << RESET;
			} 
			else {
				setbgcolor(90, 0, 0);
				cout << "|--------------------|" << RESET;
			}
			cout << endl << endl;
			Healthwarnings(hp);
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
		cout << WHITE << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
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
	bool playerGoesFirst;
	if(!RazeMissionBrief()) {
		return 0;
	}
//	CombatDialogue(true, false);  >>>> ADD THIS LATER



	RazeMissionBrief();


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
	setbgcolor(0,0,80);
    cout << CYAN << "[Incoming Call: RAZE]" << RESET << endl;
    cout << CYAN << "Raze: Yo, choom... you ready to dance?" << RESET << endl;
	RazeReplyMenu();
	playerGoesFirst = firstPuzzle();
	
	if (playerGoesFirst) { Fight(false); }//TRUE FOR ENEMY TURN FIRST / FALSE FOR PLAYER TURN FIRST
	else { Fight(true); }                 //I WOULD CHANGE IT BUT IT WOULD BE A HASSLE AT THIS POINT OF TIME
	return 0;

    return 0;
}
