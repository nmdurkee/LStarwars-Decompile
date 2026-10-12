/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x424040; label: FUN_00424040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00424040(int param_1)

{
  undefined *puVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  undefined4 *local_8;
  int local_4;
  
  if (param_1 != 0) {
    puVar8 = (undefined1 *)(param_1 + 0xa6e);
    puVar6 = (undefined4 *)(param_1 + 0xa70);
    local_8 = &DAT_008568f0;
    iVar10 = param_1 + 0x178;
    local_4 = 2;
    do {
      FUN_0062e650(iVar10,0xffffffff);
      puVar8[-2] = 0;
      *puVar6 = 0;
      *puVar8 = 2;
      *local_8 = 2;
      local_8 = local_8 + 1;
      iVar10 = iVar10 + 0x48;
      puVar8 = puVar8 + 1;
      puVar6 = puVar6 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    if (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x48) != 0) {
      iVar7 = 0;
      local_8 = (undefined4 *)&DAT_0085697c;
      pfVar11 = (float *)&DAT_00856904;
      iVar10 = 0;
      do {
        puVar1 = PTR_DAT_00802c54;
        iVar4 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 0x48) + 8);
        *pfVar11 = *(float *)(iVar4 + iVar7);
        pfVar11[1] = *(float *)(iVar4 + 4 + iVar7);
        pfVar11[2] = *(float *)(iVar4 + iVar7 + 8);
        iVar4 = *(int *)(*(int *)(*(int *)(puVar1 + 0x2ac4) + 0x48) + 8);
        uVar2 = FUN_005be2d0(*(float *)(iVar4 + 0xc + iVar7) - *pfVar11,
                             *(float *)(iVar4 + 0x14 + iVar7) - pfVar11[2]);
        *(undefined2 *)local_8 = uVar2;
        *(undefined2 *)((int)&DAT_0085694c + iVar10) = 0;
        iVar4 = FUN_0054fa60();
        *(undefined2 *)((int)&DAT_00856948 + iVar10) = 0;
        *(undefined2 *)((int)&DAT_0085694a + iVar10) = 0;
        *(undefined2 *)((int)&DAT_00856888 + iVar10) = 0;
        *(float *)((int)&DAT_00856944 + iVar10) = (float)iVar4 * 1.5259022e-05 * 0.5 * 0.5;
        *(undefined4 *)((int)&DAT_00856940 + iVar10) = 0;
        *(undefined4 *)((int)&DAT_0085693c + iVar10) = 0;
        iVar4 = FUN_0054fa60();
        *(undefined2 *)((int)&DAT_00856884 + iVar10) = 0;
        *(undefined2 *)((int)&DAT_00856886 + iVar10) = 0;
        *(undefined2 *)((int)&DAT_008568d8 + iVar10) = 0;
        *(float *)((int)&DAT_00856880 + iVar10) = (float)iVar4 * 1.5259022e-05 * 0.5 * 0.5;
        *(undefined4 *)((int)&DAT_0085687c + iVar10) = 0;
        *(undefined4 *)((int)&DAT_00856878 + iVar10) = 0;
        iVar4 = FUN_0054fa60();
        local_8 = (undefined4 *)((int)local_8 + 2);
        *(undefined2 *)((int)&DAT_008568d4 + iVar10) = 0;
        *(undefined2 *)((int)&DAT_008568d6 + iVar10) = 0;
        iVar9 = iVar10 + 0x14;
        iVar7 = iVar7 + 0x18;
        pfVar11 = pfVar11 + 3;
        *(float *)((int)&DAT_008568d0 + iVar10) = (float)iVar4 * 1.5259022e-05 * 0.5 * 0.5;
        *(undefined4 *)((int)&DAT_008568cc + iVar10) = 0;
        *(undefined4 *)((int)&DAT_008568c8 + iVar10) = 0;
        iVar10 = iVar9;
      } while (iVar9 < 0x28);
      sVar3 = FUN_0054fa60();
      DAT_00856970 = CONCAT22(sVar3 + 0x4000,sVar3);
      sVar3 = FUN_0054fa60();
      DAT_008568f8 = CONCAT22(sVar3 + -0x8000,sVar3);
      sVar3 = FUN_0054fa60();
      DAT_0085696c = CONCAT22(sVar3 + -0x8000,sVar3);
      sVar3 = FUN_0054fa60();
      DAT_008568fc = CONCAT22(sVar3 + -0x8000,sVar3);
    }
    FUN_00423c30(param_1,0xffffffff);
    _DAT_008569a4 = 0;
    local_8 = (undefined4 *)0x0;
    iVar10 = 0;
    do {
      iVar7 = 0;
      piVar5 = (int *)(param_1 + 0x48);
      do {
        if (0 < *piVar5) {
          uVar2 = FUN_00592940(param_1,(ushort)(&DAT_0086e4ec)[iVar7 + iVar10] - 1,*piVar5,local_8,
                               iVar7);
          (&DAT_0086e4ec)[iVar7 + iVar10] = uVar2;
        }
        iVar7 = iVar7 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar7 < 9);
      local_8 = (undefined4 *)((int)local_8 + 1);
      iVar10 = iVar10 + 0x1c;
    } while (iVar10 < 0x38);
    DAT_008568c4 = 0;
    DAT_00856964 = 0;
    _DAT_00856978 = 0x3f800000;
    DAT_00856974 = 0x3f800000;
  }
  return;
}

