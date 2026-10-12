/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x549a30; label: FUN_00549a30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00549a30(int param_1)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float local_6c;
  float local_68;
  float local_64;
  undefined1 local_60 [12];
  undefined1 local_54 [24];
  undefined1 local_3c [12];
  undefined1 local_30 [48];
  
  pfVar4 = (float *)&DAT_008021cc;
  pfVar1 = (float *)&stack0xffffff88;
  do {
    pfVar3 = pfVar1 + 6;
    local_6c = pfVar4[-1] * _DAT_0087b938;
    iVar2 = param_1 + 0xb8;
    local_68 = *pfVar4 * _DAT_0087b998;
    local_64 = pfVar4[1];
    if (DAT_0092539c == 0) {
      iVar2 = param_1 + 0x78;
    }
    FUN_005b3200(&local_6c,&local_6c,iVar2);
    FUN_005b37d0(pfVar3,&local_6c,param_1 + 0x11c);
    FUN_005b3b30(&local_6c,&local_6c);
    pfVar4 = pfVar4 + 3;
    pfVar1[9] = _DAT_008021f8 * local_6c + *pfVar3;
    pfVar1[10] = _DAT_008021f8 * local_68 + pfVar1[7];
    pfVar1[0xb] = _DAT_008021f8 * local_64 + pfVar1[8];
    pfVar1 = pfVar3;
  } while ((int)pfVar4 < 0x8021fc);
  FUN_005499b0(&DAT_009250e8,local_60);
  FUN_005499b0(&DAT_00925100,local_3c);
  FUN_005499b0(&DAT_00925118,local_60);
  FUN_005499b0(&DAT_00925130,local_30);
  FUN_005499b0(&DAT_009250d0,local_60);
  FUN_005499b0(&DAT_00925148,local_54);
  return;
}

