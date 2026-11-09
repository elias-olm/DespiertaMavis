#ifndef NDEBUG
#include <vld.h> // Visual Leak Detector
#endif
#include "raylib.h"

int main(void)
{
    // Inicializacion
    InitWindow(1080, 720, "Despierta Scizor");
    SetTargetFPS(60);


    // Carga
    Texture2D scizor = LoadTexture("sprite.png");
    Vector2 posInicial = { 540,560 };
    bool mostrarInfo = true;
    Color colorFondo = DARKGRAY;
    Vector2 posMouse = GetMousePosition(); 
    Color colorMouse = YELLOW;
    bool chequeoColor1 = true;
    bool chequeoColor2 = true;

    // Bucle principal
    while (!WindowShouldClose())
    {
        // Actualizacion
        posMouse = GetMousePosition();
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
            posInicial.x+=5;
        }

        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
            posInicial.x -= 5;
        }

        if (IsKeyPressed(KEY_SPACE)) {
         posInicial.y -= 30;
        }
        
        if (IsKeyPressed(KEY_R)) {
            posInicial.x = 540;
            posInicial.y = 560;
        }

        if (IsKeyPressed(KEY_M)) {
        mostrarInfo=!mostrarInfo;
        }

        if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
            chequeoColor1=!chequeoColor1;
            if (chequeoColor1) {
                colorMouse=RED;
            }
            else
            {
                colorMouse=YELLOW;
            }
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && (posMouse.x>520 && posMouse.x<560) && (posMouse.y > 180 && posMouse.y < 220)) {
            
            chequeoColor2 = !chequeoColor2;
            if (chequeoColor2) {
                colorFondo = LIGHTGRAY;
            }
            else
            {
                colorFondo = DARKGRAY;
            }
        }







        if (posInicial.x >945) {
            posInicial.x = 945;
       }

        if (posInicial.x <0) {
            posInicial.x= 0;
        }

        if (posInicial.y < 0) {
            posInicial.y = 0;
        }


        // Dibujado
        BeginDrawing();
        ClearBackground(colorFondo);
        DrawCircle(540, 200, 20, MAGENTA);
        DrawTextureEx(scizor, posInicial, 0, 0.25, WHITE);
        if (mostrarInfo){
            DrawText("Pulsa R para resetear posicion - Click derecho para cambiar de color de letras - Pulsa click en el circulo para cambiar de color el fondo - Pulsa M para ocultar info",0,0,12,colorMouse);
        }
        DrawText("Posicion del personaje: ", 10, 680, 10, colorMouse);
        DrawText(TextFormat("X:%.2f",posInicial.x),10,700,10,colorMouse);
        DrawText(TextFormat("Y:%.2f", posInicial.y),60, 700, 10, colorMouse);
        EndDrawing();


    }

    // Descarga




    // Cierre
    CloseWindow();

    return 0;
}
