//
//  APIManager.h
//  RedMountainMobile
//
//  Created by Hubino on 1/27/16.
//  Copyright © 2016 Hubino. All rights reserved.
//

@interface Identity : NSObject

@property NSString *uid;

@property NSString *clientId;

@property NSString *avatar;

@property NSString *key_public;

@property NSString *key_fingerprint;

@property NSDate *enroll_date;

@property NSString *name;

@property NSString *sex;

@property NSString *age;

@property NSString *face_shape;

@property NSString *skin_tone;

@property NSString *eye_position;

@property NSString *eye_setting;

@property NSString *eye_shape;

@property NSString *eye_colour;

@property BOOL isCorrectDecision;

@property NSString *nsstr_deviceUUID;

@property NSString *nsstr_strSysOSName;

@property NSString *nsstr_strSysOSVersion;

@property NSString *nsstr_appVersion;

@property NSString *nsstr_manufacturer;

@property NSString *nsstr_modelInfo;

@property NSString *nsstr_camerasInfo;

@property NSString *nsstr_sessionId;

@property NSString *nsstr_type;

@property NSMutableArray *nsmutble_faceImages;

@property UIImage *uimg_faceImages;

@property UIImage *uimg_eyeImages;


@property NSMutableArray *nsmutble_eyePatchImages;

@property float *eyerect;

@property NSMutableArray *eyerectArrayValue;


@property BOOL isCamera;


@end

@interface Credentials : NSObject


@property (nonatomic, strong) NSString *clientId;

@property (nonatomic, strong) NSString *clientKey;

@property (nonatomic, strong) NSString *clientName;

@end



@interface Result : NSObject

@property NSString *code;

@property NSString *message;

@end

/*!
 * @typedef CaptureParameters
 * @brief A list of CaptureParameters types.
 * @constant Camera camera Front and Back.
 * @constant Vibration On Off.
 * @constant VoiceEvent On Off.
 * @constant Help On Off.
 * @constant VoiceCapture On Off.
 * @constant UserAssist On Off.
 */
@interface CaptureParameters : NSObject

typedef NS_ENUM(NSUInteger, Camera) {
    CAMERA_BACK,
    CAMERA_FRONT
};


typedef NS_ENUM(NSUInteger, Vibration) {
    VIBRATION_OFF,
    VIBRATION_ON
};

typedef NS_ENUM(NSUInteger, VoiceEvent) {
    
    VOICE_EVENT_OFF,
    VOICE_EVENT_ON
};

typedef NS_ENUM(NSUInteger, Help) {
    HELP_OFF,
    HELP_ON
};


typedef NS_ENUM(NSUInteger, VoiceCapture) {
    
    VOICE_CAPTURE_OFF,
    VOICE_CAPTURE_ON
};

typedef NS_ENUM(NSUInteger, UserAssist) {
    USER_ASSIST_OFF,
    USER_ASSIST_ON
};


@property (nonatomic) VoiceEvent voiceEvent;

@property (nonatomic) VoiceCapture voiceCapture;

@property (nonatomic) Vibration vibration;

@property (nonatomic) Camera camera;

@property (nonatomic) UserAssist visualCues;

@end



/*!
 * @typedef CaptureType
 * @brief  Current Capture type status.
 * @constant EYETHENTICATE.
 * @constant ENROL.
 * @constant EYEDENTIFY.
 * @constant CAPTURE_AVATAR.
 * @constant ALL.
 */

typedef NS_ENUM(NSUInteger, CaptureType) {
    EYETHENTICATE=1,
    ENROL=2,
    EYEDENTIFY=3,
    CAPTURE_AVATAR=4,
    ALL=5
};

@interface SDKManager : NSObject{
    
    Identity *identity;
    
    CaptureParameters *captureParameters;
    
}

@end


@interface Error : NSObject

@property int *QCErrorCode;
@property NSString *QCErrorMessage;
@property BOOL isDeviceStright;
@property int responseCode;
@property NSDictionary *responseArray;


@end



@protocol ResultBackDelegate <NSObject>

/*!
 
 @abstract resultActivity
 
 @discussion Sending the results details for Camera Activities.
 
 @return results - send the results code , captureType - send the captureType to decide the decision identity - get the user infromation
 
 */
- (void)resultActivity:(Result*)results captureType:(CaptureType)captureType identity:(Identity *)identity;
@end




@interface APIManager : NSObject{
    Result *results;
}

@property(nonatomic, retain) CaptureParameters *captureReturnParameters;

+ (instancetype)getInstance;


- (void) startPreview:(Identity *)identity;

- (void) stopPreview;

- (void) resume;

- (void) pause;

- (void) startEyethenticate :(Identity *)identity;

- (void) initialize :(void (^)(BOOL))handler;

- (void) setDeviceInfo :(void (^)(BOOL , NSMutableDictionary*))handler;

- (void) getDeviceInfo :(void (^)(BOOL , NSMutableDictionary*))handler;

- (void) getIdentity :(NSString *)uid completionHandler:(void (^)(BOOL, NSMutableDictionary*))handler;

- (void) setIdentity :(Identity *)identity completionHandler:(void (^)(BOOL, NSMutableDictionary*))handler;



- (void) initialize;


/*!
 
 @abstract checkConnectivity - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion Server Connection Check
 
 @return false if server is offline, true if server is online
 
 */
- (void) checkConnectivity :(void (^)(BOOL))handler;



/*!
 
 @abstract checkInternetConnectivity - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion Internet Connection Check
 
 @return false if internet is offline, true if internet is online
 
 */
- (void) checkInternetConnectivity:(void (^)(BOOL))handler;



/*!
 
 @abstract initializeLibrary - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion Init does the following: -  Load Model files -Check device authorization - Check internet and server connectivity
 
 @return true if initializeLibrary is successfully, false if initializeLibrary is failed. Result - error message return if device is UnAuthorized
 
 */

- (void) initializeLibrary :(void (^)(BOOL,Result*))handler;


/*!
 
 @abstract cameraPreview
 
 @discussion This method is used to intialize the camera preview
 
 @param viewController - self
 
 */

- (void) cameraPreview :(UIViewController *)viewController;


/*!
 
 @abstract libraryReady
 
 @discussion Function gives an indication weather the library is ready to be used
 
 @return true if library initialization is finished, false if it is still busy
 
 */
- (BOOL) libraryReady;


/*!
 
 @abstract checkIdentity - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion Check if identity exists in eyethenticate database
 
 @param identity - is the identity that you want to query
 
 @return false if the identity has not been found in eyethenticates database, true if the identity has been found in eyethenticates database
 
 */
- (void) checkIdentity:(Identity *)identity completionHandler:(void (^)(BOOL,Identity *))handler;


/*!
 
 @abstract startActivityForResult - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion Check if identity exists in eyethenticate database
 
 @param identity - is the identity that you want to query
 
 @param captureType - the name of the enum constant to be pass(EYETHENTICATE,ENROL,IDENTIFICATION).
 
 @param captureParameters - the name of the camera enum constant(CAMERA_FRONT/CAMERA_BACK), the name of the vibtation enum constant(VIBRATION_ON/VIBRATION_OFF) and the name of the voice event enum constant (VOICE_EVENT_ON/VOICE_EVENT_OFF),
 
 @return false if the identity has not been found in eyethenticates database, true if the identity has been found in eyethenticates database
 
 */
- (void) startActivityForResult:(UIViewController *)viewController identity:(Identity *)identity captureType:(CaptureType)captureType captureParameters:(CaptureParameters*)captureParameters completionHandler:(void (^)(BOOL))handler;

/*!
 
 @abstract getUserAvatar - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion Check if get User Avatar exists in eyethenticate database
 
 @param identity - is the identity that you want to query
 
 @return false if the user avatar has not been found in eyethenticates database, true if the user avatar  has been found in eyethenticates database
 
 */
- (void) getUserAvatar :(Identity *)identity completionHandler:(void (^)(BOOL, UIImage*))handler;


/*!
 
 @abstract uploadUserAvatar - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion Upload the User Avatar in eyethenticate database
 
 @param identity - is the identity that you want to query
 
 @return false if the user avatar upload failuer, true if the user avatar uploaded successfuly
 
 */
- (void) uploadUserAvatar :(Identity *)identity completionHandler:(void (^)(BOOL))handler;


/*!
 
 @abstract createCredentials - The completion handler to call when the load request is complete. This handler is executed on the delegate queue
 
 @discussion set client credentials details.
 
 @param credentials - is the credentials that you want to query
 
 @return true
 
 */

- (void) createCredentials :(Credentials *)credentials completionHandler:(void (^)(BOOL))handler;


@property id<ResultBackDelegate> errorDelegate;

@end

