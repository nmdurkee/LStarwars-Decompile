/* Ghidra pseudocode, not original source.
 * ev_6f25f465777d6c282cbfa6a77d593954d589f2e76f9dc6caa100c42a001a6af1
 * Entry: 0x6f6ae8; label: FUN_006f6ae8
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006f6ae8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined2 uStack_c;
  undefined6 uStack_a;
  undefined2 uStack_4;
  
  dVar5 = (double)CONCAT44(param_2,param_1);
  uVar1 = param_2 >> 0x10 & 0x7fff;
  if ((0x408f - uVar1 | uVar1 - 0x3c90) < 0x80000000) {
    dVar6 = dVar5 * 92.33248261689366 + 6755399441055744.0;
    dVar7 = (dVar5 * 92.33248261689366 + 6755399441055744.0) - 6755399441055744.0;
    uVar1 = SUB84(dVar6,0);
    iVar2 = (uVar1 & 0x3f) * 0x10;
    dVar4 = (dVar5 - (dVar6 - 6755399441055744.0) * 0.010830424696223417) -
            (dVar6 - 6755399441055744.0) * 2.572804622327669e-14;
    dVar5 = (dVar5 - dVar7 * 0.010830424696223417) - dVar7 * 2.572804622327669e-14;
    dVar6 = (double)(*(ulonglong *)(&UNK_00779018 + iVar2) |
                    ((ulonglong)dVar6 & 0xffffffc0) + 0xffc0 << 0x2e);
    dVar5 = dVar5 * dVar5 * (dVar5 * 0.16666666669815094 + 0.4999999999995663) +
            dVar4 + *(double *)(&DAT_00779010 + iVar2) +
            dVar4 * dVar4 * dVar4 * dVar4 * (dVar4 * 0.008332168270616733 + 0.04166672086872847);
    if (((int)uVar1 >> 6) + 0x37eU < 0x77d) {
      return (float10)(dVar5 * dVar6 + dVar6);
    }
    dVar4 = (double)(*(ulonglong *)(&UNK_00779018 + iVar2) & 0xfffffffffffff |
                    (ulonglong)(((int)uVar1 >> 7) + 0x3ff) << 0x34);
    uStack_4 = (undefined2)((ulonglong)dVar4 >> 0x30);
    dVar5 = (double)((ulonglong)((((int)uVar1 >> 6) - ((int)uVar1 >> 7)) + 0x3ff) << 0x34) *
            (dVar4 + dVar5 * dVar4);
    if (((ushort)((ulonglong)dVar5 >> 0x30) & 0x7ff0) < 0x7ff0) {
      if (((ulonglong)dVar5 & 0x7ff0000000000000) != 0) goto LAB_006f6ce2;
      uVar3 = 0xf;
    }
    else {
      uVar3 = 0xe;
    }
  }
  else {
    uVar1 = param_2 & 0x7fffffff;
    if (uVar1 < 0x40900000) {
      return (float10)((double)CONCAT44(param_2,param_1) + 1.0);
    }
    if (uVar1 < 0x7ff00000) {
      if (param_2 < 0x80000000) {
        dVar5 = INFINITY;
        uVar3 = 0xe;
      }
      else {
        dVar5 = 0.0;
        uVar3 = 0xf;
      }
    }
    else {
      if ((uVar1 < 0x7ff00001) && (param_1 == 0)) {
        if (param_2 != 0x7ff00000) {
          return (float10)0.0;
        }
        return (float10)INFINITY;
      }
      uVar3 = 0x3ea;
    }
  }
  uStack_c = SUB82(dVar5,0);
  uStack_a = (undefined6)((ulonglong)dVar5 >> 0x10);
  ___libm_error_support(&param_1,&param_1,(short)&uStack_c,uVar3);
  dVar5 = (double)CONCAT62(uStack_a,uStack_c);
LAB_006f6ce2:
  return (float10)dVar5;
}

