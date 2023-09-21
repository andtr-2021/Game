#include "../uart/uart1.h"
#include "mbox.h"
#include "framebf.h"
#include "paddle.h"
#include "background.h"
#include "greenTile.h"
#include "blueTile.h"
#include "redTile.h"
#include "ball.h"
#include "../gcclib/stdbool.h"
#include "mbox.h"

struct Sprite
{
    int x;
    int y;
    int direction;
};

void offsetVirtual(int x, int y)
{
    mBuf[0] = 8 * 4; // Length of message in bytes
    mBuf[1] = MBOX_REQUEST;
    mBuf[2] = MBOX_TAG_SETVIRTOFF; // Set virtual offset
    mBuf[3] = 8;
    mBuf[4] = 0;
    mBuf[5] = x; // x offset
    mBuf[6] = y; // y offset
    mBuf[7] = MBOX_TAG_LAST;
    mbox_call(ADDR(mBuf), MBOX_CH_PROP);
}

void drawBackground(int x, int y)
{
    for (int j = y; j < 768; j++)
    {
        y++;
        for (int i = 0; i < 1024; i++)
        {
            drawPixelARGB32(i + x, y, background[j * 1024 + i]);
        }
    }
}

void drawBlueTile(int x, int y)
{
    for (int j = 0; j < 30; j++)
    {
        y++;
        for (int i = 0; i < 150; i++)
        {
            if (blueTile[j * 150 + i] != 0x00)
                drawPixelARGB32(i + x, y, blueTile[j * 150 + i]);
        }
    }
}

void drawGreenTile(int x, int y)
{
    for (int j = 0; j < 30; j++)
    {
        y++;
        for (int i = 0; i < 150; i++)
        {
            if (greenTile[j * 150 + i] != 0x00)
                drawPixelARGB32(i + x, y, greenTile[j * 150 + i]);
        }
    }
}

void drawRedTile(int x, int y)
{
    for (int j = 0; j < 30; j++)
    {
        y++;
        for (int i = 0; i < 150; i++)
        {
            if (redTile[j * 150 + i] != 0x00)
                drawPixelARGB32(i + x, y, redTile[j * 150 + i]);
        }
    }
}

// Function draw paddle.
void drawPaddle(int x, int y)
{
    // Draw image paddle.
    for (int j = 0; j < 24; j++)
    {
        y++;
        for (int i = 0; i < 127; i++)
        {
            /*Draw image paddle pixle by pixel according to */
            drawPixelARGB32(i + x, y, paddle[j * 127 + i]);
        }
    }
}

// Function cover paddle trace.
void movePaddle(char *str, int paddleX)
{
    int count = 0;
    if (str[0] == 'd')
    {
        // Using same method as drawing image.
        for (int j = 700; j < 725; j++)
        {
            for (int i = paddleX; i < paddleX + 50; i++)
            {
                // Draw background image on top of paddle trace
                drawPixelARGB32(i, j, background[j * 1024 + i + paddleX]);
            }
        }
    }

    if (str[0] == 'a')
    {
        // Using same method as drawing image.
        for (int j = 700; j < 725; j++)
        {
            for (int i = paddleX + 127; i > paddleX + 77; i--)
            {
                // Draw background image to cover paddle trace
                drawPixelARGB32(i, j, background[j * 1024 + i + paddleX]);
            }
        }
    }
}

void draw_ball(int x, int y) {
    for (int j = 0; j < 50; j++) {
        y++;
        for (int i = 0; i < 50; i++) {
            unsigned int pixel = ball[j * 50 + i];
            
            // Check if the pixel is not transparent (not black)
            if (pixel != 0x00ffffff) {
                drawPixelARGB32(i + x, y, pixel);
            } else {
                // Search for the nearest non-transparent pixel in the surrounding area
                for (int offset = 1; offset <= 7; offset++) {
                    if (i + offset < 50 && ball[j * 50 + i + offset] != 0x00) {
                        drawPixelARGB32(i + x, y, background[y * 1024 + x + i]);
                        break;
                    } else if (i - offset >= 0 && ball[j * 50 + i - offset] != 0x00) {
                        drawPixelARGB32(i + x, y, background[y * 1024 + x + i]);
                        break;
                    } else if (j - 1 >= 0 && ball[(j - 1) * 50 + i] != 0x00) {
                        drawPixelARGB32(i + x, y, background[y * 1024 + x + i]);
                        break;
                    } else if (j + 1 < 50 && ball[(j + 1) * 50 + i] != 0x00) {
                        drawPixelARGB32(i + x, y, background[y * 1024 + x + i]);
                        break;
                    }
                }
            }
        }
    }
}


int detectCollision(int x, int y, int direction,struct Sprite* tiles)
{
    // Declare variables: count, dir, pre_dir.
    int count = 0;
    int dir = 0;
    int pre_dir = 0;
    /*Set dir to be equal with direction, so that if the function dectect no collision between the ball and the tiles
    it will maintance current direction of the ball.*/
    dir = direction;
    pre_dir = dir;
    for (int i = 0; i < 40; i++)
    {
        // Collision on the top and bottom of the tiles
        if (((x > tiles[i].x) && (x < (tiles[i].x + 150))) || (((x + 50) > tiles[i].x) && ((x + 50) < (tiles[i].x + 150))))
        {
            /*Check if the ball hits a tile from bottom up.*/
            if (y == (tiles[i].y + 30))
            {
                // Call function delete tile for visually and in the tiles array.
                deleteTile_Visual(tiles[i].x, tiles[i].y);
                deleteTile_Array(i, tiles);
                if (pre_dir == 9)
                    dir = 5;
                else if (pre_dir == 3)
                    dir = 1;
                else if (pre_dir == 2)
                    dir = 4;
                else if (pre_dir == 10)
                    dir = 7;
                else
                    dir = 1;
            }

            /*Check is the ball hit a tile from top down.*/
            if ((y + 50) == tiles[i].y)
            {
                // Call function delete tile for visually and in the tiles array.
                deleteTile_Visual(tiles[i].x, tiles[i].y);
                deleteTile_Array(i, tiles);
                if (pre_dir == 1)
                    dir = 3;
                else if (pre_dir == 5)
                    dir = 9;
                else if (pre_dir == 4)
                    dir = 2;
                else if (pre_dir == 7)
                    dir = 10;
                else
                    dir = 3;
            }
        }
        // Collision in the top left corner of the tile
        else if (((x + 50) == tiles[i].x) && ((y + 50) == tiles[i].y))
        {
            // Call function delete tile for visually and in the tiles array.
            deleteTile_Visual(tiles[i].x, tiles[i].y);
            deleteTile_Array(i, tiles);
            if (pre_dir == 1)
                dir = 3;
            else if (pre_dir == 5)
                dir = 9;
            else if (pre_dir == 4)
                dir = 2;
            else if (pre_dir == 7)
                dir = 10;
            else
                dir = 2;
        }
        // Collision in the bottom left corner of the tile
        else if (((x + 50) == tiles[i].x) && (y == (tiles[i].y + 30)))
        {
            // Call function delete tile for visually and in the tiles array.
            deleteTile_Visual(tiles[i].x, tiles[i].y);
            deleteTile_Array(i, tiles);
            if (pre_dir == 9)
                dir = 5;
            else if (pre_dir == 3)
                dir = 1;
            else if (pre_dir == 2)
                dir = 4;
            else if (pre_dir == 10)
                dir = 7;
            else
                dir = 4;
        }
        // Collision in the top left corner of the tile
        else if ((x == tiles[i].x) && ((y + 50) == tiles[i].y))
        {
            // Call function delete tile for visually and in the tiles array.
            deleteTile_Visual(tiles[i].x, tiles[i].y);
            deleteTile_Array(i, tiles);
            if (pre_dir == 1)
                dir = 3;
            else if (pre_dir == 5)
                dir = 9;
            else if (pre_dir == 4)
                dir = 2;
            else if (pre_dir == 7)
                dir = 10;
            else
                dir = 3;
        }
        // Collision in the bottom right corner of the tile
        else if ((x == (tiles[i].x + 150)) && (y == (tiles[i].y + 30)))
        {
            // Call function delete tile for visually and in the tiles array.
            deleteTile_Visual(tiles[i].x, tiles[i].y);
            deleteTile_Array(i, tiles);
            if (pre_dir == 9)
                dir = 5;
            else if (pre_dir == 3)
                dir = 1;
            else if (pre_dir == 2)
                dir = 4;
            else if (pre_dir == 10)
                dir = 7;
            else
                dir = 1;
        }
        // Checking if the ball hit tile/s with partial of the ball from side to side.
        else if ((y <= tiles[i].y) && (y >= (tiles[i].y + 30)))
        {
            // Checking if partial of the ball hit tile/s from the left side of the tile.
            if ((x + 50) == tiles[i].x)
            {
                // Call function delete tile for visually and in the tiles array.
                deleteTile_Visual(tiles[i].x, tiles[i].y);
                deleteTile_Array(i, tiles);
                if (pre_dir == 9)
                    dir = 10;
                else if (pre_dir == 1)
                    dir = 4;
                else if (pre_dir == 3)
                    dir = 2;
                else if (pre_dir == 5)
                    dir = 7;
                else
                    dir = 2;
            }

            // Checking if partial of the ball hit tile/s from the right side of the tile.
            if (x == (tiles[i].x + 150))
            {
                // Call function delete tile for visually and in the tiles array.
                deleteTile_Visual(tiles[i].x, tiles[i].y);
                deleteTile_Array(i, tiles);
                if (pre_dir == 2)
                    dir = 3;
                else if (pre_dir == 10)
                    dir = 9;
                else if (pre_dir == 7)
                    dir = 5;
                else if (pre_dir == 4)
                    dir = 1;
                else
                    dir = 3;
            }
        }
        // Checking if the ball hit tile/s fully side to side.
        else if (((tiles[i].y >= y) && (tiles[i].y <= (y + 50))) || (((tiles[i].y + 30) >= y) && ((tiles[i].y + 30) <= (y + 50))))
        {
            if (x + 50 == tiles[i].x)
            {
                // Call function delete tile for visually and in the tiles array.
                deleteTile_Visual(tiles[i].x, tiles[i].y);
                deleteTile_Array(i, tiles);
                if (pre_dir == 9)
                    dir = 10;
                else if (pre_dir == 1)
                    dir = 4;
                else if (pre_dir == 3)
                    dir = 2;
                else if (pre_dir == 5)
                    dir = 7;
                else
                    dir = 2;
            }

            if (x == (tiles[i].x + 150))
            {
                // Call function delete tile for visually and in the tiles array.
                deleteTile_Visual(tiles[i].x, tiles[i].y);
                deleteTile_Array(i, tiles);

                if (pre_dir == 2)
                    dir = 3;
                else if (pre_dir == 10)
                    dir = 9;
                else if (pre_dir == 7)
                    dir = 5;
                else if (pre_dir == 4)
                    dir = 1;
                else
                    dir = 3;
            }
        }
        pre_dir = dir;
    }
    // return any value dir have.
    return dir;
}

void deleteTile_Visual(int x, int y)
{
    for(int i = x; i < (x + 170); i++){
        for(int j = y; j < (y + 32); j++){
            drawPixelARGB32(i, j, background[j * 1024 + i]);
        }
    }
}

void deleteTile_Array(int position, struct Sprite* tiles){
    // Start from the position of the collided tile
    int count = position;
    
    // Continue until the end of the 'tiles' array is reached
    while (tiles[count].x != 0 && count < 39) {
        // Replace the current tile's coordinates with the next tile's coordinates
        tiles[count].x = tiles[count + 1].x;
        tiles[count].y = tiles[count + 1].y;
        
        // Move to the next element in the array
        count++;
    }
    
    // Set the last element to 0 to mark the end of the array
    tiles[count].x = 0;
    tiles[count].y = 0;
}

int collisionPaddle(int ballX, int ballY, int paddleX, int direction)
{
    int dir = direction;  // Initialize dir with the given direction

    // Check if the ball's x-coordinate is within the paddle's x-range
    if ((ballX >= paddleX && ballX <= paddleX + 127) || (ballX + 50 >= paddleX && ballX + 50 <= paddleX + 127))
    {
        // Check if the ball's bottom edge is at the same y-level as the top of the paddle
        if (ballY + 50 == 700)
        {
            // Check which part of the paddle the ball hit
            if ((ballX + 50) >= paddleX && (ballX + 50) <= (paddleX + 40))
            {
                // Handle ball collision with the leftmost part of the paddle
                if (dir == 1)
                {
                    dir = 9;
                }
                else if (dir == 4)
                {
                    dir = 10;
                }
                else
                {
                    dir = 9;
                }
            }
            else if (ballX < (paddleX + 87) && (ballX + 50) > (paddleX + 40))
            {
                // Handle ball collision with the middle part of the paddle
                if (dir == 1)
                {
                    dir = 3;
                }
                else if (dir == 4)
                {
                    dir = 2;
                }
                else
                {
                    dir = 3;
                }
            }
            else if (ballX <= (paddleX + 127) && (ballX + 50) >= (paddleX + 87))
            {
                // Handle ball collision with the rightmost part of the paddle
                if (dir == 1)
                {
                    dir = 9;
                }
                else if (dir == 4)
                {
                    dir = 10;
                }
                else
                {
                    dir = 9;
                }
            }
        }
        else if ((ballY + 50 >= 700) && (ballY + 50 <= 730))
        {
            // Ball hits the left side of the paddle
            if (((ballX + 50) >= paddleX) && ((ballX + 50) <= paddleX + 127))
            {
                if (dir == 1)
                {
                    dir = 9;
                }
                else if (dir == 4)
                {
                    dir = 10;
                }
                else
                {
                    dir = 9;
                }
            }

            // Ball hits the right side of the paddle
            if ((ballX <= (paddleX + 127)) && (ballX >= (paddleX + 127)))
            {
                if (dir == 1)
                {
                    dir = 9;
                }
                else if (dir == 4)
                {
                    dir = 10;
                }
                else
                {
                    dir = 9;
                }
            }
        }
        else if ((ballX + 50 == paddleX) && (ballY + 50 == 700))
        {
            // Handle ball collision with the leftmost part of the paddle
            if (dir == 1)
            {
                dir = 9;
            }
            else if (dir == 4)
            {
                dir = 10;
            }
            else
            {
                dir = 9;
            }
        }
        else if ((ballX == paddleX) && (ballY + 50 == 700))
        {
            // Handle ball collision with the rightmost part of the paddle
            if (dir == 1)
            {
                dir = 9;
            }
            else if (dir == 4)
            {
                dir = 10;
            }
            else
            {
                dir = 9;
            }
        }
        return dir;
    }

    // Return the updated direction
    return dir;
}

// Function to remove the coordinates of a collided tile from the 'tiles' array
int collisionWithBrick(int ballX, int ballY, int tileX, int tileY, int direction){
    // Delare variable dir, pre_dir.
    int dir = 0;
    int pre_dir = 0;
    // set dir to be equal with direction.
    /*In case the function is dectect no collision between the ball and the paddle, it will return the same current
    direction of the ball.*/
    dir = direction;
    /*Condition to check if the bottom of the ball is on the same y axis with the top of the brick and stay within
    the length of the brick.*/
    if (((ballX > tileX) && (ballX < tileX + 240)) || (((ballX + 50) > tileX) && (ballX + 50 < tileX + 240)))
    {
        if (ballY + 50 == tileY)
        {
            // Condition to decide direction whether the ball collide with which part of the paddle will bounce back.
            // If the ball hit the first 60 pixels of the brick.
            if ((((ballX + 50) >= tileX) && ((ballX + 50) <= (tileX + 80))))
            {
                // Direction the ball will bounce back.
                if (dir == 1)
                    dir = 3;
                else if (dir == 4)
                    dir = 10;
                else
                    dir = 10;
            }
            // If the ball hit the middle part of the brick (from pixle 80 - 160).
            else if (((ballX < (tileX + 160)) && ((ballX + 50) > (tileX + 80))))
            {
                // Direction the ball will bounce back.
                if (dir == 1)
                    dir = 3;
                else if (dir == 4)
                    dir = 2;
                else
                    dir = 3;
            }
            // If the ball hit the rightmost pixels of the brick.
            else if (((ballX <= (tileX + 240)) && ((ballX + 50) >= (tileX + 160))))
            {
                // Direction the ball will bounce back.
                if (dir == 1)
                    dir = 9;
                else if (dir == 4)
                    dir = 10;
                else
                    dir = 9;
            }
        }
        /*Condition to check if the bottom of the ball is on the same y axis with the bottom of the brick and stay within
        the length of the brick.*/
        // uart_dec(dir);

        if (ballY == (tileY + 20))
        {
            // Condition to decide direction whether the ball collide with which part of the paddle will bounce back.
            // If the ball hit the first 100 pixels of the brick.
            if ((((ballX + 50) >= tileX) && ((ballX + 50) <= (tileX + 80))))
            {
                // Direction the ball will bounce back.
                if (dir == 10)
                    dir = 7;
                else if (dir == 9)
                    dir = 5;
                else
                    dir = 7;
            }
            // If the ball hit the middle part of the paddle (from pixle 100 - 200).
            else if (((ballX < (tileX + 160)) && ((ballX + 50) > (tileX + 80))))
            {
                // Direction the ball will bounce back.
                if (dir == 2)
                    dir = 4;
                else if (dir == 3)
                    dir = 1;
                else
                    dir = 4;
            }
            // If the ball hit the rightmost pixels of the brick.
            else if (((ballX <= (tileX + 240)) && ((ballX + 50) >= (tileX + 160))))
            {
                // Direction the ball will bounce back.
                if (dir == 9)
                    dir = 5;
                else if (dir == 3)
                    dir = 1;
                else
                    dir = 5;
            }
        }

        // pre_dir = dir;
    }
    // Checking if the ball hit tile/s with partial of the ball from side to side.
    else if ((ballY <= (tileY + 20)) && (ballY >= tileY))
    {
        // Checking if partial of the ball hit brick from the left side of the tile.
        if ((ballX + 50) == tileX)
        {
            if (dir == 9)
                dir = 10;
            else if (dir == 1)
                dir = 4;
            else if (dir == 3)
                dir = 2;
            else if (dir == 5)
                dir = 7;
            else
                dir = 2;
        }

        // Checking if partial of the ball hit brick from the right side of the tile.
        if (ballX == (tileX + 240))
        {
            if (dir == 2)
                dir = 3;
            else if (dir == 10)
                dir = 9;
            else if (dir == 7)
                dir = 5;
            else if (dir == 4)
                dir = 1;
            else
                dir = 3;
        }
    }
    // Checking if the ball hit brick fully side to side.
    else if (((tileY >= ballY) && (tileY <= (ballY + 50))))
    {
        if (ballX + 50 == tileX)
        {
            if (dir == 9)
                dir = 10;
            else if (dir == 1)
                dir = 4;
            else if (dir == 3)
                dir = 2;
            else if (dir == 5)
                dir = 7;
            else
                dir = 2;
        }

        if (ballX == (tileX + 240))
        {
            if (dir == 2)
                dir = 3;
            else if (dir == 10)
                dir = 9;
            else if (dir == 7)
                dir = 5;
            else if (dir == 4)
                dir = 1;
            else
                dir = 3;
        }
    }
    return dir;
}
