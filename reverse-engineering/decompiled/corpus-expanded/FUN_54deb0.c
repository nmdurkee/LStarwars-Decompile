/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54deb0; label: FUN_0054deb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054deb0(int *param_1,int param_2)

{
  byte *pbVar1;
  
  if (param_1 != (int *)0x0) {
    pbVar1 = (byte *)(*param_1 + 0x1e);
    *pbVar1 = *pbVar1 ^ ((param_2 != 0) * '\x02' ^ *(byte *)(*param_1 + 0x1e)) & 2;
  }
  return;
}

