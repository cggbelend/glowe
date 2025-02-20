#pragma ones

namespace buttons
{
    void begin();
    void update(uint16_t baudrate);
    namespace counter
    {
        void decrement();
        void increment();
        void H_CounterCheck();
    } // namespace counter

    void ChangeMode();

} // namespace buttons
