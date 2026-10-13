/**
 * Clears the WebView resource cache shared by the whole app. No WebView needs to be mounted.
 */
export declare function clearCache(): Promise<void>;
/**
 * Clears all website data shared by the whole app: caches, cookies, Web Storage, IndexedDB and
 * other storage. No WebView needs to be mounted.
 */
export declare function clearWebsiteData(): Promise<void>;
