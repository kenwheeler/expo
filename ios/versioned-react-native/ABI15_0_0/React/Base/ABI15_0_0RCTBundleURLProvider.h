/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

extern NSString *const ABI15_0_0RCTBundleURLProviderUpdatedNotification;

extern const NSUInteger kABI15_0_0RCTBundleURLProviderDefaultPort;

@interface ABI15_0_0RCTBundleURLProvider : NSObject

/**
 * Set default settings on NSUserDefaults.
 */
- (void)setDefaults;

/**
 * Reset every settings to default.
 */
- (void)resetToDefaults;

/**
 * Returns the jsBundleURL for a given bundle entrypoint and
 * the fallback offline JS bundle if the packager is not running.
 */
- (NSURL *)jsBundleURLForBundleRoot:(NSString *)bundleRoot
                   fallbackResource:(NSString *)resourceName;

/**
 * Returns the resourceURL for a given bundle entrypoint and
 * the fallback offline resource file if the packager is not running.
 */
- (NSURL *)resourceURLForResourceRoot:(NSString *)root
                         resourceName:(NSString *)name
                    resourceExtension:(NSString *)extension
                        offlineBundle:(NSBundle *)offlineBundle;

/**
 * Returns the URL of the packager server.
 */
- (NSURL *)packagerServerURL;

/**
 * The IP address or hostname of the packager.
 */
@property (nonatomic, copy) NSString *jsLocation;

@property (nonatomic, assign) BOOL enableLiveReload;
@property (nonatomic, assign) BOOL enableMinification;
@property (nonatomic, assign) BOOL enableDev;

+ (instancetype)sharedSettings;

/**
 Given a hostname for the packager and a bundle root, returns the URL to the js bundle. Generally you should use the
 instance method -jsBundleURLForBundleRoot:fallbackResource: which includes logic to guess if the packager is running
 and fall back to a pre-packaged bundle if it is not.
 */
+ (NSURL *)jsBundleURLForBundleRoot:(NSString *)bundleRoot
                       packagerHost:(NSString *)packagerHost
                          enableDev:(BOOL)enableDev
                 enableMinification:(BOOL)enableMinification;

/**
 * Given a hostname for the packager and a resource path (including "/"), return the URL to the resource.
 * In general, please use the instance method to decide if the packager is running and fallback to the pre-packaged
 * resource if it is not: -resourceURLForResourceRoot:resourceName:resourceExtension:offlineBundle:
 */
+ (NSURL *)resourceURLForResourcePath:(NSString *)path
                         packagerHost:(NSString *)packagerHost
                                query:(NSString *)query;

@end
