#include <allegro.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define AZUL 0,0,255
#define VERDE 0,255,0
#define VERMELHO 255,0,0
#define AMARELO 255,255,0

void top10facil();
void top10medio();
void top10dificil();
void init();
void deinit();
void fMove_Bola();
void fAumenta_Velocidade();
void fInimigo();
void fTempo();
void mostraMenu();
void menuDificuldade();
void menu_Cor_Barra();
void inicio();
void pontos();
void inicio();

int g,x = 240;
int y = 440;
int inimigo_x = 240;
int inimigo_y = 40;
int bola_x = 200;
int bola_y = 200;
int vSentido1 = 2;
int vSentido2 = 1;
int vVelocidade_Bola = 2;
int vVelocidade = 2;
int vTempo = 0;
char nome[100];
int w,contador = 0 ,contador1 = 0;
int opcao,dificuldade;

struct ranking{

    char nome2[100];
    int tempo;

};
typedef struct ranking Rank;

int main()
{



while(contador1 != 1){

    mostraMenu();

    scanf("%d",&opcao);

    if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4){

        system("cls");
        contador1 = 1;


    }else{              //FIM DO IF DA VERIFICACAO DA OPCAO DO MENU
        system("cls");
        puts("essa opcao nao existe");
    }

}   //FIM DO WHILE DA VERIFICACAO DA OPCAO DO MENU

    switch(opcao){

    case 1 :

    puts("Digite seu nome : ");
    scanf(" %[^\n]s",nome);


    system("cls");

    printf("Selecione a Dificuldade : \n\n\n");


    while(contador != 1){

        menuDificuldade();

        scanf("%d",&dificuldade);

        if(dificuldade == 1 || dificuldade == 2 || dificuldade == 3 || dificuldade== 4){

            system("cls");
            contador = 1;


    if(dificuldade==4){
    mostraMenu();

}
 }else{

            system("cls");
            puts("Essa dificuldade nao existe ");
        }

    }


    contador = 0;
    int numero_cor;
    char cor_barra;

     printf("Selecione a cor da barra : \n\n");

    while(contador != 1){

        menu_Cor_Barra();

        scanf(" %d",&numero_cor);

        if(numero_cor == 1 || numero_cor == 2 || numero_cor == 3 || numero_cor == 4){

            system("cls");
            contador = 1;


        }else{
            system("cls");
            puts("Esse numero de cor nao existe");
        }

    }

	init();

    BITMAP *buffer = create_bitmap(640,480);//TAMANHO DA JANELA LIMITE ALLEGRO

    if(dificuldade == 1)
    install_int(fAumenta_Velocidade, 30000);

    if(dificuldade == 2)
    install_int(fAumenta_Velocidade, 20000);

    if(dificuldade == 3)
    install_int(fAumenta_Velocidade, 10000);

    install_int(fInimigo, 2);
    install_int(fTempo, 1000);

	while (!key[KEY_ESC]) {

          if ( bola_y > 410 || bola_y <= 2 || bola_x <= 2 || bola_x >= 638 || bola_y <= 50)
              fMove_Bola();

          clear_bitmap(buffer);

          if (key[KEY_RIGHT] && x <= 486 )
          {
              x += vVelocidade;
          }
          if (key[KEY_LEFT] && x >= 4 )
          {
              x -= vVelocidade;
          }

          circlefill (buffer, bola_x, bola_y, 6, makecol(255,255,255));//TAMANHO DA BOLINHA

          rect(buffer, 1, 1, 639, 479, makecol(200,20,70));
          line(buffer, 0, 479, 640, 479, makecol(0,0,0));


          if(numero_cor == 1)
            rectfill(buffer, x, y, x+150, y+10, makecol(AZUL));

          if(numero_cor == 2)
            rectfill(buffer, x, y, x+150, y+10, makecol(VERMELHO));

          if(numero_cor == 3)
            rectfill(buffer, x, y, x+150, y+10, makecol(VERDE));

          if(numero_cor == 4)
            rectfill(buffer, x, y, x+150, y+10, makecol(AMARELO));


          rectfill(buffer, inimigo_x, inimigo_y, inimigo_x+150, inimigo_y+10, makecol(VERMELHO));

	      if ( vSentido1 == 2 )
	          bola_y -= vVelocidade_Bola;
          else
          if ( vSentido1 == -1 )
              bola_y += vVelocidade_Bola;

          if ( vSentido2 == 1 )
              bola_x += vVelocidade_Bola;
          else
          if ( vSentido2 == 0 )
              bola_x -= vVelocidade_Bola;


          textprintf_ex(buffer, font, 10, 10, makecol(0, 0, 255), -1,"Tempo: %d segundos",vTempo);//TEMPO QUE APARECE NO JOGO
	      draw_sprite(screen, buffer, 0, 0);


	      textprintf_ex(buffer, font, 9, 25, makecol(0, 0, 255), -1,"Jogador: %s ",nome);
	      draw_sprite(screen, buffer, 0, 0);


    if(dificuldade == 1){
        if(vTempo % 30 == 0 && vTempo != 0){
	      textprintf_ex(buffer, font, 280, 190, makecol(0, 0, 255), -1,"Level Up");
	      draw_sprite(screen, buffer, 0, 0);
        }

    }

    if(dificuldade == 2){
        if(vTempo % 20 == 0 && vTempo != 0){
	      textprintf_ex(buffer, font, 280, 190, makecol(0, 0, 255), -1,"Level Up");
	      draw_sprite(screen, buffer, 0, 0);
        }

    }

    if(dificuldade == 3){
        if(vTempo % 10 == 0 && vTempo != 0){
	      textprintf_ex(buffer, font, 280, 190, makecol(0, 0, 255), -1,"Level Up");
	      draw_sprite(screen, buffer, 0, 0);
        }

    }

}

	deinit();

break;

    case 2:
         menuDificuldade();
        scanf("%d",&dificuldade);
        system("cls");
         if(dificuldade==1){
        top10facil();
        FILE *arq;
        arq = fopen("facil.txt","r");
        printf("|---------  NOME  ---------TEMPO---------\n");
       while(fscanf(arq,"%s %d",nome,&vTempo)!=EOF){
            printf("%s %d segundos\n",nome,vTempo);
       }
    break;

        }
        if(dificuldade==2){
        top10medio();
        FILE *arq;
        arq = fopen("medio.txt","r");
        printf("|---------  NOME  ---------TEMPO---------\n");
       while(fscanf(arq,"%s %d",nome,&vTempo)!=EOF){
            printf("%s %d segundos\n",nome,vTempo);
       }
    break;

        }
        if(dificuldade == 3){
    top10dificil();
         FILE *arq;
        arq = fopen("teste.txt","r");
        printf("|---------  NOME  ---------TEMPO---------\n");
       while(fscanf(arq,"%s %d",nome,&vTempo)!=EOF){
            printf("%s %d segundos\n",nome,vTempo);
       }
    break;
        }
        if(dificuldade==4){
            mostraMenu();
        }
        break;
        system("cls");
case 3:
textcolor(AZUL);
    printf("INSTRUCOES DO PING-PONG \n\n\n");
    printf("(1) O jogo tem 3 dificuldades : \n\n");
    printf("     Facil   : A bolinha ira aumentar a velocidade a cada 30 segundos   \n");
    printf("     Medio   : A bolinha ira aumentar a velocidade a cada 20 segundos   \n");
    printf("     Dificil : A bolinha ira aumentar a velocidade a cada 10 segundos \n\n");
    printf("(2) Voce podera escolher entre 4 cores para a sua barra \n\n");
    printf("(3)o movimento da barra é feito com as setas do teclado,esquerda e direita\n\n");
    printf("(4)voltar ao menu principal \n\n");
      scanf("%d",&g);
      switch (g){
case 4:
    system("cls");
     mostraMenu();
     scanf("%d",&opcao);


    if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4){

        system("cls");
        contador1 = 1;


    }else{              //FIM DO IF DA VERIFICACAO DA OPCAO DO MENU
        system("cls");
        puts("essa opcao nao existe");
    }

}   //FIM DO WHILE DA VERIFICACAO DA OPCAO DO MENU

    switch(opcao){

    case 1 :

    puts("Digite seu nome : ");
    scanf(" %[^\n]s",nome);


    system("cls");

    printf("Selecione a Dificuldade : \n\n\n");


    while(contador != 1){

        menuDificuldade();

        scanf("%d",&dificuldade);

        if(dificuldade == 1 || dificuldade == 2 || dificuldade == 3){

            system("cls");
            contador = 1;


        }else{

            system("cls");
            puts("Essa dificuldade nao existe ");
        }

    }


    contador = 0;
    int numero_cor;
    char cor_barra;

     printf("Selecione a cor da barra : \n\n");

    while(contador != 1){

        menu_Cor_Barra();

        scanf(" %d",&numero_cor);

        if(numero_cor == 1 || numero_cor == 2 || numero_cor == 3 || numero_cor == 4){

            system("cls");
            contador = 1;


        }else{
            system("cls");
            puts("Esse numero de cor nao existe");
        }

    }

	init();

    BITMAP *buffer = create_bitmap(640,480);//TAMANHO DA JANELA LIMITE ALLEGRO

    if(dificuldade == 1)
    install_int(fAumenta_Velocidade, 30000);

    if(dificuldade == 2)
    install_int(fAumenta_Velocidade, 20000);

    if(dificuldade == 3)
    install_int(fAumenta_Velocidade, 10000);

    install_int(fInimigo, 2);
    install_int(fTempo, 1000);

	while (!key[KEY_ESC]) {

          if ( bola_y > 410 || bola_y <= 2 || bola_x <= 2 || bola_x >= 638 || bola_y <= 50)
              fMove_Bola();

          clear_bitmap(buffer);

          if (key[KEY_RIGHT] && x <= 486 )
          {
              x += vVelocidade;
          }
          if (key[KEY_LEFT] && x >= 4 )
          {
              x -= vVelocidade;
          }

          circlefill (buffer, bola_x, bola_y, 6, makecol(255,255,255));//TAMANHO DA BOLINHA

          rect(buffer, 1, 1, 639, 479, makecol(200,20,70));
          line(buffer, 0, 479, 640, 479, makecol(0,0,0));


          if(numero_cor == 1)
            rectfill(buffer, x, y, x+150, y+10, makecol(AZUL));

          if(numero_cor == 2)
            rectfill(buffer, x, y, x+150, y+10, makecol(VERMELHO));

          if(numero_cor == 3)
            rectfill(buffer, x, y, x+150, y+10, makecol(VERDE));

          if(numero_cor == 4)
            rectfill(buffer, x, y, x+150, y+10, makecol(AMARELO));


          rectfill(buffer, inimigo_x, inimigo_y, inimigo_x+150, inimigo_y+10, makecol(VERMELHO));

	      if ( vSentido1 == 2 )
	          bola_y -= vVelocidade_Bola;
          else
          if ( vSentido1 == -1 )
              bola_y += vVelocidade_Bola;

          if ( vSentido2 == 1 )
              bola_x += vVelocidade_Bola;
          else
          if ( vSentido2 == 0 )
              bola_x -= vVelocidade_Bola;


          textprintf_ex(buffer, font, 10, 10, makecol(0, 0, 255), -1,"Tempo: %d segundos",vTempo);//TEMPO QUE APARECE NO JOGO
	      draw_sprite(screen, buffer, 0, 0);


	      textprintf_ex(buffer, font, 9, 25, makecol(0, 0, 255), -1,"Jogador: %s ",nome);
	      draw_sprite(screen, buffer, 0, 0);


    if(dificuldade == 1){
        if(vTempo % 30 == 0 && vTempo != 0){
	      textprintf_ex(buffer, font, 280, 190, makecol(0, 0, 255), -1,"Level Up");
	      draw_sprite(screen, buffer, 0, 0);
        }

    }

    if(dificuldade == 2){
        if(vTempo % 20 == 0 && vTempo != 0){
	      textprintf_ex(buffer, font, 280, 190, makecol(0, 0, 255), -1,"Level Up");
	      draw_sprite(screen, buffer, 0, 0);
        }

    }

    if(dificuldade == 3){
        if(vTempo % 10 == 0 && vTempo != 0){
	      textprintf_ex(buffer, font, 280, 190, makecol(0, 0, 255), -1,"Level Up");
	      draw_sprite(screen, buffer, 0, 0);
        }

    }

}

	deinit();

break;
      }
break;

case 4:

   // system("PAUSE");
    return 0;

break;

}


}
END_OF_MAIN();

void init()
{
	int res;

    allegro_init();

    set_color_depth(32);

    res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);//TAMANHO DA JANELA

    if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
}

void deinit()
{
	clear_keybuf();
}

void fMove_Bola()
{
     if( bola_x <= 2 && vSentido1 == 2 && vSentido2 == 0 )
     {
         vSentido2 = 1;
     }
     else
     if ( bola_x >= 638 && vSentido1 == 2 && vSentido2 == 1 )
     {
         vSentido2 = 0;
     }

     if ( bola_x <= 2 && vSentido1 == -1 && vSentido2 == 0 )
     {
         vSentido2 = 1;
     }
     else
     if ( bola_x >= 638 && vSentido1 == -1 && vSentido2 == 1 )
     {
         vSentido2 = 0;
     }

     if ( bola_y >= 440 && bola_x >= x && bola_x <= ( x+150 ) && vSentido1 == -1 )//ESSA PARTE EH PRA RECONHECER O CONTATO DA BOLINHA COM O RETANGULO
     {
         vSentido1 = 2;
     }

     if ( bola_y <= 50 && bola_x >= inimigo_x && bola_x <= ( inimigo_x+150 ) && vSentido1 == 2 )
     {
         vSentido1 = -1;
     }

     if ( bola_y >= 480 )

     {

          if(dificuldade==1){
        top10facil();
         FILE *arq;
        arq = fopen("facil.txt","r");
        printf("|----------------RANKING NIVEL FACIL---------------------|\n");
        printf("|---------  NOME  ---------TEMPO---------\n");
       while(fscanf(arq,"%s %d",nome,&vTempo)!=EOF){
            printf("%s %d segundos\n",nome,vTempo);
       }

         }
         if(dificuldade==2){
        top10medio();
         FILE *arq;
        arq = fopen("medio.txt","r");
        printf("|----------------RANKING NIVEL MEDIO------------------------\n");
        printf("|---------  NOME  ---------TEMPO---------\n");
       while(fscanf(arq,"%s %d",nome,&vTempo)!=EOF){
            printf("%s %d segundos\n",nome,vTempo);
       }

         }

         if(dificuldade==3){
        top10dificil();
         FILE *arq;
        arq = fopen("teste.txt","r");
        printf("-----------------RANKING NIVEL DIFICIL-----------------------\n");
        printf("|---------  NOME  ---------TEMPO---------\n");
       while(fscanf(arq,"%s %d",nome,&vTempo)!=EOF){
            printf("%s %d segundos\n",nome,vTempo);
       }

         }


       allegro_message("Game Over!\nTempo : %d segundos\n\n %s Perdeu!",vTempo,nome);
        deinit();
        allegro_exit();
        exit(0);


        //system("cls");

     }
     else
     if ( bola_y <= 0)
     {
        allegro_message("Parabens!\nTempo : %d segundos\n\n %s Venceu!",vTempo,nome);
        deinit();
        allegro_exit();
        exit(0);
     }
}


void fAumenta_Velocidade()
{
     vVelocidade++;
     vVelocidade_Bola++;
}

void fInimigo()
{
    if ( bola_x > 320 && bola_x >= (inimigo_x+120) && inimigo_x <= 486 && vSentido2 == 1)
        inimigo_x += vVelocidade-1;
    else
    if ( bola_x > 320 && bola_x <= (inimigo_x+120) && vSentido2 == 0)
        inimigo_x -= vVelocidade-1;

    if ( bola_x < 320 && bola_x <= (inimigo_x+50) && inimigo_x >= 4 && vSentido2 == 0)
        inimigo_x -= vVelocidade-1;
    else
    if ( bola_x < 320 && bola_x >= (inimigo_x+50) && vSentido2 == 1)
        inimigo_x += vVelocidade-1;
}

void fTempo()
{
     vTempo += 1;//SEGUNDOS DO JOGO
}

void mostraMenu(){
textcolor(10);
textbackground(15);

printf("         _____     _    _   __    _______                                  \n");
printf("        |  _  \\   | |  | \\ | |   /  _____|                                 \n");
printf("        | |_|  |  | |  |  \\| |  /  / __                                    \n");
printf("        |  ___/   | |  |     | |  | |_ \\                                   \n");
printf("        | |       | |  | |\\  | |  |___| |                                  \n");
printf("        | |       | |  | |\\  | |       /                                   \n");
printf("        |_|       |_|  |_| \\_|  \\_____/                                    \n");
printf("                _______     _____    _  __      ______                     \n");
printf("               |       |   / __  \\  | \\ | |   /  _____|                    \n");
printf("               |__   __|  | |  | |  |  \\| |  /  / __                       \n");
printf("                 |  |     | |  | |  |     | |  | |_ \\                      \n");
printf("              _  |  |     | |  | |  | |\\  | |  |___| |                     \n");
printf("             | |_/  /     | |__| |  | | \\ |  \\       /                     \n");
printf("             \\_____/       \\____/   |_| |_|   \\_____/                      \n");


textcolor(5);
printf("+------------------------------------------------------------------------+ \n");
printf("|                               (1)Jogar                                 | \n");
printf("|                               (2)Ranking                               | \n");
printf("|                               (3)Instrucoes                            | \n");
printf("|                               (4)Sair                                  | \n");
printf("+------------------------------------------------------------------------+ \n");

}

void menuDificuldade(){

printf("    \\--------------------------------------------------------------/ \n");
printf("    |                            (1)Facil                          |  \n");
printf("    |                            (2)Medio                          |  \n");
printf("    |                            (3)Dificil                        |  \n");
printf("    |                            (4)voltar ao menu                 |  \n");
printf("    /--------------------------------------------------------------\\ \n");

}

void menu_Cor_Barra(){

    printf("  /---------------------------\\ \n");
    printf("  |        (1)AZUL            |  \n");
    printf("  |        (2)VERMELHO        |  \n");
    printf("  |        (3)VERDE           |  \n");
    printf("  |        (4)AMARELO         |  \n");
    printf("  \\---------------------------/  \n");

}

void top10dificil()
{
        int i = 0;
        FILE *arq;

        arq = fopen("teste.txt","r");

        if(arq == NULL){
            puts("erro ao abrir");
            exit(1);
        }

        //fclose(arq);
       Rank *r;
       r = malloc(11* sizeof(Rank));
       for (i = 0; i < 11; i++)
       {
           r[i].tempo = 0;
       }

        //char nomes[100];
        i = 0;
       while(fscanf(arq,"%s %d\n",r[i].nome2,&r[i].tempo)!=EOF){
            i++;
       }
    strcpy(r[i].nome2, nome);

    r[i].tempo = vTempo;
    int j, k, n;
    int aux;
    char auxnome[50];
    n = i + 1;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (r[i].tempo < r[j].tempo)
            {
               aux = r[j].tempo;
               strcpy(auxnome, r[j].nome2);

               r[j].tempo = r[i].tempo;
               strcpy(r[j].nome2, r[i].nome2);

               r[i].tempo = aux;
               strcpy(r[i].nome2, auxnome);

            }
        }
    }
    arq = fopen("teste.txt","w");
    for (i = 0; i < 10; i++)
    {
        if (r[i].tempo != 0)
            fprintf(arq, "%s %d\n", r[i].nome2, r[i].tempo);
    }
fclose(arq);

}
void top10medio()
{
        int i = 0;
        FILE *arq;

        arq = fopen("medio.txt","r");

        if(arq == NULL){
            puts("erro ao abrir");
            exit(1);
        }

        //fclose(arq);
       Rank *r;
       r = malloc(11* sizeof(Rank));
       for (i = 0; i < 11; i++)
       {
           r[i].tempo = 0;
       }

        //char nomes[100];
        i = 0;
       while(fscanf(arq,"%s %d\n",r[i].nome2,&r[i].tempo)!=EOF){
            i++;
       }
    strcpy(r[i].nome2, nome);

    r[i].tempo = vTempo;
    int j, k, n;
    int aux;
    char auxnome[50];
    n = i + 1;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (r[i].tempo < r[j].tempo)
            {
               aux = r[j].tempo;
               strcpy(auxnome, r[j].nome2);

               r[j].tempo = r[i].tempo;
               strcpy(r[j].nome2, r[i].nome2);

               r[i].tempo = aux;
               strcpy(r[i].nome2, auxnome);

            }
        }
    }
    arq = fopen("medio.txt","w");
    for (i = 0; i < 10; i++)
    {
        if (r[i].tempo != 0)
            fprintf(arq, "%s %d\n", r[i].nome2, r[i].tempo);
    }
fclose(arq);

}
void top10facil()
{
        int i = 0;
        FILE *arq;

        arq = fopen("facil.txt","r");

        if(arq == NULL){
            puts("erro ao abrir");
            exit(1);
        }

        //fclose(arq);
       Rank *r;
       r = malloc(11* sizeof(Rank));
       for (i = 0; i < 11; i++)
       {
           r[i].tempo = 0;
       }

        //char nomes[100];
        i = 0;
       while(fscanf(arq,"%s %d\n",r[i].nome2,&r[i].tempo)!=EOF){
            i++;
       }
    strcpy(r[i].nome2, nome);

    r[i].tempo = vTempo;
    int j, k, n;
    int aux;
    char auxnome[50];
    n = i + 1;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (r[i].tempo < r[j].tempo)
            {
               aux = r[j].tempo;
               strcpy(auxnome, r[j].nome2);

               r[j].tempo = r[i].tempo;
               strcpy(r[j].nome2, r[i].nome2);

               r[i].tempo = aux;
               strcpy(r[i].nome2, auxnome);

            }
        }
    }
    arq = fopen("facil.txt","w");
    for (i = 0; i < 10; i++)
    {
        if (r[i].tempo != 0)
            fprintf(arq, "%s %d\n", r[i].nome2, r[i].tempo);
    }
fclose(arq);

}




