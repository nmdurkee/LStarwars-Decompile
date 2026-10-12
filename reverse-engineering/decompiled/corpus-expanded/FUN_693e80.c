/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x693e80; label: FUN_00693e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00693e80(int param_1)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  do {
    if (param_1 == 1 << ((byte)iVar1 & 0x1f)) {
      if (iVar1 == -1) {
        return 0;
      }
      return *(undefined4 *)(in_ECX + 0xc + iVar1 * 4);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return 0;
}

