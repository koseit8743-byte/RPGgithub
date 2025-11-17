# RPGgithub
RPG project
Lucca DeRaffaele - Puzzles

Variables (including vectors):

Variables are used in all my  puzzl1es to store and track data such as the player’s guesses, number of attempts, and puzzle outcomes.
For example, in the frequency puzzle, variables like double target and double guess store the secret signal frequency and the player’s input.
In the memory puzzle, a string pattern holds the randomly generated sequence the player must recall.
 In future expansions, vectors could be used to hold multiple puzzle states or store previously entered codes for reference.

Algebra:

Basic algebraic operations appear throughout the puzzles.
In the frequency puzzle, the difference between the target frequency and the player’s guess is calculated using fabs(guess - target) to determine accuracy.
If the player is within a certain range (for example, within 3.0), Raze steps in to stabilize the signal.
 This use of arithmetic comparison and absolute value demonstrates algebraic reasoning within the game logic.

Input and Output:

All puzzles rely heavily on user input and system output.
<<<<<<< HEAD
 Players type their answers, codes, or patterns using cin or getline(), and the program responds using cout to to display feedback, colorized dialogue, and story narration.
=======
 Players type their answers, codes, or patterns using cin or getline(), and the program responds using cout to display feedback, colorized dialogue, and story narration.
>>>>>>> e376237 (README.md)
 For example, when the player enters the arrow directions in the door puzzle, the game outputs Raze’s reactions and whether the pattern was correct, creating an interactive experience.
Branches
Each puzzle uses branches (if, else if, and else) to determine outcomes based on the player’s choices.
 In the firewall puzzle, branches decide if the entered code is correct, wrong, or triggers hints from Raze.
 In the lie detector puzzle, multiple branches lead to different story paths depending on how the player answers ECHO’s philosophical questions.
 These decision points allow for dynamic storytelling and varied gameplay.

Loops:

Loops are used to control repeated attempts and progressive difficulty.
In the door arrow puzzle, a for loop gives the player three tries, providing more hints after each failed attempt.
The memory puzzle also uses loops to limit the number of attempts, while iterating through each character to compare the player’s input with the stored pattern.
Loops keep gameplay balanced by giving the player multiple chances while maintaining challenge.

Functions:

Each puzzle is written as its own function, keeping the program organized and modular.
 Examples include firstuzzle(), secondPuzzle(), and thirdPuzzle().
 Every function handles its own input, logic, and output, returning true or false depending on success or failure.
 This structure allows the puzzles to be called in sequence during the main mission, making the program easier to test, expand, and maintain.

