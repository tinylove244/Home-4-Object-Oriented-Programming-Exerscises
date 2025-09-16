
# 📘 Public Transportation Station Management System - Documentation

<p align="center">
  <b>Name:</b> Ngô Quang Trường &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <b>Student's ID:</b> 24110142
</p>

<p align="center">
  <b>Subject:</b> Object - Oriented Programming
</p>

---


### 1. OOA Analysis

In the analysis phase, the system was divided into key objects:  
**Vehicle, ExpressBus, Passenger, Station, and Schedule**.  
Their relationships:  
- Vehicle stores route, capacity, passengers.  
- ExpressBus inherits Vehicle and adds speed, demonstrating **inheritance** in OOP.  
- Passenger can book or cancel rides on Vehicle.  
- Station manages schedules (Schedule) connected to Vehicles.  
- Schedule links a Vehicle with departure time and type.  

### 2. Class Design Explanation

- **Vehicle (abstract class)**: Contains route, capacity, status, passenger list, assigned station. Defines pure virtual function `calculateTravelTime`.  
- **ExpressBus**: Inherits from Vehicle, adds speed, overrides `calculateTravelTime` and `displayInfo`.  
- **Schedule**: Manages time, type, and assigned Vehicle.  
- **Station**: Manages name, location, type, and a list of schedules.  
- **Passenger**: Manages passenger info, booking/canceling rides, and stores booked trips.  

### 3. Challenges Encountered

- Designing the abstract class `Vehicle` and implementing inheritance was challenging.  
- Errors occurred when handling pointers between Passenger and Vehicle.  
- Managing relationships among Station, Schedule, and Vehicle required adjustments.  

### 4. Code Walkthrough

- **Vehicle & ExpressBus**: Vehicle defines the base, ExpressBus adds speed and custom travel time.  
- **Schedule**: Connects Vehicle with a departure time and type.  
- **Station**: Stores schedules and displays them.  
- **Passenger**: Can book, cancel rides, and print booked rides info.  
- **Menu**: Provides main system options (Book, Cancel, View passenger info, View schedules).  

### 5. Test Results

- Test 1: Passengers booked rides successfully when capacity was available.  
- Test 2: Booking failed correctly when capacity exceeded.  
- Test 3: Station schedules displayed properly.  
- Test 4: Passenger canceled a ride, system updated correctly.  

The system works as designed and correctly manages public transportation station operations.  

### 6. LLM Usage

- I used ChatGPT for suggestions on class methods and documentation structuring.  
- Example: *"Suggest methods for a Vehicle class in a transportation station system."*  
- I then rewrote and finalized the code myself.  

