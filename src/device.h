#pragma once

#include <libusb.h>
#include <stdint.h>

#define VENDOR_CORSAIR  0x1b1c
#define VENDOR_LOGITECH 0x046d

/** @brief A list of all features settable/queryable
 *         for headsets
 */
enum capabilities {
    CAP_SIDETONE            = 1
};

/** @brief Defines the basic data of a device
 *
 *  Also defines function pointers for using supported features
 */
struct device
{
    /// USB Vendor id
    uint16_t idVendor;
    /// USB Product id
    uint16_t idProduct;
 
    /// Name of device, used as information for the user
    char device_name[32];
 
    /// Bitmask of currently supported features the software can currently handle
    int capabilities;
    
    /** @brief Function pointer for setting headset sidetone
     *
     *  Forwards the request to the device specific implementation
     *
     *  @param device_handle The libUSB handle. Must be the same
     *                       device as defined here (same ids)
     *  @param num           Level of the sidetone, between 0 - 128
     */
    int (*send_sidetone)(libusb_device_handle *device_handle, uint8_t num);
};

