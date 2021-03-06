/*
 * Copyright (c) 1998-2001 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 *
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

/*
 * Copyright (c) 2000-2001 Apple Computer, Inc.  All rights reserved.
 *
 * IOATABlockStorageDevice.h
 *
 * This subclass implements a relay to a protocol and device-specific
 * provider.
 *
 *
 * HISTORY
 *
 *		09/28/2000	CJS		Started IOATABlockStorageDevice
 *							(ported IOATAHDDrive)
 *
 */

#ifndef _IO_ATA_BLOCKSTORAGE_DEVICE_H_
#define _IO_ATA_BLOCKSTORAGE_DEVICE_H_

#include <IOKit/IOTypes.h>
#include <IOKit/storage/IOBlockStorageDevice.h>

class IOATABlockStorageDriver;

class IOATABlockStorageDevice : public IOBlockStorageDevice
{
	
	OSDeclareDefaultStructors ( IOATABlockStorageDevice )
	
	
protected:
	
	
	IOATABlockStorageDriver *     fProvider;
	
	// binary compatibility instance variable expansion
	struct ExpansionData { };
	ExpansionData * reserved;
	
	virtual bool		attach ( IOService * provider );
	virtual void		detach ( IOService * provider );
	
public:
	
	//-----------------------------------------------------------------------
	// Override setProperties for turning off APM features on powerbooks.
	
    virtual IOReturn	setProperties ( OSObject * properties );
	
	
	virtual IOReturn	doAsyncReadWrite ( 	IOMemoryDescriptor *	buffer,
											UInt32					block,
											UInt32					nblks,
											IOStorageCompletion		completion );
	
	virtual IOReturn	doSyncReadWrite ( 	IOMemoryDescriptor *	buffer,
											UInt32					block,
											UInt32					nblks );
	
    virtual IOReturn	doEjectMedia ( void );
	
    virtual IOReturn	doFormatMedia ( UInt64 byteCapacity );
	
    virtual UInt32		doGetFormatCapacities ( UInt64 *	capacities,
    											UInt32		capacitiesMaxCount ) const;
	
    virtual IOReturn	doLockUnlockMedia ( bool doLock );
	
    virtual IOReturn	doSynchronizeCache ( void );
        
    virtual char *		getVendorString ( void );
    
    virtual char *		getProductString ( void );
    
    virtual char *		getRevisionString ( void );
    
    virtual char *		getAdditionalDeviceInfoString ( void );
    
    virtual IOReturn	reportBlockSize ( UInt64 * blockSize );
    
    virtual IOReturn	reportEjectability ( bool * isEjectable );
    
    virtual IOReturn	reportLockability ( bool * isLockable );
    
    virtual IOReturn	reportMediaState ( bool * mediaPresent, bool * changed );
    
    virtual IOReturn	reportPollRequirements ( 	bool * pollIsRequired,
    												bool * pollIsExpensive );
    
    virtual IOReturn	reportMaxReadTransfer ( UInt64 blockSize, UInt64 * max );
    
    virtual IOReturn	reportMaxValidBlock ( UInt64 * maxBlock );
    
    virtual IOReturn	reportMaxWriteTransfer ( UInt64 blockSize, UInt64 * max );
    
    virtual IOReturn	reportRemovability ( bool * isRemovable );
    
    virtual IOReturn	reportWriteProtection ( bool * isWriteProtected );

	// Binary Compatibility reserved method space
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 1 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 2 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 3 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 4 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 5 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 6 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 7 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 8 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 9 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 10 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 11 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 12 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 13 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 14 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 15 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 16 );
	
};

#endif /* !_IO_ATA_BLOCKSTORAGE_DEVICE_H_ */
