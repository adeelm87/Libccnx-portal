/*
 * Copyright (c) 2013-2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL XEROX OR PARC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ################################################################################
 * #
 * # PATENT NOTICE
 * #
 * # This software is distributed under the BSD 2-clause License (see LICENSE
 * # file).  This BSD License does not make any patent claims and as such, does
 * # not act as a patent grant.  The purpose of this section is for each contributor
 * # to define their intentions with respect to intellectual property.
 * #
 * # Each contributor to this source code is encouraged to state their patent
 * # claims and licensing mechanisms for any contributions made. At the end of
 * # this section contributors may each make their own statements.  Contributor's
 * # claims and grants only apply to the pieces (source code, programs, text,
 * # media, etc) that they have contributed directly to this software.
 * #
 * # There is no guarantee that this section is complete, up to date or accurate. It
 * # is up to the contributors to maintain their portion of this section and up to
 * # the user of the software to verify any claims herein.
 * #
 * # Do not remove this header notification.  The contents of this section must be
 * # present in all distributions of the software.  You may only modify your own
 * # intellectual property statements.  Please provide contact information.
 *
 * - Palo Alto Research Center, Inc
 * This software distribution does not grant any rights to patents owned by Palo
 * Alto Research Center, Inc (PARC). Rights to these patents are available via
 * various mechanisms. As of January 2016 PARC has committed to FRAND licensing any
 * intellectual property used by its contributions to this software. You may
 * contact PARC at cipo@parc.com for more information or visit http://www.ccnx.org
 */
/**
 * @author Glenn Scott, Alan Walendowski, Palo Alto Research Center (Xerox PARC)
 * @copyright (c) 2013-2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC).  All rights reserved.
 */
#include <config.h>

#include <LongBow/runtime.h>

#include <ccnx/api/ccnx_Portal/ccnx_PortalAPI.h>

#include <parc/algol/parc_Object.h>
#include <parc/algol/parc_Deque.h>

typedef struct {
    PARCDeque *messageAddressBuffer;
} _CCNxPortalAPIContext;

static void
_ccnxPortalAPIContext_Destroy(_CCNxPortalAPIContext **instancePtr)
{
    _CCNxPortalAPIContext *instance = *instancePtr;

    parcDeque_Release(&instance->messageAddressBuffer);
}

parcObject_ExtendPARCObject(_CCNxPortalAPIContext, _ccnxPortalAPIContext_Destroy, NULL, NULL, NULL, NULL, NULL, NULL);

//static parcObject_ImplementAcquire(_ccnxPortalAPIContext, _CCNxPortalAPIContext);

static parcObject_ImplementRelease(_ccnxPortalAPIContext, _CCNxPortalAPIContext);

static _CCNxPortalAPIContext *
_ccnxPortalAPIContext_Create(void)
{
    _CCNxPortalAPIContext *result = parcObject_CreateInstance(_CCNxPortalAPIContext);
    result->messageAddressBuffer = parcDeque_Create();
    return result;
}

static void
_ccnxPortalAPI_Start(void *privateData)
{
}

static void
_ccnxPortalAPI_Stop(void *privateData)
{
}

static bool
_ccnxPortalAPI_Send(void *privateData, const CCNxMetaMessage *portalMessage, const CCNxStackTimeout *microSeconds)
{
    printf("Inside _ccnxPortalAPI_Send\n");
    const _CCNxPortalAPIContext *transportContext = (_CCNxPortalAPIContext *) privateData;

    // Save the address of the portal message on our queue. We don't need to copy the whole message.
    parcDeque_Append(transportContext->messageAddressBuffer, (void *) ccnxMetaMessage_Acquire(portalMessage));

    return true;
}

static CCNxMetaMessage *
_ccnxPortalAPI_Receive(void *privateData, const CCNxStackTimeout *microSeconds)
{
    const _CCNxPortalAPIContext *transportContext = (_CCNxPortalAPIContext *) privateData;

    if (parcDeque_IsEmpty(transportContext->messageAddressBuffer)) {
        return NULL;
    }

    CCNxMetaMessage *result = (CCNxMetaMessage *) parcDeque_RemoveFirst(transportContext->messageAddressBuffer);

    return result;
}

static int
_ccnxPortalAPI_GetFileId(void *privateData)
{
    return 3;
}

static CCNxPortalAttributes *
_ccnxPortalAPI_GetAttributes(void *privateData)
{
    return NULL;
}

static bool
_ccnxPortalAPI_SetAttributes(void *privateData, const CCNxPortalAttributes *attributes)
{
    return false;
}

static bool
_ccnxPortalAPI_Listen(void *privateData, const CCNxName *name, const CCNxStackTimeout *microSeconds)
{
    return true;
}

static bool
_ccnxPortalAPI_Ignore(void *privateData, const CCNxName *name, const CCNxStackTimeout *microSeconds)
{
    return true;
}

CCNxPortal *
ccnxPortalAPI_LoopBack(const CCNxPortalFactory *factory, const CCNxPortalAttributes *attributes)
{
    _CCNxPortalAPIContext *apiContext = _ccnxPortalAPIContext_Create();

    CCNxPortalStack *stack =
        ccnxPortalStack_Create(factory,
                               attributes,
                               _ccnxPortalAPI_Start,
                               _ccnxPortalAPI_Stop,
                               _ccnxPortalAPI_Receive,
                               _ccnxPortalAPI_Send,
                               _ccnxPortalAPI_Listen,
                               _ccnxPortalAPI_Ignore,
                               _ccnxPortalAPI_GetFileId,
                               _ccnxPortalAPI_SetAttributes,
                               _ccnxPortalAPI_GetAttributes,
                               apiContext,
                               (void (*)(void **))_ccnxPortalAPIContext_Release);

    CCNxPortal *result = ccnxPortal_Create(attributes, stack);
    return result;
}
