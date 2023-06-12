# HW7 Report

**Aleksandar Jeremic, Jason Jiang, Andy Zhang**

**6/11/23**

## Challenge 1: Observations and Feedback

### Iteration 1:
The prototype will like previously planned, consist of an emitter and 2 receivers, one near the door and the other away from the door.

We asked the customer for any feedback regarding this iteration of our prototype, and she did not express any major concerns. 

### Iteration 2:
Our design underwent significant changes. Now, there will be an emitter, 4 receivers, and a hub. Each receiver will be spread across the room and, like previously, will be sending RSSI values consistently to the hub, where the state machine will be to determine whether or not the cat has entered or left the room.

We asked our customer for any feedback regarding this new iteration. The only demand we got was that to make sure it will work properly in the end.

## Challenge 2: Prototype Tests

### Iteration 1:
After discussing and conducting a thought experiment with the professor, we determined that this iteration was not feasible. Since given the possibility that the device will output an incorrect result, this can cause all subsequent detections to be erroneous. As a result, the risk for such errors to occur was too high, and we decided to scrap this design.

### Iteration 2:
With the new iteration containing 4 receivers and a separate hub, we were then able to successively conduct tests. 
Our tests primarily revolved around finding a threshold value that would separate the inside of the room from the outside of the room. 
Whenever the sum of all the RSSI values exceed this threshold value, the hub will determine the cat to be outside the room, otherwise the cat would be considered to be inside the room. 
To conduct these tests, we took the emitter and moved it around the room and outside the room to find the ideal value for our threshold.



Our first design involved a single sensor in the back corner of the room, this setup was even less accurate if the person was near the door,
it was also having a similar issue to the 2 sensor design where it would sense the cat "in the room" if the cat was on the other side of the wall near the sensor.

![](https://github.com/UCSD-ECE16/ece16-sp23-team-cat-tracker/blob/main/HW7/Documentation/Gifs/1sensor.jpg)


Our second design involved only 2 sensors, we took 2 sensors and placed both in the back of the room furthest from the door.
This set up led to slightly less accurate results compared to our 4 sensor test. This test especially would fail when someone was on the other side of the wall near the sensors,
The sensors would sense it near as if it were in the room but nearer to the door (away from the sensors)

![](https://github.com/UCSD-ECE16/ece16-sp23-team-cat-tracker/blob/main/HW7/Documentation/Gifs/2sensor.jpg)

Our final design involved all 4 sensors in each corner of the room, this design had alot of success and created very accurate readings for when the cat was in the room.

![](https://github.com/UCSD-ECE16/ece16-sp23-team-cat-tracker/blob/main/HW7/Documentation/Gifs/4sensor.jpg)



## Challenge 3: Final Product

