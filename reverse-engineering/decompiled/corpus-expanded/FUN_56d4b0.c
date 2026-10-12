/* Ghidra pseudocode, not original source.
 * ev_312b56a8c21479f8c96fd7dc1d322c1a4486fb258981ae7e1dc00f07a4c49ce9
 * Entry: 0x56d4b0; label: FUN_0056d4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056d4b0(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x34);
    *pbVar1 = *pbVar1 ^ ((param_2 != 0) * '\x02' ^ *(byte *)(*param_1 + 0x34)) & 2;
  }
  return;
}

