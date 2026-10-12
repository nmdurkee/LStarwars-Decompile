/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5350; label: FUN_005e5350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e5350(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((0 < param_1) && (iVar2 = *(int *)(DAT_0097157c + -4 + param_1 * 4), iVar2 != 0)) {
    piVar1 = (int *)(iVar2 + 0x18);
    *piVar1 = *piVar1 + -1;
  }
  return;
}

