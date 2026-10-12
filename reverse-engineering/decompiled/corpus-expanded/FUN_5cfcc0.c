/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5cfcc0; label: FUN_005cfcc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005cfcc0(int *param_1,int param_2)

{
  uint *puVar1;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_1[1] != 0) {
      if (param_2 != 0) {
        puVar1 = (uint *)(param_1[1] + 0x48);
        *puVar1 = *puVar1 | 0x200;
        return;
      }
      puVar1 = (uint *)(param_1[1] + 0x48);
      *puVar1 = *puVar1 & 0xfffffdff;
      return;
    }
    if (param_1[2] != 0) {
      if (param_2 != 0) {
        puVar1 = (uint *)(param_1[2] + 0xb8);
        *puVar1 = *puVar1 | 0x200;
        return;
      }
      puVar1 = (uint *)(param_1[2] + 0xb8);
      *puVar1 = *puVar1 & 0xfffffdff;
    }
  }
  return;
}

