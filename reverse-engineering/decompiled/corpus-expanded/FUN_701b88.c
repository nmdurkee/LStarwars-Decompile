/* Ghidra pseudocode, not original source.
 * ev_7661b65940d612abb24c352a2878817c29de5a09135c60a7ac694e4ecef30f99
 * Entry: 0x701b88; label: __lseeki64
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __lseeki64
   
   Library: Visual Studio 2005 Release */

longlong __cdecl __lseeki64(int _FileHandle,longlong _Offset,int _Origin)

{
  undefined4 *puVar1;
  int iVar2;
  int in_stack_ffffffc8;
  undefined8 local_28;
  
  if (_FileHandle == -2) {
    puVar1 = (undefined4 *)FUN_006ead72();
    *puVar1 = 0;
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
  }
  else {
    if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_029a9b2c)) {
      iVar2 = (_FileHandle & 0x1fU) * 0x38;
      if ((*(byte *)((&DAT_029a9b40)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
        puVar1 = (undefined4 *)FUN_006ead72();
        *puVar1 = 0;
        puVar1 = (undefined4 *)FUN_006ead5f();
        *puVar1 = 9;
        FUN_006e9fc2(0,0,0,0,0);
        local_28._4_4_ = 0xffffffff;
        local_28._0_4_ = 0xffffffff;
      }
      else {
        ___lock_fhandle(_FileHandle);
        if ((*(byte *)((&DAT_029a9b40)[_FileHandle >> 5] + 4 + iVar2) & 1) == 0) {
          puVar1 = (undefined4 *)FUN_006ead5f();
          *puVar1 = 9;
          puVar1 = (undefined4 *)FUN_006ead72();
          *puVar1 = 0;
          local_28 = -1;
        }
        else {
          local_28 = __lseeki64_nolock(_FileHandle,_Offset,in_stack_ffffffc8);
        }
        FUN_00701c97();
      }
      goto LAB_00701c91;
    }
    puVar1 = (undefined4 *)FUN_006ead72();
    *puVar1 = 0;
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
    FUN_006e9fc2(0,0,0,0,0);
  }
  local_28._0_4_ = 0xffffffff;
  local_28._4_4_ = 0xffffffff;
LAB_00701c91:
  return CONCAT44(local_28._4_4_,(undefined4)local_28);
}

