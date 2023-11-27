#include "Car.hpp"

int main() {
    Car car(1, 0, 0, 0);

    std::cout << std::endl << "Testing Gears" << std::endl;
    car.shift_up();
    car.shift_up();
    car.shift_up();
    car.shift_up();
    car.shift_up(); 
    car.shift_up();

    car.shift_down();
    car.shift_down();
    car.shift_down();
    car.shift_down();
    car.shift_down();
    car.shift_down();

    car.reverse();

    std::cout << std::endl << "Testing Wheel" << std::endl;
    car.turn_wheel(90);
    car.turn_wheel(90);
    car.turn_wheel(90);
    car.turn_wheel(90);
    car.turn_wheel(90);
    car.turn_wheel(90);
    car.turn_wheel(90);

    car.straighten_wheel();

    std::cout << std::endl << "Testing Engine" << std::endl;
    car.start();
    car.accelerate(10);
    car.accelerate(10);
    car.accelerate(10);
    car.accelerate(10);
    car.accelerate(10);
    car.accelerate(10);

    car.stop();

    std::cout << std::endl << "Testing Break" << std::endl;
    car.apply_force_on_brakes(10);
    car.apply_force_on_brakes(10);
    car.apply_force_on_brakes(10);

    car.apply_emergency_brakes();
    car.apply_force_on_brakes(0);

    std::cout << std::endl << "Testing copy constructor" << std::endl;
    Car car2(car);

    car2.shift_up();
    car2.shift_up();
    car2.shift_up();

    car2.turn_wheel(90);
    car2.turn_wheel(90);

    std::cout << "Car 1: " << std::endl;
    car.print();
    std::cout << "Car 2: " << std::endl;
    car2.print();
}