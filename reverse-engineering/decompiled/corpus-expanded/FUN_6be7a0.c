/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be7a0; label: FUN_006be7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006be7a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(in_ECX + 0x24)) {
    iVar2 = 0;
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(*(int *)(in_ECX + 8) + iVar2),param_1);
      if (iVar1 == 0) {
        return *(int *)(in_ECX + 8) + iVar3 * 0x18;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar3 < *(int *)(in_ECX + 0x24));
  }
  return 0;
}

