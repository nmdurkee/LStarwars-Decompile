/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x5506f0; label: FUN_005506f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005506f0(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  float10 fVar6;
  int local_40 [16];
  
  uVar5 = 0;
  if (param_1 != 0) {
    iVar2 = FUN_0055f450();
    sVar1 = *(short *)(param_1 + 0x1070);
    if (sVar1 != -1) {
      local_40[0] = (int)sVar1;
    }
    uVar5 = (uint)(sVar1 != -1);
    if ((((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + 0x2adc), iVar2 != 0)) && (DAT_00951288 == 0)) &&
       (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0 && (iVar4 = *(int *)(iVar2 + 4), 0 < iVar4)))) {
      piVar3 = (int *)(iVar2 + 0x18);
      do {
        if (*piVar3 != 0) {
          local_40[uVar5] = (int)*(short *)(*piVar3 + 0x1070);
          uVar5 = uVar5 + 1;
        }
        piVar3 = piVar3 + 5;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar2 = 0;
    if (0 < (int)uVar5) {
      do {
        FUN_0067c8e0(local_40[iVar2],0);
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)uVar5);
    }
    if ((DAT_00802524 != 0xffffffff) &&
       (*(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) == 0.0)) {
      param_4 = param_4 & ~DAT_00802524;
    }
  }
  fVar6 = (float10)FUN_00673730(param_2,0,param_3,param_3,param_4);
  if ((param_1 != 0) && (*(short *)(param_1 + 0x1070) != -1)) {
    FUN_0067c8e0((int)*(short *)(param_1 + 0x1070),1);
  }
  iVar2 = 0;
  if (0 < (int)uVar5) {
    do {
      FUN_0067c8e0(local_40[iVar2],1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar5);
  }
  return (float10)(float)fVar6;
}

