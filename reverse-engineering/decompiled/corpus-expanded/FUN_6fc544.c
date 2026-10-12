/* Ghidra pseudocode, not original source.
 * ev_8ae20aee9003ac5b707eda996059b97c5ee653d1eec48e1211714341787544ca
 * Entry: 0x6fc544; label: __get_osfhandle
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 2005 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  undefined4 *puVar1;
  intptr_t *piVar2;
  
  if (_FileHandle == -2) {
    puVar1 = (undefined4 *)FUN_006ead72();
    *puVar1 = 0;
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
    return -1;
  }
  if (((-1 < _FileHandle) && ((uint)_FileHandle < DAT_029a9b2c)) &&
     (piVar2 = (intptr_t *)((_FileHandle & 0x1fU) * 0x38 + (&DAT_029a9b40)[_FileHandle >> 5]),
     (*(byte *)(piVar2 + 1) & 1) != 0)) {
    return *piVar2;
  }
  puVar1 = (undefined4 *)FUN_006ead72();
  *puVar1 = 0;
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 9;
  FUN_006e9fc2(0,0,0,0,0);
  return -1;
}

