/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x565230; label: FUN_00565230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565230(int param_1,uint *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  if ((DAT_00951be8 == 0) || (*(float *)(DAT_00951be8 + 0x6c) == 0.0)) {
    *(undefined4 *)(DAT_00925164 + 0x48) = *(undefined4 *)(param_1 + 4);
  }
  else {
    *(undefined4 *)(DAT_00925164 + 0x48) = *(undefined4 *)(DAT_00951be8 + 0x6c);
  }
  if ((DAT_00951be8 == 0) || (uVar1 = *(ushort *)(DAT_00951be8 + 0xe8), uVar1 == 0)) {
    uVar1 = *(ushort *)(param_1 + 8);
  }
  local_18 = (uint)uVar1;
  *(float *)(DAT_00925164 + 0x4c) = (float)local_18;
  iVar2 = *(int *)(PTR_DAT_00802c54 + 0x128);
  if ((((iVar2 != DAT_00951b88) && ((*(uint *)(iVar2 + 100) & 0x400) == 0)) &&
      (iVar2 != DAT_00951b98)) && ((iVar2 != DAT_00951b9c && (1.0 <= _DAT_00950678)))) {
    *param_2 = ((*(byte *)(param_1 + 0xe) | 0xffff8000) << 8 | (uint)*(byte *)(param_1 + 0xc)) << 8
               | (uint)*(byte *)(param_1 + 10);
    param_2[1] = ((*(byte *)(param_1 + 0xf) | 0xffff8000) << 8 | (uint)*(byte *)(param_1 + 0xd)) <<
                 8 | (uint)*(byte *)(param_1 + 0xb);
    return;
  }
  FUN_005647e0(0);
  uVar3 = FUN_006e6b90();
  local_10 = uVar3;
  uVar4 = FUN_006e6b90();
  local_18 = uVar4;
  uVar5 = FUN_006e6b90();
  local_8 = uVar5;
  local_c = FUN_006e6b90();
  local_14 = FUN_006e6b90();
  uVar6 = FUN_006e6b90();
  local_1c = 1.0;
  if ((DAT_0095075c != (code *)0x0) &&
     (local_4 = uVar6, (*DAT_0095075c)(&local_1c), local_1c != 1.0)) {
    uVar3 = FUN_006e6b90();
    uVar4 = FUN_006e6b90();
    uVar5 = FUN_006e6b90();
    local_c = FUN_006e6b90();
    local_14 = FUN_006e6b90();
    uVar6 = FUN_006e6b90();
  }
  param_2[1] = ((uVar6 & 0xff | 0xffff8000) << 8 | local_14 & 0xff) << 8 | local_c & 0xff;
  *param_2 = ((uVar5 & 0xff | 0xffff8000) << 8 | uVar4 & 0xff) << 8 | uVar3 & 0xff;
  return;
}

