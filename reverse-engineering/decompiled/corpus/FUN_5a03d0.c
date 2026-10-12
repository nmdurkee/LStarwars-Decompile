/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x5a03d0; label: FUN_005a03d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a03d0(int param_1,int param_2)

{
  float fVar1;
  
  if ((DAT_008028a8 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_008028a8)) {
    if ((*(char *)(param_1 + 0x7b5) == -1) && (param_2 != 0)) {
      FUN_005a0320();
      return;
    }
  }
  else {
    fVar1 = *(float *)(param_1 + 0x77c) - _DAT_00925018;
    *(float *)(param_1 + 0x77c) = fVar1;
    if (fVar1 <= 0.0) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
    }
  }
  return;
}

