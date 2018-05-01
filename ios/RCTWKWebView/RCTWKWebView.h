#import <WebKit/WebKit.h>

#import <React/RCTView.h>

@class RCTWKWebView;

/**
 * Special scheme used to pass messages to the injectedJavaScript
 * code without triggering a page load. Usage:
 *
 *   window.location.href = RCTJSNavigationScheme + '://hello'
 */
extern NSString *const RCTJSNavigationScheme;

@protocol RCTWKWebViewFactory <NSObject>

- (WKWebView *)newWebViewWithFrame:(CGRect)frame configuration:(WKWebViewConfiguration *)config;

@end

@protocol RCTWKWebViewDelegate <NSObject>

- (BOOL)webView:(RCTWKWebView *)webView
shouldStartLoadForRequest:(NSMutableDictionary<NSString *, id> *)request
   withCallback:(RCTDirectEventBlock)callback;

@end

@interface RCTWKWebView : RCTView

@property (nonatomic, weak) id<RCTWKWebViewDelegate> delegate;

@property (nonatomic, copy) NSDictionary *source;
@property (nonatomic, assign) UIEdgeInsets contentInset;
@property (nonatomic, assign) BOOL automaticallyAdjustContentInsets;
@property (nonatomic, assign) BOOL openNewWindowInWebView;
@property (nonatomic, copy) NSString *injectedJavaScript;
@property (nonatomic, assign) BOOL hideKeyboardAccessoryView;
@property (nonatomic, copy) NSDictionary *userData;

- (void)instantiateDefaultWebView;
- (void)instantiateWebViewWithFactory:(id<RCTWKWebViewFactory>)webViewFactory;

- (void)goForward;
- (void)goBack;
- (BOOL)canGoBack;
- (BOOL)canGoForward;
- (void)reload;
- (void)stopLoading;
- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id, NSError *error))completionHandler;

@end
