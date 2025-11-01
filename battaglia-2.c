#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   //mi serve per randomizzare il seed di rand()
#include <stdbool.h>

int battaglia(int hp_g,int hp_n);
int selezione(); //serve ad ottenere un valore da usare in uno switch
int attacco_giocatore(int hp_n);  // diminuisce hp nemico in maniera casuale
int attacco_nemico(int hp_g);     //diminusice hp_giocatore in maniera casuale
int cura_giocatore(int hp_g);     //cura un numero di hp casuale al giocatore
int cura_nemico(int hp_n);      //cura un numero di hp casuale al nemico
bool fuga();                    // prova in maniera casuale  a far terminare la battaglia



int selezione(){
    int out;
      printf("\nCosa vuoi fare?\n");                          
      printf("0 - Attaccare\n");
      printf("1 - Curarti\n");
      printf("2 - Scappare\n");

      scanf(" %d",&out);   //inserisco spazio nello scanf per eliminare eventuali newline residui
      return out;               //restituisco la scelta compiuta dal giocatore
}

int attacco_giocatore(int hp_n){
    srand(time(NULL));                  //impostazione del seed
    int riuscita  = rand() % (7-1)+1;       //il numero generato è compreso tra 1 e 6 che sono i danni che verranno fatti
    printf("\nHai inflitto %d Danni\n",riuscita);
    return hp_n - riuscita; //viene restituito gli hp dopo l'attacco
}

int attacco_nemico(int hp_g){   //identica alla precedente
    srand(time(NULL));
    int riuscita = rand() % (5-1)+1;
    printf("\nHai subito %d danni\n", riuscita);
    return hp_g - riuscita;
}

int cura_giocatore(int hp_g){  //molto simile ma ho inserito un controllo per evitare che gli hp salgano oltre il massimo
    srand(time(NULL));
    int riuscita = rand() % (6 - 2) + 2;
    printf("\nHai curato %d HP!\n",riuscita);
    if((hp_g+riuscita) <= 18){
        return hp_g + riuscita;
    } else if(hp_g + riuscita > 18){
        return 18;
    }
}

int cura_nemico(int hp_n){  //come cura_giocatore
    srand(time(NULL));
    int riuscita = rand() % (4-1)+1;
    printf("\nIl goblin si est curato per %d HP\n", riuscita);
    if((hp_n+riuscita) <= 20){
        return hp_n + riuscita;
    } else if(hp_n + riuscita > 20){
        return 20;
    }
}

bool fuga(){     //una possibilità su nove di fuggire(rompere il do while istantaneamente)
    int risultato = rand() % (9);
    if(risultato == 7){
        printf("Sei scappato dal goblin!\n");
        return true;
    } else{
        printf("Non sei riuscito a scappare\n");
        return false;
    }
}

int battaglia(int hp_g,int hp_n){
    do{ //assicuriamoci che venga almeno una volta eseguito il loop
        
        //
        printf("Davanti a te hai un Goblin!\n"); 
        printf("Ha %d\\20 HP!\n",hp_n);
        printf("\nTu hai %d\\18 HP\n",hp_g);
        
        //il giocatore sceglie cosa fare e uno switch esegue l'azione giusta
        int sel = selezione();
        switch(sel){
            case 0:
            
            // le varie funzioni attacco e cura vengono sempre usate per riassegnare gli hp degli agenti
            hp_n  = attacco_giocatore(hp_n);
            break;
            
            case 1:
            hp_g = cura_giocatore(hp_g);
            break;
            
            case 2:
            if (fuga()){
                //se il giocatore riesce a fuggire gli hp del nemico sono azzerati e si salta al controllo del while per evitare che il nemico attacchi dopo la fuga
                hp_n = 0;
                goto fine;  //fine è un etichetta che sposta il flusso di controllo alla fine del while
            } 
            break;
        }

         //anche l'azione del nemico è random
        srand(time(NULL));
        int azione_nemico = rand()%(4); 

        switch(azione_nemico){
            case 0:
            printf("Il mostro non fa niente\n");
            break;
            
            //creo due case uguali per rendere più probabile questa azione
            case 1:
            hp_g = attacco_nemico(hp_g);
            break;

            case 2:
            hp_g = attacco_nemico(hp_g);
            break;

            case 3:
            hp_n = cura_nemico(hp_n);
            break;

        }
              
       
       //controllo dello stato del giocatore, se gli hp si azzerano finisce il programma istantaneamente
        if(hp_g <= 0){  
            printf("SEI MORTO!\n");
            return 0;
        }

        fine:
    } while(hp_n > 0);

    printf("\nLa battaglia est finita!\n");
    return 0;

}

int main(){
    int hp_g = 18;  //dichiariamo i punti vita dei due agenti
    int hp_n = 20; // lo facciamo fuori altriemnti non "salverebbe" il danno
    battaglia(hp_g,hp_n);    
    return 0;
}