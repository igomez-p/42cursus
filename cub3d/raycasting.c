#include "cub.h"
#include "libft/libft.h"
#include <math.h>


#define WIDTH_SCREEN   640
#define HEIGHT_SCREEN  360

// floats
#define FOV            radians(64)
#define PASO           0.01

float altura_anterior = 0;
float nTecho_anterior = 0;
float nSuelo_anterior = 0;

//Propiedades del jugador:
float xJugador = 2.0; //Posicion X
float yJugador = 2.0; //Posicion Y
float aJugador = 0.0; //Rotación (ángulo hacia dónde está apuntando)
float velocidad = 0.004; //Velocidad de movimiento
float giro = 0.002; //Velocidad de giro

//Variables para calcular el delta time:
float lastTime = 0;
float delta = 0;

int mapaColum = 0;
int mapaFilas = 0;

void lanzarRayos(t_cub *cub)
{
    void draw()
    {
        //Calculamos el delta time:
        delta = millis() - lastTime;
        
        //Pintar el cielo y el suelo:
      //  noStroke();
        fill(30);
        rect(0,0,WIDTH_SCREEN, HEIGHT_SCREEN/2); //Cielo
        fill(120);
        rect(0,HEIGHT_SCREEN/2,WIDTH_SCREEN, HEIGHT_SCREEN/2); //Suelo
        int x = 0, y = 0;
        while (x < WIDTH_SCREEN)
        {
            //La posición inicial del rayo será la del jugador:
            float xRayo = xJugador;
            float yRayo = yJugador;
            
            //Calculamos su ángulo inicial:
            float aRayo = (aJugador - FOV / 2.0) + x*(FOV / WIDTH_SCREEN);

            //Calculamos el incremento:
            float xIncremento = cos(aRayo)*PASO;
            float yIncremento = sin(aRayo)*PASO;

            //Calcular la trayectoria del rayo, paso a paso:
            int choque = 0;
            while(!choque)
            {
                //Calcular un nuevo punto de la trayectoria:
                xRayo += xIncremento;
                yRayo += yIncremento;
                
                //Si el rayo sale del mapa, o si colisiona con un muro, salimos del bucle while:
                if( xRayo < 0 || xRayo >= mapaColum || yRayo < 0 || yRayo >= mapaFilas || cub->map[(int)yRayo][(int)xRayo] != VACIO)
                {
                    choque = 1;
                }
            }

            //Calcular la distancia corregida del jugador al punto de colisión:
            float distancia = sqrt( pow(xRayo - xJugador, 2) + pow(yRayo - yJugador, 2) );
            distancia = distancia * cos(aRayo - aJugador);
            
            //Calcular la altura del muro:
            float altura = min(HEIGHT_SCREEN, HEIGHT_SCREEN / distancia);

            //Calcular el píxel de la pantalla donde hay que empezar a dibujar el muro (nTecho) y donde hay que acabar (nSuelo)
            int nTecho = (int)((float)HEIGHT_SCREEN / 2.0 - altura/2);
            int nSuelo = (int)((float)HEIGHT_SCREEN / 2.0 + altura/2);

            //Calcular una tonalidad para la columna, que dependerá de la distancia (cuanto más lejos, más oscuro)
            float tonalidad = map(min(distancia, 7), 0, 7, 255, 40);
         //   stroke(int(tonalidad));
            
            //Dibujar la línea vertical:
            line(x, nTecho, x, nSuelo);

            //Comprobar si hay que dibujar un borde lateral:
            if( abs(altura - altura_anterior) >= 10)
            {
           //     stroke(0);
            //    strokeWeight(2);
                if(altura > altura_anterior)
                    line(x, nTecho, x, nSuelo);
                else
                    line(x-1, nTecho_anterior, x-1, nSuelo_anterior);
            }
            
            //Guardar los parámetros de la columna actual:
            altura_anterior = altura;
            nTecho_anterior = nTecho;
            nSuelo_anterior = nSuelo;

            // DRAW bordes

            x++;
        }
    }
}