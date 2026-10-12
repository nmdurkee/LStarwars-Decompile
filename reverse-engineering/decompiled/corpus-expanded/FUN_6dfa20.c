/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6dfa20; label: FUN_006dfa20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dfa20(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_02976668 != 0) {
    do {
      FUN_006e54e0(iVar1,5,2);
      FUN_006e54e0(iVar1,6,2);
      FUN_006e54e0(iVar1,7,2);
      FUN_006e54e0(iVar1,9,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 != DAT_02976668);
  }
  return;
}

