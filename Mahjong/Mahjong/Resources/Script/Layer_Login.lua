--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
CLoginLayer={
    tag_enter = 24,
    tag_fastRegister = 25,
    tag_TextField_Username = 22,
    tag_TextField_Password = 23,        --这个值在做界面的时候有重复
    TAG_BTN_CLOSE = 41,      --返回
}

function CLoginLayer:new(o)
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    return o
end

function CLoginLayer:create()
    return CocostudioHelper.createNode(CLoginLayer,"LoginLayer.csb")
end

function CLoginLayer:onNodeLoaded()
    local tags=
    {
        self.tag_enter,
        self.tag_fastRegister,
        self.TAG_BTN_CLOSE
    }
    CocostudioHelper.regBtnEvn(self,tags)
end

function CLoginLayer:onEnter()
    self.bg_panel = self._tg:getChildByTag(2)
    

    self._userName = self.bg_panel:getChildByTag(self.tag_TextField_Username)
    --self._userName:setPasswordEnabled(true)
    self._password = self.bg_panel:getChildByName("TextField_passward")
    self._password:setPasswordEnabled(true) 
end

function  CLoginLayer:onEnterTransitionFinish()
     local listener = cc.EventListenerCustom:create("RegisterSucess", function() self:onRegisterSucess() end)
	self._tg:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)

--    local msg={},flag
--     flag , msg._userName , msg._userPassWd = self:checkUserInfo()
--     gameData:setPlayerName(msg._userName)
--     gameData:setPlayerPassWord(msg._userPassWd)
--    if flag then
--        session:sendLogin(msg)
--    end
end

function CLoginLayer:onExit()
    logOut("onexit")
    self._tg:getEventDispatcher():removeEventListenersForTarget(self._tg)
end


function CLoginLayer:onPressEnded(sender)
    local action = 
    {
        [self.tag_enter] = self.onBtnEnter,
        [self.tag_fastRegister] = self.onBtnFasteregister,
        [self.TAG_BTN_CLOSE] = self.onBtnClose
    }
    Utility.callFunc(self,sender:getTag(), action)
end


function CLoginLayer:onBtnEnter()
   
end
function CLoginLayer:onBtnFasteregister()
    local msg={}
    msg._userName , msg._userPassWd = self:checkUserInfo()
    session:sendRegisterInfo(msg)
end

function CLoginLayer:onBtnClose()
    sceneManager:close(self)
end
function CLoginLayer:onPressCanceled(sender)
     
end

function CLoginLayer:checkUserInfo()
    local account = self._userName:getString()
    local password = self._password:getString()
    logOut("用户名，密码分别是:"..account..";"..password)
    if account~=nil and password~=nil then
        return true,account,password
    else
        return false
    end
end


function CLoginLayer:onRegisterSucess()
    print("注册成功1")
    print("注册成功")
    local flag, account, password =  self:checkUserInfo()
    if flag then
        gameData:setPlayerName(account)
        gameData:setPlayerPassWord(password)
        AccountManager:setCurrentAccount()
    end
    SceneManager:close(self)
end
--endregion
