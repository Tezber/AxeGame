//header files either depicted in <> or "" known as the C++ libraries
//though this is an external library which are in "" while standard libraries are in <>
#include "raylib.h"

int main()
{
    //Window dimenstions
    int width(1000);     //declaring a new variable, width and its value
    int length(550);    //declaring a new variable, length and its value
    InitWindow(width, length, "The Bite"); //multiple function input split by using ','

    //Circle coordinates
    int circle_x(200);
    int circle_y(200);
    int circle_radius(25);
    //circle edges
    int l_circle_x(circle_x - circle_radius);
    int r_circle_x(circle_x + circle_radius);
    int u_circle_y(circle_y - circle_radius);
    int b_circle_y(circle_y + circle_radius);

    //Axe coordinates
    int axe_x(400);
    int axe_y(0);
    int axe_length(50);
    //axe edges
    int l_axe_x(axe_x);
    int r_axe_x(axe_x + axe_length);
    int u_axe_y(axe_y);
    int b_axe_y(axe_y + axe_length);

    int direction(10);

    //detects the collision between the two and is the operator to assume wether the game is over or not
    bool collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

    SetTargetFPS(60);
    while (WindowShouldClose() != true)    //unless hit the X button or an exit button keep the application open
    {
        BeginDrawing(); //sets up drawing
        ClearBackground(PURPLE); //must call this to avoid flickering and adds colour to canva or window

        if (collision_with_axe)
        {
            DrawText("Game Over!", 400, 225, 20, BLACK);
        }
        else
        {
            //game logic begins

            //update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            //update collision_with_axe
            collision_with_axe = 
                        (b_axe_y >= u_circle_y) && 
                        (u_axe_y <= b_circle_y) && 
                        (r_axe_x >= l_circle_x) && 
                        (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE); //Draws a circle
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED); //Draws the Rectangle or Axe

            //move the axe
            axe_y += direction; //could also be written as axe_y = axe_y + 10;
            if (axe_y > length || axe_y < 0)
            {
                direction = -direction; //whenever axe_y reaches the end it will move in the opposite diresction after reaching -10 upwards, vice versa with the OR (||) statement
            }

            //moving the circle
            if (IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10;
            }
            //game logic ends   
        }
        EndDrawing(); //tearsdown drawing
    }
}