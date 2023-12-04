# Self-Landing-Rocket
Democratization of Self-Landing Rocketry Capstone repository
# Project Description
The goal of this project is to provide research groups and hobbyists with an open source, sub-scale, self-stabilizing model rocket platform that will unlock previously inaccessible low-budget research/experimentation of 'inverted pendulum' self-landing rockets. This page contains details on the required materials and tools as well as build instructions.

<img width="436" alt="Screenshot 2023-11-28 at 5 56 44 PM" src="https://github.com/samueliu/Self-Landing-Rocket/assets/151796773/e18f314b-079f-452b-893b-856840619189">

# Fabrication Techniques and Materials
The following machines will be needed for fabrication
1. FDM Printer
2. Resin Printer
3. Desktop CNC Router
4. Soldering Iron
5. Drill
6. Dremel

Additionally, a full list of materials with links to purchasing sites can be found in the materials folder.
# Build/Assembly
There are three main components to this build. The first is machining, printing and cutting parts. The second is soldering the circuit schematic together and the third is epoxying and bolting together the full assembly. 

Step 1: Machining, Printing and Cutting

The parts to print are seperated into resin and FDM parts and can be found under the rocket hardware folder. The majority of the custom components on the vehcile are 3D printed primarily using FDM (Fused Deposition Modeling) but a select few parts were printed on SLA (Stereolithography) 3D printers. The rationale for using the SLA 3D printers primarily revolves around the need for increased component resolution/tolerance. For example, the two pitch and roll servo couplers mate to the T15 servo spline which has 15 teeth size on the order of a single millimeter. For accessability and ease of manufacture, the majority of the remainder of the custom components were printed on a FDM 3D printer as they are generally larger and require less fidelity. A lightweight thermoplastic filament called LW-PLA from PloyMaker was used with low infill (15%) to reduce the wieght of these larger FDM parts. 

A few number of select parts require CNC machining (including the four landing gear legs and the battery holder) as these parts have strict sitffness/mass requirements which could only be satisfied by fiberglass or carbon fiber. In order to meet the stiffness requirements that would be neccesary from supporting the thrust mechanism as well as shock from landing, 3mm Carbon fiber was chosen as the material for the landing gear legs. A desktop CNC router (Shapeoko 4) was used to cut the parts. The feed/punge rate was set to approximately 400mm/s and 150mm/s with a 1/16" 4 flute burr endmill and the CAD/CAM files can be found here under the rocket hardware folder.

A select number of components also required cutting/joining. The two carbon fiber shafts holding the motors were cut using a dremel and the rocket tube was cut using an X-acto knife. A part was also printed to help guide this X acto knife cut and can be found within the STL folder. Super glue was used to couple all 3D printed TVC parts to the respective carbon components except for joints experiencing large loads (carbon legs to rocket fuselage and carbon battery plate to nose cone) which were coupled using an off-the-shelf 5 minute epoxy.

Step 2: Circuit schematic

<img width="511" alt="Screenshot 2023-11-30 at 2 34 41 PM" src="https://github.com/samueliu/Self-Landing-Rocket/assets/151664858/97983e49-5ef1-41f6-8b25-743f2beb1a74">

Above is the circuit schematic used in this project. A proto board was used for integrating all parts. 

Step 3: Putting it all Together

With all materials printed, machined and cut, as well as the electronics put together, the final step is to build the rocket. Provided are both an stl of the full build for easy reference, as well as an instructional manual with step by step build instructions. 
