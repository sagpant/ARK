/*
 * This source file is part of ArkNX
 * For the latest info, see https://github.com/ArkNX
 *
 * Copyright (c) 2013-2019 ArkNX authors.
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

#include "kernel/include/AFCRow.hpp"
#include "kernel/include/AFCData.hpp"
#include "kernel/include/AFCNode.hpp"

namespace ark {

// constructor
AFCRow::AFCRow(AFITableInner* pTableInner, uint32_t row)
    : row_(row)
{
    table_inner_ = pTableInner;
}

AFCRow::~AFCRow()
{
    data_.removeall();
}

// get row
uint32_t AFCRow::GetRow() const
{
    return row_;
}

// get row data
bool AFCRow::GetBool(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    return pData->GetBool();
}

int32_t AFCRow::GetInt32(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_INT);

    return pData->GetInt32();
}

int64_t AFCRow::GetInt64(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_INT64);

    return pData->GetInt64();
}

uint32_t AFCRow::GetUInt32(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_INT);

    return pData->GetUInt32();
}

uint64_t AFCRow::GetUInt64(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_INT64);

    return pData->GetUInt64();
}

float AFCRow::GetFloat(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_FLOAT);

    return pData->GetFloat();
}

double AFCRow::GetDouble(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_DOUBLE);

    return pData->GetDouble();
}

const std::string& AFCRow::GetString(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_STR);

    return pData->GetString();
}

const std::wstring& AFCRow::GetWString(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_WIDESTR);

    return pData->GetWString();
}

const AFGUID& AFCRow::GetGUID(const uint32_t index)
{
    AFINode* pData = FindData(index);
    ARK_ASSERT_RET_VAL(pData != nullptr, NULL_GUID);

    return pData->GetObject();
}

bool AFCRow::GetBool(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, false);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, false);

    return GetBool(index);
}

int32_t AFCRow::GetInt32(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_INT);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_INT);

    return GetInt32(index);
}

int64_t AFCRow::GetInt64(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_INT64);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_INT64);

    return GetInt64(index);
}

uint32_t AFCRow::GetUInt32(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_INT);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_INT);

    return GetUInt32(index);
}

uint64_t AFCRow::GetUInt64(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_INT64);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_INT64);

    return GetUInt64(index);
}

float AFCRow::GetFloat(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_FLOAT);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_FLOAT);

    return GetFloat(index);
}

double AFCRow::GetDouble(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_DOUBLE);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_FLOAT);

    return GetDouble(index);
}

const std::string& AFCRow::GetString(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_STR);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_STR);

    return GetString(index);
}

const std::wstring& AFCRow::GetWString(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_WIDESTR);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_WIDESTR);

    return GetWString(index);
}

const AFGUID& AFCRow::GetGUID(const std::string& name)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_GUID);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_GUID);

    return GetGUID(index);
}

// set row data
bool AFCRow::SetBool(const uint32_t index, bool value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_BOOLEAN, false);

    auto old_value = pData->GetBool();
    pData->SetBool(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetInt32(const uint32_t index, int32_t value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_INT32, false);

    auto old_value = pData->GetInt32();
    pData->SetInt32(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetInt64(const uint32_t index, int64_t value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_INT64, false);

    auto old_value = pData->GetInt64();
    pData->SetInt64(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetUInt32(const uint32_t index, uint32_t value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_UINT32, false);

    auto old_value = pData->GetUInt32();
    pData->SetUInt32(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetUInt64(const uint32_t index, uint64_t value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_UINT64, false);

    auto old_value = pData->GetUInt64();
    pData->SetUInt64(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetFloat(const uint32_t index, float value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_FLOAT, false);

    auto old_value = pData->GetFloat();
    pData->SetFloat(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetDouble(const uint32_t index, double value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_DOUBLE, false);

    auto old_value = pData->GetDouble();
    pData->SetDouble(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetString(const uint32_t index, const std::string& value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_STRING, false);

    auto old_value = pData->GetString();
    pData->SetString(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value.c_str()), AFCData(data_type, value.c_str()));
    }

    return true;
}

bool AFCRow::SetWString(const uint32_t index, const std::wstring& value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_WSTRING, false);

    auto old_value = pData->GetWString();
    pData->SetWString(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value.c_str()), AFCData(data_type, value.c_str()));
    }

    return true;
}

bool AFCRow::SetGUID(const uint32_t index, const AFGUID& value)
{
    AFINode* pData = FindData(index, true);
    ARK_ASSERT_RET_VAL(pData != nullptr, false);

    ARK_ASSERT_RET_VAL(pData->GetType() == ArkDataType::DT_GUID, false);

    auto old_value = pData->GetObject();
    pData->SetObject(value);

    if (old_value != value)
    {
        // data callbacks
        ArkDataType data_type = pData->GetType();
        OnTableCallBack(index, AFCData(data_type, old_value), AFCData(data_type, value));
    }

    return true;
}

bool AFCRow::SetBool(const std::string& name, bool value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetBool(index, value);
}

bool AFCRow::SetInt32(const std::string& name, int32_t value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetInt32(index, value);
}

bool AFCRow::SetInt64(const std::string& name, int64_t value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetInt64(index, value);
}

bool AFCRow::SetUInt32(const std::string& name, uint32_t value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetUInt32(index, value);
}

bool AFCRow::SetUInt64(const std::string& name, uint64_t value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetUInt64(index, value);
}

bool AFCRow::SetFloat(const std::string& name, float value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetFloat(index, value);
}

bool AFCRow::SetDouble(const std::string& name, double value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetDouble(index, value);
}

bool AFCRow::SetString(const std::string& name, const std::string& value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetString(index, value);
}

bool AFCRow::SetWString(const std::string& name, const std::wstring& value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetWString(index, value);
}

bool AFCRow::SetGUID(const std::string& name, const AFGUID& value)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, NULL_BOOLEAN);

    auto index = table_inner_->GetIndex(name);
    ARK_ASSERT_RET_VAL(index > 0, NULL_BOOLEAN);

    return SetGUID(index, value);
}

AFINode* AFCRow::First()
{
    iter_ = data_.begin();
    ARK_ASSERT_RET_VAL(iter_ != data_.end(), nullptr);

    return iter_->second;
}

AFINode* AFCRow::Next()
{
    ARK_ASSERT_RET_VAL(iter_ != data_.end(), nullptr);

    iter_++;
    ARK_ASSERT_RET_VAL(iter_ != data_.end(), nullptr);

    return iter_->second;
}

// find data
AFINode* AFCRow::FindData(const uint32_t index, bool bCreate /* = false*/)
{
    auto pData = data_.find_value(index);

    if (nullptr == pData && bCreate)
    {
        ARK_ASSERT_RET_VAL(table_inner_ != nullptr, nullptr);

        auto pTableMeta = table_inner_->GetMeta();
        ARK_ASSERT_RET_VAL(pTableMeta != nullptr, nullptr);

        auto pDataMeta = pTableMeta->FindMeta(index);
        ARK_ASSERT_RET_VAL(pDataMeta != nullptr, nullptr);

        pData = CreateDataByMeta(pDataMeta);
        if (!data_.insert(index, pData).second)
        {
            ARK_DELETE(pData);
            return nullptr;
        }
    }

    return pData;
}

bool AFCRow::OnTableCallBack(const uint32_t index, const AFIData& old_data, const AFIData& new_data)
{
    ARK_ASSERT_RET_VAL(table_inner_ != nullptr, false);

    table_inner_->OnRowDataChanged(row_, index, old_data, new_data);

    return true;
}

} // namespace ark