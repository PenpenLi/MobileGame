--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
require("layermain.lua")

FileInfo =
{
   "loading.plist",
   "login.plist",
   "res_mj.plist",
   "res00.plist",
   "res01.plist",
   "res02.plist",
   "roomBG.plist",
   "scene.plist",       ---
   "loading.plist",
   "login.plist",
   "res_mj.plist",
   "res00.plist",
   "res01.plist",
   "res02.plist",
   "roomBG.plist",
   "scene.plist",
}

LoadingLayer ={
    TAG_Flag = 13,
}

function LoadingLayer:new(o)
	o = o or {}
	setmetatable(o,self)
	self.__index = self
	return o
end

function LoadingLayer:create()
    return CocostudioHelper.createNode(LoadingLayer,"loading.csb")
end

function LoadingLayer:onNodeLoaded()
end

function LoadingLayer:onEnter()
    print("onEnter")
    self.bg_panel = self._tg:getChildByTag(2)
    self._curAddCount = 0
end

function LoadingLayer:onEnterTransitionFinish()
   local listener = cc.EventListenerCustom:create("ImageLoadDone", function() self:onImageLoadDone() end)
    self._tg:getEventDispatcher():addEventListenerWithFixedPriority(listener,1)
    listener = cc.EventListenerCustom:create("OneImageLoaded", function() self:onOneImageLoaded() end)
	self._tg:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)

    self._progressbar = self.bg_panel:getChildByTag(12)
    self._moveflag = self.bg_panel:getChildByTag(13)    

    
    addimagesync:AddImageAsync(FileInfo)
end

function LoadingLayer:onExit()
    self._tg:getEventDispatcher():removeEventListenersForTarget(self._tg)
    if self._scheduler ~= nil then        
        cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self._scheduler)            
    end
end

function LoadingLayer:onImageLoadDone()
    logOut("开始进入首界面")
    SceneManager:run(LayerMain)
end

--加载资源
function LoadingLayer:onOneImageLoaded()
    self._curAddCount = self._curAddCount +1
    if self._curAddCount <= #FileInfo then
        cc.SpriteFrameCache:getInstance():addSpriteFrames(FileInfo[self._curAddCount])
        local lPercent =self._curAddCount / #FileInfo *100
        self._progressbar:setPercent(lPercent)
        local posX = self._moveflag:getPositionX()+self._progressbar:getContentSize().width /#FileInfo
        self._moveflag:setPositionX(posX)
    end
end
--endregion
