
#include <graphics.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
//////////////////
/// Basic Functions//
//////////////////
void add(void);
void report(void);
void find(void);
void del(void);
///////////////////
// Message Functions//
//////////////////
void alert(void);
void invalid(void);
void notfind(void);
void moreadd(void);
void wrong_name(void);
void more_del(void);
void del_not_found(void);
void find_more(void);
void help(void);
//////////////////
void main()
{
    int gd = 0, gm, errorcode;
    closegraph();
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    errorcode = graphresult();
    if (errorcode != grOk) /* an error occurred */
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1); /* return with error code */
    }
    int choice;
invalid_key:
    cleardevice();
    setbkcolor(1);
    setcolor(WHITE);
    rectangle(2, 2, 633, 475);
    line(2, 405, 633, 405);
    setfillstyle(1, 1);
    bar(170, 30, 450, 57);
    settextstyle(2, 0, 7);
    outtextxy(70, 410, "Made by Zeeshan Ahmed... [ Electrify (EF) ]");
    line(2, 440, 633, 440);
    settextstyle(2, 0, 5);
    outtextxy(5, 450, "web : www.tehseenwd.4t.com * E-mail: zeeshanwon@yahoo.com *  Mob: 0304-2615105");
    settextstyle(8, 0, 2);
    setcolor(11);
    rectangle(170, 30, 450, 63);
    outtextxy(190, 30, "TELEPHONE INDEX 1.0");
    setcolor(7);              ////White Color for Lines ////
    line(170, 79, 450, 79);   // Up line
    line(169, 80, 169, 390);  // Left Line
    setcolor(8);              //	Black color
    line(170, 392, 450, 392); //    Down Line
    line(452, 79, 452, 390);  //   Right Line
    setfillstyle(1, 6);
    bar(170, 80, 450, 390);
    settextstyle(2, 0, 6);
    setcolor(WHITE);

    setfillstyle(9, 8);
    bar(225, 350, 300, 370);

    outtextxy(180, 120, "1.  Add New Record");
    outtextxy(180, 160, "2.  Find Record");
    outtextxy(180, 200, "3.  Display All Records");
    outtextxy(180, 240, "4.  Delete Record");
    outtextxy(180, 290, "5.  Exit Program");
    gotoxy(30, 23);
    scanf("%1d", &choice);
    fflush(stdin); // flush the input stream in case of bad input //
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        find();
        break;
    case 3:
        report();
        break;
    case 4:
        del();
        break;
    case 0:
        help();
    case 5:
        closegraph();
        exit(0);
    default:
        invalid();
        goto invalid_key;
    }
    getch();
}

/////////////// Functions ///////////////////
// Add Function Begin///////////

void add()
{
    struct phone
    {
        char name[30], address[50];
        char ph[30], mob[30];
    };
    struct phone p;
    int g = 0;
    FILE *tel;
    tel = fopen("grtel.dat", "ab");
    cleardevice();
    if (tel == NULL)
    {
        fclose(tel);
        alert();
        exit(0);
    }
    fflush(stdin);
    setcolor(WHITE);
    line(200, 5, 200, 68);
    gotoxy(2, 3);
    printf("Type \"exit\" for cancel.");
    settextstyle(3, 0, 2);
    outtextxy(250, 5, "ELECTRIFY");
    line(218, 35, 400, 35);
    outtextxy(220, 40, "Adding Records");
    line(5, 68, 630, 68);
    rectangle(5, 5, 630, 450);
    gotoxy(10, 6);
    printf("Enter Name:? ");
    gets(p.name);
    if (stricmp(p.name, "exit") == 0)
    {
        fclose(tel);
        closegraph();
        main();
    }
    ////////////////////// Check The Name Is that "String" /////////////////
    while (p.name[g] != '\0')
    {
        if ((p.name[g] >= 65 && p.name[g] <= 90) || (p.name[g] >= 97 && p.name[g] <= 122) || (p.name[g] == 32 || p.name[g] == 46))
            g++;
        else
        {
            fclose(tel);
            wrong_name();
        }
    } ////////////////////////////////////////////////////////////// gotoxy(10,8);printf("Enter Phone No:? "); gets(p.ph); if(stricmp(p.ph,"exit")==0) { fclose(tel); closegraph(); main(); } gotoxy(10,10);printf("Enter Mobile No:? "); gets(p.mob); if(stricmp(p.mob,"exit")==0) { fclose(tel); closegraph(); main(); } gotoxy(10,12);printf("Enter Address:? "); gets(p.address); if(stricmp(p.address,"exit")==0) { fclose(tel); closegraph(); main(); } fwrite(&p,sizeof(p),1,tel); fflush(stdin); fclose(tel); moreadd(); } ////////////End Add function////////////////////////// //Begin Find Funtion/////////////////// void find() { struct phone { char name[30],address[50]; char ph[30],mob[30]; }; struct phone p; char search[25]; int cl=0,CHECK_RECORD=1,TOTAL_FOUND=0; int rec=0,y=7; FILE *tel; tel=fopen("grtel.dat","rb"); cleardevice(); if(tel==NULL) { fclose(tel); alert(); //// Alert Message like windows/// closegraph(); main(); } flushall(); cleardevice(); setcolor(WHITE); rectangle(2,2,633,475); settextstyle(2,0,6); setcolor(WHITE); rectangle(5,295,200,330); gotoxy(2,20);printf("Type \"exit\" for cancel."); outtextxy(10,10,"Enter Name for Searching:?"); settextstyle(1,0,4); outtextxy(10,350,"Searching option... EF (TTLC)"); setfillstyle(1,8); bar(6,45,200,70); gotoxy(3,4);gets(search); if(stricmp(search,"exit")==0) { fclose(tel); closegraph(); main(); } flushall(); while(fread(&p,sizeof(p),1,tel)==1) { if(stricmp(p.name,search)==0) { TOTAL_FOUND++; } } fclose(tel); flushall(); tel=fopen("grtel.dat","rb"); while(fread(&p,sizeof(p),1,tel)==1) { if(stricmp(p.name,search)==0) { cl++; if(cl==1) { cleardevice(); } cl=0; line(200,5,200,68); gotoxy(3,3);printf("%d Record(s) Found...",TOTAL_FOUND); settextstyle(3,0,2); outtextxy(250,5,"ELECTRIFY"); line(218,35,400,35); outtextxy(220,40,"Search Option"); line(5,68,630,68); ////// "y" took so increase y axis Value mean swap for "\n" rectangle(5,5,630,450); gotoxy(10,y);printf("* Record %d.",CHECK_RECORD); y++; gotoxy(10,y);printf("Name == %s.",p.name); y++; gotoxy(10,y);printf("Phone No.== %s",p.ph); y++; gotoxy(10,y);printf("Mobile No.== %s",p.mob); y++; gotoxy(10,y);printf("Address:== %s",p.address); y++; gotoxy(10,y);printf("-------------------------------------------------------------"); y++; y=7; getch(); CHECK_RECORD++; ////////////// if(y>19)
    {
        cleardevice(); /// if screen full shows on 1,1 axix..Electrify...
        y = 7;
    }
    //////////////
    rec = 1;
}
}
if (rec == 1)
{
    gotoxy(10, 19);
    printf("Record Updated.");
}
else
{
    flushall();
    fclose(tel);
    notfind(); /// Not Find Message Function box///////
}
CHECK_RECORD = 1;
fclose(tel);
flushall();
getch();
find_more();
}
////////////////Begin Delete Function //////////
void del()
{
    struct phone
    {
        char name[30], address[50];
        char ph[30], mob[30];
    };
    struct phone p;
    char del[25];
    int rec = 0;
    FILE *tel;
    FILE *temp;
    tel = fopen("grtel.dat", "rb");
    temp = fopen("grtempo.dat", "ab");
    cleardevice();
    if (tel == NULL)
    {
        fclose(tel);
        fclose(temp);
        alert();
        closegraph();
        main();
    }
    flushall();
    cleardevice();
    settextstyle(2, 0, 6);
    setcolor(WHITE);
    rectangle(2, 2, 633, 475);
    rectangle(5, 295, 200, 330);
    gotoxy(2, 20);
    printf("Type \"exit\" for cancel.");
    outtextxy(10, 10, "Enter Name for Deleting:?");
    settextstyle(1, 0, 4);
    outtextxy(10, 350, "Deleting option... EF (TTLC)");
    setfillstyle(1, 8);
    bar(6, 45, 200, 70);
    gotoxy(3, 4);
    gets(del);
    if (stricmp(del, "exit") == 0)
    {
        fclose(temp);
        fclose(tel);
        closegraph();
        remove("grtempo.dat");
        main();
    }
    while (fread(&p, sizeof(p), 1, tel) == 1)
    {
        if (stricmp(del, p.name) != 0)
            fwrite(&p, sizeof(p), 1, temp);
        else
            rec = 1;
    }
    if (rec == 1)
    {
        fclose(tel);
        fclose(temp);
        remove("grtel.dat");
        rename("grtempo.dat", "grtel.dat");
        fflush(stdin);
        more_del();
    }
    else
    {
        fclose(tel);
        fclose(temp);
        remove("grtempo.dat");
        flushall();
        fflush(stdin);
        del_not_found();
    }
}
////////////End Delete Function//////////

////////// Begin Report Function ////////
void report()
{
    struct phone
    {
        char name[30], address[50];
        char ph[30], mob[30];
    };
    struct phone p;
    int not_all, y = 7, TOTAL_RECORDS = 0, CHECK_RECORD = 1;
    FILE *tel;
    tel = fopen("grtel.dat", "rb");
    cleardevice();
    if (tel == NULL)
    {
        alert();
        closegraph();
        main();
    }
    flushall();
    while (fread(&p, sizeof(p), 1, tel) == 1)
    {
        TOTAL_RECORDS++;
    }
    fclose(tel);
    /////////////////////////////
    tel = fopen("grtel.dat", "rb"); /// Again Open File For Again while loop//
    ////////////////////////////
    flushall();
    while (fread(&p, sizeof(p), 1, tel) == 1)
    {
        setcolor(WHITE);
        settextstyle(3, 0, 2);
        outtextxy(250, 5, "ELECTRIFY");
        line(200, 5, 200, 68);
        gotoxy(5, 3);
        printf("Total Record(s). %d", TOTAL_RECORDS);
        line(218, 35, 400, 35);
        outtextxy(220, 40, "Display All Option");
        line(5, 68, 630, 68);
        ////// "y" took so increase y axis Value mean swap for "\n"
        rectangle(5, 5, 630, 450);
        gotoxy(10, y);
        printf("* Record %d.", CHECK_RECORD);
        y++;
        gotoxy(10, y);
        printf("Name == %s.", p.name);
        y++;
        gotoxy(10, y);
        printf("Phone No.== %s", p.ph);
        y++;
        gotoxy(10, y);
        printf("Mobile No.== %s", p.mob);
        y++;
        gotoxy(10, y);
        printf("Address:==  %s", p.address);
        y++;
        gotoxy(10, y);
        printf("-------------------------------------------------------------");
        y++;
        not_all = getch();
        fflush(stdout);
        CHECK_RECORD++;
        //////////////
        if (y > 19)
        {
            cleardevice(); /// if screen full shows on 1,1 axix..Electrify...
            y = 7;
        }
        if (not_all == 27) // If user do not want to whatch all report so press ESC.
        {
            goto pass_others;
        }
        ///////////////
    } // while loop End
pass_others:
    gotoxy(10, 21);
    printf("*******************");
    gotoxy(10, 22);
    printf("Total Record(s) %d.", TOTAL_RECORDS);
    gotoxy(10, 23);
    printf("*******************");
    gotoxy(10, 25);
    printf("Press any key to main menu...");
    getch();
    fflush(stdout);
    fclose(tel);
    closegraph();
    main();
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
void alert()
{
    int a;
    ///// Gray box Back /////
    setfillstyle(1, LIGHTGRAY);
    bar(130, 150, 490, 250);
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(130, 151, 490, 167);
    settextstyle(2, 0, 4);
    setcolor(WHITE);
    outtextxy(133, 152, "Electrify...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(130, 149, 490, 149); // Up Line ///
    line(129, 150, 129, 250); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(130, 252, 490, 252); //////Down Line //////
    line(490, 149, 490, 251); ////For Write Line/////
    //////// Message ///////////
    // settextstyle(2,0,4);  // if need Editing Message size///
    setcolor(1);
    outtextxy(195, 177, "Can't open File...");
    outtextxy(195, 188, "Please Create Data File... ");
    outtextxy(195, 199, "Very simple choose option 1 and add any record...");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 13; a++)
    {
        setcolor(8);
        circle(159, 193, a);
    }
    for (a = 1; a <= 13; a++)
    {
        setcolor(RED);
        circle(157, 191, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(150, 185, "X");
    /////////////////////
    ///// OK Button /////
    setfillstyle(1, LIGHTGRAY);
    bar(265, 223, 325, 243);
    /////// Lines for OK Button ////////
    setcolor(WHITE);
    line(264, 222, 325, 222); // Up Line ///
    line(264, 223, 264, 242); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(265, 243, 325, 243); //////Down Line //////
    line(326, 223, 326, 243); //  for Right line
    /////////////////////
    //// Write OK on Button //////
    settextstyle(0, 0, 1);
    outtextxy(286, 229, "OK");
    /////////////
    // Up Side Line for showing ok button select///
    settextstyle(2, 0, 4);
    outtextxy(267, 216, "...............");
    //////////
    /// Left Side Line for showing ok button select///
    settextstyle(2, 1, 4);
    outtextxy(258, 224, "....");
    /////////
    // Down Side Line for showing ok button select///
    settextstyle(2, 0, 4);
    outtextxy(267, 232, "...............");
    ////////
    // Right Side Line for showing ok button select///
    settextstyle(2, 1, 4);
    outtextxy(315, 224, "....");
    //////////////////////
    getch();
}
//////////////////////////
///////////// Invalid Key /////////////////
void invalid()
{
    int a;
    setcolor(WHITE);
    settextstyle(2, 0, 4);
    ///// Gray box Back /////
    setfillstyle(1, LIGHTGRAY);
    bar(130, 150, 490, 250);
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(130, 151, 490, 167);
    outtextxy(133, 152, "Invalid Key...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(130, 149, 490, 149); // Up Line ///
    line(129, 150, 129, 250); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(130, 250, 490, 250); //////Down Line //////
    line(490, 149, 490, 251); ////For White Line/////
    //////// Message ///////////
    // settextstyle(2,0,4);  // if need Editing Message size///
    setcolor(1);
    outtextxy(210, 177, "Type 1 to 5...");
    outtextxy(210, 190, "For Entering Menu... ");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 13; a++)
    {
        setcolor(8);
        circle(159, 193, a);
    }
    for (a = 1; a <= 13; a++)
    {
        setcolor(RED);
        circle(157, 191, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(150, 185, "X");
    /////////////////////
    ///// OK Button /////
    setfillstyle(1, LIGHTGRAY);
    bar(265, 223, 325, 243);
    /////// Lines for OK Button ////////
    setcolor(WHITE);
    line(264, 222, 325, 222); // Up Line ///
    line(264, 223, 264, 242); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(265, 243, 325, 243); //////Down Line //////
    line(326, 223, 326, 243); //  for Right line
    /////////////////////
    settextstyle(0, 0, 1);
    outtextxy(286, 229, "OK");
    setlinestyle(1, 0, 1);
    rectangle(267, 225, 323, 240);
    getch();
    setlinestyle(0, 0, 1);
    cleardevice();
}

///////////////////////////////////////////////
// Can not Find
////////////////////
void notfind()
{
    int a, select, sh = 1, option;
    setfillstyle(1, LIGHTGRAY);
    bar(200, 150, 380, 270); /// x==180  y== 20
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(200, 151, 380, 167);
    settextstyle(11, 0, 1);
    outtextxy(202, 155, "Can't found...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(200, 149, 380, 149); // Up Line ///
    line(199, 150, 199, 270); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(200, 271, 380, 271); //////Down Line //////
    line(380, 149, 380, 271); ////For Right Line/////
    //////// Message ///////////
    setcolor(1);
    settextstyle(2, 0, 4); // if need Editing Message size///
    outtextxy(250, 177, "Record not Found...");
    outtextxy(250, 190, "Try Again...");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 10; a++)
    {
        setcolor(8);
        circle(215, 184, a); /// 40 difference
    }
    for (a = 1; a <= 10; a++)
    {
        setcolor(RED);
        circle(213, 182, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(207, 176, "X");
    //////////////////////////////// Box Complete ///////
    goto lw;

    while ((select = getch()) != '\r')
    {
        option = select;
    ///////////////////////////////////////////////////
    //          Retry Button   //////////////
    lw:
        ////// Retry Button///////////
        setfillstyle(1, LIGHTGRAY);
        bar(220, 240, 280, 260);
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(220, 240, 280, 240); // Up Line ///
        line(220, 240, 220, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(220, 260, 280, 260); //////Down Line //////
        line(280, 240, 280, 260); //  for Right line
        /////////////////////
        //// Write "Retry" on Button //////
        settextstyle(0, 0, 1);
        outtextxy(230, 246, "Retry");
        /////////////

        /////////////Retry Complete/////////

        ////////////////////////////////////////////////
        ///// Cancel Button /////
        setfillstyle(1, LIGHTGRAY);
        bar(290, 240, 350, 260); ////////  Y==20;  X==60
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(290, 240, 350, 240); // Up Line ///
        line(290, 240, 290, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(290, 260, 350, 260); //////Down Line //////
        line(350, 240, 350, 260); //  for Right line
        /////////////////////
        //// Write OK on Button //////               // Left 75/// Right==77//
        settextstyle(0, 0, 1);
        outtextxy(296, 246, "Cancel");
        /////////////
        //////////////////////

        if (sh == 1) /// For Already Select "Retry" option first time //////
        {
            option = 75;
            sh++;
        }
        switch (option)
        {
        case 77: ////////Cancel
            setlinestyle(1, 0, 0);
            rectangle(293, 243, 347, 257);
            setlinestyle(0, 0, 0);
            break;
            ///////// Retry /// Left
        case 75:
            setlinestyle(1, 0, 0);
            rectangle(223, 243, 277, 257);
            setlinestyle(0, 0, 0);
            break;
        }
    }
    if (option == 77)
    {
        closegraph();
        main();
    }
    else if (option == 75)
        find();
    else
        find();
} // while Loop End
/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//////////////MORE ADD
///////////////////////////////////
void moreadd()
{
    int a, select, sh = 1, option;
    setfillstyle(1, LIGHTGRAY);
    bar(200, 150, 420, 270); /// x==180  y== 20
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(200, 151, 420, 167);
    setcolor(WHITE);
    settextstyle(11, 0, 1);
    outtextxy(202, 155, "Add More...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(200, 149, 420, 149); // Up Line ///
    line(199, 150, 199, 270); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(200, 271, 420, 271); //////Down Line //////
    line(420, 149, 420, 271); ////For Right Line/////
    //////// Message ///////////
    setcolor(1);
    settextstyle(2, 0, 4); // if need Editing Message size///
    outtextxy(240, 177, "Record Successfuly saved.");
    outtextxy(240, 190, "Add more...");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 10; a++)
    {
        setcolor(8);
        circle(215, 184, a); /// 40 difference
    }
    for (a = 1; a <= 10; a++)
    {
        setcolor(GREEN);
        circle(213, 182, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(207, 176, "!");
    //////////////////////////////// Box Complete ///////
    goto lw;

    while ((select = getch()) != '\r')
    {

        option = select;

    lw:
        ////// Retry Button///////////
        setfillstyle(1, LIGHTGRAY);
        bar(220, 240, 280, 260);
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(220, 240, 280, 240); // Up Line ///
        line(220, 240, 220, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(220, 260, 280, 260); //////Down Line //////
        line(280, 240, 280, 260); //  for Right line
        /////////////////////
        //// Write "Retry" on Button //////
        settextstyle(0, 0, 1);
        outtextxy(235, 246, "Add +");
        ///// Cancel Button /////
        setfillstyle(1, LIGHTGRAY);
        bar(330, 240, 390, 260); ////////  Y==20;  X==60
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(330, 240, 390, 240); // Up Line ///
        line(330, 240, 330, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(330, 260, 390, 260); //////Down Line //////
        line(390, 240, 390, 260); //  for Right line
        /////////////////////
        //// Write OK on Button //////               // Left 75/// Right==77//
        settextstyle(0, 0, 1);
        outtextxy(350, 246, "No");
        /////////////
        //////////////////////

        if (sh == 1) /// For Already Select "Retry" option first time //////
        {
            option = 75;
            sh++;
        }
        switch (option)
        {
        case 77: ////////Cancel
            setlinestyle(1, 0, 0);
            rectangle(333, 243, 387, 257);
            setlinestyle(0, 0, 0);
            break;
            ///////// Retry /// Left
        case 75:
            setlinestyle(1, 0, 0);
            rectangle(223, 243, 277, 257);
            setlinestyle(0, 0, 0);
            break;
        }
    }
    if (option == 77)
    {
        closegraph();
        main();
    }
    if (option == 75)
        add();
} // while Loop End
/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////// Not Correct Name //////////

void wrong_name()
{
    int a;
    setcolor(WHITE);
    settextstyle(2, 0, 4);
    ///// Gray box Back /////
    setfillstyle(1, LIGHTGRAY);
    bar(130, 150, 490, 250);
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(130, 151, 490, 167);
    outtextxy(133, 152, "Invalid Name...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(130, 149, 490, 149); // Up Line ///
    line(129, 150, 129, 250); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(130, 252, 490, 252); //////Down Line //////
    line(490, 149, 490, 251); ////For Write Line/////
    //////// Message ///////////
    // settextstyle(2,0,4);  // if need Editing Message size///
    setcolor(1);
    outtextxy(210, 177, "Type Correct Name...");
    outtextxy(210, 190, "because any problem not occur in finding... ");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 13; a++)
    {
        setcolor(8);
        circle(159, 193, a);
    }
    for (a = 1; a <= 13; a++)
    {
        setcolor(RED);
        circle(157, 191, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(150, 185, "X");
    /////////////////////
    ///// OK Button /////
    setfillstyle(1, LIGHTGRAY);
    bar(265, 223, 325, 243);
    /////// Lines for OK Button ////////
    setcolor(WHITE);
    line(264, 222, 325, 222); // Up Line ///
    line(264, 223, 264, 242); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(265, 243, 325, 243); //////Down Line //////
    line(326, 223, 326, 243); //  for Right line
    /////////////////////
    settextstyle(0, 0, 1);
    outtextxy(286, 229, "OK");
    settextstyle(2, 0, 4);
    outtextxy(267, 216, "...............");
    settextstyle(2, 1, 4);
    outtextxy(258, 224, "....");
    settextstyle(2, 0, 4);
    outtextxy(267, 232, "...............");
    settextstyle(2, 1, 4);
    outtextxy(315, 224, "....");
    getch();
    add();
    cleardevice();
}
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

void more_del()
{
    int a, select, sh = 1, option;
    setfillstyle(1, LIGHTGRAY);
    bar(200, 150, 420, 270); /// x==180  y== 20
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(200, 151, 420, 167);
    setcolor(WHITE);
    settextstyle(11, 0, 1);
    outtextxy(202, 155, "Delete More...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(200, 149, 420, 149); // Up Line ///
    line(199, 150, 199, 270); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(200, 271, 420, 271); //////Down Line //////
    line(420, 149, 420, 271); ////For Right Line/////
    //////// Message ///////////
    setcolor(1);
    settextstyle(2, 0, 4); // if need Editing Message size///
    outtextxy(240, 177, "Record Successfuly Deleted.");
    outtextxy(240, 190, "Delete more...");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 10; a++)
    {
        setcolor(8);
        circle(215, 184, a); /// 40 difference
    }
    for (a = 1; a <= 10; a++)
    {
        setcolor(GREEN);
        circle(213, 182, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(207, 176, "!");
    //////////////////////////////// Box Complete ///////
    goto lw;

    while ((select = getch()) != '\r')
    {

        option = select;

    lw:
        ////// Retry Button///////////
        setfillstyle(1, LIGHTGRAY);
        bar(220, 240, 280, 260);
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(220, 240, 280, 240); // Up Line ///
        line(220, 240, 220, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(220, 260, 280, 260); //////Down Line //////
        line(280, 240, 280, 260); //  for Right line
        /////////////////////
        //// Write "Retry" on Button //////
        settextstyle(0, 0, 1);
        outtextxy(235, 246, "Del +");
        ///// Cancel Button /////
        setfillstyle(1, LIGHTGRAY);
        bar(330, 240, 390, 260); ////////  Y==20;  X==60
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(330, 240, 390, 240); // Up Line ///
        line(330, 240, 330, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(330, 260, 390, 260); //////Down Line //////
        line(390, 240, 390, 260); //  for Right line
        /////////////////////
        //// Write OK on Button //////               // Left 75/// Right==77//
        settextstyle(0, 0, 1);
        outtextxy(350, 246, "No");
        /////////////
        //////////////////////

        if (sh == 1) /// For Already Select "Retry" option first time //////
        {
            option = 75;
            sh++;
        }
        switch (option)
        {
        case 77: ////////Cancel
            setlinestyle(1, 0, 0);
            rectangle(333, 243, 387, 257);
            setlinestyle(0, 0, 0);
            break;
            ///////// Retry /// Left
        case 75:
            setlinestyle(1, 0, 0);
            rectangle(223, 243, 277, 257);
            setlinestyle(0, 0, 0);
            break;
        }
    }
    if (option == 77)
    {
        closegraph();
        main();
    }
    else if (option == 75)
        del();
    else
        del();
} // while Loop End
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
void del_not_found()
{
    int a, select, sh = 1, option;
    setfillstyle(1, LIGHTGRAY);
    bar(200, 150, 380, 270); /// x==180  y== 20
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(200, 151, 380, 167);
    settextstyle(11, 0, 1);
    outtextxy(202, 155, "Can't Delete...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(200, 149, 380, 149); // Up Line ///
    line(199, 150, 199, 270); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(200, 271, 380, 271); //////Down Line //////
    line(380, 149, 380, 271); ////For Right Line/////
    //////// Message ///////////
    setcolor(1);
    settextstyle(2, 0, 4); // if need Editing Message size///
    outtextxy(250, 177, "Record not exist...");
    outtextxy(250, 190, "Try Again...");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 10; a++)
    {
        setcolor(8);
        circle(215, 184, a); /// 40 difference
    }
    for (a = 1; a <= 10; a++)
    {
        setcolor(RED);
        circle(213, 182, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(207, 176, "X");
    //////////////////////////////// Box Complete ///////
    goto lw;

    while ((select = getch()) != '\r')
    {
        option = select;
    ///////////////////////////////////////////////////
    //          Retry Button   //////////////
    lw:
        ////// Retry Button///////////
        setfillstyle(1, LIGHTGRAY);
        bar(220, 240, 280, 260);
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(220, 240, 280, 240); // Up Line ///
        line(220, 240, 220, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(220, 260, 280, 260); //////Down Line //////
        line(280, 240, 280, 260); //  for Right line
        /////////////////////
        //// Write "Retry" on Button //////
        settextstyle(0, 0, 1);
        outtextxy(230, 246, "Retry");
        /////////////

        /////////////Retry Complete/////////

        ////////////////////////////////////////////////
        ///// Cancel Button /////
        setfillstyle(1, LIGHTGRAY);
        bar(290, 240, 350, 260); ////////  Y==20;  X==60
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(290, 240, 350, 240); // Up Line ///
        line(290, 240, 290, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(290, 260, 350, 260); //////Down Line //////
        line(350, 240, 350, 260); //  for Right line
        /////////////////////
        //// Write OK on Button //////               // Left 75/// Right==77//
        settextstyle(0, 0, 1);
        outtextxy(296, 246, "Cancel");
        /////////////
        //////////////////////

        if (sh == 1) /// For Already Select "Retry" option first time //////
        {
            option = 75;
            sh++;
        }
        switch (option)
        {
        case 77: ////////Cancel
            setlinestyle(1, 0, 0);
            rectangle(293, 243, 347, 257);
            setlinestyle(0, 0, 0);
            break;
            ///////// Retry /// Left
        case 75:
            setlinestyle(1, 0, 0);
            rectangle(223, 243, 277, 257);
            setlinestyle(0, 0, 0);
            break;
        }
    }
    if (option == 77)
    {
        closegraph();
        main();
    }
    else if (option == 75)
        del();
    else
        del();
} // while Loop End
/////////////////////////////////////////////////////////////////////

void find_more()
{
    int a, select, sh = 1, option;
    setfillstyle(1, LIGHTGRAY);
    bar(200, 150, 420, 270); /// x==180  y== 20
    ///// Blue Title /////
    setfillstyle(1, BLUE);
    bar(200, 151, 420, 167);
    setcolor(WHITE);
    settextstyle(11, 0, 1);
    outtextxy(202, 155, "Find More...");
    ///////// Lines ///////////
    setcolor(WHITE);
    line(200, 149, 420, 149); // Up Line ///
    line(199, 150, 199, 270); /// For left White line ///////
    setcolor(8);              /// Black color//
    line(200, 271, 420, 271); //////Down Line //////
    line(420, 149, 420, 271); ////For Right Line/////
    //////// Message ///////////
    setcolor(1);
    settextstyle(2, 0, 4); // if need Editing Message size///
    outtextxy(240, 177, "Do you want to find more...");
    outtextxy(240, 190, "Find more...");
    /////////////////////////////
    ///// Icon /////
    for (a = 1; a <= 10; a++)
    {
        setcolor(8);
        circle(215, 184, a); /// 40 difference
    }
    for (a = 1; a <= 10; a++)
    {
        setcolor(GREEN);
        circle(213, 182, a);
    }
    setcolor(WHITE);
    settextstyle(0, 0, 2);
    outtextxy(207, 176, "!");
    //////////////////////////////// Box Complete ///////
    goto lw;

    while ((select = getch()) != '\r')
    {

        option = select;

    lw:
        ////// Retry Button///////////
        setfillstyle(1, LIGHTGRAY);
        bar(220, 240, 280, 260);
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(220, 240, 280, 240); // Up Line ///
        line(220, 240, 220, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(220, 260, 280, 260); //////Down Line //////
        line(280, 240, 280, 260); //  for Right line
        /////////////////////
        //// Write "Retry" on Button //////
        settextstyle(0, 0, 1);
        outtextxy(230, 246, "Find +");
        ///// Cancel Button /////
        setfillstyle(1, LIGHTGRAY);
        bar(330, 240, 390, 260); ////////  Y==20;  X==60
        /////// Lines for OK Button ////////
        setcolor(WHITE);
        line(330, 240, 390, 240); // Up Line ///
        line(330, 240, 330, 260); /// For left White line ///////
        setcolor(8);              /// Black color//
        line(330, 260, 390, 260); //////Down Line //////
        line(390, 240, 390, 260); //  for Right line
        /////////////////////
        //// Write OK on Button //////               // Left 75/// Right==77//
        settextstyle(0, 0, 1);
        outtextxy(350, 246, "No");
        /////////////
        //////////////////////

        if (sh == 1) /// For Already Select "Retry" option first time //////
        {
            option = 75;
            sh++;
        }
        switch (option)
        {
        case 77: ////////Cancel
            setlinestyle(1, 0, 0);
            rectangle(333, 243, 387, 257);
            setlinestyle(0, 0, 0);
            break;
            ///////// Retry /// Left
        case 75:
            setlinestyle(1, 0, 0);
            rectangle(223, 243, 277, 257);
            setlinestyle(0, 0, 0);
            break;
        }
    }
    if (option == 77)
    {
        closegraph();
        main();
    }
    else if (option == 75)
        find();
    else
        find();
} // while Loop End
//////////////////////////////////////////////////////
void help(void)
{
    cleardevice();
    setbkcolor(1);
    setcolor(WHITE);
    rectangle(2, 2, 633, 475);
    line(2, 440, 633, 440);
    outtextxy(200, 10, "Welcome to Help Menu");
    getch();
    main();
}
