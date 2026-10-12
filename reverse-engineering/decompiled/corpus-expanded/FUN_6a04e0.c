/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x6a04e0; label: FUN_006a04e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a04e0(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  
  iVar5 = *(int *)(param_1 + 0x1c);
  if (iVar5 == 0) {
    return 0xffffff7f;
  }
  iVar1 = FUN_006a3bb0();
  iVar7 = 0;
  *(int *)(iVar5 + 0x18) = iVar1 + 1;
  if (0 < iVar1 + 1) {
    puVar6 = (undefined4 *)(iVar5 + 0x720);
    do {
      pvVar2 = _calloc(1,0x34);
      *puVar6 = pvVar2;
      iVar1 = FUN_006a9450();
      if (iVar1 != 0) goto LAB_006a0740;
      iVar7 = iVar7 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar7 < *(int *)(iVar5 + 0x18));
  }
  iVar1 = FUN_006a3bb0();
  iVar7 = 0;
  if (0 < iVar1 + 1) {
    do {
      iVar3 = FUN_006a3bb0();
      if (iVar3 != 0) goto LAB_006a0740;
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar1 + 1);
  }
  iVar1 = FUN_006a3bb0();
  iVar7 = 0;
  *(int *)(iVar5 + 0x10) = iVar1 + 1;
  if (0 < iVar1 + 1) {
    piVar8 = (int *)(iVar5 + 0x420);
    do {
      iVar1 = FUN_006a3bb0();
      piVar8[-0x40] = iVar1;
      if ((iVar1 < 0) || (1 < iVar1)) goto LAB_006a0740;
      iVar1 = (**(code **)((&PTR_DAT_00817010)[iVar1] + 4))(param_1);
      *piVar8 = iVar1;
      if (iVar1 == 0) goto LAB_006a0740;
      iVar7 = iVar7 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar7 < *(int *)(iVar5 + 0x10));
  }
  iVar1 = FUN_006a3bb0();
  iVar7 = 0;
  *(int *)(iVar5 + 0x14) = iVar1 + 1;
  if (0 < iVar1 + 1) {
    piVar8 = (int *)(iVar5 + 0x620);
    do {
      iVar1 = FUN_006a3bb0();
      piVar8[-0x40] = iVar1;
      if ((iVar1 < 0) || (2 < iVar1)) goto LAB_006a0740;
      iVar1 = (**(code **)((&PTR_DAT_00817018)[iVar1] + 4))(param_1);
      *piVar8 = iVar1;
      if (iVar1 == 0) goto LAB_006a0740;
      iVar7 = iVar7 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar7 < *(int *)(iVar5 + 0x14));
  }
  iVar1 = FUN_006a3bb0();
  iVar7 = 0;
  *(int *)(iVar5 + 0xc) = iVar1 + 1;
  if (0 < iVar1 + 1) {
    piVar8 = (int *)(iVar5 + 0x220);
    do {
      iVar1 = FUN_006a3bb0();
      piVar8[-0x40] = iVar1;
      if ((iVar1 < 0) || (0 < iVar1)) goto LAB_006a0740;
      iVar1 = (**(code **)((&PTR_PTR_00817024)[iVar1] + 4))(param_1);
      *piVar8 = iVar1;
      if (iVar1 == 0) goto LAB_006a0740;
      iVar7 = iVar7 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar7 < *(int *)(iVar5 + 0xc));
  }
  iVar1 = FUN_006a3bb0();
  iVar7 = 0;
  *(int *)(iVar5 + 8) = iVar1 + 1;
  if (0 < iVar1 + 1) {
    piVar8 = (int *)(iVar5 + 0x20);
    do {
      pvVar2 = _calloc(1,0x10);
      *piVar8 = (int)pvVar2;
      uVar4 = FUN_006a3bb0();
      *(undefined4 *)*piVar8 = uVar4;
      uVar4 = FUN_006a3bb0();
      *(undefined4 *)(*piVar8 + 4) = uVar4;
      uVar4 = FUN_006a3bb0();
      *(undefined4 *)(*piVar8 + 8) = uVar4;
      uVar4 = FUN_006a3bb0();
      *(undefined4 *)(*piVar8 + 0xc) = uVar4;
      iVar1 = *piVar8;
      if (((0 < *(int *)(iVar1 + 4)) || (0 < *(int *)(iVar1 + 8))) ||
         (*(int *)(iVar5 + 0xc) <= *(int *)(iVar1 + 0xc))) goto LAB_006a0740;
      iVar7 = iVar7 + 1;
      piVar8 = piVar8 + 1;
    } while (iVar7 < *(int *)(iVar5 + 8));
  }
  iVar5 = FUN_006a3bb0();
  if (iVar5 == 1) {
    return 0;
  }
LAB_006a0740:
  FUN_006a0180(param_1);
  return 0xffffff7b;
}

