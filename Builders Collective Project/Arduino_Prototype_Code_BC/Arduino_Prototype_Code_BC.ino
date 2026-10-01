const int moistureSensor = A0; //getting readings from moisture sensor (plugged into A0 on Arduino)


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); //Initializing serial communication from Arduino to computer
  //Serial.println("Soil Moisture Sensor Initialized"); //Just stating that moisture sensor from the arduino is initialized; dont really need this so just commenting it out for now. Will probably delete anyways

}




void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogRead(moistureSensor); //reading the values from the moisture sensor

  int moisturePercent = map(sensorValue, 690, 592, 0, 100);  //Converting moisture readings into percents;      Wet readings is 592...  Dry readings is about 690...
  moisturePercent = constrain(moisturePercent, 0, 100); //making sure percents stay between 0 and 100


  Serial.print("Moisture Raw Value: ");
  Serial.println(sensorValue); //prints sensor value before converting to percent
  Serial.print("Moisture of plant: ");
  Serial.print(moisturePercent); //print sensor value after converting to percent
  Serial.println("%");


  delay(3000); //3 second delay
}
