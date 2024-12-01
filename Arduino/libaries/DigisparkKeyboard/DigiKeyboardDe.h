#include "DigiKeyboard.h"
#ifndef DIGIKEYBOARDDE_H
#define DIGIKEYBOARDDE_H

#define DE_MOD_CONTROL_LEFT    (1<<8)
#define DE_MOD_SHIFT_LEFT      (1<<9)
#define DE_MOD_ALT_LEFT        (1<<10)
#define DE_MOD_GUI_LEFT        (1<<11)
#define DE_MOD_CONTROL_RIGHT   (1<<12)
#define DE_MOD_SHIFT_RIGHT     (1<<13)
#define DE_MOD_ALT_RIGHT       (1<<14)
#define DE_MOD_GUI_RIGHT       (1<<15)

// HID-Codes für Pfeiltasten
#define KEY_ARROW_UP     0x52  // Pfeil nach oben
#define KEY_ARROW_DOWN   0x51  // Pfeil nach unten
#define KEY_ARROW_LEFT   0x50  // Pfeil nach links
#define KEY_ARROW_RIGHT  0x4F  // Pfeil nach rechts

const uint16_t _ascii_de_map[128] PROGMEM =
{
    0x00,             // NUL
    0x00,             // SOH
    0x00,             // STX
    0x00,             // ETX
    0x00,             // EOT
    0x00,             // ENQ
    0x00,             // ACK
    0x00,             // BEL
    0x2a,     // BS Backspace
    0x2b,     // TAB  Tab
    0x28,     // LF Enter
    0x00,             // VT
    0x00,             // FF
    0x00,             // CR
    0x00,             // SO
    0x00,             // SI
    0x00,             // DEL
    0x00,             // DC1
    0x00,             // DC2
    0x00,             // DC3
    0x00,             // DC4
    0x00,             // NAK
    0x00,             // SYN
    0x00,             // ETB
    0x00,             // CAN
    0x00,             // EM
    0x00,             // SUB
    0x00,             // ESC
    0x00,             // FS
    0x00,             // GS
    0x00,             // RS
    0x00,             // US

    0x2c,      //  ' '
    0x1e|DE_MOD_SHIFT_LEFT,    // !
    0x1F|DE_MOD_SHIFT_LEFT,    // "
    0x38,    // #
    0x21|DE_MOD_SHIFT_LEFT,    // $
    0x22|DE_MOD_SHIFT_LEFT,    // %
    0x23|DE_MOD_SHIFT_LEFT,    // &
    0x32|DE_MOD_SHIFT_LEFT,          // '
    0x25|DE_MOD_SHIFT_LEFT,    // (
    0x26|DE_MOD_SHIFT_LEFT,    // )
    0x30|DE_MOD_SHIFT_LEFT,    // *
    0x30,    // +
    0x36,          // ,
    0x38,          // -
    0x37,          // .
    0x24|DE_MOD_SHIFT_LEFT,          // /
    0x27,          // 0
    0x1e,          // 1
    0x1f,          // 2
    0x20,          // 3
    0x21,          // 4
    0x22,          // 5
    0x23,          // 6
    0x24,          // 7
    0x25,          // 8
    0x26,          // 9
    0x37|DE_MOD_SHIFT_LEFT,      // :
    0x36|DE_MOD_SHIFT_LEFT,          // ;
    0x64,      // <
    0x27|DE_MOD_SHIFT_LEFT,          // =
    0x64|DE_MOD_SHIFT_LEFT,      // >
    0x2D|DE_MOD_SHIFT_LEFT,      // ?
    0x14|DE_MOD_ALT_RIGHT,      // @ 0x40 0x14
    0x04|DE_MOD_SHIFT_LEFT,      // A
    // (Der Rest des ASCII-Mappings bleibt unverändert)
    0x1c,          // z
    // Pfeiltasten können außerhalb des ASCII-Mappings verwendet werden
};

class DigiKeyboardDeviceDe : public DigiKeyboardDevice {
public:
    size_t write(uint8_t chr) {
        unsigned int temp = pgm_read_word_near(_ascii_de_map + chr);
        unsigned char low = temp & 0xFF;
        unsigned char high = (temp >> 8) & 0xFF;
        sendKeyStroke(low, high);
        return 1;
    }
    
    void sendKeyReport(uchar *array, const unsigned int size) {
        while (!usbInterruptIsReady()) {
            usbPoll();
            _delay_ms(5);
        }
        usbSetInterrupt(array, size);
    }
};

DigiKeyboardDeviceDe DigiKeyboardDe = DigiKeyboardDeviceDe();
#endif // DIGIKEYBOARDDE_H
