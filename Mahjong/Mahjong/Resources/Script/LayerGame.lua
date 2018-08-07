--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
LayerGame=
{
    TAG_BTN_RETURN = 12,
}

function LayerGame:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    return o
end

function LayerGame:create()
    return CocostudioHelper.createNode(LayerGame,"MjGameLayer.csb")
end

function LayerGame:onNodeLoaded()
end

function LayerGame:onEnter()
    local tags=
    {
        self.TAG_BTN_RETURN,
    }
    CocostudioHelper.regBtnEvn(self,tags)
end

function  LayerGame:onEnterTransitionFinish()
   
end

function LayerGame:onExit()
     
end

function LayerGame:onPressEnded(sender)
    local action = 
    {
        [self.TAG_BTN_RETURN] = self.onBtnReturn
    }
    Utility.callFunc(self,sender:getTag(), action)
end

function LayerGame:onBtnReturn()
    sceneManager:close(self)
end


--endregion
