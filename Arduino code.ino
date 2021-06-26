String text = "";
int pinCol[5] = {13,12,11,10,9};
int pinRow[5] = {3,4,5,6,7};

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);

  Serial.begin(9600);

}

void loop()
{


  if (Serial.available() > 0) {
    // read the incoming byte:
    text = Serial.readString();
  }
  if(text != "")
    turnLights(text);

}

void toIntArray(String neki, int array[][5])
{
  //int array[5][5];
  int row = 0;
  String number = "";
  for(int i = 0; i < neki.length(); i++){

    if(String(neki.charAt(i)) != "," ){
      number += String(neki.charAt(i));
    }

    if(String(neki.charAt(i)) == "," || i == neki.length()-1){
      number.trim();
      String bin = String(number.toInt(),BIN);

      while(bin.length() < 5){
        bin = "0" + bin;
      }

      for(int j = 0; j < 5; j++){
        array[row][j] = String(bin.charAt(j)).toInt();
      }
      row++;
      number = "";
    }
  }
  //return array;

}
void lowToAll(){
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);

  digitalWrite(7,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
}
void turnLights(String neki){
  int test[5][5];
  toIntArray(neki, test);

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(test[i][j] == 1){
        digitalWrite(pinRow[i],HIGH);
        digitalWrite(pinCol[j],HIGH);
      }

    }
    delay(6);
    lowToAll();
  }


}
