/* Ghidra pseudocode, not original source.
 * ev_1147004b9dc166d1e84637369286a2c1a549644e29d4b7aad5b4a967d59cac62
 * Entry: 0x5a5b70; label: FUN_005a5b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a5b70(int param_1,byte param_2)

{
  *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) & 0xfffffdff;
  *(byte *)(param_1 + 0xd0) = *(byte *)(param_1 + 0xd0) | '\x01' << (param_2 & 0x1f);
  if ((*(uint *)(param_1 + 200) & 0x20000000) == 0) {
    *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) | 0x2000100;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_0054a8a0(**(undefined4 **)(*(int *)(param_1 + 0x30) + 0xca4),0x3dcccccd,0);
  }
  return;
}

