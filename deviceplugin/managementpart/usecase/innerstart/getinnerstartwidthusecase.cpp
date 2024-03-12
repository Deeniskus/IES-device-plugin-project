#include "getinnerstartwidthusecase.h"


GetInnerStartWidthUseCase::GetInnerStartWidthUseCase(const std::shared_ptr<DeviceEntity> &device_entity):
        _device_entity(device_entity){

}

GetInnerStartWidthUseCaseResponse GetInnerStartWidthUseCase::execute(GetInnerStartWidthUseCaseRequest request) {
    GetInnerStartWidthUseCaseResponse response{};

    if (_device_entity != nullptr) {
        GetInnerStartWidthRequest entity_request;
        auto entity_response = _device_entity->getInnerStartWidth(entity_request);

        response.error_code = entity_response.error_code;
        response.value = entity_response.result;
    }

    return response;
}