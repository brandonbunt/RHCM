# RHCM
Radial Heat Conduction Module

Final stage of my ME thesis at the Cooper Union: Developing a test rig that can give a benchmark k-value for low thermal conductivity materials using steady-state methods. 
This design is inspired by hot-wire methods as well as the losses from the LHCM. Instead of trying all sorts of techniques to reduce the radial heat loss in the LHCM, this design embraces heat transfer in the radial direction, and seeks to measure it as the primary form of measuring k. 

The downside compared to the LHCM is the oddly-shaped cylindrical towers for the samples. 

Temperature data was gathered using two needle tip K-type thermocouples and MCP9601 thermocouple amplifier breakout boards from Adafruit. Wiring utilizes I2C, and up to 8 total amplifiers can be read with this configuration without a multiplexer. 
