#include "raylib.h"
#include "raymath.h"
#define CLOCK_IMPLEMENTATION
#include "clock.h"
#define window_height 540
#define window_width 740
#define pixeloffset 20
#define thickness 10.00
#define width1 GetScreenHeight()/3-20
#define width2 GetScreenHeight()/3
#define second  GOLD
#define minute  GREEN
#define hours BLUE
#define color_ring RED
#define BACKGROUND_COLOR BLACK
int main() {
    SetConfigFlags(0x00000004);
    InitWindow(window_width, window_height, "ANALOG CLOCK");
    SetTargetFPS(60); 
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        Vector2 vec={GetScreenWidth()/2,GetScreenHeight()/2};
        Vector2 vec_rec_origin1={0,10};
        Vector2 vec_rec_origin2={0,15};
        Vector2 vec_rec_origin3={0,20};
        Vector2 vec_rec_origin4={0,5};
        Rectangle line1={vec.x,vec.y ,width1-(pixeloffset*5),thickness*2};
        Rectangle line2={vec.x, vec.y,width1-(pixeloffset),thickness*3};
        Rectangle line3={vec.x, vec.y,width1-(pixeloffset*4), thickness*4};
        Rectangle line4={vec.x, vec.y,width1, 9};
        int rotatel= -90+sec()*6;
        int rotate2=-90+min()*6;
        int rotate3=-90+hour()*30;
        DrawRing(vec,width1, width2,0, 360, 2,color_ring);
        for(int i=1;i<=360;i++){
            if(i%2==0)line4.width=0;
            else line4.width=width1-10;
            DrawRectanglePro(line4, vec_rec_origin4,i*1, color_ring);}
        DrawRectanglePro(line1, vec_rec_origin1, rotatel,second); 
        DrawRectanglePro(line2,vec_rec_origin2, rotate2, minute);
        DrawRectanglePro(line3, vec_rec_origin3,rotate3, hours);
        DrawCircle(vec.x, vec.y, thickness*4, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}