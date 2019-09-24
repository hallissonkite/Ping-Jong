#include <allegro.h>

volatile int exit_program;
void fecha_programa() { exit_program = TRUE; }
END_OF_FUNCTION(fecha_programa)

int main()
{
  allegro_init();
  install_timer();
  install_keyboard();
  install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
  set_window_title("agr");

  exit_program = FALSE;
  LOCK_FUNCTION(fecha_programa);
  LOCK_VARIABLE(exit_program);
  set_close_button_callback(fecha_programa);

  ///SONS
  SAMPLE* efeito = load_sample("efeito.wav");
  MIDI* naruto = load_midi("naruto.mid");

  ///BITMAPS
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

  ///VARIÁVEIS
  int estado_anterior_SPACE;

  play_midi(naruto, TRUE);

  ///GAME LOOP
  while(!exit_program)
  {
    //INPUT
    estado_anterior_SPACE = key[KEY_SPACE];
	poll_keyboard();

    if(key[KEY_ESC])
     fecha_programa();

    if(estado_anterior_SPACE == 0 && key[KEY_SPACE] != 0)
//      play_sample(efeito, 255, 128, 1000, FALSE);

    //UPDATE

    //DRAW
    draw_sprite(screen, buffer, 0, 0);
    clear(buffer);
  }

  stop_midi();

  ///FINALIZAÇÂO
  destroy_sample(efeito);
  destroy_midi(naruto);
  destroy_bitmap(buffer);

  return 0;
}
END_OF_MAIN();
