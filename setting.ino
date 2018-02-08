#include <EEPROM.h>

/*  EEPROM layout for settings:
 *   
 *  uint64_t UUID
 *  uint16_t Name length (Max 100)
 *  String Name (Name length bytes)
 *  uint8_t Key length (Max 128)
 *  String Key (Key length bytes)
 *  double Min Voltage
 *  double Max Voltage
 */

 struct Settings {
  uint32_t uuid;
  char name[100];
  char key[100];
  double min_v;
  double max_v;
 };

 Settings settings;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  EEPROM.get(0, settings);
  print_info();
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {
    char arg_buf[100];
    size_t arg_len = Serial.readBytesUntil(' ', arg_buf, 100);

    if (arg_len > 0) {
      arg_buf[arg_len] = 0;
      
      char param_buf[100];
      size_t param_len = Serial.readBytesUntil('\n', param_buf, 100);

      if (param_len > 0) {
        param_buf[param_len] = 0;
        
        if (strcmp(arg_buf, "name") == 0) {
          Serial.print("Setting name to '");
          Serial.print(param_buf);
          Serial.println("'");
          
          strcpy(settings.name, param_buf);
          EEPROM.put(0, settings);
        } else if (strcmp(arg_buf, "uuid") == 0) {
          Serial.print("Setting uuid to '");
          Serial.print(param_buf);
          Serial.println("'");
          
          settings.uuid = atoi(param_buf);
          EEPROM.put(0, settings);
        } else if (strcmp(arg_buf, "key") == 0) {
          Serial.print("Setting key to '");
          Serial.print(param_buf);
          Serial.println("'");
          
          strcpy(settings.key, param_buf);
          EEPROM.put(0, settings);
        } else if (strcmp(arg_buf, "vmin") == 0) {
          Serial.print("Setting min voltage to '");
          Serial.print(param_buf);
          Serial.println("'");
          
          settings.min_v = atof(param_buf);
          EEPROM.put(0, settings);
        } else if (strcmp(arg_buf, "vmax") == 0) {
          Serial.print("Setting max voltage to '");
          Serial.print(param_buf);
          Serial.println("'");
          
          settings.max_v = atof(param_buf);
          EEPROM.put(0, settings);
        } else {
          Serial.print("Unrecognized argument: ");
          Serial.println(arg_buf);
        }
      }
    }
  }
}

void print_info() {
  Serial.print("UUID: ");
  Serial.println(settings.uuid);
  Serial.print("Name: ");
  Serial.println(settings.name);
  Serial.print("Key: ");
  Serial.println(settings.key);
  Serial.print("Min Voltage: ");
  Serial.println(settings.min_v);
  Serial.print("Max Voltage: ");
  Serial.println(settings.max_v);
}
