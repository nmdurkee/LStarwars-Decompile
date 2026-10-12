/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x437510; label: FUN_00437510
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00437510(float param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float10 fVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float local_18;
  undefined4 local_14;
  float local_10;
  undefined1 local_c [12];
  
  iVar5 = param_4;
  *(undefined4 *)((int)param_1 + 0x2c) = 0x400;
  local_18 = *(float *)(param_4 + 0x68) * 1.5;
  local_14 = 0;
  local_10 = *(float *)(param_4 + 0x70) * 1.5;
  *(undefined1 **)((int)param_1 + 0x44) = &LAB_00437420;
  *(code **)((int)param_1 + 0x48) = FUN_00433160;
  *(undefined1 **)((int)param_1 + 0x54) = &LAB_00433a30;
  *(float **)((int)param_1 + 8) = &local_18;
  iVar2 = FUN_0064d270(param_1);
  if (iVar2 != 0) {
    param_1 = 0.0;
    *(undefined4 *)(iVar2 + 0x100) = 0x3fc00000;
    pcVar3 = &DAT_008766b0;
    *(undefined4 *)(iVar2 + 0x104) = 0x3fc00000;
    do {
      if (*pcVar3 == '\0') goto LAB_004375ae;
      pcVar3 = pcVar3 + 0x34;
      param_1 = (float)((int)param_1 + 1);
    } while ((int)pcVar3 < 0x876780);
    param_1 = -NAN;
LAB_004375ae:
    param_1 = (float)(int)param_1;
    *(float *)(iVar2 + 0x20c) = param_1;
    if ((param_1 != -1.0) && (*(int *)(iVar5 + 0xe64) != 0)) {
      fVar10 = (float10)FUN_005bec80(iVar2 + 0x80);
      fVar1 = (float10)_DAT_00925018;
      iVar4 = FUN_006e6b90();
      (&DAT_008766b0)[iVar4 * 0x34] = 1;
      iVar4 = FUN_006e6b90();
      puVar8 = (undefined4 *)(iVar5 + 0xe64);
      puVar9 = (undefined4 *)(&DAT_00876690 + iVar4 * 0x34);
      for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      iVar4 = *(int *)(iVar5 + 0xcd0);
      iVar7 = FUN_006e6b90();
      if (iVar4 == 0) {
        *(undefined4 *)(&DAT_008766b4 + iVar7 * 0x34) = 0;
      }
      else {
        *(int *)(&DAT_008766b4 + iVar7 * 0x34) = iVar4;
        iVar4 = FUN_006e6b90();
        iVar4 = *(int *)(&DAT_008766b4 + iVar4 * 0x34);
        *(float *)(iVar4 + 0x68) = local_18;
        *(undefined4 *)(iVar4 + 0x6c) = local_14;
        *(float *)(iVar4 + 0x70) = local_10;
        iVar4 = FUN_006e6b90();
        *(float *)(*(int *)(&DAT_008766b4 + iVar4 * 0x34) + 0x6c) =
             *(float *)(*(int *)(&DAT_008766b4 + iVar4 * 0x34) + 0x6c) + 1.5;
        iVar4 = FUN_006e6b90();
        iVar4 = iVar4 * 0x34;
        *(undefined4 *)(&DAT_008766b8 + iVar4) = *(undefined4 *)(iVar5 + 0x5c);
        *(undefined4 *)(&DAT_008766bc + iVar4) = *(undefined4 *)(iVar5 + 0x60);
        *(undefined4 *)(&DAT_008766c0 + iVar4) = *(undefined4 *)(iVar5 + 100);
      }
      iVar5 = FUN_006e6b90();
      FUN_00550a20(*(undefined4 *)(&DAT_00876690 + iVar5 * 0x34),
                   *(undefined4 *)(&DAT_008766ac + iVar5 * 0x34),local_c,&param_4,&param_1,1);
      sVar6 = (short)param_4 + -0x8000;
      if ((float)(fVar10 * fVar1) < 0.0) {
        param_1 = (float)(-(int)param_1 & 0xffff);
        sVar6 = (short)param_4;
      }
      *(undefined2 *)(iVar2 + 0x13c) = 0;
      *(short *)(iVar2 + 0x138) = -SUB42(param_1,0);
      *(short *)(iVar2 + 0x13a) = sVar6;
      return;
    }
    FUN_0064ac90(iVar2,0);
  }
  return;
}

