Home Blog Topics Sitemap
MYCPLUS - C and C++ Programming Resources
TUTORIALS
SOURCE CODE
DOWNLOADS
BOOKS
VIDEOS
NEWS
Telephone Directory Program in C
Posted by M. Saqib | Updated Feb 22, 2020 | C Programming Source Code |     

This is telephone directory program written in C and uses BGI Graphics to display data. The program takes Name, Phone Number, Mobile Number, Address and saves it in newly created file.

The program also shows saved record on screen. User can find and delete the records too.

Zeeshan Ahmed from Mirpurkhas, pakistan.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
182
183
184
185
186
187
188
189
190
191
192
193
194
195
196
197
198
199
200
201
202
203
204
205
206
207
208
209
210
211
212
213
214
215
216
217
218
219
220
221
222
223
224
225
226
227
228
229
230
231
232
233
234
235
236
237
238
239
240
241
242
243
244
245
246
247
248
249
250
251
252
253
254
255
256
257
258
259
260
261
262
263
264
265
266
267
268
269
270
271
272
273
274
275
276
277
278
279
280
281
282
283
284
285
286
287
288
289
290
291
292
293
294
295
296
297
298
299
300
301
302
303
304
305
306
307
308
309
310
311
312
313
314
315
316
317
318
319
320
321
322
323
324
325
326
327
328
329
330
331
332
333
334
335
336
337
338
339
340
341
342
343
344
345
346
347
348
349
350
351
352
353
354
355
356
357
358
359
360
361
362
363
364
365
366
367
368
369
370
371
372
373
374
375
376
377
378
379
380
381
382
383
384
385
386
387
388
389
390
391
392
393
394
395
396
397
398
399
400
401
402
403
404
405
406
407
408
409
410
411
412
413
414
415
416
417
418
419
420
421
422
423
424
425
426
427
428
429
430
431
432
433
434
435
436
437
438
439
440
441
442
443
444
445
446
447
448
449
450
451
452
453
454
455
456
457
458
459
460
461
462
463
464
465
466
467
468
469
470
471
472
473
474
475
476
477
478
479
480
481
482
483
484
485
486
487
488
489
490
491
492
493
494
495
496
497
498
499
500
501
502
503
504
505
506
507
508
509
510
511
512
513
514
515
516
517
518
519
520
521
522
523
524
525
526
527
528
529
530
531
532
533
534
535
536
537
538
539
540
541
542
543
544
545
546
547
548
549
550
551
552
553
554
555
556
557
558
559
560
561
562
563
564
565
566
567
568
569
570
571
572
573
574
575
576
577
578
579
580
581
582
583
584
585
586
587
588
589
590
591
592
593
594
595
596
597
598
599
600
601
602
603
604
605
606
607
608
609
610
611
612
613
614
615
616
617
618
619
620
621
622
623
624
625
626
627
628
629
630
631
632
633
634
635
636
637
638
639
640
641
642
643
644
645
646
647
648
649
650
651
652
653
654
655
656
657
658
659
660
661
662
663
664
665
666
667
668
669
670
671
672
673
674
675
676
677
678
679
680
681
682
683
684
685
686
687
688
689
690
691
692
693
694
695
696
697
698
699
700
701
702
703
704
705
706
707
708
709
710
711
712
713
714
715
716
717
718
719
720
721
722
723
724
725
726
727
728
729
730
731
732
733
734
735
736
737
738
739
740
741
742
743
744
745
746
747
748
749
750
751
752
753
754
755
756
757
758
759
760
761
762
763
764
765
766
767
768
769
770
771
772
773
774
775
776
777
778
779
780
781
782
783
784
785
786
787
788
789
790
791
792
793
794
795
796
797
798
799
800
801
802
803
804
805
806
807
808
809
810
811
812
813
814
815
816
817
818
819
820
821
822
823
824
825
826
827
828
829
830
831
832
833
834
835
836
837
838
839
840
841
842
843
844
845
846
847
848
849
850
851
852
853
854
855
856
857
858
859
860
861
862
863
864
865
866
867
868
869
870
871
872
873
874
875
876
877
878
879
880
881
882
883
884
885
886
887
888
889
890
891
892
893
894
895
896
897
898
899
900
901
902
903
904
905
906
907
908
909
910
911
912
913
914
915
916
917
918
919
920
921
922
923
924
925
926
927
928
929
930
931
932
933
934
935
936
937
938
939
940
941
942
943
944
945
946
947
948
949
950
951
952
953
954
955
956
957
958
959
960
961
962
963
964
965
966
967
968
969
970
971
972
973
974
975
976
977
978
979
980
981
982
983
984
985
986
987
988
989
990
991
992
993
994
995
996
997
998
999
1000
1001
1002
1003
1004
1005
1006
1007
1008
1009
1010
1011
1012
1013
1014
1015
1016
1017
1018
1019
1020
1021
1022
1023
1024
1025
1026
1027
1028
1029
1030
1031
1032
1033
1034
1035
1036
1037
1038
1039
1040
1041
1042
1043
1044
1045
1046
1047
1048
1049
1050
1051
1052
1053
1054
1055
1056
1057
1058
1059
1060
1061
1062
1063
1064
1065
1066
1067
1068
1069
1070
1071
1072
1073
1074
1075
1076
1077
1078
1079
1080
1081
1082
1083
1084
1085
1086
1087
1088
1089
1090
1091
1092
1093
1094
1095
1096
1097
1098
1099
1100
1101
1102
1103
1104
//Made by Zeeshan Ahmed /////////
 
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<io.h>
//////////////////
///Basic Functions//
//////////////////
void add(void);
void report(void);
void find(void);
void del(void);
///////////////////
//Message Functions//
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
 int gd=0,gm,errorcode;
 closegraph();
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 errorcode = graphresult();
 if (errorcode != grOk)  /* an error occurred */
  {
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);             /* return with error code */
  }
 int choice;
 invalid_key:
 cleardevice();
 setbkcolor(1);
 setcolor(WHITE);
 rectangle(2,2,633,475);
 line(2,405,633,405);
 setfillstyle(1,1);
 bar(170,30,450,57);
 settextstyle(2,0,7);
 outtextxy(70,410,"Made by Zeeshan Ahmed... [ Electrify (EF) ]");
 line(2,440,633,440);
 settextstyle(2,0,5);
 outtextxy(5,450,"web : www.tehseenwd.4t.com * E-mail: zeeshanwon@yahoo.com *  Mob: 0304-2615105");
 settextstyle(8,0,2);
 setcolor(11);
 rectangle(170,30,450,63);
 outtextxy(190,30,"TELEPHONE INDEX 1.0");
 setcolor(7);         ////White Color for Lines ////
 line(170,79,450,79);    // Up line
 line(169,80,169,390);   // Left Line
 setcolor(8);	        //	Black color
 line(170,392,450,392);  //    Down Line
 line(452,79,452,390);  //   Right Line
 setfillstyle(1,6);
 bar(170,80,450,390);
 settextstyle(2,0,6);
 setcolor(WHITE);
 
  setfillstyle(9,8);
  bar(225,350,300,370);
 
 outtextxy(180,120,"1.  Add New Record");
 outtextxy(180,160,"2.  Find Record");
 outtextxy(180,200,"3.  Display All Records");
 outtextxy(180,240,"4.  Delete Record");
 outtextxy(180,290,"5.  Exit Program");
 gotoxy(30,23);scanf("%1d",&choice);
 fflush(stdin);  //flush the input stream in case of bad input //
 switch(choice)
  {
   case 1:
   add();break;
   case 2:
   find();break;
   case 3:
   report();break;
   case 4:
   del();break;
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
//Add Function Begin///////////
 
void add()
 {
 struct phone
 {
 char name[30],address[50];
 char ph[30],mob[30];
 };
 struct phone p;
 int g=0;
 FILE *tel;
 tel=fopen("grtel.dat","ab");
 cleardevice();
 if(tel==NULL)
 {
 fclose(tel);
 alert();
 exit(0);
 }
  fflush(stdin);
  setcolor(WHITE);
  line(200,5,200,68);
  gotoxy(2,3);printf("Type \"exit\" for cancel.");
  settextstyle(3,0,2);
  outtextxy(250,5,"ELECTRIFY");
  line(218,35,400,35);
  outtextxy(220,40,"Adding Records");
  line(5,68,630,68);
  rectangle(5,5,630,450);
  gotoxy(10,6);printf("Enter Name:? ");
  gets(p.name);
  if(stricmp(p.name,"exit")==0)
    {
    fclose(tel);
    closegraph();
    main();
    }
////////////////////// Check The Name Is that "String" /////////////////
  while(p.name[g]!='\0')
   {
   if( (p.name[g]>=65 && p.name[g]<=90) || (p.name[g]>=97 && p.name[g]<=122) || (p.name[g]==32 || p.name[g]==46) ) g++; else { fclose(tel); wrong_name(); } } ////////////////////////////////////////////////////////////// gotoxy(10,8);printf("Enter Phone No:? "); gets(p.ph); if(stricmp(p.ph,"exit")==0) { fclose(tel); closegraph(); main(); } gotoxy(10,10);printf("Enter Mobile No:? "); gets(p.mob); if(stricmp(p.mob,"exit")==0) { fclose(tel); closegraph(); main(); } gotoxy(10,12);printf("Enter Address:? "); gets(p.address); if(stricmp(p.address,"exit")==0) { fclose(tel); closegraph(); main(); } fwrite(&p,sizeof(p),1,tel); fflush(stdin); fclose(tel); moreadd(); } ////////////End Add function////////////////////////// //Begin Find Funtion/////////////////// void find() { struct phone { char name[30],address[50]; char ph[30],mob[30]; }; struct phone p; char search[25]; int cl=0,CHECK_RECORD=1,TOTAL_FOUND=0; int rec=0,y=7; FILE *tel; tel=fopen("grtel.dat","rb"); cleardevice(); if(tel==NULL) { fclose(tel); alert(); //// Alert Message like windows/// closegraph(); main(); } flushall(); cleardevice(); setcolor(WHITE); rectangle(2,2,633,475); settextstyle(2,0,6); setcolor(WHITE); rectangle(5,295,200,330); gotoxy(2,20);printf("Type \"exit\" for cancel."); outtextxy(10,10,"Enter Name for Searching:?"); settextstyle(1,0,4); outtextxy(10,350,"Searching option... EF (TTLC)"); setfillstyle(1,8); bar(6,45,200,70); gotoxy(3,4);gets(search); if(stricmp(search,"exit")==0) { fclose(tel); closegraph(); main(); } flushall(); while(fread(&p,sizeof(p),1,tel)==1) { if(stricmp(p.name,search)==0) { TOTAL_FOUND++; } } fclose(tel); flushall(); tel=fopen("grtel.dat","rb"); while(fread(&p,sizeof(p),1,tel)==1) { if(stricmp(p.name,search)==0) { cl++; if(cl==1) { cleardevice(); } cl=0; line(200,5,200,68); gotoxy(3,3);printf("%d Record(s) Found...",TOTAL_FOUND); settextstyle(3,0,2); outtextxy(250,5,"ELECTRIFY"); line(218,35,400,35); outtextxy(220,40,"Search Option"); line(5,68,630,68); ////// "y" took so increase y axis Value mean swap for "\n" rectangle(5,5,630,450); gotoxy(10,y);printf("* Record %d.",CHECK_RECORD); y++; gotoxy(10,y);printf("Name == %s.",p.name); y++; gotoxy(10,y);printf("Phone No.== %s",p.ph); y++; gotoxy(10,y);printf("Mobile No.== %s",p.mob); y++; gotoxy(10,y);printf("Address:== %s",p.address); y++; gotoxy(10,y);printf("-------------------------------------------------------------"); y++; y=7; getch(); CHECK_RECORD++; ////////////// if(y>19)
    {
    cleardevice();  /// if screen full shows on 1,1 axix..Electrify...
    y=7;
    }
  //////////////
       rec=1;
      }
     }
     if(rec==1)
      {
       gotoxy(10,19);printf("Record Updated.");
      }
    else
     {
     flushall();
     fclose(tel);
     notfind(); /// Not Find Message Function box///////
     }
     CHECK_RECORD=1;
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
 char name[30],address[50];
 char ph[30],mob[30];
 };
 struct phone p;
 char del[25];
  int rec=0;
  FILE *tel;
  FILE *temp;
  tel=fopen("grtel.dat","rb");
  temp=fopen("grtempo.dat","ab");
  cleardevice();
  if(tel==NULL)
   {
   fclose(tel);
   fclose(temp);
   alert();
   closegraph();
   main();
   }
    flushall();
    cleardevice();
    settextstyle(2,0,6);
    setcolor(WHITE);
    rectangle(2,2,633,475);
    rectangle(5,295,200,330);
    gotoxy(2,20);printf("Type \"exit\" for cancel.");
    outtextxy(10,10,"Enter Name for Deleting:?");
    settextstyle(1,0,4);
    outtextxy(10,350,"Deleting option... EF (TTLC)");
    setfillstyle(1,8);
    bar(6,45,200,70);
    gotoxy(3,4);gets(del);
     if(stricmp(del,"exit")==0)
      {
       fclose(temp);
       fclose(tel);
       closegraph();
       remove("grtempo.dat");
       main();
      }
  while(fread(&p,sizeof(p),1,tel)==1)
   {
    if(stricmp(del,p.name)!=0)
     fwrite(&p,sizeof(p),1,temp);
    else
     rec=1;
   }
  if(rec==1)
    {
     fclose(tel);
     fclose(temp);
     remove("grtel.dat");
     rename("grtempo.dat","grtel.dat");
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
 char name[30],address[50];
 char ph[30],mob[30];
 };
 struct phone p;
 int not_all,y=7,TOTAL_RECORDS=0,CHECK_RECORD=1;
 FILE *tel;
 tel=fopen("grtel.dat","rb");
 cleardevice();
 if(tel==NULL)
 {
 alert();
 closegraph();
 main();
 }
 flushall();
while(fread(&p,sizeof(p),1,tel)==1)
 {
 TOTAL_RECORDS++;
 }
 fclose(tel);
 /////////////////////////////
 tel=fopen("grtel.dat","rb"); /// Again Open File For Again while loop//
 ////////////////////////////
 flushall();
 while(fread(&p,sizeof(p),1,tel)==1)
  {
  setcolor(WHITE);
  settextstyle(3,0,2);
  outtextxy(250,5,"ELECTRIFY");
  line(200,5,200,68);
  gotoxy(5,3);printf("Total Record(s). %d",TOTAL_RECORDS);
  line(218,35,400,35);
  outtextxy(220,40,"Display All Option");
  line(5,68,630,68);
    ////// "y" took so increase y axis Value mean swap for "\n"
   rectangle(5,5,630,450);
   gotoxy(10,y);printf("* Record %d.",CHECK_RECORD);
   y++;
   gotoxy(10,y);printf("Name == %s.",p.name);
   y++;
   gotoxy(10,y);printf("Phone No.== %s",p.ph);
   y++;
   gotoxy(10,y);printf("Mobile No.== %s",p.mob);
   y++;
   gotoxy(10,y);printf("Address:==  %s",p.address);
   y++;
   gotoxy(10,y);printf("-------------------------------------------------------------");
   y++;
   not_all=getch();
   fflush(stdout);
   CHECK_RECORD++;
  //////////////
   if(y>19)
    {
    cleardevice();  /// if screen full shows on 1,1 axix..Electrify...
    y=7;
    }
    if(not_all==27)//If user do not want to whatch all report so press ESC.
     {
     goto pass_others;
     }
  ///////////////
   }  // while loop End
   pass_others:
   gotoxy(10,21);printf("*******************");
   gotoxy(10,22);printf("Total Record(s) %d.",TOTAL_RECORDS);
   gotoxy(10,23);printf("*******************");
   gotoxy(10,25);printf("Press any key to main menu...");
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
 setfillstyle(1,LIGHTGRAY);
 bar(130,150,490,250);
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(130,151,490,167);
 settextstyle(2,0,4);
 setcolor(WHITE);
 outtextxy(133,152,"Electrify...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(130,149,490,149); // Up Line ///
 line(129,150,129,250); ///For left White line ///////
 setcolor(8); ///Black color//
 line(130,252,490,252);//////Down Line //////
 line(490,149,490,251); ////For Write Line/////
 //////// Message ///////////
 //settextstyle(2,0,4);  // if need Editing Message size///
 setcolor(1);
 outtextxy(195,177,"Can't open File...");
 outtextxy(195,188,"Please Create Data File... ");
 outtextxy(195,199,"Very simple choose option 1 and add any record...");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=13;a++)
  {
  setcolor(8);
  circle(159,193,a);
  }
 for(a=1;a<=13;a++)
  {
  setcolor(RED);
  circle(157,191,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(150,185,"X");
/////////////////////
///// OK Button /////
setfillstyle(1,LIGHTGRAY);
bar(265,223,325,243);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(264,222,325,222); // Up Line ///
line(264,223,264,242); ///For left White line ///////
setcolor(8); ///Black color//
line(265,243,325,243);//////Down Line //////
line(326,223,326,243);	 //  for Right line
/////////////////////
//// Write OK on Button //////
settextstyle(0,0,1);
outtextxy(286,229,"OK");
/////////////
// Up Side Line for showing ok button select///
settextstyle(2,0,4);
outtextxy(267,216,"...............");
//////////
///Left Side Line for showing ok button select///
settextstyle(2,1,4);
outtextxy(258,224,"....");
/////////
//Down Side Line for showing ok button select///
settextstyle(2,0,4);
outtextxy(267,232,"...............");
////////
// Right Side Line for showing ok button select///
settextstyle(2,1,4);
outtextxy(315,224,"....");
//////////////////////
getch();
}
//////////////////////////
///////////// Invalid Key /////////////////
void invalid()
 {
 int a;
 setcolor(WHITE);
 settextstyle(2,0,4);
 ///// Gray box Back /////
 setfillstyle(1,LIGHTGRAY);
 bar(130,150,490,250);
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(130,151,490,167);
 outtextxy(133,152,"Invalid Key...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(130,149,490,149); // Up Line ///
 line(129,150,129,250); ///For left White line ///////
 setcolor(8); ///Black color//
 line(130,250,490,250);//////Down Line //////
 line(490,149,490,251); ////For White Line/////
 //////// Message ///////////
 //settextstyle(2,0,4);  // if need Editing Message size///
 setcolor(1);
 outtextxy(210,177,"Type 1 to 5...");
 outtextxy(210,190,"For Entering Menu... ");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=13;a++)
  {
  setcolor(8);
  circle(159,193,a);
  }
 for(a=1;a<=13;a++)
  {
  setcolor(RED);
  circle(157,191,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(150,185,"X");
/////////////////////
///// OK Button /////
setfillstyle(1,LIGHTGRAY);
bar(265,223,325,243);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(264,222,325,222); // Up Line ///
line(264,223,264,242); ///For left White line ///////
setcolor(8); ///Black color//
line(265,243,325,243);//////Down Line //////
line(326,223,326,243);	 //  for Right line
/////////////////////
settextstyle(0,0,1);
outtextxy(286,229,"OK");
setlinestyle(1,0,1);
rectangle(267,225,323,240);
getch();
setlinestyle(0,0,1);
cleardevice();
}
 
///////////////////////////////////////////////
//Can not Find
////////////////////
void notfind()
{
int a,select,sh=1,option;
setfillstyle(1,LIGHTGRAY);
 bar(200,150,380,270);    /// x==180  y== 20
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(200,151,380,167);
 settextstyle(11,0,1);
 outtextxy(202,155,"Can't found...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(200,149,380,149); // Up Line ///
 line(199,150,199,270); ///For left White line ///////
 setcolor(8); ///Black color//
 line(200,271,380,271);//////Down Line //////
 line(380,149,380,271); ////For Right Line/////
 //////// Message ///////////
 setcolor(1);
 settextstyle(2,0,4);  // if need Editing Message size///
 outtextxy(250,177,"Record not Found...");
 outtextxy(250,190,"Try Again...");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=10;a++)
  {
  setcolor(8);
  circle(215,184,a);    /// 40 difference
  }
 for(a=1;a<=10;a++)
  {
  setcolor(RED);
  circle(213,182,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(207,176,"X");
//////////////////////////////// Box Complete ///////
goto lw;
 
while( (select=getch() )!='\r')
{
option=select;
///////////////////////////////////////////////////
//          Retry Button   //////////////
lw:
////// Retry Button///////////
setfillstyle(1,LIGHTGRAY);
bar(220,240,280,260);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(220,240,280,240); // Up Line ///
line(220,240,220,260); ///For left White line ///////
setcolor(8); ///Black color//
line(220,260,280,260);//////Down Line //////
line(280,240,280,260);	 //  for Right line
/////////////////////
//// Write "Retry" on Button //////
settextstyle(0,0,1);
outtextxy(230,246,"Retry");
/////////////
 
/////////////Retry Complete/////////
 
////////////////////////////////////////////////
///// Cancel Button /////
setfillstyle(1,LIGHTGRAY);
bar(290,240,350,260);          ////////  Y==20;  X==60
/////// Lines for OK Button ////////
setcolor(WHITE);
line(290,240,350,240); // Up Line ///
line(290,240,290,260); ///For left White line ///////
setcolor(8); ///Black color//
line(290,260,350,260);//////Down Line //////
line(350,240,350,260);	 //  for Right line
/////////////////////
//// Write OK on Button //////               // Left 75/// Right==77//
settextstyle(0,0,1);
outtextxy(296,246,"Cancel");
/////////////
//////////////////////
 
if(sh==1) /// For Already Select "Retry" option first time //////
{
option=75;
sh++;
}
switch(option)
 {
case 77:  ////////Cancel
setlinestyle(1,0,0);
rectangle(293,243,347,257);
setlinestyle(0,0,0);
break;
	///////// Retry /// Left
case 75:
setlinestyle(1,0,0);
rectangle(223,243,277,257);
setlinestyle(0,0,0);
break;
 }
}
if(option==77)
 {
 closegraph();
 main();
 }
else if(option==75)
 find();
else
 find();
}  // while Loop End
/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//////////////MORE ADD
///////////////////////////////////
void moreadd()
{
int a,select,sh=1,option;
setfillstyle(1,LIGHTGRAY);
 bar(200,150,420,270);    /// x==180  y== 20
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(200,151,420,167);
 setcolor(WHITE);
 settextstyle(11,0,1);
 outtextxy(202,155,"Add More...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(200,149,420,149); // Up Line ///
 line(199,150,199,270); ///For left White line ///////
 setcolor(8); ///Black color//
 line(200,271,420,271);//////Down Line //////
 line(420,149,420,271); ////For Right Line/////
 //////// Message ///////////
 setcolor(1);
 settextstyle(2,0,4);  // if need Editing Message size///
 outtextxy(240,177,"Record Successfuly saved.");
 outtextxy(240,190,"Add more...");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=10;a++)
  {
  setcolor(8);
  circle(215,184,a);    /// 40 difference
  }
 for(a=1;a<=10;a++)
  {
  setcolor(GREEN);
  circle(213,182,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(207,176,"!");
//////////////////////////////// Box Complete ///////
goto lw;
 
while((select=getch())!='\r')
{
 
option=select;
 
lw:
////// Retry Button///////////
setfillstyle(1,LIGHTGRAY);
bar(220,240,280,260);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(220,240,280,240); // Up Line ///
line(220,240,220,260); ///For left White line ///////
setcolor(8); ///Black color//
line(220,260,280,260);//////Down Line //////
line(280,240,280,260);	 //  for Right line
/////////////////////
//// Write "Retry" on Button //////
settextstyle(0,0,1);
outtextxy(235,246,"Add +");
///// Cancel Button /////
setfillstyle(1,LIGHTGRAY);
bar(330,240,390,260);          ////////  Y==20;  X==60
/////// Lines for OK Button ////////
setcolor(WHITE);
line(330,240,390,240); // Up Line ///
line(330,240,330,260); ///For left White line ///////
setcolor(8); ///Black color//
line(330,260,390,260);//////Down Line //////
line(390,240,390,260);	 //  for Right line
/////////////////////
//// Write OK on Button //////               // Left 75/// Right==77//
settextstyle(0,0,1);
outtextxy(350,246,"No");
/////////////
//////////////////////
 
if(sh==1) /// For Already Select "Retry" option first time //////
{
option=75;
sh++;
}
switch(option)
 {
case 77:  ////////Cancel
setlinestyle(1,0,0);
rectangle(333,243,387,257);
setlinestyle(0,0,0);
break;
	///////// Retry /// Left
case 75:
setlinestyle(1,0,0);
rectangle(223,243,277,257);
setlinestyle(0,0,0);
break;
 }
}
if(option==77)
 {
 closegraph();
 main();
 }
if(option==75)
 add();
}  // while Loop End
/////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
////// Not Correct Name //////////
 
void wrong_name()
 {
 int a;
 setcolor(WHITE);
 settextstyle(2,0,4);
 ///// Gray box Back /////
 setfillstyle(1,LIGHTGRAY);
 bar(130,150,490,250);
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(130,151,490,167);
 outtextxy(133,152,"Invalid Name...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(130,149,490,149); // Up Line ///
 line(129,150,129,250); ///For left White line ///////
 setcolor(8); ///Black color//
 line(130,252,490,252);//////Down Line //////
 line(490,149,490,251); ////For Write Line/////
 //////// Message ///////////
 //settextstyle(2,0,4);  // if need Editing Message size///
 setcolor(1);
 outtextxy(210,177,"Type Correct Name...");
 outtextxy(210,190,"because any problem not occur in finding... ");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=13;a++)
  {
  setcolor(8);
  circle(159,193,a);
  }
 for(a=1;a<=13;a++)
  {
  setcolor(RED);
  circle(157,191,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(150,185,"X");
/////////////////////
///// OK Button /////
setfillstyle(1,LIGHTGRAY);
bar(265,223,325,243);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(264,222,325,222); // Up Line ///
line(264,223,264,242); ///For left White line ///////
setcolor(8); ///Black color//
line(265,243,325,243);//////Down Line //////
line(326,223,326,243);	 //  for Right line
/////////////////////
settextstyle(0,0,1);
outtextxy(286,229,"OK");
settextstyle(2,0,4);
outtextxy(267,216,"...............");
settextstyle(2,1,4);
outtextxy(258,224,"....");
settextstyle(2,0,4);
outtextxy(267,232,"...............");
settextstyle(2,1,4);
outtextxy(315,224,"....");
getch();
add();
cleardevice();
}
//////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
 
 
void more_del()
{
int a,select,sh=1,option;
setfillstyle(1,LIGHTGRAY);
 bar(200,150,420,270);    /// x==180  y== 20
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(200,151,420,167);
 setcolor(WHITE);
 settextstyle(11,0,1);
 outtextxy(202,155,"Delete More...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(200,149,420,149); // Up Line ///
 line(199,150,199,270); ///For left White line ///////
 setcolor(8); ///Black color//
 line(200,271,420,271);//////Down Line //////
 line(420,149,420,271); ////For Right Line/////
 //////// Message ///////////
 setcolor(1);
 settextstyle(2,0,4);  // if need Editing Message size///
 outtextxy(240,177,"Record Successfuly Deleted.");
 outtextxy(240,190,"Delete more...");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=10;a++)
  {
  setcolor(8);
  circle(215,184,a);    /// 40 difference
  }
 for(a=1;a<=10;a++)
  {
  setcolor(GREEN);
  circle(213,182,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(207,176,"!");
//////////////////////////////// Box Complete ///////
goto lw;
 
while((select=getch())!='\r')
{
 
option=select;
 
lw:
////// Retry Button///////////
setfillstyle(1,LIGHTGRAY);
bar(220,240,280,260);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(220,240,280,240); // Up Line ///
line(220,240,220,260); ///For left White line ///////
setcolor(8); ///Black color//
line(220,260,280,260);//////Down Line //////
line(280,240,280,260);	 //  for Right line
/////////////////////
//// Write "Retry" on Button //////
settextstyle(0,0,1);
outtextxy(235,246,"Del +");
///// Cancel Button /////
setfillstyle(1,LIGHTGRAY);
bar(330,240,390,260);          ////////  Y==20;  X==60
/////// Lines for OK Button ////////
setcolor(WHITE);
line(330,240,390,240); // Up Line ///
line(330,240,330,260); ///For left White line ///////
setcolor(8); ///Black color//
line(330,260,390,260);//////Down Line //////
line(390,240,390,260);	 //  for Right line
/////////////////////
//// Write OK on Button //////               // Left 75/// Right==77//
settextstyle(0,0,1);
outtextxy(350,246,"No");
/////////////
//////////////////////
 
if(sh==1) /// For Already Select "Retry" option first time //////
{
option=75;
sh++;
}
switch(option)
 {
 case 77:  ////////Cancel
setlinestyle(1,0,0);
rectangle(333,243,387,257);
setlinestyle(0,0,0);
 break;
	///////// Retry /// Left
 case 75:
setlinestyle(1,0,0);
rectangle(223,243,277,257);
setlinestyle(0,0,0);
 break;
  }
}
if(option==77)
 {
  closegraph();
  main();
 }
else if(option==75)
 del();
else
 del();
}  // while Loop End
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
void del_not_found()
 {
 int a,select,sh=1,option;
 setfillstyle(1,LIGHTGRAY);
 bar(200,150,380,270);    /// x==180  y== 20
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(200,151,380,167);
 settextstyle(11,0,1);
 outtextxy(202,155,"Can't Delete...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(200,149,380,149); // Up Line ///
 line(199,150,199,270); ///For left White line ///////
 setcolor(8); ///Black color//
 line(200,271,380,271);//////Down Line //////
 line(380,149,380,271); ////For Right Line/////
 //////// Message ///////////
 setcolor(1);
 settextstyle(2,0,4);  // if need Editing Message size///
 outtextxy(250,177,"Record not exist...");
 outtextxy(250,190,"Try Again...");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=10;a++)
  {
  setcolor(8);
  circle(215,184,a);    /// 40 difference
  }
 for(a=1;a<=10;a++)
  {
  setcolor(RED);
  circle(213,182,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(207,176,"X");
//////////////////////////////// Box Complete ///////
goto lw;
 
while((select=getch())!='\r')
{
option=select;
///////////////////////////////////////////////////
//          Retry Button   //////////////
lw:
////// Retry Button///////////
setfillstyle(1,LIGHTGRAY);
bar(220,240,280,260);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(220,240,280,240); // Up Line ///
line(220,240,220,260); ///For left White line ///////
setcolor(8); ///Black color//
line(220,260,280,260);//////Down Line //////
line(280,240,280,260);	 //  for Right line
/////////////////////
//// Write "Retry" on Button //////
settextstyle(0,0,1);
outtextxy(230,246,"Retry");
/////////////
 
/////////////Retry Complete/////////
 
////////////////////////////////////////////////
///// Cancel Button /////
setfillstyle(1,LIGHTGRAY);
bar(290,240,350,260);          ////////  Y==20;  X==60
/////// Lines for OK Button ////////
setcolor(WHITE);
line(290,240,350,240); // Up Line ///
line(290,240,290,260); ///For left White line ///////
setcolor(8); ///Black color//
line(290,260,350,260);//////Down Line //////
line(350,240,350,260);	 //  for Right line
/////////////////////
//// Write OK on Button //////               // Left 75/// Right==77//
settextstyle(0,0,1);
outtextxy(296,246,"Cancel");
/////////////
//////////////////////
 
if(sh==1) /// For Already Select "Retry" option first time //////
{
option=75;
sh++;
}
switch(option)
 {
case 77:  ////////Cancel
setlinestyle(1,0,0);
rectangle(293,243,347,257);
setlinestyle(0,0,0);
break;
	///////// Retry /// Left
case 75:
setlinestyle(1,0,0);
rectangle(223,243,277,257);
setlinestyle(0,0,0);
break;
 }
}
if(option==77)
 {
 closegraph();
 main();
 }
else if(option==75)
del();
else
del();
}  // while Loop End
/////////////////////////////////////////////////////////////////////
 
void find_more()
{
int a,select,sh=1,option;
setfillstyle(1,LIGHTGRAY);
 bar(200,150,420,270);    /// x==180  y== 20
 ///// Blue Title /////
 setfillstyle(1,BLUE);
 bar(200,151,420,167);
 setcolor(WHITE);
 settextstyle(11,0,1);
 outtextxy(202,155,"Find More...");
 ///////// Lines ///////////
 setcolor(WHITE);
 line(200,149,420,149); // Up Line ///
 line(199,150,199,270); ///For left White line ///////
 setcolor(8); ///Black color//
 line(200,271,420,271);//////Down Line //////
 line(420,149,420,271); ////For Right Line/////
 //////// Message ///////////
 setcolor(1);
 settextstyle(2,0,4);  // if need Editing Message size///
 outtextxy(240,177,"Do you want to find more...");
 outtextxy(240,190,"Find more...");
 /////////////////////////////
 ///// Icon /////
 for(a=1;a<=10;a++)
  {
  setcolor(8);
  circle(215,184,a);    /// 40 difference
  }
 for(a=1;a<=10;a++)
  {
  setcolor(GREEN);
  circle(213,182,a);
  }
 setcolor(WHITE);
 settextstyle(0,0,2);
 outtextxy(207,176,"!");
//////////////////////////////// Box Complete ///////
goto lw;
 
while((select=getch())!='\r')
{
 
option=select;
 
lw:
////// Retry Button///////////
setfillstyle(1,LIGHTGRAY);
bar(220,240,280,260);
/////// Lines for OK Button ////////
setcolor(WHITE);
line(220,240,280,240); // Up Line ///
line(220,240,220,260); ///For left White line ///////
setcolor(8); ///Black color//
line(220,260,280,260);//////Down Line //////
line(280,240,280,260);	 //  for Right line
/////////////////////
//// Write "Retry" on Button //////
settextstyle(0,0,1);
outtextxy(230,246,"Find +");
///// Cancel Button /////
setfillstyle(1,LIGHTGRAY);
bar(330,240,390,260);          ////////  Y==20;  X==60
/////// Lines for OK Button ////////
setcolor(WHITE);
line(330,240,390,240); // Up Line ///
line(330,240,330,260); ///For left White line ///////
setcolor(8); ///Black color//
line(330,260,390,260);//////Down Line //////
line(390,240,390,260);	 //  for Right line
/////////////////////
//// Write OK on Button //////               // Left 75/// Right==77//
settextstyle(0,0,1);
outtextxy(350,246,"No");
/////////////
//////////////////////
 
if(sh==1) /// For Already Select "Retry" option first time //////
{
option=75;
sh++;
}
switch(option)
 {
case 77:  ////////Cancel
setlinestyle(1,0,0);
rectangle(333,243,387,257);
setlinestyle(0,0,0);
break;
	///////// Retry /// Left
case 75:
setlinestyle(1,0,0);
rectangle(223,243,277,257);
setlinestyle(0,0,0);
break;
 }
}
if(option==77)
 {
 closegraph();
 main();
 }
else if(option==75)
 find();
else
 find();
}  // while Loop End
//////////////////////////////////////////////////////
void help(void)
{
 cleardevice();
 setbkcolor(1);
 setcolor(WHITE);
 rectangle(2,2,633,475);
 line(2,440,633,440);
 outtextxy(200,10,"Welcome to Help Menu");
 getch();
 main();
}
