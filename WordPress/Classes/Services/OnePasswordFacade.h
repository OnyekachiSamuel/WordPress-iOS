#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef void (^OnePasswordFacadeCallback)(NSString * _Nullable username, NSString * _Nullable password,  NSString * _Nullable oneTimePassword, NSError * _Nullable);

extern NSString * const WPOnePasswordTitleKey;
extern NSString * const WPOnePasswordUsernameKey;
extern NSString * const WPOnePasswordPasswordKey;
extern NSString * const WPOnePasswordGeneratedPasswordMinLengthKey;
extern NSString * const WPOnePasswordGeneratedPasswordMaxLengthKey;
extern NSInteger WPOnePasswordErrorCodeCancelledByUser;

/**
 *  This protocol is a Facade that hides some of the implementation details for interacting with 1Password.
 */
@protocol OnePasswordFacade

/**
 *  This method will pull up the 1Password extension and display any logins for the passed in `loginUrl`
 *
 *  @param loginUrl       the URL of the site in question.
 *  @param viewController the view controller of the class that needs the 1Password extension to appear. Note this can't be nil.
 *  @param sender         the control that triggered the action
 *  @param completion     block that is called when 1Password is done retrieving the password.
 */
- (void)findLoginForURLString:(NSString *)loginUrl viewController:(UIViewController *)viewController sender:(id)sender completion:(OnePasswordFacadeCallback)completion;

/**
 *  A method to check if the 1Password extension is enabled
 *
 *  @return whether the 1Password extension is enabled.
 */
- (BOOL)isOnePasswordEnabled;

/**
 *  Stores a new entry in the 1Password extension.
 *
 *  @param URLString                    the URL of the site in question.
 *  @param loginDetailsDictionary       a dictionary containing login credentials to store.
 *  @param passwordGenerationOptions    a dictionary specifying password generation options.
 *  @param viewController the view controller of the class that needs the 1Password extension to appear. Note this can't be nil.
 *  @param sender         the control that triggered the action
 *  @param completion     block that is called when 1Password is done setting the credentials.
 */
- (void)storeLoginForURLString:(NSString *)URLString
                  loginDetails:(NSDictionary *)loginDetailsDictionary
     passwordGenerationOptions:(NSDictionary *)passwordGenerationOptions
             forViewController:(UIViewController *)viewController
                        sender:(id)sender
                    completion:(void (^)(NSDictionary *loginDictionary, NSError * _Nullable error))completion;

@end
NS_ASSUME_NONNULL_END

@interface OnePasswordFacade : NSObject <OnePasswordFacade>

@end
