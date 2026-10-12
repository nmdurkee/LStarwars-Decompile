/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b98a0; label: FUN_006b98a0
 */

void FUN_006b98a0(undefined4 param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  undefined1 *puStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined1 *puStack_c8;
  float fStack_c4;
  float afStack_b8 [2];
  undefined1 local_b0 [120];
  uint uStack_38;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)afStack_b8;
  afStack_b8[1] = 0.0;
  iVar1 = *(int *)(param_2 + 0xc);
  fStack_c4 = 0.0;
  puStack_c8 = local_b0;
  uStack_cc = DAT_02973ab8;
  uStack_d0 = *(undefined4 *)(iVar1 + 0xc);
  uStack_d4 = 0x6b98e4;
  (**(code **)(**(int **)(iVar1 + 8) + 4))();
  if (param_2 == *(int *)(iVar1 + 0x10)) {
    uStack_d4 = *(undefined4 *)(param_2 + 100);
    fStack_d8 = 9.881265e-39;
    fVar2 = (float10)FUN_004f28e0();
    fStack_c4 = (float)fVar2;
  }
  if (param_2 == *(int *)(iVar1 + 0x14)) {
    uStack_d4 = *(undefined4 *)(param_2 + 100);
    fStack_d8 = 9.881305e-39;
    fVar2 = (float10)FUN_004f28e0();
    fStack_c4 = (float)fVar2;
  }
  if (param_2 == *(int *)(iVar1 + 0x18)) {
    uStack_d4 = *(undefined4 *)(param_2 + 100);
    fStack_d8 = 9.881346e-39;
    fVar2 = (float10)FUN_004f28e0();
    fStack_c4 = (float)fVar2;
    afStack_b8[0] = fStack_c4;
  }
  uStack_d4 = 0;
  fStack_d8 = 0.0;
  afStack_b8[1] = 1.0;
  puStack_dc = &stack0xffffff40;
  (**(code **)(**(int **)(iVar1 + 8) + 8))(*(undefined4 *)(iVar1 + 0xc),DAT_02973ab8);
  FUN_004f2740(&stack0xffffff44,&DAT_0076bd70,(double)fStack_d8);
  FUN_0061e530(param_2,&stack0xffffff44);
  __security_check_cookie(uStack_38 ^ (uint)&puStack_dc);
  return;
}

