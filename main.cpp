#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

int main() {
    // Initialize OpenAL and list all available devices
    if (alcIsExtensionPresent(NULL, "ALC_ENUMERATE_ALL_EXT") == AL_TRUE) {
        const ALCchar* deviceSpecifier = alcGetString(NULL, ALC_ALL_DEVICES_SPECIFIER);
        const ALCchar* next = deviceSpecifier + 1;
        std::vector<std::string> devices;

        std::cout << "Available OpenAL devices:" << std::endl;
        while (deviceSpecifier && *deviceSpecifier != '\0') {
            std::cout << "Device: " << deviceSpecifier << std::endl;
            devices.push_back(deviceSpecifier);
            deviceSpecifier += strlen(deviceSpecifier) + 1;
        }
    } else {
        std::cout << "ALC_ENUMERATE_ALL_EXT not supported." << std::endl;
    }

    // Default device using more detailed specifier
    const ALCchar* defaultDeviceName = alcGetString(NULL, ALC_DEFAULT_ALL_DEVICES_SPECIFIER);
    std::cout << "\nDefault device: " << defaultDeviceName << std::endl;

    // Open the default device
    ALCdevice* device = alcOpenDevice(defaultDeviceName);
    if (!device) {
        std::cerr << "Failed to open the default device." << std::endl;
        return -1;
    }

    // Clean up
    alcCloseDevice(device);
    return 0;
}
