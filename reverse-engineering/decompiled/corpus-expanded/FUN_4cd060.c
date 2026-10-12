/* Ghidra pseudocode, not original source.
 * ev_8be83d5a314ed06484cc1a00e0611cd4a1346ac66c548b102291ab30b68096a0
 * Entry: 0x4cd060; label: FUN_004cd060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cd060(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x3c);
    *pbVar1 = *pbVar1 ^ (param_2 != 0 ^ *(byte *)(*param_1 + 0x3c)) & 1;
  }
  return;
}

