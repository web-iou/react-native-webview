#import "RNCWebViewModule.h"

#import "RNCWebViewDecisionManager.h"

#import <React/RCTFabricComponentsPlugins.h>
#import <WebKit/WebKit.h>

@implementation RNCWebViewModule

RCT_EXPORT_MODULE(RNCWebViewModule)

RCT_EXPORT_METHOD(isFileUploadSupported:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject) {
    if (resolve) {
        resolve(@(YES));
    }
}

RCT_EXPORT_METHOD(shouldStartLoadWithLockIdentifier:(BOOL)shouldStart lockIdentifier:(double)lockIdentifier)
{
    [[RNCWebViewDecisionManager getInstance] setResult:shouldStart forLockIdentifier:(int)lockIdentifier];
}

RCT_EXPORT_METHOD(clearCache:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject)
{
    dispatch_async(dispatch_get_main_queue(), ^{
        NSSet *dataTypes = [NSSet setWithArray:@[
            WKWebsiteDataTypeMemoryCache,
            WKWebsiteDataTypeDiskCache,
            WKWebsiteDataTypeOfflineWebApplicationCache,
            WKWebsiteDataTypeFetchCache,
        ]];
        [[WKWebsiteDataStore defaultDataStore] removeDataOfTypes:dataTypes
                                                   modifiedSince:[NSDate distantPast]
                                               completionHandler:^{
            resolve(nil);
        }];
    });
}

RCT_EXPORT_METHOD(clearWebsiteData:(RCTPromiseResolveBlock)resolve reject:(RCTPromiseRejectBlock)reject)
{
    dispatch_async(dispatch_get_main_queue(), ^{
        [[WKWebsiteDataStore defaultDataStore] removeDataOfTypes:[WKWebsiteDataStore allWebsiteDataTypes]
                                                   modifiedSince:[NSDate distantPast]
                                               completionHandler:^{
            resolve(nil);
        }];
    });
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:(const facebook::react::ObjCTurboModule::InitParams &)params {
  return std::make_shared<facebook::react::NativeRNCWebViewModuleSpecJSI>(params);
}

Class RNCWebViewModuleCls(void) {
  return RNCWebViewModule.class;
}

@end
