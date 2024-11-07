# Mental Fighter 

### [link to code](A2.ino)

## Overall Description
Mental Fighter is a physical representation of a fighting game player’s “mental”—the complex series of thoughts and emotions (joy, anger, frustration, confusion, etc.) that players experience as they progress through rounds and matches. Mental Fighter visualizes these mental states, providing players with feedback on their emotional and psychological condition throughout gameplay.

A common question might be, “Why would competitive players need visual feedback about their feelings?” Competitive players are often driven to keep playing regardless of frustration, anger, or other negative emotions that arise during a session. Ignoring these feelings can impact decision-making, mechanical skill, and even mental health.

Mental Fighter offers a solution by showing players their “mental” state after each match. This reflection allows them to assess whether they should continue playing or take a short break to reset and improve their mindset.
## Project Documentation 
### How Does it Work?

1. **Win/Loss Tracking and Action Mapping:**  
Mental Fighter monitors the player’s wins and losses. Each outcome triggers a specific action: winning a match prompts Mental Fighter to perform a punch or power-up motion, while losing a match triggers a blocking action. This approach reflects the player’s in-game performance through physical actions, allowing them to see their “mental state” unfold as the game progresses.

2. **Real-Time Physical Feedback:**  
As the player wins or loses consecutive games, Mental Fighter responds with different physical movements. For example, a winning streak prompts it to “power up,” representing momentum and confidence, while losing too many games in a row causes Mental Fighter to curl into a fetal position, indicating mental strain. These physical reactions occur in real-time, giving players immediate, tangible feedback that mirrors their in-game experiences.

3. **Reflection and Mandatory Breaks:**  
After each match, players can assess their Mental Fighter’s condition and decide whether to continue or take a break. However, when Mental Fighter reaches the fetal position (a “super block” state) due to excessive losses, the system enforces a 5-minute break. During this time, Mental Fighter remains in the fetal position, signaling the need for a mental reset. Once the 5-minute timer ends, it returns to an idle state, allowing the player to resume gameplay.


## Initial ideas
<div style="text-align: center;">
  <img src="CPSC599A2Images/Assignment 2_241106_215100_3.jpg" style="width: 45%; height: auto; display: inline-block; margin: 10px;">
   <img src="CPSC599A2Images/Assignment 2_241106_215100_2.jpg" style="width: 45%; height: auto; display: inline-block; margin: 10px;">
   <p> Text explaining initial ideas</p>
</div>

## Prototypes 
<style>
  .prototype-images {
    width: auto;           /* Allow width to scale naturally */
    height: 15rem;         /* Set a consistent height for all images */
    max-width: 45%;        /* Limit the width to a reasonable percentage */
    display: inline-block;
    margin: 10px;
  }
</style>

<div style="text-align: center;">
  <img src="CPSC599A2Images/IMG_0336.PNG" class="prototype-images">
  <img src="CPSC599A2Images/IMG_0337.PNG" class="prototype-images">
  <img src="CPSC599A2Images/IMG_0338.PNG" class="prototype-images">
  <img src="CPSC599A2Images/IMG_0339.PNG" class="prototype-images">
  <p>Test explaining early prototypes</p>
</div>

<div style="text-align: center;">
  <img src="CPSC599A2Images/IMG_0340.PNG" class="prototype-images">
  <img src="CPSC599A2Images/IMG_0341.PNG" class="prototype-images">
  <img src="CPSC599A2Images/IMG_0342.PNG" class="prototype-images">
  <img src="CPSC599A2Images/IMG_0343.PNG" class="prototype-images">
  <p>Test explaining pre-final and final prototypes</p>
</div>


### Circuit Schematic Diagram
<div style="text-align: center;">
  <img src="CPSC599A2Images/CPSC599A2Circuit.PNG" style="width: 45%; height: auto; display: inline-block; margin: 10px;">
</div>

### Demo Video 
<div style="text-align: center;">
  <iframe width="560" height="315" src="" 
  title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen>
  </iframe>
</div>


## Refrence 
<a href="https://docs.arduino.cc/learn/electronics/servo-motors/">Guide for servo motors </a><br>
<a href="https://www.youtube.com/watch?v=tF3-zdU4qhw&ab_channel=TD_Sculptures%26Crafts">tutorial helped with building mental fighters body </a>
<a href="https://www.youtube.com/watch?v=4tjkLSWzl_g&list=PL9ZvIWB2N7tS1Q2JEs3H-poSWc0xKp8f8&ab_channel=PaperPatriot">tutorial helped with building mental fighters body </a>


