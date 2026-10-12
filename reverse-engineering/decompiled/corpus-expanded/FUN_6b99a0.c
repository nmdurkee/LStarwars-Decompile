/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b99a0; label: FUN_006b99a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

