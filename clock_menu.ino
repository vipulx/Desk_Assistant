#include "U8glib.h"

// Clock display function
void displayClock() {
  int hour = 12;
  int minute = 0;
  int second = 0;

  while (true) {
    second++;
    if (second == 60) {
      second = 0;
      minute++;
      if (minute == 60) {
        minute = 0;
        hour++;
        if (hour == 24) {
          hour = 0;
        }
      }
    }

    // Render the clock
    u8g.firstPage();
    do {
      u8g.setFont(u8g_font_10x20);
      u8g.setPrintPos(20, 24);
      u8g.print(hour);
      u8g.print(":");
      u8g.print(minute);
      u8g.print(":");
      u8g.print(second);
    } while (u8g.nextPage());

    // Exit back to main menu if SELECT is pressed
    if (digitalRead(BUTTON_SELECT) == LOW) {
      break;
    }
  }
}
