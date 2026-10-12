/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f3c80; label: FUN_005f3c80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005f3c80(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_2 != 0) && (DAT_0080b6f4 != 0)) {
    FUN_005d6900(DAT_00973940);
    puVar1 = (undefined4 *)(param_1 + 0x120);
    *(undefined4 *)(param_1 + 0x140) = 0;
    *(undefined4 *)(param_1 + 0x144) = 0;
    if (*(int *)(param_1 + 0x128) == 0) {
      *puVar1 = *(undefined4 *)(param_1 + 0x1c);
    }
    else {
      *puVar1 = *(undefined4 *)(*(int *)(param_1 + 0x128) + 0x1c);
    }
    *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) & 0xffffffea;
    _DAT_0097393c = 1;
    if ((DAT_0080b6f8 != 0) && (*(int *)(param_1 + 300) != 0)) {
      FUN_005d6f30(puVar1);
    }
    if ((*(int *)(param_1 + 0x138) == 0) || (DAT_0080ba58 == 0)) {
      if ((*(int *)(param_1 + 0x134) != 0) && (DAT_0080ba14 != 0)) {
        *(int *)(param_1 + 0x140) = param_2;
        FUN_005d8fb0(puVar1,param_1);
        *(uint *)(param_1 + 0x148) = *(uint *)(param_1 + 0x148) | 1;
      }
    }
    else {
      FUN_005eeb30(param_1);
    }
    if (DAT_0097394c == 1) {
      FUN_00603cc0(&DAT_00973760);
    }
    return puVar1;
  }
  return (undefined4 *)0x0;
}

