/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x693e10; label: FUN_00693e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00693e10(void)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(in_ECX + 0x1c) != 0) {
    iVar1 = (*(int *)(in_ECX + 0x20) + 1) % *(int *)(in_ECX + 0x1c);
    *(int *)(in_ECX + 0x20) = iVar1;
    *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(*(int *)(in_ECX + 0x18) + iVar1 * 4);
    return;
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  return;
}

