/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5ea6a0; label: FUN_005ea6a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ea6a0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_54;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar3 = 0;
  local_54 = 0;
  if (param_3 == 0) {
    if (DAT_009715a0 != 0) {
      iVar3 = 0;
      if (DAT_00966384 == 0) {
        return 0;
      }
      do {
        if (0 < (int)(&DAT_0096e550)[iVar3]) {
          return 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != DAT_00966384);
      return 0;
    }
  }
  else {
    DAT_009715a0 = 0;
  }
  uVar2 = 0;
  if (DAT_00966384 != 0) {
    do {
      local_20 = *param_1;
      local_1c = param_1[1];
      local_18 = param_1[2];
      local_30 = *param_2;
      local_2c = param_2[1];
      local_28 = param_2[2];
      iVar1 = FUN_005c7050(&local_20,&local_30);
      (&DAT_0096e550)[iVar3] = iVar1;
      if (0 < iVar1) {
        local_54 = 1;
      }
      iVar3 = iVar3 + 1;
      uVar2 = local_54;
    } while (iVar3 != DAT_00966384);
  }
  DAT_009715a0 = 1;
  return uVar2;
}

