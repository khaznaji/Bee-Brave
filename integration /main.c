#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "fonction.h"
#include "enigme.h"
#include <time.h>
void pause()
{
    int continuer = 1;
    SDL_Event event;
 
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main (void)
{
SDL_Surface *screen =NULL,*enigme=NULL;
SDL_Init(SDL_INIT_VIDEO);
SDL_EnableKeyRepeat(10,40);
int continuer=1;
screen = SDL_SetVideoMode(1500,480,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
SDL_Surface *fond=NULL/*,*image=NULL*/,*vies=NULL,*score=NULL;
SDL_Rect positionfond;
SDL_Rect posvies;
SDL_Rect posscore;
SDL_Rect positionenigme;
//SDL_Rect positionimage;
SDL_Rect animepos[8];
SDL_Event event;
int frame=4;
Hero hero;
initializeHero(&hero);
enigme = IMG_Load("enigme-box.jpg");
positionenigme.x=900;
positionenigme.y=370;
animepos[0].x=0;
animepos[0].y=0;
animepos[0].w=128;
animepos[0].h=180;

animepos[1].x=128;
animepos[1].y=0;
animepos[1].w=109;
animepos[1].h=180;

animepos[2].x=237;
animepos[2].y=0;
animepos[2].w=167;
animepos[2].h=180;

animepos[3].x=404;
animepos[3].y=0;
animepos[3].w=130;
animepos[3].h=180;

animepos[4].x=534;
animepos[4].y=0;
animepos[4].w=127;
animepos[4].h=180;

animepos[5].x=661;
animepos[5].y=0;
animepos[5].w=109;
animepos[5].h=180;

animepos[6].x=770;
animepos[6].y=0; 
animepos[6].w=167;
animepos[6].h=180;

animepos[7].x=937;
animepos[7].y=0;
animepos[7].w=129;
animepos[7].h=180;



positionfond.x=0;
positionfond.y=0;
fond= IMG_Load("background.png");

//positionimage.x=0;
//positionimage.y=265;
//image=IMG_Load("anim.png");
vies=IMG_Load("vies.png");
score=IMG_Load("score.png");
posvies.x=0;
posvies.y=0;

posscore.x=1250;
posscore.y=0;

/*SDL_BlitSurface(fond,NULL,screen, &positionfond);
SDL_Flip(screen);
SDL_BlitSurface(vies,NULL,screen, &posvies);
SDL_BlitSurface(score,NULL,screen, &score);
SDL_BlitSurface(hero.image,&animepos[frame],screen,&hero.positionimage);

SDL_Flip(screen);*/
int enigmevalid=1;

while (continuer == 1)
    {

if((hero.positionimage.x==900)&&(enigmevalid==1))
enigmevalid=menigme(screen);
        SDL_PollEvent(&event);
        switch(event.type)
        {



            case SDL_QUIT:
                continuer = 0;

SDL_Quit();
                break;
	    case SDL_MOUSEMOTION: 
			
                        break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {   
		    case SDLK_ESCAPE:
			continuer=0;
			break; 
		    case SDLK_UP: 

 break;
                   
                    case SDLK_RIGHT:





                             animed(animepos,&frame);
//positionimage.x+=20;
hero.positionimage.x+=20;


		    break;

                    case SDLK_LEFT: 

 
animeg(animepos,&frame);
			
//positionimage.x-=20;
hero.positionimage.x-=20;


                        break;
		    
                }
               

               
}


SDL_BlitSurface(fond,NULL,screen, &positionfond);
SDL_BlitSurface(vies,NULL,screen, &posvies);
SDL_BlitSurface(enigme,NULL,screen,&positionenigme); 
SDL_BlitSurface(score,NULL,screen, &posscore);
SDL_BlitSurface(hero.image,&animepos[frame],screen,&hero.positionimage);

SDL_Flip(screen);

}

}

