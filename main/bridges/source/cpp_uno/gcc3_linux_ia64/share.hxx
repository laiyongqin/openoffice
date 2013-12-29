/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#include "uno/mapping.h"

#include <typeinfo>
#include <exception>
#include <cstddef>
#include "bridges/cpp_uno/shared/vtablefactory.hxx"

namespace CPPU_CURRENT_NAMESPACE
{

  void dummy_can_throw_anything( char const * );


// ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h

struct _Unwind_Exception
{
    unsigned exception_class __attribute__((__mode__(__DI__)));
    void * exception_cleanup;
    unsigned private_1 __attribute__((__mode__(__word__)));
    unsigned private_2 __attribute__((__mode__(__word__)));
} __attribute__((__aligned__));

struct __cxa_exception
{ 
    ::std::type_info *exceptionType;
    void (*exceptionDestructor)(void *); 
    
    ::std::unexpected_handler unexpectedHandler;
    ::std::terminate_handler terminateHandler;
    
    __cxa_exception *nextException;
    
    int handlerCount;
    
    int handlerSwitchValue;
    const unsigned char *actionRecord;
    const unsigned char *languageSpecificData;
    void *catchTemp;
    void *adjustedPtr;
    
    _Unwind_Exception unwindHeader;
};    

extern "C" void *__cxa_allocate_exception(
    std::size_t thrown_size ) throw();
extern "C" void __cxa_throw (
    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) ) __attribute__((noreturn));

struct __cxa_eh_globals
{
    __cxa_exception *caughtExceptions;
    unsigned int uncaughtExceptions;
};
extern "C" __cxa_eh_globals *__cxa_get_globals () throw();

// -----

//==================================================================================================
void raiseException(
    uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
//==================================================================================================
void fillUnoException(
    __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
}

namespace ia64
{
    enum ia64limits { MAX_GPR_REGS = 8, MAX_SSE_REGS = 8, MAX_REG_SLOTS = 8 };

    bool return_in_hidden_param( typelib_TypeDescriptionReference *pTypeRef );
    bool return_via_r8_buffer( typelib_TypeDescriptionReference *pTypeRef );

    struct RegReturn
    {
        long r8;
        long r9;
        long r10;
        long r11;
    };
}

namespace bridges
{
    namespace cpp_uno
    {
        namespace shared
        {
            /*
                http://www.swag.uwaterloo.ca/asx/ABI.html
                On Itanium, function pointers are pairs: the function address followed
                by the global pointer value that should be used when calling the
                function (code address, gp value)
            */
            struct VtableFactory::Slot
            {
                sal_uInt64 code_address;
                sal_uInt64 gp_value;
            };
        }
    }
}
/* vi:set tabstop=4 shiftwidth=4 expandtab: */