/* Ghidra analysis pseudocode, not original source.
 * ev_7c9627a116e74c10f7e1ba5a6ebe852fd25b4abb6a97a0a4eb0abdf2e857683f
 * Entry: 0x6b6b10; label: FUN_006b6b10
 */

void FUN_006b6b10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *unaff_EDI;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  
  iVar3 = *(int *)(in_EAX + 0x1c);
  if (*(int *)(unaff_EDI[2] + iVar3 * 4) == 0) {
    iVar7 = *(int *)(*(int *)(*(int *)(*(int *)(in_EAX + 0x40) + 4) + 0x1c) + iVar3 * 4) / 2;
    iVar1 = *(int *)(param_1 + 4);
    iVar2 = *unaff_EDI;
    fVar8 = (float10)FUN_006eb9e0();
    fVar9 = (float10)FUN_006eb9e0();
    pvVar4 = _malloc(iVar7 * 4 + 4);
    *(void **)(unaff_EDI[2] + iVar3 * 4) = pvVar4;
    iVar6 = 0;
    if (0 < iVar7) {
      do {
        iVar5 = *(int *)(param_1 + 4);
        fVar10 = (float10)FUN_006eb9e0();
        fVar11 = (float10)FUN_006eb9e0();
        FUN_006eafc0((double)(((float10)((float)iVar6 * (((float)iVar5 * 0.5) / (float)iVar7)) *
                               (float10)9.999999747378752e-05 +
                              fVar11 * (float10)13.100000381469727 +
                              (float10)(double)(fVar10 * (float10)2.240000009536743)) *
                             (float10)(float)((float10)iVar2 /
                                             ((float10)((double)iVar1 * 0.5) *
                                              (float10)9.999999747378752e-05 +
                                             fVar9 * (float10)13.100000381469727 +
                                             (float10)(double)(fVar8 * (float10)2.240000009536743)))
                             ));
        iVar5 = FUN_006e6b90();
        if (*unaff_EDI <= iVar5) {
          iVar5 = *unaff_EDI + -1;
        }
        *(int *)(*(int *)(unaff_EDI[2] + iVar3 * 4) + iVar6 * 4) = iVar5;
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar7);
    }
    *(undefined4 *)(*(int *)(unaff_EDI[2] + iVar3 * 4) + iVar6 * 4) = 0xffffffff;
    unaff_EDI[iVar3 + 3] = iVar7;
  }
  return;
}

