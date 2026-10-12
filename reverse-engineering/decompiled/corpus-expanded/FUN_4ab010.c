/* Ghidra pseudocode, not original source.
 * ev_4df9c92bab8da1c62fff3d01a59be6c54dba6221cb99b73c04065ca1a333c731
 * Entry: 0x4ab010; label: FUN_004ab010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ab010(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) == 0) {
    FUN_004a7c00();
    iVar3 = FUN_00562150(param_1);
    if ((iVar3 == 0) && ((*(char *)(param_1 + 0x7b5) != -1 || (*(char *)(param_1 + 0x281) != '\0')))
       ) {
      iVar3 = *(int *)(param_1 + 0xca4);
      if (((*(byte *)(iVar3 + 0x5a) & 2) == 0) && (0.0 < *(float *)(iVar3 + 0x28))) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
        if ((*(float *)(iVar2 + 0x18) + *(float *)(iVar2 + 0x14)) * 0.5 < *(float *)(iVar3 + 0x28))
        {
          *(undefined2 *)(param_1 + 0x42) = 0;
        }
        else {
          *(undefined2 *)(param_1 + 0x42) = 4;
        }
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x42) = 5;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
  }
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

