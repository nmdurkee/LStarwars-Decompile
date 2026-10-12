/* Ghidra pseudocode, not original source.
 * ev_fb4a243913288e8884e4b26b9d3f1b2cc90d3774ba2cd7b272b490162dad9d99
 * Entry: 0x46aad0; label: FUN_0046aad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046aad0(int param_1,undefined4 param_2,short param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  float **ppfVar5;
  float10 fVar6;
  float local_5c;
  float local_58;
  undefined4 local_54;
  float *local_50 [4];
  undefined4 local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_2a;
  int local_28;
  code *local_14;
  code *local_8;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
  if ((param_1 != 0) &&
     ((*(char *)(param_1 + 0x280) == '\0' || (*(char *)(param_1 + 0x280) == '\x01')))) {
    if (DAT_008032cc != 0) {
      uVar2 = FUN_0054a510(0);
      sVar1 = FUN_00550040(0,uVar2);
      local_5c = _DAT_007fc31c;
      if (*(char *)(param_1 + 0x280) == '\0') {
        local_5c = -_DAT_007fc31c;
      }
      fVar6 = (float10)FUN_004b7120((int)*(char *)(param_1 + 0x280));
      local_58 = (float)(fVar6 + (float10)_DAT_007fc310);
      local_54 = 0x3f800000;
      if (0.0 < *(float *)(param_1 + 0xdec)) {
        FUN_0046a9f0();
      }
      puVar4 = &DAT_00802cd8;
      ppfVar5 = local_50;
      for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
        *ppfVar5 = (float *)*puVar4;
        puVar4 = puVar4 + 1;
        ppfVar5 = ppfVar5 + 1;
      }
      local_2a = 0xd0;
      local_28 = *(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xd00;
      local_50[3] = (float *)DAT_00950f60;
      local_50[1] = (float *)param_2;
      local_4 = *(undefined1 *)(param_1 + 0x280);
      local_40 = _DAT_007fc2b4;
      local_50[2] = &local_5c;
      local_34 = 0x3f800000;
      local_14 = FUN_0046a970;
      local_8 = FUN_0046aa90;
      local_3 = 1;
      local_38 = 0x2112d;
      local_2 = 7;
      iVar3 = FUN_00560b60(local_50);
      if (iVar3 != 0) {
        *(short *)(iVar3 + 0xe2) = param_3 - sVar1;
        (&DAT_00879360)[*(char *)(param_1 + 0x280)] = param_3 - sVar1;
      }
    }
    FUN_0056e320(param_2,param_1);
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f800000,0);
    FUN_0054a8a0(**(undefined4 **)(param_1 + 0xca4),0x3e4ccccd,0);
  }
  return;
}

