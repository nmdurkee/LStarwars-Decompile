/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x43ae00; label: FUN_0043ae00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043ae00(int param_1,float param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float *unaff_ESI;
  int unaff_EDI;
  
  if (*unaff_ESI * *unaff_ESI + unaff_ESI[2] * unaff_ESI[2] < param_2 * param_2) {
    *unaff_ESI = *(float *)(unaff_EDI + 0x5c) - *(float *)(param_1 + 0x5c);
    fVar1 = *(float *)(unaff_EDI + 100) - *(float *)(param_1 + 100);
    unaff_ESI[2] = fVar1;
    uVar2 = FUN_005be2d0(*unaff_ESI,fVar1);
    *unaff_ESI = *(float *)(*(int *)(unaff_EDI + 4) + 0x104) - *(float *)(param_1 + 0x5c);
    fVar1 = *(float *)(*(int *)(unaff_EDI + 4) + 0x10c) - *(float *)(param_1 + 100);
    unaff_ESI[2] = fVar1;
    uVar3 = FUN_005be2d0(*unaff_ESI,fVar1);
    iVar4 = FUN_005be5b0(uVar3,uVar2);
    iVar5 = FUN_006e6b90();
    if ((iVar5 < iVar4) || (iVar5 = -iVar5, iVar4 < iVar5)) {
      iVar4 = iVar5;
    }
    FUN_005be590(uVar2,iVar4);
    *unaff_ESI = 0.0;
    unaff_ESI[1] = 0.0;
    unaff_ESI[2] = param_2;
    FUN_005b3620();
    *(float *)(*(int *)(unaff_EDI + 4) + 0x114) = *(float *)(param_1 + 0x5c) + *unaff_ESI;
    *(undefined4 *)(*(int *)(unaff_EDI + 4) + 0x118) =
         *(undefined4 *)(*(int *)(unaff_EDI + 4) + 0x108);
    *(float *)(*(int *)(unaff_EDI + 4) + 0x11c) = *(float *)(param_1 + 100) + unaff_ESI[2];
  }
  return;
}

