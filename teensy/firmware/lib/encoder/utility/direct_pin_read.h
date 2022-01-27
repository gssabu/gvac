#ifndef direct_pin_read_h_
#define direct_pin_read_h_

#if defined(__AVR__)

#define IO_REG_TYPE			uint8_t
#define PIN_TO_BASEREG(pin)             (portInputRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*(base)) & (mask)) ? 1 : 0)

#elif defined(TEENSYDUINO) && (defined(KINETISK) || defined(KINETISL))

#define IO_REG_TYPE			uint8_t
#define PIN_TO_BASEREG(pin)             (portInputRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*(base)) & (mask)) ? 1 : 0)

#elif defined(__IMXRT1052__) || defined(__IMXRT1062__)

#define IO_REG_TYPE			uint32_t
#define PIN_TO_BASEREG(pin)             (portOutputRegister(pin))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*(base)) & (mask)) ? 1 : 0)

#elif defined(__SAM3X8E__)  // || defined(ESP8266)

#define IO_REG_TYPE			uint32_t
#define PIN_TO_BASEREG(pin)             (portInputRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*(base)) & (mask)) ? 1 : 0)

#elif defined(__PIC32MX__)

#define IO_REG_TYPE			uint32_t
#define PIN_TO_BASEREG(pin)             (portModeRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)	(((*(base+4)) & (mask)) ? 1 : 0)

/* ESP8266 v2.0.0 Arduino workaround for bug https://github.com/esp8266/Arduino/issues/1110 */
#elif defined(ESP8266)

#define IO_REG_TYPE			uint32_t
#define PIN_TO_BASEREG(pin)             ((volatile uint32_t *)(0x60000000+(0x318)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*(base)) & (mask)) ? 1 : 0)

/* ESP32  Arduino (https://github.com/espressif/arduino-esp32) */
#elif defined(ESP32)

#define IO_REG_TYPE			uint32_t
#define PIN_TO_BASEREG(pin)             (portInputRegister(digitalPinToPort(pin)))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*(base)) & (mask)) ? 1 : 0)

#elif defined(__SAMD21G18A__) || defined(__SAMD21E18A__)

#define IO_REG_TYPE                     uint32_t
#define PIN_TO_BASEREG(pin)             portModeRegister(digitalPinToPort(pin))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*((base)+8)) & (mask)) ? 1 : 0)

#elif defined(__SAMD51__)

#define IO_REG_TYPE                     uint32_t
#define PIN_TO_BASEREG(pin)             portInputRegister(digitalPinToPort(pin))
#define PIN_TO_BITMASK(pin)             (digitalPinToBitMask(pin))
#define DIRECT_PIN_READ(base, mask)     (((*(base)) & (mask)) ? 1 : 0)

#endif

#endif
