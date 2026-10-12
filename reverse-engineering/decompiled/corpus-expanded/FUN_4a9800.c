/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a9800; label: FUN_004a9800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9800(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0xca4);
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
    goto LAB_004a98a5;
  }
  FUN_004a7c00();
  iVar3 = FUN_00562150(param_1);
  if (iVar3 == 0) {
    if (*(short *)(param_1 + 0x42) != 5) {
      if (((*(byte *)(*(int *)(param_1 + 0xca4) + 0x5a) & 2) == 0) &&
         (0.0 < *(float *)(iVar2 + 0x28))) {
        FUN_004a85e0();
        if ((*(short *)(param_1 + 0x42) == 0) && ((*(byte *)(param_1 + 0xe24) & 1) != 0)) {
          *(undefined2 *)(param_1 + 0x42) = 0x40;
        }
      }
      goto LAB_004a988c;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = 5;
LAB_004a988c:
    if (*(short *)(param_1 + 0x42) != 5) goto LAB_004a98a5;
  }
  if (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x14) == 0) {
    *(undefined2 *)(param_1 + 0x42) = 1;
  }
LAB_004a98a5:
  FUN_00415370(param_1);
  sVar1 = *(short *)(param_1 + 0x42);
  if ((sVar1 != 5) &&
     (((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x20) == 0 ||
      (((sVar1 != 0x28 && (sVar1 != 0x4b)) && (sVar1 != 0x4c)))))) {
    *(undefined4 *)(param_1 + 0xdac) = 0;
    return;
  }
  *(float *)(param_1 + 0xdac) = _DAT_00925018 + *(float *)(param_1 + 0xdac);
  return;
}

