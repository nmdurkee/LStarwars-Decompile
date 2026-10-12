/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c6e0; label: FUN_0046c6e0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0046c6e0(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_0055f1d0(param_1);
  if (((iVar2 == 0) && ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x8000) == 0)
      ) && (*(int *)(param_1 + 0x7fc) != 0)) {
    if (param_2 == 1) {
      uVar3 = (-(uint)(DAT_00951154 != 0) & 23000) + 2000;
    }
    else if (param_2 == 2) {
      uVar3 = (-(uint)(DAT_00951154 != 0) & 0x2cec) + 1000;
    }
    else {
      uVar3 = 0;
    }
    iVar2 = FUN_0056e160(0x2c);
    if (iVar2 != 0) {
      if (PTR_DAT_007f3a14[DAT_00856c0c * 4] == '\x01') {
        uVar3 = uVar3 * 2;
      }
      else if (PTR_DAT_007f3a14[DAT_00856c0c * 4] == -1) {
        uVar3 = uVar3 >> 1;
      }
    }
    puVar1 = *(uint **)(param_1 + 0x7fc);
    if (*puVar1 < uVar3) {
      uVar3 = *puVar1;
      *puVar1 = 0;
    }
    else if (uVar3 != 0) {
      *puVar1 = *puVar1 - uVar3;
    }
    iVar2 = FUN_0056e0f0(0x7c);
    if ((iVar2 != 0) || (0.0 < _DAT_00925040)) {
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0;
}

