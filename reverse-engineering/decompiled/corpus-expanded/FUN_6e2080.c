/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e2080; label: FUN_006e2080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2080(void)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(in_ECX + 0x660);
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x618) != 0) {
    piVar1 = (int *)(iVar3 * 0x10 + *(int *)(in_ECX + 0x61c));
    while (((piVar2 = (int *)(iVar3 * 0x10 + *(int *)(in_ECX + 0x61c)), *piVar2 != *piVar1 ||
            (piVar2[1] != piVar1[1])) || (piVar2[2] == piVar1[2]))) {
      iVar3 = iVar3 + -1;
      if (iVar3 < 0) {
        iVar3 = *(int *)(in_ECX + 0x618) + -1;
      }
      uVar4 = uVar4 + 1;
      if (*(uint *)(in_ECX + 0x618) <= uVar4) {
        return;
      }
    }
    *(int *)(in_ECX + 0x660) = iVar3;
  }
  return;
}

