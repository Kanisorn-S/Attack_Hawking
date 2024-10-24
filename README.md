# Hand Gesture Controlled Mobile Robot

## Introduction

It is widely agreed that the modern age has ushered in a leap in development for human society by creating conveniences for all but that convenience also creates problems that no one could have expected. The convenience of automatic devices leads to people moving their bodies less, especially their hands, which they often do in limited movements such as prolonged extension or flexions of the wrist. These monotonous movements of the hand lead to a problem called carpal tunnel syndrome where the tendon in the hands swells which then puts pressure on the nerves and veins. 

This problem has been a growing concern in office workers and students so to address this, we introduce Attack Hawking, a hand gesture-controlled mobile robot designed to prevent and alleviate the symptoms of carpal tunnel syndrome while bringing in a fun challenge for all ages. Attack Hawking's core functionality revolves around hand gesture control, allowing users to move, aim, and shoot at targets by using specific hand movements, specially designed to exercise the hands in a natural and engaging way. This process encourages a wide range of motion in the hands and wrists, promoting healthier movement patterns and preventing stiffness.

## Methodology

#### *Initial Design*

The topic of the project that we had to come up with was a toy that incorporates some kind of technology. We decided that our project would be a follow up to our previous project, Hawking which is a mobile robot by making a kind of RC car. While coming up with ideas for other potential toys, an interesting proposal came up to make a ballista which will shoot BBQ sticks at a target. We decided that both the RC car and ballista were interesting so we decided to combine both of them into one which became a ballista on top of a car or what we call, Attack Hawking.

While deciding what the control would be, a remote control was initially chosen but it was too basic and was already numerous in the market. A control that would truly be unique would not be an extension at all but simply out of our own hands. We chose our hands as the control for our car. Each hand gesture would correspond to an action for the car whether that be for moving or for shooting. We decided that the hand gestures would not only make for a unique experience but it would also help with preventing carpal tunnel syndrome which is quite common for those who use the computer a lot. So we looked for gestures that would move the hand in a wide range of motion to use as the controls.

### Hardware

#### *Designing the robot*

Initially, our design was supposed to use a ballista to shoot a circular projectile (See Fig. 6(a)), but after further research and the new requirement from the ID student, we chose to make a turret, using flywheel wheel cannon design, utilizing two DC motors and wheels (See Fig. 6(b)). The flywheel cannon will be set in vertical orientation. The projectile will be loaded from the top and will be using a foam ball. The tilt of the cannon will be controlled by a servo motor. The car design will be using Mecanum wheels driven by servo motors and the structure will be made using acrylic sheet. The robot will be powered by 4 AA batteries and lithium ion batteries. 

// pic

Fig. 6(a) Initial Design with Mounted Ballista

// pic

Fig. 6(b) New Design with Flywheel Cannon

#### *Car body and Cannon design*

The car is made using a 5mm acrylic sheet cut into a structural piece and bolted together in a 2 layer structure. The servo motors are also bolted in in this process. The Mecanum wheels are mounted to the servo motors using 3D printed connectors.

// pic 

Fig. 7 3D Model of the Cannon and Base

The cannon is initially designed to be all 3d printed (See Fig. 7), the DC motors housing and micro servo housing is designed in the cannon structure. The cannon is designed to be 30 cm long in order to look like the design from ID as much as possible. But after testing the prototype, the pressure formed during firing prevented the ball from reaching the design momentum, so we changed the barrel to a smaller pvc pipe. 

The base of the cannon was also supposed to be made using 3D print, but since there were time constraints, we remodeled the cannon base using 5 mm acrylic structure. The structure is made to carry the weight of the cannon and also house the servo motor for tilt. 

On the top part of the car structure the turret is mounted using five  3 cm  standoff screws. The batteries and other electronics are placed on the top acrylic part and covered with plastic exterior made by ID students.

#### *Target Design*
	
The target is needed for the Attack Hawking to have a purpose. The target was initially just a large blank board with holes of different sizes drilled into it. Each hole will have a corresponding point for its size with smaller ones giving more points due to the difficulty. There would also be a net to catch the balls that were shot and to tally the points up afterwards.  

// pic

Fig. 8(a) Early Prototype of New Target Design

// pic

Fig. 8(b) New Target Design of Different Sizes

The initial design was scrapped due to its simplicity and a need for something interesting. We decided to create a target that is similar to ones from archery that when a ball hits will immediately add up the scores displayed on screen. When assembling the targets, we used DIY items which can be found anywhere to create them. They consist of ice-cream sticks, plastic straws, future board, colored paper and glue (See Fig. 8(a)). To detect the target being hit, an infrared sensor is placed behind the counter weight which will detect a change in distance whenever the target is hit. There are a total of 4 targets of different sizes (See Fig. 8(b)). These targets are then put in a box which is reused from our previous project, the automatic curtain and modified a little to suit the needs of this project. When everything is in place, we attach the breadboard and battery rack onto the walls and wire everything up. We also coded so that the same target cannot be hit twice and only score once until another is hit.
	
#### *Component Selection and Ordering*

Informed by design iterations, components were selected, and orders were placed. Modifications were made during this stage due to budget constraints.

The robot body is mainly made of 5mm Laser Cutted Acrylic Plates, as some parts like wheel-to-motor axes are made of 3D printed ABS Plastics. Our robot wheels were selected to be Mecanum wheels, as they can make the robot travel in diagonal directions. The driving motor must be strong enough to drive the whole body of the robot so it is selected to be MG996R Large Metal Geared Continuous Servo Motors. 

The cannon’s whole body is made of 3D printed ABS plastic. The Cannon’s firepower lies at the two Tamiya DC motors spinning at the top and the bottom of the track at high speed.  The ball bullet controller is a Continuous Micro Servo motor that lets out the ball once per time when the command is called. The cannon’s upward angle can be adjusted by the TD8120MG High Torque Metal Shell Large Angle Digital Steering Gear Servo Motor. The whole cannon is placed on the four 30mm Pillar Nuts around the back of the robot.

Motor controller should be a servo controller type that controls all servo motors in the robot, so it is selected to be a PCA9685. The robot receives commands from the computer through ESP-12F ESP8266-12F Wifi Arduino Board. Every component on the robot is powered by 18650 Lithium Batteries connected to the adjustable step down module and the AA batteries. Around the center of the board, there is a small breadboard placed there.

The target rack's whole body is made of laser cutted acrylic plates wrapped around with gray paper. There are four targets placed inside the rack, each of them is made of future board, popsicle sticks, plastic straws, thick paper and printed target picture. The counter-weight of the target is made of future boards. Apart from the counter-weight, there is an IR sensor placed on a piece of a popsicle stick pointing at the weight. The breadboard, AA battery rack, and ESP-12F ESP8266-12F Wifi Arduino Board are placed at the side of the board, powering the target and connecting signals back to the computer.

### Software

#### *The Integration of Computer Vision and Machine Learning in Gesture Recognition*

The gesture recognition we use is based on a Python script from the internet[11], let's call it "app.py." This script integrates computer vision and machine learning to achieve real-time gesture recognition using OpenCV and MediaPipe.
The core of "app.py" involves strategically importing libraries: OpenCV (cv2) for image processing, MediaPipe for hand tracking, and standard Python libraries for data handling. The initialization process includes loading label files in CSV format, which contain crucial data on keypoints and gesture classifications. This setup enables advanced gesture analysis by establishing necessary parameters and reference points.

Moreover, the script sets up data structures like deques for managing frame-per-second (FPS) calculations and storing gesture history. These steps are essential for handling real-time data efficiently and ensuring the application remains performant and responsive.

At the heart of "app.py" is its main processing loop, which captures and processes video frames from a webcam continuously. This loop includes key press detection for user interaction, allowing users to exit or switch modes seamlessly. Frame processing involves image mirroring and color space conversions to optimize the feed for hand tracking. MediaPipe plays a critical role here, processing the video to detect hand landmarks, which is the foundation for gesture recognition.

Once landmarks are detected, the script calculates gestures based on predefined keypoints. Each detected hand is analyzed within a bounding rectangle, identifying specific gestures and displaying this information on the screen. This capability not only demonstrates the script's ability to recognize and interpret gestures but also provides interactive feedback to the user in real-time.

Utility functions in "app.py" are also crucial. These functions draw keypoints, gesture information, and other UI elements like FPS and mode indicators on the video feed, enhancing the user interface and interaction experience. These details are vital for making the application user-friendly and accessible, allowing users to understand and react to the presented information effectively.

User interaction with the application is primarily managed through keyboard inputs, a simple and effective method of control that ensures ease of use and quick adaptation. This interaction pattern allows users to control the application's modes and exit without needing complex commands or interfaces, making the technology accessible to everyone.

#### *Learning the Hand Gesture*

A typical keypoint classification notebook starts with an introduction outlining the problem statement and objectives, followed by importing essential libraries like TensorFlow, Keras, and NumPy for data handling and machine learning. The notebook progresses by loading datasets containing image-derived keypoints and applying preprocessing techniques such as normalization or augmentation to prepare the data for training. The neural network model's architecture is then defined, ranging from convolutional neural networks (CNNs) for image-based keypoints to simpler dense networks for less complex data.

Training involves setting up loss functions, optimizers, and metrics, and running the model on preprocessed data while monitoring performance with validation data. After training, the model is evaluated on a separate test set to determine its accuracy and generalization capabilities, often visualized through confusion matrices or accuracy plots. Fine-tuning follows, adjusting hyperparameters or implementing techniques like dropout or batch normalization to enhance performance. Finally, the trained model is saved for integration into applications, such as using real-time video data for gesture recognition in the main application described in "app.py."

In order for the model to train, we must provide it with enough data. We can achieve this by recording the coordinates of different landmarks (See Fig. 9), provided by MediaPipe’s hand solution, for different hand gestures along with an integer which is used to identify the hand gesture.

// pic

Fig. 9 Recording Landmarks’ Coordinates for a Hand Gesture

In the model development phase, raw keypoints (See Fig. 10) are transformed into a machine learning-friendly format, often through normalization or calculating distances and angles between keypoints to maintain robustness against variations in image scale and orientation. Selecting the right model is crucial, with options ranging from convolutional neural networks (CNNs) for image-based analysis to simpler architectures for coordinate inputs. Training involves adjusting model weights through backpropagation, using a loss function to minimize errors between predicted and actual gesture labels.

// pic

Fig. 10 Raw Keypoints Stored as a CSV File

The deployment and optimization stages focus on integrating the trained model into real-time applications and ensuring it operates efficiently. Techniques like model quantization or pruning enhance performance, while hyperparameter tuning and data augmentation improve the model’s accuracy and robustness. Advanced methods like transfer learning or ensemble learning are also used to leverage related pre-trained models or combine multiple model outputs, boosting overall accuracy and making the gesture recognition system more effective and responsive in practical applications.

#### *Communication Between Computer, Car, and Target*

Our initial plan is to use Blynk in order to communicate with both the ESP8266, located within the car, and the ESP32, located within the target box. After a presentation with the professor, he pointed out that using Blynk might cause a delay in the communication process, recommending us to look into other forms of communication protocol, such as MQTT, HTTP, or ESP-NOW. 

After looking into other communication protocols, we found out that the upgraded performance  in terms of speed when using other protocols, such as MQTT, is not as significant as we had hoped. Furthermore, many protocols that we have tried had compatibility problems with the PCA9685, which is used to control the servo motors. Due to the differences in the delay time of communication between Blynk and other communication methods being negligible, we decided to stick with our initial design of using Blynk to communicate and send data to and from our computer. Additionally, Blynk offers an easy to use interface along with a dashboard, available both in the web and on mobile devices, allowing for easy moderation and testing.

We first begin by creating a new project on the Blynk website. By creating virtual pins within our newly created project, we are able to have channels for sending data and information from our computer to the ESP8266 and ESP32 boards, and vice versa. We then obtain the Blynk key and password which can be placed in our code in order to allow both the ESP8266 and ESP32 boards to have access to the virtual pins that we have created. For our virtual pins, we have created 2 pins: the state pin and the score pin. The state pin is used to store the current state of the car control, for this pin, the data flows from the computer to the ESP8266 which then controls the motors to the desired state. The state pin stores an integer between 0 and 11, representing 11 different states, which is each associated with a hand gesture (10 is not used). On the other hand, the score pin stores an integer between 1 and 4, which represents the 4 scores of the 4 targets available. Once a target is hit, the ESP32 board sends the score through the virtual pin, which is then received by the computer. Both virtual pins can be monitored and controlled through the customizable Blynk dashboard both on the Blynk web (See Fig. 11(a)) and Blynk application (See Fig. 11(b)).

// pic

Fig. 11(a) Blynk Web-based Dashboard

// pic

Fig. 11(b) Blynk App-based Dashboard

Finally, we utilize a python library[11] made for Blynk in order to integrate  the Blynk’s functionality within our hand gesture recognition program, which is written in python.

#### *Servos and Motors Control*

When deciding on the motors to be used in order to control the mecanum wheels, we have taken into consideration the price, reliability and compatibility of the motor types along with their respective motor driver module. For the 4 wheels, we have decided to use 4 360 continuous servo motors mainly due to the PCA9685 servo driver board, which can control up to 16 servos simultaneously, while a traditional dc motor driver, like the L298N, can only control 2 motors at a time. The PCA9685 is also compatible with our ESP8266 board, using I2C communication to adjust the PWM value to control the different servos. Additionally, we use 2 additional servos, a 360 continuous servo and a normal servo, in order to operate the cannon mounted on the car. The normal servo is used to adjust the angle of the cannon. The traditional servo ensures that the cannon isn’t turned too far in either direction. On the other hand, the 360 continuous servo is used to dispense the foam bullet from the feeding tube into the firing mechanism.

For the firing mechanism, we have decided to use 2 dc motors due to their rotational speed and the L298N’s compatibility with our ESP8266. The two dc motors are connected to the L298N, which in turns is connected to the ESP8266. We can control the dc motors by controlling the many available digital pins on the ESP8266 board.

For the omni-directional movement, the initial design is for a ballasta to be mounted on top of a car, however, the traditional movement of a 4-wheel car does not provide the player with enough direction to allow precise aiming of the ballista due to the limiting degree of maneuverability. By implementing mecanum wheels, the car can move in many directions. It can do 360 degree turns, slide sideways and has a very tight turning radius. By controlling the 4 different servos to turn in different directions at roughly the same speed (See Fig. 12), we were able to implement omni-directional movement without having to rely on complex kinematic models.

// pic

Fig. 12 Motions of Omnidirectional Platform

#### *Target Detection*

For our DIY target design, we utilize the target’s pendulum-like motion in order to detect the target being hit. For each of the 4 targets, we placed an ir sensor behind the lower part of the target (See Fig. 13). When the target is stationary and not hit by the foam bullet, the IR sensor detects the bottom part of the target and outputs a HIGH digital signal to the ESP32 board. Conversely, when a target is hit, the lower part of the target swings forward and up, leaving the sensor’s detection area. This motion causes the sensor to send a LOW signal to the ESP32 board. 

// pic

Fig. 13 IR Sensors Behind the Target

For the logic within the ESP32 board, the board constantly checks for any LOW signal from the 4 IR sensors. When a LOW signal is detected, the board writes a number between 1 and 4 according to the target that has been hit to a virtual pin on Blynk. The main program on the computer would also constantly monitor the value stored in the virtual score pin, which is 0 by default. If the score pin obtains a value, the program increments the total score by that value. Additionally, the main program stores the most recent target hit, ensuring that if the same target were hit twice, the score would not be registered, making the game more challenging for the player.

## Overall Result

The programming parts and the mechanical part have made up for a robot which can move and react based on the hand gesture that we have set. Both hardware and software parts have been fused into a state of art machine for the purpose of rehabilitating office workers with their hand cramps and for fun.

## Conclusion

We created this project in order to create a creative smart toy for office workers and students who have high risk of developing office syndromes, such as carpal tunnel. We utilize MediaPipe’s hand solution along with Tensorflow Keras model in order to create a hand gesture detection, recognition, and classification program. We then use Blynk, which allows us to have wireless communication between our computer and the ESP8266 and ESP32 board. For the controls within our car, we use the PCA9685 servo driver module to control the 4 wheels along with the servos which is used to adjust the angle of the gun and dispense bullets. Moreover, instead of traditional wheels, we installed mecanum wheels, which allows the car to have instant lateral movement, improving the player’s control and experience playing. We use the L298N motor driver module to control the 2 dc motors within our cannon in order to fire the foam bullet. Finally, we use 4 IR sensors, which are connected to the ESP32 board, in order to implement the target detection system and keep track of the score for the player.

From our project, we have found that Blynk is a solid and reliable way of implementing wireless communication and is excellent for IOT projects; however, it does have some limitations when it comes to delay time during rapid communication. As for the hand gesture recognition system, we have had great success implementing the functionality by adapting and modifying Kasuhito00’s github repository[12], an incredible implementation of MediaPipe’s hand solution along with Tensorflow in order to create a live hand gesture detection and recognition system. The Tensorflow model has great categorization; however, it does struggle with gestures that are very similar, such as ones with the only difference being the lifting of a pinky finger.

In conclusion, we were able to implement artificial intelligence and machine learning, alongside robotics in order to create a creative, smart, and fun toy which can help office workers and students deal with office syndromes, such as carpal tunnel. By using Blynk to communicate wirelessly along with MediaPipe and Tensorflow to detect and recognize hand gestures, we were able to create an incentive for players to exercise their hand, risk, and fingers, preventing cramps and other unwanted side effects from working, while providing a fun and enjoyable experience of playing with a toy car which can fire foam bullets at different targets, collecting points.
