/* Ghidra pseudocode, not original source.
 * ev_6f25f465777d6c282cbfa6a77d593954d589f2e76f9dc6caa100c42a001a6af1
 * Entry: 0x6f8422; label: __commit
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 2005 Release */

int __cdecl __commit(int _FileHandle)

{
  undefined4 *puVar1;
  HANDLE hFile;
  BOOL BVar2;
  DWORD *pDVar3;
  int iVar4;
  DWORD local_20;
  
  if (_FileHandle == -2) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
  }
  else {
    if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_029a9b2c)) {
      iVar4 = (_FileHandle & 0x1fU) * 0x38;
      if ((*(byte *)(iVar4 + 4 + (&DAT_029a9b40)[_FileHandle >> 5]) & 1) != 0) {
        ___lock_fhandle(_FileHandle);
        if ((*(byte *)(iVar4 + 4 + (&DAT_029a9b40)[_FileHandle >> 5]) & 1) != 0) {
          hFile = (HANDLE)__get_osfhandle(_FileHandle);
          BVar2 = FlushFileBuffers(hFile);
          if (BVar2 == 0) {
            local_20 = GetLastError();
          }
          else {
            local_20 = 0;
          }
          if (local_20 == 0) goto LAB_006f84e4;
          pDVar3 = (DWORD *)FUN_006ead72();
          *pDVar3 = local_20;
        }
        puVar1 = (undefined4 *)FUN_006ead5f();
        *puVar1 = 9;
        local_20 = 0xffffffff;
LAB_006f84e4:
        FUN_006f84f9();
        return local_20;
      }
    }
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
    FUN_006e9fc2(0,0,0,0,0);
  }
  return -1;
}

