/* Ghidra pseudocode, not original source.
 * ev_ba497556ae4cb5529d0570e30fa122537b7c12099b06aeea7aeb0dc1b59874db
 * Entry: 0x5b1260; label: FUN_005b1260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b1260(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((*(byte *)(iVar1 + 0x10) & 1) != 0) {
    *(undefined4 *)(iVar1 + 4) = 0x3f800000;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 8) = 0xbfaaaaab;
    return;
  }
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 8) = 0x40000000;
  return;
}

