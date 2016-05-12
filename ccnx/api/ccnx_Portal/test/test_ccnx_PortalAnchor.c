/*
 * Copyright (c) 2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC)
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
 * @author <#gscott#>, Palo Alto Research Center (Xerox PARC)
 * @copyright (c) 2015, Xerox Corporation (Xerox) and Palo Alto Research Center, Inc (PARC).  All rights reserved.
 */
#include "../ccnx_PortalAnchor.c"

#include <LongBow/testing.h>
#include <LongBow/debugging.h>
#include <parc/algol/parc_Memory.h>
#include <parc/algol/parc_SafeMemory.h>
#include <parc/algol/parc_DisplayIndented.h>

#include <parc/testing/parc_MemoryTesting.h>
#include <parc/testing/parc_ObjectTesting.h>

LONGBOW_TEST_RUNNER(ccnx_PortalAnchor)
{
    // The following Test Fixtures will run their corresponding Test Cases.
    // Test Fixtures are run in the order specified, but all tests should be idempotent.
    // Never rely on the execution order of tests or share state between them.
    LONGBOW_RUN_TEST_FIXTURE(CreateAcquireRelease);
    LONGBOW_RUN_TEST_FIXTURE(Object);
    LONGBOW_RUN_TEST_FIXTURE(Specialization);
}

// The Test Runner calls this function once before any Test Fixtures are run.
LONGBOW_TEST_RUNNER_SETUP(ccnx_PortalAnchor)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

// The Test Runner calls this function once after all the Test Fixtures are run.
LONGBOW_TEST_RUNNER_TEARDOWN(ccnx_PortalAnchor)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE(CreateAcquireRelease)
{
    LONGBOW_RUN_TEST_CASE(CreateAcquireRelease, CreateRelease);
}

LONGBOW_TEST_FIXTURE_SETUP(CreateAcquireRelease)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(CreateAcquireRelease)
{
    if (!parcMemoryTesting_ExpectedOutstanding(0, "%s leaked memory.", longBowTestCase_GetFullName(testCase))) {
        return LONGBOW_STATUS_MEMORYLEAK;
    }

    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_CASE(CreateAcquireRelease, CreateRelease)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *instance = ccnxPortalAnchor_Create(name, expireTime);
    assertNotNull(instance, "Expected non-null result from ccnxPortalAnchor_Create();");

    parcObjectTesting_AssertAcquireReleaseContract(ccnxPortalAnchor_Acquire, instance);

    ccnxPortalAnchor_Release(&instance);
    ccnxName_Release(&name);
    assertNull(instance, "Expected null result from ccnxPortalAnchor_Release();");
}

LONGBOW_TEST_FIXTURE(Object)
{
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_Compare);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_Copy);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_Display);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_Equals);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_HashCode);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_IsValid);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_ToJSON);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_ToString);
    LONGBOW_RUN_TEST_CASE(Object, ccnxPortalAnchor_SerializeDeserialize);
}

LONGBOW_TEST_FIXTURE_SETUP(Object)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(Object)
{
    if (!parcMemoryTesting_ExpectedOutstanding(0, "%s mismanaged memory.", longBowTestCase_GetFullName(testCase))) {
        return LONGBOW_STATUS_MEMORYLEAK;
    }

    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_CASE(Object,  ccnxPortalAnchor_Compare)
{
    testUnimplemented("");

}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_Copy)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *instance = ccnxPortalAnchor_Create(name, expireTime);

    CCNxPortalAnchor *copy = ccnxPortalAnchor_Copy(instance);
    assertTrue(ccnxPortalAnchor_Equals(instance, copy), "Expected the copy to be equal to the original");

    ccnxPortalAnchor_Release(&instance);
    ccnxPortalAnchor_Release(&copy);
    ccnxName_Release(&name);
}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_Display)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *instance = ccnxPortalAnchor_Create(name, expireTime);
    ccnxPortalAnchor_Display(instance, 0);
    ccnxPortalAnchor_Release(&instance);
    ccnxName_Release(&name);
}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_Equals)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *x = ccnxPortalAnchor_Create(name, expireTime);
    CCNxPortalAnchor *y = ccnxPortalAnchor_Create(name, expireTime);
    CCNxPortalAnchor *z = ccnxPortalAnchor_Create(name, expireTime);

    parcObjectTesting_AssertEquals(x, y, z, NULL);

    ccnxPortalAnchor_Release(&x);
    ccnxPortalAnchor_Release(&y);
    ccnxPortalAnchor_Release(&z);
    ccnxName_Release(&name);
}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_HashCode)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *x = ccnxPortalAnchor_Create(name, expireTime);
    CCNxPortalAnchor *y = ccnxPortalAnchor_Create(name, expireTime);

    parcObjectTesting_AssertHashCode(x, y);

    ccnxPortalAnchor_Release(&x);
    ccnxPortalAnchor_Release(&y);
    ccnxName_Release(&name);
}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_IsValid)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *instance = ccnxPortalAnchor_Create(name, expireTime);
    assertTrue(ccnxPortalAnchor_IsValid(instance), "Expected ccnxPortalAnchor_Create to result in a valid instance.");

    ccnxPortalAnchor_Release(&instance);
    ccnxName_Release(&name);

    assertFalse(ccnxPortalAnchor_IsValid(instance), "Expected ccnxPortalAnchor_Release to result in an invalid instance.");
}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_ToJSON)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *instance = ccnxPortalAnchor_Create(name, expireTime);

    PARCJSON *json = ccnxPortalAnchor_ToJSON(instance);

    parcJSON_Release(&json);

    ccnxPortalAnchor_Release(&instance);
    ccnxName_Release(&name);
}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_ToString)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *instance = ccnxPortalAnchor_Create(name, expireTime);

    char *string = ccnxPortalAnchor_ToString(instance);

    assertNotNull(string, "Expected non-NULL result from ccnxPortalAnchor_ToString");

    parcMemory_Deallocate((void **) &string);
    ccnxPortalAnchor_Release(&instance);
    ccnxName_Release(&name);
}

LONGBOW_TEST_CASE(Object, ccnxPortalAnchor_SerializeDeserialize)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *instance = ccnxPortalAnchor_Create(name, expireTime);

    PARCBufferComposer *composer = parcBufferComposer_Create();
    ccnxPortalAnchor_Serialize(instance, composer);
    PARCBuffer *buffer = parcBufferComposer_ProduceBuffer(composer);
    CCNxPortalAnchor *copy = ccnxPortalAnchor_Deserialize(buffer);

    assertTrue(ccnxPortalAnchor_Equals(instance, copy), "Expected deserialized form to be equal to the original");
    ccnxPortalAnchor_Release(&copy);
    parcBuffer_Release(&buffer);
    parcBufferComposer_Release(&composer);
    ccnxPortalAnchor_Release(&instance);
    ccnxName_Release(&name);
}

LONGBOW_TEST_FIXTURE(Specialization)
{
    LONGBOW_RUN_TEST_CASE(Specialization, ccnxPortalAnchor_GetNamePrefix);

    LONGBOW_RUN_TEST_CASE(Specialization, ccnxPortalAnchor_GetExpireTime);
}

LONGBOW_TEST_FIXTURE_SETUP(Specialization)
{
    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_FIXTURE_TEARDOWN(Specialization)
{
    if (!parcMemoryTesting_ExpectedOutstanding(0, "%s mismanaged memory.", longBowTestCase_GetFullName(testCase))) {
        return LONGBOW_STATUS_MEMORYLEAK;
    }

    return LONGBOW_STATUS_SUCCEEDED;
}

LONGBOW_TEST_CASE(Specialization, ccnxPortalAnchor_GetNamePrefix)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *anchor = ccnxPortalAnchor_Create(name, expireTime);

    CCNxName *actual = ccnxPortalAnchor_GetNamePrefix(anchor);

    assertTrue(ccnxName_Equals(name, actual), "Expected name to be equal.");
    ccnxPortalAnchor_Release(&anchor);
    ccnxName_Release(&name);
}

LONGBOW_TEST_CASE(Specialization, ccnxPortalAnchor_GetExpireTime)
{
    CCNxName *name = ccnxName_CreateFromCString("lci:/name");
    time_t expireTime = 123;
    CCNxPortalAnchor *anchor = ccnxPortalAnchor_Create(name, expireTime);

    time_t actual = ccnxPortalAnchor_GetExpireTime(anchor);

    assertTrue(expireTime == actual, "Expected expire-time to be equal.");
    ccnxPortalAnchor_Release(&anchor);
    ccnxName_Release(&name);
}


int
main(int argc, char *argv[argc])
{
    LongBowRunner *testRunner = LONGBOW_TEST_RUNNER_CREATE(ccnx_PortalAnchor);
    int exitStatus = longBowMain(argc, argv, testRunner, NULL);
    longBowTestRunner_Destroy(&testRunner);
    exit(exitStatus);
}
