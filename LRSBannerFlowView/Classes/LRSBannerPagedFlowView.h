
#import <UIKit/UIKit.h>
#import "LRSBannerPageFlowCellProtocol.h"

@protocol LRSBannerPageFlowDataSource;
@protocol LRSBannerPageFlowDelegate;


typedef NS_ENUM(NSUInteger, LRSBannerPagedFlowViewOrientation) {
    LRSBannerPagedFlowViewHorizontal,
    LRSBannerPagedFlowViewVertical
};

@interface LRSBannerPagedFlowView : UIView<UIScrollViewDelegate>

/**
 *  默认为横向
 */
@property (nonatomic,assign) LRSBannerPagedFlowViewOrientation orientation;

@property (nonatomic, strong) UIScrollView *scrollView;

@property (nonatomic,assign) BOOL needsReload;
/**
 *  总页数
 */
@property (nonatomic,assign) NSInteger pageCount;

@property (nonatomic,strong) NSMutableArray *cells;
@property (nonatomic,assign) NSRange visibleRange;
/**
 *  如果以后需要支持reuseIdentifier，这边就得使用字典类型了
 */
@property (nonatomic,strong) NSMutableArray *reusableCells;

@property (nonatomic,weak)   id <LRSBannerPageFlowDataSource> dataSource;
@property (nonatomic,weak)   id <LRSBannerPageFlowDelegate>   delegate;

/**
 *  指示器
 */
@property (nonatomic,retain)  UIPageControl *pageControl;

/**
 *  非当前页的透明比例
 */
@property (nonatomic, assign) CGFloat minimumPageAlpha;

/**
 左右间距,默认20
 */
@property (nonatomic, assign) CGFloat leftRightMargin;

/**
 上下间距,默认30
 */
@property (nonatomic, assign) CGFloat topBottomMargin;

/**
 *  是否开启自动滚动,默认为开启
 */
@property (nonatomic, assign) BOOL isOpenAutoScroll;

/**
 *  是否开启无限轮播,默认为开启
 */
@property (nonatomic, assign) BOOL isCarousel;

/**
 *  当前是第几页
 */
@property (nonatomic, assign, readonly) NSInteger currentPageIndex;

/**
 *  定时器
 */
@property (nonatomic, weak) NSTimer *timer;

/**
 *  自动切换视图的时间,默认是5.0
 */
@property (nonatomic, assign) CGFloat autoTime;

/**
 *  原始页数
 */
@property (nonatomic, assign) NSInteger orginPageCount;

/**
 *  刷新视图
 */
- (void)reloadData;

/**
 *  获取可重复使用的Cell
 *
 *  @return views
 */
- (UIView<LRSBannerPageFlowCellProtocol> *)dequeueReusableCell;

- (void)scrollToPage:(NSInteger)pageNumber;

/**
 *  开启定时器,废弃
 */
//- (void)startTimer;

/**
 *  关闭定时器,关闭自动滚动
 */
- (void)stopTimer;


@property (nonatomic, assign) CGFloat itemScale;

@end


@protocol  LRSBannerPageFlowDelegate<NSObject>

@optional

- (CGSize)sizeForPageInFlowView:(LRSBannerPagedFlowView *)flowView;

- (void)didScrollToPage:(NSInteger)pageNumber inFlowView:(LRSBannerPagedFlowView *)flowView;

- (void)didSelectCell:(UIView *)subView withSubViewIndex:(NSInteger)subIndex;

@end


@protocol LRSBannerPageFlowDataSource <NSObject>


- (NSInteger)numberOfPagesInFlowView:(LRSBannerPagedFlowView *)flowView;

- (UIView<LRSBannerPageFlowCellProtocol> *)flowView:(LRSBannerPagedFlowView *)flowView cellForPageAtIndex:(NSInteger)index;

@end
