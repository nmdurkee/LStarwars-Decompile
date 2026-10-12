/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c0350; label: FUN_005c0350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c0350(int param_1,int param_2,int param_3,int param_4)

{
  for (; param_4 != 0; param_4 = param_4 + -1) {
    D3DXMatrixMultiply(param_1,param_2,param_3);
    param_1 = param_1 + 0x40;
    param_2 = param_2 + 0x40;
    param_3 = param_3 + 0x40;
  }
  return;
}

