# 💡 Pick_2_Light Master System

The **Pick_2_Light Master** project is an embedded system designed to manage inventory efficiently by communicating with **Pick_2_Light Slave** devices through **CAN (Controller Area Network)** protocol. The master system accepts user input through a **UART** interface, transmits **Node ID (N_ID)** and **Updated Stock (U_ST)** information via CAN, and displays received data on **Tera Term**.

---

## 🛠 Project Features

- **CAN Communication:** Transmits and receives inventory data to and from **Pick_2_Light Slave** devices.
- **User Interface:** Accepts **Node ID** and **Updated Stock** inputs via **UART**.
- **Tera Term Display:** Shows received **Node ID** and **Stock Data** in a terminal interface.
- **Data Handling:** Ensures valid numeric input with real-time feedback.
- **Interrupt-Driven Communication:** Utilizes external interrupts for UART data reception.
- **Error Handling:** Manages invalid inputs and buffer overflows gracefully.

---

## 🧰 Technology Stack

- **Microcontroller:** PIC Microcontroller
- **Communication Protocol:** CAN (Controller Area Network)
- **Serial Communication:** UART (Universal Asynchronous Receiver/Transmitter)
- **Input Interface:** Tera Term via UART
- **Output Interface:** Tera Term terminal display
- **Interrupt Handling:** Manages UART input with **ISR (Interrupt Service Routine)**

---

## 🔄 Project Workflow

1. **Initialization:** Configures **CAN**, **UART**, and **Interrupts**.
2. **Data Reception:**
   - Waits for **CAN** messages from **Slave** devices.
   - Displays received **Node ID** and **Updated Stock** values on **Tera Term**.
3. **User Input Handling:**
   - Prompts for **Node ID** and **Updated Stock** through **UART**.
   - Accepts only numeric inputs (max 4 digits) with input validation.
4. **CAN Transmission:**
   - Packages and transmits input data to **Slave** devices.
   - Resets input state after successful transmission.
5. **Interrupt Handling:**
   - **ISR** manages received **UART** data and stores it in a buffer for processing.

---

## 📂 File Structure

- `main.c` - Core application logic, manages UART input and CAN communication.
- `can.c` - Initializes CAN module, handles CAN message transmit and receive.
- `uart.c` - Manages UART initialization and data transmission to **Tera Term**.
- `isr.c` - **Interrupt Service Routine** for handling UART receive interrupts.
- `main.h` - Contains global definitions, function prototypes, and configuration settings.

---

## 🚀 Future Enhancements

- **LCD Interface:** Display received data on an **LCD** instead of **Tera Term**.
- **Advanced Input Validation:** Add support for alphanumeric **Node IDs**.
- **Wireless Communication:** Introduce **Bluetooth/WiFi** for remote management.
- **Automated Testing:** Implement diagnostics for **CAN** and **UART** communications.
- **Web Interface:** Display inventory data on a **web dashboard**.

---

## 📧 Contact

For any questions, feel free to reach out:

- **Vivek**
- Email: [gopivivek57@gmail.com](mailto:gopivivek57@gmail.com)
- LinkedIn: [Vivek](https://www.linkedin.com/in/vivek57/)
