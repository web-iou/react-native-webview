import { TurboModuleRegistry } from 'react-native';
import type { Spec } from './NativeRNCWebViewModule';

function getModule(): Spec {
  const module = TurboModuleRegistry.get<Spec>('RNCWebViewModule');
  if (!module) {
    throw new Error('Clearing WebView data is not supported on this platform.');
  }
  return module;
}

/**
 * Clears the WebView resource cache shared by the whole app. No WebView needs to be mounted.
 */
export async function clearCache(): Promise<void> {
  return getModule().clearCache();
}

/**
 * Clears all website data shared by the whole app: caches, cookies, Web Storage, IndexedDB and
 * other storage. No WebView needs to be mounted.
 */
export async function clearWebsiteData(): Promise<void> {
  return getModule().clearWebsiteData();
}
