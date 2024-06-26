#include <simpleble/Descriptor.h>

#include "DescriptorBase.h"
#include "DescriptorBuilder.h"

using namespace SimpleBLE;

BluetoothUUID Descriptor::uuid() const { return internal().uuid(); }

const DescriptorBase &Descriptor::internal() const { return *internal_; }
