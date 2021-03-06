//
//  AllianceCommentShieldRemove.cpp
//  IF
//
//  Created by ganxiaohua on 15-1-15.
//
//

#include "AllianceCommentShieldRemove.h"

bool AllianceCommentShieldRemove::handleRecieve(cocos2d::CCDictionary *dict)
{
    if (dict->valueForKey("cmd")->compare(ALLIANCE_COMMENT_SHIELD_REMOVE) != 0)
        return false;
    
    CCDictionary *params=_dict(dict->objectForKey("params"));
    if (!params) {
        return false;
    }
    const CCString *pStr = params->valueForKey("errorCode");
    if (pStr->compare("")!=0) {
        callFail(NetResult::create());
    }else{
        callSuccess(NetResult::create(Error_OK, params));
    }
    return true;
}