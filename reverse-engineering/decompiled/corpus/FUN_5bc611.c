/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5bc611; label: FUN_005bc611
 */

float10 FUN_005bc611(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_EAX;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  int in_stack_00000010;
  int iStack00000014;
  int in_stack_00000018;
  float in_stack_0000001c;
  
  iVar2 = *(int *)(in_stack_00000018 + in_stack_00000010 * 4);
  piVar1 = (int *)(in_stack_00000018 + (in_stack_00000010 + in_EAX) * 4);
  if (piVar1[-1] == iVar2) {
    if (*piVar1 == *(int *)(in_stack_00000018 + 4 + in_stack_00000010 * 4)) {
      return (float10)0.0;
    }
    if (piVar1[-1] == iVar2) {
      iVar2 = *piVar1;
      iStack00000014 = iVar2;
      fVar6 = (float10)FUN_005bc5c0(in_stack_00000010 + 1,in_EAX + -1,in_stack_00000018,
                                    in_stack_0000001c);
      return (float10)(float)((((float10)iStack00000014 - (float10)in_stack_0000001c) /
                              (float10)(iVar2 - *(int *)(in_stack_00000018 + 4 +
                                                        in_stack_00000010 * 4))) * fVar6);
    }
  }
  iVar3 = *piVar1;
  iVar5 = in_EAX + -1;
  if (iVar3 == *(int *)(in_stack_00000018 + 4 + in_stack_00000010 * 4)) {
    iStack00000014 = iVar2;
    fVar6 = (float10)FUN_005bc5c0(in_stack_00000010,iVar5,in_stack_00000018,in_stack_0000001c);
    return (float10)(float)((((float10)in_stack_0000001c - (float10)iStack00000014) /
                            (float10)(piVar1[-1] - iVar2)) * fVar6);
  }
  iStack00000014 = iVar3;
  fVar6 = (float10)FUN_005bc5c0(in_stack_00000010 + 1,iVar5,in_stack_00000018,in_stack_0000001c);
  fVar7 = (float10)iStack00000014;
  iVar2 = *(int *)(in_stack_00000018 + 4 + in_stack_00000010 * 4);
  iVar4 = *(int *)(in_stack_00000018 + in_stack_00000010 * 4);
  iStack00000014 = iVar4;
  fVar8 = (float10)FUN_005bc5c0(in_stack_00000010,iVar5,in_stack_00000018,in_stack_0000001c);
  return (float10)(float)((((float10)in_stack_0000001c - (float10)iStack00000014) /
                          (float10)(piVar1[-1] - iVar4)) * fVar8 +
                         (float10)(double)(fVar6 * ((fVar7 - (float10)in_stack_0000001c) /
                                                   (float10)(iVar3 - iVar2))));
}

