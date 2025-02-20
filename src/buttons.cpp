#include <EasyButton.h>
#include <ArduinoLog.h>
#include <leds.h>
#include <config.h>
#include <buttons.h>

namespace buttons
{
    EasyButton FwdBtn(config::buttons::FWD_PIN);
    EasyButton BwdBtn(config::buttons::BWD_PIN);

    void begin(){
        FwdBtn.begin();
        BwdBtn.begin();
        Log.infoln("buttons began");

        FwdBtn.onPressed(counter::increment);
        BwdBtn.onPressed(counter::decrement);
        Log.infoln("button callbacks set");
    }

    void update(uint16_t baudrate){
        EVERY_N_MILLISECONDS(baudrate){
            FwdBtn.read();
            BwdBtn.read();
        }
    }

    namespace counter
    {
        uint8_t counter;

        void decrement(){
            counter --;
            Log.traceln("counter decremeted");
            H_CounterCheck();

            ChangeMode();
        }

        void increment(){
            counter ++;
            Log.traceln("counter incremeted");
            H_CounterCheck();

            ChangeMode();
        }

        void H_CounterCheck(){
            if (counter > leds::ModesCount - 1)
            {
                Log.traceln("counter is bigger than 3, setting to 0");
                counter = 0;
            }
        }

    } // namespace counter
        void ChangeMode(){
            switch (counter::counter)
            {
            case 0:
                leds::color_wipe();
                Log.infoln("Mode changed to color_wipe");
                break;

            case 1:
                leds::fade();
                Log.infoln("Mode changed to fade");

            case 2:
                leds::rainbow();
                Log.infoln("Mode changed to rainbow");

            case 3:
                leds::twinkle();
                Log.infoln("Mode changed to twinkle");
            
            default:
                Log.fatalln("invalid counter value of buttons::counter::counter");
                break;
            }
        }
    
} // namespace buttons
