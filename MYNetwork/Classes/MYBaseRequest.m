//
//  MYBaseRequest.m
//  MYNetwork
//
//  Created by APPLE on 2023/11/29.
//

#import "MYBaseRequest.h"
#import <AFNetworking/AFNetworking.h>
#import <MYUtils/MYUtils.h>
#import <YYModel/YYModel.h>
#import "MYNetworkManager.h"
#import "MYResponseModel.h"

@implementation MYBaseRequest

- (void)requestApiName:(NSString *)apiName
               version:(NSString *)version
                 param:(NSDictionary *)param
               success:(void (^)(NSDictionary *result))success
               failure:(void (^)(NSError *error))failure {
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    NSString *url = [NSString stringWithFormat:@"%@%@%@",MYNetworkManager.shared.getHost,apiName,version];
    NSDictionary *hearder;
    NSMutableDictionary *dict = @{}.mutableCopy;
    [dict addEntriesFromDictionary:param];
    //TODO: wmy log
//    [MYLog debug:url];
    [manager POST:url parameters:dict headers:hearder progress:nil
          success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        MYResponseModel *model = [MYResponseModel yy_modelWithDictionary:responseObject];
        if (model.success) {
            if (success) {
                success(model.data);
            }
        } else {
            NSError *error = [NSError errorWithDomain:model.data[@"errorMsg"] code:1 userInfo:nil];
            if (failure) {
                failure(error);
            }
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
        if ([error.domain isEqualToString:NSURLErrorDomain]) {
            // 服务异常
            NSString *exceptionString = @"service_exception".local;
            NSError *err = [NSError errorWithDomain:exceptionString code:500 userInfo:nil];
            if (failure) {
                failure(err);
            }
        } else {
            if (failure) {
                failure(error);
            }
        }
        
    }];
    
}


@end
