/* Ghidra pseudocode, not original source.
 * ev_82e843d85b8a15ad0c2712a3dca0d893aca885ca51044f6184084df2488405d8
 * Entry: 0x475390; label: FUN_00475390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475390(int param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined *puVar13;
  uint local_98;
  float local_94;
  int local_90;
  int local_8c;
  char local_88 [100];
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_98;
  local_8c = FUN_006e6b90();
  local_94 = _DAT_00879b54 - -0.35;
  local_90 = 0;
  do {
    iVar9 = local_8c;
    iVar8 = local_90;
    if ((short *)(&PTR_DAT_007fa184)[local_90 * 2] == (short *)0x0) {
      local_88[0] = '\0';
    }
    else {
      FUN_004f1f10(local_88,*(undefined4 *)
                             (DAT_00926c20 + *(short *)(&PTR_DAT_007fa184)[local_90 * 2] * 4));
    }
    switch(iVar8) {
    case 0:
      if (local_88[0] != '\0') {
        FUN_004f1e80(local_88,&DAT_00759700);
      }
      iVar1 = *(int *)(&PTR_DAT_007fa100)[(&DAT_007fa188)[iVar8 * 8]];
      if (((iVar1 == 0) || (sVar6 = *(short *)(iVar1 + 0x78), sVar6 == 0)) ||
         (*(int *)(DAT_00926c20 + sVar6 * 4) == 0)) {
        FUN_004f1e80(local_88,&DAT_00755ba8);
        uVar10 = (uint)*(byte *)(iVar1 + 0x7c);
      }
      else {
        FUN_004f1e80(local_88,*(undefined4 *)(DAT_00926c20 + sVar6 * 4));
        uVar10 = (uint)*(byte *)(iVar1 + 0x7c);
      }
LAB_00475687:
      bVar12 = (&DAT_0086e0f4)[uVar10 * 0xc] == '\0';
LAB_00475692:
      if (bVar12) goto LAB_00475694;
      break;
    case 1:
      if (local_88[0] != '\0') {
        FUN_004f1e80(local_88,&DAT_00759700);
      }
      puVar13 = *(undefined **)
                 (DAT_00926c20 + *(short *)(&PTR_DAT_007fa130)[(&DAT_007fa188)[iVar8 * 8] * 3] * 4);
      if (puVar13 == (undefined *)0x0) {
        puVar13 = &DAT_00755ba8;
      }
      FUN_004f1e80(local_88,puVar13);
      if (*(int *)(&DAT_007fa134 + (&DAT_007fa188)[iVar8 * 8] * 0xc) != 0) {
        FUN_004f1e80(local_88,&DAT_007596fc);
        FUN_0054bb30(*(undefined4 *)(&DAT_007fa134 + (&DAT_007fa188)[iVar8 * 8] * 0xc),local_24);
        FUN_004f1e80(local_88,local_24);
        FUN_004f1e80(local_88,&DAT_00755d70);
      }
      break;
    case 2:
      FUN_004f1e80(local_88,&DAT_00759700);
      if (*(int *)(&DAT_007f9f5c + (&DAT_007fa188)[iVar8 * 8] * 4) == 0) {
        FUN_004f1e80(local_88,*(undefined4 *)(DAT_00926c20 + DAT_0088085c * 4));
      }
      else {
        _sprintf(local_24,"%i",*(int *)(&DAT_007f9f5c + (&DAT_007fa188)[iVar8 * 8] * 4));
        FUN_004f1e80(local_88,local_24);
        if (*(int *)(DAT_00926c20 + DAT_008807dc * 4) != 0) {
          FUN_004f1e80(local_88,&DAT_007596f8);
          FUN_004f1e80(local_88,*(undefined4 *)(DAT_00926c20 + DAT_008807dc * 4));
        }
      }
      break;
    case 3:
      FUN_004f1e80(local_88,&DAT_00759700);
      sVar6 = DAT_00880854;
      if ((&DAT_007fa188)[iVar8 * 8] != '\0') {
        sVar6 = DAT_00880844;
      }
      FUN_004f1e80(local_88,*(undefined4 *)(DAT_00926c20 + sVar6 * 4));
      if (DAT_0087956c == 0) {
        bVar12 = DAT_00879570 == 0;
        goto LAB_00475692;
      }
      break;
    case 4:
      if (*(int *)(&PTR_DAT_007fa100)[DAT_007fa188] != 0) {
        uVar10 = (uint)*(byte *)(*(int *)(&PTR_DAT_007fa100)[DAT_007fa188] + 0x7c);
        goto LAB_00475687;
      }
LAB_00475694:
      iVar9 = iVar9 / 3;
    }
    bVar5 = DAT_00921dae;
    if ((param_1 == 0) || (DAT_00879584 != iVar8)) {
      uVar10 = (uint)DAT_00921da9;
      uVar11 = (uint)DAT_0080099a;
      uVar7 = (uint)DAT_0080099b;
    }
    else {
      bVar2 = DAT_008009a2;
      bVar3 = DAT_008009a1;
      bVar4 = DAT_00921dae;
      if (DAT_009213e4 != 0) {
        bVar2 = DAT_008009a0;
        bVar3 = DAT_00921dad;
        bVar4 = DAT_0080099f;
      }
      uVar11 = (uint)bVar4;
      uVar10 = (uint)bVar3;
      uVar7 = (uint)bVar2;
      iVar8 = local_90;
      if (0.0 < _DAT_00921d70) {
        local_98 = (uint)DAT_008009a1;
        uVar10 = FUN_006e6b90();
        local_98 = (uint)bVar5;
        uVar11 = FUN_006e6b90();
        local_98 = (uint)DAT_008009a2;
        uVar7 = FUN_006e6b90();
        iVar8 = local_90;
      }
    }
    FUN_0050d910(local_88,0,local_94,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,uVar10,uVar11,
                 uVar7,0x3fd9999a,1,0,0,iVar9);
    local_94 = local_94 - 0.175;
    local_90 = iVar8 + 1;
    if (4 < local_90) {
      __security_check_cookie(local_4 ^ (uint)&local_98);
      return;
    }
  } while( true );
}

