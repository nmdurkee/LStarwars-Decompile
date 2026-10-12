/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x4058a0; label: FUN_004058a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_004058a0(float param_1)

{
  float *pfVar1;
  byte bVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  iVar4 = (int)param_1;
  if (param_1 == 0.0) {
    return false;
  }
  bVar2 = *(byte *)((int)param_1 + 0x7e);
  if ((*(byte *)((int)param_1 + 0x7c) < bVar2) ||
     (*(char *)((int)param_1 + 5 + (uint)bVar2 * 0x14) != '\0')) {
    iVar5 = *(int *)((int)param_1 + 0x84);
    local_18 = *(undefined4 *)(iVar5 + 0x80);
    local_14 = *(undefined4 *)(iVar5 + 0x84);
    local_10 = *(undefined4 *)(iVar5 + 0x88);
  }
  else {
    iVar5 = FUN_00404850((uint)bVar2);
    if (iVar5 == 0) {
      return false;
    }
  }
  param_1 = 5.0;
  if (1.0 < *(float *)(iVar4 + 0x80)) {
    param_1 = (*(float *)(iVar4 + 0x80) - 1.0) * 5.0 + 5.0;
  }
  if ((*(float *)(iVar4 + 0x80) < 4.0) && (iVar5 = FUN_00404d00(), iVar5 != 0)) {
    FUN_0067b230(local_c);
    FUN_00404a50(iVar4,local_c);
  }
  if ((*(byte *)(iVar4 + 0xaf) & 1) == 0) {
    FUN_005b3800(&local_24,&local_18,iVar4 + 100);
    FUN_005b3b30(&local_24,&local_24);
    FUN_005b3830(&local_24,&local_24,0x40a00000);
    fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(iVar4 + 0x70),local_24,param_1);
    *(float *)(iVar4 + 0x70) = (float)fVar6;
    fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(iVar4 + 0x74),local_20,param_1);
    *(float *)(iVar4 + 0x74) = (float)fVar6;
    fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(iVar4 + 0x78),local_1c,param_1);
    *(float *)(iVar4 + 0x78) = (float)fVar6;
    fVar3 = _DAT_00925018 + *(float *)(iVar4 + 0xb0);
    *(float *)(iVar4 + 0xb0) = fVar3;
    if ((0.2 < fVar3) && ('\0' < *(char *)(iVar4 + 0xae))) {
      *(undefined4 *)(iVar4 + 0xb0) = 0;
      *(char *)(iVar4 + 0xae) = *(char *)(iVar4 + 0xae) + -1;
    }
  }
  else {
    FUN_00404c90(iVar4);
  }
  pfVar1 = (float *)(iVar4 + 100);
  *pfVar1 = *(float *)(iVar4 + 0x70) * _DAT_00925018 + *pfVar1;
  *(float *)(iVar4 + 0x68) = *(float *)(iVar4 + 0x74) * _DAT_00925018 + *(float *)(iVar4 + 0x68);
  *(float *)(iVar4 + 0x6c) = *(float *)(iVar4 + 0x78) * _DAT_00925018 + *(float *)(iVar4 + 0x6c);
  fVar6 = (float10)FUN_005b3c50(pfVar1,&local_18,0);
  return fVar6 < (float10)0.0625;
}

