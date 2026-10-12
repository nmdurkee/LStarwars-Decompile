/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481d70; label: FUN_00481d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00481d70(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x17);
    *pbVar1 = *pbVar1 ^ ((param_2 != 0) * '\x02' ^ *(byte *)(*param_1 + 0x17)) & 2;
  }
  return;
}

