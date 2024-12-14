# **Arduino Relay Timer with Manual Override Button**

This project controls a relay module using an Arduino, providing both automated timer-based operation and manual override functionality via a button. The system is designed for applications where a device needs to be powered on and off cyclically over a set period, such as lighting, pumps, or other appliances.

## **Features:**
## **Timer-Based Relay Control:**
The relay turns ON for a specified duration (relayOnTime) and then OFF for another specified duration (relayOffTime).

By default, the relay is OFF when the Arduino powers up.

## **Manual Override Button:**
A button connected to the Arduino allows manual toggling of the relay state (ON/OFF).

The button uses an internal pull-up resistor for stable input and includes a debounce mechanism to prevent false triggers.

 ## **Status Feedback:**
Messages are printed to the Serial Monitor to indicate changes in the relay state (e.g., "Relay ON (Button Press)" or "Relay OFF (Timer)").

## **Customizable Timing:**
The timing for the relay ON and OFF states is set in milliseconds. For example:

relayOnTime is set to 6 hours (in milliseconds).
        
 relayOffTime is set to 18 hours (in milliseconds).
        
You can modify these durations for testing (e.g., 20 seconds for ON and 10 seconds for OFF) or for different use cases.

## **How It Works:**

## **Timer Control:**
The system tracks time using the millis() function, which provides the number of milliseconds since the Arduino started.

If the relay is OFF, it checks whether the specified ON duration (relayOnTime) has passed. When it has, the relay turns ON, and the timer resets.

Similarly, if the relay is ON, it checks whether the OFF duration (relayOffTime) has passed. When it has, the relay turns OFF, and the timer resets.

## **Manual Override:**
Pressing the button toggles the relay state immediately, overriding the timer logic temporarily.

For example, if the relay is ON due to the timer, pressing the button will turn it OFF, and vice versa.

## **Debouncing:**
A small delay (200 ms) is used to debounce the button, preventing unintentional multiple toggles caused by mechanical noise.

## **Hardware Setup:**

Relay Module: Connected to digital pin relayPin (default: pin 13).

Button: Connected to digital pin buttonPin (default: pin 2) with an internal pull-up resistor.

Power Supply: Ensure the Arduino and relay module are powered appropriately for the connected appliance.

## **Code Variables:**

relayOnTime: Duration (in milliseconds) for the relay to stay ON (default: 6 hours).

relayOffTime: Duration (in milliseconds) for the relay to stay OFF (default: 18 hours).

previousMillis: Tracks the last time the relay state was updated.

relayState: Stores the current state of the relay (ON or OFF).

## **Serial Debugging:**

The code prints messages to the Serial Monitor (baud rate: 9600) to provide real-time updates about the relay's state and the reason for the state change (e.g., timer or button press).

![alt text](https://github.com/Spuda/Arduino-light-switch/blob/[branch]/Spectacular Kup-Wolt.png?raw=true)
