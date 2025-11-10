//Fill out this comment with your names and which bullet points you did
//Partners: DeRaffaele, Romero, Rangel, Osei Tutu,
//Bullet Points: 1,2,3,4,5
//Extra Credit: 2,3
//URL to cover art and music:
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include "/public/colors.h"
#include "/public/read.h"
using namespace std;
//COLOR MAP: Player=YELLOW Raze=CYAN Enemy=RED Basic=WHITE


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

int main() {
	bool start = RazeMissionBrief();
	if (!start) return 0;
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
	puzzle = secondPuzzle();
	puzzle = thirdPuzzle();


	return 0;
}
