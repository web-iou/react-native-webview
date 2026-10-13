
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off


#include <NativeModules.h>
#include <tuple>

namespace RNCWebViewCodegen {

struct WebviewModuleSpec : winrt::Microsoft::ReactNative::TurboModuleSpec {
  static constexpr auto methods = std::tuple{
      Method<void(Promise<void>) noexcept>{0, L"clearCache"},
      Method<void(Promise<void>) noexcept>{1, L"clearWebsiteData"},
      Method<void(Promise<bool>) noexcept>{2, L"isFileUploadSupported"},
      Method<void(bool, double) noexcept>{3, L"shouldStartLoadWithLockIdentifier"},
  };

  template <class TModule>
  static constexpr void ValidateModule() noexcept {
    constexpr auto methodCheckResults = CheckMethods<TModule, WebviewModuleSpec>();

    REACT_SHOW_METHOD_SPEC_ERRORS(
          0,
          "clearCache",
          "    REACT_METHOD(clearCache) void clearCache(::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(clearCache) static void clearCache(::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          1,
          "clearWebsiteData",
          "    REACT_METHOD(clearWebsiteData) void clearWebsiteData(::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(clearWebsiteData) static void clearWebsiteData(::React::ReactPromise<void> &&result) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          2,
          "isFileUploadSupported",
          "    REACT_METHOD(isFileUploadSupported) void isFileUploadSupported(::React::ReactPromise<bool> &&result) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(isFileUploadSupported) static void isFileUploadSupported(::React::ReactPromise<bool> &&result) noexcept { /* implementation */ }\n");
    REACT_SHOW_METHOD_SPEC_ERRORS(
          3,
          "shouldStartLoadWithLockIdentifier",
          "    REACT_METHOD(shouldStartLoadWithLockIdentifier) void shouldStartLoadWithLockIdentifier(bool shouldStart, double lockIdentifier) noexcept { /* implementation */ }\n"
          "    REACT_METHOD(shouldStartLoadWithLockIdentifier) static void shouldStartLoadWithLockIdentifier(bool shouldStart, double lockIdentifier) noexcept { /* implementation */ }\n");
  }
};

} // namespace RNCWebViewCodegen
