//
//  DetailViewController.h
//  TroyStory4
//
//  Created by S on 10/21/14.
//  Copyright (c) 2014 Ryan Siska. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController

@property (strong, nonatomic) id detailItem;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end

