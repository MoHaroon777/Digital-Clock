void printTime(){
  //I could also print the Time one line but I'll have to parse all the values to string.
  //for example:  println(String(hMSD)+String(hLSD)+":"+String(mMSD)+String(mLSD)+":"+String(sMSD)+":"+String(sLSD));
  //But if you do Println(hMSD+hLSD+":"+mMSD+mLSD+":"+sMSD+sLSD);
  //This method does not work because you are adding the actual values the variables are holding.
    Serial.print(hMSD);
    Serial.print(hLSD);
    Serial.print(':');
    Serial.print(mMSD);
    Serial.print(mLSD);
    Serial.print(':');
    Serial.print(sMSD);
    Serial.println(sLSD);
}
