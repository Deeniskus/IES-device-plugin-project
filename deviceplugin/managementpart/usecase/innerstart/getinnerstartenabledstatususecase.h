//
// Created by Den on 12.03.2024.
//

#ifndef IES_DEVICE_PLUGIN_PROJECT_GETINNERSTARTENABLEDSTATUSUSECASE_H
#define IES_DEVICE_PLUGIN_PROJECT_GETINNERSTARTENABLEDSTATUSUSECASE_H


#include <QObject>

#include <utils/baseutils.h>

#include "deviceplugin/entity/deviceentity.h"


struct GetInnerStartEnabledStatusUseCaseRequest {

};

struct GetInnerStartEnabledStatusUseCaseResponse {
    bool value = false;
    ErrorCode error_code = OPERATION_INTERRUPTED;
};


class GetInnerStartEnabledStatusUseCase: public QObject {
public:
    explicit GetInnerStartEnabledStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity);

    GetInnerStartEnabledStatusUseCaseResponse execute(GetInnerStartEnabledStatusUseCaseRequest request);

private:
    std::shared_ptr<DeviceEntity> _device_entity = nullptr;
};



#endif //IES_DEVICE_PLUGIN_PROJECT_GETINNERSTARTENABLEDSTATUSUSECASE_H
