﻿/*
* This source file is part of ArkGameFrame
* For the latest info, see https://github.com/ArkGame
*
* Copyright (c) 2013-2017 ArkGame authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#include "SDK/Interface/AFIModule.h"
#include "AFINetClientService.h"

namespace ark
{

    class AFINetClientManagerModule : public AFIModule
    {
    public:
        virtual int CreateClusterClients() = 0;
        virtual int CreateClusterClient(const int bus_id, const std::string& url) = 0;

        virtual AFINetClientService* GetNetClientService(const uint8_t& app_type) = 0;
        virtual AFINetClientService* GetNetClientServiceByBusID(const int bus_id) = 0;

        virtual bool AddNetConnectionBus(const int bus_id, AFINet* net_client_ptr) = 0;
        virtual bool RemoveNetConnectionBus(const int bus_id) = 0;
        virtual AFINet* GetNetConnectionBus(const int src_bus, const int target_bus) = 0;
    };

}