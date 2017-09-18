 
 import processing.serial.*;
  Serial port;
  PImage img;
  int ang=15;
  
  void setup() {
  size(313,240);
  img = loadImage("CATAPULT.jpg"); 

  port = new Serial(this,"COM3", 9600);
  }
void draw() {
 image(img, 0, 0);
 
  if (mouseX >75 && mouseX <125 && mouseY >112 && mouseY <160)
  {
   
   ellipse(mouseX,mouseY, 25, 25);
   
  if(mousePressed)
       ang=5;
  
 } 
 else if (mouseX >162 && mouseX <209 && mouseY >112 && mouseY <164)
  {
  ellipse(mouseX,mouseY, 25, 25);
  if(mousePressed)
    
    ang=10;
    
  } else if (mouseX >85 && mouseX <210 && mouseY >185 && mouseY <235)
  {
  ellipse(mouseX,mouseY, 25, 25);
  if(mousePressed)
   ang=20;
   
    
  }
  
  else 
    ang=15;
 port.write(ang);
}