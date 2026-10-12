/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545760; label: FUN_00545760
 */

void FUN_00545760(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float10 fVar6;
  
  puVar1 = (undefined4 *)(param_1 + 0x30);
  fVar6 = (float10)FUN_00673820(puVar1,0,0x40a00000,0);
  *(float *)(param_1 + 0x34) = (float)fVar6;
  FUN_005be2d0(DAT_0292fdc0,DAT_0292fdbc);
  fVar6 = (float10)FUN_005c0240(DAT_0292fdbc * DAT_0292fdbc + DAT_0292fdc0 * DAT_0292fdc0);
  FUN_005be2d0(DAT_0292fdb8,(float)fVar6);
  uVar2 = *puVar1;
  uVar3 = *(undefined4 *)(param_1 + 0x34);
  uVar4 = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *puVar1 = 0;
  uVar5 = FUN_006e6b90();
  FUN_005b5160(param_1,uVar5);
  uVar5 = FUN_006e6b90();
  FUN_005b4cf0(param_1,uVar5);
  *puVar1 = uVar2;
  *(undefined4 *)(param_1 + 0x34) = uVar3;
  *(undefined4 *)(param_1 + 0x38) = uVar4;
  return;
}

