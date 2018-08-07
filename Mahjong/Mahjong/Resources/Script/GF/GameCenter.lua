--region *.lua
--Date
--此文件由[BabeLua]插件自动生成
GameCenter=
{
    names=
    {
        mahjong = "Mahjong"
    },

    curGameName = "unKnow",

    invokeGame = function(name)
        for k,v in pairs(GameCenter.names) do
            if v == name then
                GameCenter.curGameName = name
                return
            end
        end
    end;

    getCurrentGameName = function()
        return GameCenter.curGameName
    end

}

--endregion
