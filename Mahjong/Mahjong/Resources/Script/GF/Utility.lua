local targetPlatform = cc.Application:getInstance():getTargetPlatform()
TargetPlatform = 
{
	UNKNOWN = 0,
	IOS = 1,
	ANDROID = 2,
	WIN32 = 3,
}

-- cclog
cclog = function(...)
    print(string.format(...))
end

debugstack = false


function trace()
	if (debugstack) then
		return debug.traceback()
	else
		return ""
	end
end

function log(t)
	--if(Environment.isDebug()) then
		if(type(t) == "string" or type(t) == "number") then
			logOut(trace().."\n\t"..t)
        elseif type(t) == "table" then
            logOut(trace().."\n\t"..tostringt(t))
		else
			logOut(trace().."\n\t"..tostring(t))
		end
	--end
end

function logOut(str)
	if(luajava == nil) then
		print(str)
	else
		local logcat = luajava.bindClass("android.util.Log")
		logcat:d("[Lua]", str)
	end 
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
end

Utility =
{
     createSprite = function(resName)
        return cc.Sprite:create(resName)
    end;


    createCsb = function (resName)
        return cc.CSLoader:createNode(resName)
    end;


    callFunc = function(obj, tag, funcs)
		    local func = funcs[tag]
		    if(func ~= nil) then
			    func(obj, tag)
		    end
	end;

    getWidget = function(aLayer, aTag)
        return ccui.Helper:seekWidgetByTag(aLayer._root, aTag)   
	end;

    getTargetPlatform = function()
        return targetPlatform
    end;

    getPlatformIOS = function()
        return cc.PLATFORM_OS_IPHONE
    end;

    getPlatformMac = function()
        return cc.PLATFORM_OS_MAC
    end;

    getPlatformWin = function()
        return cc.PLATFORM_OS_WINDOWS
    end;

    getPlatformAndroid = function()
        return cc.PLATFORM_OS_ANDROID
    end;


}

function getPlatForm()
--    if _platform == TargetPlatForm.IOS then
--        return "/mnt/sdcard/qp.game.cache/ios/"
--    elseif _platform == TargetPlatForm.ANDROID then
--        return "/mnt/sdcard/qp.game.cache/android/"
--    elseif _platform == TargetPlatForm.WIN32 then
--        return "f://mnt//qp.game.cache//win32//"
--    end  
    local path = addimagesync:getAccountPath()    
    logOut("存储路径是"..path)
    return path
end