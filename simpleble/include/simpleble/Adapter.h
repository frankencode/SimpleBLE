#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include <simpleble/export.h>

#include <simpleble/Exceptions.h>
#include <simpleble/Peripheral.h>
#include <simpleble/Types.h>

namespace SimpleBLE {

class AdapterBase;

class SIMPLEBLE_EXPORT Adapter {
  public:
    Adapter() = default;
    virtual ~Adapter() = default;

    bool initialized() const;
    void* underlying() const;

    std::string identifier() const;
    BluetoothAddress address() const;

    void scan_start();
    void scan_stop();
    void scan_for(int timeout_ms);
    bool scan_is_active() const;
    std::vector<Peripheral> scan_get_results() const;

    void set_callback_on_scan_start(std::function<void()> on_scan_start);
    void set_callback_on_scan_stop(std::function<void()> on_scan_stop);
    void set_callback_on_scan_updated(std::function<void(Peripheral)> on_scan_updated);
    void set_callback_on_scan_found(std::function<void(Peripheral)> on_scan_found);

    std::vector<Peripheral> get_paired_peripherals() const;

    static bool bluetooth_enabled();

    /**
     *  Fetches a list of all available adapters.
     */
    static std::vector<Adapter> get_adapters();

  protected:
    AdapterBase &internal();
    const AdapterBase &internal() const;
    std::shared_ptr<AdapterBase> internal_;
};

}  // namespace SimpleBLE
