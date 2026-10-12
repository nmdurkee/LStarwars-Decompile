/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x463520; label: FUN_00463520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463520(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 in_FPUControlWord;
  float10 extraout_ST0;
  undefined4 local_214;
  float local_210;
  longlong local_20c;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_214;
  if (param_3 != 0) {
    if (*(int *)(param_1 + 0x14) < 1) {
      local_210 = 1.0;
    }
    else {
      if (0.5 <= *(float *)(param_1 + 0x18)) {
        if (4.5 <= *(float *)(param_1 + 0x18)) {
          fVar1 = *(float *)(param_1 + 0x18) - 4.5;
          local_214 = 1.0 - (fVar1 + fVar1);
          local_210 = local_214;
        }
        else {
          local_210 = 1.0;
          local_214 = 1.0;
        }
      }
      else {
        local_214 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x18);
        local_210 = 1.0;
      }
      iVar3 = FUN_006e6b90();
      if (*(int *)(param_2 + 0x70) == 0) {
        uVar4 = *(undefined4 *)(DAT_00926c20 + DAT_00880718 * 4);
        local_20c = CONCAT71(local_20c._1_7_,0xff);
        local_214 = (float)((uint)local_214._1_3_ << 8);
      }
      else {
        uVar4 = *(undefined4 *)(DAT_00926c20 + DAT_00880700 * 4);
        local_20c = (ulonglong)local_20c._1_7_ << 8;
        local_214 = (float)CONCAT31(local_214._1_3_,0xff);
      }
      FUN_0050d910(uVar4,0,0x3e4ccccd,(float)extraout_ST0,0x3f333333,0x3f333333,0x3f333333,0,
                   (undefined4)local_20c,local_214,0,0x3fd9999a,1,0,0,iVar3);
      if (0.5 <= *(float *)(param_1 + 0x18)) {
        if (4.0 <= *(float *)(param_1 + 0x18)) {
          fVar1 = 1.0;
        }
        else {
          fVar1 = (*(float *)(param_1 + 0x18) - 0.5) / 3.5;
        }
      }
      else {
        fVar1 = 0.0;
      }
      fVar2 = (float)*(int *)(param_2 + 0xac);
      if (*(int *)(param_2 + 0xac) < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      local_214 = (float)CONCAT22((short)((uint)fVar1 >> 0x10),in_FPUControlWord);
      local_20c = (longlong)ROUND(fVar2 * fVar1);
      FUN_0054bb30((undefined4)local_20c,local_204);
      FUN_0050c780(local_204,0,0,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,0xff,0xff,0xff,iVar3)
      ;
      FUN_0054bb30(*(undefined4 *)(param_2 + 0x6c),local_204);
      FUN_004f1f10(local_104,&DAT_00755d74);
      FUN_004f1e80(local_104,local_204);
      FUN_004f1e80(local_104,&DAT_00755d70);
      FUN_0050c780(local_104,0,0xbe4ccccd,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,0xff,0xff,
                   0xff,iVar3 / 2);
    }
    iVar3 = FUN_006e6b90(_DAT_0087b93c,1,0x3f800000,0xff,0xbf,0);
    fVar1 = (_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] +
            _DAT_007fc314;
    local_20c = CONCAT44(local_20c._4_4_,fVar1);
    FUN_004b80e0(**(undefined4 **)(param_2 + 0x1c),fVar1);
  }
  __security_check_cookie(local_4 ^ (uint)&local_214);
  return;
}

