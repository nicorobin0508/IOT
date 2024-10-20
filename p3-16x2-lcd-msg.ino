#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
char gpsString[] = "$GPGGA,134658.00,5106.9792,N,11402.3003,W,2,09,1.0,1048.47,M,-16.27,M,08,AAAA*60";
String latitude = "No Range";
String longitude = "No Range";
boolean gps_status = false;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Vehicle Tracking");
  lcd.setCursor(0, 1);
  lcd.print("System");
  delay(4000);
  lcd.clear();
  delay(2000);
}

void loop() {
  get_gps();
}

void get_gps() {
  gps_status = false;
  int x = 0;
  int comma = 0;

  // Clear previous values
  latitude = "No Range";
  longitude = "No Range";

  while (!gps_status) {
    while (x < strlen(gpsString)) {
      if (gpsString[x] == ',') {
        comma++;
      }

      if (comma == 2) { // Extract latitude
        int start = x + 1; // Start after the comma
        while (gpsString[x] != ',' && x < strlen(gpsString)) {
          latitude += gpsString[x];
          x++;
        }
      } 
      else if (comma == 4) { // Extract longitude
        int start = x + 1; // Start after the comma
        while (gpsString[x] != ',' && x < strlen(gpsString)) {
          longitude += gpsString[x];
          x++;
        }
      }
      x++;
    }

    // Trim trailing spaces (if necessary)
    latitude.trim();
    longitude.trim();

    // Update LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Lat: ");
    lcd.print(latitude);
    lcd.setCursor(0, 1);
    lcd.print("Long: ");
    lcd.print(longitude);

    // Print to Serial
    Serial.print("Lat: ");
    Serial.print(latitude);
    Serial.print("\tLong: ");
    Serial.println(longitude);

    gps_status = true; // Set to true to exit the loop after one complete read
    delay(2000);
  }
}
