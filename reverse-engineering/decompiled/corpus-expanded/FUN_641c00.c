/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x641c00; label: FUN_00641c00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00641c00(void)

{
  int in_ECX;
  float fStack_98;
  undefined1 *puStack_94;
  undefined4 uStack_90;
  undefined1 local_88 [116];
  uint uStack_14;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_88;
  uStack_90 = 0;
  puStack_94 = local_88;
  fStack_98 = *(float *)(in_ECX + 0x10);
  (**(code **)(**(int **)(in_ECX + 8) + 4))(*(undefined4 *)(in_ECX + 0xc));
  FUN_004f2740(&puStack_94,*(undefined4 *)(in_ECX + 0x14),(double)fStack_98);
  FUN_0061e530(*(undefined4 *)(in_ECX + 4),&puStack_94);
  __security_check_cookie(uStack_14 ^ (uint)&fStack_98);
  return;
}

