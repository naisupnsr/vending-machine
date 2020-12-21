#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
void NO(void);

int z=1;
int main()

{
    int i,j,h;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    struct food
    {
        int code;
        char name[100];
        int sellprice;//
        int stock;
        int sale;
    } data[40];


    FILE *intpt,*strpt,*stockpt,*timept;
    char *ch;
    if((intpt=fopen("intdata.txt","r"))==NULL&&(strpt=fopen("strdata.txt","r"))==NULL&&(stockpt=fopen("stocksale.txt","r"))==NULL&&(timept=fopen("timedata.txt","r"))==NULL)
    {
        printf("Error! Can not open file.");
        exit(1);
    }
    intpt=fopen("intdata.txt","r");
    strpt=fopen("strdata.txt","r");
    stockpt=fopen("stocksale.txt","r");


    for (i=0; i<40; i++) /*ลูปสำหรับดึงข้อมูลมาใส่ในstructure*/
    {
        fscanf(intpt, "%d %d", &data[i].code,&data[i].sellprice);
        fscanf(stockpt,"%d %d", &data[i].stock,&data[i].sale);
        fgets(data[i].name,100,strpt);
        if ((ch = strchr(data[i].name,'\n'))!=NULL)
            *ch='\0';


    }
    fclose(stockpt);
    fclose(intpt);
    fclose(strpt);
    /*for (i=0; i<40; i++) //สำหรับเช็คข้อมูลไฟล์ว่ามีผิดพลาดอะไรมั้ย  ไว้เช็คโค้ด ไม่เกี่ยวกับการประมวลผล
    {
        printf("%02d %s %d %d %d\n",data[i].code, data[i].name,data[i].sellprice,data[i].stock,data[i].sale);
    }*/
    int cus_or_sta,start,shop_or_menu,eiei;
start:
    printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
    printf("\t                     WHO ARE YOU ?                  \n\n");
    printf("\t                     1.Customer                      \n\n");
    printf("\t                     2.Staff                         \n\n");
    printf("\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
    printf("                      Please select number: ");
    scanf("%1d",&cus_or_sta);
    if(cus_or_sta==1)
    {
        system("cls");
eiei:
        printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
        printf("\t                    WHAT DO YOU WANT TO DO ?         \n\n");
        printf("\t                    1.Go shopping                    \n\n");
        printf("\t                    2.Go to menu                     \n\n");
        printf("\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
        printf("                      Please select number: ");
        scanf("%1d",&shop_or_menu);
        if (shop_or_menu==1);
        else if(shop_or_menu==2)
        {
            system("cls");
            goto start;
        }
        else

        {
            printf("\n\t             PLEASE TRY AGAIN !\n\t             ");
            system("pause");
            system("cls");
            goto eiei;
        }

        {

            system("cls");
            int t[100],q[100]={0,0},c=1,n,m=0;
            char ask;
            printf("\n\n                                       PlEASE SELECT NUMBER OF PRODUCT                  \n\n");
            printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=||=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\t          Frozen Food <Baht per price>             ||      Beverages <Baht per price>     \n");
            printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=||=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\t  1.Spaghetti white souce <60>                     ||  11.Coca'Cola <15>                  \n");
            printf("\t  2.Gyoza series <32>                              ||  12.Canned coffee <20>              \n");
            printf("\t  3.Chricken green curry  wite rice <40>           ||  13.Spite <15>                      \n");
            printf("\t  4.Teriyaki chricken with rice <45>               ||  14.Fanta <15>                      \n");
            printf("\t  5.Pud Thai <35>                                  ||  15.Milk box <13>                   \n");
            printf("\t  6.Pork fried rice <47>                           ||  16.Mineral water <10>              \n");
            printf("\t  7.Chricken sausage fried rice <30>               ||  17.Full moon <50>                  \n");
            printf("\t  8.Hainanese chicken rice with soup <45>          ||  18.Breezer <50>                    \n");
            printf("\t  9.Noodles <30>                                   ||  19.Smirnoff <40>                   \n");
            printf("\t  10.Pork panang curry with rice <40>              ||  20.Soda <10>                       \n");
            printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=||=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
            printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=||=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\t           Snacks <Baht per price>                 ||     Candies <Baht per price>        \n");
            printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=||=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("\t  21.Lay's <20>                                    ||  31.M&M <30>                        \n");
            printf("\t  22.Cornae <10>                                   ||  32.Hershey's <40>                  \n");
            printf("\t  23.Oreo <5>                                      ||  33.Snicker <25>                    \n");
            printf("\t  24.Pringles <20>                                 ||  34.KitKat <20>                     \n");
            printf("\t  25.Koh-Kae <10>                                  ||  35.Hichew <25>                     \n");
            printf("\t  26.Tao Kae Noi <5>                               ||  36.Dairy milk <25>                 \n");
            printf("\t  27.Hanami <20>                                   ||  37.Haribo <40>                     \n");
            printf("\t  28.Taro <10>                                     ||  38.Crunch <10>                     \n");
            printf("\t  29.Bento <5>                                     ||  39.Mentos <10>                     \n");
            printf("\t  30.Pocky <15>                                    ||  40.Halls <10>                      \n");
            printf("\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=||=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            do
            {
                for(i=0; i<100; i++)
                {
                    m=0;
                    printf("\n\t  Enter number of product %d : ",c);
                    scanf("%d",&t[i]);

                    while(t[i]>40||t[i]<=0)
                    {
                        printf("\t  Error ! Please enter again \n");
                        printf("\t  Enter number of product %d  : ",c);
                        scanf("%d",&t[i]);
                    }
                    for(j=0; j<40; j++)
                    {
                        if (data[j].code==t[i])
                        {
                            if (data[j].stock==0)
                            {
                                printf("\t  Out of stock.(Remain %d piece)\n)",data[j].stock);
                                m=1;
                            }

                        }
                    }

                    if (m==0)//ของไม่หมดถึงมาเข้า
                    {

                        do
                        {
                            n=0;
                            printf("\t  Enter quantity of product number %d (%s) : ",t[i],data[t[i]-1].name);
                            scanf("%d",&q[i]);
                            for(j=0; j<40; j++)
                            {
                                if (data[j].code==t[i])
                                {

                                    if (data[j].stock<q[i])
                                    {
                                        printf("\t  Out of stock.(Remain %d piece)\n)",data[j].stock);
                                        n=1;
                                    }
                                    else data[j].stock=data[j].stock-q[i];

                                }
                            }
                        }
                        while(n>0);//ถ้าจำนวนของที่จะซื้อไม่พอกบจำนวนของในสต็อคให้วนใหม่
                        c++;//นับจำนวนของที่ซื้อในลูป i
                    }
                    else;
                    do
                    {
                        printf("\n\t  Do you want to get more?(Y/N): ");
                        scanf(" %c",&ask);
                        if (ask!='Y'&&ask!='N')
                            printf("\t  Error! Please input 'Y' or 'N' \n");
                    }
                    while (ask!='Y'&&ask!='N');
                    if(ask=='N')
                        break;
                }
            }
            while (ask!='N');

            int price,sum=0,sale;
            for(i=0; i<c; i++)
            {
                for(j=0; j<40; j++)
                {
                    if(data[j].code==t[i])
                    {


                        sale=q[i];
                        data[j].sale =data[j].sale+sale;
                        price = data[j].sellprice*sale;

                        sum = sum+price;

                        timept=fopen("timedata.txt","a");
                        fprintf(timept,"\n%d %d %d %d %d",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900,t[i],q[i]);
                        fclose(timept);
                        stockpt=fopen("stocksale.txt","w");
                        for (h=0; h<40; h++)
                        {
                            fprintf(stockpt,"\n%d %d",data[h].stock,data[h].sale);
                        }
                        fclose(stockpt);
                    }
                }
            }
            int money,change;
            printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
            printf(" \t                   THE TOTAL PRICE : %d                    \n\n ",sum);
            printf("\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
            do
            {
                printf("\t  Enter money (100,50,20,10,5,1): ");
                scanf("\t  %d",&money);
                if(money==100||money==50||money==20||money==10||money==5||money==1)
                {

                    sum -=money;
                    if (sum > 0)
                    {
                        printf("\t  Remain price : %d\n\n",sum);
                    }


                }
                else
                    printf("\t  Error! invalid money\n\n");

            }
            while (sum>0);
            sum = -sum;
            printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=--=-=-=-=-=-=-=-=\n\n");
            printf(" \t               COMPLETE!! CHANGE IS %d BATH               \n\n ",sum);
            printf("\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
            if(sum/100>0)
            {
                printf("\t  100 baht bank note = %d \n",sum/100);
                sum%=100;
            }
            if(sum/50>0)
            {
                printf("\t  50 baht bank note = %d \n",sum/50);
                sum%=50;
            }
            if(sum/20>0)
            {
                printf("\t  20 baht bank note = %d \n",sum/20);
                sum%=20;
            }
            if(sum/10>0)
            {
                printf("\t  10 baht coin = %d \n",sum/10);
                sum%=10;
            }
            if(sum/5>0)
            {
                printf("\t  5 baht coin = %d \n",sum/5);
                sum%=5;
            }
            if(sum>0)
                printf("\t  1 baht coin = %d \n",sum);



        }
        NO();

        char s;
        do
        {
            printf("\n\t  Do you want to exit?(Y/N) : ");
            scanf(" %c",&s);
            if (s!='Y'&&s!='N')
                printf("\n\t  Error! Please input 'Y' or 'N' \n");
        }
        while (s!='Y'&&s!='N');
        if(s=='N')
        {
            system("cls");
            goto start;
        }
        else ;

    }
    else if (cus_or_sta==2)
    {
        int re5;
        system("cls");
re5:
        printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
        printf("\t                    WHAT DO YOU WANT TO DO ?         \n\n");
        printf("\t                    1.Login as staff                    \n\n");
        printf("\t                    2.Go to menu                     \n\n");
        printf("\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
        printf("                      Please select number: ");
        scanf("%1d",&shop_or_menu);
        if (shop_or_menu==1);
        else if(shop_or_menu==2)
        {
            system("cls");
            goto start;
        }
        else

        {
            printf("\n\t             PLEASE TRY AGAIN !\n\t             ");
            system("pause");
            system("cls");
            goto re5;
        }



        char u[4][20]= {"puntara","pojanakorn","passamon","phanusrom"};
        int pass[4]= {296,227,137,136};
        char iu[20];
        int ip,a=0;
        int ag,pst;
        system("cls");
        printf("\n\n\n                             USERNAME : ");
        fflush(stdin);
        gets(iu);

pst:
        for(i=0; i<4; i++)
        {
            if(strcmp(iu,u[i])==0)
            {
                a++;//ตรวจชื่อว่าตรงไหมถ้าตรงก็จะบวก
            }
        }
        while(a==0)
        {
            a=0;

            printf("\n\n\t            WRONG USERNAME ! PLEASE TRY AGAIN\n\t            ");
            system("pause");
            system("cls");
            printf("\n\n\n                             USERNAME : ");
            fflush(stdin);
            gets(iu);
            goto pst;//รับค่าใหม่มาต้องวนไปตรวจอีกที
        }
        a=0;
        printf("\n                             PASSWORD : ");
        scanf("%d",&ip);
ag:
        for(i=0; i<4; i++)
        {
            if(strcmp(iu,u[i])==0)//ตรวจชื่อว่าตรงไหม
            {
                if(ip==pass[i])//ตรวจพาสเวิสว่าตรงไหมกับชื่อนั้นๆ
                {
                    a++;
                }
            }
        }
        while(a==0)
        {
            a=0;
            printf("\n\n\t             WRONG PASSWORD ! PLEASE TRY AGAIN\n\t             ");
            system("pause");
            system("cls");
            printf("\n\n\n                             USERNAME : %s\n\n",&iu );
            printf("                             PASSWORD : ");
            scanf("%d",&ip);
            goto ag;
        }
        int staff_choice,staff;
        char back_to_menu ;
staff:
        system("cls");
        printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
        printf("\t                   WHAT DO YOU WANT TO DO ?                 \n\n");
        printf("\t                    1.Manage stock                          \n\n");
        printf("\t                    2.Show product graph                    \n\n");
        printf("\t                    3.Logout                                \n\n");
        printf("\t                    4.Exit                                  \n\n");
        printf("\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
        printf("                     Please select number: ");
        scanf("%1d",&staff_choice);
        if(staff_choice==1)
        {
            {

                int codestock,oldstock,newstock,check=0;
                char ask,stockname[100],ask2;

                system("cls");
                printf("\n\n\t     NAME \t\t\t      STOCK \n");
                printf("\t  --------------------------------------------\n");
                for (i=0; i<40; i++)
                {
                    printf("\t  %02d %-33s | %-5d \n",data[i].code, data[i].name,data[i].stock);
                }
                printf("\t  --------------------------------------------\n");
                int re3;
                for (i=0; i<40; i++)
                {
                    if (data[i].stock<4&&data[i].stock>0)
                        printf("\t  %02d %s is almost out of stock,Please Fills the stock!\n",data[i].code, data[i].name);
                    else if (data[i].stock==0)
                        printf("\t  %02d %s is out of stock!!!, Please Fills the stock!\n",data[i].code, data[i].name);
                }
re3:
                do
                {
                    printf("\n\t  Do you want to fill stocks? (Y/N) : ");
                    scanf(" %c",&ask);
                    if (ask!='Y'&&ask!='N')
                        printf("\t  Error! Please input 'Y' or 'N' \n\n");
                }
                while (ask!='Y'&&ask!='N');
                if (ask=='Y')
                {
                    do
                    {
                        do
                        {

                            check=0;
                            printf("\n\t  Enter code of product : ");
                            scanf("%d",&codestock);

                            for (i=0; i<40; i++)
                            {
                                if (codestock==data[i].code)
                                {
                                    oldstock=data[i].stock;
                                    strcpy(stockname,data[i].name);
                                    check++;

                                }

                            }
                            if (check!=1)
                                printf("\t  Error! Code does not found! Please input again\n\n");




                        }
                        while(check!=1);

                        do
                        {
                            printf("\t  Enter quantity that you fill (%02d) %s (%d pieces in stock) : ",codestock,stockname,oldstock);
                            scanf("%d",&newstock);
                            if(newstock<0)
                                printf("\t  Error! Please input positive integer\n\n");
                        }
                        while(newstock<0);
                        for (i=0; i<40; i++)
                        {
                            if (codestock==data[i].code)
                            {
                                data[i].stock= data[i].stock+newstock;
                                printf("\n\t  So, (%02d) %s remains %d pieces\n",data[i].code,data[i].name,data[i].stock);
                                stockpt=fopen("stocksale.txt","w");
                                for (h=0; h<40; h++)
                                {
                                    fprintf(stockpt,"\n%d %d",data[h].stock,data[h].sale);
                                }
                                fclose(stockpt);
                            }
                        }
                        do
                        {
                            printf("\n\t  Do you want fill stock of product more? (Y/N) : ");
                            scanf(" %c",&ask2);
                            if (ask2!='Y'&&ask2!='N')
                                printf("\t  Error! Please input 'Y' or 'N' \n\n");
                        }
                        while (ask2!='Y'&&ask2!='N');


                    }
                    while(ask2!='N');


                }
                else;

            }


            int re1,re2;
re1:
            printf("\t  Go back to menu (Y/N) : ");
            scanf(" %c",&back_to_menu);
            if (back_to_menu=='Y')
            {
                goto staff;
            }
            else if(back_to_menu=='N')
                goto re3;
            else
            {
                printf("\t  Error! Please input 'Y' ot 'N' \n\n");
                goto re1;
            }
        }
        else if(staff_choice==2)
        {
            system("cls");
            char choose,ask3;
            struct d
            {
                int day;
                int month;
                int year;
                int salecode;
                int saleday;
                int salemonth;
                int saleyear;
                int saleq;


            } time[40];
            if((timept=fopen("timedata.txt","r"))==NULL)
            {
                printf("Error! Can not open file.");
                exit(1);
            }


            for(i=0; i<40; i++)
            {
                time[i].saleday=0;
                time[i].salemonth=0;
                time[i].saleyear=0;
                timept=fopen("timedata.txt","r");
                while (!feof(timept))
                {
                    fscanf(timept,"%d %d %d %d %d",&time[i].day,&time[i].month,&time[i].year,&time[i].salecode,&time[i].saleq);

                    if ((time[i].day==tm.tm_mday)&&(time[i].month==tm.tm_mon + 1)&&(time[i].year==tm.tm_year + 1900)&&(time[i].salecode==data[i].code))
                    {
                        time[i].saleday=time[i].saleday+time[i].saleq;
                    }
                    if ((time[i].month==tm.tm_mon + 1)&&(time[i].year==tm.tm_year + 1900)&&(time[i].salecode==data[i].code))
                        time[i].salemonth=time[i].salemonth+time[i].saleq;
                    if ((time[i].year==tm.tm_year + 1900)&&(time[i].salecode==data[i].code))
                        time[i].saleyear=time[i].saleyear+time[i].saleq;
                }

                fclose(timept);

            }
            do
            {
                int q;
q:
                system("cls");
                timept=fopen("timedata.txt","r");
                printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                printf("\t     TODAY IS %d/%d/%d",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900);
                printf("\n\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                printf("  \t            NUMBER'S TYPE OF GRAPH THAT YOU WANT\n\n");
                printf("  \t                  1.Today\n\n");
                printf("  \t                  2.This Month\n\n");
                printf("  \t                  3.This year\n\n");
                printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                printf("                      Please select number: ");
                scanf(" %c",&choose);
                if (choose=='1')
                {
                    system("cls");
                    printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                    printf("  \t                        - TODAY -\n");
                    printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                    for (i=0; i<40; i++)
                    {
                        if(time[i].saleday>0)
                        {
                            printf("\t  %02d ||  ",data[i].code);
                            for (j=0; j<time[i].saleday; j++)
                                printf("*");
                            printf("\n");
                        }
                    }
                    printf("\n\t  --------------------------------------------------------\n\n");
                    for (i=0; i<40; i++)
                    {
                        if(time[i].saleday>0)
                        {
                            printf("\t   %02d : %s (%d pieces)",data[i].code,data[i].name,time[i].saleday);
                            printf("\n");
                        }
                    }





                }
                else if (choose=='2')
                {
                    system("cls");
                    printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                    printf("  \t                       - THIS MONTH -\n");
                    printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                    for (i=0; i<40; i++)
                    {
                        if(time[i].salemonth>0)
                        {
                            printf("\t  %02d || ",data[i].code);
                            for (j=0; j<time[i].salemonth; j++)
                                printf("*");
                            printf("\n");
                        }
                    }
                    printf("\n\t  --------------------------------------------------------\n\n");
                    for (i=0; i<40; i++)
                    {
                        if(time[i].salemonth>0)
                        {
                            printf("\t  %02d : %s (%d pieces)",data[i].code,data[i].name,time[i].salemonth);
                            printf("\n");
                        }
                    }


                }
                else if (choose=='3')
                {
                    system("cls");
                    printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                    printf("  \t                       - THIS YEAR -\n");
                    printf("\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n\n");
                    for (i=0; i<40; i++)
                    {
                        if(time[i].saleyear>0)
                        {
                            printf("\t  %02d ||  ",data[i].code);
                            for (j=0; j<time[i].saleyear; j++)
                                printf("*");
                            printf("\n");
                        }
                    }
                    printf("\n\t  --------------------------------------------------------\n\n");
                    for (i=0; i<40; i++)
                    {
                        if(time[i].saleyear>0)
                        {
                            printf("\t  %02d : %s (%d pieces)",data[i].code,data[i].name,time[i].saleyear);
                            printf("\n");
                        }
                    }



                }
                else
                {
                    printf("\n\t             PLEASE TRY AGAIN !\n\t             ");
                    system("pause");
                    system("cls");
                    goto q;
                }
                int abc;
abc:
                printf("\n\n\t  =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=\n");

                printf("\n\t  Do you want to see more? (Y/N) : ");
                scanf(" %c",&ask3);
                if (ask3!='N'&&ask3!='Y')
                {
                    printf("\t  Error! Please input 'Y' or 'N' \n");
                    goto  abc;
                }
                while(ask3!='N'&&ask3!='Y');
            }
            while (ask3!='N');

re2:
            printf("\t  Go back to menu (Y/N) :");
            scanf(" %c",&back_to_menu);
            if(back_to_menu=='Y')
                goto staff;
            else if(back_to_menu =='N')
                goto abc;
            else
            {
                printf("\t  Error! Please input 'Y' ot 'N' \n\n");
                goto re2 ;
            }
        }
        else if(staff_choice==3)
        {

            printf("\n");
            system("cls");
            goto start;
        }
        else if (staff_choice==4);
        else
        {
            printf("\n\t             PLEASE TRY AGAIN !\n\t             ");
            system("pause");
            goto staff;
        }
    }
    else
    {
        printf("\n\t              PLEASE TRY AGAIN !\n\t              ");
        system("pause");
        system("cls");
        goto start;
    }




}


void NO()
{

    printf("\t  You are customer NO.%d\n",z);
    z++;
}


