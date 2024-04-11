// Serial Number Checker

#include <iostream>
#include <windows.h>

using std::cout;
using std::endl;

const int DELAY_SHORT = 1000;
const int DELAY_LONG = 10000;

void displayMessage(const std::string& message) {
    cout << message << endl;
}

void checkSystemInfo(const std::string& command, const std::string& title) {
    displayMessage(title);
    displayMessage("========================");
    system(command.c_str());
}

int main() {
    displayMessage("Checking your serials...");
    displayMessage("Please Wait.");

    Sleep(DELAY_SHORT);

    checkSystemInfo("wmic diskdrive get serialnumber", "Disk");
    checkSystemInfo("wmic baseboard get serialnumber", "Motherboard");
    checkSystemInfo("wmic path win32_computersystemproduct get uuid", "SMBios");
    checkSystemInfo("wmic PATH Win32_VideoController GET Description,PNPDeviceID", "GPU");
    checkSystemInfo("wmic memorychip get serialnumber", "RAM");
    checkSystemInfo("wmic csproduct get uuid", "Bios");
    checkSystemInfo("wmic cpu get processorid", "CPU");
    checkSystemInfo("wmic path Win32_NetworkAdapter where \"PNPDeviceID like '%%PCI%%' AND NetConnectionStatus=2 AND AdapterTypeID='0'\" get MacAddress", "Mac");

    displayMessage("Exiting in 10 seconds.");
    Sleep(DELAY_LONG);
    return 0;
}
