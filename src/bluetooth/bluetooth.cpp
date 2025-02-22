#include <SoftwareSerial.h>
#include <config.h>
#include <ArduinoLog.h>
#include <bluetooth/parser.h>
#include "bluetooth/bluetooth.h"

namespace bluetooth
{

    void listen(){
        if (BTSerial.available())
        {
            char msg = BTSerial.read();
            Log.info("bluetoooth msg receved: "+msg);
            BTParer::parce(msg);
        }

        
    }

    void send(char msg){
        BTSerial.println(msg);
        Log.infoln("bluetooth mesage sent: "+msg);
    }
} // namespace bluetooth
