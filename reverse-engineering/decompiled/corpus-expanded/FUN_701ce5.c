/* Ghidra pseudocode, not original source.
 * ev_7661b65940d612abb24c352a2878817c29de5a09135c60a7ac694e4ecef30f99
 * Entry: 0x701ce5; label: __isatty
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

