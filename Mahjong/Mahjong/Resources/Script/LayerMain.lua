--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
require("Layer_Login.lua")
require("LayerHall.lua")
require("LayerGame.lua")
LayerMain=
{
    TAG_BTN_FASTSTARTGAME = 11,  --快速开始
    TAG_BTN_Hall = 12,      --大厅
    TAG_BTN_SWITCHACCOUNT = 13
}

function LayerMain:new(o)
	o = o or {} 
	setmetatable(o,self)
	self.__index = self
	return o
end


function  LayerMain:create()
    print("............")
    return CocostudioHelper.createNode(LayerMain,"mainmenu.csb")
end

function LayerMain:onNodeLoaded(args)
    local tags=
    {
        self.TAG_BTN_FASTSTARTGAME,
        self.TAG_BTN_Hall,
        self.TAG_BTN_SWITCHACCOUNT
    }

    CocostudioHelper.regBtnEvn(self,tags)
end

function LayerMain:onEnter()
    notificationCenter:register(self, self.onLoginResp, MessageTags.LoginResponse)
    notificationCenter:register(self, self.onCreateRoomResp, MessageTags.CreateRoom)
end

function LayerMain:onEnterTransitionFinish()
--    local listener = cc.EventListenerCustom:create("CreateRoomSucess", function() self:onCreateRoomSucess() end)
--    self._tg:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)
--    listener = cc.EventListenerCustom:create(MessageTags.LoginResponse,function() self:onLoginResp() end) -- 
--    self._tg:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)    
--    listener = cc.EventListenerCustom:create("RegisterError", function() self:onRegisterError() end)
--    self._tg:getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)
    local savePath = getPlatForm()
    addimagesync:setAcccountPath(savePath)
    local rigesterInfo = addimagesync:ReadAccountInfo()
    local accountInfo = nil
    if rigesterInfo~="" then
        accountInfo = json.decode(rigesterInfo,0)
        local msg={},flag
        msg._userName , msg._userPassWd = accountInfo.AccountName, accountInfo.PassWords
        session:sendLogin(msg)
    else
        self:onBtnSwitchAccount()
    end
end

function LayerMain:onExit()   
    notificationCenter:unregisterAll(self)
end

function LayerMain:onTouchBegan(posX,posY)

end

function LayerMain:onTouchMoved(posX,posY)

end

function LayerMain:onTouchEnded(posX, pos)
   
end

function LayerMain:onPressEnded(sender)     
    local action=
    {
        [self.TAG_BTN_FASTSTARTGAME] = self.onBtnFastStartGame,
        [self.TAG_BTN_Hall] = self.onBtnHall,
        [self.TAG_BTN_SWITCHACCOUNT] = self.onBtnSwitchAccount,
    }
    Utility.callFunc(self, sender:getTag(), action)
end

--快速开始
function LayerMain:onBtnFastStartGame(sender)
    sceneManager:run(LayerHall)
end

--进房间
function LayerMain:onBtnHall()
    local msg={}
    msg._roleUID = gameData:getPlayerUID()
    msg._userPassWd = ""
    Session:sendCreateRoom(msg)
end
--切换登录用户名
function LayerMain:onBtnSwitchAccount()
    SceneManager:run(CLoginLayer)
end

--自动登录成功，显示用户信息，失败切换到用户注册界面
function LayerMain:onLoginResp(status)
    if status == true then
        self.bg_panel = self._tg:getChildByName("bg_panel")
        self._PlayerName = self.bg_panel:getChildByName("board"):getChildByName("name")
        local _playname = gameData:getPlayerName()
        self._PlayerName:setString(gameData:getPlayerName())
        self._PlayerMoney = self.bg_panel:getChildByName("board"):getChildByName("money")
        local _playMoney = gameData:getPlayerMoney()
        self._PlayerMoney:setString(gameData:getPlayerMoney()) 
    else
        self:onBtnSwitchAccount()
    end
end


function LayerMain:onCreateRoomResp()
    sceneManager:run(LayerHall)
end
--endregion
