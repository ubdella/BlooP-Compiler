#include <iostream>
#include <string>
#include <map>

class BlooP {
public:
    void assign(std::string var, int value) {
        variables[var] = value;
    }

    int get(std::string var) {
        return variables[var];
    }

    void add(std::string var, int value) {
        variables[var] += value;
    }

    void multiply(std::string var, int value) {
        variables[var] *= value;
    }

    void loop(std::string var, void (BlooP::*func)(std::string, int), std::string var2, int times) {
        for (int i = 0; i < times; i++) {
            (this->*func)(var2, get(var));
        }
    }

private:
    std::map<std::string, int> variables;
};

int main() {
    BlooP bloop;
    bloop.assign("x", 5);
    bloop.loop("x", &BlooP::add, "y", 2);  
    std::cout << bloop.get("y") << std::endl;  
    return 0;
}
