--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
GameData=
{
    _userInfo ={_userName = nil, _userPassWord = nil, _userMoney= 0, _roleUID = nil }, --注册信息
    _createRoomInfo,    --创建房间信息
    _playersInfo=
    {
        roomName={},
        playerInfo={{},{},{},{}}
    }, --玩家用户信息
}

function GameData:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    return o
end

---用户注册信息begin---
function GameData:setPlayerRigstInfo(msg)
    self._userInfo = msg
    --这个地方服务器发过来的有问题
    self:setPlayerName(self._userInfo.PlayerData.RoleData.PlayerName)       --
    self:setPlayerMoney(self._userInfo.PlayerData.RoleData.PlayerMoney)
    self:setPlayerUID(self._userInfo.PlayerData.RoleData.PlayerRoleUID)
end

function GameData:setPlayerName(msg)
    self._userInfo._userName = msg
end

function GameData:getPlayerName()
    if self._userInfo ~= nil and self._userInfo._userName~= nil then
        return self._userInfo._userName
    else
        return ""
    end
end

function GameData:setPlayerPassWord(msg)
    self._userInfo._userPassWord = msg
end

function GameData:getPlayerPassWord(msg)
    if self._userInfo ~= nil and self._userInfo._userPassWord then
        return self._userInfo._userPassWord
    end
    return ""
end

function GameData:setPlayerMoney(msg)
    self._userInfo._userMoney = msg
end

function GameData:getPlayerMoney()
    if self._userInfo ~= nil and self._userInfo._userMoney~= 0 then
        return self._userInfo._userMoney
    else
        return 0
    end
end

--角色id
function GameData:setPlayerUID(msg)
    self._userInfo._roleUID = msg
end

function GameData:getPlayerUID()
    if self._userInfo ~= nil and self._userInfo._roleUID~= nil then
        return self._userInfo._roleUID
    end
end
---用户注册信息end---


----创建房间时玩家用户信息begin------
function GameData:setCreateRoomInfo(msg)
--msg = {IsSucc=true Protocol2=18 RoomData={} Protocol=3 }
--RoomData_1 = {RoomMsg="【此房间为测试房间】  欢迎来到长波的四川麻将房间！！！" PlayerData={} RoomID="1" RoomPic="/res/upload/over.png" RoomPassWD="" }
    self._createRoomInfo = msg

    print("..........................................TEST")
    self._room = msg.RoomData_1.PlayerData
    for v,k in pairs(self._room) do
        print("....name:=="..v)
        print("....value=="..k.PlayerName)
    end
    print("...........................................")
end

--function GameData:getCreateRoomInfo()
--    return self._createRoomInfo.RoomID
--end

function GameData:getRoomName()
     return self._createRoomInfo.RoomData_1.RoomMsg
end


function GameData:getPlayerInfo()
--    for i,v in ipairs(self._createRoomInfo.RoomData[1]PlayerData) do
--        _playersInfo.playerInfo[i] = v
--    end
end


----创建房间时玩家用户信息end--------
--endregion
