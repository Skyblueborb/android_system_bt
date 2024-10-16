/*
 * Copyright 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <functional>
#include <list>
#include <string>

constexpr char kPrivateAddressPrefix[] = "xx:xx:xx:xx";
#define PRIVATE_ADDRESS(addr)                                            \
  (addr.ToString()                                                       \
       .replace(0, strlen(kPrivateAddressPrefix), kPrivateAddressPrefix) \
       .c_str())

namespace bluetooth {
namespace shim {

using DumpsysFunction = std::function<void(int fd)>;

/**
 * Entrypoint from legacy stack to provide dumpsys functionality
 * for both the legacy shim and the Gabeldorsche stack.
 */
void Dump(int fd);

/**
 * Dumpsys access for legacy shim modules.
 */
void RegisterDumpsysFunction(const void* token, DumpsysFunction func);
void UnregisterDumpsysFunction(const void* token);

}  // namespace shim
}  // namespace bluetooth
