#include <ArduinoJson.h>
#include <IRremote.h>

#define BAUDRATE 38400

// IRsend irsend; // PIN D3

StaticJsonDocument<128> serialJson;
DynamicJsonDocument data(128);

void setup() {
  Serial.begin(BAUDRATE);
  IrSender.setSendPin(3);
}

void loop() {
  bool jsonError = false;

  serialJson.clear();
  data.clear();

  // {"type":"ac","cmd":"cool28"}
  if (nextSerialJson(&serialJson, &jsonError)) {
    String type = serialJson["type"];

    if (type.equals("null")) {
    }
    else if (type.equals("ac")) {
      String cmd = serialJson["cmd"];
      String msg = "xxx";

      bool ret = sendIR_A75C3777(cmd, &msg);

      data["ret"] = ret;
      data["msg"] = msg;

      serializeJson(data, Serial);
      Serial.println("");
    }
  }
  else if (jsonError) {
    data["type"] = "jsonError";
    serializeJson(data, Serial);
    Serial.println("");
  }
}
