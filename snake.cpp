#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];
int ntail = 0;
enum eDirections {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirections dir;

int _kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
void setup(){
  gameOver = false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  foodX = rand() % width;
  foodY = rand() % height;
  score = 0;
}
void draw(){
  system("clear");
  for(int i = 0; i < width + 2; i++){
    printf("#");
  }
  printf("\n");

  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      if(j == 0){
        printf("#");
      }
      if(i == y && j == x){
        printf("0");
      }
      else if(i == foodY && j == foodX){
        printf("F");
      }
      else{
        bool tailDone = false;
        for(int k = 0; k < ntail; k++){
          if(tailX[k] == j && tailY[k] == i){
            printf("o");
            tailDone = true;
          }
        }
        if(!tailDone){
        printf(" ");
        }
      }
      if(j == width - 1){
        printf("#");
      }
    }
    printf("\n");
  }

   for(int i = 0; i < width + 2; i++){
    printf("#");
  }
  printf("\n");
  printf("score : %d", score);
}
void input(){

  if(_kbhit()){
    switch(getchar()){
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'x':
        gameOver = true;
        break;
    }
  }
}
void logic(){
  int prevX = tailX[0];
  int prevY = tailY[0];
  int prev2X, prev2Y;
  tailX[0] = x;
  tailY[0] = y;
 
   
  for(int i = 1; i < ntail; i++){
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
  switch(dir){
    case LEFT:
      x--;
      break;
    case RIGHT:
      x++;
      break;
    case UP:
      y--;
      break;
    case DOWN:
      y++;
      break;
    default:
      break;
  }
  if(x > width) x = 0;else if (x < 0) x = width - 1;
  if(y > height) y = 0;else if (y < 0) y = height - 1;
  for(int i = 0; i < ntail; i++){
    if(tailX[i] == x && tailY[i] == y){
      printf("\nGAME OVER!");
      gameOver = true;
    }
  }
  if(x == foodX && y == foodY){
    
    score += 10;
    foodX = rand() % width;
  foodY = rand() % height;
  ntail++;
  }
}
int main(){
  setup();
  while(!gameOver){
    draw();
    input();
    logic();
   usleep(200000);
  }
  return 0;
}