# Skynet-Part-2
adds AI and human input
Create a new solution and project and GitHub for this assignment.
Hint: Open two separate visual studios to do this. One for the old solution project, and one for the new solution project. Now copy all the code from the original Skynet HK-Aerial into this new project to save you from having to recode everything from scratch. Test this before you move on to make sure the code works in your new project like it did in your old project. Now close your old project and that instance of visual studio.
Modify your new C++ program for the Skynet HK-Aerial.
Add another AI player using the less efficient Linear search pattern.
Add another AI player using a random number guess between grid locations 1 and 64.
Add a human player, letting the human input grid numbers from the console.
The easiest way to code this would be for this program’s user interface to start with the human player and use a while loop until the human guesses the location the enemy while keeping track of the number of guesses the human uses. Then the random guess AI player should guess using their own while loop until they find the enemy location and keep track of how many guesses it took them. Then the linear Search AI player should guess using their own while loop until they find the enemy location, and then finally the Binary search AI should run it’s while loop and keep track of the number of guesses it takes to find the enemy location. Once all players AI and Human have found the enemy location, then this game is over. Display the stats of each player's number of guesses it took. You don't have to physically sort them, just display the number of guesses each drone pilot took to find the enemy.
Be sure to comment each line of code except cout statements, write very readable code using good coding standards.
The Grid does not need to be displayed, remember the grid is abstract. Think of this as more of a guess the number game like at the end of chapter two.
When all the players have found the enemies, the game is over, the console should ask the human player if they would like to play again. If the human player say's yes, then the game should reset all scores and play again.
