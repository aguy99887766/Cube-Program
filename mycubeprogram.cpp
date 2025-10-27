#include <iostream>
#include <string>
#include <limits>

class Cube
{
    /*
    Cube Object
        Length - INT
        Width - INT
        Height - INT
        Color - STRING

        Can track volume, spin, and print out information.
    */
    public:
        int length;
        int width;
        int height;
        std::string color;

        Cube(int, int, int, std::string);
        int volume() {
            return(length*width*height);
        }
        void spin() {
            std::cout << "The cube is spinning" << std::endl;
        }
        void get_information() {
            std::cout << "Length: " << length << std::endl;
            std::cout << "Width: " << width << std::endl;
            std::cout << "Height: " << height << std::endl;
        }


};

Cube::Cube(int get_length, int get_width, int get_height, std::string get_color) {
    length = get_length;
    width = get_width;
    height = get_height;
    color = get_color;
}

template <typename T>
void user_input(const std::string question, T* value) {
    /*
    User input method to reduce copy and pasting
    */


    while (true) { 
        std::cout << question << ": ";
        std::cin >> *value;


        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Validation failed. Try again." << std::endl;
        
        } else {
            break;
        }
    }
}

Cube* user_object = nullptr;

void edit_cube() {

    /*
    Menu to create / edit a cube
    
    */

    int p_length;
    int p_width;
    int p_height;
    std::string complete;
    std::string p_color;

    while (true) {

        user_input("Enter the length of this cube!", &p_length);
        user_input("Enter the width of this cube!", &p_width);
        user_input("Enter the height of this cube!", &p_height);
        user_input("Enter the color! ", &p_color);


        if (p_length < 0 || p_height < 0 || p_width < 0) {
            std::cout << "Validation Failed restarting" << std::endl;
            continue;
        }

        user_input("Are you complete?", &complete);
        if (complete == "yes" || complete == "y") {
            break;
        }

    
    }

    user_object = new Cube(p_length, p_width, p_height, p_color);
    user_object->get_information();

}



int main() {

    int options;

    std::cout << "Hello user, please create your cube!" << std::endl;
    edit_cube();

    while (true) { 

        std::cout << "Welcome user!, what do you want to do with your cube" << std::endl;
        std::cout << "1) Edit cube" << std::endl;
        std::cout << "2) View cube" << std::endl;
        std::cout << "3) Spin cube" << std::endl;
        std::cout << "4) Leave" << std::endl;

        user_input("Choose an option [1-4]", &options);

        if (options == 1) {
            edit_cube();
        }

        if (options == 2) {

            std::cout << std::string(25, '-') << std::endl;
            user_object->get_information();
            std::cout << "VOLUME: " << user_object->volume() << std::endl;
            std::cout << std::string(25, '-') << std::endl;

        }

        if (options == 3) {
            user_object->spin();
        }

        if (options == 4) {
            break;
        }

    
    }
    


    return 0;
}