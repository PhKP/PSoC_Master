    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; I2C_SCB
I2C_SCB__BIST_CONTROL EQU CYREG_SCB0_BIST_CONTROL
I2C_SCB__BIST_DATA EQU CYREG_SCB0_BIST_DATA
I2C_SCB__CTRL EQU CYREG_SCB0_CTRL
I2C_SCB__EZ_DATA00 EQU CYREG_SCB0_EZ_DATA00
I2C_SCB__EZ_DATA01 EQU CYREG_SCB0_EZ_DATA01
I2C_SCB__EZ_DATA02 EQU CYREG_SCB0_EZ_DATA02
I2C_SCB__EZ_DATA03 EQU CYREG_SCB0_EZ_DATA03
I2C_SCB__EZ_DATA04 EQU CYREG_SCB0_EZ_DATA04
I2C_SCB__EZ_DATA05 EQU CYREG_SCB0_EZ_DATA05
I2C_SCB__EZ_DATA06 EQU CYREG_SCB0_EZ_DATA06
I2C_SCB__EZ_DATA07 EQU CYREG_SCB0_EZ_DATA07
I2C_SCB__EZ_DATA08 EQU CYREG_SCB0_EZ_DATA08
I2C_SCB__EZ_DATA09 EQU CYREG_SCB0_EZ_DATA09
I2C_SCB__EZ_DATA10 EQU CYREG_SCB0_EZ_DATA10
I2C_SCB__EZ_DATA11 EQU CYREG_SCB0_EZ_DATA11
I2C_SCB__EZ_DATA12 EQU CYREG_SCB0_EZ_DATA12
I2C_SCB__EZ_DATA13 EQU CYREG_SCB0_EZ_DATA13
I2C_SCB__EZ_DATA14 EQU CYREG_SCB0_EZ_DATA14
I2C_SCB__EZ_DATA15 EQU CYREG_SCB0_EZ_DATA15
I2C_SCB__EZ_DATA16 EQU CYREG_SCB0_EZ_DATA16
I2C_SCB__EZ_DATA17 EQU CYREG_SCB0_EZ_DATA17
I2C_SCB__EZ_DATA18 EQU CYREG_SCB0_EZ_DATA18
I2C_SCB__EZ_DATA19 EQU CYREG_SCB0_EZ_DATA19
I2C_SCB__EZ_DATA20 EQU CYREG_SCB0_EZ_DATA20
I2C_SCB__EZ_DATA21 EQU CYREG_SCB0_EZ_DATA21
I2C_SCB__EZ_DATA22 EQU CYREG_SCB0_EZ_DATA22
I2C_SCB__EZ_DATA23 EQU CYREG_SCB0_EZ_DATA23
I2C_SCB__EZ_DATA24 EQU CYREG_SCB0_EZ_DATA24
I2C_SCB__EZ_DATA25 EQU CYREG_SCB0_EZ_DATA25
I2C_SCB__EZ_DATA26 EQU CYREG_SCB0_EZ_DATA26
I2C_SCB__EZ_DATA27 EQU CYREG_SCB0_EZ_DATA27
I2C_SCB__EZ_DATA28 EQU CYREG_SCB0_EZ_DATA28
I2C_SCB__EZ_DATA29 EQU CYREG_SCB0_EZ_DATA29
I2C_SCB__EZ_DATA30 EQU CYREG_SCB0_EZ_DATA30
I2C_SCB__EZ_DATA31 EQU CYREG_SCB0_EZ_DATA31
I2C_SCB__I2C_CFG EQU CYREG_SCB0_I2C_CFG
I2C_SCB__I2C_CTRL EQU CYREG_SCB0_I2C_CTRL
I2C_SCB__I2C_M_CMD EQU CYREG_SCB0_I2C_M_CMD
I2C_SCB__I2C_S_CMD EQU CYREG_SCB0_I2C_S_CMD
I2C_SCB__I2C_STATUS EQU CYREG_SCB0_I2C_STATUS
I2C_SCB__INTR_CAUSE EQU CYREG_SCB0_INTR_CAUSE
I2C_SCB__INTR_I2C_EC EQU CYREG_SCB0_INTR_I2C_EC
I2C_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB0_INTR_I2C_EC_MASK
I2C_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB0_INTR_I2C_EC_MASKED
I2C_SCB__INTR_M EQU CYREG_SCB0_INTR_M
I2C_SCB__INTR_M_MASK EQU CYREG_SCB0_INTR_M_MASK
I2C_SCB__INTR_M_MASKED EQU CYREG_SCB0_INTR_M_MASKED
I2C_SCB__INTR_M_SET EQU CYREG_SCB0_INTR_M_SET
I2C_SCB__INTR_RX EQU CYREG_SCB0_INTR_RX
I2C_SCB__INTR_RX_MASK EQU CYREG_SCB0_INTR_RX_MASK
I2C_SCB__INTR_RX_MASKED EQU CYREG_SCB0_INTR_RX_MASKED
I2C_SCB__INTR_RX_SET EQU CYREG_SCB0_INTR_RX_SET
I2C_SCB__INTR_S EQU CYREG_SCB0_INTR_S
I2C_SCB__INTR_S_MASK EQU CYREG_SCB0_INTR_S_MASK
I2C_SCB__INTR_S_MASKED EQU CYREG_SCB0_INTR_S_MASKED
I2C_SCB__INTR_S_SET EQU CYREG_SCB0_INTR_S_SET
I2C_SCB__INTR_SPI_EC EQU CYREG_SCB0_INTR_SPI_EC
I2C_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB0_INTR_SPI_EC_MASK
I2C_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB0_INTR_SPI_EC_MASKED
I2C_SCB__INTR_TX EQU CYREG_SCB0_INTR_TX
I2C_SCB__INTR_TX_MASK EQU CYREG_SCB0_INTR_TX_MASK
I2C_SCB__INTR_TX_MASKED EQU CYREG_SCB0_INTR_TX_MASKED
I2C_SCB__INTR_TX_SET EQU CYREG_SCB0_INTR_TX_SET
I2C_SCB__RX_CTRL EQU CYREG_SCB0_RX_CTRL
I2C_SCB__RX_FIFO_CTRL EQU CYREG_SCB0_RX_FIFO_CTRL
I2C_SCB__RX_FIFO_RD EQU CYREG_SCB0_RX_FIFO_RD
I2C_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB0_RX_FIFO_RD_SILENT
I2C_SCB__RX_FIFO_STATUS EQU CYREG_SCB0_RX_FIFO_STATUS
I2C_SCB__RX_MATCH EQU CYREG_SCB0_RX_MATCH
I2C_SCB__SPI_CTRL EQU CYREG_SCB0_SPI_CTRL
I2C_SCB__SPI_STATUS EQU CYREG_SCB0_SPI_STATUS
I2C_SCB__SS0_POSISTION EQU 0
I2C_SCB__SS1_POSISTION EQU 1
I2C_SCB__SS2_POSISTION EQU 2
I2C_SCB__SS3_POSISTION EQU 3
I2C_SCB__STATUS EQU CYREG_SCB0_STATUS
I2C_SCB__TX_CTRL EQU CYREG_SCB0_TX_CTRL
I2C_SCB__TX_FIFO_CTRL EQU CYREG_SCB0_TX_FIFO_CTRL
I2C_SCB__TX_FIFO_STATUS EQU CYREG_SCB0_TX_FIFO_STATUS
I2C_SCB__TX_FIFO_WR EQU CYREG_SCB0_TX_FIFO_WR
I2C_SCB__UART_CTRL EQU CYREG_SCB0_UART_CTRL
I2C_SCB__UART_RX_CTRL EQU CYREG_SCB0_UART_RX_CTRL
I2C_SCB__UART_RX_STATUS EQU CYREG_SCB0_UART_RX_STATUS
I2C_SCB__UART_TX_CTRL EQU CYREG_SCB0_UART_TX_CTRL

; I2C_SCB_IRQ
I2C_SCB_IRQ__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
I2C_SCB_IRQ__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
I2C_SCB_IRQ__INTC_MASK EQU 0x400
I2C_SCB_IRQ__INTC_NUMBER EQU 10
I2C_SCB_IRQ__INTC_PRIOR_MASK EQU 0xC00000
I2C_SCB_IRQ__INTC_PRIOR_NUM EQU 3
I2C_SCB_IRQ__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
I2C_SCB_IRQ__INTC_SET_EN_REG EQU CYREG_CM0_ISER
I2C_SCB_IRQ__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; I2C_SCBCLK
I2C_SCBCLK__DIVIDER_MASK EQU 0x0000FFFF
I2C_SCBCLK__ENABLE EQU CYREG_CLK_DIVIDER_A00
I2C_SCBCLK__ENABLE_MASK EQU 0x80000000
I2C_SCBCLK__MASK EQU 0x80000000
I2C_SCBCLK__REGISTER EQU CYREG_CLK_DIVIDER_A00

; I2C_scl
I2C_scl__0__DM__MASK EQU 0x07
I2C_scl__0__DM__SHIFT EQU 0
I2C_scl__0__DR EQU CYREG_PRT4_DR
I2C_scl__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
I2C_scl__0__HSIOM_MASK EQU 0x0000000F
I2C_scl__0__HSIOM_SHIFT EQU 0
I2C_scl__0__INTCFG EQU CYREG_PRT4_INTCFG
I2C_scl__0__INTSTAT EQU CYREG_PRT4_INTSTAT
I2C_scl__0__MASK EQU 0x01
I2C_scl__0__PC EQU CYREG_PRT4_PC
I2C_scl__0__PC2 EQU CYREG_PRT4_PC2
I2C_scl__0__PORT EQU 4
I2C_scl__0__PS EQU CYREG_PRT4_PS
I2C_scl__0__SHIFT EQU 0
I2C_scl__DR EQU CYREG_PRT4_DR
I2C_scl__INTCFG EQU CYREG_PRT4_INTCFG
I2C_scl__INTSTAT EQU CYREG_PRT4_INTSTAT
I2C_scl__MASK EQU 0x01
I2C_scl__PC EQU CYREG_PRT4_PC
I2C_scl__PC2 EQU CYREG_PRT4_PC2
I2C_scl__PORT EQU 4
I2C_scl__PS EQU CYREG_PRT4_PS
I2C_scl__SHIFT EQU 0

; I2C_sda
I2C_sda__0__DM__MASK EQU 0x38
I2C_sda__0__DM__SHIFT EQU 3
I2C_sda__0__DR EQU CYREG_PRT4_DR
I2C_sda__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
I2C_sda__0__HSIOM_MASK EQU 0x000000F0
I2C_sda__0__HSIOM_SHIFT EQU 4
I2C_sda__0__INTCFG EQU CYREG_PRT4_INTCFG
I2C_sda__0__INTSTAT EQU CYREG_PRT4_INTSTAT
I2C_sda__0__MASK EQU 0x02
I2C_sda__0__PC EQU CYREG_PRT4_PC
I2C_sda__0__PC2 EQU CYREG_PRT4_PC2
I2C_sda__0__PORT EQU 4
I2C_sda__0__PS EQU CYREG_PRT4_PS
I2C_sda__0__SHIFT EQU 1
I2C_sda__DR EQU CYREG_PRT4_DR
I2C_sda__INTCFG EQU CYREG_PRT4_INTCFG
I2C_sda__INTSTAT EQU CYREG_PRT4_INTSTAT
I2C_sda__MASK EQU 0x02
I2C_sda__PC EQU CYREG_PRT4_PC
I2C_sda__PC2 EQU CYREG_PRT4_PC2
I2C_sda__PORT EQU 4
I2C_sda__PS EQU CYREG_PRT4_PS
I2C_sda__SHIFT EQU 1

; UART_ISR
UART_ISR__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
UART_ISR__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
UART_ISR__INTC_MASK EQU 0x800
UART_ISR__INTC_NUMBER EQU 11
UART_ISR__INTC_PRIOR_MASK EQU 0xC0000000
UART_ISR__INTC_PRIOR_NUM EQU 3
UART_ISR__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
UART_ISR__INTC_SET_EN_REG EQU CYREG_CM0_ISER
UART_ISR__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; UART_rx
UART_rx__0__DM__MASK EQU 0x7000
UART_rx__0__DM__SHIFT EQU 12
UART_rx__0__DR EQU CYREG_PRT0_DR
UART_rx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
UART_rx__0__HSIOM_MASK EQU 0x000F0000
UART_rx__0__HSIOM_SHIFT EQU 16
UART_rx__0__INTCFG EQU CYREG_PRT0_INTCFG
UART_rx__0__INTSTAT EQU CYREG_PRT0_INTSTAT
UART_rx__0__MASK EQU 0x10
UART_rx__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
UART_rx__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
UART_rx__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
UART_rx__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
UART_rx__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
UART_rx__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
UART_rx__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
UART_rx__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
UART_rx__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
UART_rx__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
UART_rx__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
UART_rx__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
UART_rx__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
UART_rx__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
UART_rx__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
UART_rx__0__PC EQU CYREG_PRT0_PC
UART_rx__0__PC2 EQU CYREG_PRT0_PC2
UART_rx__0__PORT EQU 0
UART_rx__0__PS EQU CYREG_PRT0_PS
UART_rx__0__SHIFT EQU 4
UART_rx__DR EQU CYREG_PRT0_DR
UART_rx__INTCFG EQU CYREG_PRT0_INTCFG
UART_rx__INTSTAT EQU CYREG_PRT0_INTSTAT
UART_rx__MASK EQU 0x10
UART_rx__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
UART_rx__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
UART_rx__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
UART_rx__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
UART_rx__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
UART_rx__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
UART_rx__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
UART_rx__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
UART_rx__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
UART_rx__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
UART_rx__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
UART_rx__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
UART_rx__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
UART_rx__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
UART_rx__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
UART_rx__PC EQU CYREG_PRT0_PC
UART_rx__PC2 EQU CYREG_PRT0_PC2
UART_rx__PORT EQU 0
UART_rx__PS EQU CYREG_PRT0_PS
UART_rx__SHIFT EQU 4

; UART_SCB
UART_SCB__BIST_CONTROL EQU CYREG_SCB1_BIST_CONTROL
UART_SCB__BIST_DATA EQU CYREG_SCB1_BIST_DATA
UART_SCB__CTRL EQU CYREG_SCB1_CTRL
UART_SCB__EZ_DATA00 EQU CYREG_SCB1_EZ_DATA00
UART_SCB__EZ_DATA01 EQU CYREG_SCB1_EZ_DATA01
UART_SCB__EZ_DATA02 EQU CYREG_SCB1_EZ_DATA02
UART_SCB__EZ_DATA03 EQU CYREG_SCB1_EZ_DATA03
UART_SCB__EZ_DATA04 EQU CYREG_SCB1_EZ_DATA04
UART_SCB__EZ_DATA05 EQU CYREG_SCB1_EZ_DATA05
UART_SCB__EZ_DATA06 EQU CYREG_SCB1_EZ_DATA06
UART_SCB__EZ_DATA07 EQU CYREG_SCB1_EZ_DATA07
UART_SCB__EZ_DATA08 EQU CYREG_SCB1_EZ_DATA08
UART_SCB__EZ_DATA09 EQU CYREG_SCB1_EZ_DATA09
UART_SCB__EZ_DATA10 EQU CYREG_SCB1_EZ_DATA10
UART_SCB__EZ_DATA11 EQU CYREG_SCB1_EZ_DATA11
UART_SCB__EZ_DATA12 EQU CYREG_SCB1_EZ_DATA12
UART_SCB__EZ_DATA13 EQU CYREG_SCB1_EZ_DATA13
UART_SCB__EZ_DATA14 EQU CYREG_SCB1_EZ_DATA14
UART_SCB__EZ_DATA15 EQU CYREG_SCB1_EZ_DATA15
UART_SCB__EZ_DATA16 EQU CYREG_SCB1_EZ_DATA16
UART_SCB__EZ_DATA17 EQU CYREG_SCB1_EZ_DATA17
UART_SCB__EZ_DATA18 EQU CYREG_SCB1_EZ_DATA18
UART_SCB__EZ_DATA19 EQU CYREG_SCB1_EZ_DATA19
UART_SCB__EZ_DATA20 EQU CYREG_SCB1_EZ_DATA20
UART_SCB__EZ_DATA21 EQU CYREG_SCB1_EZ_DATA21
UART_SCB__EZ_DATA22 EQU CYREG_SCB1_EZ_DATA22
UART_SCB__EZ_DATA23 EQU CYREG_SCB1_EZ_DATA23
UART_SCB__EZ_DATA24 EQU CYREG_SCB1_EZ_DATA24
UART_SCB__EZ_DATA25 EQU CYREG_SCB1_EZ_DATA25
UART_SCB__EZ_DATA26 EQU CYREG_SCB1_EZ_DATA26
UART_SCB__EZ_DATA27 EQU CYREG_SCB1_EZ_DATA27
UART_SCB__EZ_DATA28 EQU CYREG_SCB1_EZ_DATA28
UART_SCB__EZ_DATA29 EQU CYREG_SCB1_EZ_DATA29
UART_SCB__EZ_DATA30 EQU CYREG_SCB1_EZ_DATA30
UART_SCB__EZ_DATA31 EQU CYREG_SCB1_EZ_DATA31
UART_SCB__I2C_CFG EQU CYREG_SCB1_I2C_CFG
UART_SCB__I2C_CTRL EQU CYREG_SCB1_I2C_CTRL
UART_SCB__I2C_M_CMD EQU CYREG_SCB1_I2C_M_CMD
UART_SCB__I2C_S_CMD EQU CYREG_SCB1_I2C_S_CMD
UART_SCB__I2C_STATUS EQU CYREG_SCB1_I2C_STATUS
UART_SCB__INTR_CAUSE EQU CYREG_SCB1_INTR_CAUSE
UART_SCB__INTR_I2C_EC EQU CYREG_SCB1_INTR_I2C_EC
UART_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB1_INTR_I2C_EC_MASK
UART_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB1_INTR_I2C_EC_MASKED
UART_SCB__INTR_M EQU CYREG_SCB1_INTR_M
UART_SCB__INTR_M_MASK EQU CYREG_SCB1_INTR_M_MASK
UART_SCB__INTR_M_MASKED EQU CYREG_SCB1_INTR_M_MASKED
UART_SCB__INTR_M_SET EQU CYREG_SCB1_INTR_M_SET
UART_SCB__INTR_RX EQU CYREG_SCB1_INTR_RX
UART_SCB__INTR_RX_MASK EQU CYREG_SCB1_INTR_RX_MASK
UART_SCB__INTR_RX_MASKED EQU CYREG_SCB1_INTR_RX_MASKED
UART_SCB__INTR_RX_SET EQU CYREG_SCB1_INTR_RX_SET
UART_SCB__INTR_S EQU CYREG_SCB1_INTR_S
UART_SCB__INTR_S_MASK EQU CYREG_SCB1_INTR_S_MASK
UART_SCB__INTR_S_MASKED EQU CYREG_SCB1_INTR_S_MASKED
UART_SCB__INTR_S_SET EQU CYREG_SCB1_INTR_S_SET
UART_SCB__INTR_SPI_EC EQU CYREG_SCB1_INTR_SPI_EC
UART_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB1_INTR_SPI_EC_MASK
UART_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB1_INTR_SPI_EC_MASKED
UART_SCB__INTR_TX EQU CYREG_SCB1_INTR_TX
UART_SCB__INTR_TX_MASK EQU CYREG_SCB1_INTR_TX_MASK
UART_SCB__INTR_TX_MASKED EQU CYREG_SCB1_INTR_TX_MASKED
UART_SCB__INTR_TX_SET EQU CYREG_SCB1_INTR_TX_SET
UART_SCB__RX_CTRL EQU CYREG_SCB1_RX_CTRL
UART_SCB__RX_FIFO_CTRL EQU CYREG_SCB1_RX_FIFO_CTRL
UART_SCB__RX_FIFO_RD EQU CYREG_SCB1_RX_FIFO_RD
UART_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB1_RX_FIFO_RD_SILENT
UART_SCB__RX_FIFO_STATUS EQU CYREG_SCB1_RX_FIFO_STATUS
UART_SCB__RX_MATCH EQU CYREG_SCB1_RX_MATCH
UART_SCB__SPI_CTRL EQU CYREG_SCB1_SPI_CTRL
UART_SCB__SPI_STATUS EQU CYREG_SCB1_SPI_STATUS
UART_SCB__SS0_POSISTION EQU 0
UART_SCB__SS1_POSISTION EQU 1
UART_SCB__SS2_POSISTION EQU 2
UART_SCB__SS3_POSISTION EQU 3
UART_SCB__STATUS EQU CYREG_SCB1_STATUS
UART_SCB__TX_CTRL EQU CYREG_SCB1_TX_CTRL
UART_SCB__TX_FIFO_CTRL EQU CYREG_SCB1_TX_FIFO_CTRL
UART_SCB__TX_FIFO_STATUS EQU CYREG_SCB1_TX_FIFO_STATUS
UART_SCB__TX_FIFO_WR EQU CYREG_SCB1_TX_FIFO_WR
UART_SCB__UART_CTRL EQU CYREG_SCB1_UART_CTRL
UART_SCB__UART_RX_CTRL EQU CYREG_SCB1_UART_RX_CTRL
UART_SCB__UART_RX_STATUS EQU CYREG_SCB1_UART_RX_STATUS
UART_SCB__UART_TX_CTRL EQU CYREG_SCB1_UART_TX_CTRL

; UART_SCBCLK
UART_SCBCLK__DIVIDER_MASK EQU 0x0000FFFF
UART_SCBCLK__ENABLE EQU CYREG_CLK_DIVIDER_C00
UART_SCBCLK__ENABLE_MASK EQU 0x80000000
UART_SCBCLK__MASK EQU 0x80000000
UART_SCBCLK__REGISTER EQU CYREG_CLK_DIVIDER_C00

; UART_tx
UART_tx__0__DM__MASK EQU 0x38000
UART_tx__0__DM__SHIFT EQU 15
UART_tx__0__DR EQU CYREG_PRT0_DR
UART_tx__0__HSIOM EQU CYREG_HSIOM_PORT_SEL0
UART_tx__0__HSIOM_MASK EQU 0x00F00000
UART_tx__0__HSIOM_SHIFT EQU 20
UART_tx__0__INTCFG EQU CYREG_PRT0_INTCFG
UART_tx__0__INTSTAT EQU CYREG_PRT0_INTSTAT
UART_tx__0__MASK EQU 0x20
UART_tx__0__OUT_SEL EQU CYREG_UDB_PA0_CFG10
UART_tx__0__OUT_SEL_SHIFT EQU 10
UART_tx__0__OUT_SEL_VAL EQU -1
UART_tx__0__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
UART_tx__0__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
UART_tx__0__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
UART_tx__0__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
UART_tx__0__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
UART_tx__0__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
UART_tx__0__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
UART_tx__0__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
UART_tx__0__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
UART_tx__0__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
UART_tx__0__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
UART_tx__0__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
UART_tx__0__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
UART_tx__0__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
UART_tx__0__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
UART_tx__0__PC EQU CYREG_PRT0_PC
UART_tx__0__PC2 EQU CYREG_PRT0_PC2
UART_tx__0__PORT EQU 0
UART_tx__0__PS EQU CYREG_PRT0_PS
UART_tx__0__SHIFT EQU 5
UART_tx__DR EQU CYREG_PRT0_DR
UART_tx__INTCFG EQU CYREG_PRT0_INTCFG
UART_tx__INTSTAT EQU CYREG_PRT0_INTSTAT
UART_tx__MASK EQU 0x20
UART_tx__PA__CFG0 EQU CYREG_UDB_PA0_CFG0
UART_tx__PA__CFG1 EQU CYREG_UDB_PA0_CFG1
UART_tx__PA__CFG10 EQU CYREG_UDB_PA0_CFG10
UART_tx__PA__CFG11 EQU CYREG_UDB_PA0_CFG11
UART_tx__PA__CFG12 EQU CYREG_UDB_PA0_CFG12
UART_tx__PA__CFG13 EQU CYREG_UDB_PA0_CFG13
UART_tx__PA__CFG14 EQU CYREG_UDB_PA0_CFG14
UART_tx__PA__CFG2 EQU CYREG_UDB_PA0_CFG2
UART_tx__PA__CFG3 EQU CYREG_UDB_PA0_CFG3
UART_tx__PA__CFG4 EQU CYREG_UDB_PA0_CFG4
UART_tx__PA__CFG5 EQU CYREG_UDB_PA0_CFG5
UART_tx__PA__CFG6 EQU CYREG_UDB_PA0_CFG6
UART_tx__PA__CFG7 EQU CYREG_UDB_PA0_CFG7
UART_tx__PA__CFG8 EQU CYREG_UDB_PA0_CFG8
UART_tx__PA__CFG9 EQU CYREG_UDB_PA0_CFG9
UART_tx__PC EQU CYREG_PRT0_PC
UART_tx__PC2 EQU CYREG_PRT0_PC2
UART_tx__PORT EQU 0
UART_tx__PS EQU CYREG_PRT0_PS
UART_tx__SHIFT EQU 5

; Clock
Clock__DIVIDER_MASK EQU 0x0000FFFF
Clock__ENABLE EQU CYREG_CLK_DIVIDER_B00
Clock__ENABLE_MASK EQU 0x80000000
Clock__MASK EQU 0x80000000
Clock__REGISTER EQU CYREG_CLK_DIVIDER_B00

; Timer_cy_m0s8_tcpwm_1
Timer_cy_m0s8_tcpwm_1__CC EQU CYREG_TCPWM_CNT0_CC
Timer_cy_m0s8_tcpwm_1__CC_BUFF EQU CYREG_TCPWM_CNT0_CC_BUFF
Timer_cy_m0s8_tcpwm_1__COUNTER EQU CYREG_TCPWM_CNT0_COUNTER
Timer_cy_m0s8_tcpwm_1__CTRL EQU CYREG_TCPWM_CNT0_CTRL
Timer_cy_m0s8_tcpwm_1__INTR EQU CYREG_TCPWM_CNT0_INTR
Timer_cy_m0s8_tcpwm_1__INTR_MASK EQU CYREG_TCPWM_CNT0_INTR_MASK
Timer_cy_m0s8_tcpwm_1__INTR_MASKED EQU CYREG_TCPWM_CNT0_INTR_MASKED
Timer_cy_m0s8_tcpwm_1__INTR_SET EQU CYREG_TCPWM_CNT0_INTR_SET
Timer_cy_m0s8_tcpwm_1__PERIOD EQU CYREG_TCPWM_CNT0_PERIOD
Timer_cy_m0s8_tcpwm_1__PERIOD_BUFF EQU CYREG_TCPWM_CNT0_PERIOD_BUFF
Timer_cy_m0s8_tcpwm_1__STATUS EQU CYREG_TCPWM_CNT0_STATUS
Timer_cy_m0s8_tcpwm_1__TCPWM_CMD EQU CYREG_TCPWM_CMD
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK EQU 0x01
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT EQU 0
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK EQU 0x100
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT EQU 8
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK EQU 0x1000000
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT EQU 24
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK EQU 0x10000
Timer_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT EQU 16
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL EQU CYREG_TCPWM_CTRL
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK EQU 0x01
Timer_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT EQU 0
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE EQU CYREG_TCPWM_INTR_CAUSE
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK EQU 0x01
Timer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT EQU 0
Timer_cy_m0s8_tcpwm_1__TCPWM_NUMBER EQU 0
Timer_cy_m0s8_tcpwm_1__TR_CTRL0 EQU CYREG_TCPWM_CNT0_TR_CTRL0
Timer_cy_m0s8_tcpwm_1__TR_CTRL1 EQU CYREG_TCPWM_CNT0_TR_CTRL1
Timer_cy_m0s8_tcpwm_1__TR_CTRL2 EQU CYREG_TCPWM_CNT0_TR_CTRL2

; RedLED
RedLED__0__DM__MASK EQU 0x1C0000
RedLED__0__DM__SHIFT EQU 18
RedLED__0__DR EQU CYREG_PRT1_DR
RedLED__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
RedLED__0__HSIOM_MASK EQU 0x0F000000
RedLED__0__HSIOM_SHIFT EQU 24
RedLED__0__INTCFG EQU CYREG_PRT1_INTCFG
RedLED__0__INTSTAT EQU CYREG_PRT1_INTSTAT
RedLED__0__MASK EQU 0x40
RedLED__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
RedLED__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
RedLED__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
RedLED__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
RedLED__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
RedLED__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
RedLED__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
RedLED__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
RedLED__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
RedLED__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
RedLED__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
RedLED__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
RedLED__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
RedLED__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
RedLED__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
RedLED__0__PC EQU CYREG_PRT1_PC
RedLED__0__PC2 EQU CYREG_PRT1_PC2
RedLED__0__PORT EQU 1
RedLED__0__PS EQU CYREG_PRT1_PS
RedLED__0__SHIFT EQU 6
RedLED__DR EQU CYREG_PRT1_DR
RedLED__INTCFG EQU CYREG_PRT1_INTCFG
RedLED__INTSTAT EQU CYREG_PRT1_INTSTAT
RedLED__MASK EQU 0x40
RedLED__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
RedLED__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
RedLED__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
RedLED__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
RedLED__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
RedLED__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
RedLED__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
RedLED__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
RedLED__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
RedLED__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
RedLED__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
RedLED__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
RedLED__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
RedLED__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
RedLED__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
RedLED__PC EQU CYREG_PRT1_PC
RedLED__PC2 EQU CYREG_PRT1_PC2
RedLED__PORT EQU 1
RedLED__PS EQU CYREG_PRT1_PS
RedLED__SHIFT EQU 6

; timer_ISR
timer_ISR__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
timer_ISR__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
timer_ISR__INTC_MASK EQU 0x10000
timer_ISR__INTC_NUMBER EQU 16
timer_ISR__INTC_PRIOR_MASK EQU 0xC0
timer_ISR__INTC_PRIOR_NUM EQU 3
timer_ISR__INTC_PRIOR_REG EQU CYREG_CM0_IPR4
timer_ISR__INTC_SET_EN_REG EQU CYREG_CM0_ISER
timer_ISR__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 6
CYDEV_CHIP_DIE_PSOC4A EQU 3
CYDEV_CHIP_DIE_PSOC5LP EQU 5
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x04C81193
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 3
CYDEV_CHIP_MEMBER_4D EQU 2
CYDEV_CHIP_MEMBER_4F EQU 4
CYDEV_CHIP_MEMBER_5A EQU 6
CYDEV_CHIP_MEMBER_5B EQU 5
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4A
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYIPBLOCK_M0S8_CTBM_VERSION EQU 0
CYIPBLOCK_m0s8cpuss_VERSION EQU 0
CYIPBLOCK_m0s8csd_VERSION EQU 0
CYIPBLOCK_m0s8gpio2_VERSION EQU 0
CYIPBLOCK_m0s8hsiom4a_VERSION EQU 0
CYIPBLOCK_m0s8lcd_VERSION EQU 0
CYIPBLOCK_m0s8lpcomp_VERSION EQU 0
CYIPBLOCK_m0s8pclk_VERSION EQU 0
CYIPBLOCK_m0s8sar_VERSION EQU 0
CYIPBLOCK_m0s8scb_VERSION EQU 0
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 0
CYIPBLOCK_m0s8udbif_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 2
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END