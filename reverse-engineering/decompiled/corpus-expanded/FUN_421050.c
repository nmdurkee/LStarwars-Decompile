/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x421050; label: FUN_00421050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00421050(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = FUN_004f1ff0(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  uVar4 = (uint)param_1 & 3;
  if ((int)uVar1 < (int)((uint)param_1 & 3)) {
    uVar4 = uVar1;
  }
  uVar2 = 0;
  uVar5 = uVar4;
  if (0 < (int)uVar4) {
    do {
      uVar2 = uVar2 << 8 | (int)(char)*param_1;
      param_1 = (uint *)((int)param_1 + 1);
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  uVar5 = uVar1 - uVar4 & 3;
  iVar3 = (uVar1 - uVar4) - uVar5;
  if (0 < iVar3) {
    iVar3 = (iVar3 - 1U >> 2) + 1;
    do {
      if ((int)uVar2 < 0) {
        uVar2 = uVar2 * 2 | 1;
      }
      else {
        uVar2 = uVar2 * 2;
      }
      uVar2 = uVar2 ^ *param_1;
      param_1 = param_1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (uVar5 != 0) {
    uVar1 = 0;
    for (; uVar5 != 0; uVar5 = uVar5 - 1) {
      uVar1 = uVar1 << 8 | (int)(char)*param_1;
      param_1 = (uint *)((int)param_1 + 1);
    }
    if ((int)uVar2 < 0) {
      return (uVar2 * 2 | 1) ^ uVar1;
    }
    uVar2 = uVar2 * 2 ^ uVar1;
  }
  return uVar2;
}

