--region *.lua
--Date
--此文件由[BabeLua]插件自动生成

AccountInfo = 
{
    AccountName = "",
    PassWords = "",
}

--function AccountInfo:clear()
--    self.AccountName ="",
--    self.PassWords ="",
--    --_account = AccountInfo,
--end

AccountManager = 
{
  NEWFILE = 'NewData',
  _account = AccountInfo,
}


function AccountManager:setCurrentAccount()
    local context =""
    --if nil ~= self._account then
       AccountInfo.AccountName = gameData:getPlayerName()
       AccountInfo.PassWords = gameData:getPlayerPassWord()
       context =json.encode(AccountInfo)
       addimagesync:AccountInfo(context)
    --end
    print("...")
end

--endregion
