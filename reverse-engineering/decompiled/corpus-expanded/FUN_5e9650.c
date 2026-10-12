/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e9650; label: FUN_005e9650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005e9650(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) {
    if (param_1[1] == 0) {
      if (((param_1[2] == 0) || (iVar2 = *(int *)(param_1[2] + 0xc4), iVar2 == -1)) || (iVar2 == 0))
      goto LAB_005e96c3;
    }
    else {
      iVar2 = *(int *)(*(int *)(param_1[1] + 0x40) + 0x48);
    }
    if (iVar2 != 0) {
      if (*(int *)(*(int *)(iVar1 + 0x54) + (uint)*(ushort *)(iVar2 + 0x5c) * 4) != 0) {
        fVar4 = (float10)FUN_005ca4b0();
        return fVar4;
      }
      uVar3 = *(uint *)(iVar2 + 0x50) >> 0x16;
      if ((uVar3 != 0) && (*(int *)(iVar1 + 0x1e0) != 0)) {
        return (float10)*(ushort *)(*(int *)(iVar1 + 0x1e0) + -10 + uVar3 * 0xc);
      }
    }
  }
LAB_005e96c3:
  return (float10)0;
}

