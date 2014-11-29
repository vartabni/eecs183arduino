
//MircroArcade EECS 183 2014 Showcase

//Breaker Breaker



#include <Wire.h>

#include "Adafruit_LEDBackpack.h"

#include "Adafruit_GFX.h"

#include "stdlib.h"

#include <Adafruit_LEDBackpack.h>

#include <Adafruit_GFX.h>


class Board

{
    
public:
    
    
    
    //MODIFIES: the private member variables of Board
    
    //EFFECTS: initializes paddlePos and level to 0, initializes lives to 3, paddleHeight to 7, paused and ballLeft to true
    
    // YAY
    
    Board();
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns paddlePos
    
    // YAY
    
    int getPaddlePos();
    
    
    
    //MODIFIES: paddlePos
    
    //EFFECTS: sets the paddle position to input
    
    // YAY
    
    void setPaddlePos(int input);
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns lives
    
    // YAY
    
    int getLives();
    
    
    
    //MODIFIES: lives
    
    //EFFECTS: sets the lives to input
    
    // YAY
    
    void setLives(int input);
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns level
    
    // YAY
    
    int getLevel();
    
    
    
    //MODIFIES: level
    
    //EFFECTS: sets the level to input
    
    // YAY
    
    void setLevel(int input);
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns ballRow
    
    // YAY
    
    int getBallRow();
    
    
    
    //MODIFIES: ballRow
    
    //EFFECTS: sets the row of the ball to input
    
    // YAY
    
    void setBallRow(int input);
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns ballCol
    
    // YAY
    
    int getBallCol();
    
    
    
    //MODIFIES: ballCol
    
    //EFFECTS: sets the column of the ball to input
    
    // YAY
    
    void setBallCol(int input);
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns ballLeft
    
    // YAY
    
    boolean getBallLeft();
    
    
    
    //MODIFIES: ballLeft
    
    //EFFECTS: sets ballLeft to input
    
    // YAY
    
    void setBallLeft(boolean input);
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns ballRight
    
    // YAY
    
    boolean getBallRight();
    
    
    
    //MODIFIES: ballRight
    
    //EFFECTS: sets ballRight to input
    
    // YAY
    
    void setBallRight(boolean input);
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns ballDown
    
    // YAY
    
    boolean getBallDown();
    
    
    
    //MODIFIES: ballDown
    
    //EFFECTS: sets ballDown to input
    
    // YAY
    
    void setBallDown(boolean input);
    
    
    
    //MODIFIES:nothing
    
    //EFFECTS: returns paddleHeight
    
    // YAY
    
    int getPaddleHeight();
    
    
    
    //MODIFIES:paused
    
    //EFFECTS: sets paused to false
    
    // YAY
    
    void resetPause();
    
    
    
    //MODIFIES:paused
    
    //EFFETCS: sets paused to true
    
    // YAY
    
    void setPause();
    
    
    
    //MODIFIES: nothing
    
    //EFFETCS: returns paused
    
    // YAY
    
    boolean getPaused();
    
    
    
    //MODIFIES: strength array, ballRow, ballCol, BallRight, ballDown
    
    //EFFECTS: first sets up the ball so that it is on top of the paddle
    
    // on the left pixel with initial direction to the left and up. Next
    
    //sets up the board according to which level the game is on.
    // YAY
    
    void initBoard();
    
    
    
    //EFFECTS:Displays the pixels with strength>0 on the board
    // YAY
    
    void displayBlocks();
    
    
    
    //MODIFIES: ballRow and ballCol
    
    //EFFECTS: updates the balls position based on what direction the ball
    
    //is traveling. Be careful to not let the ball go off the board!
    // YAY
    
    void updateBall();
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns true if the ball goes off the board when the player
    
    //fails to hit it with the paddle
    // YAY
    
    boolean lostBall();
    
    
    
    //MODIFIES:ballDown, ballRight, ballLeft
    
    //EFFECTS: changes the ball's direction if the ball hits the top or sides of the board
    // YAY
    
    void hitWall();
    
    
    
    //MODIFIES:ballDown, ballRight, ballLeft
    
    //EFFECTS:changes the direction of the ball depending on which direction the ball was traveling
    
    //when it hits the paddle
    // YAY
    
    void hitPaddle( );
    
    
    
    //MODIFIES:ballDown, ballRight, ballLeft, strength array
    
    //EFFECTS:changes the direction of the ball depending on which direction the ball was traveling
    
    //when it hits a block. Decrements the strength of the block.
    
    // INCOMPLETE!!!
    
    void hitBlock();
    
    
    
    //MODIFIES: nothing
    
    //EFFECTS: returns true if all blocks are destroyed, false otherwise
    // YAY
    
    boolean levelComplete();
    
    
    
    //MODIFIES:strength array
    
    //EFFECTS: sets all strengths to 0
    // YAY
    
    void initStrength();
    
    
    
    
    
private:
    
    
    
    int strength[8][16];          //The strengths of blocks on the board
    
    int paddlePos;		//Leftmost position of the paddle
    
    int paddleHeight;	        // height of the upper paddle
    
    int lives;			//Number of lives left
    
    int level;			//Current level
    
    int ballRow;			//Row of the ball
    
    int ballCol;			//Column of the ball
    
    boolean ballLeft;		//If ballleft == TRUE, ball is moving left
    
    boolean ballRight;		//If ballRight == TRUE, ball is moving right.
    
    boolean ballDown;		//If ballDown == TRUE, ball is moving down.  Otherwise, ball is moving up
    
    boolean paused;		// Pause after ball loss
    
    
    
};



//sets up the LED board with the correct parameters

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();



//EFFECTS:turns off all the pixels on the board

void clearBoard();



//REQUIRES:  val is the value of the potentiometer

//MODIFIES: nothing

//EFFECTS: returns the column position of the left pixel of the paddle

int calculatePaddlePosition(int val);





//EFFECTS:displays the number of lives remaining/level number on the board. If it doesn't all fit

//on the board at once, the text scrolls.

//use text size 1 and delay of 50

void printMessage(int number);



//EFFECTS:displays string text needed(suchs as "LIVES" or "LEVEL") on the board. If it

//doesn't all fit on the board at once, the text scrolls.

//use text size 1 and delay of 50

void printMessage(String message);



//contains data about pin assignments and values

struct Pins

{
    
    int potPin; 	        //input pin potentiometer
    
    int val;		//value of the potentiometer
    
    int button;		//input pin for the button
    
    int buttonState;      // current state of the button
    
    
    
};



void(* resetFunc) (void) = 0; //declare reset function @ address 0



//EFFECTS:displays "GameOver" on the board and resets the game. This function

//is implemented for you.

void gameOver(){
    
    printMessage("GameOver");
    
    delay(3000);
    
    resetFunc();
    
}



//DO NOT MODIFY ANY CODE ABOVE THIS LINE.

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------



void setup()

{
    
    
    
}





void loop()

{
    
    //everything needed for the game to play goes here
    
    
    
    //YOUR CODE GOES HERE
    
    
    
    matrix.writeDisplay(); //display all changes made in one iteration of loop
    
    delay(150); //to slow it down and make it easier to debug. also makes the paddle lag
    
}



//WRITE YOUR FUNCTION IMPLEMENTATIONS BELOW



Board() {
    
    
    
    int strength[8][16] = { 0 };
    
    int paddlePos = 0;
    
    int paddleHeight = 7;
    
    int lives = 3;
    
    int level = 1;
    
    int ballRow = 0;
    
    int ballCol = 0;
    
    boolean ballLeft = true;
    
    boolean ballRight = false;
    
    boolean ballDown = false;
    
    boolean paused = true;
    
}



int getPaddlePos() {
    
    return paddlePos;
    
}



void setPaddlePos(int input) {
    
    paddlePos = input;
    
}



int getLives() {
    
    return lives;
    
}



void setLives(int input) {
    
    lives = input;
    
}



int getLevel() {
    
    return level;
    
}



void setLevel(int input) {
    
    level = input;
    
}



int getBallRow() {
    
    return ballRow;
    
}



void setBallRow(int input) {
    
    ballRow = input;
    
}



int getBallCol() {
    
    return ballCol;
    
}



void setBallCol(int input) {
    
    ballCol = input;
    
}



boolean getBallLeft() {
    
    return ballLeft;
    
}



void setBallLeft(boolean input) {
    
    ballLeft = input;
    
}



boolean getBallRight() {
    
    return ballRight;
    
}



void setBallRight(boolean input) {
    
    ballRight = input;
    
}



boolean getBallDown() {
    
    return ballDown;
    
}



void setBallDown(boolean input) {
    
    ballDown = input;
    
}



int getPaddleHeight() {
    
    return paddleHeight;
    
}



void resetPause() {
    
    pause = false;
    
}



void setPause() {
    
    pause = true;
    
}



boolean getPaused() {
    
    return paused;
    
}

void initBoard() {
    
    paddleHeight = 9;
    paddlePos = 3;
    setPaddlePos(paddlePos);
    ballRow = paddlePos;
    ballCol = 15;
    ballRight = false;
    ballDown = false;
    
    if (level == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 1; j++) {
                strength[i][j] = 1;
            }
        }
    }
    
    if (level == 2) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 2; j++) {
                strength[i][j] = 1;
            }
        }
    }
    
    if (level == 3) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 2; j++) {
                if (j == 0) {
                    strength[i][j] = 2;
                }
                if (j == 1) {
                    strength[i][j] = 1;
                }
            }
        }
    }
    
    if (level == 4) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 0) {
                    strength[i][j] = 3;
                }
                if (j == 1) {
                    strength[i][j] = 2;
                }
                if (j == 2) {
                    strength[i][j] = 1;
                }
            }
        }
    }
    
    if (level == 5) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 10; j++) {
                if (j == 0) {
                    strength[i][j] = 3;
                }
                if (j == 1) {
                    strength[i][j] = 0;
                }
                if (j == 2) {
                    strength[i][j] = 2;
                }
                if ((j == 8) || (i == 9)) {
                    strength[i][j] = 1;
                }
            }
        }
    }
}


void displayBlocks() {
    for (int i = 0, i < 8, i++) {
        for (int j = 0, i < 16, I++) {
            
            if (strength[i][j] > 0) {
                drawPixel (j, i);
            }
        }
    }
}


void updateBall() {
    if (ballRight == true) {
        ballCol += 1;
    }
    if (ballLeft == true) {
        ballCol -= 1;
    }
    if (ballDown == true) {
        ballRow -= 1;
    }
    if (ballDown == false) {
        ballRow += 1;
    }
}

boolean lostBall() {
    if (ballRow == 0) {
        return true;
    }
    else {
        return false;
    }
}

void hitWall() {
    
    if ((ballCol == 0 || ball Col == 7) && ballRow == 15) {  //Redirects ball when upper corners are hit
        if (ballCol == 0 && ballLeft == true && ballDown == false) { //Hitting left corner coming from left
            ballLeft = false;
            ballRight = true;
            ballDown = true;
        }
        else if (ballCol == 7 && ballRight == true && ballDown == false) { //Hitting right corner coming from right
            ballRight = false;
            ballLeft = true;
            ballDown = true;
        }
    }
    else if ((ballCol == 0) || (ballCol == 7)) { //Redirects ball if left/right walls are hit
        if (ballRight == true) { //Ball is going right (hitting right wall)
            ballRight = false;
            ballLeft = true;
        }
        else { //Ball is going left (hitting left wall)
            ballLeft = false;
            ballRight = true;
        }
    }
    
    else if (ballRow == 15) { //Redirects ball if top wall is hit
        if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
            ballDown = true;
        }
        else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
            if (ballRight == true) { //Ball is coming right-diagonally
                ballRight == false;
                ballLeft == true;
                ballDown == true;
            }
            if (ballLeft == true) { //Ball is coming left-diagonally
                ballLeft == false;
                ballRight == true;
                ballDown == true;
            }
        }
    }
}

void hitPaddle( ) {
    if (ballRow == 1 || ballRow == 10) {
        if (ballCol >= (paddlePos - 1) && ballDown == true) { // Redirects the ball when it hits the upper/lower paddle
            if ((ballLeft == true) && (ballRight == false)) { //Ball hits paddle from a left-diagonal
                if (ballCol == (paddlePos + 1)) { //Ball hits right side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = true;
                }
                else if (ballCol == paddlePos) { //Ball hits left side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
                else if (ballCol == (paddlePos - 1)) { ///Ball hits the left corner of paddle
                    ballDown = false;
                    ballLeft = true;
                    ballRight = false;
                }
            }
            else if ((ballRight == true) && (ballLeft == false)) { //Ball hits paddle from a right-diagonal
                if (ballCol == (paddlePos - 1)) { ///Ball hits the left corner of paddle
                    ballDown = false;
                    ballLeft = true;
                    ballRight = false;
                }
                else if (ballCol == paddlePos) { //Ball hits left side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
                else if (ballCol == (paddlePos + 1)) { //Ball hits right side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = true;
                }
            }
            else if ((ballLeft == false) && (ballRight == false)) { //Ball hits paddle from straight down
                
                /*Note: The spec doesn't really give details for how we should code the paddle for this situation
                 so for right now it just returns the ball back in a straight up motion, and only if the
                 left/right hand sides of the paddle are hit -- not the left corner */
                
                if (ballCol == paddlePos) { //Ball hits left side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
                else if (ballCol == (paddlePos + 1)) { //Ball htis right side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
            }
        }
    }
}


void hitBlock() {
    // Note: I decided to code this to be level-dependent (possibly not the best way)
    //       If you have any other ideas let me know! Redirection code is same/copied between levels
    
    if (level == 1) {
        if (ballRow == 14) {
            if (strength[(ballRow + 1),ballCol] > 0) {
                strength[(ballRow + 1),ballCol] -= 1;
                if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                    ballDown = true;
                }
                else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == true;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == true;
                    }
                }
            }
        }
    }
    else if (level == 2) {
        if (ballRow == 13 || ballRow == 14) {
            if (strength[(ballRow + 1),ballCol] > 0) {
                strength[(ballRow + 1),ballCol] -= 1;
                if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                    ballDown = true;
                }
                else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == true;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == true;
                    }
                }
            }
        }
        
    }
    else if (level == 3) {
        if (ballRow == 13 || ballRow == 14) {
            if (strength[(ballRow + 1),ballCol] > 0) {
                strength[(ballRow + 1),ballCol] -= 1;
                if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                    ballDown = true;
                }
                else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == true;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == true;
                    }
                }
            }
        }
        
    }
    else if (level == 4) {
        if (ballRow == 12 || ballRow == 13 || ballRow == 14) {
            if (strength[(ballRow + 1),ballCol] > 0) {
                strength[(ballRow + 1),ballCol] -= 1;
                if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                    ballDown = true;
                }
                else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == true;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == true;
                    }
                }
            }
        }
    }
    else if (level == 5) { //Two-tiered block formation is introduced
        if (ballRow == 14 || ballRow == 12 || ballRow == 4 || ballRow == 5) { //When the ball is hitting from the bottom
            if (strength[(ballRow + 1),ballCol] > 0) {
                strength[(ballRow + 1),ballCol] -= 1;
                if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                    ballDown = true;
                }
                else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == true;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == true;
                    }
                }
            }
        }
        else if (ballRow == 6 || ballRow == 7)  { //When ball is hitting from the top -- only possible for lower-tier blocks
            if (strength[(ballRow - 1),ballCol] > 0) {
                strength[(ballRow - 1),ballCol] -= 1;
                if (ballDown == true && ballRight == false && ballLeft == false) { //Ball is coming straight down
                    ballDown = false;
                }
                else if (ballDown == true && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == false;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == false;
                    }
                }
            }
        }
    }
    
    
    else { //Level is 6 or higher -- block strength is randomized at this stage
        if (ballRow == 14 || ballRow == 13 || ballRow == 12 || ballRow == 5 || ballRow == 4) { //Ball is hitting from the bottom
            if (strength[(ballRow + 1),ballCol] > 0) {
                strength[(ballRow + 1),ballCol] -= 1;
                if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                    ballDown = true;
                }
                else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == true;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == true;
                    }
                }
            }
        }
        else if (ballRow == 6 || ballRow == 7) { //Ball is hitting from the top -- on the lower-tiered blocks
            if (strength[(ballRow - 1),ballCol] > 0) {
                strength[(ballRow - 1),ballCol] -= 1;
                if (ballDown == true && ballRight == false && ballLeft == false) { //Ball is coming straight down
                    ballDown = false;
                }
                else if (ballDown == true && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight == true;
                        ballLeft == false;
                        ballDown == false;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft == true;
                        ballRight == false;
                        ballDown == false;
                    }
                }
            }
        }
    }
}





boolean levelComplete() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 15; j++) {
            if (strength [i,j] > 0) {
                return false;
            }
        }
    }
    return true;
}

void initStrength() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 15; j++) {
            strength [i,j] = 0;
        }
    }
}





// JSYK: FUNCTIONS BELOW DIRECTLY INTERACT WITH THE ADAFRUIT DISPLAY BOARD!
//       (All have been stubbed -- until properly implemented! Please delete RME's once implemented!)




//EFFECTS:turns off all the pixels on the board

void clearBoard() {
    
}

//REQUIRES:  val is the value of the potentiometer

//MODIFIES: nothing

//EFFECTS: returns the column position of the left pixel of the paddle

int calculatePaddlePosition(int val) {
    return 0;
}

//EFFECTS:displays the number of lives remaining/level number on the board. If it doesn't all fit

//on the board at once, the text scrolls.

//use text size 1 and delay of 50

void printMessage(int number) {
    
}

//EFFECTS:displays string text needed(suchs as "LIVES" or "LEVEL") on the board. If it

//doesn't all fit on the board at once, the text scrolls.

//use text size 1 and delay of 50

void printMessage(String message) {
    
}

