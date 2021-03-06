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

#include "Common.h"

/* String: high level string management
 * ------------------------------------
 * Basic usage:
 *   String strFoo = "Scratch"; // Scratch
 *   String strBar = "lib" + strFoo.ToLower(); // libscratch
 *   String strTest = strBar.Replace("libs", "S") + "!"; // Scratch!
 *
 *   StackArray<String> astrParse = strTest.Split("c");
 *   ASSERT(astrParse.Count() == 3);
 *   ASSERT(astrParse[0] == "S");
 *   ASSERT(astrParse[1] == "rat");
 *   ASSERT(astrParse[2] == "h");
 */
#include "CString.h"

/* Filename: high level string management with filename functions
 * --------------------------------------------------------------
 * Basic usage:
 *   Filename fnmFoo = "foo/bar/test.c";
 *   String strExtension = fnmFoo.Extension();
 *   String strPath = fnmFoo.Path();
 *   String strFilename = fnmFoo.Filename();
 *   ASSERT(strExtension == "c");
 *   ASSERT(strPath == "foo/bar/");
 *   ASSERT(strFilename == "test.c");
 */
#include "CFilename.h"

/* StackArray: high level array management
 * ---------------------------------------
 * Basic usage:
 *   StackArray<int> aiTest;
 *   aiTest.Push() = 5;
 *   aiTest.Push() = 10;
 *   aiTest.Push() = 123;
 *   ASSERT(aiTest[0] == 5);
 *   ASSERT(aiTest.Pop() == 123);
 *   ASSERT(aiTest.Count() == 2);
 */
#include "CStackArray.h"

/* Dictionary: high level table management
 * ---------------------------------------
 * Basic usage:
 *   Dictionary<String, String> dstrTest;
 *   dstrTest.Add("Name", "libscratch");
 *   dstrTest["Author"] = "Angelo Geels";
 */
#include "CDictionary.h"

/* FileStream: high level file stream management
 * ---------------------------------------------
 * Basic usage:
 *   FileStream fs;
 *   fs.Open("test.bin", "r+");
 *   INDEX iTest;
 *   fs >> iTest;
 *   fs << iTest * 2;
 *   fs.Close();
 */
#include "CFileStream.h"

/* MemoryStream: high level memory stream management
 * -------------------------------------------------
 * Basic usage:
 *   MemoryStream ms;
 *   ms << INDEX(5);
 *   FileStream fs;
 *   fs.Open("test.bin", "w");
 *   fs << ms.Size();
 *   fs << ms;
 */
#include "CMemoryStream.h"

/* NetworkStream: high level network connections management
 * ---------------------------------------------------------
 * Basic usage:
 *   NetworkStream ns;
 *   ns.Connect("127.0.0.1", 1234);
 *   ns << INDEX(5);
 *   INDEX iResult;
 *   ns >> iResult;
 *   ns.Close();
 */
#include "CNetworkStream.h"

/* Mutex: high level mutex management
 * ----------------------------------
 * Basic usage:
 *   Mutex mutex;
 *   mutex.Lock();
 *   // do some work
 *   mutex.Unlock();
 * Or:
 *   Mutex mutex;
 *   MutexWait(mutex);
 *   // do some work
 */
#include "CMutex.h"

/* Exception: high level exception management
 * ------------------------------------------
 * Basic usage:
 *   try {
 *     throw Exception("Found %d items", 20);
 *   } catch(Exception &ex) {
 *     // do something with ex.Message
 *   }
 */
#include "CException.h"
