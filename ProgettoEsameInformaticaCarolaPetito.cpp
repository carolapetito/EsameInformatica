#include <stdio.h>
#include<stdlib.h>

// Progetto di Carola Petito
int main()
{
    int i;
	int p;
	int v=0;
	int a;
	int b;
	int giocatore=0;
	int par;
	char scelta;
    char t[3][3]; //Dichiaro una matrice di caratteri 3x3


    printf("\n######### TRIS DI CAROLA PETITO #########\n");

    //Inizializzo la matrice con il carattere "spazio"
    for(i=0;i<3;i++)
    {
        for(p=0;p<3;p++)
            t[i][p]=' ';
    }

    	printf("\nInizio del gioco:\n\n[ ][ ][ ]\n[ ][ ][ ]\n[ ][ ][ ]\n"); //Stampo la matrice di gioco (vuota)

    while(v == 0) //Il ciclo verifica che il gioco non sia terminato
    {

        if(v == 0) //Se il gioco non è ancora terminato eseguo la mossa
        {
            //Piccolo algoritmo per alternare i giocatori

            giocatore=(giocatore%2)+1;
            printf("\nGiocatore %d inserisci le coordinate: ", giocatore);
            scanf("%d %d", &a, &b);

            //Controllo che verifica l'idoneità delle coordinate
            while(a<1 || b<1 || a>3 || b>3)
            {
                printf("\nCoordinata inesistente, riprova: ");
                scanf("%d %d", &a, &b);
            }
            //Controllo anti-cheat (il giocatore non può sovrascrivere una mossa già effettuata)
            while(t[a-1][b-1]!=' ')
            {
                printf("\nNon barare! Riprova: ");
                scanf("%d %d", &a, &b);
            }
            if (giocatore == 1) //Controllo identità del giocatore
                t[a-1][b-1]='X';
            else
                t[a-1][b-1]='O';
            giocatore+=2;
        }
            //Nella riga di seguito stampo la matrice di gioco aggiornata
            printf("\nQuesta e' la situazione di gioco:\n\n[%c][%c][%c]\n[%c][%c][%c]\n[%c][%c][%c]\n",
			t[0][0], t[0][1], t[0][2], t[1][0], t[1][1], t[1][2], t[2][0], t[2][1], t[2][2]);

            //Inizio serie di cicli che controllano lo stato del gioco
            //Controllo righe
            for(i=0;i<3;i++)
            {
                if(t[i][0] == t[i][1] && t[i][1] == t[i][2] && t[i][0] != ' ' && t[i][1] != ' ' && t[i][2] != ' ')
                {
                    printf("\nC'e' un tris di %c sulla riga %d!", t[i][0], i+1);
                    printf("\nIl giocatore %d vince!\n\n", giocatore-2);
                    printf("---COMPLIMENTI---");
                    v=1;
                }
            }

            //Controllo colonne
            for(i=0;i<3;i++)
            {
                if(t[0][i] == t[1][i] && t[1][i] == t[2][i] && t[0][i] != ' ')
                {

                	printf("\nC'e' un tris di %c sulla colonna %d", t[i][i], i+1);
                    printf("\nIl giocatore %d vince!\n\n", giocatore-2);
                    printf("---COMPLIMENTI---");

                     v=1;
					}

                }

            //Controllo diagonali
           // Controllo diagonale principale

			  if(t[0][0] == t[1][1] && t[1][1] == t[2][2] && t[0][0] != ' ')
				{

              	printf("\nC'e' un tris diagonale di %c!", t[0][0]);
            	printf("\nIl giocatore %d vince!\n\n",giocatore-2);
            	printf("---COMPLIMENTI---");

              		 v=1;
              	}


           // Controllo diagonale secondaria

              if(t[0][2] == t[1][1] && t[1][1] == t[2][0] && t[2][0] != ' ')
          		{

                printf("\nC'e' un tris diagonale di %c!", t[1][1]);
                printf("\nIl giocatore %d vince!\n\n", giocatore-2);
                printf("---COMPLIMENTI---");

              		 v=1;
			  	}


            //Controllo che identifica uno stato di parità
            par=0;
            for(i=0;i<3;i++)
            {
                if(t[i][0]!=' ' && t[i][1]!=' ' && t[i][2]!=' ' && v!=1)
                par++;
                if(par==3)
                {
                    printf("\n---PARITA'---\n\n");
                    v=1;
                }
            }
    	}
}
