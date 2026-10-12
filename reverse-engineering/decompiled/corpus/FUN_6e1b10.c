/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e1b10; label: FUN_006e1b10
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

