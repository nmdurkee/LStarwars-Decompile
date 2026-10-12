/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x626890; label: FUN_00626890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00626890(undefined4 *param_1,char *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar5 = (int)param_2;
  bVar3 = false;
  FUN_0061e5e0(param_1);
  FUN_006253f0(param_1);
  FUN_0061e650();
  if ((*(byte *)((int)param_2 + 0x4c) & 1) == 0) {
    param_2 = *(char **)((int)param_2 + 100);
  }
  else {
    param_2 = &DAT_02900b70;
  }
  if (*param_2 == '\0') {
    piVar7 = *(int **)(iVar5 + 0x80);
    if (piVar7 != (int *)0x0) {
      do {
        piVar2 = (int *)*piVar7;
        if (*(int **)(iVar5 + 0x80) == piVar7) {
          *(int **)(iVar5 + 0x80) = piVar2;
        }
        if (*piVar7 != 0) {
          *(int *)(*piVar7 + 4) = piVar7[1];
        }
        if ((int *)piVar7[1] != (int *)0x0) {
          *(int *)piVar7[1] = *piVar7;
        }
        *piVar7 = 0;
        piVar7[1] = 0;
        if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
          *param_1 = piVar7;
        }
        else {
          *(undefined4 *)param_1[1] = piVar7;
        }
        piVar7[1] = param_1[1];
        *piVar7 = 0;
        param_1[1] = piVar7;
        param_1[3] = *param_1;
        DAT_02900c84 = piVar7;
        param_1[4] = 0;
        piVar7 = piVar2;
      } while (piVar2 != (int *)0x0);
      goto LAB_006269ea;
    }
  }
  else {
    puVar1 = (undefined4 *)*param_1;
    while (puVar4 = puVar1, puVar4 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar4;
      if (((puVar4[2] != 0x14) && (puVar4[2] != 0x12)) &&
         (iVar6 = FUN_004f8a70(puVar4[9],param_2), iVar6 == 0)) {
        FUN_00619130(param_1,puVar4);
        puVar4[1] = 0;
        *puVar4 = *(undefined4 *)(iVar5 + 0x80);
        if (*(int *)(iVar5 + 0x80) != 0) {
          *(undefined4 **)(*(int *)(iVar5 + 0x80) + 4) = puVar4;
        }
        *(undefined4 **)(iVar5 + 0x80) = puVar4;
        bVar3 = true;
      }
    }
    piVar7 = *(int **)(iVar5 + 0x80);
    while (piVar2 = piVar7, piVar2 != (int *)0x0) {
      piVar7 = (int *)*piVar2;
      iVar6 = FUN_004f8a70(piVar2[9],param_2);
      if (iVar6 != 0) {
        if (*(int **)(iVar5 + 0x80) == piVar2) {
          *(int *)(iVar5 + 0x80) = *piVar2;
        }
        if (*piVar2 != 0) {
          *(int *)(*piVar2 + 4) = piVar2[1];
        }
        if ((int *)piVar2[1] != (int *)0x0) {
          *(int *)piVar2[1] = *piVar2;
        }
        *piVar2 = 0;
        piVar2[1] = 0;
        if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
          *param_1 = piVar2;
        }
        else {
          *(undefined4 *)param_1[1] = piVar2;
        }
        piVar2[1] = param_1[1];
        *piVar2 = 0;
        param_1[1] = piVar2;
        param_1[3] = *param_1;
        DAT_02900c84 = piVar2;
        param_1[4] = 0;
        bVar3 = true;
      }
    }
    if (bVar3) goto LAB_006269ea;
  }
  if ((*(byte *)(iVar5 + 0x88) & 1) != 0) {
    return 0;
  }
LAB_006269ea:
  FUN_00619060(param_1);
  *(uint *)(iVar5 + 0x88) = *(uint *)(iVar5 + 0x88) | 1;
  return 0;
}

