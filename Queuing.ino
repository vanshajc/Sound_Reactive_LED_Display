#include <QueueList.h>

/**
 * fucntions to extract characters from string and add to queue
 */

 QueueList<String> nextColumnQueue;
 String straightLine = "001111100";
 String oneTopOneBottom = "001000100";
 

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
    nextColumnQueue.push(straightLine);
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
    
}

