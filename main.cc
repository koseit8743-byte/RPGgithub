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
int main() {

	RazeMissionBrief();
	return 0;



}

