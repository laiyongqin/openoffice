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



#ifndef _SVX_XFLBOXY_HXX
#define _SVX_XFLBOXY_HXX

#include <svl/intitem.hxx>
#include "svx/svxdllapi.h"

/*************************************************************************
|*
|*
|*
\************************************************************************/

class SVX_DLLPUBLIC XFillBmpPosOffsetXItem : public SfxUInt16Item
{
public:
							TYPEINFO();
							XFillBmpPosOffsetXItem( sal_uInt16 nOffPosX = 0 );
							SVX_DLLPRIVATE XFillBmpPosOffsetXItem( SvStream& rIn );

	SVX_DLLPRIVATE virtual SfxPoolItem*    Clone( SfxItemPool* pPool = 0 ) const;
	SVX_DLLPRIVATE virtual SfxPoolItem*    Create( SvStream& rIn, sal_uInt16 nVer ) const;

	SVX_DLLPRIVATE virtual SfxItemPresentation GetPresentation( SfxItemPresentation ePres,
									SfxMapUnit eCoreMetric,
									SfxMapUnit ePresMetric,
                                    String &rText, const IntlWrapper * = 0 ) const;
};


/*************************************************************************
|*
|*
|*
\************************************************************************/

class SVX_DLLPUBLIC XFillBmpPosOffsetYItem : public SfxUInt16Item
{
public:
							TYPEINFO();
							XFillBmpPosOffsetYItem( sal_uInt16 nOffPosY = 0 );
							SVX_DLLPRIVATE XFillBmpPosOffsetYItem( SvStream& rIn );

	SVX_DLLPRIVATE virtual SfxPoolItem*    Clone( SfxItemPool* pPool = 0 ) const;
	SVX_DLLPRIVATE virtual SfxPoolItem*    Create( SvStream& rIn, sal_uInt16 nVer ) const;

	SVX_DLLPRIVATE virtual SfxItemPresentation GetPresentation( SfxItemPresentation ePres,
									SfxMapUnit eCoreMetric,
									SfxMapUnit ePresMetric,
                                    String &rText, const IntlWrapper * = 0 ) const;
};

#endif