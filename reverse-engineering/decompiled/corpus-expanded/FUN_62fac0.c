/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x62fac0; label: FUN_0062fac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062fac0(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  local_8 = 0;
  local_4 = 0;
  if ((DAT_02913110 != 1) && (DAT_029a99a8 != 0)) {
    if ((1 < param_3) && (iVar6 = 0, 0 < param_3)) {
      iVar5 = param_3 + -1;
      puVar3 = (undefined2 *)(param_4 + -2 + param_3 * 2);
      do {
        iVar4 = iVar5;
        if (*(short *)(param_4 + iVar6 * 2) == 6) {
          uVar2 = *puVar3;
          param_3 = param_3 + -1;
          puVar3 = puVar3 + -1;
          *(undefined2 *)(param_4 + iVar6 * 2) = uVar2;
          iVar4 = iVar5 + -1;
          local_8 = iVar5;
        }
        iVar5 = iVar4;
        if (*(short *)(param_4 + iVar6 * 2) == 0) {
          uVar2 = *puVar3;
          param_3 = param_3 + -1;
          puVar3 = puVar3 + -1;
          *(undefined2 *)(param_4 + iVar6 * 2) = uVar2;
          iVar5 = iVar4 + -1;
          local_4 = iVar4;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_3);
    }
    DAT_009738f0 = DAT_029a99a8;
    FUN_005cfae0(2,&DAT_029a99a8);
    uVar1 = *(undefined1 *)(param_1 + 0x1a0);
    *(undefined1 *)(param_1 + 0x1a0) = 1;
    FUN_005cfb50(1,0);
    FUN_005f4ff0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    FUN_005cfb50(0,0);
    FUN_005cfae0(0,0);
    DAT_009738f0 = 0;
    *(undefined1 *)(param_1 + 0x1a0) = uVar1;
    if (local_8 != 0) {
      *(undefined2 *)(param_4 + local_8 * 2) = 6;
    }
    if (local_4 != 0) {
      *(undefined2 *)(param_4 + local_4 * 2) = 0;
    }
  }
  return;
}

