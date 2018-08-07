--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
require("Info.lua")
require("GF/TimerManager.lua")
local updateWatingTime = 4
Update =
{
    _currentVersion =
    {
        GameHotFixVersion = 4,
        GameBigVersion = 2
    }
}
function Update:new()
    o = o or {}
    setmetatable(o,self)
    self.__index = self
    self._updater = my.UpdateService:create()
    self:checkVersionFile()
    self:loadVersion()
    return o;
end

--检查当前版本号，没有，就把当前lua文件中的大小版本号写入文件
function  Update:checkVersionFile()
    local fl = io.open(Config.getUpdateInfo().VerFile,"r")
    if f1 == nil then
        self:writeVersion()
    else
        fl:close()
    end
end

function Update:writeVersion()
    local wfile = io.open(Config.getUpdateInfo().VerFile,"w")
    if wfile ~= nil then
        wfile:write(json.encode(self._currentVersion))
        wfile:close()
    end
end

--获得当前的小版本号
function Update:getCurHotFixVersion()
    if self._currentVersion and self._currentVersion.GameHotFixVersion then
        return self._currentVersion.GameHotFixVersion
    else
        return 0
    end
end

-- 获得当前的大版本号
function Update:getCurBigVersion()
    if self._currentVersion and self._currentVersion.GameBigVersion then
        return self._currentVersion.GameBigVersion
    else
        return 0
    end
end

function Update:loadVersion()
    local rfile = io.open(Config.getUpdateInfo().VerFile,"r")
    log(Config.getUpdateInfo().VerFile)

    if(rfile ~= nil) then
        local str = rfile:read("*a")
        self._preVersion = json.decode(str)

        local delete = function()
            local writableDir = cc.FileUtils:getInstance():getWritablePath()
            local bOk = os.rmdir(writableDir)
            if bOk then
                logOut("delete dir:"..writableDir.." success!")
                self:writeVersion()
            end
        end

        if(luajava ~= nil) then
            local version = self._currentVersion.versionCode or 0
            local javaApp = luajava.bindClass("com.qpgame.gameframe.GameFrame")
            local infos = javaApp:getAppInfo()
            if infos then
                if tonumber(infos.versionCode) > version then
                    self._currentVersion.versionCode = tonumber(infos.versionCode)
                    delete()
                end
            end

            --local lBigVerion = javaApp:getGameBigVersion()
            self._currentVersion.GameBigVersion = tonumber(infos.versionCode)
            self:writeVersion()
        end
        if Utility.getTargetPlatform() == TargetPlatform.IOS then
            require( "GF/GameFrame.lua" )
            local version = self._currentVersion.versionCode or 0
            local args = {class = "PlatformHelper", func = "getAppBuildCode"}
            local ok, ret = luaoc.callStaticMethod("LuaocDispatcher","dispatchCall",args)
            if ok and ret then
                logOut("ret.version:"..ret.version)
                logOut("version:"..version)
                self._currentVersion.GameBigVersion = tonumber(ret.version)
                if tonumber(ret.version) > tonumber(version) then
                    self._currentVersion.versionCode = tonumber(ret.version)
                    delete()
                end
            end
        end
        rfile:close()
    end

end

function Update:StartGame()
    log("this is Update::StartGame")    
    TimerManager:removeAll()
    --self._updater:exit()

    log("StartGame begin")
    sceneManager:run(LoadingLayer)
    log("StartGame end")
end

function Update:start()
    logOut("this is Update::start")
    local lPlatform = Utility.getTargetPlatform()    
    print("....当前的平台是:"..lPlatform)
    local gameid = Info.GameId
    local UpdateInfo = json.encode(Config.getUpdateInfo())
    self._updater:Start(UpdateInfo,11,gameid,4,Config.getUpdateInfo().WaitTime,lPlatform,
        function(event,result, value,flag, bigver,size) self:onUpdate(event,result, value,flag, bigver,size) end)
    self._updatedCount = 0
    --self._updater:checkVersion()
    self._checkScheduler = cc.Director:getInstance():getScheduler():scheduleScriptFunc(function() self:onCheckVersion(false,0,0,0,0) end,updateWatingTime, false)
end


function Update:onUpdate(event,result, value,flag, bigver,size)
    local action = 
    {
        ["CheckVersion"] = Update.onCheckVersion,
        ["CheckDownload"] = Update.onCheckDownload,
        ["DownloadFile"] = Update.onDownloadFile,
        ["DownloadFullVersionResult"] = Update.onDownloadFullVersion,
    }
    local func = action[event]
    if func~= nil then
        func(self, result, value,flag, bigver,size)
    end
end

--检查版本并提示升级或是开始游戏
function Update:onCheckVersion(result, value,flag, bigver,size)
    --如果是回Start的回调，就进行更新检测，如果是Scheduler,就直接开始游戏
    cc.Director:getInstance():getScheduler():unscheduleScriptEntry(self._checkScheduler)
    local lStartGame = true
   
    if result then
        if bigver> self:getCurBigVersion() then
            lStartGame = false
            self._newBigver = bigver
            --提示升级
            --self._layer:dectedNewVersionFull(size)
        elseif value ~= self:getCurHotFixVersion() then
            lStartGame = false
            self._newHotFixVer = value
            --self:checkDownload()
        end
    end

    if lStartGame then
        self:StartGame()
    end
end


function Update:checkDownload()
    self._updater:checkDownload(self._newHotFixVer)
end


GameCenter.invokeGame("Mahjong")
local update = Update:new()

--更新检测
Update:start()
--直接开始游戏
--Update:StartGame()
--endregion
