/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e25f0; label: FUN_004e25f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e25f0(float param_1)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  float local_24 [2];
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = (int)param_1;
  iVar5 = 0;
  if (*(char *)((int)param_1 + 0x7b5) == '4') {
    param_1 = _DAT_007fffe0 * _DAT_007fffe0;
    piVar6 = &DAT_0087a96c;
    do {
      piVar1 = (int *)*piVar6;
      if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
        iVar2 = *piVar1;
        if (((*(uint *)(iVar2 + 0x94) & 0x800000) != 0) && ((*(uint *)(iVar2 + 0x94) & 1) == 0)) {
          fVar7 = (float10)FUN_005b3c50(iVar2 + 0x4c,iVar4 + 0x80,&local_18);
          if ((float)fVar7 < param_1) {
            local_c = local_18;
            local_8 = local_14;
            local_4 = local_10;
            iVar5 = iVar2;
            param_1 = (float)fVar7;
          }
        }
      }
      piVar6 = piVar6 + 1;
    } while ((int)piVar6 < 0x87a98c);
    if (iVar5 != 0) {
      FUN_005b3b30(local_24,&local_c);
      fVar7 = (float10)FUN_005c0240(param_1);
      fVar3 = _DAT_007fffe4 * (1.0 - (float)fVar7 / _DAT_007fffe0);
      local_24[0] = local_24[0] * fVar3;
      local_1c = fVar3 * local_1c;
      fVar7 = (float10)FUN_0054fb40(*(undefined4 *)(iVar4 + 0x68),local_24[0],_DAT_007fffe8);
      *(float *)(iVar4 + 0x68) = (float)fVar7;
      fVar7 = (float10)FUN_0054fb40(*(undefined4 *)(iVar4 + 0x70),local_1c,_DAT_007fffe8);
      *(float *)(iVar4 + 0x70) = (float)fVar7;
    }
  }
  return;
}

