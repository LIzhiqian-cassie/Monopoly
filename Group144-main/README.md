# Group144
Team members: LI Haochen, LI Zhiqian.
Game: Minipoly

# Description: 
As an ambitious graduated student, you just left the university. Unluckily, you slept over and missed the interview for your ideal job. As a result, you only got an awful job offer. So you thought why not working for yourself? Using your clever mind and knowledge learned, you can still become the minipoly of the neighborhood, you thought. But...will you? Let's go and see! A misterious banker appeared, calling himself Dave, and willing to help you by offering a term risk-free lending of $500,000. Your goal is to become the 'minipoly', or only bankruptcy awaits. "Take a faithful draw, young man", Dave said...      

# Rule:
## About players
You can set the number of players (2~4) at the start of the game. You can pick your nicknames and symbols at the biginning. Players will play this game by turns.

**human players**: you and your friends;
**Dave**: the banker is the third party. 

## About blocks
The neighborhood has 16 blocks and consists of 1*_START_, 4*_STORE_, 4*_PUBLIC_SERVICE_, 2*_HOUSE_, and 5*_CHANCE_. 

**_START_**: Player passed by START (excluding the beginning of the game) will receive a present (randon gain of money) from Dave.

**_STORE_, _PUBLIC_SERVICE_ and _HOUSE_**: 
For the players landed on the unsold _STORE_, _PUBLIC_SERVICE_ and _HOUSE_, they would have the options to purchase it at the prices of $100,000, $180,000 and $350,000 **respectively** or pass. The owner can choose sell their _STORE_, _PUBLIC_SERVICE_ and _HOUSE_ at 70% of the orignal prices to the public in his/her turn.
When other players land on the sold _STORE_, _PUBLIC_SERVICE_ and _HOUSE_, they would have to pay the owner $10,000, $20,000, $50,000 as passing fee respectively.


**_CHANCE_**: Five blocks are **_CHANCE_**, players will encounter one of the following mini games: Random Gain/Loss of money, Stock Exchange, rock-paper-scissors, Sudoku, Slot machine . You can earn a lot but can also loss a lot in these games.


## About financial system
There are 3 types of financial categories: **Cash**, **Building** and **Net**.

**Cash**: the cash you have, it will be automatically stored in the bank and will generate 8% interest rate each round and will be accumulated. You can use cash to pay the fees to other players anytime. Or you can pay your debt when you finish each circle(after hitting start point). 
**Building**: The value of real estate(s) you own.
**Net**: the savings owned by you. ***Earnings = Building + Casht***.

## About rounds
In each round, player will throw the dice and randomly advance 1 to 4 step(s). Players advance according to their order (i.e. Player1 -> Player 2). After moving, players can do the follwing actions:**Continue, Buy, Quit, Save, Save and Quit** while the **Pay, Game** actions will be executed automatically. 

**Buy**: When players land on an unsold _STORE_, _PUBLIC_SERVICE_ and _HOUSE_, they would be given the option to buy it.
**Quit**: Quit the game without saving.
**Save and Quit**: Save the game as a file that players can re-name and then quit.
**Pay**: When players land on an sold _STORE_, _PUBLIC_SERVICE_ and _HOUSE_, the passing fee will be automatically dedected from their cash account.
**Game**: When players land on"**_CHANCE_**", they will be automatically assigned to one of the mini games.

## Winning cretiria 
The goal is to 
1. own all _STORE_, _PUBLIC_SERVICE_ and _HOUSE_ on the map, OR
2. make all other players go bankrupt, OR
3. The winner is the one who survive till the end.
## Losing cretiria
Dave will not believe in you when your net is less than 0. Then, you are bankrupt.

# Features:
-Random Event: When throwing a dice, land on **chance**, passing by **start** and playing mini games,random number will be generated.(requirement1:Generation of random game sets or events)

-Real-time account and map printing: Storing core variables and print block maps and account for player's reference. (requirement 2: Data structures for storing game status & 3 Dynamic memory management)

-Finance system: players' account status will change by time and players' decisions. (requirement 2: Data structures for storing game status)

-Load, Save & Quit: palyers can choose to load game in menu and save current game status. (requirement 4: File input/output)

-Achiement system: there is an archivement option in menu. It will list out the highest earning, highest debt owner and fastest winner, etc. and their achieving time as well as player name.(requirement 4: File input/output)

-Minigames: when landed on **chance**, there will be a number of random games/events that will be called from other files. (requirement 5: Program codes in multiple files)
