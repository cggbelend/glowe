#include <ArduinoJson.h>
#include <ArduinoLog.h>
#include <leds.cpp>

namespace BTParer
{
    StaticJsonDocument<100> jsonDoc;

    void deserialize(char msg){
        DeserializationError err = deserializeJson(jsonDoc, msg);

        if (err)
        {
            Log.errorln("error while deserealizing json, json: " + msg + " error: " + err.f_str());
        }
        
    }

    void callFunction(const char* funcName, int count, ...) {
    va_list args;
    va_start(args, count);

    // Example output indicating the function being called
    Log.trace ("Calling " + funcName +" with " + " arguments: "+ args);
    
    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        Log.trace(value); // Use the argument value
        if (i < count - 1) {
            Log.trace(" ,");
        }
    }
    

    va_end(args);
}


    void parce(char msg){
        Log.traceln("parcing incoming message...");
        Log.traceln("deserialing incoming message...");
        deserialize(msg);
        Log.traceln("calling: "+jsonDoc["leds:: %d",jsonDoc["mode"]]);
        callFunction(jsonDoc["leds:: %d",jsonDoc["mode"]],0);
        Log.traceln("message parced");
    }
} // namespace BTParer
