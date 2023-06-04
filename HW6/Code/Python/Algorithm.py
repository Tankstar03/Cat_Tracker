# -*- coding: utf-8 -*-
"""
Created on Sat Jun  3 18:00:20 2023
HW6 ALGORITHM CODE

"""

from ECE16Lib.Communication import Communication
from ECE16Lib.CircularList import CircularList
from matplotlib import pyplot as plt
from time import time, sleep
import math
import numpy as np
import ECE16Lib.DSP as filt


    
    
    
if __name__ == "__main__":
  num_samples = 250               # 5 seconds of data @ 50Hz
  # with 5 seconds of data i no longer need to do passing timing, I can just look at my values in my circular list and go from te whole list for 5 secodns or 50 values which is 1 second at 50hz
  refresh_time = 0.1              # update the plot every 0.1s (10 FPS)
  active = 0
  RSSI_1 = CircularList([], num_samples)
  RSSI_2 = CircularList([], num_samples)
  grad_RSSI_2 = CircularList([],num_samples)
  
  cat_in_room = 0
  near_door = -70

  comms = Communication("COM3", 2000000)
  sleep(3)
  comms.clear()                   # just in case any junk is in the pipes
  comms.send_message("wearable")# begin sending data

  try:
    previous_time = 0
    
    while(True):
      message = comms.receive_message()
      if(message != None):
        try:
          
          (m1, m2) = message.split(',')
        except ValueError:        # if corrupted data, skip the sample
          continue


        # add the new values to the circular lists
        RSSI_1.add(int(m1))
        RSSI_2.add(int(m2))
        grad_RSSI_2.add(filt.gradient(RSSI_2))
        
        
        # if enough time has elapsed, clear the axis, and plot az
        current_time = time()
        
        if (current_time - previous_time > refresh_time):
          previous_time = current_time
          plt.cla()

          plt.plot(RSSI_1)

          plt.show(block=False)
          plt.pause(0.01)
        
        if (not cat_in_room):
            if (np.max(RSSI_1[-50:]) > near_door and np.max(grad_RSSI_2[-50:])>0):  #add check for gradient of RSSI_2         
                comms.send_message("1")
                cat_in_room = 1
            else:
                comms.send_message("0")
                cat_in_room = 0
        else:
            if (np.max(RSSI_1[-50:]) > near_door and np.max(grad_RSSI_2[-50:])>0):# add check for the gradient of RSSI_2
                comms.send_message("1")
                cat_in_room = 1
            else:
                comms.send_message("0")
                cat_in_room = 0

  except(Exception, KeyboardInterrupt) as e:
    print(e)                     # Exiting the program due to exception
  finally:
    comms.close()