/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x460530; label: FUN_00460530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00460530(int param_1,int param_2,float param_3)

{
  uint uVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int local_10;
  int local_c;
  uint local_8;
  
  local_10 = 0;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
    DAT_0087a1e4 = 1;
    return;
  case 1:
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      *(undefined4 *)(param_1 + 0x14) = 2;
      return;
    }
    break;
  case 2:
    puVar5 = (uint *)(param_2 + 0x84);
    local_c = 2;
    do {
      uVar1 = *puVar5;
      if (uVar1 == 0) {
LAB_00460642:
        local_10 = local_10 + 1;
      }
      else {
        uVar3 = 100;
        iVar4 = 0x23;
        if (99 < uVar1) {
          do {
            uVar3 = uVar3 * 10;
            iVar4 = iVar4 * 10;
          } while (uVar3 <= uVar1);
        }
        fVar2 = (float)iVar4;
        if (iVar4 < 0) {
          fVar2 = fVar2 + 4.2949673e+09;
        }
        local_8 = (uint)(longlong)ROUND(fVar2 * param_3);
        uVar3 = uVar1;
        if ((local_8 <= uVar1) && (uVar3 = local_8, local_8 == 0)) {
          uVar3 = 1;
        }
        *puVar5 = uVar1 - uVar3;
        FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),uVar3,0,0);
        if (*puVar5 == 0) goto LAB_00460642;
      }
      puVar5 = puVar5 + 1;
      local_c = local_c + -1;
    } while (local_c != 0);
    FUN_00681f40("PickupCoin",0);
    if (local_10 == 2) {
      *(undefined4 *)(param_1 + 0x14) = 3;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
      if (*(int *)(param_2 + 0x90) + *(int *)(param_2 + 0x8c) != 0) {
        FUN_00681f40("Shop_BuyCheat",0);
        return;
      }
      FUN_00547930(0x32,0,0);
    }
    break;
  case 3:
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      FUN_004838f0(param_2);
      return;
    }
  }
  return;
}

