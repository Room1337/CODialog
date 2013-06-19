//
//  CODialog.h
//  CODialog
//
//  Created by Erik Aigner on 10.04.12.
//  Copyright (c) 2012 chocomoko.com. All rights reserved.
//
// ROOM1337-fixes and alterations to the show (/update) & hide methods, see comments in the .m

#import <UIKit/UIKit.h>


enum {
  CODialogStyleDefault = 0,
  CODialogStyleIndeterminate,
  CODialogStyleDeterminate,
  CODialogStyleSuccess,
  CODialogStyleError,
  CODialogStyleCustomView
};
typedef NSInteger CODialogStyle;

@interface CODialog : UIView
@property (nonatomic, strong) UIView *customView;
@property (nonatomic, assign) CODialogStyle dialogStyle;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, assign) CGFloat progress;
@property (nonatomic, assign) NSTimeInterval batchDelay;

+ (instancetype)dialogWithWindow:(UIWindow *)hostWindow;

- (id)initWithWindow:(UIWindow *)hostWindow;

/** @name Configuration */

- (void)resetLayout;
- (void)removeAllControls;
- (void)removeAllTextFields;
- (void)removeAllButtons;

- (void)addTextFieldWithPlaceholder:(NSString *)placeholder secure:(BOOL)secure;
- (void)addButtonWithTitle:(NSString *)title target:(id)target selector:(SEL)sel;
- (void)addButtonWithTitle:(NSString *)title target:(id)target selector:(SEL)sel highlighted:(BOOL)flag;

/** @name Getting Values */

- (NSString *)textForTextFieldAtIndex:(NSUInteger)index;

/** @name Showing, Updating and Hiding */

- (void)showAnimated:(BOOL)flag;
- (void)showAnimated:(BOOL)flag afterDelay:(NSTimeInterval)delay;
- (void)showAnimatedWithCompletionBlock:(void (^)(void))block;
- (void)showAnimatedAfterDelay:(NSTimeInterval)delay withCompletionBlock:(void (^)(void))block;

- (void)showOrUpdateAnimated:(BOOL)flag; // ROOM1337-for compatibility

- (void)update;

- (void)hideAnimated:(BOOL)flag;
- (void)hideAnimated:(BOOL)flag afterDelay:(NSTimeInterval)delay;
- (void)hideAnimatedWithCompletionBlock:(void (^)(void))block;
- (void)hideAnimatedAfterDelay:(NSTimeInterval)delay withCompletionBlock:(void (^)(void))block;

/** @name Methods to Override */

- (void)drawRect:(CGRect)rect;
- (void)drawDialogBackgroundInRect:(CGRect)rect;
- (void)drawButtonInRect:(CGRect)rect title:(NSString *)title highlighted:(BOOL)highlighted down:(BOOL)down;
- (void)drawTitleInRect:(CGRect)rect isSubtitle:(BOOL)isSubtitle;
- (void)drawSymbolInRect:(CGRect)rect;
- (void)drawTextFieldInRect:(CGRect)rect;
- (void)drawDimmedBackgroundInRect:(CGRect)rect;

@end
