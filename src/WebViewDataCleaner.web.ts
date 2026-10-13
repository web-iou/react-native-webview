const unsupported = () =>
  Promise.reject(new Error('Clearing WebView data is not supported on this platform.'));

export const clearCache = (): Promise<void> => unsupported();

export const clearWebsiteData = (): Promise<void> => unsupported();
