/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55bbf0; label: FUN_0055bbf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055bbf0(int *param_1)

{
  int iVar1;
  
  DAT_0093b280 = param_1;
  DAT_0093b26c = 0;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    while (iVar1 != 0) {
      DAT_0093b26c = DAT_0093b26c + 1;
      param_1 = param_1 + 3;
      iVar1 = *param_1;
    }
  }
  return;
}

