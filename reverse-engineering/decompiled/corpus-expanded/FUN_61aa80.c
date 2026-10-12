/* Ghidra pseudocode, not original source.
 * ev_abcfc2048e1dc22b455e7f936aed00990aa3046186fb3e66e554800088b2998e
 * Entry: 0x61aa80; label: FUN_0061aa80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0061aa80(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  bool bVar8;
  
  iVar3 = param_4;
  FUN_005d0e80();
  iVar4 = FUN_006e6b90();
  uVar6 = iVar4 >> 2;
  FUN_005d0e80(DAT_02912b38);
  FUN_005d0eb0(DAT_02912b38);
  iVar5 = FUN_006e6b90();
  bVar8 = DAT_02912eb8 == 0;
  *(int *)(param_2 + 0x1c) = param_3;
  *(int *)(param_2 + 0x20) = param_4;
  if (((bVar8) &&
      (FUN_005db880(param_3 << 4,param_4 * 8,param_5 << 4,uVar6 * 8,
                    *(undefined4 *)(param_2 + 0x30 + (*(byte *)(param_2 + 0x11) & 1) * 4),
                    (&DAT_02900c70)[DAT_02912e90]), DAT_02912eb8 == 0)) &&
     (FUN_005d0fb0(), DAT_02912eb8 == 0)) {
    FUN_005d1060(DAT_02912b38,*(undefined4 *)(param_2 + 0x28 + (*(byte *)(param_2 + 0x11) & 1) * 4))
    ;
  }
  if ((*(int *)(param_2 + 0x6c) == 0) || (*(int *)(param_2 + 0x50) == 0)) {
    FUN_00618310(DAT_02912b38,iVar5 + param_4 * 8,*(undefined4 *)(param_2 + 0x24));
  }
  else {
    FUN_00618310(DAT_02912b38,iVar5 + param_4 * 8,"%1.03f",
                 (double)*(float *)(*(int *)(param_2 + 0x50) + 8));
    *(int *)(param_2 + 0x6c) = *(int *)(param_2 + 0x6c) + -1;
  }
  piVar1 = *(int **)(param_2 + 0x4c);
  if (piVar1 != (int *)0x0) {
    piVar7 = (int *)*piVar1;
    param_4 = piVar1[2];
    if (piVar7 != (int *)0x0) {
      do {
        FUN_00618920(param_3,(iVar4 >> 3) + iVar3,param_5,iVar4 >> 3,param_4,piVar7[2]);
        param_4 = piVar7[2];
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
    }
  }
  puVar2 = *(undefined4 **)(param_2 + 0x4c);
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return uVar6;
    }
    iVar4 = FUN_006e6b90();
    if (DAT_02912eb8 == 0) {
      FUN_005db880((iVar4 + param_3 + -2) * 0x10,(((uVar6 & 0xfffffffe) - 4) + iVar3 * 2) * 4,0x50,
                   (uVar6 & 0xfffffffe) * 4 + 0x10,puVar2[3],DAT_02900c70);
    }
    if (puVar2 == *(undefined4 **)(param_2 + 0x50)) {
      if (DAT_02912eb8 == 0) {
        iVar5 = ((uVar6 & 0xfffffffe) - 4) + iVar3 * 2;
LAB_0061ad0d:
        FUN_005dbbf0((iVar4 + param_3 + -2) * 0x10,iVar5 * 4,0x50,(uVar6 & 0xfffffffe) * 4 + 0x10);
      }
    }
    else if (DAT_02912eb8 == 0) {
      iVar5 = ((uVar6 & 0xfffffffe) - 4) + iVar3 * 2;
      goto LAB_0061ad0d;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}

