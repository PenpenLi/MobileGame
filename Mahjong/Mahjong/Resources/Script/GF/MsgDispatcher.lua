--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
MsgDispatcher={}
function MsgDispatcher:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
   -- cc.Director:getInstance():getScheduler():scheduleScriptFunc(function(dt) self:onSchedule(dt) end, 0.05, false)
    return o
end

function MsgDispatcher:onSchedule(dt)
    local msgbuf=gameFrame:getMsgWithDispatchMsg()
    local _msg = json.decode(msgbuf)
    print("...hcb:".._msg)
end

function MsgDispatcher:playerPersonInfo(msg)
    gameData:setPlayerRigstInfo(msg)
end

function MsgDispatcher:createRoomInfo(msg)
    gameData:setCreateRoomInfo(msg)
end
--endregion
