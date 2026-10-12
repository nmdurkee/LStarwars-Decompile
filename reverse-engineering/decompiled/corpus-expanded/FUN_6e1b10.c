/* Ghidra pseudocode, not original source.
 * ev_d1297140d064b8e6ed3605b22cb50648192a7104d7ee6940892434500fccfde8
 * Entry: 0x6e1b10; label: FUN_006e1b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006e1b10(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  if (((uVar1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) {
    return 1;
  }
  uVar2 = *param_2;
  if ((((uVar2 != 0) || (param_2[1] != 0)) || (param_2[2] != 0)) && (uVar2 <= uVar1)) {
    if (uVar1 != uVar2) {
      return 1;
    }
    if (param_2[1] <= param_1[1]) {
      if (param_1[1] != param_2[1]) {
        return 1;
      }
      if (param_2[2] <= param_1[2]) {
        return (uint)(param_2[2] < param_1[2]);
      }
    }
  }
  return 0xffffffff;
}

