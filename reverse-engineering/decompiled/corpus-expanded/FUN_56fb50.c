/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56fb50; label: FUN_0056fb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056fb50(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x17);
    *pbVar1 = *pbVar1 ^ ((param_2 != 0) * '\x04' ^ *(byte *)(*param_1 + 0x17)) & 4;
  }
  return;
}

