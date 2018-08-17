//
//  RCTStatusCachedPassword.h
//  RCTStatus
//
//  Created by Igor Mandrigin on 2018-08-16.
//  Copyright © 2018 Status.im. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RCTStatusCachedPassword : NSObject

+ (NSString *)retrieve;

+ (void)store:(NSString *)password;

@end
