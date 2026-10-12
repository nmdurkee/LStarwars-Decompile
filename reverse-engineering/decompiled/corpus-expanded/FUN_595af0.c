/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x595af0; label: FUN_00595af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00595af0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float10 fVar5;
  
  iVar1 = param_1;
  FUN_00636010(param_1 + 0x4d8,1);
  FUN_006371d0(param_2,param_1 + 0x4d8,param_1 + 0x80,0,0xffffffff,0x3f800000);
  if ((*(float *)(param_1 + 0x21c) == 2e+06) ||
     (((&DAT_008034cc)[*(char *)(param_1 + 0x285) * 0xc] & 8) == 0)) {
    param_1 = 0;
  }
  else {
    param_1 = 0x3f800000;
  }
  if ((*(byte *)(iVar1 + 0xef0) & 0x80) == 0) {
    fVar5 = (float10)FUN_0054fad0(*(undefined4 *)(iVar1 + 0xd6c),param_1,_DAT_00925018 * 3.0);
    *(float *)(iVar1 + 0xd6c) = (float)fVar5;
  }
  else {
    *(int *)(iVar1 + 0xd6c) = param_1;
  }
  if ((*(byte *)(iVar1 + 0xef0) & 0x80) == 0) {
    fVar5 = (float10)FUN_0054fb40(*(undefined4 *)(iVar1 + 0x61c),*(undefined4 *)(iVar1 + 0x598),
                                  0x40a00000);
    *(float *)(iVar1 + 0x61c) = (float)fVar5;
    fVar5 = (float10)FUN_0054fb40(*(undefined4 *)(iVar1 + 0x620),*(undefined4 *)(iVar1 + 0x59c),
                                  0x40a00000);
    *(float *)(iVar1 + 0x620) = (float)fVar5;
    fVar5 = (float10)FUN_0054fb40(*(undefined4 *)(iVar1 + 0x624),*(undefined4 *)(iVar1 + 0x5a0),
                                  0x40a00000);
    *(float *)(iVar1 + 0x624) = (float)fVar5;
  }
  else {
    *(undefined4 *)(iVar1 + 0x61c) = *(undefined4 *)(iVar1 + 0x598);
    *(undefined4 *)(iVar1 + 0x620) = *(undefined4 *)(iVar1 + 0x59c);
    *(undefined4 *)(iVar1 + 0x624) = *(undefined4 *)(iVar1 + 0x5a0);
  }
  pfVar3 = (float *)(iVar1 + 0x628);
  iVar2 = 3;
  do {
    if ((*(byte *)(iVar1 + 0xef0) & 0x80) == 0) {
      fVar5 = (float10)FUN_0054fb40(*pfVar3,pfVar3[-0x36],0x40a00000);
      *pfVar3 = (float)fVar5;
      fVar5 = (float10)FUN_0054fb40(pfVar3[1],pfVar3[-0x35],0x40a00000);
      pfVar3[1] = (float)fVar5;
      fVar5 = (float10)FUN_0054fb40(pfVar3[2],pfVar3[-0x34],0x40a00000);
      pfVar3[2] = (float)fVar5;
      fVar5 = (float10)FUN_0054fb40(pfVar3[9],pfVar3[-0x2d],0x40a00000);
      pfVar3[9] = (float)fVar5;
      fVar5 = (float10)FUN_0054fb40(pfVar3[10],pfVar3[-0x2c],0x40a00000);
      pfVar3[10] = (float)fVar5;
      fVar5 = (float10)FUN_0054fb40(pfVar3[0xb],pfVar3[-0x2b],0x40a00000);
      pfVar3[0xb] = (float)fVar5;
    }
    else {
      *pfVar3 = pfVar3[-0x36];
      pfVar3[1] = pfVar3[-0x35];
      pfVar3[2] = pfVar3[-0x34];
      pfVar3[9] = pfVar3[-0x2d];
      pfVar3[10] = pfVar3[-0x2c];
      pfVar3[0xb] = pfVar3[-0x2b];
    }
    pfVar4 = pfVar3 + 9;
    if (((*pfVar4 == 0.0) && (pfVar3[10] == 0.0)) && (pfVar3[0xb] == 0.0)) {
      *pfVar4 = pfVar3[-0x2d];
      pfVar3[10] = pfVar3[-0x2c];
      pfVar3[0xb] = pfVar3[-0x2b];
    }
    else {
      FUN_005b3b30(pfVar4,pfVar4);
    }
    pfVar3 = pfVar3 + 3;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(uint *)(iVar1 + 0xef0) = *(uint *)(iVar1 + 0xef0) & 0xffffff7f;
  return;
}

