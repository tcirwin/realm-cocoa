////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#import <Foundation/Foundation.h>

@interface RLMUnitTestHelper : NSObject

/*
 Create an instance of the unit test helper.
 
 @param useInMemoryRealms  Set to `YES` to make the default Realm an in-memory Realm, `NO` to make it an on-disk Realm.
 */
- (instancetype)initUsingInMemoryRealms:(BOOL)useInMemoryRealms;

/*
 Invoke the unit test.
 
 This method should always be called within the `XCUnitTest`'s `-invokeTest` method. The block must contain a call to
 `[super invokeTest]`.
 */
- (void)invokeTestWithBlock:(void (^)(void))invokeBlock;

/*
 Dispatch an asynchronous block on the test-specific dispatch queue. Prefer this method to using GCD directly.
 */
- (void)dispatch:(dispatch_block_t)block;

/*
 Dispatch an asynchronous block on the test-specific dispatch queue, and wait for the block to complete executing before
 returning. Prefer this method to using GCD directly.
 */
- (void)dispatchAndWait:(dispatch_block_t)block;

@end
