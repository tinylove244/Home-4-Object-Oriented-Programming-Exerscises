//Generated with assistance from ChatGPT 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Station;
class Passenger;

// build abstract class "Vehicle" with route, capacity, status, passengers, and assigned station
class Vehicle {
protected:
    string route;
    int capacity;
    bool status;
    vector<Passenger*> passengers;
    Station* assignedStation;
public:
    // Constructor 
    Vehicle(string route, int capacity) {
        this->route = route;
        this->capacity = capacity;
        this->status = true;
        this->assignedStation = nullptr;
    }

    // Destructor 
    virtual ~Vehicle() {}

    // Getter and Setter methods
    string getRoute() const {
        return route;
    }

    void setRoute(const string& r) {
        this->route = r;
    }

    int getCapacity() const {
        return capacity;
    }

    void setCapacity(int c) {
        this->capacity = c;
    }

    bool getStatus() const {
        return status;
    }

    void setStatus(bool s) {
        this->status = s;
    }

    // assign vehicle to a station
    void assignToStation(Station* station) {
        this->assignedStation = station;
    }

    // pure virtual function to calculate travel time
    virtual double calculateTravelTime(double distance) = 0;

    // add passenger to vehicle
    bool addPassenger(Passenger* p) {
        if ((int)passengers.size() < capacity) {
            passengers.push_back(p);
            return true;
        }
        return false;
    }

    // remove passenger from vehicle
    bool removePassenger(Passenger* p) {
        for (auto it = passengers.begin(); it != passengers.end(); ++it) {
            if (*it == p) {
                passengers.erase(it);
                return true;
            }
        }
        return false;
    }

    // display vehicle information
    virtual void displayInfo() {
        cout << "Route: " << route
             << ", Capacity: " << capacity
             << ", Current Passengers: " << passengers.size()
             << ", Status: " << (status ? "On-time" : "Delayed") << "\n";
    }
};

// build class "ExpressBus" inherits from Vehicle with speed property
class ExpressBus : public Vehicle {
private:
    double speed;
public:
    // Constructor 
    ExpressBus(string route, int capacity, double speed) : Vehicle(route, capacity) {
        this->speed = speed;
    }

    // override calculateTravelTime 
    double calculateTravelTime(double distance) override {
        return (distance / speed) * 0.8;
    }

    // override displayInfo 
    void displayInfo() override {
        cout << "[ExpressBus] Route: " << route
             << ", Capacity: " << capacity
             << ", Current Passengers: " << passengers.size()
             << ", Speed: " << speed
             << ", Status: " << (status ? "On-time" : "Delayed") << "\n";
    }
};

// build class "Schedule" to manage vehicle schedules
class Schedule {
private:
    string time;
    string type;
    Vehicle* vehicle;
public:
    // Constructor 
    Schedule(string time, string type, Vehicle* v) {
        this->time = time;
        this->type = type;
        this->vehicle = v;
    }

    // display schedule with vehicle info
    void displaySchedule() {
        cout << "Time: " << time << ", Type: " << type << "\n";
        if (vehicle != nullptr) {
            vehicle->displayInfo();
        }
        cout << "\n";  // add blank line
    }
};

// build class "Station" with name, location, type, and schedule list
class Station {
private:
    string name;
    string location;
    string type;
    vector<Schedule> schedules;
public:
    // Constructor 
    Station(string name, string location, string type) {
        this->name = name;
        this->location = location;
        this->type = type;
    }

    // add a schedule
    void addSchedule(Schedule s) {
        schedules.push_back(s);
    }

    // remove a schedule by index
    void removeSchedule(int idx) {
        if (idx >= 0 && idx < (int)schedules.size()) {
            schedules.erase(schedules.begin() + idx);
        }
    }

    // display all schedules
    void displaySchedules() {
        cout << "Station: " << name << " (" << location << ")\n";
        for (auto& s : schedules) {
            s.displaySchedule();
        }
        cout << "\n";  // add blank line
    }
};

// build class "Passenger" with id, name, and booked rides
class Passenger {
private:
    string name;
    int id;
    vector<Vehicle*> booked;
public:
    // Constructor 
    Passenger(int id, string name) {
        this->id = id;
        this->name = name;
    }

    // book a ride
    void bookRide(Vehicle* v) {
        if (v->addPassenger(this)) {
            booked.push_back(v);
            cout << name << " booked vé thành công trên " << v->getRoute() << "\n\n";
        } else {
            cout << name << " book vé không thành công (xe đã đầy)\n\n";
        }
    }

    // cancel a ride
    void cancelRide(Vehicle* v) {
        if (v->removePassenger(this)) {
            for (auto it = booked.begin(); it != booked.end(); ++it) {
                if (*it == v) {
                    booked.erase(it);
                    break;
                }
            }
            cout << name << " đã huỷ vé trên " << v->getRoute() << "\n\n";
        }
    }

    // display passenger info
    void displayInfo() {
        cout << "Passenger " << name << " (" << id << ") booked rides:\n";
        for (auto* v : booked) {
            v->displayInfo();
        }
        cout << "\n";  // add blank line
    }
};

// build function "menu" to show options
void menu() {
    cout << "========== MENU ==========\n";
    cout << "1. Book vé\n";
    cout << "2. Cancel vé\n";
    cout << "3. Xem thông tin hành khách\n";
    cout << "4. Xem lịch trình\n";
    cout << "0. Thoát\n";
    cout << "==========================\n\n";
}

int main() {
    // Create express bus
    ExpressBus bus("HCM - VungTau", 2, 80);

    // Create station and schedule
    Station st("Mien Dong", "HCM", "bus");
    Schedule sch("08:00", "departure", &bus);
    st.addSchedule(sch);

    // Create passengers
    Passenger p1(1, "Nguyen Van A");
    Passenger p2(2, "Tran Thi B");
    Passenger p3(3, "Le Van C");

    // Passengers book rides
    p1.bookRide(&bus);
    p2.bookRide(&bus);
    p3.bookRide(&bus);  // expected fail because capacity = 2

    // Show schedules and passenger info
    st.displaySchedules();
    p1.displayInfo();

    // Cancel ride
    p1.cancelRide(&bus);
    p1.displayInfo();

    // show menu
    menu();

    return 0;
}
