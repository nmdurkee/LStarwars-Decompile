/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x499610; label: FUN_00499610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00499610(int param_1)

{
  float fVar1;
  int iVar2;
  undefined1 uVar3;
  short sVar4;
  int iVar5;
  bool bVar6;
  float local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  float local_c [2];
  float local_4;
  
  if ((*(char *)(param_1 + 0x7b5) != -1) && (*(char *)(param_1 + 0x7b5) != ':')) {
    return;
  }
  if (_DAT_00924fdc < 1.0) {
    return;
  }
  bVar6 = *(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b234;
  if (*(char *)(param_1 + 0x280) == -1) {
    return;
  }
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x1078) == '\0') {
    return;
  }
  local_18 = *(undefined4 *)(param_1 + 0x6a8);
  local_14 = *(float *)(param_1 + 0x6ac);
  local_10 = *(undefined4 *)(param_1 + 0x6b0);
  iVar5 = FUN_0054fa60();
  sVar4 = *(short *)(param_1 + 0x1064);
  local_14 = (*(float *)(param_1 + 0x6ac) - *(float *)(param_1 + 0x1e0) * 0.5) +
             (*(float *)(param_1 + 0x1e0) / 65535.0) * (float)iVar5;
  if (sVar4 == DAT_007f1948) {
    iVar5 = 0x6c;
  }
  else {
    if ((sVar4 != DAT_007f1970) && (sVar4 != DAT_007f1a1c)) {
      iVar5 = -1;
      goto LAB_0049976d;
    }
    iVar5 = 100;
  }
  if (sVar4 == DAT_007f1948) {
    FUN_0054fa60();
    FUN_0054fa60();
  }
  FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + iVar5 * 0x14),
               &local_18,0x34,_DAT_00925018,0,0,0);
  iVar5 = 0x65;
LAB_0049976d:
  if (((*(float *)(param_1 + 0x6b8) <= 0.574) &&
      (fVar1 = *(float *)(param_1 + 0x6b8), !NAN(fVar1) && -0.574 < fVar1 != (fVar1 == -0.574))) &&
     (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x10) < *(float *)(param_1 + 0x22c))) {
    FUN_005b3b30(local_c,param_1 + 0x6b4);
    local_24 = *(float *)(param_1 + 0xdf8);
    local_20 = *(undefined4 *)(param_1 + 0xdfc);
    local_1c = *(float *)(param_1 + 0xe00);
    FUN_005b3b30(&local_24,&local_24);
    local_24 = -local_24;
    local_1c = -local_1c;
    sVar4 = FUN_00497c40(local_c[0] * local_24 + local_4 * local_1c);
    if (((bVar6) || ((DAT_007fc218 * 0x10000) / 0x168 <= (int)(short)(0x4000 - sVar4))) ||
       (iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x24),
       *(float *)(param_1 + 0x22c) <= (*(float *)(iVar2 + 0x18) + *(float *)(iVar2 + 0x14)) * 0.5))
    {
      if ((DAT_007fc214 * 0x10000) / 0x168 <= (int)(short)(0x4000 - sVar4)) {
        return;
      }
      _DAT_0087b918 =
           (1.0 / *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x1c)) *
           (*(float *)(param_1 + 0xdf0) - *(float *)(param_1 + 0xdf4));
      if (_DAT_0087b918 <= _DAT_007fc210) {
        return;
      }
      uVar3 = 1;
    }
    else {
      uVar3 = *(undefined1 *)(param_1 + 0x107e);
    }
    FUN_00438230(0,param_1,uVar3,0,0,1);
    if (iVar5 != -1) {
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),iVar5,param_1 + 0x6a8);
    }
  }
  return;
}

