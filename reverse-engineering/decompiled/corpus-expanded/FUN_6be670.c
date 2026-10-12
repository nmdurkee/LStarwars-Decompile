/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be670; label: FUN_006be670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006be670(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(in_ECX + 0x1c)) {
    iVar2 = 0;
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(*(int *)(in_ECX + 4) + iVar2),param_1);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar3 < *(int *)(in_ECX + 0x1c));
  }
  return -1;
}

