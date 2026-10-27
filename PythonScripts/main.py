import serial
from pycaw.pycaw import AudioUtilities
import subprocess
from commands import *
import pybrightness

#############################################################################################################################################

def change_volume(delta):
    """
    Изменяет громкость системы на delta процентов.
    delta > 0 — повышает, delta < 0 — понижает.
    """
    # Получаем устройство вывода по умолчанию
    device = AudioUtilities.GetSpeakers()
    
    # Текущая громкость в процентах (0.0 - 1.0 в API, но pycaw дает удобное свойство)
    # В новых версиях pycaw свойство volume_percent возвращает значение от 0 до 100
    current = device.volume_percent
    
    # Вычисляем новое значение и ограничиваем его диапазоном [0, 100]
    new_volume = max(0, min(100, current + delta))
    
    # Устанавливаем новую громкость
    device.volume_percent = new_volume
    
    print(f"Громкость ({current:.0f}): {new_volume:.0f}%")


def switch_mute():
    device = AudioUtilities.GetSpeakers()

    is_mute = device.EndpointVolume.GetMute()

    device.EndpointVolume.SetMute(not is_mute, None)
    

#############################################################################################################################################



#############################################################################################################################################

VOL_UP_ARDU = ENCODER1_R_ARDU
VOL_DOWN_ARDU = ENCODER1_L_ARDU

SWITCH_ARDU = BUTTON1_C_ARDU # переключить устройство вывода звука по умолчанию
VMUTE_ARDU = BUTTON2_C_ARDU # vol mute

#############################################################################################################################################

vol_change_step = 4

#############################################################################################################################################

over = False # для выхода из цикла
is_showed_serial_error = False # чтобы при serial.serialutil.SerialException уведомление выводилось один раз

while not over:
    try:
        ser = serial.Serial('COM9', 9600, timeout=1)
        print(r"\/Подключено\/")
        is_showed_serial_error = False
        
        while True:
            line = ser.readline().decode('utf-8', errors='ignore').strip()
            #-----------------------------------------------------------------------------------------------------------
            if line == VOL_UP_ARDU:
                change_volume(+vol_change_step)
            elif line == VOL_DOWN_ARDU:
                change_volume(-vol_change_step)
            elif line == VMUTE_ARDU:
                switch_mute()
                
            elif line == SWITCH_ARDU:
                subprocess.run("W:/QUICKACCES/DIY проекты/Мини-клавиатура/Scripts/switch.bat")
            #-----------------------------------------------------------------------------------------------------------
                
    except serial.serialutil.SerialException:
        if not is_showed_serial_error:
            print(r"**Отключено**")
            is_showed_serial_error = True

    except KeyboardInterrupt:
        over = True
        print("Остановлено")

ser.close()