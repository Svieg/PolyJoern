#include <iostream>
#include <cstring>

class VulnerableClass {
private:
    char buffer[16];
public:
    void copyData(const char* input) {
        strcpy(buffer, input);
    }
    const char* getData() {
        return buffer;
    }
    
    void run_command(char *cmd) {
        char buffer[100];
        sprintf(buffer, "%s", cmd);
        system(buffer);
    }
};

int main() {
    VulnerableClass vc;
    char input[100];
    std::cout << "Enter some data: ";
    std::cin.getline(input, 100);
    vc.copyData(input);
    std::cout << "Data entered: " << vc.getData() << std::endl;
    return 0;
}
