/*
   Copyright (c) 2014 Innovative Experiment Co.,Ltd.

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
   THE SOFTWARE.
*/

/*
   โปรแกรมทดสอบการทำงานของบอร์ด Arduino Uno กับจอยสติ๊กไร้สายที่ทำงานเข้ากันได้กับจอยสติ๊ก PS2

   ใช้หน้าต่าง Serial monitor ในการแสดงผลชื่อปุ่มของจอยสติ๊กที่ถูกกด
*/
#include <PS2X_lib.h>                  // เรียกใช้งานไลบรารีสำหรับจอยสติ๊ก PS2

#define PS2_DAT   2                    // กำหนดขา Data    เป็นขา 30
#define PS2_CMD   3                    // กำหนดขา Command เป็นขา 4
#define PS2_SEL   4                   // กำหนดขา Select  เป็นขา 6
#define PS2_CLK   5                   // กำหนดขา Clock   เป็นขา 12

PS2X ps2x;                             // ประกาศตัวแปรสำหรับจอยสติ๊ก PS2

void setup()

{
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  delay(1000);                         // หน่วงเวลา 1 วินาทีเพื่อรอให้บอร์ดพร้อมทำงาน
  Serial.begin(9600);
  Serial.println("Connecting");        // แสดงข้อความเพื่อแจ้งว่า กำลังเชื่อมต่อกับจอยสติ๊ก
  while (true)                         // วนรอการเชื่อมต่อกับจอยสติ๊ก
  {
    // กำหนดขาเชื่อมต่อกับจอยสติ๊ก โดยมีการเก็บค่าที่ส่งกลับมาเป็น Integer เพื่อรู้ได้ว่าเชื่อมต่อได้หรือไม่
    int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);

    if (error == 0)                    // กรณีที่เชื่อมต่อได้ Error = 0
    {
      Serial.println("OK");            // แสดงข้อความว่า เชื่อมต่อกับจอยสติ๊กเรียบร้อยแล้ว
      delay(1000);                     // หน่วงเวลา 1 วินาที
      break;                           // ออกจาก while(true)
    }
    delay(500);                        // หน่วงเวลา 500 มิลลิวินาทีเพื่อรอการเชื่อมต่อครั้งต่อไปในกรณีที่เชื่อมต่อไม่สำเร็จ
  }
}

void loop()
{
  ps2x.read_gamepad(false, false);     // อ่านข้อมูลจาก PS2 Controller

  if (ps2x.Button(PSB_CIRCLE))         // ถ้าปุ่มวงกลมถูกกด
  {
    Serial.println("Circle");
  }
  //    Serial.println("Circle");          // แสดงข้อความว่า Circle
  //  else if(ps2x.Button(PSB_CROSS))      // ถ้าปุ่มกากบาทถูกกด
  //    Serial.println("Cross");           // แสดงข้อความว่า Cross
  //  else if(ps2x.Button(PSB_SQUARE))     // ถ้าปุ่มสี่เหลี่ยมถูกกด
  //    Serial.println("Square");          // แสดงข้อความว่า Square
  //  else if(ps2x.Button(PSB_TRIANGLE))   // ถ้าปุ่มสามเหลี่ยมถูกกด
  //    Serial.println("Triangle");        // แสดงข้อความว่า Triangle
  //  else if(ps2x.Button(PSB_L1))         // ถ้าปุ่ม L1 ถูกกด
  //    Serial.println("L1");              // แสดงข้อความว่า L1
  //  else if(ps2x.Button(PSB_L2))         // ถ้าปุ่ม L2 ถูกกด
  //    Serial.println("L2");              // แสดงข้อความว่า L2
  //  else if(ps2x.Button(PSB_L3))         // ถ้าปุ่ม L3 ถูกกด
  //    Serial.println("L3");              // แสดงข้อความว่า L3
  //  else if(ps2x.Button(PSB_R1))         // ถ้าปุ่ม R1 ถูกกด
  //    Serial.println("R1");              // แสดงข้อความว่า R1
  //  else if(ps2x.Button(PSB_R2))         // ถ้าปุ่ม R2 ถูกกด
  //    Serial.println("R2");              // แสดงข้อความว่า R2
  //  else if(ps2x.Button(PSB_R3))         // ถ้าปุ่ม R3 ถูกกด
  //    Serial.println("R3");              // แสดงข้อความว่า R3
  //  else if(ps2x.Button(PSB_START))      // ถ้าปุ่ม Start ถูกกด
  //    Serial.println("Start");           // แสดงข้อความว่า Start
  //  else if(ps2x.Button(PSB_SELECT))     // ถ้าปุ่ม Select ถูกกด
  //    Serial.println("Select");          // แสดงข้อความว่า Select
  else if (ps2x.Button(PSB_PAD_UP))  {
    Serial.println("Up");
    forward();
  }

  // แสดงข้อความว่า Up
  else if (ps2x.Button(PSB_PAD_DOWN)) {
    Serial.println("Down");
    reward();
  }
  // แสดงข้อความว่า Down
  else if (ps2x.Button(PSB_PAD_LEFT))  // ถ้าปุ่ม Left ถูกกด
    Serial.println("Left");            // แสดงข้อความว่า Left
  else if (ps2x.Button(PSB_PAD_RIGHT)) // ถ้าปุ่ม Right ถูกกด
    Serial.println("Right");           // แสดงข้อความว่า Right

  delay(50);                           // หน่วงเวลา 50 มิลลิวินาที
}


void forward() {
  digitalWrite(7, 1);
  analogWrite(6, 255);
}
void reward() {
  digitalWrite(7, 0);
  analogWrite(6, 255);
}
