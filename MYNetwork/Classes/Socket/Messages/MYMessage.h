//
//  MYMessage.h
//  DearIMProject
//
//  Created by APPLE on 2023/11/6.
//

#import <Foundation/Foundation.h>
#import "MYMessageEnum.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    MYMessageStatus_loading,
    MYMessageStatus_Success,
    MYMessageStatus_Failure,
} MYMessageStatus;

@interface MYMessage : NSObject

@property (nonatomic, assign) long msgId;/**<  消息id */
@property (nonatomic, assign) long fromId;/**<  消息发送方 */
@property (nonatomic, assign) MYMessageEntityType fromEntity;
@property (nonatomic, assign) long toId;/**<  消息接收方 */
@property (nonatomic, assign) MYMessageEntityType toEntity;
@property (nonatomic, strong) NSString *content;/**<  内容 */
@property (nonatomic, assign) MYMessageType messageType;/**<  messageType */
@property (nonatomic, assign) long long timestamp;
@property (nonatomic, assign) MYMessageStatus sendStatus;/**<  消息发送状态 */

@property (nonatomic, strong) NSArray *readList;/**<  已读列表 */

@end

@interface MYSuccessContentJsonModel : NSObject

@property (nonatomic, assign) long msgId;/**<  消息id */
@property (nonatomic, strong) NSString *content;/**<  内容 */
@property (nonatomic, assign) MYMessageType messageType;/**<  messageType */
@property (nonatomic, assign) long long timestamp;

@end

NS_ASSUME_NONNULL_END
