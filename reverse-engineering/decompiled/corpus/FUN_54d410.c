/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54d410; label: FUN_0054d410
 */

int FUN_0054d410(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (DAT_00802874 == -1) {
    return 0;
  }
  iVar2 = 0;
  iVar1 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if ((((*(uint *)(iVar1 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) &&
         (param_2 != iVar1)) {
        if ((*(char *)(iVar1 + 0x7b5) == DAT_00802874) && (*(int *)(iVar1 + 0x798) == param_1)) {
          return iVar1;
        }
        if (((param_3 != 0) && (*(int *)(iVar1 + 0x424) == param_3)) &&
           ((DAT_00802838 != -1 && (*(char *)(iVar1 + 0x7b5) == DAT_00802838)))) {
          return iVar1;
        }
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10d8;
    } while (iVar2 < DAT_0093d500);
  }
  return 0;
}

