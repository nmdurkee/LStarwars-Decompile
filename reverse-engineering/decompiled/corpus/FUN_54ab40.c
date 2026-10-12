/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54ab40; label: FUN_0054ab40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054ab40(float param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if ((param_1 != 0.0) && ((*(byte *)((int)param_1 + 0x1fc) & 0x80) != 0)) {
    param_1 = (ABS(*(float *)((int)param_1 + 0x6c)) /
              *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x1c)) * 0.15 + 0.25;
    if (1.0 < param_1) {
      param_1 = 1.0;
    }
    FUN_0054a850(**(undefined4 **)(iVar1 + 0xca4),param_1,0);
    iVar1 = **(int **)(iVar1 + 0xca4);
    if (iVar1 != 0) {
      FUN_00698900(iVar1,1.0 / _DAT_00925024,0,0,0);
    }
  }
  return;
}

