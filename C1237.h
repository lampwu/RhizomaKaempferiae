#ifndef __CS1237__h__
#define __CS1237__h__
#define SCK 12
#define DOUT 13
#define SCK_LOW digitalWrite(SCK,LOW)
#define SCK_HIGH digitalWrite(SCK,HIGH)

void CS1237Init()
{
    pinMode(SCK,OUTPUT);
    pinMode(DOUT,INPUT);
    //pinMode(DOUT,INPUT_PULLUP);
    SCK_LOW;
}

int CS1237isReady()
{
    if(digitalRead(DOUT) == 0)
    {
        return 1;
    }
    return 0;
}

void CS1237Config()
{
}

void CS1237ClockUp()
{
    SCK_LOW;
    delayMicroseconds(10);
    SCK_HIGH;
    delayMicroseconds(10);
}

int CS1237Read()
{
    int tmp = 0;
    int now = 0;
    int i;
    int num = 100;
    while(!CS1237isReady())
    {
        yield();
    }
    for (i = 0; i < 24; i ++ )
    {
        CS1237ClockUp();
        now = digitalRead(DOUT);
        SCK_LOW;
        tmp *= 2;
        tmp = tmp + now;
    }

    SCK_LOW;
    SCK_LOW;
    delayMicroseconds(10);
    SCK_HIGH;
    delayMicroseconds(10);
    SCK_LOW;
    delayMicroseconds(10);
    SCK_HIGH;
    delayMicroseconds(10);
    SCK_LOW;
    delayMicroseconds(10);
    SCK_HIGH;
    delayMicroseconds(10);
    SCK_LOW;

    return tmp;

}

int getValue(int num)
{
    int i = 0;
    int tmp = 0;
    long weight = 0;
    for ( i = 0; i < num; i ++)
    {
        tmp = CS1237Read();
        weight = weight + tmp;
    }
    return weight/num;
}

int getHelp(int num)
{
    return num * 3;
}

#endif

