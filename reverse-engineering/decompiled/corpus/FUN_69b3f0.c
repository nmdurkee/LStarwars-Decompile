/* Ghidra analysis pseudocode, not original source.
 * ev_b9f25343996aedf2297d7d3ade291ed602d662c61207b78e5aec6bfbfbdc583f
 * Entry: 0x69b3f0; label: FUN_0069b3f0
 */

longlong FUN_0069b3f0(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  int extraout_EDX;
  int iVar6;
  uint uVar7;
  bool bVar8;
  longlong lVar9;
  
  uVar1 = in_EAX[2];
  iVar5 = in_EAX[3];
  lVar3 = -1;
  iVar6 = iVar5;
  uVar7 = uVar1;
  do {
    bVar8 = 0xffff < uVar7;
    uVar7 = uVar7 - 0x10000;
    iVar6 = iVar6 + -1 + (uint)bVar8;
    if ((iVar6 < 1) && (iVar6 < 0)) {
      uVar7 = 0;
      iVar6 = 0;
    }
    if (*in_EAX == 0) {
      iVar4 = -0x81;
    }
    else if (((code *)in_EAX[0xb1] == (code *)0x0) ||
            (iVar4 = (*(code *)in_EAX[0xb1])(*in_EAX,uVar7,iVar6,0), iVar4 == -1)) {
      iVar4 = -0x80;
    }
    else {
      in_EAX[2] = uVar7;
      in_EAX[3] = iVar6;
      FUN_0069fae0(in_EAX + 6);
      iVar4 = 0;
    }
    if (iVar4 != 0) {
      return (longlong)iVar4;
    }
    if (in_EAX[3] <= iVar5) {
      if (in_EAX[3] < iVar5) goto LAB_0069b485;
      uVar2 = in_EAX[2];
      lVar9 = lVar3;
      while (lVar3 = lVar9, uVar2 < uVar1) {
LAB_0069b485:
        do {
          lVar9 = FUN_0069b340(param_1,uVar1 - in_EAX[2],
                               (iVar5 - in_EAX[3]) - (uint)(uVar1 < (uint)in_EAX[2]));
          if (lVar9 == -0x80) {
            return -0x80;
          }
          if (lVar9 < 0) goto LAB_0069b4ce;
          lVar3 = lVar9;
        } while (in_EAX[3] < iVar5);
        if (iVar5 < in_EAX[3]) break;
        uVar2 = in_EAX[2];
      }
    }
LAB_0069b4ce:
    if (lVar3 != -1) {
      iVar5 = FUN_0069b2e0(lVar3);
      lVar9 = (longlong)iVar5;
      if (iVar5 == 0) {
        FUN_0069b340(param_1,0x10000,0);
        lVar9 = lVar3;
        if ((extraout_EDX < 1) && (extraout_EDX < 0)) {
          return -0x81;
        }
      }
      return lVar9;
    }
  } while( true );
}

