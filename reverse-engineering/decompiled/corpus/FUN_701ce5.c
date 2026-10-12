/* Ghidra analysis pseudocode, not original source.
 * ev_fd7ef47e89ee49e811b9d461fb0d02a426b46bfab1eb980b5176b797a15dd7e8
 * Entry: 0x701ce5; label: __isatty
 */

/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 2005 Release */

int __cdecl __isatty(int _FileHandle)

{
  undefined4 *puVar1;
  
  if (_FileHandle == -2) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
    return 0;
  }
  if ((-1 < _FileHandle) && ((uint)_FileHandle < DAT_029a9b2c)) {
    return *(byte *)((&DAT_029a9b40)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 0x38) & 0x40;
  }
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 9;
  FUN_006e9fc2(0,0,0,0,0);
  return 0;
}

