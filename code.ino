#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

char input[12];
int count = 0;
int a;
int p1=0,p2=0,p3=0,p4=0; 
int c1=0,c2=0,c3=0,c4=0;

double total = 0;
int count_prod = 0;


void setup ()
{
//  Pin direction
   
  pinMode(3, INPUT_PULLUP);   //Push Switch
  pinMode(4, OUTPUT);         //BUZZER

// Initialization
  Serial.begin(9600);

  
//  lcd.begin();
 lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" SMART");
  delay (2000);
  lcd.setCursor(0, 1);
  lcd.print("  SHOPPING CART       ");

}
 void loop()
{
  
 count = 0;
    while (Serial.available() && count < 12)
    {
      input[count] = Serial.read();
      count++;
      delay(5);
    }
      int a=digitalRead(3);
      
    if ((strncmp(input, "4000350ABAC5", 12) == 0) && (a == 1))
    {
     
      lcd.setCursor(0, 0);
      lcd.print("Butter Added       ");
      lcd.setCursor(0, 1);
      lcd.print("Price(Rs):4.00      ");    
      digitalWrite(4,LOW);
      
      delay(2000);
      total = total + 4.00;
      count_prod++; 
      p1++;       
      digitalWrite(4,HIGH);       
        
    }


    else if ((strncmp(input, "4000350ABAC5", 12) == 0) && (a == 0))
    {
      if(p1>0)
      {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Butter Removed!!!        ");        
      digitalWrite(4,LOW);
      delay(2000);
      total = total - 4.00;
      lcd.clear();       
      digitalWrite(4,HIGH);
      p1--;
      if(p1==0)
      {
        count_prod--;
      }
      }
      else
      {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not in cart!!!        ");
      digitalWrite(4,LOW);        
      delay(2000);        
      digitalWrite(4,HIGH);        
      lcd.clear();
      }
    }


    if ((strncmp(input, "4000351B7B15", 12) == 0) && (a == 1))
    {
      lcd.setCursor(0, 0);
      lcd.print("Milk Added       ");
      lcd.setCursor(0, 1);
      lcd.print("Price(Rs):6.00      ");
      digitalWrite(6,HIGH);
      delay(2000);
      total = total + 6.00;
      count_prod++;       
      digitalWrite(4,HIGH);      
      p2++;  
    }


    else if ((strncmp(input, "4000351B7B15", 12) == 0) && (a == 0))
    {
      if(p2>0)
      {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Butter Removed!!!        ");
      digitalWrite(4,LOW);
      delay(2000);
      lcd.clear();
      digitalWrite(4,HIGH);
      p2--;
      if(p2==0)
      {
        count_prod--;
      }
      }
      else
      {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not in cart!!!        ");
      digitalWrite(4,LOW);
      delay(2000);
      digitalWrite(4,HIGH);
      lcd.clear();
      }
    }

    if ((strncmp(input, "4000355181A5", 12) == 0) && (a == 1))
    {

      lcd.clear();  
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");        
      lcd.setCursor(0, 1);
      lcd.print(total);
      delay(5000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("  THANKS FOR  ");
      lcd.setCursor(0, 1);
      lcd.print("   VISITING ");
     
    }     

}

