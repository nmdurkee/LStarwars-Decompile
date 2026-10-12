/* Ghidra analysis pseudocode, not original source.
 * ev_8dba402bb7d22455a765fa1be408776d0f2383442396bc16910bcc92f9a08d40
 * Entry: 0x7022ca; label: __set_error_mode
 */

/* Library Function - Single Match
    __set_error_mode
   
   Library: Visual Studio 2005 Release */

int __cdecl __set_error_mode(int _Mode)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (-1 < _Mode) {
    if (_Mode < 3) {
      iVar1 = DAT_0297c190;
      DAT_0297c190 = _Mode;
      return iVar1;
    }
    if (_Mode == 3) {
      return DAT_0297c190;
    }
  }
  puVar2 = (undefined4 *)FUN_006ead5f();
  *puVar2 = 0x16;
  FUN_006e9fc2(0,0,0,0,0);
  return -1;
}

