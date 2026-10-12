/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4baad0; label: FUN_004baad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004baad0(int param_1,int param_2,int param_3,int param_4)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float local_18;
  
  if (_DAT_00950780 != 0.0) {
    return;
  }
  if (param_4 < 1) {
    return;
  }
  fVar2 = _DAT_007fc3a8 * _DAT_007fc3a4;
  uVar6 = 0;
  fVar3 = _DAT_007fc3a8 * _DAT_007fc3b0 * 0.5;
  fVar4 = _DAT_007fc3b4 * 0.5 * _DAT_007fc3a8;
  local_18 = (float)(1 - param_4) * fVar3 * 0.5;
  if (param_4 < 1) {
    return;
  }
  do {
    if ((uVar6 & 1) == 0) {
      fVar5 = _DAT_007fc3ac - fVar4;
    }
    else {
      fVar5 = fVar4 + _DAT_007fc3ac;
    }
    if (param_3 == 0) {
      if (*(char *)(uVar6 + param_2) == '\0') {
        uVar7 = 0x3f800000;
      }
      else {
        uVar7 = 0x3e800000;
      }
      sVar1 = *(short *)(param_1 + uVar6 * 2);
      uVar8 = uVar7;
    }
    else {
      sVar1 = *(short *)(param_1 + uVar6 * 2);
      uVar7 = *(undefined4 *)(param_3 + uVar6 * 4);
      uVar8 = *(undefined4 *)(param_3 + uVar6 * 4);
    }
    FUN_0055b830((int)sVar1,local_18,fVar5,0,fVar2,0xa7,uVar7,uVar8,1,0);
    local_18 = local_18 + fVar3;
    uVar6 = uVar6 + 1;
  } while ((int)uVar6 < param_4);
  return;
}

