# Parking-sensor

Projekt:
Czujnik parkowania

Opis projektu:
Celem projektu jest stworzenie urządzenia działającego podobnie do komercyjnych czujników parkowania wykorzystywanych w samochodach. Sygnalizacja zbliżającej się przeszkody odbędzie się poprzez sygnał dźwiękowy z buzzera oraz ewentualne wyświetlenie odległości na wyświetlaczu. 

Analiza problemu:
W celu określenie odległości od przeszkody wykorzystany zostanie sensor ultradźwiękowy HC-SR04. Jego zakres działania to od 2cm do aż 2m, więc spełnia wymagania tego projektu. Komunikuję się on z płytką przy pomocy interfejsu SPI zatem konieczne będzie stworzenie odpowiednich bibliotek. Konieczne będzie wykorzystanie wbudowanego przetwornika ADC, do przetworzenia danych zebranych przez czujnik. Dane w postaci cyfrowej będą wykorzystane do oceny odległości, która będzie widoczna na ekranie oraz do aktywowania buzzera, jeśli zostanie przekroczona wartość progowa.
Do obsługi wyświetlacza wykorzystany zostanie interfejs I2C.

Plan realizacji:
Do realizacji projektu użyjemy:
- płytki ewaluacyjnej FRDM-K20D50M wyposażonej w procesor Cortex M4
-wyświetlacz LCD 2x16 (I2C)
-sensor ultradźwiękowy HC-SR04 (SPI)
-buzzer z generatorem (PWM)
