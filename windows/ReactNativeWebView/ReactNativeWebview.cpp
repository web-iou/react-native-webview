#include "pch.h"

#include "ReactNativeWebview.h"

namespace winrt::ReactNativeWebview
{

// See https://microsoft.github.io/react-native-windows/docs/native-platform for help writing native modules

void RNCWebViewModule::Initialize(React::ReactContext const &reactContext) noexcept {
  m_context = reactContext;
}

void RNCWebViewModule::shouldStartLoadWithLockIdentifier(bool /*shouldStart*/, double /*lockIdentifier*/) noexcept {
  // Implementation for handling should start load request callback
  // This is called from JS to respond to onShouldStartLoadWithRequest
}

void RNCWebViewModule::clearCache(React::ReactPromise<void> &&promise) noexcept {
  // WebView2 browsing data is owned by a CoreWebView2 profile, which is only
  // available from an existing WebView instance.
  promise.Reject("clearCache is not supported on Windows. Use the WebView instance's clearCache instead.");
}

void RNCWebViewModule::clearWebsiteData(React::ReactPromise<void> &&promise) noexcept {
  promise.Reject("clearWebsiteData is not supported on Windows.");
}

void RNCWebViewModule::isFileUploadSupported(React::ReactPromise<bool> &&promise) noexcept {
  // WebView2 on Windows supports file uploads
  promise.Resolve(true);
}

} // namespace winrt::ReactNativeWebview