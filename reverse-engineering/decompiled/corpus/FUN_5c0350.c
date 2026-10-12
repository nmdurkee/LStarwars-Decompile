/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c0350; label: FUN_005c0350
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

