# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Lasse\Documents\GitHub\PSoC_Master\PSoC_Master\PSoC_Master.cydsn\PSoC_Master.cyprj
# Date: Mon, 20 Apr 2015 06:23:49 GMT
#set_units -time ns
create_clock -name {I2C_SCBCLK(FFB)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {Clock(FFB)} -period 1666.6666666666665 -waveform {0 833.333333333333} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {UART_SCBCLK(FFB)} -period 8666.6666666666661 -waveform {0 4333.33333333333} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {I2C_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 15 31} [list]
create_generated_clock -name {Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 41 81} -nominal_period 1666.6666666666665 [list]
create_generated_clock -name {UART_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 209 417} -nominal_period 8666.6666666666661 [list]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]


# Component constraints for C:\Users\Lasse\Documents\GitHub\PSoC_Master\PSoC_Master\PSoC_Master.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Lasse\Documents\GitHub\PSoC_Master\PSoC_Master\PSoC_Master.cydsn\PSoC_Master.cyprj
# Date: Mon, 20 Apr 2015 06:23:46 GMT
