#include <SoftwareSerial.h>
#pragma once

namespace bluetooth
{
    SoftwareSerial BTSerial (BT_RX,BT_TX);

    void listen();
    void send(char msg);
} // namespace bluetooth
