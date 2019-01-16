
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

// the value of the 'other' resistor
#define SERIESRESISTOR 10000    
 
// What pin to connect the sensor to
#define THERMISTORPIN A0 

///Thermistor Constants
const double VCC = 3.3;             // NodeMCU on board 3.3v vcc
const double R2 = 10000;            // 10k ohm series resistor
const double adc_resolution = 1023; // 10-bit adc

const double A = 0.001129148;   // thermistor equation parameters
const double B = 0.000234125;
const double C = 0.0000000876741; 

const char* ssid = "WLAN-FB" ;
const char* pw   = "*pass123";


void setup()
{

  wifiConnection();
  
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D5, OUTPUT);

  //pinMode(A0, INPUT);

  Serial.begin(9600);
}

void loop()
{
  wifiConnection();
  //Serial.print("LUX: ");
  Serial.println(readPhoto());
  Serial.println(readTemp());
  sendToApi(readPhoto(),readTemp());
  delay(1000);

}

void sendToApi(float light, int temp)
{
  StaticJsonBuffer<300> JSONbuffer;
  JsonObject& JSONencoder = JSONbuffer.createObject();
  
  JSONencoder["IP"] = WiFi.localIP().toString();
  JSONencoder["Temp"] = String(temp);
  JSONencoder["Light"] = String(light);

  char JSONmessageBuffer[300];
  JSONencoder.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  //Serial.println(JSONmessageBuffer);
  
  HTTPClient http; //Declare object of class HTTPClient
  http.begin("http://192.168.178.30:5000/api/nodemcu"); //Specify request destination
  http.addHeader("Content-Type", "application/json"); //Specify content-type header
  
  int httpCode = http.POST(JSONmessageBuffer); //Send the request
  String payload = http.getString(); //Get the response payload
  http.end(); //Close connection
}
void wifiConnection()
{
  // connect to wifi
  WiFi.begin(ssid, pw);
  Serial.println();
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("success!");
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP());
}

float readPhoto()
{
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D5, LOW);

  int sensorValue = analogRead(A0);
  return sensorValue;

}

int readTemp()
{
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D5, LOW);

  double Vout, Rth, temperature, adc_value;

  adc_value = analogRead(A0);
  Vout = (adc_value * VCC) / adc_resolution;
  Rth = (VCC * R2 / Vout) - R2;

  temperature = (1 / (A + (B * log(Rth)) + (C * pow((log(Rth)),3))));   // Temperature in kelvin

  temperature = temperature - 273.15;  // Temperature in degree celsius
  return temperature;
  
  delay(500);

}
