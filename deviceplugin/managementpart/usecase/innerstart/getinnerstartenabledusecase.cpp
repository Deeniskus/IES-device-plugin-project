#include "getinnerstartenabledstatususecase.h"

GetInnerStartEnabledStatusUseCase::GetInnerStartEnabledStatusUseCase(const std::shared_ptr<DeviceEntity> &device_entity):
        _device_entity(device_entity){

}

GetInnerStartEnabledStatusUseCaseResponse GetInnerStartEnabledStatusUseCase::execute(GetInnerStartEnabledStatusUseCaseRequest request) {
    GetInnerStartEnabledStatusUseCaseResponse response{};

    if (_device_entity != nullptr) {
        GetInnerStartEnabledStatusRequest entity_request;
        auto entity_response = _device_entity->getInnerStartEnabledStatus(entity_request);

        response.error_code = entity_response.error_code;
        response.value = entity_response.result;
    }

    return response;
}