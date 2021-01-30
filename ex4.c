#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<io.h>

void dealCard(int round, int pcards[13], int curDeck[13][4]){ //Chia 1 con bai cho 1 nguoi, round la index cua con bai chuan bi chia
    int ranCard = rand() % 52;
    while(curDeck[ranCard / 4][ranCard % 4]){
        if(ranCard == 51) ranCard = 0;
        ranCard++;
    }
    pcards[round] = ranCard;
    curDeck[ranCard / 4][ranCard % 4] = 1;
}

void display(int pcards[13], int player){//In tat ca bai cua 1 nguoi choi ra man hinh
    printf("Player %d: ", player);
    for(int i = 0; i < 13; i++){
        int value = pcards[i] / 4 + 1;
        switch (value)
        {
        case 1:
            printf("A");
            break;
        case 11:
            printf("J");
            break;
        case 12:
            printf("Q");
            break;
        case 13:
            printf("K");
            break;   
        default:
            printf("%d", value);
            break;
        }

        _setmode(_fileno(stdout), _O_U16TEXT); //Su dung Unicode de in ky hieu cac chat cua bai
        int suit = pcards[i] % 4;
        switch (suit)
        {
        case 0:
            wprintf(L"\x2660 ");
            break;
        case 1:
            wprintf(L"\x2663 ");
            break;
        case 2:
            wprintf(L"\x2665 ");
            break;
        case 3:
            wprintf(L"\x2666 ");
            break;       
        default:
            break;
        }
        _setmode(_fileno(stdout), _O_TEXT);//Tro lai binh thuong
    }
    printf("\n");
}

void haveFourOfAKind(int pcards[13], int player){
    int count;
    int found = 0;
    for(int i = 0; i < 13; i++){
        count = 0;
        for(int j = i + 1; j < 13; j++){
            if (pcards[i] / 4 == pcards[j] / 4){
                count++;
            }
        }
        if (count == 3) {
            char value = pcards[i] / 4 + 1;
            switch (value)
            {
            case 1:
                printf("Player %d has four of a kind, A\n", player);
                break;
            case 11:
                printf("Player %d has four of a kind, J\n", player);
                break;
            case 12:
                printf("Player %d has four of a kind, Q\n", player);
                break;
            case 13:
                printf("Player %d has four of a kind, K\n", player);
                break;   
            default:
                printf("Player %d has four of a kind, %d\n", player, value);
                break;
            }   
            found = 1;
        }
    }
    if(!found) printf("Player %d doesn't have four of a kind.\n", player);

}
int main(){
    srand(time(NULL));
    int deck[13][4];//Khoi tao bo bai voi tat ca ca phan tu la 0
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 4; j++){
            deck[i][j] = 0;
        }
    }
    int p1cards[13], p2cards[13], p3cards[13], p4cards[13]; //Bai cua moi nguoi choi
    for(int i = 0; i < 13; i++){//13 round
        dealCard(i, p1cards, deck);
        dealCard(i, p2cards, deck);
        dealCard(i, p3cards, deck);
        dealCard(i, p4cards, deck);
    }
    int testCards[13] = {1, 10, 2, 7, 11, 33, 3, 12, 13, 0, 9, 8, 50};

    display(p1cards, 1);
    display(p2cards, 2);
    display(p3cards, 3);
    display(p4cards, 4);

    haveFourOfAKind(p1cards, 1);
    haveFourOfAKind(p2cards, 2);
    haveFourOfAKind(p3cards, 3);
    haveFourOfAKind(p4cards, 4);
   
    return 0;
}