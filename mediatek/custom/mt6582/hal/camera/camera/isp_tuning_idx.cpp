/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/********************************************************************************************
 *     LEGAL DISCLAIMER
 *
 *     (Header of MediaTek Software/Firmware Release or Documentation)
 *
 *     BY OPENING OR USING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *     THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE") RECEIVED
 *     FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON AN "AS-IS" BASIS
 *     ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES, EXPRESS OR IMPLIED,
 *     INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
 *     A PARTICULAR PURPOSE OR NONINFRINGEMENT. NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY
 *     WHATSOEVER WITH RESPECT TO THE SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY,
 *     INCORPORATED IN, OR SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK
 *     ONLY TO SUCH THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *     NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S SPECIFICATION
 *     OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *     BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE LIABILITY WITH
 *     RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE, AT MEDIATEK'S OPTION,
TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE, OR REFUND ANY SOFTWARE LICENSE
 *     FEES OR SERVICE CHARGE PAID BY BUYER TO MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *     THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE WITH THE LAWS
 *     OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF LAWS PRINCIPLES.
 ************************************************************************************************/

#define LOG_TAG "isp_tuning_idx"

#ifndef ENABLE_MY_LOG
    #define ENABLE_MY_LOG       (1)
#endif

#include <aaa_log.h>
#include <aaa_types.h>
#include "camera_custom_nvram.h"
#include <isp_tuning.h>
#include <camera_feature.h>
#include <awb_param.h>
#include <ae_param.h>
#include <af_param.h>
#include <flash_param.h>
#include <isp_tuning_cam_info.h>
#include <isp_tuning_idx.h>
#include "cfg_isp_tuning_idx.h"


using namespace NSIspTuning;

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
namespace
{
    enum EIndexNum
    {
        NUM_OBC         =   NVRAM_OBC_TBL_NUM,
        NUM_BPC         =   NVRAM_BPC_TBL_NUM,
        NUM_NR1         =   NVRAM_NR1_TBL_NUM,
        NUM_CFA         =   NVRAM_CFA_TBL_NUM,
        NUM_GGM         =   NVRAM_GGM_TBL_NUM,
        NUM_ANR         =   NVRAM_ANR_TBL_NUM,
        NUM_CCR         =   NVRAM_CCR_TBL_NUM,
        NUM_EE          =   NVRAM_EE_TBL_NUM,
    };

    template <EIndexNum Num>
    inline MBOOL setIdx(UINT8 &rIdxTgt, UINT8 const IdxSrc)
    {
        if  (IdxSrc < Num)
        {
            rIdxTgt = IdxSrc;
            return  MTRUE;
        }
        return  MFALSE;
    }

};  //  namespace


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MBOOL IndexMgr::setIdx_OBC(UINT8 const idx)   { return setIdx<NUM_OBC>(OBC, idx); }
MBOOL IndexMgr::setIdx_BPC(UINT8 const idx)   { return setIdx<NUM_BPC>(BPC, idx); }
MBOOL IndexMgr::setIdx_NR1(UINT8 const idx)   { return setIdx<NUM_NR1>(NR1, idx); }
MBOOL IndexMgr::setIdx_CFA(UINT8 const idx)   { return setIdx<NUM_CFA>(CFA, idx); }
MBOOL IndexMgr::setIdx_GGM(UINT8 const idx)   { return setIdx<NUM_GGM>(GGM, idx); }
MBOOL IndexMgr::setIdx_ANR(UINT8 const idx)   { return setIdx<NUM_ANR>(ANR, idx); }
MBOOL IndexMgr::setIdx_CCR(UINT8 const idx)   { return setIdx<NUM_CCR>(CCR, idx); }
MBOOL IndexMgr::setIdx_EE(UINT8 const idx)    { return setIdx<NUM_EE>(EE, idx); }

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void
IndexMgr::
dump() const
{
    MY_LOG(
        "[IndexMgr][dump]"
        " OBC:%d, BPC:%d, NR1:%d, CFA:%d, GGM:%d, ANR:%d, CCR:%d, EE:%d"
        , OBC, BPC, NR1, CFA, GGM, ANR, CCR, EE
    );
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
IdxSetMgrBase&
IdxSetMgrBase::
getInstance()
{
    static IdxSetMgr singleton;
    static struct link
    {
        link(IdxSetMgr& r)
        {
            r.linkIndexSet();
        }
    } link_singleton(singleton);
    return  singleton;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
MVOID
IdxSetMgr::
linkIndexSet()
{
    ::memset(m_pNormalPreview,  0, sizeof(m_pNormalPreview));
    ::memset(m_pZsdPreview_CC,  0, sizeof(m_pZsdPreview_CC));
    ::memset(m_pZsdPreview_NCC,  0, sizeof(m_pZsdPreview_NCC));
    ::memset(m_pNormalCapture,  0, sizeof(m_pNormalCapture));
    ::memset(m_pVideoPreview,   0, sizeof(m_pVideoPreview));
    ::memset(m_pVideoCapture,   0, sizeof(m_pVideoCapture));
    ::memset(m_pMFCapturePass1, 0, sizeof(m_pMFCapturePass1));
    ::memset(m_pMFCapturePass2, 0, sizeof(m_pMFCapturePass2));

#define LINK_ONE_SCENE_ISOs(link, scene)\
    link(scene, eIDX_ISO_100);\
    link(scene, eIDX_ISO_200);\
    link(scene, eIDX_ISO_400);\
    link(scene, eIDX_ISO_800);\
    link(scene, eIDX_ISO_1600);\
    link(scene, eIDX_ISO_2400);\
    link(scene, eIDX_ISO_3200)

#define LINK_SCENEs_ISOs(link)\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_OFF);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_NORMAL);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_ACTION);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_PORTRAIT);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_LANDSCAPE);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_NIGHTSCENE);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_NIGHTPORTRAIT);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_THEATRE);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_BEACH);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_SNOW);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_SUNSET);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_STEADYPHOTO);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_FIREWORKS);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_SPORTS);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_PARTY);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_CANDLELIGHT);\
    LINK_ONE_SCENE_ISOs(link, SCENE_MODE_HDR)

#define LINK_NORMAL_PREVIEW(scene, iso)\
m_pNormalPreview[scene][iso] = &IdxSet<EIspProfile_NormalPreview, scene, iso>::idx

#define LINK_ZSD_PREVIEW_CC(scene, iso)\
m_pZsdPreview_CC[scene][iso] = &IdxSet<EIspProfile_ZsdPreview_CC, scene, iso>::idx

#define LINK_ZSD_PREVIEW_NCC(scene, iso)\
m_pZsdPreview_NCC[scene][iso] = &IdxSet<EIspProfile_ZsdPreview_NCC, scene, iso>::idx

#define LINK_NORMAL_CAPTURE(scene, iso)\
m_pNormalCapture[scene][iso] = &IdxSet<EIspProfile_NormalCapture, scene, iso>::idx


    //======================================================================
    LINK_SCENEs_ISOs(LINK_NORMAL_PREVIEW);
    LINK_SCENEs_ISOs(LINK_ZSD_PREVIEW_CC);
    LINK_SCENEs_ISOs(LINK_ZSD_PREVIEW_NCC);    
    LINK_SCENEs_ISOs(LINK_NORMAL_CAPTURE);
    //======================================================================


#define LINK_VIDEO_PREVIEW(scene, iso)\
m_pVideoPreview [iso] = &IdxSet<EIspProfile_VideoPreview, iso>::idx;

#define LINK_VIDEO_CAPTURE(scene, iso)\
m_pVideoCapture [iso] = &IdxSet<EIspProfile_VideoCapture, iso>::idx;

#define LINK_MF_CAPTURE_PASS1(scene, iso)\
m_pMFCapturePass1 [iso] = &IdxSet<EIspProfile_MFCapPass1, iso>::idx;

#define LINK_MF_CAPTURE_PASS2(scene, iso)\
m_pMFCapturePass2 [iso] = &IdxSet<EIspProfile_MFCapPass2, iso>::idx;

    //======================================================================
    LINK_ONE_SCENE_ISOs(LINK_VIDEO_PREVIEW, "unused scene");
    LINK_ONE_SCENE_ISOs(LINK_VIDEO_CAPTURE, "unused scene");
    LINK_ONE_SCENE_ISOs(LINK_MF_CAPTURE_PASS1, "unused scene");
    LINK_ONE_SCENE_ISOs(LINK_MF_CAPTURE_PASS2, "unused scene");
    //======================================================================

}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
INDEX_T const*
IdxSetMgr::
get(MUINT32 const mode, MUINT32 const i/*=-1*/, MUINT32 const j/*=-1*/) const
{
    switch  (mode)
    {
    //  Normal
    case EIspProfile_NormalPreview:
        return  get_NormalPreview(i, j);
    case EIspProfile_ZsdPreview_CC:
        return  get_ZsdPreview_CC(i, j);
    case EIspProfile_ZsdPreview_NCC:    
        return  get_ZsdPreview_NCC(i, j);
    case EIspProfile_NormalCapture:
        return  get_NormalCapture(i, j);
    case EIspProfile_VideoPreview:
        return  get_VideoPreview(i, j);
    case EIspProfile_VideoCapture:
        return  get_VideoCapture(i, j);
    case EIspProfile_MFCapPass1:
        return  get_MFCapturePass1(i, j);
    case EIspProfile_MFCapPass2:
        return  get_MFCapturePass2(i, j);
    default:
        break;
    }
    return  NULL;
}


