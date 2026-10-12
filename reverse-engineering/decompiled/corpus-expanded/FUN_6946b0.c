/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x6946b0; label: FUN_006946b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006946b0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = *(uint *)(in_ECX + 0x128);
  if (uVar2 < *(uint *)(in_ECX + 300)) {
    do {
      iVar1 = FUN_004f8b10(uVar2,param_1);
      if (iVar1 == 0) {
        return uVar2;
      }
      iVar1 = FUN_004f1ff0(uVar2);
      uVar2 = uVar2 + 1 + iVar1;
    } while (uVar2 < *(uint *)(in_ECX + 300));
  }
  return 0;
}

