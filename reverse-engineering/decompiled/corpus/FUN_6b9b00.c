/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b9b00; label: FUN_006b9b00
 */

void FUN_006b9b00(void)

{
  int in_ECX;
  float unaff_ESI;
  float10 fVar1;
  float fStack_fc;
  float *pfStack_f8;
  int iStack_f4;
  float fStack_ec;
  float fStack_e8;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  undefined1 auStack_a8 [132];
  uint uStack_24;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&fStack_ec;
  iStack_f4 = 0;
  pfStack_f8 = &local_e0;
  fStack_fc = DAT_02973abc;
  (**(code **)(**(int **)(in_ECX + 8) + 4))(*(undefined4 *)(in_ECX + 0xc));
  if (*(int *)(in_ECX + 0x10) != 0) {
    FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_c0);
    FUN_0061e530(*(undefined4 *)(in_ECX + 0x10),auStack_a8);
  }
  if (*(int *)(in_ECX + 0x14) != 0) {
    FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_bc);
    FUN_0061e530(*(undefined4 *)(in_ECX + 0x14),auStack_a8);
  }
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_b8);
    FUN_0061e530(*(undefined4 *)(in_ECX + 0x18),auStack_a8);
  }
  if (((*(int *)(in_ECX + 0x1c) != 0) || (*(int *)(in_ECX + 0x20) != 0)) ||
     (*(int *)(in_ECX + 0x24) != 0)) {
    FUN_005bf5e0(&stack0xffffff10,&pfStack_f8,&iStack_f4,&fStack_fc);
    if (*(int *)(in_ECX + 0x1c) != 0) {
      FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)(int)pfStack_f8 * 0.0054931640625);
      FUN_0061e530(*(undefined4 *)(in_ECX + 0x1c),auStack_a8);
    }
    if (*(int *)(in_ECX + 0x20) != 0) {
      FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)iStack_f4 * 0.0054931640625);
      FUN_0061e530(*(undefined4 *)(in_ECX + 0x20),auStack_a8);
    }
    if (*(int *)(in_ECX + 0x24) != 0) {
      FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)(int)fStack_fc * 0.0054931640625);
      FUN_0061e530(*(undefined4 *)(in_ECX + 0x24),auStack_a8);
    }
  }
  if (*(int *)(in_ECX + 0x28) != 0) {
    fStack_fc = fStack_e8 * fStack_e8 + unaff_ESI * unaff_ESI + fStack_ec * fStack_ec;
    fVar1 = (float10)FUN_005c0240();
    fStack_fc = (float)fVar1;
    FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_fc);
    FUN_0061e530(*(undefined4 *)(in_ECX + 0x28),auStack_a8);
  }
  if (*(int *)(in_ECX + 0x2c) != 0) {
    fStack_fc = fStack_d8 * fStack_d8 + local_e0 * local_e0 + fStack_dc * fStack_dc;
    fVar1 = (float10)FUN_005c0240();
    fStack_fc = (float)fVar1;
    FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_fc);
    FUN_0061e530(*(undefined4 *)(in_ECX + 0x2c),auStack_a8);
  }
  if (*(int *)(in_ECX + 0x30) != 0) {
    fStack_fc = fStack_c8 * fStack_c8 + fStack_d0 * fStack_d0 + fStack_cc * fStack_cc;
    fVar1 = (float10)FUN_005c0240();
    fStack_fc = (float)fVar1;
    FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_fc);
    FUN_0061e530(*(undefined4 *)(in_ECX + 0x30),auStack_a8);
  }
  __security_check_cookie(uStack_24 ^ (uint)&fStack_fc);
  return;
}

