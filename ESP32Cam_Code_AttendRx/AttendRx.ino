#include "WifiCam.hpp"
#include <WiFi.h>
#include <Wire.h>             
#include "SSD1306Wire.h" 
#include "images.h"

SSD1306Wire display(0x3c, 14, 15); // SDA-14, SCL-15
#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 0;

static const char* WIFI_SSID = "SSID";
static const char* WIFI_PASS = "password";

esp32cam::Resolution initialResolution;

WebServer server(80);

void drawProgressBarDemo() {
  int progress = 0;
  while(progress<99){
    display.clear();
    progress = (counter / 5) % 100;
    // draw the progress bar
    display.drawProgressBar(0, 32, 120, 10, progress);
    // draw the percentage as String
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 15, "Loading " + String(progress) + "%");
    display.display();
    counter++;
    delay(10);
  }
    display.clear();
    progress = 100;
    // draw the progress bar
    display.drawProgressBar(0, 32, 120, 10, progress);
    // draw the percentage as String
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(64, 15, "Loading " + String(progress) + "%");
    display.display();
    counter++;
    delay(10);
}

void write(String text, String Alignment, int fontSize, bool clearScreen = true){
  if(clearScreen == true){
    display.clear();
  }
  if(Alignment == "left"){
    display.setTextAlignment(TEXT_ALIGN_LEFT);
  }
  else if(Alignment == "center"){
    display.setTextAlignment(TEXT_ALIGN_CENTER);
  }
  else if(Alignment == "right"){
    display.setTextAlignment(TEXT_ALIGN_RIGHT);
  }
  
  if(fontSize == 10){
    display.setFont(ArialMT_Plain_10);
  }
  else if(fontSize == 16){
    display.setFont(ArialMT_Plain_16);
  }
  else if(fontSize == 24){
    display.setFont(ArialMT_Plain_24);
  }
  
  display.drawString(0, 0, text);
  display.display();
}

void drawImageDemo() {
    // see http://blog.squix.org/2015/05/esp8266-nodemcu-how-to-create-xbm.html
    // on how to create xbm files
    display.drawXbm(34, 14, WiFi_Logo_width, WiFi_Logo_height, WiFi_Logo_bits);
    display.display();
}

void setup()
{
  Serial.begin(115200);
  Serial.println();
  delay(2000);

  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);

  drawProgressBarDemo();
  write("AttendRx\nStarted!", "left", 24);

  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi failure");
    write("Wifi\nFailure!", "left", 24);
    delay(5000);
    ESP.restart();
  }
  Serial.println("WiFi connected");
  write("Wifi\nConnected!", "left", 24);
  delay(1000);
  {
    using namespace esp32cam;

    initialResolution = Resolution::find(1024, 768);

    Config cfg;
    cfg.setPins(pins::AiThinker);
    cfg.setResolution(initialResolution);
    cfg.setJpeg(80);

    bool ok = Camera.begin(cfg);
    if (!ok) {
      Serial.println("camera initialize failure");
      write("camera\ninitialize\nfailure", "left", 16);
      delay(5000);
      ESP.restart();
    }
    Serial.println("camera initialize success");
    write("camera\ninitialize\nsuccess", "left", 16);
    delay(1000);
  }

  Serial.println("camera starting");
  write("camera\nstarting...", "left", 24);
  delay(1000);
  Serial.print("http://");
  Serial.println(WiFi.localIP());
  
  write("Connected to Galaxy at: \nhttp://"+ (WiFi.localIP()).toString(), "left", 10);


  addRequestHandlers();
  server.begin();
}

void
loop()
{
  server.handleClient();
}
