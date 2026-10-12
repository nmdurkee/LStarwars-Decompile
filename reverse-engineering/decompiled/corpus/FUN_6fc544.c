/* Ghidra analysis pseudocode, not original source.
 * ev_90cdd648c2da38df3e143f8257cf22e5b1942b178da0f5c322cb3d7ec211647f
 * Entry: 0x6fc544; label: __get_osfhandle
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

