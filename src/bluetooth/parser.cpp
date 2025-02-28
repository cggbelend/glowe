#include <ArduinoJson.h>
#include <ArduinoLog.h>
#include <leds.h>

namespace BTParer
{
    StaticJsonDocument <100> jsonDoc;
    void deserialize(char* msg){
        DeserializationError err = deserializeJson(jsonDoc, msg);

        if (err)
        {
            Log.fatal("err while parsing");
        }
        
    }

    void callFunction(const char* funcName, int count, ...) {
    va_list args;
    va_start(args, count);

    // Example output indicating the function being called
    
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        Log.trace(" %d",value); // Use the argument value
        if (i < count - 1) {
            Log.trace(" ,");
        }
    }
    

    va_end(args);
}


    void parce(char* msg){
        Log.traceln("parcing incoming message...");
        Log.traceln("deserialing incoming message...");
        deserialize(msg);
        Log.traceln("calling: leds:: %c", jsonDoc["mode"].as<const char*>());
        callFunction("leds:: %c", *jsonDoc["mode"].as<const char*>());
        Log.traceln("message parced");
    }
} // namespace BTParer
