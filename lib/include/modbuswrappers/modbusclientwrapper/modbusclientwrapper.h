#ifndef TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTWRAPPER_H_
#define TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTWRAPPER_H_

#include <memory>
#include <vector>
#include <map>
#include <thread>
#include <mutex>

#include <utils/baseutils.h>


#include "modbuswrappers/modbuswrapper.h"
#include <modbuswrappers/export.h>

// TODO: Добавить состояние NOT_CONNECTED и вынести туда логику из DISCONNECTED. Состояние DISCONNECTED сделать таким, чтобы там была логика восстановления коннекта


class MODBUSWRAPPERS_EXPORT ModbusClientWrapper: public ModbusWrapper {
 public:
  explicit ModbusClientWrapper(const std::string &ip, int port, int modbus_id);

  std::string getIP() override;
  int getPort() override;
  int getModbusID() override;

  ErrorCode connect() override;
  ErrorCode disconnect() override;

  ErrorCode isConnected(bool &is_connected) override;

  ErrorCode readHoldingRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readHoldingRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;
  ErrorCode writeHoldingRegisters(int reg_num, std::vector<uint16_t> value, int modbus_id) override;
  ErrorCode writeHoldingRegister(int reg_num, uint16_t value, int modbus_id) override;

  ErrorCode readInputRegister(int reg_num, uint16_t &value, int modbus_id) override;
  ErrorCode readInputRegisters(int reg_num, int reg_count, std::vector<uint16_t> &values, int modbus_id) override;

  void checkConnectionStatusByResponse(modbus::ModbusResult response);

  void changeState(DeviceState state);
  void addState(const std::pair<DeviceState, std::shared_ptr<ModbusWrapper>> &state);

 private:
  std::string _ip;
  int _port = 4001;
  int _modbus_id = 2;

  std::map<DeviceState, std::shared_ptr<ModbusWrapper>> _states;
  std::shared_ptr<ModbusWrapper> _current_state = nullptr;
};

#endif //TEST_PROJECT_WITH_MODULE_ARCH_MODBUSWRAPPERS_MODBUSCLIENTWRAPPER_MODBUSCLIENTWRAPPER_H_
