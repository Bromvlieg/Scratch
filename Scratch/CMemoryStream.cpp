/*  libscratch - Multipurpose objective C++ library.
    
    Copyright (c) 2015 Angelo Geels <spansjh@gmail.com>
    
    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:
    
    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.
    
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/

#include "CMemoryStream.h"

SCRATCH_NAMESPACE_BEGIN;

MemoryStream::MemoryStream(void)
{
  strm_pubBuffer = NULL;
  strm_ulPosition = 0;
  strm_ulSize = 0;
  strm_ulUsed = 0;
  AllocateMoreMemory(1024);
}

MemoryStream::MemoryStream(const MemoryStream &copy)
{
  strm_pubBuffer = NULL;
  strm_ulPosition = 0;
  strm_ulSize = 0;
  strm_ulUsed = 0;
  AllocateMoreMemory(copy.strm_ulSize);
  memcpy(strm_pubBuffer, copy.strm_pubBuffer, copy.strm_ulSize);
  strm_ulPosition = copy.strm_ulPosition;
  strm_ulUsed = copy.strm_ulUsed;
}

MemoryStream::~MemoryStream(void)
{
  delete[] strm_pubBuffer;
}

ULONG MemoryStream::Size()
{
  return strm_ulUsed;
}

ULONG MemoryStream::Location()
{
  return strm_ulPosition;
}

void MemoryStream::Seek(ULONG ulPos, INDEX iOrigin)
{
  switch(iOrigin) {
  case SEEK_CUR: strm_ulPosition += ulPos; break;
  case SEEK_END: strm_ulPosition = Size() + ulPos; break;
  case SEEK_SET: strm_ulPosition = ulPos; break;
  }
}

BOOL MemoryStream::AtEOF()
{
  return Size() - Location() > 0;
}

void MemoryStream::Write(const void* p, ULONG iLen)
{
  // check if we need a larger buffer
  if(strm_ulPosition + iLen >= strm_ulSize) {
    AllocateMoreMemory(Max<ULONG>(iLen, 1024));
  }

  // copy over memory
  memcpy(strm_pubBuffer + strm_ulPosition, p, iLen);

  // increase position
  strm_ulPosition += iLen;

  // update used counter
  strm_ulUsed = Max<ULONG>(strm_ulPosition, strm_ulUsed);
}

int MemoryStream::Read(void* pDest, ULONG iLen)
{
  ULONG ulStart = strm_ulPosition;

  // increase position
  strm_ulPosition += iLen;

  // check boundaries
  if(strm_ulPosition > Size()) {
    strm_ulPosition = Size();
  }

  ULONG ulRealLength = strm_ulPosition - ulStart;

  // copy data to destination
  memcpy(pDest, strm_pubBuffer + ulStart, ulRealLength);

  return ulRealLength;
}

void MemoryStream::AllocateMoreMemory(ULONG ctBytes)
{
  ASSERT(ctBytes > 0);

  // create new buffer and remember old one
  UBYTE* pubNewBuffer = new UBYTE[strm_ulSize + ctBytes];
  UBYTE* pubOldBuffer = strm_pubBuffer;
  
  // if there's old memory to copy
  if(pubOldBuffer != NULL && strm_ulSize > 0) {
    memcpy(pubNewBuffer, pubOldBuffer, strm_ulSize);
  }

  // increase the size count
  strm_ulSize += ctBytes;

  // set the new buffer pointer
  strm_pubBuffer = pubNewBuffer;

  // delete old memory
  if(pubOldBuffer != NULL) {
    delete[] pubOldBuffer;
  }
}

SCRATCH_NAMESPACE_END;
