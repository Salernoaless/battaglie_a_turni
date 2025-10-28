# battaglie_a_turni
Progetto realizzato per esercitarmi con il C e la programmazione strutturata in generale in cui progetto un battle system per u gioco di ruolo testuale

Dev diary:
battaglia-1.0: ho creato nel main uno switch che si ripeta fin quando il nemico ha punti vita. Il giocatore sceglie cosa fare attraverso una banale funzione. Il numero di hp inflitti o curati vengono determinati dalla funzione rand() della libreria stdlib. Anche il comportamento del nemico è casuale. Ho dovuto impiegare un goto(cercherò di trovare un altro modo nelle versioni future).

battaglia-2.0(wip): intendo trasformare il programma inserendo il corpo del main in una funzione che necessità di parametri hp_g,hp_n e nome nemico. é subito evidente come la OOP sia molto più conveniente in questi casi in quanto mi permetterebbe di creare un classe agente con nome,numero di hp e quanti danni fa

battaglia3.0(wip):intendo rendere il gioco un ciclo di 2-3 battaglie in cui ogni nemico ha un dado diverso per infliggere danni(in dnd il range dei danni inflitti che va dalla faccia con 1 a quella con il valore massimo(4,6,12))
