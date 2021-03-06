//
//  GameViewController.h
//  StickMaze
//
//  Created by Zackary Neil Chaulk on 2015-03-28.
//  Copyright (c) 2015 Zackary Neil Chaulk. All rights reserved.
//

#import <GLKit/GLKit.h>
#import <CoreMotion/CoreMotion.h>
#import "PauseMenuViewController.h"
#include "ScoreController.h"
#import "StickMan.h"
#import "MazeModel.h"
@protocol GameViewControllerDelegate <NSObject>

-(void)notifyGameDone;

@end

typedef enum{
    NORMAL,
    INVERTED,
    LEFT,
    RIGHT
}gravityBase;

@interface GameViewController : GLKViewController<PauseMenuProtocolDelegate, UIApplicationDelegate>{
    CMMotionManager *motionMan;
    NSTimer *timer;
    float _avgAccX, _avgAccY, _avgAccZ, gravity;
    StickMan *player;
    MazeModel *mazeModel;
    gravityBase gBase;
    int startUpAcceleratorVal;
    BOOL zoomedOut;
    ScoreController *_scoreCon;
}
@property id<GameViewControllerDelegate> gvDelegate;
@property (strong, nonatomic) IBOutlet UILabel *lifeLabel;
@property (strong, nonatomic) IBOutlet UILabel *scoreLabel;

- (IBAction)pause:(id)sender;

- (void)setupGL;
- (void)tearDownGL;
- (void)setupOrthographicView: (CGSize)size;
@property (strong, nonatomic) EAGLContext *context;

@end
