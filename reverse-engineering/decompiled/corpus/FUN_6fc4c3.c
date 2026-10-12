/* Ghidra analysis pseudocode, not original source.
 * ev_90cdd648c2da38df3e143f8257cf22e5b1942b178da0f5c322cb3d7ec211647f
 * Entry: 0x6fc4c3; label: __free_osfhnd
 */

/* Library Function - Single Match
    __free_osfhnd
   
   Library: Visual Studio 2005 Release */

int __cdecl __free_osfhnd(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  DWORD nStdHandle;
  
  if ((-1 < param_1) && ((uint)param_1 < DAT_029a9b2c)) {
    iVar3 = (param_1 & 0x1fU) * 0x38;
    piVar1 = (int *)((&DAT_029a9b40)[param_1 >> 5] + iVar3);
    if (((*(byte *)(piVar1 + 1) & 1) != 0) && (*piVar1 != -1)) {
      if (DAT_00829580 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_006fc521;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,(HANDLE)0x0);
      }
LAB_006fc521:
      *(undefined4 *)(iVar3 + (&DAT_029a9b40)[param_1 >> 5]) = 0xffffffff;
      return 0;
    }
  }
  puVar2 = (undefined4 *)FUN_006ead5f();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_006ead72();
  *puVar2 = 0;
  return -1;
}

