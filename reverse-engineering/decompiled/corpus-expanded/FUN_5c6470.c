/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6470; label: FUN_005c6470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005c6470(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = DAT_00973850;
  if (0 < DAT_0097384c) {
    do {
      if (param_1 == *piVar2) {
        return DAT_00973850 + iVar1 * 10;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 10;
    } while (iVar1 < DAT_0097384c);
  }
  return (int *)0x0;
}

