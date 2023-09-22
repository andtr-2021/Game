#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H


// Function prototypes for graphics and game-related functions
void offsetVirtual(int x, int y);
void drawBackground(int x, int y);
void drawBlueTile(int x, int y);
void drawGreenTile(int x, int y);
void drawRedTile(int x, int y);
void drawPaddle(int x, int y);
void movePaddle(char* str, int paddleX);
void draw_ball(int x, int y);
int collisionWithPaddle(int ballX, int ballY, int paddleX, int direction);
void deleteTile_Array(int position, struct Sprite* tiles);
void deleteTile_Visual(int x, int y);
int collisionWithBrick(int ballX, int ballY, int brickX, int brickY, int direction);
int detectCollision(int x, int y, int direction,struct Sprite* tiles, int *checkCollideTile);


#endif // GAME_FUNCTIONS_H
