/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_helloworld,
    0x0c04e376,0xd468,0x412c,0x96,0x3a,0xd2,0xd7,0xcc,0x18,0x82,0xb8);
// {0c04e376-d468-412c-963a-d2d7cc1882b8}
