

<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/walitor/Parking-sensor">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Parking sensor</h3>

  <p align="center">
    HC-SR04 rangefinder as a parking sensor with FRDM KL05Z board
    <br />
    <br />
  </p>
</p>



<!-- TABLE OF CONTENTS -->
<details open="open">
  <summary><h2 style="display: inline-block">Table of Contents</h2></summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgements">Acknowledgements</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

Parking sensor project for FRDM KL05Z development board. FRDM KL05Z inbuilt I2C peripheral is used to communicate with 2x16 LCD screen and HC-SR04 rangefinder.
HC-SR04 is an ultrasonic rangefinder, made by [Cytron Technologies](https://www.cytron.io/).
2x16 LCD is used to display current distance (between 2 and 20 m) between object and rangefinder, sound feedback is provided with a buzzer.
Build by: 
*[Jan Magiera](https://github.com/J-Magiera)

*[Szymon Adamus](https://github.com/walitor)




### Built With

*



<!-- GETTING STARTED -->
## Getting Started

Connect FRDM-KL05Z pins with LCD, rangefinder and buzzer. Connect KL05Z with a programming unit, such as PC.
Upload software, disconnect programming unit and power KL05Z with 5V/1A supply.

### Components

FRDM KL05Z evaluation board

PWN Buzzer
   
HC-SR04 ultrasonic rangefinder


### Installation

1. Clone the repo
   ```sh
   git clone https://github.com/walitor/Parking-sensor
   ```
2. Open ARM IDE (such us Keil uVision)

3. Select appropriate microcontroller 

4. Add files necessary to launch with CMSIS-DAP

5. Attach files from this repo to project

6. Build and upload



<!-- USAGE EXAMPLES -->
## Usage

Empty as of today




<!-- CONTACT -->
## Contact

Jan Magiera: (Jan.Magiera@Protonmail.com)

Adamus Szymon: ///

Project Link: [https://github.com/walitor/Parking-sensor](https://github.com/walitor/Parking-sensor)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements







