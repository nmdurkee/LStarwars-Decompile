/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x675610; label: FUN_00675610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00675610(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  float10 fVar7;
  float local_14;
  float local_10;
  float local_c;
  
  iVar6 = DAT_0292186c;
  local_c = 0.0;
  local_10 = 0.0;
  local_14 = 0.0;
  fVar2 = *(float *)(DAT_0292186c + 0x50);
  *(undefined1 *)(DAT_0292186c + 0x88) = 0;
  *(undefined4 *)(iVar6 + 0x98) = 0x4479f99a;
  fVar7 = (float10)FUN_005c0240(*(float *)(iVar6 + 0x28) * *(float *)(iVar6 + 0x28) +
                                *(float *)(iVar6 + 0x30) * *(float *)(iVar6 + 0x30));
  iVar6 = DAT_0292186c;
  *(float *)(DAT_0292186c + 0x3c) = (float)fVar7;
  pfVar1 = (float *)(*DAT_0292fc68 + param_2 * 0x38);
  *(float *)(iVar6 + 0x70) = *(float *)(iVar6 + 0x1c) - *(float *)(*DAT_0292fc68 + param_2 * 0x38);
  bVar5 = false;
  *(float *)(iVar6 + 0x74) = *(float *)(iVar6 + 0x20) - pfVar1[1];
  *(float *)(iVar6 + 0x78) = *(float *)(iVar6 + 0x24) - pfVar1[2];
  *(float *)(iVar6 + 0x7c) = (*(float *)(iVar6 + 0x28) + *(float *)(iVar6 + 0x1c)) - *pfVar1;
  *(float *)(iVar6 + 0x80) = (*(float *)(iVar6 + 0x2c) + *(float *)(iVar6 + 0x20)) - pfVar1[1];
  fVar3 = (*(float *)(iVar6 + 0x30) + *(float *)(iVar6 + 0x24)) - pfVar1[2];
  *(float *)(iVar6 + 0x84) = fVar3;
  fVar4 = (((fVar3 - *(float *)(param_1 + 0x20)) * *(float *)(param_1 + 0x50) +
           (*(float *)(iVar6 + 0x7c) - *(float *)(param_1 + 0x18)) * *(float *)(param_1 + 0x48) +
           (*(float *)(iVar6 + 0x80) - *(float *)(param_1 + 0x1c)) * *(float *)(param_1 + 0x4c)) -
          fVar2) - *(float *)(iVar6 + 0xa4);
  if ((fVar4 < 0.0) &&
     (local_c = ((*(float *)(iVar6 + 0x78) - *(float *)(param_1 + 0x20)) *
                 *(float *)(param_1 + 0x50) +
                (*(float *)(iVar6 + 0x70) - *(float *)(param_1 + 0x18)) * *(float *)(param_1 + 0x48)
                + (*(float *)(iVar6 + 0x74) - *(float *)(param_1 + 0x1c)) *
                  *(float *)(param_1 + 0x4c)) - fVar2, -fVar2 < local_c)) {
    bVar5 = true;
  }
  if (((((*(float *)(param_1 + 0x58) < 65536.0) &&
        (local_14 = (((*(float *)(iVar6 + 0x7c) - *(float *)(param_1 + 0x3c)) *
                      *(float *)(param_1 + 0x54) +
                      (*(float *)(iVar6 + 0x80) - *(float *)(param_1 + 0x40)) *
                      *(float *)(param_1 + 0x58) +
                     *(float *)(param_1 + 0x5c) * (fVar3 - *(float *)(param_1 + 0x44))) - fVar2) -
                    *(float *)(iVar6 + 0xa4), local_14 < 0.0)) &&
       (local_10 = ((*(float *)(iVar6 + 0x78) - *(float *)(param_1 + 0x44)) *
                    *(float *)(param_1 + 0x5c) +
                   (*(float *)(iVar6 + 0x70) - *(float *)(param_1 + 0x3c)) *
                   *(float *)(param_1 + 0x54) +
                   (*(float *)(iVar6 + 0x74) - *(float *)(param_1 + 0x40)) *
                   *(float *)(param_1 + 0x58)) - fVar2, -fVar2 < local_10)) || (bVar5)) &&
     (iVar6 = FUN_00674490(local_c,fVar4,local_10,local_14,param_1), iVar6 != 0)) {
    *(short *)(DAT_0292186c + 0x6c) = (short)param_2;
    return 1;
  }
  return 0;
}

