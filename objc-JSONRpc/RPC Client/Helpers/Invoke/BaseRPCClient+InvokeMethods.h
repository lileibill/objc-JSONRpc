//
//  BaseRPCClient+InvokeMethods.h
//  objc-JSONRpc
//
//  Created by Rasmus Styrk on 29/08/12.
//  Copyright (c) 2012 Rasmus Styrk. All rights reserved.
//

#import "BaseRPCClient.h"

// Few other callback types (default RPCCompletedCallback is defined inside BaseRPCClient.h)
typedef void (^RPCSuccessCallback)(RPCResponse *response);
typedef void (^RPCFailedCallback)(RPCError *error);

/**
 * This category class adds invoking of methods to the base RPC Class.
 *
 *
 */
@interface BaseRPCClient (InvokeMethods)

/**
 * Invokes a RPCRequest against the end point
 *
 * @param RPCRequest reqeust The request to invoke
 * @param RPCCompletedCallback A callback method to invoke when request is done (or any error accours)
 * @return NSString The used request id. Can be used to match callback's if neccesary
 */
- (NSString *) invoke:(RPCRequest*) request onCompleted:(RPCCompletedCallback)callback;

/**
 * Invokes a method against the end point
 *
 * @param NSString method The method to invoke
 * @param id Either named or un-named parameter list (or nil)
 * @param RPCCompletedCallback A callback method to invoke when request is done (or any error accours)
 * @return NSString The used request id. Can be used to match callback's if neccesary
 */
- (NSString *) invoke:(NSString*) method params:(id) params  onCompleted:(RPCCompletedCallback)callback;

/**
 * Invokes a method against endpoint providing a way to define both a success callback and a failure callback.
 *
 * @param NSString method The method to invoke
 * @param id Either named or un-named parameter list (or nil)
 * @param RPCSuccessCallback A callback method to invoke when request finishes successfull
 * @param RPCFailedCallback A callback method to invoke when request finishes with an error
 * @return NSString The used request id. Can be used to match callback's if neccesary
 */
- (NSString *) invoke:(NSString*) method params:(id) params onSuccess:(RPCSuccessCallback)successCallback onFailure:(RPCFailedCallback)failedCallback;

@end