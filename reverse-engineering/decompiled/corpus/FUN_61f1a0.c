/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f1a0; label: FUN_0061f1a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0061f1a0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  float10 fVar4;
  float10 fVar5;
  
  uVar3 = DAT_02912ec4 >> 6;
  iVar1 = *(int *)(param_1 + 0x10);
  if ((*(byte *)(iVar1 + 0x38) & 1) == 0) {
    fVar4 = (float10)FUN_006ddea0();
    fVar5 = (float10)FUN_006ddeb0();
    if (DAT_02912e8c == 0) {
      _DAT_029130b4 = (float)(fVar4 * (float10)640.0) - (float)*(int *)(iVar1 + 0x14);
      _DAT_029130b0 = (float)(fVar5 * (float10)448.0) - (float)*(int *)(iVar1 + 0x18);
    }
    uVar2 = FUN_006e6b90();
    *(undefined4 *)(iVar1 + 0x14) = uVar2;
    uVar2 = FUN_006e6b90();
    *(undefined4 *)(iVar1 + 0x18) = uVar2;
  }
  return uVar3 & 1;
}

