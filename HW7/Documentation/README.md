# HW7 Report

**Aleksandar Jeremic, Jason Jiang, Andy Zhang**

**6/11/23**

## Challenge 1: Observations and Feedback

### Iteration 1:
The prototype will like previously planned, consist of an emitter and 2 receivers, one near the door and the other away from the door.

We asked the customer for any feedback regarding this iteration of our prototype, and she did not express any major concerns. 

### Iteration 2:
Our design underwent significant changes. Now, there will be an emitter, 4 receivers, and a Hub. Each receiver will be spread across the room and, like previously, will be sending RSSI values consistently to the hub, where the state machine will be to determine whether or not the cat has entered or left the room.

We asked our customer for any feedback regarding this new iteration. The only demand we got was that to make sure it will work properly in the end.

## Challenge 2: Prototype Tests

### Iteration 1:
After discussing and conducting a thought experiment with the professor, we determined that this iteration was not feasible. Since given the possibility that the device will output an incorrect result, this can cause all subsequent detections to be erroneous. As a result, the risk for such errors to occur was too high, and we decided to scrap this design.

### Iteration 2:
