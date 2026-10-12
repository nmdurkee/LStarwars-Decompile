/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfe20; label: FUN_005cfe20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005cfe20(int *param_1,int param_2)

{
  uint *puVar1;
  
  if (*param_1 != 0) {
    if (param_1[1] != 0) {
      puVar1 = (uint *)(*(int *)(param_1[1] + 0x40) + 0x44);
      *puVar1 = *puVar1 ^ (param_2 * 2 ^ *(uint *)(*(int *)(param_1[1] + 0x40) + 0x44)) & 2;
      return;
    }
    if (param_1[2] != 0) {
      if (param_2 != 0) {
        puVar1 = (uint *)(param_1[2] + 0xb8);
        *puVar1 = *puVar1 | 4;
        return;
      }
      puVar1 = (uint *)(param_1[2] + 0xb8);
      *puVar1 = *puVar1 & 0xfffffffb;
    }
  }
  return;
}

