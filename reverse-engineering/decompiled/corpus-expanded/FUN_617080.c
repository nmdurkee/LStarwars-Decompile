/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x617080; label: FUN_00617080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617080(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  iVar1 = DAT_02973bac;
  local_8 = 0;
  if (0 < DAT_02973bac) {
    do {
      puVar2 = (undefined4 *)FUN_006be7f0(local_8);
      if ((puVar2 != (undefined4 *)0x0) && (puVar2[5] != 0)) {
        FUN_006118f0(*puVar2);
        local_c = 0;
        iVar3 = (**(code **)(*(int *)puVar2[5] + 0x14))(0);
        while (iVar3 != 0) {
          iVar4 = (**(code **)(*(int *)puVar2[5] + 0x2c))(iVar3);
          if (iVar4 == 0) {
            iVar4 = FUN_00612a50();
            (**(code **)(*(int *)puVar2[5] + 0x28))(iVar3,iVar4);
          }
          FUN_00616a80(iVar3,puVar2,iVar4);
          iVar3 = (**(code **)(*(int *)puVar2[5] + 0x14))(iVar3);
          local_c = local_c + 1;
        }
        FUN_006118f0(local_c,*puVar2);
      }
      local_8 = local_8 + 1;
    } while (local_8 < iVar1);
  }
  return;
}

