# Arduino CO2 Detector

Simple CO2 detector for arduino boards.

## Hardware required

- 1x Arduino board (or compatible)
- 1x MQ135 sensor module
- 5x F-M female to male Dupont wires

## Software required

- Arduino IDE: https://www.arduino.cc/en/software
- MQ135 library: https://github.com/Phoenix1747/MQ135

## Usage

1. Wire the components to the board
2. Now you need to leave the board ON for 24/48h outside. It doesn't need to have the program uploaded. This step is needed for the MQ135 module to be heated
3. Open arduino's IDE
4. Edit arduino-co2-detector.ino and set CALIBRATE_MODE to true
5. Upload the program with arduino's IDE
6. Outside, let it run until it gives you an "Average Rzero" and several PPM readings
7. Check the PPM, it should be around 400-420 unless you are in a highly poluted area. You can check the latest PPM in clean air in: https://www.co2.earth/daily-co2
8. Save the average rzero and set it in the RZERO constant. Set CALIBRATE_MODE to false
9. Re-upload the program with arduino's IDE
10. You may now leave the board in the desired place. Don't forget to turn it on!
