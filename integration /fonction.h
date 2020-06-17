typedef struct Hero Hero ;
struct Hero 
{

SDL_Surface *image;

SDL_Rect positionimage;

float score ; 
float vies ; 

};

void animed (SDL_Rect animepos[],int *frame);
void animeg (SDL_Rect animepos[],int *frame);
void initializeHero(Hero* hero);
