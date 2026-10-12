/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5370; label: FUN_005e5370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005e5370(int param_1)

{
  int iVar1;
  
  if ((0 < param_1) && (iVar1 = *(int *)(DAT_0097157c + -4 + param_1 * 4), iVar1 != 0)) {
    return *(undefined4 *)(iVar1 + 0x18);
  }
  return 0;
}

