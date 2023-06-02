# HW6 Report

**Aleksandar Jeremic, Jason Jiang, Andy Zhang**

**5/31/23**

## Challenge 1: Project Proposal

[Cat Tracker: Project Proposal](https://docs.google.com/presentation/d/1xfuLxy2PaP_ie7QjM4WHKkoSBVSgxtEl-8eqzutL6aY/edit?usp=share_link)

In our initial project proposal, we first went over our customer's general needs, which were to track whenever their roommate's cat entered or exited the room. The sensor also should not emit any auditory cues. After that, we conducted a potential customer survey asking for what additional features would be acceptable or appropriate and conducted background research at the same time.

After gathering all the potential customer feedback and doing the background research, we came to the conclusion that our device should contain a display showing when the cat is in the room or not, have a collar with a name tag come complementary with the sensor, and have the sensor be connected to a phone app to receive signals.

Our initial plan for our prototype was to consist of 2 parts: an emitter that sends out signals, this will be attached to the cat's collar, and a receiver that detects the signals and relays them to the phone, this will be placed on a wall that is close to the door to the room. The receiver more specifically will contain 2 adjacent infrared sensors, one closer to the door and the other slightly further away. The order in which they are triggered will determine if the cat entered the room or exited the room.

## Challenge 2: Customer Feedback & Project Plan

### Project Update
After further research and checking in with the professor, we decided on a few changes for our project. Instead of using infrared sensors, we will use low energy bluetooth sensors. In addition, we have changed our intitial prototype to now consist of 3 parts. The emitter is the same as before, attached to the collar of the cat and constantly emitting a signal. The receiver is now 2 separate parts, one is the Near sensor, which will be placed right next to the door, the other is the Far sensor, which will be placed on the other side of the room.

The algorithm for determining the position of the cat has changed too. The new algorithm will have the receivers constantly calculating the distance from the cat. The cat will have entered the room if the Near sensor detects a change in distance while the Far sensor detects a continuous decrease in distance. The cat will have left the room if the Near sensor detects a change in distance while the Far sensor detects a countinuous increase in distance.

### Customer Feedback
Our customer was generally unopposed to all the suggested changes we made. No significant suggestions were made.

### Project Plan
**6/4/23** -
Get the ESP 32s to communicate with each other. This will then allow the receivers to speak to each other, critical to the algorithm.

**6/7/23** -
Finish the poster in preparation for the final presentation.

**6/9/23** -
Finish the lab report

**6/15/23** -
Final poster presentation

## Challenge 3: Initial Prototype

