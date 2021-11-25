//
//  LRSBannerPageFlowCellProtocol.h
//  LangRen
//
//  Created by 刘俊臣 on 2018/3/26.
//  Copyright © 2018年 langrengame.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol LRSBannerPageFlowCellProtocol <NSObject>
/**
 *  主图
 */
@property (nonatomic, strong) UIImageView *mainImageView;

/**
 *  用来变色的view
 */
@property (nonatomic, strong) UIView *coverView;

@end
