#import "RCTStatusCachedPassword.h"

@implementation RCTStatusCachedPassword

+ (NSString *)retrieve {
    return [NSUserDefaults.standardUserDefaults stringForKey:@"FIXME_PASSWORD"];
}

+ (void)store:(NSString *)password {
    [NSUserDefaults.standardUserDefaults setObject:password forKey:@"FIXME_PASSWORD"];
}

@end
