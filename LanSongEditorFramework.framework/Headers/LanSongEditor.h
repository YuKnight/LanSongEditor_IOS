//
//  LanSongEditor.h
//  LanSongEditor
//
//  Created by sno on 16/8/3.
//  Copyright © 2016年 sno. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for LanSongEditor.
FOUNDATION_EXPORT double LanSongEditorVersionNumber;

//! Project version string for LanSongEditor.
FOUNDATION_EXPORT const unsigned char LanSongEditorVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LanSongEditor/PublicHeader.h>


//**************************容器类(8个)***********************************
//视频预览容器
#import <LanSongEditorFramework/DrawPadVideoPreview.h>

//视频后台执行容器
#import <LanSongEditorFramework/DrawPadVideoExecute.h>

//AE模板的后台合成容器
#import <LanSongEditorFramework/DrawPadAEExecute.h>

//AE模板的前台预览容器
#import <LanSongEditorFramework/DrawPadAEPreview.h>
#import <LanSongEditorFramework/BitmapPadPreview.h>

//录制视频容器:录制视频
#import <LanSongEditorFramework/DrawPadCameraPreview.h>

//图片容器: 给图片增加滤镜; 给多张图片增加滤镜;
#import <LanSongEditorFramework/BitmapPadExecute.h>

//音频容器:用来合成各种声音
#import <LanSongEditorFramework/AudioPadExecute.h>

//容器显示,集成UIView
#import <LanSongEditorFramework/LanSongView2.h>

//前台录制UI
#import <LanSongEditorFramework/LSORecordUIPreview.h>

//后台录制UI
#import <LanSongEditorFramework/LSORecordUIExecute.h>


#import <LanSongEditorFramework/DrawPadAeText.h>
#import <LanSongEditorFramework/LSOOneLineText.h>

//********************图层类(6个)*************************************

//处理视频和音频的基本单元.
#import <LanSongEditorFramework/LSOVideoBody.h>
#import <LanSongEditorFramework/LSOAudioBody.h>

//图层的父类, 所有的xxxPen 集成这个父类;
#import <LanSongEditorFramework/Pen.h>

//视频图层, 用在前台预览容器中
#import <LanSongEditorFramework/VideoPen.h>
//视频图层, 用在后台容器中
#import <LanSongEditorFramework/VideoPen2.h>

//MV图层
#import <LanSongEditorFramework/MVPen.h>

//UI图层, 用来增加一些UIView到容器中
#import <LanSongEditorFramework/ViewPen.h>

//图片图层;
#import <LanSongEditorFramework/BitmapPen.h>

//子图层: 可做灵魂出窍等功能;
#import <LanSongEditorFramework/SubPen.h>
//******************************滤镜****************************************
//各种滤镜的头文件;
#import <LanSongEditorFramework/LanSong.h>
//***************************独立的音视频功能******************************
//Mp3 转AAC的类
#import <LanSongEditorFramework/LanSongMp3ToAAC.h>
//提取视频帧, 异步工作模式
#import <LanSongEditorFramework/LanSongExtractFrame.h>
//提取视频帧, 同步工作模式
#import <LanSongEditorFramework/LanSongVideoDecoder.h>

//提取MV视频帧, 同步工作模式
#import <LanSongEditorFramework/LanSongGetMVFrame.h>

//视频缩放, 支持任意视频分辨率的缩放
#import <LanSongEditorFramework/LanSongScaleExecute.h>

//视频倒序
#import <LanSongEditorFramework/LanSongVideoReverse.h>

//音频录制类
#import <LanSongEditorFramework/LanSongAudioRecorder.h>

//视频转换为编辑模式.
#import <LanSongEditorFramework/LanSongEditMode.h>

//*************************辅助, 常见功能处理类**************************
#import <LanSongEditorFramework/LanSongLog.h>
//获取音视频的信息;
#import <LanSongEditorFramework/MediaInfo.h>

//列举了一些常见的视频编辑功能
#import <LanSongEditorFramework/VideoEditor.h>

//创建临时 处理文件的头文件
#import <LanSongEditorFramework/LanSongFileUtil.h>

//处理图片的一些公共函数.(持续增加)
#import <LanSongEditorFramework/LanSongImageUtil.h>
//辅助类, 保存数据到文件;
#import <LanSongEditorFramework/LSOSaveToFile.h>

//*************************杂项**************************

#import <LanSongEditorFramework/LSOAeView.h>
#import <LanSongEditorFramework/LSOAeImage.h>
#import <LanSongEditorFramework/LSOAeText.h>

@interface LanSongEditor : NSObject

/**
  获取当前sdk的限制时间中的年份.
 */
+(int)getLimitedYear;

/**
 获取当前sdk的限制时间中的月份

 @return
 */
+(int)getLimitedMonth;

/**
 返回当前sdk的版本号.

 @return
 */
+(NSString *)getVersion;
/**
 初始化sdk,

 @return
 */
+(BOOL)initSDK:(NSString *)name;

/**
 使用完毕sdk后, 注销sdk, 
 (当前内部执行为空,可以不调用. 仅预留)
 */
+(void)unInitSDK;



/**
 设置内部文件创建在哪个文件夹下;
 
 如果不设置,默认在当前Document/lansongBox下;
 举例:
 NSArray *paths =NSSearchPathForDirectoriesInDomains(NSDocumentDirectory,NSUserDomainMask, YES);
 NSString *documentsDirectory =[paths objectAtIndex:0];
 NSString *tmpDir = [documentsDirectory stringByAppendingString:@"/box2"];
 [LanSongFileUtil setGenTempFileDir:tmpDir];
 
 建议在initSDK的时候设置;
 */
+(void)setTempFileDir:(NSString *)path;
/**
 我们的内部默认以当前时间为文件名; 比如:20180906094232_092.mp4
 你可以在这个时间前面增加一些字符串,比如增加用户名,手机型号等等;
 举例:
 prefix:xiaoming_iphone6s; 则生成的文件名是: xiaoming_iphone6s20180906094232_092.mp4
 @param prefix
 */
+(void)setTempFilePrefix:(NSString *)prefix;




/**
 设置在编码的时候, 编码成 编辑模式的视频;
 我们内部定义一种视频格式,命名为:编辑模式;
 这样的视频: 会极速的定位到指定的一帧;像翻书一样的翻看每一帧视频;
 
 @param as 是否为编辑模式. 默认不是编辑模式;
 */
+(void)setEncodeVideoAsEditMode:(BOOL)as;

@end
