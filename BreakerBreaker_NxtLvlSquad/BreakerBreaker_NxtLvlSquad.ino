#include <Adafruit_GFX.h>

//MircroArcade EECS 183 2014 Showcase

//Breaker Breaker



#include <Wire.h>

#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

#include "stdlib.h"

//#include <Adafruit_LEDBackpack.h>
//
//#include <Adafruit_GFX.h>


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
    
    int potPin; 	//input pin potentiometer
    
    int val;		//value of the potentiometer
    
    int button;		//input pin for the f
    
    int buttonState;    // current state of the button
    
    
    
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


Pins pins;
Board board;
void setup()

{
    Serial.begin(9600); // for potentiometer paddlePos
    pins.potPin = 0;
    
    pins.val = analogRead(A0);
    
    // Beginning work on button set-up
    pins.button = 7;
    pins.buttonState = 0;
    pinMode(pins.button, INPUT);
    
    matrix.begin(0x70);
    clearBoard();
    board.initStrength();
    board.initBoard();
    printMessage("LIVES");
    printMessage(board.getLives());
}





void loop()

{
    
    // Button set-up work cont.
    pins.buttonState = digitalRead(pins.button);
    if (pins.buttonState) {
      board.resetPause();
    }
    //Serial.println(pins.buttonState); // Prints out the state of the button ( 1 = Pressed/HIGH, 0 = Not pressed/LOW)
    //delay (5);
    
    //matrix.clear();
    clearBoard(); // another way to clear the board
    board.displayBlocks();
    matrix.drawPixel(board.getBallRow(), board.getBallCol(), LED_ON); // draws the ball

    board.hitPaddle();
    board.hitWall();
    board.hitBlock();
    board.hitBlock();
    board.hitBlock();
    board.hitBlock();
    board.lostBall();
    board.levelComplete();
    
    matrix.drawPixel(board.getPaddlePos(), 15, LED_ON); // left block of bottom paddle
    matrix.drawPixel(board.getPaddlePos() + 1, 15, LED_ON); // right block of bottom paddle
    matrix.drawPixel(board.getPaddlePos(), board.getPaddleHeight(), LED_ON); // left block of the top paddle in row 9
    matrix.drawPixel(board.getPaddlePos() + 1, board.getPaddleHeight(), LED_ON); // right block of top paddle in row 9
    board.setPaddlePos(calculatePaddlePosition(pins.val));
    pins.val = analogRead(pins.potPin);
    
    matrix.writeDisplay(); //display all changes made in one iteration of loop
    
    if (board.levelComplete() == true) {
        board.setLevel(board.getLevel() + 1);
        board.initBoard();
        printMessage("LEVEL");
        printMessage(board.getLevel());
        printMessage("LIVES");
        printMessage(board.getLives());
        board.setPause();

    }
    
    if (board.lostBall() == true) {
      board.setLives(board.getLives() - 1);
      if (board.getLives() <= 0) {
        gameOver();
      }
      else {
        printMessage("LIVES");
        printMessage(board.getLives());
        board.setBallRow(board.getPaddlePos());
        board.setBallCol(14);
        board.setBallRight(false);
        board.setBallLeft(true);
        board.setBallDown(false);
        board.setPause();
      }
    }
    
    if (board.getPaused() == false) {
      board.updateBall();
    }
    else {
      board.setBallCol(14);
      board.setBallRow(board.getPaddlePos());
      board.setBallRight(false);
      board.setBallLeft(true);
      board.setBallDown(false);
      board.setPause();
    }
    
    delay(300); //to slow it down and make it easier to debug. also makes the paddle lag .. Default is 150!
    
}



//WRITE YOUR FUNCTION IMPLEMENTATIONS BELOW


Board::Board() {
  
    paddlePos = 3;
    
    paddleHeight = 7;
    
    lives = 3;
    
    level = 1;
    
    ballRow = 3;
    
    ballCol = 14;
    
    ballLeft = true;
    
    ballRight = false;
    
    ballDown = false;
    
    paused = true;
    
}



int Board::getPaddlePos() {
    
    return paddlePos;
    
}



void Board::setPaddlePos(int input) {
    
    paddlePos = input;
    
}



int Board::getLives() {
    
    return lives;
    
}



void Board::setLives(int input) {
    
    lives = input;
    
}



int Board::getLevel() {
    
    return level;
    
}



void Board::setLevel(int input) {
    
    level = input;
    
}



int Board::getBallRow() {
    
    return ballRow;
    
}



void Board::setBallRow(int input) {
    
    ballRow = input;
    
}



int Board::getBallCol() {
    
    return ballCol;
    
}



void Board::setBallCol(int input) {
    
    ballCol = input;
    
}



boolean Board::getBallLeft() {
    
    return ballLeft;
    
}



void Board::setBallLeft(boolean input) {
    
    ballLeft = input;
    
}



boolean Board::getBallRight() {
    
    return ballRight;
    
}



void Board::setBallRight(boolean input) {
    
    ballRight = input;
    
}



boolean Board::getBallDown() {
    
    return ballDown;
    
}



void Board::setBallDown(boolean input) {
    
    ballDown = input;
    
}



int Board::getPaddleHeight() {
    
    return paddleHeight;
    
}



void Board::resetPause() {
    
    paused = false;
    
}



void Board::setPause() {
    
    paused = true;
    
}



boolean Board::getPaused() {
    
    return paused;
    
}

void Board::initBoard() {
    
    paddleHeight = 7;
    paddlePos = 3;
    setPaddlePos(paddlePos);
    ballRow = paddlePos;
    ballCol = 14;
    ballRight = false;
    ballLeft = true;
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
            for (int j = 0; j < 11; j++) {
                if (j == 0) {
                    strength[i][j] = 3;
                }
                if (j == 1) {
                    strength[i][j] = 0;
                }
                if (j == 2) {
                    strength[i][j] = 2;
                }
                if ((j == 9)) {
                    strength[i][j] = 1;
                }
                if ((j == 10)) {
                    strength[i][j] = 1;
                }
            }
        }
    }
    if (level >= 6) {
      int randVal0 = rand() % 3 + 1;
      int randVal1 = rand() % 3 + 1;
      int randVal2 = rand() % 3 + 1;
      int randVal9 = rand() % 4 + 1;
      int randVal10 = rand() % 4 + 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 11; j++) {
                if (j == 0) {
                  strength[i][j] = randVal0;
                }
                if (j == 1) {
                  strength[i][j] = randVal1;
                }
                if (j == 2) {
                  strength[i][j] = randVal2;
                }
                if (j == 9) {
                  strength[i][j] = randVal9;
                }
                if (j == 10) {
                  strength[i][j] = randVal10;
                }
            }
        }
    }
}


void Board::displayBlocks() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16; j++) {
            if (strength[i][j] > 0) {
                matrix.drawPixel(i, j, LED_ON);
            }
        }
    }
}


void Board::updateBall() {
    if (ballRight == true) {
        ballRow += 1;
    }
    if (ballLeft == true) {
        ballRow -= 1;
    }
    if (ballDown == true) {
        ballCol += 1;
    }
    if (ballDown == false) {
        ballCol -= 1;
    }
}

boolean Board::lostBall() {
    if (ballCol >= 15) {
        return true;
    }
    else {
        return false;
    }
}

void Board::hitWall() {
    
    if ((ballRow == 0 || ballRow == 7) && ballCol == 0) {  //Redirects ball when upper corners are hit
        if (ballRow == 0 && ballLeft == true && ballDown == false) { //Hitting left corner coming from left
            ballLeft = false;
            ballRight = true;
            ballDown = true;
        }
        else if (ballRow == 7 && ballRight == true && ballDown == false) { //Hitting right corner coming from right
            ballRight = false;
            ballLeft = true;
            ballDown = true;
        }
    }
    else if ((ballRow == 0) || (ballRow == 7)) { //Redirects ball if left/right walls are hit
        if (ballRight == true) { //Ball is going right (hitting right wall)
            ballRight = false;
            ballLeft = true;
        }
        else { //Ball is going left (hitting left wall)
            ballLeft = false;
            ballRight = true;
        }
    }
    else if (ballCol == 0) { //Redirects ball if top wall is hit
        if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
            ballDown = true;
        }
        else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
            if (ballLeft == true) { //Ball is coming left-diagonally
                ballLeft = true;
                ballRight = false;
                ballDown = true;
            }
            else if (ballRight == true) { //Ball is coming right-diagonally
                ballRight = true;
                ballLeft = false;
                ballDown = true;
            }
        }
    }
}

void Board::hitPaddle() {
    if (ballCol == 14 || ballCol == 6) {
        if (ballRow >= (paddlePos - 1) && ballDown == true) { // Redirects the ball when it hits the upper/lower paddle
            if ((ballLeft == true) && (ballRight == false)) { //Ball hits paddle from a left-diagonal
                if (ballRow == (paddlePos + 2)) { //Ball hits the right corner of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = true;
                }
                else if (ballRow == (paddlePos + 1)) { //Ball hits right side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
                else if (ballRow == paddlePos) { //Ball hits left side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
                else if (ballRow == (paddlePos - 1)) { ///Ball hits the left corner of paddle
                    ballDown = false;
                    ballLeft = true;
                    ballRight = false;
                }
            }
            else if ((ballRight == true) && (ballLeft == false)) { //Ball hits paddle from a right-diagonal
                if (ballRow == (paddlePos - 1)) { ///Ball hits the left corner of paddle
                    ballDown = false;
                    ballLeft = true;
                    ballRight = false;
                }
                else if (ballRow == paddlePos) { //Ball hits left side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
                else if (ballRow == (paddlePos + 1)) { //Ball hits right side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = false;
                }
                else if (ballRow == (paddlePos + 2)) { //Ball hits right corner of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = true;
                }
            }
            else if ((ballLeft == false) && (ballRight == false)) { //Ball hits paddle from straight down
                
                if (ballRow == paddlePos) { //Ball hits left side of paddle
                    ballDown = false;
                    ballLeft = true;
                    ballRight = false;
                }
                else if (ballRow == (paddlePos + 1)) { //Ball htis right side of paddle
                    ballDown = false;
                    ballLeft = false;
                    ballRight = true;
                }
            }
        }
    }
    
    else if (ballCol == 8) {
        if (ballRow >= (paddlePos - 1) && ballDown == false) { // Redirects the ball when it hits the lower paddle from the bottom
            if ((ballLeft == true) && (ballRight == false)) { //Ball hits paddle from a left-diagonal
                if (ballRow == (paddlePos + 2)) { //Ball hits the right corner of paddle
                    ballDown = true;
                    ballLeft = false;
                    ballRight = true;
                }
                else if (ballRow == (paddlePos + 1)) { //Ball hits right side of paddle
                    ballDown = true;
                    ballLeft = true;
                    ballRight = false;
                }
                else if (ballRow == paddlePos) { //Ball hits left side of paddle
                    ballDown = true;
                    ballLeft = true;
                    ballRight = false;
                }
            }
            else if ((ballRight == true) && (ballLeft == false)) { //Ball hits paddle from a right-diagonal
                if (ballRow == (paddlePos - 1)) { ///Ball hits the left corner of paddle
                    ballDown = true;
                    ballLeft = true;
                    ballRight = false;
                }
                else if (ballRow == paddlePos) { //Ball hits left side of paddle
                    ballDown = true;
                    ballLeft = true;
                    ballRight = false;
                }
                else if (ballRow == (paddlePos + 1)) { //Ball hits right side of paddle
                    ballDown = true;
                    ballLeft = true;
                    ballRight = false;
                }
                
            }
            else if ((ballLeft == false) && (ballRight == false)) { //Ball hits paddle from straight up
                if (ballRow == paddlePos) { //Ball hits left side of paddle
                    ballDown = true;
                    ballLeft = true;
                    ballRight = false;
                }
                else if (ballRow == (paddlePos + 1)) { //Ball htis right side of paddle
                    ballDown = true;
                    ballLeft = false;
                    ballRight = true;
                }
            }
        }
    }
}


void Board::hitBlock() {
    if (level == 1) {
        if (ballCol == 1) {
            if ( (ballRow % 2) == 0) {
                
                if (strength[ballRow][(ballCol - 1)] > 0) {
                    strength[ballRow][(ballCol - 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol - 1] > 0) {
                    strength[(ballRow)][ballCol - 1] -= 1;
                    strength[(ballRow - 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            
        }
        
    }
    
    else if (level == 2) {
        if (ballCol == 2 || ballCol == 1) {
            if ( (ballRow % 2) == 0) {
                
                if (strength[ballRow][(ballCol - 1)] > 0) {
                    strength[ballRow][(ballCol - 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol - 1] > 0) {
                    
                    strength[(ballRow)][ballCol - 1] -= 1;
                    strength[(ballRow - 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            
        }
        
    }
    else if (level == 3) {
        if (ballCol == 2 || ballCol == 1) {
            if ( (ballRow % 2) == 0) {
                
                if (strength[ballRow][(ballCol - 1)] > 0) {
                    strength[ballRow][(ballCol - 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol - 1] > 0) {
                    
                    strength[(ballRow)][ballCol - 1] -= 1;
                    strength[(ballRow - 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            
        }
        
    }
    else if (level == 4) {
        if (ballCol == 3 || ballCol == 2 || ballCol == 1) {
            if ( (ballRow % 2) == 0) {
                if (strength[ballRow][(ballCol - 1)] > 0) {
                    strength[ballRow][(ballCol - 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol - 1] > 0) {  
                    strength[(ballRow)][ballCol - 1] -= 1;
                    strength[(ballRow - 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            
        }
        
    }
    else if (level == 5) { //Two-tiered block formation is introduced
        if (ballCol == 1 || ballCol == 3 || ballCol == 10 || ballCol == 11) { //When the ball is hitting from the bottom
            if ( (ballRow % 2) == 0) {
                if (strength[ballRow][(ballCol - 1)] > 0) {
                    strength[ballRow][(ballCol - 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol - 1] > 0) {
                    strength[(ballRow)][ballCol - 1] -= 1;
                    strength[(ballRow - 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            
        }
        else if (ballCol == 9 || ballCol == 8 || ballCol == 13)  { //When ball is hitting from the top -- only possible for lower-tier blocks
             if ( (ballRow % 2) == 0) {
                if (strength[ballRow][(ballCol + 1)] > 0) {
                    strength[ballRow][(ballCol + 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol + 1)] -= 1;
                    
                   if (ballDown == true && ballRight == false && ballLeft == false) { //Ball is coming straight down
                    ballDown = false;
                }
                else if (ballDown == true && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight = true;
                        ballLeft = false;
                        ballDown = false;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft = true;
                        ballRight = false;
                        ballDown = false;
                        }
                        
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol + 1] > 0) {
                    strength[(ballRow)][ballCol + 1] -= 1;
                    strength[(ballRow - 1)][(ballCol + 1)] -= 1;
                    
                   if (ballDown == true && ballRight == false && ballLeft == false) { //Ball is coming straight down
                    ballDown = false;
                }
                else if (ballDown == true && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight = true;
                        ballLeft = false;
                        ballDown = false;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft = true;
                        ballRight = false;
                        ballDown = false;
                        }
                        
                    }
                }
            } 
        }
    }
    else if (level >= 6) { //Level is 6 or higher -- block strength is randomized at this stage
        if (ballCol == 1 || ballCol == 2 || ballCol == 3 || ballCol == 10 || ballCol == 11) { //Ball is hitting from the bottom
            if ( (ballRow % 2) == 0) {
                if (strength[ballRow][(ballCol - 1)] > 0) {
                    strength[ballRow][(ballCol - 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol - 1] > 0) {
                    strength[(ballRow)][ballCol - 1] -= 1;
                    strength[(ballRow - 1)][(ballCol - 1)] -= 1;
                    
                    if (ballDown == false && ballRight == false && ballLeft == false) { //Ball is coming straight up
                        ballDown = true;
                    }
                    else if (ballDown == false && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                        if (ballLeft == true) { //Ball is coming left-diagonally
                            ballLeft = true;
                            ballRight = false;
                            ballDown = true;
                        }
                        else if (ballRight = true) { //Ball is coming right-diagonally
                            ballRight = true;
                            ballLeft = false;
                            ballDown = true;
                        }
                        
                    }
                }
            }
            
        }
        else if (ballCol == 8 || ballCol == 9 || ballCol == 0 || ballCol == 1 || ballCol == 2) { //Ball is hitting from the top -- on the lower-tiered blocks
            if ( (ballRow % 2) == 0) {
                
                if (strength[ballRow][(ballCol + 1)] > 0) {
                    strength[ballRow][(ballCol + 1)] -= 1;
                    strength[(ballRow + 1)][(ballCol + 1)] -= 1;
                    
                    if (ballDown == true && ballRight == false && ballLeft == false) { //Ball is coming straight down
                    ballDown = false;
                }
                else if (ballDown == true && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight = true;
                        ballLeft = false;
                        ballDown = false;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft = true;
                        ballRight = false;
                        ballDown = false;
                        }
                    }
                }
            }
            else if ( (ballRow % 2) == 1) {
                if (strength[(ballRow)][ballCol + 1] > 0) {
                    strength[(ballRow)][ballCol + 1] -= 1;
                    strength[(ballRow - 1)][(ballCol + 1)] -= 1;
                    
                    if (ballDown == true && ballRight == false && ballLeft == false) { //Ball is coming straight down
                    ballDown = false;
                }
                else if (ballDown == true && (ballRight == true || ballLeft == true)) { //Ball is coming at an angle
                    if (ballRight == true) { //Ball is coming right-diagonally
                        ballRight = true;
                        ballLeft = false;
                        ballDown = false;
                    }
                    if (ballLeft == true) { //Ball is coming left-diagonally
                        ballLeft = true;
                        ballRight = false;
                        ballDown = false;
                        }  
                    }
                }
            }
            
        }
    }
}





boolean Board::levelComplete() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16; j++) {
            if (strength [i][j] > 0) {
                return false;
            }
        }
    }
    return true;
}

void Board::initStrength() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16; j++) {
            strength [i][j] = 0;
        }
    }
}





// JSYK: FUNCTIONS BELOW DIRECTLY INTERACT WITH THE ADAFRUIT DISPLAY BOARD!
//       (All have been stubbed -- until properly implemented! Please delete RME's once implemented!)




//EFFECTS:turns off all the pixels on the board

void clearBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 16; j++){
            matrix.drawPixel(i, j, LED_OFF);
        }
    }
}


//REQUIRES:  val is the value of the potentiometer

//MODIFIES: nothing

//EFFECTS: returns the column position of the left pixel of the paddle

int calculatePaddlePosition(int val) { // FINISH IMPLEMENTATION!! -- go by 0s
    //    int sensorValue = analogRead(A0); // Use pin for the potentiometer pin, not A0, potPin?
    //    delay(1);
    if (val >= 0 && val <= 150) {
        return 0;
    }
    if (val >= 151 && val <= 300) {
        return 1;
    }
    if (val >= 301 && val <= 450) {
        return 2;
    }
    if (val >= 451 && val <= 600) {
        return 3;
    }
    if (val >= 601 && val <= 750) {
        return 4;
    }
    if (val >= 751 && val <= 900) {
        return 5;
    }
    if (val >= 901 && val <= 1024 ) {
        return 6;
    }
    
}

//EFFECTS:displays the number of lives remaining/level number on the board. If it doesn't all fit

//on the board at once, the text scrolls.

//use text size 1 and delay of 50

void printMessage(int number) {
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(number);
    matrix.writeDisplay();
    delay(100);
  }
}

//EFFECTS:displays string text needed(suchs as "LIVES" or "LEVEL") on the board. If it

//doesn't all fit on the board at once, the text scrolls.

//use text size 1 and delay of 50

void printMessage(String message) {
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(message);
    matrix.writeDisplay();
    delay(100);
  }
}



