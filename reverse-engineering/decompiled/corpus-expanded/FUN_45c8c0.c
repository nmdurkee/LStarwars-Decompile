/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45c8c0; label: FUN_0045c8c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045c8c0(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  
  fVar1 = *(float *)(param_1 + 0x18);
  if (-1 < *(int *)(param_1 + 0x14)) {
    *(float *)(param_1 + 0x18) = param_3 + *(float *)(param_1 + 0x18);
  }
  uVar3 = DAT_00876dac;
  switch(*(int *)(param_1 + 0x14)) {
  case 0:
    DAT_00876dc0 = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x3e19999a;
    *(undefined4 *)(param_1 + 0x14) = 1;
    goto LAB_0045c913;
  case 1:
    if (9 < DAT_00876dc0) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      DAT_00876dc0 = 0;
      *(undefined4 *)(param_1 + 0x14) = 2;
      *(undefined4 *)(param_1 + 0x1c) = 0x3fc00000;
      while ((uVar2 = 1 << ((byte)DAT_00876dc0 & 0x1f), (uVar3 & uVar2) != 0 ||
             ((DAT_0087aa8c & uVar2) == 0))) {
        DAT_00876dc0 = DAT_00876dc0 + 1;
        if (9 < DAT_00876dc0) {
          return;
        }
      }
      *(undefined4 *)(param_1 + 0x18) = 0;
      FUN_00681f40("LegoClicks",0);
      DAT_00876dc4 = 0;
      return;
    }
LAB_0045c913:
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
        (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
      DAT_00876dc0 = DAT_00876dc0 + 1;
      *(undefined4 *)(param_1 + 0x18) = 0;
      return;
    }
    break;
  case 2:
    if ((1.0 <= fVar1) ||
       (fVar1 = *(float *)(param_1 + 0x18), NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0))) {
      if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18)) {
        DAT_00876dac = DAT_00876dac | 1 << ((byte)DAT_00876dc0 & 0x1f);
        do {
          DAT_00876dc0 = DAT_00876dc0 + 1;
          if (9 < DAT_00876dc0) goto LAB_0045ca3f;
          uVar3 = 1 << ((byte)DAT_00876dc0 & 0x1f);
        } while (((DAT_00876dac & uVar3) != 0) || ((DAT_0087aa8c & uVar3) == 0));
        *(undefined4 *)(param_1 + 0x18) = 0;
        FUN_00681f40("LegoClicks",0);
        DAT_00876dc4 = 0;
      }
    }
    else {
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
    }
LAB_0045ca3f:
    if (DAT_00876dc0 == 10) {
      *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x14) = 3;
      *(undefined4 *)(param_1 + 0x18) = 0;
      return;
    }
    break;
  case 3:
    if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18)) {
      FUN_004838f0(param_2);
      return;
    }
  }
  return;
}

