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






int main() {
	cout << "start" << endl;
	firstPuzzle();




	return 0;
}
