/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x4151c0; label: FUN_004151c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004151c0(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  float10 fVar9;
  uint local_3a8;
  int aiStack_3a4 [233];
  
  if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) != '\0') ||
     (iVar5 = 0x76, (*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0)) {
    iVar5 = 0x19;
  }
  iVar2 = *(int *)(param_1 + 0x50);
  iVar3 = *(int *)(iVar2 + 0xc);
  iVar6 = 0;
  iVar4 = 0;
  do {
    if ((*(int *)(iVar3 + iVar4 * 4) != 0) &&
       (uVar7 = *(uint *)(*(int *)(*(int *)(iVar2 + 8) + iVar4 * 4) + 4), (uVar7 & 0x10) != 0)) {
      if (param_2 == iVar5) {
        if ((uVar7 & 0x800) != 0) {
LAB_0041522f:
          aiStack_3a4[iVar6] = iVar4;
          iVar6 = iVar6 + 1;
        }
      }
      else if ((uVar7 & 0x800) == 0) goto LAB_0041522f;
    }
    iVar4 = iVar4 + 1;
    if (0xe8 < iVar4) {
      if (iVar6 < 1) {
        FUN_004150d0(param_1,0,param_2);
        return;
      }
      do {
        if (iVar6 < 2) {
          iVar5 = 0;
        }
        else {
          iVar5 = FUN_0054fa60();
          iVar5 = iVar5 / ((int)(0xffff / (longlong)iVar6) + 1);
        }
        sVar1 = (short)aiStack_3a4[iVar5];
        *(short *)(param_1 + 0x2c4) = sVar1;
      } while ((1 < iVar6) && (sVar1 == *(short *)(param_1 + 0x2c6)));
      iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + sVar1 * 4);
      uVar7 = (uint)*(byte *)(iVar5 + 0xc);
      local_3a8 = 1;
      if ((uVar7 != 0) &&
         ((uVar8 = (uint)*(byte *)(iVar5 + 0xd), local_3a8 = uVar7, uVar8 != 0 && (uVar7 < uVar8))))
      {
        iVar5 = FUN_0054fa60();
        local_3a8 = iVar5 / ((int)(0xffff / (longlong)(int)(uVar8 - uVar7)) + 1) + uVar7;
      }
      sVar1 = *(short *)(param_1 + 0x2c4);
      *(short *)(param_1 + 0x2c6) = sVar1;
      if ((1 < (int)local_3a8) &&
         ((*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + sVar1 * 4) + 4) & 2) == 0)) {
        local_3a8 = 1;
      }
      *(undefined4 *)(param_1 + 700) = 0;
      fVar9 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),(int)sVar1,0,0,0);
      *(float *)(param_1 + 0x2c0) =
           (float)(fVar9 * (float10)(int)local_3a8 - (float10)_DAT_029a99a4);
      return;
    }
  } while( true );
}

