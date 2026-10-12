/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2010; label: FUN_006e2010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2010(void)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  int *piVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(in_ECX + 0x660);
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x618) != 0) {
    piVar1 = (int *)(uVar2 * 0x10 + *(int *)(in_ECX + 0x61c));
    while (((piVar3 = (int *)(uVar2 * 0x10 + *(int *)(in_ECX + 0x61c)), *piVar3 != *piVar1 ||
            (piVar3[1] != piVar1[1])) || (piVar3[2] == piVar1[2]))) {
      uVar2 = uVar2 + 1;
      if (*(uint *)(in_ECX + 0x618) <= uVar2) {
        uVar2 = 0;
      }
      uVar4 = uVar4 + 1;
      if (*(uint *)(in_ECX + 0x618) <= uVar4) {
        return;
      }
    }
    *(uint *)(in_ECX + 0x660) = uVar2;
  }
  return;
}

