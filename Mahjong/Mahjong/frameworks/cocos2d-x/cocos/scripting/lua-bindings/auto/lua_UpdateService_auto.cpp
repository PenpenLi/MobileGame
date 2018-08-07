#include "scripting/lua-bindings/auto/lua_UpdateService_auto.hpp"
#include "UpdateService.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

int lua_UpdateService_UpdateService_checkVersion(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_checkVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_checkVersion'", nullptr);
            return 0;
        }
        cobj->checkVersion();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:checkVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_checkVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_SendData(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_SendData'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        void* arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_SendData'", nullptr);
            return 0;
        }
        cobj->SendData(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:SendData",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_SendData'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_CheckUpdateVersion(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_CheckUpdateVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_CheckUpdateVersion'", nullptr);
            return 0;
        }
        bool ret = cobj->CheckUpdateVersion();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:CheckUpdateVersion",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_CheckUpdateVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_Run(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_Run'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_Run'", nullptr);
            return 0;
        }
        cobj->Run();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:Run",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_Run'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_myThreadA(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_myThreadA'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_myThreadA'", nullptr);
            return 0;
        }
        cobj->myThreadA();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:myThreadA",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_myThreadA'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_initInfo(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_initInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        std::string arg0;
        std::string arg1;
        int arg2;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "UpdateService:initInfo");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "UpdateService:initInfo");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UpdateService:initInfo");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_initInfo'", nullptr);
            return 0;
        }
        cobj->initInfo(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:initInfo",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_initInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_PushMsg(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_PushMsg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        UpdateMsg arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR UpdateMsg
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_PushMsg'", nullptr);
            return 0;
        }
        cobj->PushMsg(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:PushMsg",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_PushMsg'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_OnCheckVersion(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_OnCheckVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 5) 
    {
        bool arg0;
        int arg1;
        int arg2;
        int arg3;
        int arg4;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "UpdateService:OnCheckVersion");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "UpdateService:OnCheckVersion");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UpdateService:OnCheckVersion");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "UpdateService:OnCheckVersion");

        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "UpdateService:OnCheckVersion");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_OnCheckVersion'", nullptr);
            return 0;
        }
        cobj->OnCheckVersion(arg0, arg1, arg2, arg3, arg4);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:OnCheckVersion",argc, 5);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_OnCheckVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_Start(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_Start'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 7) 
    {
        std::string arg0;
        long arg1;
        long arg2;
        long arg3;
        long arg4;
        long arg5;
        int arg6;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "UpdateService:Start");

        ok &= luaval_to_long(tolua_S, 3, &arg1, "UpdateService:Start");

        ok &= luaval_to_long(tolua_S, 4, &arg2, "UpdateService:Start");

        ok &= luaval_to_long(tolua_S, 5, &arg3, "UpdateService:Start");

        ok &= luaval_to_long(tolua_S, 6, &arg4, "UpdateService:Start");

        ok &= luaval_to_long(tolua_S, 7, &arg5, "UpdateService:Start");
       
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_Start'", nullptr);
            return 0;
        }
		//ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6, "UpdateService:Start");
		arg6 = toluafix_ref_function(tolua_S, 8, 0);
		if (!arg6) return 0;

        cobj->Start(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:Start",argc, 7);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_Start'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_init(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_init'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_init'", nullptr);
            return 0;
        }
        bool ret = cobj->init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:init",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_init'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_RunTask(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_RunTask'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_RunTask'", nullptr);
            return 0;
        }
        cobj->RunTask();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:RunTask",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_RunTask'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_SendCommand(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_SendCommand'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            UpdateCommand arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UpdateService:SendCommand");

            if (!ok) { break; }
            std::string arg1;
            ok &= luaval_to_std_string(tolua_S, 3,&arg1, "UpdateService:SendCommand");

            if (!ok) { break; }
            std::string arg2;
            ok &= luaval_to_std_string(tolua_S, 4,&arg2, "UpdateService:SendCommand");

            if (!ok) { break; }
            cobj->SendCommand(arg0, arg1, arg2);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            UpdateCommand arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UpdateService:SendCommand");

            if (!ok) { break; }
            void* arg1;
            #pragma warning NO CONVERSION TO NATIVE FOR void*
		ok = false;

            if (!ok) { break; }
            cobj->SendCommand(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "UpdateService:SendCommand",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_SendCommand'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_SendCheckVersion(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_SendCheckVersion'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        UpdateMsg arg0;

        #pragma warning NO CONVERSION TO NATIVE FOR UpdateMsg
		ok = false;
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_SendCheckVersion'", nullptr);
            return 0;
        }
        cobj->SendCheckVersion(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:SendCheckVersion",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_SendCheckVersion'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_GetVerionFormServer(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_GetVerionFormServer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        int arg0;
        int arg1;
        int arg2;
        int arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "UpdateService:GetVerionFormServer");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "UpdateService:GetVerionFormServer");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "UpdateService:GetVerionFormServer");

        ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "UpdateService:GetVerionFormServer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_GetVerionFormServer'", nullptr);
            return 0;
        }
        bool ret = cobj->GetVerionFormServer(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:GetVerionFormServer",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_GetVerionFormServer'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_SendMsg(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_SendMsg'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_SendMsg'", nullptr);
            return 0;
        }
        cobj->SendMsg();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:SendMsg",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_SendMsg'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_myThreadB(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (UpdateService*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_UpdateService_UpdateService_myThreadB'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_myThreadB'", nullptr);
            return 0;
        }
        cobj->myThreadB();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:myThreadB",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_myThreadB'.",&tolua_err);
#endif

    return 0;
}
int lua_UpdateService_UpdateService_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"UpdateService",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_create'", nullptr);
            return 0;
        }
        UpdateService* ret = UpdateService::create();
        object_to_luaval<UpdateService>(tolua_S, "UpdateService",(UpdateService*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "UpdateService:create",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_create'.",&tolua_err);
#endif
    return 0;
}
int lua_UpdateService_UpdateService_constructor(lua_State* tolua_S)
{
    int argc = 0;
    UpdateService* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif



    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_UpdateService_UpdateService_constructor'", nullptr);
            return 0;
        }
        cobj = new UpdateService();
        cobj->autorelease();
        int ID =  (int)cobj->_ID ;
        int* luaID =  &cobj->_luaID ;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"UpdateService");
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "UpdateService:UpdateService",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_UpdateService_UpdateService_constructor'.",&tolua_err);
#endif

    return 0;
}

static int lua_UpdateService_UpdateService_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (UpdateService)");
    return 0;
}

int lua_register_UpdateService_UpdateService(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"UpdateService");
    tolua_cclass(tolua_S,"UpdateService","UpdateService","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"UpdateService");
        tolua_function(tolua_S,"new",lua_UpdateService_UpdateService_constructor);
        tolua_function(tolua_S,"checkVersion",lua_UpdateService_UpdateService_checkVersion);
        tolua_function(tolua_S,"SendData",lua_UpdateService_UpdateService_SendData);
        tolua_function(tolua_S,"CheckUpdateVersion",lua_UpdateService_UpdateService_CheckUpdateVersion);
        tolua_function(tolua_S,"Run",lua_UpdateService_UpdateService_Run);
        tolua_function(tolua_S,"myThreadA",lua_UpdateService_UpdateService_myThreadA);
        tolua_function(tolua_S,"initInfo",lua_UpdateService_UpdateService_initInfo);
        tolua_function(tolua_S,"PushMsg",lua_UpdateService_UpdateService_PushMsg);
        tolua_function(tolua_S,"OnCheckVersion",lua_UpdateService_UpdateService_OnCheckVersion);
        tolua_function(tolua_S,"Start",lua_UpdateService_UpdateService_Start);
        tolua_function(tolua_S,"init",lua_UpdateService_UpdateService_init);
        tolua_function(tolua_S,"RunTask",lua_UpdateService_UpdateService_RunTask);
        tolua_function(tolua_S,"SendCommand",lua_UpdateService_UpdateService_SendCommand);
        tolua_function(tolua_S,"SendCheckVersion",lua_UpdateService_UpdateService_SendCheckVersion);
        tolua_function(tolua_S,"GetVerionFormServer",lua_UpdateService_UpdateService_GetVerionFormServer);
        tolua_function(tolua_S,"SendMsg",lua_UpdateService_UpdateService_SendMsg);
        tolua_function(tolua_S,"myThreadB",lua_UpdateService_UpdateService_myThreadB);
        tolua_function(tolua_S,"create", lua_UpdateService_UpdateService_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(UpdateService).name();
    g_luaType[typeName] = "UpdateService";
    g_typeCast["UpdateService"] = "UpdateService";
    return 1;
}
TOLUA_API int register_all_UpdateService(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"my",0);
	tolua_beginmodule(tolua_S,"my");

	lua_register_UpdateService_UpdateService(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

