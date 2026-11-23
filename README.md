# 🔬How does sound intensity relate to the reaction time of a sound sensor module?

## Objective and Hypothesis
This experiment aims to measure how the reaction time of a KY-037 sound sensor varies in relation to changes in the intensity of the sound it detects.
My hypothesis is that the sensor's reaction time varies in direct proportion to the sound intensity.

## Hardware Used
* Arduino Uno R3
* KY-037 sound sensor module
* Passive buzzer
* Breadboard
* Jumper wires

## Circuit and Connections
The KY-037 sensor is connected to the Arduino as follows:
* **VCC** → 5V
* **GND** → GND
* **AO** → Pin A0
* **DO** → Pin 7

The buzzer is connected to the Arduino as follows:
* **VCC** → Pin 8
* **GND** → GND

* Circuit diagram:
<img width="1000" height="752" alt="fe380e8d-f4a0-4fca-8c57-3f7959bca184" src="https://github.com/user-attachments/assets/efaf48b2-52ec-4840-80e1-0688bce653b6" />

## Results
The data obtained via the serial monitor was exported to the files `/tabla.csv` and `/data_serial_monitor.txt`.

## Conclusions
* **Timing behavior:** When comparing frequencies of 250 Hz, 4000 Hz, and 10000 Hz, the sensor performed optimally, with a reaction time between 20 and 28 microseconds—a duration accounted for primarily by the time the Arduino takes to execute the `digitalRead()` function.

* **Analog sensor behavior:** Analog readings remained around 512 because the analog output voltage oscillates as a sine wave—exactly 4,000 times per second—around its reference voltage (typically half the supply voltage; e.g., approximately 2.5V when powered with 5V).

* **Hypothesis evaluation:** My initial theory was that intensity would affect timing; however, the data shows that the reaction time is independent of the sound frequency.

## Community and Discussions
I have begun publishing my experiments on GitHub. If you would like to replicate this experiment, have questions regarding sensor calibration, or wish to suggest improvements to the code, please feel free to open a thread in the **Discussions** tab of this repository ^_^
