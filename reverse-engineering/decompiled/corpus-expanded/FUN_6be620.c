/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6be620; label: FUN_006be620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006be620(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0x2c)) {
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(*(int *)(in_ECX + 0xc) + iVar2 * 8),param_1);
      if (iVar1 == 0) {
        return *(undefined4 *)(*(int *)(in_ECX + 0xc) + 4 + iVar2 * 8);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(in_ECX + 0x2c));
  }
  return param_1;
}

