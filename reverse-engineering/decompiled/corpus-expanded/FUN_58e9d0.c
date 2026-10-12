/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58e9d0; label: FUN_0058e9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0058e9d0(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  if (_DAT_00802860 == -1) {
    return 0;
  }
  piVar2 = &DAT_0093d7f0;
  while ((((iVar1 = *piVar2, iVar1 == 0 || ((*(byte *)(iVar1 + 0x1fc) & 0x80) == 0)) ||
          (*(char *)(iVar1 + 0x7b5) != _DAT_00802860)) || (*(int *)(iVar1 + 0x798) != unaff_ESI))) {
    piVar2 = piVar2 + 1;
    if (0x93d80f < (int)piVar2) {
      return 0;
    }
  }
  return iVar1;
}

