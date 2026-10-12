/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c8e40; label: FUN_004c8e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c8e40(undefined4 param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  float10 fVar8;
  
  FUN_004e6000(param_1,(int)DAT_007f1a3c);
  FUN_004e6260(param_1);
  iVar7 = 0;
  if ((DAT_00951b50 == 0) &&
     ((DAT_0087aa6c == 0 || (DAT_00880564 = 1, *(float *)(DAT_0087aa6c + 0x28) != 1.0)))) {
    DAT_00880564 = 0;
  }
  if (DAT_0093d7f0 != 0) {
    if ((((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (DAT_009253a4 == 0)) &&
        (*(short *)(DAT_0093d7f0 + 0x1064) == DAT_007f1948)) &&
       ((*(int *)(DAT_0093d7f0 + 0xcd0) != 0 &&
        ((*(byte *)(*(int *)(DAT_0093d7f0 + 0xcd0) + 0x1fc) & 0x80) != 0)))) {
      *(uint *)(DAT_0093d7f0 + 0xef4) = *(uint *)(DAT_0093d7f0 + 0xef4) | 0x1000000;
    }
    else {
      *(uint *)(DAT_0093d7f0 + 0xef4) = *(uint *)(DAT_0093d7f0 + 0xef4) & 0xfeffffff;
    }
  }
  if (DAT_0093d7f4 != 0) {
    if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) && (DAT_009253a4 == 0)) &&
       ((*(short *)(DAT_0093d7f4 + 0x1064) == DAT_007f1948 &&
        ((*(int *)(DAT_0093d7f4 + 0xcd0) != 0 &&
         ((*(byte *)(*(int *)(DAT_0093d7f4 + 0xcd0) + 0x1fc) & 0x80) != 0)))))) {
      *(uint *)(DAT_0093d7f4 + 0xef4) = *(uint *)(DAT_0093d7f4 + 0xef4) | 0x1000000;
    }
    else {
      *(uint *)(DAT_0093d7f4 + 0xef4) = *(uint *)(DAT_0093d7f4 + 0xef4) & 0xfeffffff;
    }
  }
  DAT_007fcd84 = 1;
  piVar6 = &DAT_0093d7f0;
  while ((((iVar3 = *piVar6, iVar3 == 0 || ((*(byte *)(iVar3 + 0x1fc) & 0x80) == 0)) ||
          ((*(uint *)(iVar3 + 0x1f8) & 0x40000) != 0)) ||
         ((iVar3 = FUN_0040e690(iVar3), iVar3 != 0 && (*(char *)(*piVar6 + 0x7b5) != '*'))))) {
    piVar6 = piVar6 + 1;
    if (0x93d7f7 < (int)piVar6) {
LAB_004c8fa1:
      puVar5 = &DAT_0087aad8;
      do {
        iVar3 = FUN_005d0420(puVar5);
        uVar4 = FUN_005cf9e0(puVar5);
        if (iVar3 != 0) {
          uVar2 = *(undefined4 *)
                   (*(int *)(*(int *)(PTR_DAT_00802c54 + 0x13c) + 0x54) +
                   (uint)*(ushort *)(iVar3 + 0x5c) * 4);
          if ((&DAT_0087aa38)[iVar7] == '\0') {
            if ((0.0 < *(float *)(iVar3 + 0x4c)) &&
               (fVar1 = *(float *)(iVar3 + 0x4c), fVar8 = (float10)FUN_005ca4b0(uVar2),
               fVar8 != (float10)fVar1)) {
              FUN_00681f40("env_laser_gate_on",uVar4);
              (&DAT_0087aa38)[iVar7] = 1;
            }
          }
          else if (((*(byte *)(iVar3 + 0x50) & 1) == 0) &&
                  (fVar1 = *(float *)(iVar3 + 0x4c), fVar8 = (float10)FUN_005ca4b0(uVar2),
                  fVar8 == (float10)fVar1)) {
            FUN_00681f40("env_laser_gate_off",uVar4);
            (&DAT_0087aa38)[iVar7] = 0;
          }
          else {
            FUN_00681f40("env_laser_gate_lp",uVar4);
          }
        }
        puVar5 = puVar5 + 3;
        iVar7 = iVar7 + 1;
      } while ((int)puVar5 < 0x87ab44);
      return;
    }
  }
  DAT_007fcd84 = 0;
  goto LAB_004c8fa1;
}

