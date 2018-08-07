print("....Mahjong")
----require("test.lua")
require("LoadingLayer.lua")
require("Info.lua")

sceneManager = SceneManager:new()
notificationCenter = LuaNotificationCenter:new()

local function main()
    cc.SpriteFrameCache:getInstance():addSpriteFrames("loading.plist")
    local test = my.MyClass:create()
    test:SetFoo(21.5)
    local num = test:GetFoo()
    logOut(".....num=".. num)

    print("....startGameBegin")
   -- Update:new()
    require("GF/Update.lua")
    print("....startGameEnd")

    --SceneManager:run(LoadingLayer)
    --[[
    --加载图片
    local function createPng()
        local layerFarm = cc.Layer:create()
        local visibleSize = cc.Director:getInstance():getVisibleSize()
        local origin = cc.Director:getInstance():getVisibleOrigin()
        local bg = createSprite("bg_blue.jpg")
        bg:setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2)
        layerFarm:addChild(bg)
        return layerFarm
    end

    --加载界面csb,plist
    local function createLayerFarmFarm()
        --local uiLayerout = GUIReader::shareReader():widgetFromJsonFile("")
        cc.SpriteFrameCache:getInstance():addSpriteFrames("loading.plist")
        --local uiLayerout = cc.CSLoader:createNode("loading.csb")
        return createCsb("loading.csb")
    end
    -- run
    if(false) then    
        local sceneGame = cc.Scene:create()
        sceneGame:addChild(createLayerFarmFarm())
        sceneGame:addChild(LoadingLayer())
        if cc.Director:getInstance():getRunningScene() then
            cc.Director:getInstance():replaceScene(sceneGame)
        else
            cc.Director:getInstance():runWithScene(sceneGame)
        end
    else
         cc.SpriteFrameCache:getInstance():addSpriteFrames("loading.plist")
         SceneManager:run(LoadingLayer)
    end
    ]]
end

xpcall(main, __G__TRACKBACK__)