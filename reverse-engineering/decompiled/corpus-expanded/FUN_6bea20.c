/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6bea20; label: FUN_006bea20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_006bea20(void)

{
  int in_EDX;
  int unaff_ESI;
  int unaff_EDI;
  bool bVar1;
  
  bVar1 = true;
  if ((*(uint *)(unaff_EDI + 0x1c) & 0x400000) == 0) {
    bVar1 = (*(uint *)(in_EDX + 0x1c) & 0x10000000) == 0;
    if ((((int)*(uint *)(in_EDX + 0x1c) < 0) && (unaff_ESI != 0)) &&
       (*(int *)(unaff_ESI + *(int *)(in_EDX + 0xc) * 4) == -1)) {
      bVar1 = false;
    }
  }
  else if ((*(uint *)(in_EDX + 0x1c) & 0x400000) != 0) {
    return false;
  }
  return bVar1;
}

