/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x45e430; label: FUN_0045e430
 */

float10 FUN_0045e430(int param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  
  iVar1 = *(int *)(param_1 + 0x124);
  iVar2 = *(int *)(iVar1 + 0xc);
  if ((iVar2 != 0xc) && (iVar2 != 0xb)) {
    if (iVar2 == 10) {
      if (*(float *)(iVar1 + 0x18) < 1.0) {
        return (float10)(1.0 - *(float *)(iVar1 + 0x18));
      }
    }
    else if (iVar2 == 0x13) {
      if (*(int *)(iVar1 + 0x14) == 0) {
        return (float10)1;
      }
      if ((float10)*(float *)(iVar1 + 0x18) < (float10)1) {
        return (float10)(1.0 - *(float *)(iVar1 + 0x18));
      }
      fVar3 = *(float *)(iVar1 + 0x1c) - 1.0;
      if (fVar3 < *(float *)(iVar1 + 0x18) != (fVar3 == *(float *)(iVar1 + 0x18))) {
        return (float10)((*(float *)(iVar1 + 0x18) - fVar3) / (*(float *)(iVar1 + 0x1c) - fVar3));
      }
    }
    else if (iVar1 != 0) {
      return (float10)1;
    }
  }
  return (float10)0;
}

