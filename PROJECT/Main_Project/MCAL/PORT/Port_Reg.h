
/*Port Base Address*/
#define PORT_P00_BASE  (0xF003A000U)
#define PORT_P02_BASE  (0xF003A200U)

#define PORT_P14_BASE  (0xF003AE00U)
#define PORT_P15_BASE  (0xF003AF00U)

#define PORT_P20_BASE  (0xF003B400U)
#define PORT_P21_BASE  (0xF003B500U)
#define PORT_P22_BASE  (0xF003B600U)
#define PORT_P23_BASE  (0xF003B700U)

#define PORT_P33_BASE  (0xF003C100U)


/*register offsets for the gpios functionalities*/


#define PORT_IOCR0_OFFSET  (0x10U)
#define PORT_IOCR4_OFFSET  (0x14U)
#define PORT_IOCR8_OFFSET  (0x18U)
#define PORT_IOCR12_OFFSET (0x1CU)

/*input configurations*/

#define PORT_MODE_INPUT_TRISTATE_0   (0x00U)
#define PORT_MODE_INPUT_PULLDOWN     (0x08U)
#define PORT_MODE_INPUT_PULLUP       (0x10U)
#define PORT_MODE_INPUT_TRISTATE_1   (0x18U)

/*output configurations*/

#define PORT_MODE_OUTPUT_PP  (0x80U)
#define PORT_MODE_OUTPUT_OD  (0xC0U)

/*pushpull Alternative functionalites*/

#define PORT_MODE_OUTPUT_ALT1_PP  (0x88U)
#define PORT_MODE_OUTPUT_ALT2_PP  (0x90U)
#define PORT_MODE_OUTPUT_ALT3_PP  (0x98U)
#define PORT_MODE_OUTPUT_ALT4_PP  (0xA0U)
#define PORT_MODE_OUTPUT_ALT5_PP  (0xA8U)
#define PORT_MODE_OUTPUT_ALT6_PP  (0xB0U)
#define PORT_MODE_OUTPUT_ALT7_PP  (0xB8U)

/*open drain Alternative functionalites*/

#define PORT_MODE_OUTPUT_ALT1_OD  (0xC8U)
#define PORT_MODE_OUTPUT_ALT2_OD  (0xD0U)
#define PORT_MODE_OUTPUT_ALT3_OD  (0xD8U)
#define PORT_MODE_OUTPUT_ALT4_OD  (0xE0U)
#define PORT_MODE_OUTPUT_ALT5_OD  (0xE8U)
#define PORT_MODE_OUTPUT_ALT6_OD  (0xF0U)
#define PORT_MODE_OUTPUT_ALT7_OD  (0xF8U)

/*PDR Registers offsets*/

#define PORT_PDR0_OFFSET (0x40U)
#define PORT_PDR1_OFFSET (0x44U)

/*PDX output settings*/

#define PORT_PDR_STRONG_SHARP   (0x0U)
#define PORT_PDR_STRONG_MEDIUM  (0x1U)
#define PORT_PDR_MEDIUM         (0x2U)

/*PLX input voltage control*/

#define PORT_PDR_INPUT_AUTO    (0x00U)
#define PORT_PDR_INPUT_TTL5V   (0x02U)
#define PORT_PDR_INPUT_TTL3V3 (0x03U)

/*port output register offset*/

#define PORT_OUT_OFFSET (0x00U)

/*port output modification register offset*/

#define PORT_OMR_OFFSET (0x04U)

/*finding the correct base address*/

#define PORT_REG32(base, offset) (*(volatile uint32 *)((base) + (offset)))













