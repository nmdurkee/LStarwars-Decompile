/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x4436e0; label: FUN_004436e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004436e0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = FUN_004f8b10(param_2,"baddy");
  if ((iVar1 != 0) && (iVar1 = FUN_004f8b10(param_2,"baddie"), iVar1 != 0)) {
    iVar1 = FUN_004f8b10(param_2,"goody");
    if ((iVar1 != 0) && (iVar1 = FUN_004f8b10(param_2,"goodie"), iVar1 != 0)) {
      iVar1 = FUN_004f8b10(param_2,"goodybaddy");
      if ((iVar1 != 0) && (iVar1 = FUN_004f8b10(param_2,"goodiebaddie"), iVar1 != 0)) {
        return 0;
      }
      return 2;
    }
    return 1;
  }
  return 0xffffffff;
}

