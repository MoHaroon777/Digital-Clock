//Name:      Mohamud Haroon
//No.:       X00145689
//Revision:  1.1
//Title:   digital clock code
/*
   The Circuit
   ===========================================================================================================================================================
   MSP pins                 Connected to              Comment
   --------------------------------------------------------------
   01 - VCC                   3.3V                      Power Input pins
   02   P1_0                  Buzzer                    For audio output if desired
   03 - P1_1                  LED                       Flashes when Alarm is on
   04 - P1_2                  ---                       Not Connected
   05 - P1_3                  ---                       Not Connected
   06 - P1_4                  A0                        Connected to 74HCT238 Pin 1 for address selection
   07 - Pl_5                  A1                        Connected to 74HCT238 Pin 2 for address selection
   08 - P2_0                  A2                        Connected to 74HCT238 Pin 3 for address selection
   09 - P2_1                  E3                        Connected to 74HCT238 Pin 6. Used to for Latch displayed numbers on the LCD when pulled low
   10 - P2_2                  1Hz                       Output from 74HCT4020 Pin 2. Used for incrementing seconds. (Not used for this program)
   11 - P2_3                  D3                        Data input Pin for the LCD
   12 - P2_4                  D2                        Data input Pin for the LCD
   13 - P2_5                  D1                        Data input Pin for the LCD
   14 - P1_6                  D0                        Data input Pin for the LCD
   15 - P1_7                  ---                       Not Connected
   16 - RST                   RST                       Resets the MSP is turned LOW
   17 - TST                   TST
   18 - P2_7                  ---                       Not Connected
   19 - P2_6                  ---                       Not Connected
   20 - GND                   GND                       GND pin on the MSP

   ===========================================================================================================================================================
*/
#define Addr0 P1_4
#define Addr1 P1_5
#define Addr2 P2_0

#define E3 P2_1

#define D0 P1_6
#define D1 P2_5
#define D2 P2_4
#define D3 P2_3

int DG1;
int DG2;
int DG3;
int DG4;
int DG5;
int DG6;

int sec = 0;
int sLSD = 0;
int sMSD = 0;
int mins = 0;
int mLSD = 0;
int mMSD = 0;
int hrs = 0;
int hLSD = 0;
int hMSD = 0;
int lastTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  pinMode(Addr0, OUTPUT);
  pinMode(Addr1, OUTPUT);
  pinMode(Addr2, OUTPUT);

  pinMode(E3, OUTPUT);

}

void loop() {
  int timeNow = millis();   //Counting milli seconds

  if ((timeNow - lastTime) >= 1000) {
    lastTime = timeNow;
    if (sec >= 59) {
      sec = 0;
      mins++;
      if (mins >= 59) {
        mins = 0;
        hrs++;
        if (hrs >= 23) {
          sec = 0;
          mins = 0;
          hrs = 0;
          //timeNow = 0;
        }
      }
    }
    else sec++;

    printTime();

  }

  sLSD = sec % 10;
  sMSD = sec / 10;
  mLSD = mins % 10;
  mMSD = mins / 10;
  hLSD = hrs % 10;
  hMSD = hrs / 10;        //Converting digit of hrs mins and seconds to 6 digits


  DG6 = sLSD;
  DG5 = sMSD;
  DG4 = mLSD;
  DG3 = mMSD;
  DG2 = hLSD;
  DG1 = hMSD;

  digitalWrite(D0, bitRead(DG6, 0));
  digitalWrite(D1, bitRead(DG6, 1));
  digitalWrite(D2, bitRead(DG6, 2));
  digitalWrite(D3, bitRead(DG6, 3));

  digitalWrite(E3, HIGH);
  digitalWrite(Addr0, HIGH);
  digitalWrite(Addr1, LOW);
  digitalWrite(Addr2, HIGH);
  digitalWrite(E3, LOW);
  delay(50);

  digitalWrite(D0, bitRead(DG5, 0));
  digitalWrite(D1, bitRead(DG5, 1));
  digitalWrite(D2, bitRead(DG5, 2));
  digitalWrite(D3, bitRead(DG5, 3));

  digitalWrite(E3, HIGH);
  digitalWrite(Addr0, LOW);
  digitalWrite(Addr1, LOW);
  digitalWrite(Addr2, HIGH);
  digitalWrite(E3, LOW);
  delay(50);

  digitalWrite(D0, bitRead(DG4, 0));
  digitalWrite(D1, bitRead(DG4, 1));
  digitalWrite(D2, bitRead(DG4, 2));
  digitalWrite(D3, bitRead(DG4, 3));

  digitalWrite(E3, HIGH);
  digitalWrite(Addr0, HIGH);
  digitalWrite(Addr1, HIGH);
  digitalWrite(Addr2, LOW);
  digitalWrite(E3, LOW);
  delay(50);

  digitalWrite(D0, bitRead(DG3, 0));
  digitalWrite(D1, bitRead(DG3, 1));
  digitalWrite(D2, bitRead(DG3, 2));
  digitalWrite(D3, bitRead(DG3, 3));

  digitalWrite(E3, HIGH);
  digitalWrite(Addr0, LOW);
  digitalWrite(Addr1, HIGH);
  digitalWrite(Addr2, LOW);
  digitalWrite(E3, LOW);
  delay(50);

  digitalWrite(D0, bitRead(DG2, 0));
  digitalWrite(D1, bitRead(DG2, 1));
  digitalWrite(D2, bitRead(DG2, 2));
  digitalWrite(D3, bitRead(DG2, 3));

  digitalWrite(E3, HIGH);
  digitalWrite(Addr0, HIGH);
  digitalWrite(Addr1, LOW);
  digitalWrite(Addr2, LOW);
  digitalWrite(E3, LOW);
  delay(50);

  digitalWrite(D0, bitRead(DG1, 0));
  digitalWrite(D1, bitRead(DG1, 1));
  digitalWrite(D2, bitRead(DG1, 2));
  digitalWrite(D3, bitRead(DG1, 3));

  digitalWrite(E3, HIGH);
  digitalWrite(Addr0, LOW);
  digitalWrite(Addr1, LOW);
  digitalWrite(Addr2, LOW);
  digitalWrite(E3, LOW);
  delay(50);
}
