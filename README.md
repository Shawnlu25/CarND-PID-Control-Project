# CarND-Controls-PID Project

## Project Overview
In this project, a Proportional-Integral-Derivative controller is developed to control the steering angle of a car in a simulated environment. The project also involves tuning parameters for the controller in order to keep the car on track.

## Reflection
### PID components
As previously stated, PID stands for "Proportional", "Derivative" and "Integral". The explanation of each component are the following:
* Proportional component means that the car will steer in proportion to the cross-track-error, that is, the distance between the position of the car and the central line of the track. Intuitively, we need to steer the car towards the central line more if the car is far away from the track. Notice that the value of Proportional coefficent would have a huge impact on the final behavior of our car: if the value is too high, the car would "overshoot" and "overcorrect" constantly, resulting in oscillation behavior; if the value is too low, the car would correct itself too slowly when encountering curves, which could result in "off-the-curb" situation.
* Derivative component stands for the change in cross-track-error from one value to the next along the timeline. With derivative, the car would gradually decrease its steering angle as it moves towards the center of the lane. In other words, the car would correct itself in a more "smooth" fashion. Low value of this coefficent would lead to constant oscillations, and a high value would cause almost constant steering angle changes (often of large degrees).
* The Integral component sums up all the CTE along the timeline to the current point, so that large accumulated CTE would cause the car to steer towards the middle gradually. This mechanism mainly deals with systematic error, where the CTE is not caused by failure of PI control described above, but by uncontrollable factors such as un-calibrated sensors. Overlarged value of this coefficient would cause a quicker oscillation, and oversmall value would cause the car to drift on side of the road for a longer period of time.

According to experiments, my observations of the simulated car under different PID settings matches my expectations.

### Parameter search
I used a combination of Twiddle and manual tuning to search for a good PID coefficent settings (The Twiddle part is removed from the final code). First, I ran Twiddle with the same setting described in the Udacity lecture; then I performed a manual search around the result from Twiddle. For each parameter setting, I took the average of CTE for 10 runs as the metric. The final setting I have is P=0.21, I=0.0042, D=2.9. This setting works well, and would enable the car to race at around 50mph safely. 

## Basic Build Instructions

1. Clone this repo.
2. Under the repository folder, run `mkdir build && cd build` followed by `cmake .. && make`
3. Open up the udacity CarND term-2 simulator
4. Run PID controller `./pid`. 