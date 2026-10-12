/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1080; label: FUN_005b1080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1080(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 0xffffffff;
  return;
}

