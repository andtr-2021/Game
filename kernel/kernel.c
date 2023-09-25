#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include "function.h"
#include "../gcclib/stdbool.h"
#include "mbox.h"
#include "font.h"
#include "colors.h"
#include "printf.h"

// Logic of strcmp from https://www.techiedelight.com/implement-strcmp-function-c/
bool my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            return false;
        }
        str1++;
        str2++;
    }
    return (*str1 == '\0' && *str2 == '\0');
}
// Logic for implementation of strstr() from string.h in C from https://sillycodes.com/strstr-function-implementation-in-c-language/
bool my_strcontain(const char *str, const char *substr)
{
    while (*str)
    {
        //
        if (*str == *substr)
        {
            // Save the current position in str
            const char *temp_str = str;
            const char *temp_substr = substr;

            // Check if the substring matches
            while (*temp_str && *temp_substr && *temp_str == *temp_substr)
            {
                temp_str++;
                temp_substr++;
            }

            // If the substring is fully matched, return true
            if (!*temp_substr)
            {
                return true;
            }
        }
        str++;
    }
    return false;
}

int my_strlen_array(char *str[])
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void freeMemory(unsigned long *str[])
{
    for (int i = 0; i < 14; i++)
    {
        str[i] = 0;
    }
}

void addScore(int score)
{

    if (score == 1)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num1};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 2)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num2};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 3)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num3};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 4)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num4};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 5)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num5};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 6)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num6};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 7)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num7};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 8)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num8};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 9)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num9};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 10)
    {
        uart_puts("it is 10");
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num0};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
}

void addScore2(int score)
{

    if (score == 11)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num1};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 12)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num2};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 13)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num3};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 14)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num4};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 15)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num5};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 16)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num6};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 17)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num7};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 18)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num8};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 19)
    {
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num9};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 20)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num0};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
}

void addScore3(int score)
{

    // make from 21 to 30
    if (score == 21)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num1};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 22)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num2};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 23)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num3};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 24)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num4};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 25)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num5};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 26)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num6};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 27)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num7};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 28)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num8};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 29)
    {
        unsigned long *score[2] = {epd_bitmap_num2, epd_bitmap_num9};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 30)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num0};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
}

void addScore4(int score)
{
    // make from 31 to 40
    if (score == 31)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num1};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 32)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num2};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 33)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num3};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 34)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num4};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 35)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num5};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 36)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num6};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 37)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num7};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 38)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num8};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 39)
    {
        unsigned long *score[2] = {epd_bitmap_num3, epd_bitmap_num9};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 40)
    {
        unsigned long *score[2] = {epd_bitmap_num4, epd_bitmap_num0};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
}

void addScoreForStage2(int score)
{
    // draw the score 
    unsigned long *scoreWord[10] = {epd_bitmap_s, epd_bitmap_c, epd_bitmap_o, epd_bitmap_r, epd_bitmap_e, epd_bitmap_colon};
    drawStrScaledDown(0, 0, scoreWord, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);

    unsigned long *stage2[8] = {epd_bitmap_space, epd_bitmap_s, epd_bitmap_t, epd_bitmap_a, epd_bitmap_g, epd_bitmap_e, epd_bitmap_num2};
    drawStrScaledDown(200, 0, stage2, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);

    
    if (score == 0) {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num0};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    } else if (score == 1)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num1};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 2)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num2};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 3)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num3};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 4)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num4};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 5)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num5};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 6)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num6};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 7)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num7};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 8)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num8};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 9)
    {
        unsigned long *score[2] = {epd_bitmap_num0, epd_bitmap_num9};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }
    else if (score == 10)
    {
        uart_puts("it is 10");
        unsigned long *score[2] = {epd_bitmap_num1, epd_bitmap_num0};
        drawStrScaledDown(150, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(score);
    }

    
}

void minusLife(int life)
{

    if (life == 2)
    {
        unsigned long *life[2] = {epd_bitmap_num0, epd_bitmap_num2};
        drawStrScaledDown(975, 0, life, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(life);
    }
    else if (life == 1)
    {
        unsigned long *life[2] = {epd_bitmap_num0, epd_bitmap_num1};
        drawStrScaledDown(975, 0, life, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(life);
    }
    else if (life == 0)
    {
        unsigned long *life[2] = {epd_bitmap_num0, epd_bitmap_num0};
        drawStrScaledDown(975, 0, life, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(life);
    }
}

void drawLifeForStage2(int life)
{

    if (life == 2)
    {
        unsigned long *life[10] = { epd_bitmap_s, epd_bitmap_c, epd_bitmap_o, epd_bitmap_r, epd_bitmap_e, epd_bitmap_colon, epd_bitmap_num0, epd_bitmap_num2};
        drawStrScaledDown(800, 0, life, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(life);
    }
    else if (life == 1)
    {
        unsigned long *life[10] = { epd_bitmap_s, epd_bitmap_c, epd_bitmap_o, epd_bitmap_r, epd_bitmap_e, epd_bitmap_colon, epd_bitmap_num0, epd_bitmap_num1};
        drawStrScaledDown(800, 0, life, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(life);
    } else if (life == 0)
    {
        unsigned long *life[10] = { epd_bitmap_s, epd_bitmap_c, epd_bitmap_o, epd_bitmap_r, epd_bitmap_e, epd_bitmap_colon, epd_bitmap_num0, epd_bitmap_num0};
        drawStrScaledDown(800, 0, life, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(life);
    }
}

struct Sprite
{
    int x;
    int y;
    int direction;
};

void gameStage2(int start, int life) {

    // set up serial console
    uart_init();
    // Initialize frame buffer
    framebf_init();
    // Initialize struct obstacle

      drawBackground(0, 0);
    // draw welcome to stage 2 
    unsigned long *welcomeToStage2[20] = {epd_bitmap_w, epd_bitmap_e, epd_bitmap_l, epd_bitmap_c, epd_bitmap_o, epd_bitmap_m, epd_bitmap_e, epd_bitmap_space, epd_bitmap_t, epd_bitmap_o, epd_bitmap_space, epd_bitmap_s, epd_bitmap_t, epd_bitmap_a,epd_bitmap_g, epd_bitmap_e, epd_bitmap_space, epd_bitmap_num2}; 
    drawStrScaledDown(300, 300, welcomeToStage2, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
    freeMemory(welcomeToStage2);

    wait_msec(5000000);
    
    uart_puts("Stage 2 initiate");
    struct Sprite obstacleLeft;
    struct Sprite obstacleRight;
    obstacleLeft.x = 30;
    obstacleLeft.y = 375;
    obstacleLeft.direction = 1;
    obstacleRight.x = 849;
    obstacleRight.y = 375;
    obstacleRight.direction = 1;
    // Start with image at index 0
    int ballX = 550, ballY = 650;
    // direction is the direction of the ball, 0 is the ball fly directly upward.
    int direction = 0;
    // index is the index of the tile in the tiles array.
    int index = 0;
    // isCollide is the flag to check if the ball hit the tile.
    int isCollide = 0, isIni = 0;
    // count is the counter for the inputBuffer.
    int count = 0;
    // start is the flag to check if the game is started.
       
    // inputBuffer is the buffer to store the input from the keyboard.
    char inputBuffer[60]; // A separate buffer for UART input
    // tiles is the array to store all the tiles in the game.
    struct Sprite tiles[40];
    // initialize tiles[40]
    for (int i = 0; i < 40; i++)
    {
        tiles[i].x = 0;
        tiles[i].y = 0;
        tiles[i].direction = 0;
    }
    // i is the index of the tiles array.
    int i = 0;
    // paddleX is the x coordinate of the paddle.
    int paddleX = 500;
    // Draw the background and the paddle.
    drawBackground(0, 0);
    // Draw the paddle at the center of the screen.
    drawPaddle(paddleX, 700);
    // Draw the whole game board
    // Stage 3 : Drawing The Second Time 
    while (start > 2 && start < 4 )
    {
        
        drawObstacle(obstacleLeft.x, obstacleLeft.y , obstacleLeft.direction);
        drawObstacle(obstacleRight.x, obstacleRight.y, obstacleRight.direction);
        // Draw all tiles in a column.
        for (int x = 90; x < 900; x += 170)
        {   
            
           // Draw all tiles in a row.
            for (int y = 50; y < 280; y += 32)
            {
                // Draw blue tile at position any x, and y = 50.
                if (y == 50)
                {
                    // Draw yellow tile at position any x, and y = 50.
                    drawBlueTile(x, y);
                    // Saving the tile coordinate to the tiles array.
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                // Draw green title at position any x and y = 82
                else if (y == 82)
                {
                    drawGreenTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }

                // Draw green title at position any x and y = 82
                else if (y == 114)
                {
                    drawRedTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }

                // Draw green title at position any x and y = 146
                else if (y == 146)
                {
                    drawGreenTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 178)
                {
                    drawBlueTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 210)
                {
                    drawRedTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 242)
                {
                    drawGreenTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 274)
                {
                    drawBlueTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
            }
        }

        // score : 00
        int score = 0; 
        addScoreForStage2(score);

        freeMemory(score);

        // life : 3
        drawLifeForStage2(life);

        // move to the next stage
        start = start + 1;
    }

    // Play the Gmae the Second TIME 
    // score is the score of the player.
    int scoreUser = 0;
    // life is the life of the player.
    int lifeUser = life; 

    // Control the paddle with keyboard input
    while (start > 3 && start < 5)
    {

        // Check if the ball is in the screen frame.
        if ((ballX <= 955 && ballX >= -127) && (ballY <= 786 && ballY >= 0))
        {

            // Called draw_pixelBall constantly with coordinate value of ballX and ballY.
            draw_ball(ballX, ballY);

            /*Get direction from function collisionPaddle function for the ball change direction when it hit
            the paddle.*/
            direction = collisionPaddle(ballX, ballY, paddleX, direction);

            // divide all three side of the screen frame into half(the screen frame will be called as wall).
            /*Check if the ball hit the top wall, and the ball hit left side of the wall.*/
            if ((ballY == 50))
            {
                if (direction == 2)
                    direction = 4;
                else if (direction == 3)
                    direction = 1;
                else if (direction == 10)
                    direction = 7;
                else if (direction == 9)
                    direction = 5;
                else
                    direction = 1;
            }
            else if ((ballX == 0) || (ballX == 1))
            {
                if (direction == 4)
                    direction = 1;
                else if (direction == 2)
                    direction = 3;
                else if (direction == 10)
                    direction = 9;
                else if (direction == 7)
                    direction = 5;
                else
                    direction = 1;
            }
            else if ((ballX == 955) || (ballX == 954))
            {
                if (direction == 1)
                    direction = 4;
                else if (direction == 3)
                    direction = 2;
                else if (direction == 9)
                    direction = 10;
                else if (direction == 5)
                    direction = 7;
                else
                    direction = 2;
            }

            // Condition to let the ball fly in direction 1.
            if (direction == 1)
            {
                ballX++;
                ballY++;
                if (ballX == 955)
                {
                    continue;
                }
            }
            // Condition to let the ball fly in direction 2.
            else if (direction == 2)
            {
                ballX--;
                ballY--;
                if ((ballX == 0) || (ballY == 0))
                {
                    continue;
                }
            }
            // Condition to let the ball fly in direction 3.
            else if (direction == 3)
            {
                ballX++;
                ballY--;
                if (ballX == 955 || ballY == 0)
                {
                    continue;
                }
            }
            // Condition to let the ball fly in direction 4.
            else if (direction == 4)
            {
                ballX--;
                ballY++;
                if (ballX == 0)
                {
                    continue;
                }
            }
            else if (direction == 5)
            {
                ballX = ballX + 1;
                ballY++;
                if (ballX == 956)
                {
                    continue;
                }
            }
            // Fall straight downwards
            else if (direction == 6)
            {
                ballX++;
                if (ballY == 955)
                {
                    continue;
                }
            }
            else if (direction == 7)
            {
                ballX = ballX - 2;
                ballY++;
                if (ballX == 0)
                {
                    continue;
                }
            }
            else if (direction == 8)
            {
                ballX++;
                ballY = ballY - 2;
                if (ballX == 955 || ballY == 0)
                {
                    continue;
                }
            }
            else if (direction == 9)
            {
                ballX += 2;
                ballY--;
                if (ballX == 955 || ballY == 0)
                {
                    continue;
                }
            }
            else if (direction == 10)
            {
                ballX -= 2;
                ballY--;
                if (ballX == 0 || ballY == 0)
                {
                    continue;
                }
            }
            /*the ball fly directly upward as begining of the game, or after returned when players faild to catch
            the ball with the paddle.*/
            else
            {
                ballY--;
                if (ballY == 0)
                {
                    continue;
                }
            }

            // direction = tiles->direction;
            // Get direction from function detectCollision if the ball hit tiles.
            int checkCollideTile = 0;
            direction = collisionWithObstacle(ballX, ballY, obstacleLeft.x, obstacleLeft.y, direction);

            direction = collisionWithObstacle(ballX, ballY, obstacleRight.x, obstacleRight.y, direction);
            // direction = collisionWithObstacle(ballX, ballY, obstacleRight.x, obstacleRight.y, obstacleRight.direction);

            direction = detectCollision(ballX, ballY, direction, tiles, &checkCollideTile);

            if (checkCollideTile == 1)
            {
                scoreUser = scoreUser + 1;
                printf("score: %d\n", scoreUser);

                if (scoreUser <= 10)
                {
                    addScoreForStage2(scoreUser);
                }
            }

            if (scoreUser > 3)
            {
                start = start + 1;
            }

            // Slow down the running speed of the program to allow hummand can see the ball.
            wait_msec(3000);
        }
        else
        {
            // reset ballX to 500, ballY to 650 and direction to 0 when the ball drop of from the screen.
            ballX = 500;
            ballY = 650;
            paddleX = 500;
            drawBackground(paddleX, 690);
            drawPaddle(paddleX, 700);
            direction = 0;
            lifeUser = lifeUser - 1;
            drawLifeForStage2(lifeUser);

            if (lifeUser == 0)
            {
                start = start + 1; 
            }
        }

        char c = getUart();

        count = 0;

        uart_sendc(c);

        inputBuffer[count] = c;
        count++;
        inputBuffer[count] = '\0'; // Null-terminate the input buffer
        uart_puts("\n");

        // Process user input and move the paddle
        if (my_strcmp(inputBuffer, "d"))
        {
            if (paddleX + 127 <= 977)
            {
                movePaddle(inputBuffer, paddleX);
                paddleX += 50;
                drawPaddle(paddleX, 700);
            }
        }

        if (my_strcmp(inputBuffer, "a"))
        {
            if (paddleX >= 10)
            {
                movePaddle(inputBuffer, paddleX);
                paddleX -= 50;
                drawPaddle(paddleX, 700);
            }
        }

    }

    drawBackground(0, 0);
    unsigned long *gameover[12] = {epd_bitmap_g, epd_bitmap_a, epd_bitmap_m, epd_bitmap_e, epd_bitmap_space, epd_bitmap_o, epd_bitmap_v, epd_bitmap_e, epd_bitmap_r, epd_bitmap_colon};
    drawStrScaledDown(400, 300, gameover, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
    freeMemory(gameover);

    
     
}


void main()
{
    // set up serial console
    uart_init();
    // Initialize frame buffer
    framebf_init();
    // Initialize struct obstacle
    // struct Sprite obstacle;
    // obstacle.x = 35;
    // obstacle.y = 375;
    // obstacle.direction = 1;

    drawBackground(0, 0);
    // draw welcome to the game
    unsigned long *welcome[20] = {epd_bitmap_w, epd_bitmap_e, epd_bitmap_l, epd_bitmap_c, epd_bitmap_o, epd_bitmap_m, epd_bitmap_e, epd_bitmap_space, epd_bitmap_t, epd_bitmap_o, epd_bitmap_space, epd_bitmap_t, epd_bitmap_h, epd_bitmap_e, epd_bitmap_space, epd_bitmap_g, epd_bitmap_a, epd_bitmap_m, epd_bitmap_e};
    drawStrScaledDown(300, 300, welcome, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
    freeMemory(welcome);

    wait_msec(5000000);

    // Start with image at index 0
    int ballX = 550, ballY = 650;
    // direction is the direction of the ball, 0 is the ball fly directly upward.
    int direction = 0;
    // index is the index of the tile in the tiles array.
    int index = 0;
    // isCollide is the flag to check if the ball hit the tile.
    int isCollide = 0, isIni = 0;
    // count is the counter for the inputBuffer.
    int count = 0;
    // start is the flag to check if the game is started.
    int start = 1;
    // leftbrickX is the x coordinate of the left brick.

    // inputBuffer is the buffer to store the input from the keyboard.
    char inputBuffer[60]; // A separate buffer for UART input
    // tiles is the array to store all the tiles in the game.
    struct Sprite tiles[40];
    // initialize tiles[40]
    for (int i = 0; i < 40; i++)
    {
        tiles[i].x = 0;
        tiles[i].y = 0;
        tiles[i].direction = 0;
    }
    // i is the index of the tiles array.
    int i = 0;
    // paddleX is the x coordinate of the paddle.
    int paddleX = 500;

    uart_puts("\n");
    uart_puts("Welcome to MyBareMetal!\n");

    // Draw the background and the paddle.
    drawBackground(0, 0);
    // Draw the paddle at the center of the screen.
    drawPaddle(paddleX, 700);

    // Stage 0 
    // Draw the whole game board.
    while (start > 0 && start < 2)
    {
        // Draw all tiles in a column.
        for (int x = 90; x < 900; x += 170)
        {
            // Draw all tiles in a row.
            for (int y = 50; y < 280; y += 32)
            {
                // Draw blue tile at position any x, and y = 50.
                if (y == 50)
                {
                    // Draw yellow tile at position any x, and y = 50.
                    drawBlueTile(x, y);
                    // Saving the tile coordinate to the tiles array.
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                // Draw green title at position any x and y = 82
                else if (y == 82)
                {
                    drawGreenTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }

                // Draw green title at position any x and y = 82
                else if (y == 114)
                {
                    drawRedTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }

                // Draw green title at position any x and y = 146
                else if (y == 146)
                {
                    drawGreenTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 178)
                {
                    drawBlueTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 210)
                {
                    drawRedTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 242)
                {
                    drawGreenTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
                else if (y == 274)
                {
                    drawBlueTile(x, y);
                    tiles[i].x = x;
                    tiles[i].y = y;
                    i++;
                }
            }
        }

        // score : 00
        unsigned long *score[9] = {epd_bitmap_s, epd_bitmap_c, epd_bitmap_o, epd_bitmap_r, epd_bitmap_e, epd_bitmap_colon, epd_bitmap_num0, epd_bitmap_num0};
        drawStrScaledDown(0, 0, score, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);

        freeMemory(score);

        // life : 3
        unsigned long *life[8] = {epd_bitmap_l, epd_bitmap_i, epd_bitmap_f, epd_bitmap_e, epd_bitmap_colon, epd_bitmap_num0, epd_bitmap_num3};
        drawStrScaledDown(850, 0, life, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);

        freeMemory(life);

        // move to the next stage
        start = start + 1;
    }

    // score is the score of the player.
    int scoreUser = 0;
    // life is the life of the player.
    int lifeUser = 3;

    // Stage 1
    // Control the paddle with keyboard input
    while (start > 1 && start < 3)
    {

        // Check if the ball is in the screen frame.
        if ((ballX <= 955 && ballX >= -127) && (ballY <= 786 && ballY >= 0))
        {

            // Called draw_pixelBall constantly with coordinate value of ballX and ballY.
            draw_ball(ballX, ballY);

            /*Get direction from function collisionPaddle function for the ball change direction when it hit
            the paddle.*/
            direction = collisionPaddle(ballX, ballY, paddleX, direction);

            // divide all three side of the screen frame into half(the screen frame will be called as wall).
            /*Check if the ball hit the top wall, and the ball hit left side of the wall.*/
            if ((ballY == 50))
            {
                if (direction == 2)
                    direction = 4;
                else if (direction == 3)
                    direction = 1;
                else if (direction == 10)
                    direction = 7;
                else if (direction == 9)
                    direction = 5;
                else
                    direction = 1;
            }
            else if ((ballX == 0) || (ballX == 1))
            {
                if (direction == 4)
                    direction = 1;
                else if (direction == 2)
                    direction = 3;
                else if (direction == 10)
                    direction = 9;
                else if (direction == 7)
                    direction = 5;
                else
                    direction = 1;
            }
            else if ((ballX == 955) || (ballX == 954))
            {
                if (direction == 1)
                    direction = 4;
                else if (direction == 3)
                    direction = 2;
                else if (direction == 9)
                    direction = 10;
                else if (direction == 5)
                    direction = 7;
                else
                    direction = 2;
            }

            // Condition to let the ball fly in direction 1.
            if (direction == 1)
            {
                ballX++;
                ballY++;
                if (ballX == 955)
                {
                    continue;
                }
            }
            // Condition to let the ball fly in direction 2.
            else if (direction == 2)
            {
                ballX--;
                ballY--;
                if ((ballX == 0) || (ballY == 0))
                {
                    continue;
                }
            }
            // Condition to let the ball fly in direction 3.
            else if (direction == 3)
            {
                ballX++;
                ballY--;
                if (ballX == 955 || ballY == 0)
                {
                    continue;
                }
            }
            // Condition to let the ball fly in direction 4.
            else if (direction == 4)
            {
                ballX--;
                ballY++;
                if (ballX == 0)
                {
                    continue;
                }
            }
            else if (direction == 5)
            {
                ballX = ballX + 1;
                ballY++;
                if (ballX == 956)
                {
                    continue;
                }
            }
            // Fall straight downwards
            else if (direction == 6)
            {
                ballX++;
                if (ballY == 955)
                {
                    continue;
                }
            }
            else if (direction == 7)
            {
                ballX = ballX - 2;
                ballY++;
                if (ballX == 0)
                {
                    continue;
                }
            }
            else if (direction == 8)
            {
                ballX++;
                ballY = ballY - 2;
                if (ballX == 955 || ballY == 0)
                {
                    continue;
                }
            }
            else if (direction == 9)
            {
                ballX += 2;
                ballY--;
                if (ballX == 955 || ballY == 0)
                {
                    continue;
                }
            }
            else if (direction == 10)
            {
                ballX -= 2;
                ballY--;
                if (ballX == 0 || ballY == 0)
                {
                    continue;
                }
            }
            /*the ball fly directly upward as begining of the game, or after returned when players faild to catch
            the ball with the paddle.*/
            else
            {
                ballY--;
                if (ballY == 0)
                {
                    continue;
                }
            }

            // direction = tiles->direction;
            // Get direction from function detectCollision if the ball hit tiles.
            int checkCollideTile = 0;

            // direction = collisionWithObstacle(ballX, ballY, obstacle.x, obstacle.y, direction);

            direction = detectCollision(ballX, ballY, direction, tiles, &checkCollideTile);

            if (checkCollideTile == 1)
            {
                scoreUser = scoreUser + 1;
                printf("score: %d\n", scoreUser);

                if (scoreUser <= 10)
                {
                    addScore(scoreUser);
                }
                else if (scoreUser > 10 && scoreUser <= 20)
                {
                    addScore2(scoreUser);
                }
                else if (scoreUser > 20 && scoreUser <= 30)
                {
                    addScore3(scoreUser);
                }
                else if (scoreUser > 30 && scoreUser <= 40)
                {
                    addScore4(scoreUser);
                }
            }

            if (scoreUser > 0)
            {
                start = start + 1;
            }

            // uart_puts(direction);
            // Slow down the running speed of the program to allow hummand can see the ball.
            wait_msec(3000);
        }
        else
        {
            // reset ballX to 500, ballY to 650 and direction to 0 when the ball drop of from the screen.
            ballX = 500;
            ballY = 650;
            paddleX = 500;
            drawBackground(paddleX, 690);
            drawPaddle(paddleX, 700);
            direction = 0;
            lifeUser = lifeUser - 1;
            minusLife(lifeUser);

            if (lifeUser == 0)
            {
                start += 1;
                break;
            }
        }

        char c = getUart();

        count = 0;

        uart_sendc(c);

        inputBuffer[count] = c;
        count++;
        inputBuffer[count] = '\0'; // Null-terminate the input buffer
        uart_puts("\n");

        // Process user input and move the paddle
        if (my_strcmp(inputBuffer, "d"))
        {
            if (paddleX + 127 <= 977)
            {
                movePaddle(inputBuffer, paddleX);
                paddleX += 50;
                drawPaddle(paddleX, 700);
            }
        }

        if (my_strcmp(inputBuffer, "a"))
        {
            if (paddleX >= 10)
            {
                movePaddle(inputBuffer, paddleX);
                paddleX -= 50;
                drawPaddle(paddleX, 700);
            }
        }

    } // while loop start >  1

    if (lifeUser == 0)
    {
        uart_puts("Enter stage 2");
        drawBackground(0, 0);
        unsigned long *gameover[12] = {epd_bitmap_g, epd_bitmap_a, epd_bitmap_m, epd_bitmap_e, epd_bitmap_space, epd_bitmap_o, epd_bitmap_v, epd_bitmap_e, epd_bitmap_r, epd_bitmap_colon};
        drawStrScaledDown(400, 300, gameover, 100, 100, COLOR_YELLOW, COLOR_BLUE, 4);
        freeMemory(gameover);

        return;
    }

    if (start >  2 && start << 3) {
        uart_puts("Enter stage 2");
        gameStage2(start, lifeUser);
    }
}
