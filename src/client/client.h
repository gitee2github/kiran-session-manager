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

#pragma once

#include "lib/base.h"

namespace Kiran
{
namespace Daemon
{
enum ClientEndSessionFlag
{
    // 客户端在结束会话时保存必要的信息
    CLIENT_END_SESSION_FLAG_SAVE = 1 << 1,
    // 会话结束第二阶段
    CLIENT_END_SESSION_FLAG_LAST = 1 << 2
};

enum ClientType
{
    CLIENT_TYPE_XSMP,
    CLIENT_TYPE_DBUS
};

class Client
{
public:
    Client(const std::string &id);
    virtual ~Client(){};

    std::string get_id() { return this->id_; };

    virtual std::string get_app_id();

    virtual ClientType get_type() = 0;
    virtual bool cancel_end_session() = 0;
    virtual bool query_end_session(bool interact) = 0;
    virtual bool end_session(bool save_data) = 0;
    virtual bool end_session_phase2() = 0;
    virtual bool stop() = 0;

private:
    void on_bus_acquired(Glib::RefPtr<Gio::AsyncResult> &result);

private:
    std::string id_;
};

using KSMClientVec = std::vector<std::shared_ptr<Client>>;
}  // namespace Daemon
}  // namespace Kiran
