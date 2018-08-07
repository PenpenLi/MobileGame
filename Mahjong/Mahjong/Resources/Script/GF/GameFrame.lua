--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
require("GF/Session.lua")
function dispatchCustomEvent(msg)
    cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent(msg)
end

TargetPlatForm=
{
    UNKNOWN = 0,
	IOS = 1,
	ANDROID =2,
	WIN32 = 3,
}


GameFrame={}
session = Session:new()

function GameFrame:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self    
    self._gameFrame = my.NetSession:new()
    local listener = cc.EventListenerCustom:create("DispatchMsg", function() self:getMsgWithDispatchMsg() end)
    cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(listener,1)
    return o
end


function GameFrame:sendMsgWithOutCheckSession(msg)
    
   self._gameFrame:post(msg)
end

function GameFrame:getMsgWithDispatchMsg()
    local _msg = self._gameFrame:GetDispatchMessage()
    local msg = json.decode(_msg,0)
    --msg = {IIsSucc=false Protocol2=8 PlayerData={} Protocol=3 PlayerUID="-1" }
    --PlayerData = {PlayerExp=0 PlayerAccountID=0 PlayerSex=0 PlayerWeaponPic="" PlayerName="" PlayerPayMoney=0 PlayerRoleUID=0 PlayerMoney=0 PlayerLev=0 PlayerVIPLev=0 PlayerPayMoney2=0 PlayerWeaponID=0 PlayerHeadUrl="" }
    self._proto1 = msg.Protocol
    self._protol2 =msg.Protocol2
    print("主协议:"..self._proto1 .. ";         次协议:"..self._protol2)

--    --主协议3
    if GameProto.Game_Proto == self._proto1 then
        
            self:userInfoMsg(msg)
    --    end
    --elseif  == self._proto1 then
        print("...........")
    end

--    --参照BUYV的onMessage
--    local action =
--    {

--    }

end

function GameFrame:userInfoMsg(msg)
    local secondPro = msg.Protocol2
    print("次协议为："..secondPro)
    if GameProto[GameProto.Game_Proto].CHS2C_UserRegister_Proto == secondPro then
        print(msg.PlayerData.PlayerAccountID)
        
        if msg.IIsSucc == true then
            msgdispatcher:playerPersonInfo(msg)
            --注册成功
            cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent("RegisterSucess")
        end
    elseif GameProto[GameProto.Game_Proto].CHS2C_UserLogin_Proto == secondPro then
        --登录
--        if msg.IIsSucc == true then
            msgdispatcher:playerPersonInfo(msg)
            --dispatchCustomEvent(MessageTags.LoginResponse)
            notificationCenter:post(MessageTags.LoginResponse, msg.IIsSucc)
--        else
--            cc.Director:getInstance():getEventDispatcher():dispatchCustomEvent("RegisterError")
--        end
    elseif GameProto[GameProto.Game_Proto].CHS2C_CreatRoom_Proto == secondPro then
        --{"Protocol":3,"Protocol2":18,"IsSucc":true,"RoomID":"1"}
        --创建房间成功
        if msg.IsSucc == true then
            msgdispatcher:createRoomInfo(msg.RoomData)
            notificationCenter:post(MessageTags.CreateRoom)
        end
    end
end
--endregion
