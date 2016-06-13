float x = 0;
float y = 0;

void setup() {

 background(0);
 size(1248,724);
 

 frameRate(100);

}

void draw() {
  
 
  background(0);
  stroke(255, 0, 0);
   strokeWeight(2);
  line(x, 0, x, height);
  x = x+1;
   if (x > width) {
     x = 0; }
     
   
      
    stroke(255);
     strokeWeight(20);
   line((y+10), 0, (y+10), height);
  y = y+4;
   if (y > width) {
     y = 0; }
     
    //    filter(BLUR, 4);
       

}
  