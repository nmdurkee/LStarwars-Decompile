/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b29f0; label: FUN_004b29f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b29f0(int param_1,int param_2)

{
  float fVar1;
  int in_EAX;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  if (*(char *)(in_EAX + 0x7b5) != '\x1a') {
    if (param_1 == 0) {
      return;
    }
    if (*(char *)(in_EAX + 0x7b5) != -1) {
      return;
    }
    if ((*(byte *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x94) & 0x80) == 0) {
      return;
    }
    if (*(int *)(*(int *)(*(int *)(in_EAX + 0x50) + 0xc) + 0x1ac) == 0) {
      return;
    }
    *(undefined4 *)(in_EAX + 0x77c) = 0;
    *(undefined1 *)(in_EAX + 0x7b5) = 0x1a;
    *(undefined2 *)(in_EAX + 0x7aa) = 0x6b;
    fVar7 = (float10)FUN_0062e040((int)*(short *)(in_EAX + 0x1064),0x6b,0,0,1);
    *(float *)(in_EAX + 0x784) = (float)fVar7;
    if (param_2 == 0) {
      return;
    }
    FUN_0058d480();
    return;
  }
  pfVar2 = (float *)FUN_0062f150(in_EAX + 8,(int)*(short *)(in_EAX + 0x7aa),1,0);
  if (pfVar2 == (float *)0x0) {
    return;
  }
  if ((((param_2 != 0) ||
       (pfVar3 = (float *)FUN_0062f250(*(undefined4 *)(in_EAX + 0x50),
                                       (int)*(short *)(in_EAX + 0x7aa)), pfVar3 == (float *)0x0)) ||
      (fVar1 = *pfVar3, NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0))) ||
     (((fVar1 = pfVar3[1], NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0) ||
       (fVar1 = pfVar3[2], NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0))) ||
      (fVar1 = pfVar3[3], NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0))))) goto LAB_004b2b02;
  if (*pfVar3 < *pfVar2) {
    if (*pfVar2 < pfVar3[1]) {
      *(float *)(in_EAX + 0xd38) = (*pfVar2 - *pfVar3) / (pfVar3[1] - *pfVar3);
      goto LAB_004b2b02;
    }
    if (*pfVar2 < pfVar3[2]) {
      *(undefined4 *)(in_EAX + 0xd38) = 0x3f800000;
      goto LAB_004b2b02;
    }
    if (*pfVar2 < pfVar3[3]) {
      *(float *)(in_EAX + 0xd38) = 1.0 - (*pfVar2 - pfVar3[2]) / (pfVar3[3] - pfVar3[2]);
      goto LAB_004b2b02;
    }
  }
  *(undefined4 *)(in_EAX + 0xd38) = 0;
LAB_004b2b02:
  fVar1 = _DAT_00925018 + *(float *)(in_EAX + 0x77c);
  *(float *)(in_EAX + 0x77c) = fVar1;
  if (*(float *)(in_EAX + 0x784) < fVar1 != (*(float *)(in_EAX + 0x784) == fVar1)) {
    *(undefined4 *)(in_EAX + 0xd38) = 0;
    *(undefined1 *)(in_EAX + 0x7b5) = 0xff;
    if ((((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0) && (iVar4 = FUN_0056e160(10), iVar4 != 0)) &&
       (iVar6 = 0, iVar4 = DAT_0093d504, 0 < DAT_0093d500)) {
      do {
        iVar5 = FUN_004b0c10();
        if (((iVar5 != 0) &&
            (fVar7 = (float10)FUN_005b3c50(in_EAX + 0x80,iVar4 + 0x80,0), fVar7 < (float10)9.0)) &&
           (iVar5 = FUN_00432620(iVar4,_DAT_00804b04), iVar5 != 0)) {
          FUN_00681f40("R2Zap",iVar4 + 0x80);
          FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),1,iVar4 + 0x80);
          FUN_00549f10();
          *(undefined1 *)(iVar4 + 0x7b8) = 2;
          iVar6 = FUN_0054fa60();
          *(uint *)(iVar4 + 0x7bc) = *(uint *)(iVar4 + 0x7bc) | 0x100;
          *(float *)(iVar4 + 0x778) = (float)iVar6 * 1.5259022e-05 * 0.3 + 0.2;
          return;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x10d8;
      } while (iVar6 < DAT_0093d500);
    }
  }
  return;
}

