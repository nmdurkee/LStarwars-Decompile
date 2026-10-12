/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a83c0; label: FUN_005a83c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a83c0(int param_1,float *param_2)

{
  undefined2 uVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  float local_24 [2];
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  if (((*(short *)(param_1 + 0x27a) != *(short *)(param_1 + 0x1060)) && (DAT_0095df20 != (int *)0x0)
      ) && (piVar5 = DAT_0095df20, *DAT_0095df20 != 0)) {
    while ((*(short *)(param_1 + 0x1064) != (short)piVar5[4] ||
           (((short)piVar5[1] != -1 &&
            (((pfVar2 = (float *)FUN_0062f150(param_1 + 8,(int)(short)piVar5[1],1,1),
              pfVar2 == (float *)0x0 ||
              ((float)piVar5[2] < *pfVar2 == ((float)piVar5[2] == *pfVar2))) ||
             ((float)piVar5[3] < *pfVar2))))))) {
      piVar5 = piVar5 + 5;
      if (*piVar5 == 0) {
        return;
      }
    }
    if (*(short *)((int)piVar5 + 6) == -1) {
      uVar1 = *(undefined2 *)(param_1 + 0x1060);
      *(undefined2 *)(param_1 + 0x27a) = uVar1;
      *(undefined2 *)(param_1 + 0x5a) = uVar1;
      *(undefined2 *)(param_1 + 0x58) = uVar1;
      return;
    }
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + *(short *)((int)piVar5 + 6) * 4) != 0) {
      iVar3 = FUN_00550040(*(undefined2 *)(param_1 + 0x1060),*(undefined2 *)(param_1 + 0x27a));
      iVar4 = *(short *)((int)piVar5 + 6) * 0x40;
      local_18 = *(undefined4 *)(iVar4 + 0x834 + param_1);
      iVar4 = iVar4 + 0x834 + param_1;
      local_14 = *(undefined4 *)(iVar4 + 4);
      local_10 = *(undefined4 *)(iVar4 + 8);
      FUN_005b3800(local_24,&local_18,param_1 + 0x5c);
      FUN_005b3620(local_c,local_24,-iVar3);
      FUN_005b37d0(local_c,local_c,param_1 + 0x8c);
      FUN_005b3800(local_24,&local_18,local_c);
      FUN_005b3830(local_24,local_24,1.0 / _DAT_00925018);
      *param_2 = *param_2 - local_24[0];
      param_2[2] = param_2[2] - local_1c;
    }
  }
  return;
}

