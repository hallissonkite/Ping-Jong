#include <allegro.h>
#include <stdio.h>
#include <conio.h>

#define AZUL 236,231,19
#define GREEN 214,48,185

void init();
void deinit();
void fMove_Bola();
void fAumenta_Velocidade();
void fInimigo();
void fTempo();
void mostraMenu();

int x = 240;
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
int w,cont = 0;
int opcao,dificuldade;

int main()
{
FILE *ranking;
char nome1;
 ranking =fopen("ranking.txt","a");
 nome1=nome;
 fprintf(ranking,"%c");

    mostraMenu();

    scanf("%d",&opcao);

    switch(opcao){

    case 1 :

    puts("Digite seu nome : ");
    scanf(" %[^\n]s",nome);

    system("cls");

    printf("Selecione a Dificuldade : \n\n\n");

    printf("           (1)Facil        \n");
    printf("           (2)Medio        \n");
    printf("           (3)Dificil      \n");


    while(cont != 1){


        scanf("%d",&dificuldade);

        if(dificuldade == 1 || dificuldade == 2 || dificuldade == 3)
            cont++;

        system("cls");

        if(dificuldade > 3 || dificuldade < 1)
            puts("Essa dificuldade nao existe ");

    }

	init();

    BITMAP *buffer = create_bitmap(1000,800);//TAMANHO DA JANELA LIMITE ALLEGRO

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

          rectfill(buffer, x, y, x+150, y+10, makecol(AZUL));
          rectfill(buffer, inimigo_x, inimigo_y, inimigo_x+150, inimigo_y+10, makecol(GREEN));

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

	      textprintf_ex(buffer, font, 500, 10, makecol(0, 0, 255), -1,"jogador: %s ",nome);
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
	      textprintf_ex(buffer, font, 280, 190, makecol(0, 0, 255), -1,"level up!!");
	      draw_sprite(screen, buffer, 0, 0);
        }

    }

}

	deinit();

break;

case 2:




case 3 :

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
        allegro_message("Game Over!\nTempo : %d segundos\n\n %s Perdeu!",vTempo,nome);
        deinit();
        allegro_exit();
        exit(0);

        //system("cls");

        //mostraMenu();
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

printf("-------------------------------------------------------------------\n");
printf("                                (1)Jogar                           \n");
printf("                                (2)Ranking                         \n");
printf("                                (3)Sair                            \n");
printf("-------------------------------------------------------------------\n");

}

