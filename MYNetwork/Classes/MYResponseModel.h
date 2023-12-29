//
//  MYResponseModel.h
//  MYNetwork
//
//  Created by APPLE on 2023/12/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MYResponseModel : NSObject

@property (nonatomic, assign) BOOL success;
@property (nonatomic, strong) NSDictionary *data;
@property (nonatomic, assign) NSTimeInterval timestamp;/**<  时间戳 */

@end

NS_ASSUME_NONNULL_END
