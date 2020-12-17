#include<graphics.h>
#include<iostream>
using namespace std;

void House1Mall1(int color)
{
    setcolor(color);
    line(75,50,155,50);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(95,25,"5km");
}
void Mall1House2(int color)
{
    setcolor(color);
    line(180,75,180,145);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(190,100,"7km");
}
void House2House3(int color)
{
    setcolor(color);
    line(75,170,155,170);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(95,145,"9km");
}
void House1House3(int color)
{
    setcolor(color);
    line(50,75,50,145);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(0,100,"2km");
}
void House3Mall2(int color)
{
    setcolor(color);
    line(50,195,50,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(0,240,"4km");
}
void Mall2House4(int color)
{
    setcolor(color);
    line(75,320,305,320);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(170,295,"15km");
}
void House4Mall3(int color)
{
    setcolor(color);
    line(330,195,330,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(340,235,"3km");
}
void Mall3House2(int color)
{
    setcolor(color);
    line(205,170,305,170);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(235,145,"6km");
}
void Mall1House5(int color)
{
    setcolor(color);
    line(205,50,425,50);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(305,25,"8km");
}
void House5Mall4(int color)
{
    setcolor(color);
    line(450,75,450,295);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(460,180,"11km");
}
void House4Mall4(int color)
{
    setcolor(color);
    line(355,320,425,320);
    setcolor(color);
    setbkcolor(15);
    settextstyle(8,0,3);
    outtextxy(370,290,"1km");
}
void Cab1(char *cab)
{
    setcolor(BLACK);
    circle(115,105,30);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(115,105,BLACK);

    setcolor(BLACK);
    setbkcolor(YELLOW);
    settextstyle(2,0,6);
    outtextxy(90,97,cab);
}
void Cab2(char *cab)
{
    setcolor(BLACK);
    circle(350,105,30);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(350,105,BLACK);

    setcolor(BLACK);
    setbkcolor(YELLOW);
    settextstyle(2,0,6);
    outtextxy(325,97,cab);
}
void Cab3(char *cab)
{
    setcolor(BLACK);
    circle(200,240,30);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(200,240,BLACK);

    setcolor(BLACK);
    setbkcolor(YELLOW);
    settextstyle(2,0,6);
    outtextxy(175,233,cab);
}

int main()
{
    initwindow(640,480,"Map");

    //bg
    setbkcolor(15);
    setfillstyle(SOLID_FILL,15);
    floodfill(1,1,15);

     //mall 1
    setcolor(BLACK);
    rectangle(155,25,205,75);
    setfillstyle(SOLID_FILL,12);
    floodfill(156,26,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(160,45,"Mall 1");

    //mall 2
    setcolor(BLACK);
    rectangle(25,295,75,345);
    setfillstyle(SOLID_FILL,12);
    floodfill(26,296,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(30,315,"Mall 2");

    //mall 3
    setcolor(BLACK);
    rectangle(305,145,355,195);
    setfillstyle(SOLID_FILL,12);
    floodfill(306,146,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(310,165,"Mall 3");

    //mall 4
    setcolor(BLACK);
    rectangle(425,295,475,345);
    setfillstyle(SOLID_FILL,12);
    floodfill(426,296,BLACK);

    setcolor(BLACK);
    setbkcolor(12);
    settextstyle(2,0,5);
    outtextxy(430,315,"Mall 4");

    //house 1
    setcolor(BLACK);
    rectangle(25,25,75,75);
    setfillstyle(SOLID_FILL,7);
    floodfill(26,26,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(28,45,"House 1");

    //house 2
    setcolor(BLACK);
    rectangle(155,145,205,195);
    setfillstyle(SOLID_FILL,7);
    floodfill(156,156,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(158,165,"House 2");

    //house 3
    setcolor(BLACK);
    rectangle(25,145,75,195);
    setfillstyle(SOLID_FILL,7);
    floodfill(26,146,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(28,165,"House 3");

    //house 4
    setcolor(BLACK);
    rectangle(305,295,355,345);
    setfillstyle(SOLID_FILL,7);
    floodfill(306,296,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(308,315,"House 4");

    //house 5
    setcolor(BLACK);
    rectangle(425,25,475,75);
    setfillstyle(SOLID_FILL,7);
    floodfill(426,26,BLACK);

    setcolor(BLACK);
    setbkcolor(7);
    settextstyle(2,0,4);
    outtextxy(428,45,"House 5");

    char cab1[10]="Cab1";
    char cab2[10]="Cab2";
    char cab3[10]="Cab3";

    Cab1(cab1);
    Cab2(cab2);
    Cab3(cab3);

    int color=5;
    House1Mall1(color);
    Mall1House2(color);
    House2House3(color);
    House1House3(color);
    House3Mall2(color);
    Mall2House4(color);
    House4Mall3(color);
    Mall3House2(color);
    Mall1House5(color);
    House5Mall4(color);
    House4Mall4(color);

    getch();
}
