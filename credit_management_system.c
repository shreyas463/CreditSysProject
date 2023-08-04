#include<stdio.h>
#include<string.h>

#define MAX 21


struct newcust
{
    char name[30]; int age; float income; char empst[20]; char rest[20];
    char ml[30]; float lamt; float mamt; float clamt; 
    char coll[40]; int ncc; int nolp; 

};

struct oldcust
{
    char name[25]; char cause[45]; float amt;
    char paidyet[5];  int paydate;  int lastdate;
    char paymeth[25]; char recpay[5]; char currmonth[7];
};


struct oldcust oc[MAX] = {
    
    {"Val", "creditcardbill", 7890, "yes", 160420, 200420, "bank", "no","apr"},
    {"Val", "mortgage", 8000, "yes", 140420, 240420, "bank", "yes", "apr"},
    {"Val", "carEMI", 25000, "no", 0, 180520, "notpaidyet", "yes","mar"},
    {"Val", "mortgage", 8000, "yes", 210320, 240320, "bank", "yes", "mar"},
    {"Val", "personal", 2400,  "yes", 310420, 310420, "creditcard", "no", "apr"},
    {"Dexter", "healthcare", 5000, "yes", 140320, 30320, "bank" ,"yes","mar"},
    {"Dexter", "carEMI", 60000, "yes", 40320, 200320,"bank" , "yes", "mar"},
    {"Dexter", "personal", 4500, "no", 0, 300420, "notpaidyet", "no", "apr"},
    {"Dexter", "creditcard",8500, "yes", 10420, 280420,"bank" , "no", "apr"}, 
    {"Dexter", "mortgage", 2000 , "yes", 160320, 300320, "creditcard" , "yes", "mar"},
    {"Ted", "healthcare", 25000, "yes", 170320, 230320, "bank", "no", "mar"},
    {"Ted", "mortgage", 3000, "no", 0, 300420, "notpaidyet", "yes", "apr"},
    {"Ted", "mortgage", 3000, "yes", 120320, 200320, "bank", "yes", "mar"},
    {"Ted", "carEMI", 6000, "yes", 190320, 280330, "creitcard", "yes", "mar"},
    {"Ted", "personal", 45000, "yes", 40420, 290420, "creditcard","no", "apr" },
    {"Tia", "carEMI", 4500, "yes" ,50420, 90420, "bank", "yes", "apr"},
    {"Tia", "personal",6000, "yes", 40320,260320, "creditcard", "no", "mar"},
    {"Tia", "healthcare",2000, "yes",220320, 260320, "bank", "no", "mar"},
    {"Tia", "creditcardbill", 5000, "yes", 220420,240420, "bank", "no", "apr"},
    {"Tia", "mortgage",8500, "yes",100320,200320, "bank", "yes", "mar"}
    };


void readnewinfo(struct newcust * c) {
        
            printf("Enter the customer details to determine if you're eligible for a loan/credit.\n\n");
            printf("Name, age, annual income, employment status, residential status\n");
            scanf("%s\n %d\n %f\n %s\n %s", c->name, &c->age, &c->income, c->empst, c->rest );
            printf("Enter major loan, loan amout, mortgage amount, car loan emi:\n");
            scanf("%s\n %f\n %f\n %f", c->ml, &c->lamt, &c->mamt, &c->clamt);
            printf("Enter collateral, no of credit cards, times late payments(if any)\n");
            scanf("%s\n %d\n %d", c->coll, &c->ncc, &c->nolp);

}

void applicable(struct newcust c)
{   
    
    float mi= (c.income)/12;
    float dmort= 0.28*mi; 
    float dcl= 0.10*(mi);


    if ((c.mamt>=dmort) || (c.clamt>=dcl) || (c.nolp>=2) || (strcmp("nil", c.coll)==0) || (strcmp("unemployed", c.empst)==0))
    {
        printf("\n\nNot eligible.\n");
    }
    else 
    {
        printf("\n\nYoure eligible. Welcome.\n");
    }
}


void searchbyname(char oldcname[25])
{   
    for (int i=0; i<25; i++)
    {   
        
        if (strcmp(oc[i].name, oldcname)==0)
        {
            printf("Name = %s\nCause = %s\nAmount = %f\nPaid Yet = %s\nPaid on = %d\nLast pay date = %d\nPayment method = %s\nReccuring = %s\n\n\n\n",  oc[i].name, oc[i].cause, oc[i].amt, oc[i].paidyet, oc[i].paydate, oc[i].lastdate, oc[i].paymeth, oc[i].recpay);
        
        }
    }
   
}

void searchbydate( int datetocheck)
{  
    for (int i=0; i<25; i++)
    {
        if ((oc[i].paydate==datetocheck)|| (oc[i].lastdate==datetocheck))
        {
            printf("Name=%s\nCause=%s\nAmount=%f\nPaid Yet=%s\nPaid on=%d\nLast pay date=%d\nPayment method=%s\nReccuring=%s\n\n",  oc[i].name, oc[i].cause, oc[i].amt, oc[i].paidyet, oc[i].paydate, oc[i].lastdate, oc[i].paymeth, oc[i].recpay);
        }
    }
}

void searchbycause(char cnametocheck[25], char causetocheck[25])
{
    
    for (int i=0; i<25; i++)
    {
        if ((strcmp(oc[i].name, cnametocheck)==0) && (strcmp(oc[i].cause, causetocheck)==0))
        {
            printf("Name = %s\nCause = %s\nAmount = %f\nPaid Yet = %s\nPaid on = %d\nLast pay date = %d\nPayment method = %s\nReccuring = %s\n\n",  oc[i].name, oc[i].cause, oc[i].amt, oc[i].paidyet, oc[i].paydate, oc[i].lastdate, oc[i].paymeth, oc[i].recpay);
        }
    }
}   

void addtransaction(int t)
{
    char idk[3];
    FILE *fp;
    struct oldcust c2[t];
    fp= fopen("f.txt","a+");
    for (int i=0; i<t; i++)
    {   
        printf("Enter the details: name, cause, amount, paid yet(Y/N), pay date, last day to pay, payment method and if its a reccuring transaction(Y/N).");
        printf("Give NEW LINE between each.");
        scanf("%s\t%s\t%f\t%s\t%d\t%d\t%s\t%s", c2[i].name, c2[i].cause, &c2[i].amt, c2[i].paidyet, &c2[i].paydate, &c2[i].lastdate, c2[i].paymeth, c2[i].recpay);
        fwrite(&c2[i], sizeof(c2), 1, fp);

        printf("\n\nTransaction succesful. Showing the invoice. \n");
        printf("Name = %s\nCause = %s\nAmount = %f\nPaid Yet = %s\nPaid on = %d\nLast pay date = %d\nPayment method = %s\nReccuring = %s\n\n",  c2[i].name, c2[i].cause, c2[i].amt, c2[i].paidyet, c2[i].paydate, c2[i].lastdate, c2[i].paymeth, c2[i].recpay);


    }
    fclose(fp);
}

void reminder()
{
     printf("\n\nREMINDER!      REMINDER!       REMINDER!\n\n The transactions due are:\n\n");
    for (int i=0; i<25; i++)
    {
        if( strcmp(oc[i].paidyet, "no")==0 )
        {
            printf("Name = %s\nCause = %s\nAmount = %f\nPaid Yet = %s\nLast pay date = %d\nReccuring = %s\n\n",  oc[i].name, oc[i].cause, oc[i].amt, oc[i].paidyet, oc[i].lastdate,  oc[i].recpay);
        }
    }
    printf("PLEASE PAY BEFORE THE DUE DATE IN ORDER TO AVOID LATE PAYMENT CHARGES.\n\n");
}

void monthlyreport(char mon[7])
{
    float sum; char placeholder[30]="a"; 
    for (int i=0; i<27; i++)
    {   
        if (strcmp(mon, oc[i].currmonth)==0)
        {
            sum=sum+(oc[i].amt);
            if (strcmp(placeholder, oc[i].name)!=0)
            {
                printf("\n\nThe total for the customer %s is Rs %f\n", oc[i].name, sum);
                strcpy(placeholder, oc[i].name);
            }
        }
    }
}

void write_data_to_file(){
    FILE *fp;
    fp= fopen("f.txt","w");
    for (int i=0; i<25; i++)
    {
    fwrite(&oc[i], sizeof(oc[i]), 1, fp);
    }

    fclose(fp);
    
}


int main()
{   

    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                 TO OUR                    =");
    printf("\n\t\t\t        =                 CREDIT                    =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t By Shreyas Chaudhary :) \n\n\n");


    struct newcust c1[5];
    char status; int n; 
    int m;
    write_data_to_file();
    printf("Do you want to see details of old customer(enter O) or add a new customer(enter N)?\n");
    scanf(" %c", &status);
    
   
    if (status=='N')
    {   
        printf("How many do customers do you want to add?\n");
        scanf("%d", &n);
        for (int i=0; i<n;i++)
        {
        readnewinfo(&c1[i]);
        applicable(c1[i]);
        }
    }
    else 
    {   while(m!=7){
        printf ("\n\n*********  MENU   ************\n");
        printf("\n\nDecide what you want to do.\n\n\n\nPress 1 for seeing all the details of a customer.\n\n");
        printf("Press 2 for seeing transactions of a particular day.\n\n");
        printf("Press 3 to see a particular transaction of a customer.\n\n");
        printf("Press 4 to add a transaction.\n\n");
        printf("Press 5 for getting a reminder about payments due.\n\n");
        printf("Press 6 for getting a monthly report.\n\n");
        printf("Press 7 to exit.\n\n");
        scanf("%d", &m);
    
        switch(m)
        {
        case 1:
        {   
            char oldcname[25];
            printf("\n\nEnter the customer name.\n");
            scanf("%s", oldcname);
            searchbyname(oldcname);
            break;
        }
        case 2:
        {
            int datetocheck;
            printf("\n\nEnter the date you want to see all transactions for.\n");
            scanf("%d", &datetocheck);
            searchbydate(datetocheck);
            break;
        }
        case 3:
        {
            char causetocheck[25];
            char cnametocheck[25];
            printf("\n\nEnter the customer name and the cause of payment you want to see.\n");
            scanf("%s\n%s", cnametocheck, causetocheck);
            searchbycause(cnametocheck, causetocheck);
            break;
        }
        case 4:
        {
            int t;
            printf("\n\nHow many transactions do you want to add?");
            scanf("%d", &t);
            addtransaction(t);
            break;
        }
        case 5:
        {
           reminder();
            break;
        }
        case 6:
        {
            char mon[7];
            printf("This is to see the monthly report. Enter the month(apr/mar).\n");
            scanf("%s", mon);
            monthlyreport(mon);
            break;
        }
        }
    }
    }
    return 0;   

}
