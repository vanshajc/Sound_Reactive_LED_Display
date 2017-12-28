#include <QueueList.h>

/**
 * fucntions to extract characters from string and add to queue
 */

 QueueList<String> nextColumnQueue;
 String straightLine = "001111100";
 String oneTopOneBottom = "001000100";
 String oneTopOneMiddleOneBottom = "001010100";
 

void setup() {
  // put your setup code here, to run once:
  String s;
  for(int i = 0; i < s.length(); i++)
  {
    addToQueue(s.charAt(i));
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

void addToQueue(char letter)
{
  if(letter=='A')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("001010000");
    nextColumnQueue.push("001010000");
    nextColumnQueue.push(straightLine);
  }
  if(letter == 'B')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("001010100");
    nextColumnQueue.push("001010100");
    nextColumnQueue.push("000101000");
  }
  if(letter == 'C')
  {
    nextColumnQueue.push("000111000");
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(oneTopOneBottom);
  }
  if(letter == 'D')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push("000111000");
  }
  if(letter == 'E')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push(oneTopOneMiddleOneBottom);
    nextColumnQueue.push(oneTopOneMiddleOneBottom);
  }
  if(letter == 'F')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("001010000");
    nextColumnQueue.push("001010000");
    nextColumnQueue.push("001000000");
  }
  if(letter == 'G')
  {
    nextColumnQueue.push("000111000");
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(oneTopOneMiddleOneBottom);
    nextColumnQueue.push("001011100");
  }
  if(letter == 'H')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("000010000");
    nextColumnQueue.push("000010000");
    nextColumnQueue.push(straightLine);
  }
  if(letter == 'I')
  {
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push(oneTopOneBottom);
  }
  if(letter == 'J')
  {
    nextColumnQueue.push("001001100");
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("001000000");
  }
  if(letter == 'K')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("000010000");
    nextColumnQueue.push("000101000");
    nextColumnQueue.push(oneTopOneBottom);
  }
  if(letter == 'L')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("000000100");
    nextColumnQueue.push("000000100");
    nextColumnQueue.push("000000100");
  }
  if(letter = 'M')
  {
    nextColumnQueue.push(straightLine);
    nextColumnQueue.push("000100000");
    nextColumnQueue.push("000010000");
    nextColumnQueue.push("000100000");
    nextColumnQueue.push(straightLine);
  }
  if(letter == 'N')
  {
    nextColumnQueue.push("000111100");
    nextColumnQueue.push("001000000");
    nextColumnQueue.push("001000000");
    nextColumnQueue.push("000111100");
  }
  if(letter == 'O')
  {
    nextColumnQueue.push("000111000");
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push("000111000");
  }
  if(letter == 'P')
  {
    nextColumnQueue.push("000111100");
    nextColumnQueue.push("001010000");
    nextColumnQueue.push("001010000");
    nextColumnQueue.push("000100000");
  }
  if(letter == 'Q')
  {
    nextColumnQueue.push("000111000");
    nextColumnQueue.push(oneTopOneBottom);
    nextColumnQueue.push(oneTopOneMiddleOneBottom);
    nextColumnQueue.push("001001100");
    nextColumnQueue.push("000111100");
  }
}

