--region *.lua
--Date
--此文件由[BabeLua]插件自动生成

Session={}
function Session:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    return o
end

--注册
function Session:sendRegisterInfo(args)
    msg = 
    {
        Protocol = GameProto.Game_Proto,
        Protocol2 = GameProto[GameProto.Game_Proto].C2CHS_UserRegister_Proto,
        StrLoginName = args._userName,     --"hecang123",
        StrLoginPassWd = args._userPassWd,
        StrMobile = "123456789",
        RoleUID = 123456,
    }
    gameFrame:sendMsgWithOutCheckSession(json.encode(msg))
end

--登录
function Session:sendLogin(args)
    msg =
    {
        Protocol = GameProto.Game_Proto,
        Protocol2 = GameProto[GameProto.Game_Proto].C2CHS_UserLogin_Proto,
        StrLoginName = args._userName,
        StrLoginPassWd = args._userPassWd,
    }
    gameFrame:sendMsgWithOutCheckSession(json.encode(msg))
end

--创建房间
function Session:sendCreateRoom(msg)
    msg =
    {
        Protocol = GameProto.Game_Proto,
        Protocol2 = GameProto[GameProto.Game_Proto].C2CHS_CreatRoom_Proto,
        RoleUID = msg._roleUID, -- gameData:getPlayerUID(),    he123,123456,roleuid:124
        PassWD = msg._userPassWd,
    }
    gameFrame:sendMsgWithOutCheckSession(json.encode(msg))
end

--endregion
