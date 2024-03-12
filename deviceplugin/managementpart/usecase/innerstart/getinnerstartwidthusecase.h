#ifndef IES_DEVICE_PLUGIN_PROJECT_DEVICEPLUGIN_MANAGEMENTPART_USECASE_INNERSTART_GETINNERSTARTWIDTHUSECASE_H_
#define IES_DEVICE_PLUGIN_PROJECT_DEVICEPLUGIN_MANAGEMENTPART_USECASE_INNERSTART_GETINNERSTARTWIDTHUSECASE_H_

#include <QObject>

#include <utils/baseutils.h>

#include "deviceplugin/entity/deviceentity.h"


struct GetInnerStartWidthUseCaseRequest {

};

struct GetInnerStartWidthUseCaseResponse {
    uint64_t value = 0;
    ErrorCode error_code = OPERATION_INTERRUPTED;
};


class GetInnerStartWidthUseCase: public QObject {
public:
    explicit GetInnerStartWidthUseCase(const std::shared_ptr<DeviceEntity> &device_entity);

    GetInnerStartWidthUseCaseResponse execute(GetInnerStartWidthUseCaseRequest request);

private:
    std::shared_ptr<DeviceEntity> _device_entity = nullptr;
};

#endif //IES_DEVICE_PLUGIN_PROJECT_DEVICEPLUGIN_MANAGEMENTPART_USECASE_INNERSTART_GETINNERSTARTWIDTHUSECASE_H_