//
//  RecordsViewController.m
//  StickMaze
//
//  Created by Zackary Neil Chaulk on 2015-03-28.
//  Copyright (c) 2015 Zackary Neil Chaulk. All rights reserved.
//

#import "RecordsViewController.h"

@implementation RecordsViewController
- (void)viewDidLoad {
    [super viewDidLoad];
    _scoreLoader = [[ScoreController alloc] init];
    [_scoreLoader loadScores];
    self.score.text = [NSString stringWithFormat:@"%d", [_scoreLoader getScore:1]];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)returnPress:(id)sender {
    [self.delegate notifyReturn];
}

@end
