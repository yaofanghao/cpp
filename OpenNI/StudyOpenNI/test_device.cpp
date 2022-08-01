#include <OpenNI.h>
#include <iostream>
using namespace std;
using namespace openni;

int main(int argc, char** argv)
{
    // 初始化OpenNI  
    OpenNI::initialize();

    // 获取设备信息  
    Array<DeviceInfo> aDeviceList;
    OpenNI::enumerateDevices(&aDeviceList);

    // output information  
    //vector<CDevice>  vDevices;  
    cout << "电脑上连接着 " << aDeviceList.getSize() << " 个设备." << endl;

    for (int i = 0; i < aDeviceList.getSize(); ++i)
    {
        cout << "设备 " << i << endl;
        const DeviceInfo& rDevInfo = aDeviceList[i];
        cout << "设备名： " << rDevInfo.getName() << endl;
        cout << "设备Id： " << rDevInfo.getUsbProductId() << endl;
        cout << "供应商名： " << rDevInfo.getVendor() << endl;
        cout << "供应商Id: " << rDevInfo.getUsbVendorId() << endl;
        cout << "设备URI: " << rDevInfo.getUri() << endl;

    }
    system("pause"); // 编译运行之后可以
    OpenNI::shutdown();
    return 0;
}
