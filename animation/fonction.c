#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <math.h>
#include "fonction.h"

void animed (SDL_Rect animepos[],int *frame)
{
if(*frame<4)
*frame=3;
(*frame)++;


if(*frame>7)
*frame=4;


}
 
void animeg (SDL_Rect animepos[],int *frame)
{
if (*frame>=4)
*frame=-1;
(*frame)++;
if (*frame==2)
*frame=3;


if(*frame>3)
*frame=0;
}
void initializeHero(Hero* hero)
{
	SDL_Surface* tmp  ;
         tmp = IMG_Load("anim.png");
	hero->image = tmp;


	SDL_Rect pos;
	pos.x=0;
	pos.y=265;
	hero->positionimage=pos;
	hero->score=0;
	hero->vies=10;
}
Uint32 getpixel(SDL_Surface *collision, int X, int Y)
		{
		    int bpp = collision->format->BytesPerPixel;
		    	
		    Uint8 *p = (Uint8 *)collision->pixels + Y * collision->pitch + X * bpp;
		 
		    switch(bpp) 
                    {
		    case 1:
			return *p;
			break;
		 
		    case 2:
			return *(Uint16 *)p;
			break;
		 
		    case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			    return p[0] << 16 | p[1] << 8 | p[2];
			else
			    return p[0] | p[1] << 8 | p[2] << 16;
			break;
		 
		    case 4:
			return *(Uint32 *)p;
			break;
		 
		    default:
			return 0;       
		    }
		 }
void jump(Hero *h,SDL_Surface* bg,SDL_Surface* screen,SDL_Surface* bg1,SDL_Rect pos)
{	
    SDL_Rect posMarioRel,posMarioAbs,animepos;
    posMarioRel.x = -50;
    posMarioRel.y = 0;
	int t=0;
	int i=0;
	Uint8 r,g,bl;

	int endjump=1;
      animepos.x=0;
animepos.x=661;
animepos.y=0;
animepos.w=109;
animepos.h=180;
           int x;
	   int y;
            posMarioAbs.x = h->positionimage.x;
            posMarioAbs.y = h->positionimage.y-(h->image->h);
	
		  
		while(endjump){
		
            posMarioRel.x++;

            if(posMarioRel.x>=100)
            {
                posMarioRel.x=-50;
            }

            //On met à "0" les pos abs:

            //On calcule la valeur relative de y:
            posMarioRel.y=(-0.04*(posMarioRel.x*posMarioRel.x)+100);

            //On calcule maintenant les valeurs abs
            h->positionimage.x = posMarioAbs.x + posMarioRel.x+50;
            h->positionimage.y = posMarioAbs.y - posMarioRel.y+29;
	 
		//printf("////////////////////////////////////////%d \n///////////////////////////////",h.poshero.y);

        //Intervalle de 10ms
        SDL_Delay(1);
	  // if(posMarioRel.x ==99)
	    // endjump=0;
		      //SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // On dessine les images aux positions respectives
     
		SDL_BlitSurface(bg1,NULL,screen,&pos);
	x=h->positionimage.y+182;
			
			SDL_GetRGB(getpixel(screen,h->positionimage.y,x),bg1->format,&r,&g,&bl);
			
			/*printf("\n xh :%d\n",p.position.x);
			printf("yh :%d\n",p.position.y);
			printf("yh+wh :%d\n",x);
			
			printf(" r=%d : g=%d : b=%d\n",r,g,bl );*/
			if(((r==255)&&(g==255)&&(bl==255))||((r==255)&&(g==255)&&(bl==255)))
				i++;
			
	    		 if((i>=2))
			{
			printf("ASSSBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA %d i",i);
			endjump=0;
h->positionimage.y-=5;
			}
SDL_BlitSurface(bg,NULL,screen,&pos);
//SDL_BlitSurface(en1,NULL,screen,pos);
	/*if (camera.x==1000)
		{
		SDL_BlitSurface(en1,NULL,screen,pos);
		pos->x--;
		}*/
		

        SDL_BlitSurface(h->image,&animepos,screen, &h->positionimage);
	
	

        // FIN DESSIN

        // Et on oublie pas de rafraichir l'image !
       SDL_Flip(screen);
	

	}



endjump=1;
        


}
Vecteur InitVecteur(int angle, int distance)
{
     Vecteur vecteur;
     int a,b;

     // il faut faire attention le résultat est en radian donc il faut le metre en degrés 
     vecteur.x = distance*cos(angle/180*3.14);
     vecteur.y = distance*sin(angle/180*3.14);
     return vecteur;
}
