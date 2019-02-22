#include <stdio.h>
#include <stdlib.h>

// by Nonthwat zaza @ECP1N Rmuit kkc 20-22/2/2019
// ReverseAndAddQ Homework code
// 100% code final ver
long long int SwN=0,Starter=0,Finalnum=0,Num=0,Aws=0,taws=0,SwNtest=0,fixaws=0,semifixaws=0,Finalnumtest=0,SwNII=0,semitaws=0;
long long int Round=0;
long long int reverse(long long N)
{
/*
    หลักการทำงานของ ฟังชั่นกลับค่า
รอบ 1
SwN1 is 0
SwN2 is 5
n1 is 195
n2 is 19
====================
รอบ2
SwN1 is 50
SwN2 is 59
n1 is 19
n2 is 1
====================
รอบ 3
SwN1 is 590
SwN2 is 591
n1 is 1
n2 is 0
====================
ref is 591

*/
            while (N != 0)
            {
                SwN = SwN * 10;
                SwN = SwN + N%10;
                N = N/10;
            }
                return SwN;
}

long long int reversetest (long long int N)
{
            while (N != 0)
            {
                SwNtest = SwNtest * 10;
                SwNtest = SwNtest + N%10;
                N = N/10;
            }
                return SwNtest;
}
long long int reverseII(long long int N)
{
    unsigned long long int SwNII=0;
            while (N != 0)
            {
                SwNII = SwNII * 10;
                SwNII = SwNII + N%10;
                N = N/10;
            }
                return SwNII;
}

long long int Plus(long long int Num)
{
    (Finalnum = Starter+Num); //คำตอบ = ตัวตั้ง+ตัวตั้งสลับที่
    Round++; //เพิ่มรอบ
    return Finalnum; // ส่งคำตอบกลับเข้าฟังชั้นmain
}

long long int Plustest (long long int N)
{
    (Finalnumtest = taws+N);
    Round++;
    return Finalnumtest;
}

long long int main()
{
    long N;
    printf("input Number : ");
    scanf("%u",&N); // รับ N
    Starter = N; // ทดตัวตั้งใน ฟังชัน plus
    Num = reverse(N); // กลับค่า N ใส่ ตัวแปร Num
    Aws = Plus(Num); // เอสเลขกลับค่าไปเข้าฟังชั้นplus ไส่ตัวแปล aws
    taws = reversetest(Aws); // กลับค่า aws เพื่อเทียบ

    if  (N==Num&&(N!=0)) // ถ้าคำตอบเท่ากับค่าที่รับและไม่เท่ากับ 0
    {
        printf("0 %u",N); // แสดงค่า
        return 0; // จบ
    }

        if ((N<10)&&(N!=0)) // ถ้าคำตอบไม่เกิน 10 และไม่ใช่ 0
    {
        printf("0 %u",N);
        return 0; // จบ
    }

    if (taws != Aws) // ถ้าคำตอบไม่เท่ากับค่าที่รับ
    {
        while ((taws != Aws)&&(Round<=1000)&&(N!=0)&&(Aws<4294967295)) //วนลูปเมื่อผลลัพธ์สลับที่แล้วค่าไม่เท่าเดิมและไม่เกิน 1000รอบและไม่เท่ากับ0และไม่เกิน 4294967295
        {
            semifixaws=Aws; // ให้ semifixaws มีค่าเท่ากับ
            Aws=Plustest(semifixaws); //นำตัวแปรกลับค่าไปบวก ใส่ aws เหมือนเดิน
            taws = reverseII(Aws);//กลับค่าตัวเลขอีกรอบใส่ taws
        }           // วน

        if(Aws>4294967295) //ถ้าผลลัพธ์เกิน 4294967295
        {
                    printf("No palindrom found");
        }
    }
    if ((Round >=1000)&&(N!=0)&&(Aws>4294967295)) //ถ้าเกิน 1000 รอบ ผลลัพธ์เกิน 4294967295 และไม่เท่ากับ 0
    {
        printf("No palindrom found");
    }
    if (taws == Aws&&(Aws<4294967295)&&(N!=0)) // ถ้าผลลัพธ์สลับที่แล้วค่าเท่าเดิมและไม่เท่ากับ0และไม่เกิน 4294967295
        {
            printf("%lli %lli",Round, Aws); // แสดง ผลลัพธ์ รอบ, ผลลัพธ์
        }


    return 0; //จบ
}
