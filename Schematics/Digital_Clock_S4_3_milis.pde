int sl = 0;
int sm = 0;
int ml = 0;
int mm = 0;
int hl = 0;
int hm = 0;
int lastTime = 0;

void setup() {
  size(400, 180);      
  background(180, 180, 180);
}
void draw() {
  int timeNow = millis();        //count the milli seconds on the operating system and store it veriable timeNow 
  if ((timeNow - lastTime) > 1000) {  //if the difference between timeNow and LastTime is 1000 milli seconds
    lastTime = timeNow;               //store the timeNow to LastTime. The difference between timeNow and LastTime is 1000, do the following
    //Seconds
    if (sl == 9) {         //if sLSD (seconds, least significant decimal) is equal to 9
      sl = 0;              //reset sLSD to 0.
      if (sm == 5) {       //if sMSD (seconds, most significant decimal) is equal to 5,
        sm = 0;            //reset sMSD to 0.
        ml++;              //and increment mLSD (minutes, least significant decimal)
      } else sm++;         //if sMSD is not equal to 5, then increment
    } else sl++;           //if sLSD is not equal to 9, then increment
    //Minutes
    if (ml == 9) {         //if mLSD is equal to 9,
      ml = 0;              // reset mLSD to 0.
      mm++;                //and increment mMSD (minutes, most significant decimal)
      if (mm == 5) {       //if mMSD is equal to 5,
        mm = 0;            //reset mMSD to 0
        hl++;              //and increment hLSD (hours, least significant decimal)
      } else mm++;         //if mMSD is not equal to 0, then increment
    } 
    //Hours
    if (hl == 9) {         //if hLSD is equal to 9,
      hl  = 0;             //reset hLSD to 0
      hm++;                //and increment hMSD (hours, most significant decimal)
      if (hm == 2) {       //if hMSD is equal to 2,
        hm = 0;            //reset hMSD to 0.
        if (hm == 2 && hl == 3) {  //if hours is 23 then reset hours to 0
          hl = 0;
          hm = 0;
        }
      }else hm++;         //if hMSD is not equal to 2, then increment
    }
    println(hm+hl+":"+mm+ml+":"+sm+sl);  //print time on the console
  }
}
