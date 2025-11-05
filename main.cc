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

//START
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





return 0;
}
