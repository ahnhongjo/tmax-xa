EXEC SQL INCLUDE sqlca.h;
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int check_account(char* account)
{
    int check = -1;
    
    EXEC SQL SELECT COUNT(*)
                 INTO :check
                 FROM BANK
                 WHERE "key"=:account;

    return check;
}

int get_balance_amount(char* account)
{
    char ret[1024];
    int check = 0;

    if(check_account(account)<0) return -1;

    EXEC SQL SELECT BALANCE 
         INTO :ret
         FROM BANK
         WHERE "key"=:account;

    return atoi(ret);
}

int deposit_money(char *amount, char* account){
    int tmp = 0;
    char sum[100];
    if(check_account(account)<=0) return -1;
    tmp=get_balance_amount(account) + atoi(amount);
    sprintf(sum,"%d",tmp);
    EXEC SQL UPDATE BANK
         SET BALANCE = :sum
         WHERE "key"=:account;
    return tmp;
}

int withdraw_money(char *amount, char* account){
    int tmp = 0;
    char sum[100];
    int balance=get_balance_amount(account);
    int realamount=atoi(amount);

    if(check_account(account)<=0) return -1;

    if(balance>=realamount){
            tmp=balance-realamount;
            sprintf(sum,"%d",tmp);
            EXEC SQL UPDATE BANK
                SET BALANCE = :sum
                WHERE "key"=:account;
        
        return tmp;
    }

    else return -2;
        
}

void record_trading(int amount, char* who,char * account){
    int idx=0;
    int balance=0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char nowdate[100];
    sprintf(nowdate,"%d-%d-%d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
    balance=get_balance_amount(account);

    EXEC SQL SELECT COUNT(*)
             INTO :idx
             FROM TRADE_HISTORY;

    idx++;

    EXEC SQL INSERT INTO TRADE_HISTORY
             VALUES(:idx,:who,:amount,:nowdate,:balance,:account);

}

int trade_recording(char* account){
    EXEC SQL BEGIN DECLARE SECTION;
        VARCHAR who[30][100];
        int amount[30];
        VARCHAR date[30][100];
        int balance[30];

    EXEC SQL END DECLARE SECTION;


    
    EXEC SQL SELECT WHO, AMOUNT, "date", BALANCE
             INTO :who, :amount, :date, :balance
             FROM TRADE_HISTORY 
             WHERE "ACCOUNT"=:account;
    
    for (int i=0;i<sqlca.sqlerrd[2];i++){
        printf("\t%.*s %d %.*s %d\n",who[i].len,who[i].arr,amount[i],date[i].len,date[i].arr,balance[i]);
    }

    return 0;
}
