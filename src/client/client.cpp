/**
 * Copyright (c) 2020 ~ 2021 KylinSec Co., Ltd. 
 * kiran-session-manager is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2. 
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2 
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, 
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, 
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.  
 * See the Mulan PSL v2 for more details.  
 * 
 * Author:     tangjie02 <tangjie02@kylinos.com.cn>
 */

#include "src/client/client.h"
#include "src/app/app-manager.h"

namespace Kiran
{
namespace Daemon
{
Client::Client(const std::string &id) : id_(id)
{
}

std::string Client::get_app_id()
{
    auto app = AppManager::get_instance()->get_app_by_startup_id(this->id_);
    return app ? app->get_app_id() : std::string();
}
}  // namespace Daemon

}  // namespace Kiran