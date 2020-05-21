
#include<stdio.h>
#define PI 3.141592654
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include <imagehlp.h>


int main(){

    //tile data
    int tiles[19][2] = {};
    int mouse_selected[2] = {0,0};
    int roads[42]= {0};
    int click_lock = 0;
    POINT mouse_location;
    srand(time(NULL));

    // number type
     /*
    7  = stone
    2  = sheep
    12 = brick
    10 = wood
    6  = wheat
    */
    int hex_x[19] = {960,1020.28,1020.28,960,960,900.72,900.72,1080.56,839.44,960,960,1020.28,1020.28, 900.72,900.72 ,1080.56,1080.56,839.44,839.44}; // tiles x location
    int hex_y[19] = {540 ,505.36 ,574.64,609.28,470.72,505.36,574.64,540,540,540+138.56,540-138.56,436.08,643.92,436.08,643.92, 470.72,609.28,470.72,609.28}; // tiles y location


/*
Color	Value
BLACK	0
BLUE	1
GREEN	2
CYAN	3
RED	4
MAGENTA	5
BROWN	6
LIGHTGRAY	7
DARKGRAY	8
LIGHTBLUE	9
LIGHTGREEN	10
LIGHTCYAN	11
LIGHTRED	12
LIGHTMAGENTA	13
YELLOW	14
WHITE	15

    */











    int hexagon_length = 40;
    float sin60 = 0.866025403, sin30 = 0.5;
    int catan = initwindow(1920,1080,"",-3,-3,true,true);
    //game window set
    //initalizing game board;
    for(int rng_tile= 0; rng_tile < 19;rng_tile++){

        switch (rand()%5){
    case 0:
        tiles[rng_tile][0] =7;
        tiles[rng_tile][1] =7;
        break;
    case 1:
        tiles[rng_tile][0] =2;
        tiles[rng_tile][1] =2;
        break;
    case 2:
        tiles[rng_tile][0] =12;
        tiles[rng_tile][1] =12;
        break;
    case 3:
        tiles[rng_tile][0] =10;
        tiles[rng_tile][1] =10;
        break;
    case 4:
        tiles[rng_tile][0] =6;
        tiles[rng_tile][1] =6;
        break;

        }
    }
    int page = 0;
    for(int refresh= 10;refresh >0;){
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        //drawing the game board
        for(int regret = 0;regret< 19;regret++){
            int arr[] = {hex_x[regret] - (20), hex_y[regret] + (40*sin60),
                         hex_x[regret] + (20), hex_y[regret] + (40*sin60),
                         hex_x[regret]+40,hex_y[regret],
                         hex_x[regret] + (20), hex_y[regret] - (40*sin60),
                         hex_x[regret] - (20), hex_y[regret] - (40*sin60),
                         hex_x[regret]-40,hex_y[regret],
                         hex_x[regret] - (20),hex_y[regret] + (40*sin60)};
            drawpoly(7,arr);
        //        int d;
        //scanf("%d",&d);
        }
        //tile colour





//42 conections  not including outsides
            rectangle(1300,100,1600,400);
            rectangle(1450,200,1550,225);
            outtextxy(1475,205,"house");



        GetCursorPos(&mouse_location);

        //putpixel(mouse_location.x,mouse_location.y,RED);
        //circle(mouse_location.x,mouse_location.y,10);
        //int line_check[2] = {99,99};

        for(int mouse_check = 0; mouse_check < 19;mouse_check++){
            setfillstyle(SOLID_FILL,tiles[mouse_check][0]);
            circle(hex_x[mouse_check],hex_y[mouse_check],37);
            int distance = sqrt(((mouse_location.x-hex_x[mouse_check])*(mouse_location.x-hex_x[mouse_check]))+((mouse_location.y-hex_y[mouse_check])*(mouse_location.y-hex_y[mouse_check])));
            if(distance <= 30){
                setfillstyle(SOLID_FILL,RED);
                if(GetAsyncKeyState(VK_LBUTTON) && mouse_selected[1] != 1){
                    mouse_selected[0] =  mouse_check;
                    mouse_selected[1] = 1;
                    tiles[mouse_check][0] = 4;
                    click_lock = 100;
                    printf("%d",click_lock);
                    do{}while(GetAsyncKeyState(VK_LBUTTON));
                 }
            }
            floodfill(hex_x[mouse_check],hex_y[mouse_check],WHITE);
            //printf("%d  ",distance);
        }
        //printf("\n");
        //if(line_check[0] != line_check[1]){
            //printf("owo");
        //}

//mouse_selected
// 1 = tile

 rectangle(1300,100,1600,400);

            rectangle(1450,200,1550,225);
            outtextxy(1475,205,"house");



        if(mouse_selected[1] == 1 && click_lock ==0){
            //printf("%d \n",mouse_selected[0]);











             if(GetAsyncKeyState(VK_LBUTTON)){
                for(int colour_reset = 0; colour_reset <19; colour_reset++){
                    tiles[colour_reset][0] =tiles[colour_reset][1];


                }
             }

        }
        //printf("%d",click_lock);
        if(click_lock > 0){
        click_lock--;
        }






    page = 1-page;









    }




    closegraph();

}

