//
//  MYBaseRequest.h
//  MYNetwork
//
//  Created by APPLE on 2023/11/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MYBaseRequest : NSObject

- (void)requestApiName:(NSString *)apiName
               version:(NSString *)version
                 param:(NSDictionary *)param
               success:(void (^)(NSDictionary *result))success
               failure:(void (^)(NSError *error))failure;
@end

NS_ASSUME_NONNULL_END
