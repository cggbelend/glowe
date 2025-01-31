#include <EasyButton.h>
#include <config.h>
#include <leds.cpp>
#include <ArduinoLog.h>
#include <Arduino.h>


namespace Buttons
{
        void change_mode(){
            switch (counter::counter)
            {
            case 0:
                ledstripp::rainbow;
                Log.infoln("mode swiched to rainbow");
                break;

            case 1:
                ledstripp::moving_rainbow;
                Log.infoln("mode swiched to moving_rainbow");
                break;

            case 2:
                ledstripp::random_gradient;
                Log.infoln("mode swiched to random_gradient");
                break;

            case 3:
                ledstripp::moving_palette;
                Log.infoln("mode swiched to moving_palette");
                break;
            case 4:
                ledstripp::kometa;
                Log.infoln("mode swiched to kometa");
                break;

            default:
                Log.fatalln("fatal error: Couldn't handle that case of a swich of change_mode function in /robo/src/buttons.cpp");
                break;
            }
        }
    
    namespace counter{

        uint8_t counter;

        void increment(){
            counter::counter ++;
            Log.noticeln("counter incremented");
            Buttons::change_mode();


            if (counter::counter > ledstripp::count)
            {
                counter::first();
                Buttons::change_mode();
            }
            
        }

        void decrement(){
            counter::counter --;
            Log.noticeln("counter decremented");

            if (counter::counter < 0)
            {
                counter::Last();
            }
            Buttons::change_mode();
        }

        void Last(){
        counter::counter = ledstripp::count;
        Log.noticeln("counter = %d", counter::counter);
        Buttons::change_mode();
    }

        void first(){
            counter::counter = 0;
            Log.noticeln("counter reseted");
            Buttons::change_mode();
        }
    }

        EasyButton FwdBtn(FWD_BTN_PIN);
        EasyButton BwdBtn(BWD_BTN_PIN);

        void Begin(){
            pinMode(FWD_BTN_PIN, INPUT);
            pinMode(BWD_BTN_PIN,INPUT);

            FwdBtn.begin();
            BwdBtn.begin();

            FwdBtn.onPressed(counter::increment);
            BwdBtn.onPressed(counter::decrement);

            FwdBtn.onSequence(2, BTN_DOUBLE_CLICK_TIMEOUT, counter::Last);
            BwdBtn.onSequence(2, BTN_DOUBLE_CLICK_TIMEOUT, counter::first);

        }
}
