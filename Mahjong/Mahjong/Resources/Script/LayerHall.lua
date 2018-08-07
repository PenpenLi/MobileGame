--region *.lua
--Date
--此文件由[BabeLua]插件自动生成

--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
LayerHall={
    TAG_BTN_ROOM1 = 36,
    TAG_BTN_RETURN = 46,
    TAG_BTN_START = 31,     --开始游戏
}

function LayerHall:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    return o
end

function LayerHall:create()
    return CocostudioHelper.createNode(LayerHall,"HallLayer.csb")
end

function LayerHall:onNodeLoaded()
   local roomNameStr = gameData:getRoomName()
   local roomNameBtn = self._tg:getChildByName("bg_panel"):getChildByName("room1")
   roomNameBtn:setTitleText(roomNameStr)
end

function LayerHall:onEnter()
    local tags=
    {
        self.TAG_BTN_ROOM1,
        self.TAG_BTN_RETURN,
        self.TAG_BTN_START,
    }
    CocostudioHelper.regBtnEvn(self,tags)
end

function  LayerHall:onEnterTransitionFinish()
   

   print(">>>>>>>>>>>>>")
end

function LayerHall:onExit()
     notificationCenter:unregisterAll(self)
end

function LayerHall:onTouchBegan(posX,posY)

end

function LayerHall:onTouchMoved(posX,posY)

end

function LayerHall:onTouchEnded(posX, pos)
end

function LayerHall:onPressEnded(sender)
    local action = 
    {
        [self.TAG_BTN_ROOM1] = self.onBtnRoom1,
        [self.TAG_BTN_RETURN] = self.onBtnReturn,
        [self.TAG_BTN_START] = self.onBtnGameStart
    }
    Utility.callFunc(self,sender:getTag(), action)
end

function LayerHall:onBtnReturn(sender)
    sceneManager:close(self)
end

function LayerHall:onBtnRoom1()
    print("房间1")
    print("房间1")
end

function LayerHall:onBtnGameStart(sender)
    sceneManager:run(LayerGame)
end
--endregion

