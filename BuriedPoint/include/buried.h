#pragma once

#include <stdint.h>

#define BURIED_EXPORT __declspec(dllexport)
//因为对外给出的是个DLL动态库，动态库需要到处符号才能给外部调用，否则外部无法使用这些函数


extern "C" {
    
BURIED_EXPORT int BuriedTest();

typedef struct Buried Buried;

struct BuriedConfig 
{
    /* data */
    const char* host;
    const char* topic;
    const char* user_id;
    const char* version;
    // const char* app_version;
    // const char* app_name;
    const char* custom_data;

};

// 需要支持多实例，所以设计出 Buried Create 和 Buried Destroy 接口。
// Buried Create 用于创建一个实例，work dir作为这个实例的工作目录，一个实例一定会在对应的工作目录下生成文件等，不会污染其它目录。
// Buried Destroy 用于销毁一个实例，有创建就要有销毁，这里应该不用过多介绍,。
// Buried Start 用于开启埋点上报能力，第一个参数buried，传入具体的实例;表示在哪个实例下工作，第二个参数config，表示这个实例对应的配置，其中:
// 1.host:要上报的url
// 2.port:对应的端口号
// 3.topic:对应的topic，一般会上传到url:port/topic下
// 4.user id:用户的ID，方便分析信息，比如哪个用户使用app出了异常等
// 5.app_version:应用的版本号
// 6.app name:应用的名称
// 7.custom data:自定义数据，Json的字符串，因为各个用户肯定想携带不同的数据使用这个custom data正好




BURIED_EXPORT Buried* Buried_Create(const char* work_dir);

BURIED_EXPORT void Buried_Destroy(Buried* buried);

BURIED_EXPORT int32_t Buried_Start(Buried* buried, BuriedConfig* config);

// BURIED_EXPORT int32_t Buried_Report(Buried* buried, const char* title,const char* report_data,
//                                     uint32_t priority);

BURIED_EXPORT int32_t Buried_Report(Buried* buried, const char* report_data,
                                    uint32_t priority);
}

