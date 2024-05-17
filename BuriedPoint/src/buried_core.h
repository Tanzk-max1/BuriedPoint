#pragma once
#include <stdint.h>
#include <filesystem>


#include <memory.h>
#include <string>
#include "buried_common.h"
#include "include/buried.h"

namespace spdlog {
    class logger;
}

struct Buried
{
public:
    struct Config{
        std::string host;
        std::string topic;
        std::string user_id;
        std::string version;
        std::string custom_data;
    };
public:
  // Buried(const std::string& work_dir);
  Buried(std::string work_dir);
  ~Buried();

  BuriedResult Start(const Config& config);
  //这个函数是 Buried 类的成员函数，返回类型为 BuriedResult，接受一个 Config 类型的参数 config。
  //它的作用是启动 Buried 对象，并根据传入的配置参数进行初始化和设置。函数可能会返回不同的 BuriedResult 值，用于表示启动过程中的不同状态或错误。

  BuriedResult Report(const char* report_data, uint32_t priority);
//   进行数据上报或记录，用于上报不同的状态码

//  public:
//   std::shared_ptr<spdlog::logger> Logger();

//  private:
//   void InitWorkPath_(const std::string& work_dir);

//   void InitLogger_();

 private:
  std::shared_ptr<spdlog::logger> logger_;

  // std::filesystem::path work_path_;
};
