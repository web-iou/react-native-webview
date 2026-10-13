import React from 'react';
import { AndroidWebViewProps } from './WebViewTypes';
declare const isFileUploadSupported: () => Promise<boolean>;
declare const WebView: React.ForwardRefExoticComponent<AndroidWebViewProps & React.RefAttributes<unknown>> & {
    isFileUploadSupported: typeof isFileUploadSupported;
};
export default WebView;
