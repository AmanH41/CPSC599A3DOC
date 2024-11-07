# Mental Fighter 

### [link to code](A2.ino)

## Overall Description
Musical Canvas is an innovative instrument that allows artists and musicians to add a unique soundtrack to their creations. Using two ultrasonic sensors, the system maps specific musical notes from the pentatonic scale to different paint choices. This setup enables even those without musical backgrounds to create harmonious music as they paint.

As the artist selects different paints, each color triggers a corresponding note, enriching the creative process. The second ultrasonic sensor detects when the artist is actively painting, causing the selected notes to play in real-time, based on the chosen colors. Once the artwork is complete, the system plays back the sequence of notes used, creating a unique musical composition that accompanies the visual piece.
## Project Documentation 
### How Does it Work?

1. **Paint and Sound Mapping:**  
   The project uses two ultrasonic sensors. The first sensor is responsible for detecting the "paint" or color the user selects. Each color is mapped to a specific note from the pentatonic scale (A, C, D, E, G).  
   As the user selects a paint color, the corresponding note is assigned to that color. The pentatonic scale was chosen to ensure even those with no musical experience can create harmonious and pleasant sounds.

2. **Painting Detection and Note Playback:**  
   The second ultrasonic sensor detects when the user is actively painting. When the user brings their brush or hand within range of this sensor, the system begins playing the assigned note for the selected paint color.  
   As the user paints with different colors, the system dynamically changes the notes based on the current selection, creating real-time sound corresponding to their artistic actions.

3. **Post-Painting Playback (was not able to implement this):**  
   After the user completes their artwork, the system will play back the sequence of notes in the order they were used during the painting process. This creates a unique musical composition that reflects the creation of the artwork, adding an audio dimension to the visual experience.


## Initial ideas
<div style="text-align: center;">
  <img src="CPSC599A2Images/Assignment 2_241106_215100_3.jpg" style="width: 45%; height: auto; display: inline-block; margin: 10px;">
   <img src="CPSC599A2Images/Assignment 2_241106_215100_2.jpg" style="width: 45%; height: auto; display: inline-block; margin: 10px;">
   <p> Text explaining initial ideas</p>
</div>

## Prototypes 
<style>
  .prototype-images {
    width: 45%;
    height: auto;
    aspect-ratio: 1 / 1; /* Ensures images maintain a square shape */
    display: inline-block;
    margin: 10px;
    object-fit: cover; /* Ensures image fills the container without distortion */
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
  <img src="CPSC599A1circuit.png" style="width: 45%; height: auto; display: inline-block; margin: 10px;">
</div>

### Demo Video 
<div style="text-align: center;">
  <iframe width="560" height="315" src="https://www.youtube.com/embed/Ia-3yWniXXw" 
  title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen>
  </iframe>
</div>


## Refrence 
<a href="https://docs.arduino.cc/learn/electronics/servo-motors/">Guide for servo motors </a><br>
<a href="https://www.youtube.com/watch?v=tF3-zdU4qhw&ab_channel=TD_Sculptures%26Crafts">tutorial helped with building mental fighters body </a>
<a href="https://www.youtube.com/watch?v=4tjkLSWzl_g&list=PL9ZvIWB2N7tS1Q2JEs3H-poSWc0xKp8f8&ab_channel=PaperPatriot">tutorial helped with building mental fighters body </a>


