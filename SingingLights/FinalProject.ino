// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            7

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      81

#define NUM_ROWS 9
#define NUM_COLS 9

typedef struct {
  char r, g, b;
  int dir; // 0 = everywhere, 1 = right, -1 = left, 2 = up, -2 = down
} Point;

Point grid[NUM_ROWS][NUM_COLS];

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

unsigned long st = 0;
void setup() {
 Serial.begin(9600);


  pixels.begin(); // This initializes the NeoPixel library.
  initGrid();
 pinMode(7, OUTPUT);
 st = millis();
//
// grid[2][2] = newRipple(128, 0, 0, 0);
// stepGrid();
// lightGrid();
}
 
 
void loop() {
  int a = analogRead(A0);
  if (a - 350 > 0){
    Serial.println(a);
    //lightUp();
    //delay(100);
    //grid[5][5] = newRipple(128, 0, 0, 0);

    generateRipple();
    delay(20);
    //lightGrid();
    //st = millis();
  }


  if (millis() - st > 100){
    lightGrid();
    stepGrid();
    st = millis();
    
  }
  
  
}


void lightUp() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.
  }
  pixels.show();
}

void turnOff(){

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.

  }

  pixels.show();
}

void generateRipple(){
  int r = random(0, NUM_ROWS);
  int c = random(0, NUM_COLS);

  grid[r][c] = newRipple(random(0, 128), random(0, 128), random(0, 128), 0);
}

void lightGrid(){
  for (int i = 0; i < NUM_ROWS; i++){
    for (int j = 0; j < NUM_COLS; j++){

      if (i % 2 == 0){
        pixels.setPixelColor(NUM_ROWS*i + j, pixels.Color(grid[i][j].r, grid[i][j].g, grid[i][j].b));
      } else {
        pixels.setPixelColor(NUM_ROWS*(i + 1) - j - 1, pixels.Color(grid[i][j].r, grid[i][j].g, grid[i][j].b));
      }
    }
  }
  pixels.show();
}

Point newOff(){
  Point a;
  a.r = 0; a.g = 0; a.b = 0;
  a.dir = 9;
  return a;
}

Point newRipple(int r, int g, int b, int dir){
  Point a;
  a.r = r; a.g = g; a.b = b;
  a.dir = dir;
  return a;
}

Point copyRipple(Point p, int dir){
  Point a;
  a.r = p.r; a.g = p.g; a.b = p.b;
  a.dir = dir;
  return a;
}
Point nGrid[NUM_ROWS][NUM_COLS];

void stepGrid(){
  int i, j;
  
  for (i = 0; i < NUM_ROWS; i++){
    for (j = 0; j < NUM_COLS; j++){
      if (grid[i][j].dir == 0){
        Point nL = copyRipple(grid[i][j], -1);
        addToGrid(nL, i - 1, j);

        Point nR = copyRipple(grid[i][j], 1);
        addToGrid(nR, i + 1, j);

        Point nU = copyRipple(grid[i][j], 2);
        addToGrid(nU, i, j - 1);

        Point nD = copyRipple(grid[i][j], -2);
        addToGrid(nD, i, j + 1);

        nGrid[i][j] = newOff();
      }
      else if (grid[i][j].dir == -1){ // MOVE LEFT
        Point nL = copyRipple(grid[i][j], -1);
        addToGrid(nL, i - 1, j);

        nGrid[i][j] = newOff();
      }
      else if (grid[i][j].dir == 1){ // MOVE RIGHT
        Point nR = copyRipple(grid[i][j], 1);
        addToGrid(nR, i + 1, j);

        nGrid[i][j] = newOff();
      }
      else if (grid[i][j].dir == 2){ // MOVE UP
        Point nU = copyRipple(grid[i][j], 2);
        addToGrid(nU, i, j - 1);
        
        nGrid[i][j] = newOff();
      }
      else if (grid[i][j].dir == -2){ // MOVE DOWN
        Point nD = copyRipple(grid[i][j], -2);
        addToGrid(nD, i, j + 1);

        nGrid[i][j] = newOff();
      }
        
    }
  }
  copyGrid();
}

void copyGrid(){
  int i, j;
  for (i = 0; i < NUM_ROWS; i++){
    for (j = 0; j < NUM_COLS; j++){
      grid[i][j] = nGrid[i][j];
    }
  }
}

void addToGrid(Point p, int x, int y){
  if (x < 0 or y < 0 or x >= NUM_ROWS or y >= NUM_COLS){
    return;
  }
  nGrid[x][y] = p;
}

void initGrid(){
  int i, j;
  for (i = 0; i < NUM_ROWS; i++){
    for (j = 0; j < NUM_COLS; j++){
      grid[i][j] = newOff();
      nGrid[i][j] = newOff();
    }
  }
}

