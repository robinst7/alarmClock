#include <Time.h>
#include <TimeAlarms.h>


//Libraries and Code from:
//https://github.com/PaulStoffregen/TimeAlarms
//https://github.com/PaulStoffregen/Time


void setup() {
  Serial.begin(9600);
  setTime(3,3,0,3,10,19);//Set time here. Variables are (hour,minutes,seconds,month,day,20xx)
  Alarm.alarmRepeat(10,0,0,MorningAlarm);   //alarm at 10 am every day
  Alarm.alarmRepeat(dowSunday,11,0,0,WeeklyAlarm); //Alarm every sunday at 11 am
  Alarm.alarmOnce(3,3,20,ExplicitAlarm); //One explicit alarm for testing purposes

}

void loop() {
  digitalClockDisplay();
  Alarm.delay(1000); //Makes the clock refresh every second
}

void MorningAlarm(){
  Serial.println("Good Morning Tim");
  //alarmSound() If I were interfacing an alarm I would tell it to go off here and it would look like this
}

void WeeklyAlarm(){
  Serial.println("Happy Sunday Morning Tim");
  //alarmSound() 
}

void digitalClockDisplay(){
  Serial.print(hour());
  PrintDigits(minute());
  PrintDigits(second());
  Serial.println();
}

void ExplicitAlarm(){
  Serial.println("This Alarm will only sound once");
  //alarmSound()
}

void PrintDigits(int digits){
  Serial.print(":");
  if(digits<10)
    Serial.print('0');
   Serial.print(digits); 
}
