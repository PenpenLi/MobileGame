#include "AppDelegate.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "audio/include/SimpleAudioEngine.h"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/lua_module_register.h"

#include "scripting/lua-bindings/auto/lua_MyClass_auto.hpp"
#include "scripting/lua-bindings/auto/lua_Manual_ImageLoader.hpp"
#include "scripting/lua-bindings/auto/lua_GameFrame_auto.hpp"
#include "scripting/lua-bindings/auto/lua_GameFramePlatform_auto.hpp"
#include "scripting/lua-bindings/auto/lua_UpdateService_auto.hpp"
#include "f:/Code/MobileGame/Mahjong/GameFrame/proj.win32/UpdateService.h"
using namespace CocosDenshion;

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();

#if (COCOS2D_DEBUG > 0) && (CC_CODE_IDE_DEBUG_SUPPORT > 0)
    // NOTE:Please don't remove this call if you want to debug with Cocos Code IDE
    RuntimeEngine::getInstance()->end();
#endif

}

// if you want a different context, modify the value of glContextAttrs
// it will affect all platforms
void AppDelegate::initGLContextAttrs()
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// if you want to use the package manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // set default FPS
    Director::getInstance()->setAnimationInterval(1.0 / 60.0f);

    // register lua module
    auto engine = LuaEngine::getInstance();
    ScriptEngineManager::getInstance()->setScriptEngine(engine);
    lua_State* L = engine->getLuaStack()->getLuaState();
    lua_module_register(L);

    register_all_packages();


	L = engine->getLuaStack()->getLuaState();
	register_all_MyClass(L);
	L = engine->getLuaStack()->getLuaState();
	register_all_ImageLoader(L);	
	L = engine->getLuaStack()->getLuaState();
	register_all_NetSession(L);
	L = engine->getLuaStack()->getLuaState();
	register_all_GameFramePlatform(L);
	L = engine->getLuaStack()->getLuaState();
	register_all_UpdateService(L);
    LuaStack* stack = engine->getLuaStack();
    stack->setXXTEAKeyAndSign("2dxLua", strlen("2dxLua"), "XXTEA", strlen("XXTEA"));

    //register custom function
    //LuaStack* stack = engine->getLuaStack();
    //register_custom_function(stack->getLuaState());
	vector<string> searchPath;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	searchPath.push_back(".");
	searchPath.push_back("Resources");
	searchPath.push_back("Resources/Script");
	searchPath.push_back("Resources/res");
	searchPath.push_back("Resources/csb");
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID or CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	std::string lPath = CCFileUtils::sharedFileUtils()->getWritablePath();
	searchPath.push_back(lPath + "assets");
	searchPath.push_back(lPath + "assets/Script");
	searchPath.push_back("Resources/res");
#endif
	FileUtils::getInstance()->setSearchPaths(searchPath);
    if (engine->executeScriptFile("game.lua"))  //src/main.lua
    {
        return false;
    }

    return true;
}

// This function will be called when the app is inactive. Note, when receiving a phone call it is invoked.
void AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();

    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();

    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
