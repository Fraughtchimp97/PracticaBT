#include "BluetoothSerial.h" 
BluetoothSerial ESP_BT;

void setup() {
  ESP_BT.begin("ESP_SEXO"); 
  Serial.begin(115000); 
}

#define SAMPLES 300
uint16_t val[SAMPLES];

void loop() {

  for(int i=1;i<=SAMPLES;i++)
  {
    val[i] = analogRead(35);

    ESP_BT.write(i);
    ESP_BT.write(val[i] & 0xFF);
    ESP_BT.write((val[i] >> 8) & 0xFF);
  }

  

}
