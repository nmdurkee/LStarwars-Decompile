/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x628970; label: FUN_00628970
 */

void FUN_00628970(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  
  DAT_029130d0 = (undefined4 *)
                 FUN_00619250(*(int *)(param_1 + 0x14) + 10,*(int *)(param_1 + 0x18) + 0x28,0xb4,
                              0xfa,*(undefined4 *)(param_1 + 0x2c),&LAB_00624e10,"GradPick Adjust");
  if (DAT_029130d0 == (undefined4 *)0x0) {
    return;
  }
  if (*(int *)(unaff_ESI + 8) == 8) {
    DAT_02900c84 = (undefined4 *)FUN_00624e20();
    if (DAT_02900c84 != (undefined4 *)0x0) {
      DAT_02900c84[2] = 0xb;
      DAT_02900c84[0xf] = FUN_0061b060;
      DAT_02900c84[0x10] = FUN_0061bb10;
    }
    if (*(int *)(unaff_ESI + 0x50) == 0) goto LAB_00628a9d;
    iVar4 = *(int *)(unaff_ESI + 0x50);
    fVar1 = *(float *)(iVar4 + 0x10);
    uVar2 = *(undefined4 *)(iVar4 + 0x14);
    uVar3 = *(undefined4 *)(iVar4 + 0x18);
    DAT_02900c84[0x15] = fVar1;
    DAT_02900c84[0x16] = uVar2;
  }
  else {
    if (*(int *)(unaff_ESI + 8) == 9) {
      DAT_02900c84 = (undefined4 *)FUN_00627a80();
      goto LAB_00628a9d;
    }
    DAT_02900c84 = (undefined4 *)FUN_00624e20();
    if (*(int *)(unaff_ESI + 0x50) == 0) goto LAB_00628a9d;
    iVar4 = *(int *)(unaff_ESI + 0x50);
    fVar1 = *(float *)(iVar4 + 0x10);
    uVar2 = *(undefined4 *)(iVar4 + 0x14);
    uVar3 = *(undefined4 *)(iVar4 + 0x18);
    DAT_02900c84[0x15] = fVar1;
    DAT_02900c84[0x16] = uVar2;
  }
  DAT_02900c84[0x17] = uVar3;
  DAT_02900c84[0x13] = fVar1 / 360.0;
  DAT_02900c84[0x14] = uVar3;
LAB_00628a9d:
  puVar5 = DAT_029130d0;
  if ((undefined4 *)DAT_029130d0[1] == (undefined4 *)0x0) {
    *DAT_029130d0 = DAT_02900c84;
  }
  else {
    *(undefined4 *)DAT_029130d0[1] = DAT_02900c84;
  }
  DAT_02900c84[1] = puVar5[1];
  *DAT_02900c84 = 0;
  puVar5[1] = DAT_02900c84;
  puVar5[3] = *puVar5;
  puVar5[4] = 0;
  DAT_02900c84 = (undefined4 *)FUN_00627a80();
  puVar5 = DAT_029130d0;
  if ((undefined4 *)DAT_029130d0[1] == (undefined4 *)0x0) {
    *DAT_029130d0 = DAT_02900c84;
  }
  else {
    *(undefined4 *)DAT_029130d0[1] = DAT_02900c84;
  }
  DAT_02900c84[1] = puVar5[1];
  *DAT_02900c84 = 0;
  puVar5[1] = DAT_02900c84;
  puVar5[3] = *puVar5;
  puVar5[4] = 0;
  DAT_02900c84 = (undefined4 *)FUN_00627a80();
  puVar5 = DAT_029130d0;
  if ((undefined4 *)DAT_029130d0[1] == (undefined4 *)0x0) {
    *DAT_029130d0 = DAT_02900c84;
  }
  else {
    *(undefined4 *)DAT_029130d0[1] = DAT_02900c84;
  }
  DAT_02900c84[1] = puVar5[1];
  *DAT_02900c84 = 0;
  puVar5[1] = DAT_02900c84;
  puVar5[3] = *puVar5;
  puVar5[4] = 0;
  DAT_02900c84 = (undefined4 *)FUN_00627a80();
  puVar5 = DAT_029130d0;
  if ((undefined4 *)DAT_029130d0[1] == (undefined4 *)0x0) {
    *DAT_029130d0 = DAT_02900c84;
  }
  else {
    *(undefined4 *)DAT_029130d0[1] = DAT_02900c84;
  }
  DAT_02900c84[1] = puVar5[1];
  *DAT_02900c84 = 0;
  puVar5[1] = DAT_02900c84;
  puVar5[3] = *puVar5;
  puVar5[4] = 0;
  DAT_02900c84[2] = *(undefined4 *)(unaff_ESI + 8);
  DAT_02900c84 = (undefined4 *)FUN_00627a80();
  if (DAT_02900c84 != (undefined4 *)0x0) {
    DAT_02900c84[0x10] = FUN_00619800;
  }
  puVar5 = DAT_029130d0;
  if ((undefined4 *)DAT_029130d0[1] == (undefined4 *)0x0) {
    *DAT_029130d0 = DAT_02900c84;
  }
  else {
    *(undefined4 *)DAT_029130d0[1] = DAT_02900c84;
  }
  DAT_02900c84[1] = puVar5[1];
  *DAT_02900c84 = 0;
  puVar5[3] = *puVar5;
  puVar5[1] = DAT_02900c84;
  puVar5[4] = 0;
  DAT_02900c84[2] = *(undefined4 *)(unaff_ESI + 8);
  FUN_006279b0(param_1,puVar5);
  return;
}

