/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6b99a0; label: FUN_006b99a0
 */

void FUN_006b99a0(void)

{
  int in_ECX;
  float unaff_ESI;
  undefined4 uStack_cc;
  undefined1 *puStack_c8;
  undefined4 uStack_c4;
  float fStack_bc;
  float fStack_b8;
  undefined1 local_b0 [8];
  undefined1 auStack_a8 [132];
  uint uStack_24;
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)&fStack_bc;
  uStack_c4 = 0;
  puStack_c8 = local_b0;
  uStack_cc = DAT_02973ab8;
  (**(code **)(**(int **)(in_ECX + 8) + 4))(*(undefined4 *)(in_ECX + 0xc));
  FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)unaff_ESI);
  FUN_0061e530(*(undefined4 *)(in_ECX + 0x10),auStack_a8);
  FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_bc);
  FUN_0061e530(*(undefined4 *)(in_ECX + 0x14),auStack_a8);
  FUN_004f2740(auStack_a8,&DAT_0076bd70,(double)fStack_b8);
  FUN_0061e530(*(undefined4 *)(in_ECX + 0x18),auStack_a8);
  __security_check_cookie(uStack_24 ^ (uint)&uStack_cc);
  return;
}

