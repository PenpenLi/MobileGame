ResolutionPolicy = 
{
    -- The entire application is visible in the specified area without trying to preserve the original aspect ratio.
    -- Distortion can occur, and the application may appear stretched or compressed.
    kResolutionExactFit = 0,
    -- The entire application fills the specified area, without distortion but possibly with some cropping,
    -- while maintaining the original aspect ratio of the application.
    kResolutionNoBorder = 1,
    -- The entire application is visible in the specified area without distortion while maintaining the original
    -- aspect ratio of the application. Borders can appear on two sides of the application.
    kResolutionShowAll = 2,
    -- The application takes the height of the design resolution size and modifies the width of the internal
    -- canvas so that it fits the aspect ratio of the device
    -- no distortion will occur however you must make sure your application works on different
    -- aspect ratios
    kResolutionFixedHeight = 3,
    -- The application takes the width of the design resolution size and modifies the height of the internal
    -- canvas so that it fits the aspect ratio of the device
    -- no distortion will occur however you must make sure your application works on different
    -- aspect ratios
    kResolutionFixedWidth = 4,

    kResolutionUnKnown = 5,
};

Orientation = 
{
    Landscape = 1,
    Portrait = 2,
}

LayoutType = 
{
	Zoom = 1,
	FitScreen = 2,
	Auto = 3,
}

LayoutHelper = 
{
	_isExactFit = false,
	_size = nil,
	_config = nil,
	_layoutType = LayoutType.Zoom,
}

function LayoutHelper:new(o)  
	o = o or {}  
	setmetatable(o,self)  
	self.__index = self
	return o  
end  
  
function LayoutHelper:shareInstance()  
	if self.instance == nil then  
		self.instance = self:new()  
	end  
	return self.instance  
end

function LayoutHelper:setLayoutType(layoutType)
	self._layoutType = layoutType
end

function LayoutHelper:autoSetLayoutType(width, height)
    local viewSize = cc.Director:getInstance():getOpenGLView():getFrameSize()
    if(viewSize.width > width or viewSize.height > height) then
        self._layoutType = LayoutType.Zoom
    elseif (viewSize.width < width or viewSize.height < height) then
        self._layoutType = LayoutType.FitScreen
    else
        self._layoutType = LayoutType.Auto
    end
end

function LayoutHelper:setLayoutInfo(size, config)
--	if(Utility.getTargetPlatform() == TargetPlatform.WIN32) then
--		GameFrameLua.SetFrameSize(size.width, size.height)
--	end

	self._size = size
	self._config = config
	if(self._layoutType == LayoutType.FitScreen) then
		local viewSize = cc.Director:getInstance():getOpenGLView():getFrameSize()
		if(viewSize.width < size.width or viewSize.height < size.height) then
			cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(size.width, size.height, ResolutionPolicy.kResolutionExactFit)
			self._isExactFit = true
		end
	elseif(self._layoutType == LayoutType.Zoom) then
		if(self._config.noExactFit) then
            if(self._config.orientation == Orientation.Landscape) then
		        cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(size.width, size.height, ResolutionPolicy.kResolutionFixedHeight)
            else
                cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(size.width, size.height, ResolutionPolicy.kResolutionFixedWidth)
            end
	    else
		    cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(size.width, size.height, ResolutionPolicy.kResolutionExactFit)
			--cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(size.width, size.height, ResolutionPolicy.kResolutionShowAll)
			self._isExactFit = true
        end
	end
end

function LayoutHelper:setAutoLayoutInfo(size, designSize, config)
	if(Utility.getTargetPlatform() == TargetPlatform.WIN32) then
		GameFrameLua.SetFrameSize(size.width, size.height)
	end

	self._size = designSize
	self._config = config
	if(self._layoutType == LayoutType.FitScreen) then
		local viewSize = cc.Director:getInstance():getOpenGLView():getFrameSize()
		if(viewSize.width < size.width or viewSize.height < size.height) then
			cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy.kResolutionExactFit)
			self._isExactFit = true
		end
	elseif(self._layoutType == LayoutType.Zoom) then
		if(self._config.noExactFit) then
            if(self._config.orientation == Orientation.Landscape) then
		        cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy.kResolutionFixedHeight)
            else
                cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy.kResolutionFixedWidth)
            end
	    else
		    cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy.kResolutionExactFit)
			self._isExactFit = true
        end
	end
end

function LayoutHelper:AdjustBackground(tg)
	if(not self._isExactFit and self._layoutType == LayoutType.FitScreen) then
		local bg = tg:getWidgetByName("bg")
		if(bg ~= nil) then
			local viewSize = cc.Director:getInstance():getOpenGLView():getFrameSize()
			local width = viewSize.width / self._size.width
			local height = viewSize.height / self._size.height
			if(width > height) then
				bg:setScale(width)
			else
				bg:setScale(height)
			end
		end
	end
end

function LayoutHelper:layout(layer)
	if(self._layoutType == LayoutType.FitScreen or self._layoutType == LayoutType.Auto) then
	else
		if(self._config.orientation == Orientation.Landscape) then
			layer:setPositionX(self:getOffset() / 2)
		else
			layer:setPositionY(self:getOffset() / 2)
		end
	end
end

function LayoutHelper:getOffset()
    local offset = 0
    if(self._config.noExactFit and self._layoutType == LayoutType.Zoom) then
        local lViewSize = cc.Director:getInstance():getOpenGLView():getFrameSize()

        if(self._config.orientation == Orientation.Landscape) then
            offset = (lViewSize.width - (cc.Director:getInstance():getOpenGLView():getScaleX() * size.width)) / cc.Director:getInstance():getOpenGLView():getScaleX()
        else
            offset = (lViewSize.height - (cc.Director:getInstance():getOpenGLView():getScaleY() * size.height)) / cc.Director:getInstance():getOpenGLView():getScaleY()
        end
    end
    return offset
end

function LayoutHelper:getSize()
    return self._size
end