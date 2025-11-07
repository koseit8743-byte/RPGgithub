//Fill out this comment with your names and which bullet points you did
//Partners: DeRaffaele, Romero, Rangel, Osei Tutu,
//Bullet Points: 1,2,3,4,5
//Extra Credit: 2,3
//URL to cover art and music:

#include <iostream>
#include <string>
#include <algorithm>
#include "/public/colors.h"
using namespace std;
//COLOR MAP: Player=YELLOW Raze=CYAN Enemy=RED Basic=WHITE

//FIRST DIALOG W RAZE
void RazeReplyMenu() {
    cout << WHITE << "\n[Reply options]" << RESET << endl;
    cout << WHITE << "  1) \"Always ready. Feed me intel.\"\n"
         << "  2) \"Hold up—what’s the plan?\"\n"
         << "  3) \"Quit the chatter, gotta focus up.\"\n"
         << "  4) Type my own reply\n" << RESET;
    string choice;
    while (true) {
        cout << WHITE << "Choose 1-4: " << RESET;
        choice = getline();
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
        cout << WHITE << "Type your reply: " << RESET;
        string freeReply = getline();
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

bool RazeMissionBrief() {//change dialogue
	cout << CYAN << "[Incoming Call: RAZE]\n"
         << "Raze: Yo, Vex — you online ? Good. The city’s humming tonight, all neon and lies.\n"
         << "Syntek’s got their claws deep in every brain on the block. ECHO’s whispering through implants like a ghost in the code.\n"
         << "Yeah, I hear it. Static in every frequency. We shut it down tonight.\n"
         << "You get in, I keep the line open. We’re hitting Syntek Tower — center of the storm.\n"
         << "You’ll need to crack five ICE walls, dance past the patrols, and drop the liberation virus into their mainframe.\n"
         << "I’ll be your eyes in the net. You handle the ground work, I’ll ghost the signal.\n"
         << "Raze: Remember, stay low, and don’t fry your deck." << RESET << endl;

    cout << WHITE << "\nRun a tactical simulation of Mission 1 now? (y/n): " << RESET;
	
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


int main() {
	if(!RazeMissionBrief()) {
		return 0;
	}
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
	RazeReplyMenu();
	firstPuzzle();




	return 0;
}
