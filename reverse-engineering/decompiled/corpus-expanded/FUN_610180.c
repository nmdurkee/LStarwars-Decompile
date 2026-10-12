/* Ghidra pseudocode, not original source.
 * ev_cd751bbce80615e44627de7d2a98b099122eeed2e472d985b2852ac0d20d1b25
 * Entry: 0x610180; label: FUN_00610180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610180(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x90) != 0) {
    FID_conflict__wprintf("mHostList\n");
  }
  if (*(int *)(in_ECX + 0x9c) != 0) {
    FID_conflict__wprintf("mPeerList\n");
  }
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x48) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x4c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x50) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x54) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x58) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x5c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x60) = 0xffffffff;
  *(undefined4 *)(in_ECX + 100) = 0xffffffff;
  return;
}

