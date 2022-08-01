#include <OpenNI.h>
#include <iostream>
using namespace std;
using namespace openni;

int main(int argc, char** argv)
{
    // ��ʼ��OpenNI  
    OpenNI::initialize();

    // ��ȡ�豸��Ϣ  
    Array<DeviceInfo> aDeviceList;
    OpenNI::enumerateDevices(&aDeviceList);

    // output information  
    //vector<CDevice>  vDevices;  
    cout << "������������ " << aDeviceList.getSize() << " ���豸." << endl;

    for (int i = 0; i < aDeviceList.getSize(); ++i)
    {
        cout << "�豸 " << i << endl;
        const DeviceInfo& rDevInfo = aDeviceList[i];
        cout << "�豸���� " << rDevInfo.getName() << endl;
        cout << "�豸Id�� " << rDevInfo.getUsbProductId() << endl;
        cout << "��Ӧ������ " << rDevInfo.getVendor() << endl;
        cout << "��Ӧ��Id: " << rDevInfo.getUsbVendorId() << endl;
        cout << "�豸URI: " << rDevInfo.getUri() << endl;

    }
    system("pause"); // ��������֮�����
    OpenNI::shutdown();
    return 0;
}
