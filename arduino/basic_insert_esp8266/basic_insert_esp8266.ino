/*
  MySQL Connector/Arduino Example : connect by wifi

  This example demonstrates how to connect to a MySQL server from an
  Arduino using an Arduino-compatible Wifi shield. Note that "compatible"
  means it must conform to the Ethernet class library or be a derivative
  with the same classes and methods.
  
  For more information and documentation, visit the wiki:
  https://github.com/ChuckBell/MySQL_Connector_Arduino/wiki.

  INSTRUCTIONS FOR USE

  1) Change the address of the server to the IP address of the MySQL server
  2) Change the user and password to a valid MySQL user and password
  3) Change the SSID and pass to match your WiFi network
  4) Connect a USB cable to your Arduino
  5) Select the correct board and port
  6) Compile and upload the sketch to your Arduino
  7) Once uploaded, open Serial Monitor (use 115200 speed) and observe

  If you do not see messages indicating you have a connection, refer to the
  manual for troubleshooting tips. The most common issues are the server is
  not accessible from the network or the user name and password is incorrect.

  Created by: Dr. Charles A. Bell
*/
#include <ESP8266WiFi.h>           // Use this for WiFi instead of Ethernet.h
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include "DHT.h"

#define DHTPIN 5
#define typeDHT DHT11

DHT dht(DHTPIN, typeDHT);

IPAddress server_addr(172,16,0,12);  // IP of the MySQL *server* here
char user[] = "user1";              // MySQL user login username
char password[] = "1234";        // MySQL user login password

// Sample query
char INSERT_SQL[] = "INSERT INTO dht11.location1(Temperature, Humidity) VALUES (%d, %d)";
char query[128];

// WiFi card example
char ssid[] = "ipTimeA1_2G";         // your SSID
char pass[] = "raspberry";     // your SSID Password

WiFiClient client;                 // Use this for WiFi instead of EthernetClient
MySQL_Connection conn(&client);
MySQL_Cursor* cursor;

void setup()
{
  Serial.begin(115200);
  while (!Serial); // wait for serial port to connect. Needed for Leonardo only

  // Begin WiFi section
  Serial.printf("\nConnecting to %s", ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // print out info about the connection:
  Serial.println("\nConnected to network");
  Serial.print("My IP address is: ");
  Serial.println(WiFi.localIP());

  Serial.print("Connecting to SQL...  ");
  if (conn.connect(server_addr, 3306, user, password))
    Serial.println("OK.");
  else
    Serial.println("FAILED.");
  
  // create MySQL cursor object
  cursor = new MySQL_Cursor(&conn);
}

void loop()
{
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  int Temperature = int(t) % 100;
  int Humidity    = int(h) % 100;

  Serial.print(Temperature);  Serial.print("*C\t");
  Serial.print(Humidity);     Serial.print("%\n");
  
  sprintf(query, INSERT_SQL, Temperature, Humidity);
    
  if (conn.connected())
    cursor->execute(query);

  delay(5000);
}