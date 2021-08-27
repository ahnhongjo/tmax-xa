#include <stdio.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/fbuf.h>
#include <usrinc/tx.h>
#include <stdlib.h>
#include <bank/bank_fdl.h>

int main(int argc, char *argv[])
{
    FBUF *sendbuf, *recvbuf;
    long rlen;
    int num, res;
    char amount[100];
    char account_number[10];
    char account_number_receiver[10];
    char retdat[1024];
    int ret;

    if (tpstart((TPSTART_T *)NULL) == -1)
    {
        printf("Tpstart failed\n");
        exit(1);
    }

    sendbuf = tpalloc("FIELD", NULL, 0);
    recvbuf = tpalloc("FIELD", NULL, 0);
    
    if (sendbuf == NULL){
        printf("Error allocation send buffer\n");
        tpend();
        exit(1);
    }

    
    if (recvbuf == NULL){
        printf("Error allocation recv buffer\n");
        tpend();
        exit(1);
    }

    printf("계좌번호를 입력해 주세요 : ");
    scanf("%s",account_number);
    fbput(sendbuf,ACCOUNT,account_number,0);

    res = tpcall("CHECK", (char *)sendbuf, 0, (char **)&recvbuf, &rlen, TPNOFLAGS);
    fbget(recvbuf, MESSAGE, retdat, 0);

    printf("%s",retdat);

    if(res<0){
        return 0;
    }

    while (1)
    {   
        ret=tx_begin();
        if (ret<0){
            printf("tx_begin failed\n");
            return;
        }
        
        fbput(sendbuf,ACCOUNT,account_number,0);
        printf("\n\t1.잔액조회\n\t2.입금\n\t3.출금\n\t4.이체\n\t5.거래내역\n\t6.EXIT\n\t:");
        scanf(" %d", &num);
        printf("\n");

        switch (num)
        {
        case 1:
            res = tpcall("BALANCE", (char *)sendbuf, 0, (char **)&recvbuf, &rlen, TPNOFLAGS);
            break;

        case 2:
            printf("\n\tPlease enter the deposit amount : ");
            scanf("%s", &amount);
            if(atoi(amount)<=0)
            {
                printf("제대로 된 수를 입력해 주세요\n");
                break;
            }
            fbput(sendbuf, FB_AMOUNT, amount, 0);
            res = tpcall("DEPOSIT", (char *)sendbuf, 0, (char **)&recvbuf, &rlen, TPNOFLAGS);
            break;
        
        case 3:
            printf("\n\tPlease enter the withdrawal amount : ");
            scanf("%s", &amount);

            if(atoi(amount)<=0)
            {
                printf("제대로 된 수를 입력해 주세요\n");
                break;
            }
            fbput(sendbuf, FB_AMOUNT, amount, 0);
            res = tpcall("WITHDRAW", (char *)sendbuf, 0, (char **)&recvbuf, &rlen, TPNOFLAGS);
            break;

        case 4:
            printf("\n\t보낼 계좌를 입력해 주세요 : ");
            scanf("%s",account_number_receiver);

            printf("\n\t보낼 금액을 입력 주세요 : ");
            scanf("%s", amount);
            if(atoi(amount)<=0)
            {
                printf("제대로 된 수를 입력해 주세요\n");
                break;
            }

            fbput(sendbuf, FB_AMOUNT, amount, 0);
            fbput(sendbuf,FB_ACCNT_REC,account_number_receiver,0);
            res = tpcall("TRANSFER", (char *)sendbuf, 0, (char **)&recvbuf, &rlen, TPNOFLAGS);
            break;

        case 5:
            res = tpcall("HISTORY", (char *)sendbuf, 0, (char **)&recvbuf, &rlen, TPNOFLAGS);
            break;

        case 6:
            return 0;

        default:
            printf("\n\tYou press wrong number\n");
            break;
        }

        if (res == -1)
        {   
            fbget(recvbuf, MESSAGE, retdat, 0);
            printf(" %s", retdat);
            tpstrerror(tperrno);
            tpfree(sendbuf);
            tpfree(recvbuf);
            tx_rollback();
            tpend();
            exit(1);
        }
        else{
            tx_commit(); 
            fbget(recvbuf, MESSAGE, retdat, 0);
            printf(" %s", retdat);
            fbinit(sendbuf,0);
        }
    }

    tpfree(sendbuf);
    tpfree(recvbuf);
    tpend();
    return 0;
}
