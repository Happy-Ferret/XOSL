/*
 * Extended Operating System Loader (XOSL)
 * Copyright (c) 1999 by Geurt Vos
 *
 * This code is distributed under GNU General Public License (GPL)
 *
 * The full text of the license can be found in the GPL.TXT file,
 * or at http://www.gnu.org
 */

/*
 * CDisk
 * Map a hard disk on sector level
 * Uses LBA access when available (necessary for 8GB+ disks)
 */

#ifndef __disk__
#define __disk__

#include <defs.h>
#include <transfer.h>

class CDisk {
	public:
		CDisk();
		~CDisk();

		int DriveCount(int Fixed);

		int Map(int Drive, unsigned long StartSector);

		int Read(unsigned long Sector, void *Buffer, int Count);
		int Write(unsigned long Sector, void *Buffer, int Count);
		int Verify(unsigned long Sector, int Count);

	private:
		int Transfer(int Action, unsigned long Sector, void *Buffer, int Count);
		void Sector2CHS(unsigned long RSector, unsigned short &SectCyl, unsigned short &DrvHead);

		CDiskAccess DiskAccess;

		int DrvHeadCount;
		int DrvSectorCount;
		int Drive;
		unsigned long StartSector;
		int UseLBA;
		int DiskMapped;
};

#endif