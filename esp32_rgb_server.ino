#include <FastLED.h>
#include <String.h>
#include <WiFi.h>

// Replace with your network credentials
const char* ssid     = "MyCoolWiFiNetwork";
const char* password = "youshallnotpass";

// Set web server port number to 80
WiFiServer server(80);

String html ="<!DOCTYPE html> <html> <head> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> <meta charset=\"utf-8\" /> <link rel=\"icon\" href=\"https://i.imgur.com/vT4FIcd.png\"> <link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\"> <link rel=\"stylesheet\" href=\"https://cdn.jsdelivr.net/gh/mdbassit/Coloris@latest/dist/coloris.min.css\" /> <script src=\"https://cdn.jsdelivr.net/gh/mdbassit/Coloris@latest/dist/coloris.min.js\"></script> </head> <body> <style> body { background-color: #666666; font-family: \"Century Gothic\", CenturyGothic, AppleGothic, sans-serif; font-style: normal; font-variant: normal; } h1 { font-family: \"Century Gothic\", CenturyGothic, AppleGothic, sans-serif; font-style: normal; font-variant: normal; } h3 { font-family: \"Century Gothic\", CenturyGothic, AppleGothic, sans-serif; font-style: normal; font-variant: normal; } p { font-family: \"Century Gothic\", CenturyGothic, AppleGothic, sans-serif; font-style: normal; font-variant: normal; } blockquote { font-family: \"Century Gothic\", CenturyGothic, AppleGothic, sans-serif; font-style: normal; font-variant: normal; } pre { font-family: \"Century Gothic\", CenturyGothic, AppleGothic, sans-serif; font-style: normal; font-variant: normal; } h1 { font-size: 2.5rem; } #rectangle { width: 40rem; height: 30rem; max-height: 50rem; background: #2f2f2f; z-index: -1; border-radius: 16px; margin-left: auto; margin-right: auto; margin-top: 3rem; display: block; padding: 8px; } .row { background-image: repeating-linear-gradient(90deg, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta); text-align: center; background-size: 1200% 1200%; -webkit-background-clip: text; -webkit-text-fill-color: transparent; animation: rainbow 60s ease infinite; margin-left: auto; margin-right: auto; margin-top: 2%; display: block; padding-bottom: 4px; } .btn { color: white; background-color: #6e00ff; border-color: #6e00ff; display: block; margin-left: auto; margin-right: auto; margin-top: 16px; max-width: 16rem } #btn-primary:active { color: #3c008b; background-color: #6e00ff; border-color: #6e00ff; } #btn-primary:hover { color: #3c008b; background-color: #6e00ff; border-color: #6e00ff; } .input-box { display: block; } .text-label { color: white; font-size: 1.5rem; display: block; } .color-label { float: left; padding-right: 4px; } .mode-block { margin-left: auto; margin-right: auto; display: block; text-align: center; padding-bottom: 4px; } .mode-label { color: white; font-size: 2rem; display: block; font-weight: bold; } .jscolor { display: block; margin-left: auto; margin-right: 8px; margin-top: 6px; } .hr-line { margin: 0px 0px 8px; padding: 0; height: 0; border: none; border-top: 1px solid #666666; } .btn-mode { display: inline-block; width: 16rem; } .btn-rainbow { background-image: repeating-linear-gradient(90deg, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta); text-align: center; background-size: 1200% 1200%; -webkit-background-clip: unset; color: white; -webkit-text-fill-color: white; border: 0; font-weight: bold; text-shadow: -1px -1px 0 #000, 1px -1px 0 #000, -1px 1px 0 #000, 1px 1px 0 #000; animation: rainbow 60s ease infinite; width: fit-content; } .footerLabel { display: block; margin-top: 1rem; margin-left: auto; margin-right: auto; text-align: center; font-size: 16px; color: white; text-shadow: -4px -4px 8px #000, 4px -4px 8px #000, -4px 4px 8px #000, 4px 4px 8px #000; } .clr-field { float: right; } @media screen and (max-width: 768px) { #rectangle { width: 30rem; } h1 { font-size: 1.78rem; } .row { font-size: 20px; } .btn { font-size: 20px; max-width: 16rem; } .text-label { color: white; font-size: 1.75rem; float: left; display: block; padding-right: 4px; } .jscolor { display: block; max-width: 3.5rem; margin-left: auto; margin-right: 8px; margin-top: 12px; } .btn-rainbow { background-image: repeating-linear-gradient(90deg, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta); text-align: center; font-size: 1rem; background-size: 1200% 1200%; -webkit-background-clip: unset; color: white; -webkit-text-fill-color: white; border: 0; font-weight: bold; text-shadow: -1px -1px 0 #000, 1px -1px 0 #000, -1px 1px 0 #000, 1px 1px 0 #000; animation: rainbow 60s ease infinite; } } @media screen and (max-width: 600px) { #rectangle { width: 25rem; } h1 { font-size: 1.689rem; font-weight: bold; } .row { font-size: 18px; } .btn { font-size: 16px; font-weight: bold; width: 16rem; max-width: 16rem; } .text-label { color: white; font-size: 1.35rem; float: left; display: block; padding-right: 1px; } .mode-label { font-size: 1.75rem; } .jscolor { display: block; max-width: 3.5rem; margin-left: auto; margin-right: 8px; margin-top: 6px; } .btn-mode { margin-top: 0px; } .btn-rainbow { background-image: repeating-linear-gradient(90deg, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta); text-align: center; font-size: 0.99rem; background-size: 1200% 1200%; -webkit-background-clip: unset; color: white; display: block; margin-top: 12px; -webkit-text-fill-color: white; border: 0; font-weight: bold; text-shadow: -1px -1px 0 #000, 1px -1px 0 #000, -1px 1px 0 #000, 1px 1px 0 #000; animation: rainbow 60s ease infinite; } } @media screen and (max-width: 480px) { #rectangle { width: 18rem; } h1 { font-size: 1.189rem; font-weight: bold; } .row { font-size: 16px; } .btn { font-size: 16px; font-weight: bold; max-width: 10rem; } .text-label { color: white; font-size: 1.15rem; float: left; display: block; padding-right: 1px; } .mode-label { font-size: 1.25rem; } .jscolor { display: block; max-width: 3.5rem; margin-left: auto; margin-right: 8px; margin-top: 6px; } .btn-mode { margin-top: 0px; } .btn-rainbow { background-image: repeating-linear-gradient(90deg, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta, #6e00ff, blue, aqua, lime, yellow, orange, red, magenta); text-align: center; font-size: 0.75rem; background-size: 1200% 1200%; -webkit-background-clip: unset; color: white; display: block; margin-top: 12px; -webkit-text-fill-color: white; border: 0; font-weight: bold; text-shadow: -1px -1px 0 #000, 1px -1px 0 #000, -1px 1px 0 #000, 1px 1px 0 #000; animation: rainbow 60s ease infinite; } .colorPicker { max-width: 5.92rem; } .clr-field { max-width: 5.92rem; } } @media screen and (max-height: 960px) { #rectangle { margin-top: 2rem; height: 30rem; } } @media screen and (max-height: 640px) { #rectangle { margin-top: 2rem; height: 30rem; } } @media screen and (max-height: 512px) { #rectangle { margin-top: 1rem; height: 30rem; } } @keyframes rainbow { 0% { background-position: 0% 50% } 50% { background-position: 100% 25% } 100% { background-position: 0% 50% } } </style> <div id=\"rectangle\"> <div class=\"container\"> <div class=\"row\"> <h1>ESP32 RGB Strip Controller</h1> </div> <p class=\"text-label color-label\">Цвет RGB ленты:</p> <input type=\"text\" class=\"colorPicker\" data-coloris> <script> Coloris({ format: 'hex', theme: 'polaroid', themeMode: 'dark', alpha: false }); </script> <input class=\"btn btn-primary btn-lg change_color\" style=\"width:16rem; margin-top: 3.25rem;\" type=\"button\" value=\"Сменить цвет\" id=\"change_color\" role=\"button\" /><br> </div> <hr class=\"hr-line\"> <div class=\"mode-block\"> <p class=\"mode-label\">Режимы/Эффекты</p> <a class=\"btn btn-primary btn-lg btn-mode\" href=\"?r0g0b0m1&\" id=\"change_mode\" role=\"button\">Цвет</a><br> <a class=\"btn btn-primary btn-lg btn-mode btn-rainbow\" href=\"?r0g0b0m3&\" id=\"change_mode\" role=\"button\">Радуга на RGB</a> <a class=\"btn btn-primary btn-lg btn-mode btn-rainbow\" href=\"?r0g0b0m2&\" id=\"change_mode\" role=\"button\">Радуга на ARGB</a> <a class=\"btn btn-primary btn-lg btn-mode btn-rainbow\" href=\"?r0g0b0m4&\" id=\"change_mode\" role=\"button\">Радуга везде</a> </div> </div> <script> var red = 0, green = 0, blue = 0; document.addEventListener('coloris:pick', event => { red = hex2rgb(event.detail.color).r; green = hex2rgb(event.detail.color).g; blue = hex2rgb(event.detail.color).b; console.log(red, \"\", green, \"\", blue); }); function hex2rgb(c) { var result = /^#?([a-f\\d]{2})([a-f\\d]{2})([a-f\\d]{2})$/i.exec(c); return result ? { r: parseInt(result[1], 16), g: parseInt(result[2], 16), b: parseInt(result[3], 16) } : null; } document.getElementById(\"change_color\").addEventListener(\"click\", function () { window.location = '?r' + red + 'g' + green + 'b' + blue + 'm1&'; }) </script> </body> <footer> <div class=\"footerLabel\"> <p>2024 © IB WorkShop. Все права защищены.</p> </div> </footer> </html>";

// Decode HTTP GET value
String redString = "0";
String greenString = "0";
String blueString = "0";
String modeString = "0";
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;
int pos4 = 0;
int pos5 = 0;
int mode = 0;

// Variable to store the HTTP req  uest
String header;

// Red, green, and blue pins for PWM control
const int redPin = 12;     // 12 corresponds to GPIO12
const int greenPin = 13;   // 13 corresponds to GPIO13
const int bluePin = 14;    // 14 corresponds to GPIO14
#define adressPin 26
#define NUMLEDS 10

byte counterHue = 0;

float saturation = 1; // Between 0 and 1 (0 = gray, 1 = full color)
float brightness = 1; // Between 0 and 1 (0 = dark, 1 is full brightness)
float hue = 0;

int red = 255;
int green = 0;
int blue = 102;

CRGB leds[NUMLEDS];

// Setting PWM frequency, channels and bit resolution
const int freq = 5000;
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;
// Bit resolution 2^8 = 256
const int resolution = 8;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0; 
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);

  FastLED.addLeds<WS2812B, adressPin, RGB>(leds, NUMLEDS);  // GRB ordering is typical

  // configure LED PWM functionalitites
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(redPin, redChannel);
  ledcAttachPin(greenPin, greenChannel);
  ledcAttachPin(bluePin, blueChannel);
  
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  countHUE();

  if(modeString.toInt() == 2){
    ARGB();
  }
  else if(modeString.toInt() == 3){
    rainbowRGB();
  }
  else if(modeString.toInt() == 4){
    ARGB();
    rainbowRGB();
  }

  /*Serial.println("\n\n");
  Serial.print("[DEBUG] HUE: ");
  Serial.println(hue);
  Serial.print("[DEBUG] Red: ");
  Serial.println(red);
  Serial.print("[DEBUG] Green: ");
  Serial.println(green);
  Serial.print("[DEBUG] Blue: ");
  Serial.println(blue);*/

  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {            // loop while the client's connected
      currentTime = millis();
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
                   
            // Display the HTML web page
            client.println(html);
            /*
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"https://i.imgur.com/vT4FIcd.png\">");
            client.println("<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css\">");
            client.println("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/jscolor/2.0.4/jscolor.min.js\"></script>");
            client.println("</head><body><style>body{ background-color: #666666}</style><div class=\"container\"><div class=\"row\"><h1>ESP32 RGB Strip Controller</h1></div>");
            client.println("<input class=\"jscolor {onFineChange:'update(this)'}\" id=\"rgb\"></div>");
            client.println("<a class=\"btn btn-primary btn-lg\" href=\"#\" id=\"change_color\" role=\"button\">Change Color</a> ");
            client.println("<script>function update(picker) {document.getElementById('rgb').innerHTML = Math.round(picker.rgb[0]) + ', ' +  Math.round(picker.rgb[1]) + ', ' + Math.round(picker.rgb[2]);");
            client.println("document.getElementById(\"change_color\").href=\"?r\" + Math.round(picker.rgb[0]) + \"g\" +  Math.round(picker.rgb[1]) + \"b\" + Math.round(picker.rgb[2]) + \"&\";}</script></body></html>");
            */
            // The HTTP response ends with another blank line
            client.println();

            // Request sample: /?r201g32b255m1&
            // Red = 201 | Green = 32 | Blue = 255 | Mode = 1
            if(header.indexOf("GET /?r") >= 0) {
              pos1 = header.indexOf('r');
              pos2 = header.indexOf('g');
              pos3 = header.indexOf('b');
              pos4 = header.indexOf('m');
              pos5 = header.indexOf('&');
              redString = header.substring(pos1+1, pos2);
              greenString = header.substring(pos2+1, pos3);
              blueString = header.substring(pos3+1, pos4);
              modeString = header.substring(pos4+1, pos5);
              
              Serial.println(redString.toInt());
              Serial.println(greenString.toInt());
              Serial.println(blueString.toInt());
              Serial.println(modeString.toInt());

              if(modeString.toInt() == 1){
                ledcWrite(redChannel, redString.toInt());
                ledcWrite(greenChannel, greenString.toInt());
                ledcWrite(blueChannel, map(blueString.toInt(), 0, 255, 0, 128));
                ARGB();
              }
            }

            // Request sample: /?a2m&
            // Automatic mode 2
            else if (header.indexOf("GET /?a") >= 0){
              mode = header.indexOf('m');
              pos5 = header.indexOf('&');

              if(mode = 1){
                
              }
            }
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

void countHUE(){
  float colorNumber = counterHue > 255 ? counterHue - 255: counterHue;
  hue = (colorNumber / float(255)) * 360; // Number between 0 and 360
  colorToRGB();

  counterHue++;
  delay(60);
}

void colorToRGB(){
  red = HSBtoRGB(hue, saturation, brightness) >> 16 & 255;
  green = HSBtoRGB(hue, saturation, brightness) >> 8 & 255;
  blue = HSBtoRGB(hue, saturation, brightness) & 255;
}

void ARGB(){
  if(modeString.toInt() == 1){
    for (int i = 0; i < NUMLEDS; i++ ) {
      leds[i] = CRGB(greenString.toInt(), redString.toInt(), blueString.toInt());
    }
  }
  else{
    for (int i = 0; i < NUMLEDS; i++ ) {
      leds[i] = CRGB(green, red, blue);
    }
  }
  FastLED.show();
}

void ARGB_SetColor(){
  for (int i = 0; i < NUMLEDS; i++ ) {
    leds[i] = CRGB(green, red, blue);
  }
  FastLED.show();
}

void rainbowRGB(){
  ledcWrite(redChannel, red);
  ledcWrite(greenChannel, green);
  ledcWrite(blueChannel, blue);
}

long HSBtoRGB(float _hue, float _sat, float _brightness) {
    float red = 0.0;
    float green = 0.0;
    float blue = 0.0;
    
    if (_sat == 0.0) {
        red = _brightness;
        green = _brightness;
        blue = _brightness;
    } else {
        if (_hue == 360.0) {
            _hue = 0;
        }

        int slice = _hue / 60.0;
        float hue_frac = (_hue / 60.0) - slice;

        float aa = _brightness * (1.0 - _sat);
        float bb = _brightness * (1.0 - _sat * hue_frac);
        float cc = _brightness * (1.0 - _sat * (1.0 - hue_frac));
        
        switch(slice) {
            case 0:
                red = _brightness;
                green = cc;
                blue = aa;
                break;
            case 1:
                red = bb;
                green = _brightness;
                blue = aa;
                break;
            case 2:
                red = aa;
                green = _brightness;
                blue = cc;
                break;
            case 3:
                red = aa;
                green = bb;
                blue = _brightness;
                break;
            case 4:
                red = cc;
                green = aa;
                blue = _brightness;
                break;
            case 5:
                red = _brightness;
                green = aa;
                blue = bb;
                break;
            default:
                red = 0.0;
                green = 0.0;
                blue = 0.0;
                break;
        }
    }

    long ired = red * 255.0;
    long igreen = green * 255.0;
    long iblue = blue * 255.0;
    
    return long((ired << 16) | (igreen << 8) | (iblue));
}