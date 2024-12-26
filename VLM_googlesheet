#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#define RST_PIN  D3
#define SS_PIN   D4
#define BUZZER   D2
int blockNum = 2;  
byte bufferLen = 18;
byte readBlockData[18];
String card_holder_name;
const String sheet_url = "https://script.google.com/macros/s/AKfycbyr8g1qHVxfMUz1h2mXK0V0NbJeEuakv2khPJ9uzxf5feT4DxcTEwWTYhvbnpSqz3ZI/exec";
#define WIFI_SSID "MEENLAPTOP 7965"
#define WIFI_PASSWORD "9173111523"
String Status_Read_Sensor = "";

int Floor,Side=0;
String Switch_1_State = "";
String Switch_2_State = "";
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  
  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
void toget(int togofloor,int flr,String operation="")
{
  int u,previousTime,currentTime;
  signed char difference;
  difference=flr-togofloor;
  difference=togofloor-flr;
  if(difference==0) return;
  if(difference>0)/*add to choose cloumn*/
    {
      u=1;
    //up();
    }
  else if(difference<0)
    {u=0;
    difference=~difference;
      difference=difference+1;
    //down();
    }
    previousTime=millis();
  if(operation!="") readurl(operation);
  Serial.println(operation);
  currentTime=millis();
  int tcut;
  tcut=int(currentTime-previousTime);
  //Serial.print(tcut);Serial.println("WRITE");
  Serial.println(difference);
      /*PORTA=difference;*/
  delay((10000*difference)-tcut);/*delay floor*/
    /*P3=flr;*/
        }
void readurl(String sts)
{
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);
    client->setInsecure();
    String Read_Data_URL;
    Read_Data_URL = sheet_url + String(sts);
    //&humd=95&swtc1=Off&swtc2=Off");
    
    card_holder_name.trim();
    //Serial.println(Read_Data_URL);
    HTTPClient http;
    //Serial.print(F("[HTTPS] begin...\n"));
    if (http.begin(*client, (String)Read_Data_URL)){
      //Serial.print(F("[HTTPS] GET...\n"));
      http.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
      int httpCode = http.GET();
      if (httpCode > 0) {
        //Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
      
        String payload;
        payload = http.getString();
          
      //Status_Read_Sensor = getValue(payload, ',', 0);
      if(sts=="?sts=read"){Floor = getValue(payload, ',', 1).toInt();
      Side = getValue(payload, ',', 2).toInt();}
      }
      else 
      {Serial.printf("[HTTPS] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());}

    }
    else {
      Serial.printf("[HTTPS} Unable to connect\n");
    }
  }

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to AP");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  /*while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();*/
}
unsigned long currentTime;
unsigned long previousTime = 0;
int seven_seg[] = {4, 5, 13, 15, 3, 0, 14, 12};
int num_array[10][7] = {{ 1, 1, 1, 1, 1, 1, 0 },  // 0
                        { 0, 1, 1, 0, 0, 0, 0 },  // 1
                        { 1, 1, 0, 1, 1, 0, 1 },  // 2
                        { 1, 1, 1, 1, 0, 0, 1 },  // 3
                        { 0, 1, 1, 0, 0, 1, 1 },  // 4
                        { 1, 0, 1, 1, 0, 1, 1 },  // 5
                        { 1, 0, 1, 1, 1, 1, 1 },  // 6
                        { 1, 1, 1, 0, 0, 0, 0 },  // 7
                        { 1, 1, 1, 1, 1, 1, 1 },  // 8
                        { 1, 1, 1, 1, 0, 1, 1 }}; // 9
void printNumber(int number) {
  for (int i = 0; i <= 8; i++) {
    pinMode(seven_seg[i], OUTPUT);
  }
  int pin;
  for (int j = 0; j < 7; j++) {
    pin = seven_seg[j];
    digitalWrite(pin,num_array[number][j]);
    digitalWrite(pin,num_array[number][j]);
  }
 
}

int CFloor=5;
 void loop()
{
  
  if (WiFi.status() == WL_CONNECTED) {
    pinMode(2,OUTPUT);digitalWrite(2,LOW);delay(250);digitalWrite(2,HIGH);delay(750);
    
    printNumber(CFloor);
    if(Floor==0){previousTime=millis(); readurl("?sts=read");currentTime=millis();Serial.print(int(currentTime-previousTime));Serial.println("read");}
    if(Floor!=0 && Floor!=5)
    {
      digitalWrite(2,LOW);
      Serial.print(Floor);
      Serial.print(Side);
      Serial.println("out");
      printNumber(CFloor);
      /*VLM ACTUAL get*/
      toget(Floor,CFloor,"?sts=write2"); 
      // if(Side==0)rear();
      //else  front();
      //delay(5000);/*delay for rear front*/
      //if(Side==0)front();
      //else  rear();
      //delay(5000);
      CFloor=Floor;
      printNumber(CFloor);
      Serial.print(Floor);
      Serial.print(Side);
      Serial.println("2");
      toget(5,Floor);//error from 0
      CFloor=5;
      printNumber(CFloor);
      Serial.print("done ");
      //delay(20000);//stay back time or switch 
      //front();
      //delay(8000);//delay to stay at zero
      //rear();
      //delay(5000);
      CFloor=Floor;   
      toget(Floor,5,"?sts=read");//error from 0
      printNumber(CFloor);
      // if(Side==0)rear();
      //else  front();
      //delay(5000);/*delay for rear front*/
      //if(Side==0)front();
      //else  rear();
      //delay(5000);      
      
    }
    }
    else{pinMode(2,OUTPUT);digitalWrite(2,LOW);delay(500);digitalWrite(2,HIGH);delay(500);}
}



void store(){currentTime = millis();
      readurl("?sts=read");
      previousTime = currentTime;
      Serial.print(int(currentTime-previousTime)/1000);Serial.println("read");}










/*<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Component Selector</title>
    <script>
        const countryNames = ["Inductor", "Resistor", "Capacitor", "Relay"];
        let submittedCountries = []; // Array to store all submitted countries

        // Function to populate the dropdown with all components initially
        function populateDropdown() {
            const dropdown = document.getElementById("countryDropdown");
            dropdown.innerHTML = ""; // Clear existing options

            countryNames.forEach(country => {
                const option = document.createElement("option");
                option.value = country;
                option.textContent = country;
                dropdown.appendChild(option);
            });
        }

        // Function to filter countries based on the input
        function filterCountries() {
            const input = document.getElementById("countryInput").value.toLowerCase();
            const filteredCountries = countryNames.filter(country => {
                return country.toLowerCase().includes(input);
            });

            const dropdown = document.getElementById("countryDropdown");
            dropdown.innerHTML = ""; // Clear existing options

            filteredCountries.forEach(country => {
                const option = document.createElement("option");
                option.value = country;
                option.textContent = country;
                dropdown.appendChild(option);
            });
        }

        // Function to handle submission of the selected country
        async function submitCountry() {
            const dropdown = document.getElementById("countryDropdown");
            const selectedCountry = dropdown.value;
            if (selectedCountry) {
                submittedCountries.unshift(selectedCountry); // Add to the beginning of the array
                const url = `https://script.google.com/macros/s/AKfycbxHHVUGKBjv3LO90oMTX_nzzNBmiM3206VQqCcv5A78UWNY5ZOmNMukwUhh-caI6LhZ/exec?sts=write&srs=${selectedCountry.toLowerCase()}`;

                try {
                    // Make the request in the background
                    await fetch(url);
                   
                    // Display all submitted countries with serial numbers from bottom to top
                    const message = submittedCountries.map((country, index) => `${submittedCountries.length - index}. ${country}`).join('<br>');
                    document.getElementById("submissionMessage").innerHTML = message;
                } catch (error) {
                    console.error("Error submitting the country:", error);
                    alert("An error occurred while submitting. Please try again.");
                }
            } else {
                alert("Please select a component.");
            }
        }

        // Populate dropdown on page load
        window.onload = populateDropdown;
    </script>
</head>
<body>
    <input type="text" id="countryInput" oninput="filterCountries()" placeholder="Type a component">
    <select id="countryDropdown"></select>
    <button onclick="submitCountry()">Submit</button>
    <div id="submissionMessage" style="margin-top: 10px; font-weight: bold;"></div> <!-- Message display area -->
</body>
</html>
*/
