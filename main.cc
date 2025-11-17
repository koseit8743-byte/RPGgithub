//Fill out this comment with your names and which bullet points you did
//Partners: Kwabe
//Bullet Points:
//Extra Credit:
//URL to cover art and music:
#include "/public/read.h"
#include "/public/colors.h"
#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;

//COLOR MAP: Player=YELLOW Raze=CYAN Enemy=RED Basic=WHITE
/// movecursor(5, 20);
// setcolor(6, 7, 67);
// setbgcolor(67, 67, 67);
// set_raw_mode(true);
//char ch =

//START
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


int main() {

	RazeMissionBrief();
//	CombatDialogue(true, false, int )00;  >>>> ADD THIS LATER

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

    return 0;
}
