#include "buried_core.h"
#include <filesystem>

#include "spdlog/sinks/basic_file_sink.h"


#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

// third_party\spdlog\include\spdlog\sinks\basic_file_sink.h

// Buried::Buried(const std::string& work_dir) {
//   // 创建控制台输出的日志记录器
//   auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
//   // 将传入的工作目录参数转换为路径对象
//   std::filesystem::path _work_dir(work_dir);
//   // 如果工作目录不存在，则创建
//   if (!std::filesystem::exists(_work_dir))
//   {
//     /* code */
//     std::filesystem::create_directories(_work_dir);
//   }
//   // 将工作目录路径追加到日志文件目录
//   _work_dir /= "buried";
//    // 如果日志文件目录不存在，则创建
//   if (!std::filesystem::exists(_work_dir)) {
//     std::filesystem::create_directories(_work_dir);
//   }
//   // 拼接日志文件路径
//   std::filesystem::path _log_dir(_work_dir);
//   _log_dir /= "buried.log";

//   // 创建文件输出的日志记录器
//   auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>( _log_dir.string(),  true);
  
//   // 创建日志器并设置输出格式和日志级别
//   logger_ = std::shared_ptr<spdlog::logger>(
//     new spdlog::logger("buried_sink",{console_sink,file_sink})
//   );
//   logger_->set_pattern("[%c] [%s:%#] [%l] %v");
//   logger_->set_level(spdlog::level::trace);
//   //trace 记录所有的日志级别，debug，warn之类的

//   // InitWorkPath_(work_dir);
//   // InitLogger_();

//   // SPDLOG_LOGGER_INFO(Logger(), "Buried init success");
//   // 输出跟踪级别的日志消息（带参数）
//   SPDLOG_LOGGER_TRACE(logger_, "Some trace message with param: {}", 42);
//   // 输出调试级别的日志消息
//   SPDLOG_LOGGER_DEBUG(logger_, "Some debug message");
// }

Buried::Buried(std::string work_dir) {
  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

  std::filesystem::path _work_dir(work_dir);
  if (!std::filesystem::exists(_work_dir)) {
    std::filesystem::create_directories(_work_dir);
  }
  _work_dir /= "buried";

  if (!std::filesystem::exists(_work_dir)) {
    std::filesystem::create_directories(_work_dir);
  }

  std::filesystem::path _log_dir(_work_dir);
  _log_dir /= "buried.log";

  auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
      _log_dir.string(), true);

  logger_ = std::shared_ptr<spdlog::logger>(
      new spdlog::logger("buried_sink", {console_sink, file_sink}));
  logger_->set_pattern("[%c] [%s:%#] [%l] %v");
  logger_->set_level(spdlog::level::trace);
  SPDLOG_LOGGER_TRACE(logger_, "Some trace message with param: {}", 42);
  SPDLOG_LOGGER_DEBUG(logger_, "Some debug message");
}

// #define SPDLOG_LEVEL_TRACE 0
// #define SPDLOG_LEVEL_DEBUG 1
// #define SPDLOG_LEVEL_INFO 2
// #define SPDLOG_LEVEL_WARN 3
// #define SPDLOG_LEVEL_ERROR 4
// #define SPDLOG_LEVEL_CRITICAL 5
// #define SPDLOG_LEVEL_OFF 6


Buried::~Buried() {}

// void Buried::InitWorkPath_(const std::string& work_dir) {
//   std::filesystem::path _work_dir(work_dir);
//   if (!std::filesystem::exists(_work_dir)) {
//     std::filesystem::create_directories(_work_dir);
//   }

//   work_path_ = _work_dir / "buried";
//   if (!std::filesystem::exists(work_path_)) {
//     std::filesystem::create_directories(work_path_);
//   }
// }

// Buried::Buried(const std::string& work_dir) {
//   InitWorkPath_(work_dir);
//   InitLogger_();

//   SPDLOG_LOGGER_INFO(Logger(), "Buried init success");
// }




// std::shared_ptr<spdlog::logger> Buried::Logger() { return logger_; }



BuriedResult Buried::Start(const Config& config) {
    return BuriedResult::kBuriedOk;
}

BuriedResult Buried::Report(const char* report_data, uint32_t priority) {
  return BuriedResult::kBuriedOk;
}

