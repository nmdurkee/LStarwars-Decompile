/* Ghidra pseudocode, not original source.
 * ev_bde5c5f75e817edbac891f5cdb42210190c78104eb02ca0378b00d023a3e9188
 * Entry: 0x6f6461; label: __write
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __write
   
   Library: Visual Studio 2005 Release */

int __cdecl __write(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  undefined4 *puVar1;
  int iVar2;
  int local_20;
  
  if (_FileHandle == -2) {
    puVar1 = (undefined4 *)FUN_006ead72();
    *puVar1 = 0;
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
  }
  else {
    if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_029a9b2c)) {
      iVar2 = (_FileHandle & 0x1fU) * 0x38;
      if ((*(byte *)((&DAT_029a9b40)[_FileHandle >> 5] + 4 + iVar2) & 1) != 0) {
        ___lock_fhandle(_FileHandle);
        if ((*(byte *)((&DAT_029a9b40)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
          puVar1 = (undefined4 *)FUN_006ead5f();
          *puVar1 = 9;
          puVar1 = (undefined4 *)FUN_006ead72();
          *puVar1 = 0;
          local_20 = -1;
        }
        else {
          local_20 = __write_nolock(_FileHandle,_Buf,_MaxCharCount);
        }
        FUN_006f6533();
        return local_20;
      }
    }
    puVar1 = (undefined4 *)FUN_006ead72();
    *puVar1 = 0;
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
    FUN_006e9fc2(0,0,0,0,0);
  }
  return -1;
}

