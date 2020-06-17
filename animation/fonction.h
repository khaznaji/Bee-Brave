typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *image;

SDL_Rect positionimage;

float score ; 
float vies ; 

};
typedef struct 
{
     int x;
     int y;
}Vecteur;

void animed (SDL_Rect animepos[],int *frame);
void animeg (SDL_Rect animepos[],int *frame);
void initializeHero(Hero* hero);
void jump(Hero *p,SDL_Surface* bg,SDL_Surface* screen,SDL_Surface* bg1,SDL_Rect pos);
Uint32 getpixel(SDL_Surface *collision, int X, int Y);
Vecteur InitVecteur(int angle, int distance);
