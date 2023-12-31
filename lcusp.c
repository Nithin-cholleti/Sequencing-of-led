void main()
{
    CMCON = 0x07;    // To turn off comparators
    ADCON1 = 0x06;   // To turn off analog to digital converters

    TRISB = 0x00;    //  set direction of RBO to output OxFE = 11111110 all other pins (RB1 - RB7) are input pins
    PORTB = 1;       // Set RB0 to high 00000001

    do              // To set infinite loop
    {
      Delay_ms(300);          // 350 mili seconds delay
      PORTB = PORTB<<1;       //Shifting right by one bit
      if(PORTB >= 0b10000000) //To reset to 00000001 when the count becomes 10000000
      {
         Delay_ms(350);       // 350 mili seconds delay
         PORTB = 1;
      }
    }while(1);      // To set infinite loop
}