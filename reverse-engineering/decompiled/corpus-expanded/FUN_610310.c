/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x610310; label: FUN_00610310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610310(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076aaa4;
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  FUN_0060df50("SessionAll");
  in_ECX[0x1f] = 0;
  in_ECX[0x10] = 2;
  in_ECX[0xf] = 0;
  DAT_028fec04 = in_ECX;
  FUN_004f1f10(in_ECX + 5,param_1);
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  return;
}

