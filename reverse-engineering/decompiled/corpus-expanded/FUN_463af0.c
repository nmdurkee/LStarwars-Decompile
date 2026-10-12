/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x463af0; label: FUN_00463af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463af0(int param_1,int param_2,int param_3)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  float10 fVar5;
  
  if (param_3 == 0) {
    if ((*(char *)(param_1 + 0x12) != '\0') && (*(int *)(*(int *)(param_2 + 0x124) + 0xc) != 0x19))
    {
      fVar5 = (float10)FUN_0045e430(param_2,&DAT_0086e714);
      FUN_004b8cf0(_DAT_007fc310,DAT_0087a6cc,DAT_0087a6cd,(float)fVar5);
    }
    return;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    _DAT_0087a1d0 = 0.0;
    return;
  }
  fVar1 = *(float *)(param_1 + 0x18);
  if (NAN(fVar1) || 0.5 < fVar1 == (fVar1 == 0.5)) {
    _DAT_0087a1d0 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x18);
  }
  else {
    _DAT_0087a1d0 = 1.0;
  }
  if (*(float *)(param_1 + 0x18) < 2.0) {
    fVar5 = (float10)FUN_005b7d30(*(undefined4 *)(param_1 + 0x18),0x3e4ccccd);
    if ((float10)0.10000000149011612 <= fVar5) {
      uVar4 = *(uint *)(param_2 + 0xb0) >> 5 & 1;
      if (uVar4 == 0) {
        uVar2 = 0xbf2ccccd;
      }
      else {
        uVar2 = 0x3f2ccccd;
      }
      uVar3 = FUN_006e6b90();
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_0088073c * 4),uVar2,_DAT_007fc310,0x3f800000,
                   0x3f333333,0x3f333333,0x3f333333,(-(uVar4 != 0) & 6U) + 2,0,0xff,0,0x3eb33333,1,0
                   ,0,uVar3);
    }
  }
  FUN_004b8cf0(_DAT_007fc310,DAT_0087a6cc,DAT_0087a6cd,_DAT_0087a1d0,&DAT_0086e714);
  return;
}

