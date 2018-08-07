print("wsk")

local function main()

    local function createLayerFarm()
        local layerFarm = cc.Layer:create()
        local visibleSize = cc.Director:getInstance():getVisibleSize()
        local origin = cc.Director:getInstance():getVisibleOrigin()
        local bg = cc.Sprite:create("bg_blue.jpg")
        bg:setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2)
        layerFarm:addChild(bg)
        return layerFarm
    end

    -- run
    local sceneGame = cc.Scene:create()
    sceneGame:addChild(createLayerFarm())
    cc.Director:getInstance():runWithScene(sceneGame)

end









xpcall(main, __G__TRACKBACK__)