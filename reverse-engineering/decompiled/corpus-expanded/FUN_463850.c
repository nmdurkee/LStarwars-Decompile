/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x463850; label: FUN_00463850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463850(int param_1,int param_2,float param_3)

{
  int iVar1;
  undefined4 *puVar2;
  char **ppcVar3;
  float10 fVar4;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  float local_15c;
  float local_158;
  char *local_154 [6];
  undefined4 local_13c;
  undefined4 local_138;
  undefined1 local_105;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_168;
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x40800000;
    DAT_0087a1e4 = 1;
    __security_check_cookie(local_4 ^ (uint)&local_168);
    return;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    local_158 = *(float *)(param_1 + 0x18);
    local_15c = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = local_15c;
    if (*(float *)(param_1 + 0x1c) < local_15c != (*(float *)(param_1 + 0x1c) == local_15c)) {
      FUN_004838f0(param_2);
      __security_check_cookie(local_4 ^ (uint)&local_168);
      return;
    }
    if ((local_158 < 2.0) && (2.0 <= local_15c)) {
      puVar2 = &DAT_00802cd8;
      ppcVar3 = local_154;
      for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppcVar3 = (char *)*puVar2;
        puVar2 = puVar2 + 1;
        ppcVar3 = ppcVar3 + 1;
      }
      FUN_00681f40("TrueJedi_100pc",0);
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      (&DAT_0086e714)[*(uint *)(param_2 + 0xb0) >> 5 & 1] =
           (&DAT_0086e714)[*(uint *)(param_2 + 0xb0) >> 5 & 1] + 1;
      _sprintf(local_104,"%i",(&DAT_0086e714)[*(uint *)(param_2 + 0xb0) >> 5 & 1]);
      if ((*(byte *)(param_2 + 0xb0) & 0x20) == 0) {
        local_168 = 0xbc75c28f;
        local_105 = 8;
      }
      else {
        local_168 = 0x3c75c28f;
        local_105 = 2;
      }
      local_154[0] = local_104;
      local_154[1] = (char *)&local_168;
      local_164 = _DAT_007fc310;
      local_160 = 0x3f800000;
      local_154[3] = (char *)0x3f333333;
      local_154[4] = (char *)0x40066666;
      local_13c = 0x4028;
      local_138 = 0x3f800000;
      local_154[2] = local_154[1];
      FUN_00560b60(local_154);
      __security_check_cookie(local_4 ^ (uint)&local_168);
      return;
    }
    if (((local_15c < 2.0) &&
        (fVar4 = (float10)FUN_005b7d30(local_158,0x3e4ccccd), fVar4 < (float10)0.10000000149011612))
       && (fVar4 = (float10)FUN_005b7d30(*(undefined4 *)(param_1 + 0x18),0x3e4ccccd),
          (float10)0.10000000149011612 <= fVar4)) {
      FUN_00681f40("PickupHeart",0);
      __security_check_cookie(local_4 ^ (uint)&local_168);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_168);
  return;
}

