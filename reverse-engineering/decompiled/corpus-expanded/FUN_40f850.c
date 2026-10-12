/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x40f850; label: FUN_0040f850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0040f850(undefined4 param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  float *pfVar3;
  int unaff_EDI;
  float10 fVar4;
  
  uVar1 = FUN_006217e0();
  *(undefined4 *)(unaff_EDI + 0x400) = uVar1;
  fVar4 = (float10)FUN_006217a0();
  *(float *)(unaff_EDI + 0x408) = (float)fVar4;
  uVar1 = FUN_006217e0();
  iVar2 = 0;
  *(undefined4 *)(unaff_EDI + 0x524) = uVar1;
  *(undefined4 *)(unaff_EDI + 0x528) = 1;
  if (in_EAX < 2) {
    *(undefined4 *)(unaff_EDI + 0x514) = 0;
    *(undefined4 *)(unaff_EDI + 0x40c) = 0;
  }
  else {
    fVar4 = (float10)FUN_006217a0();
    *(float *)(unaff_EDI + 0x40c) = (float)fVar4;
    uVar1 = FUN_006217e0();
    *(undefined4 *)(unaff_EDI + 0x514) = uVar1;
  }
  if (in_EAX < 3) {
    *(undefined4 *)(unaff_EDI + 0x51c) = 0xffffffff;
  }
  else {
    uVar1 = FUN_006217e0();
    *(undefined4 *)(unaff_EDI + 0x51c) = uVar1;
    param_1 = FUN_006217e0();
  }
  *(undefined4 *)(unaff_EDI + 0x520) = param_1;
  if (0 < *(int *)(unaff_EDI + 0x400)) {
    pfVar3 = (float *)(unaff_EDI + 8);
    do {
      fVar4 = (float10)FUN_006217a0();
      pfVar3[-2] = (float)fVar4;
      fVar4 = (float10)FUN_006217a0();
      pfVar3[-1] = (float)fVar4;
      fVar4 = (float10)FUN_006217a0();
      *pfVar3 = (float)fVar4;
      fVar4 = (float10)FUN_006217a0();
      pfVar3[1] = (float)fVar4;
      iVar2 = iVar2 + 1;
      pfVar3 = pfVar3 + 4;
    } while (iVar2 < *(int *)(unaff_EDI + 0x400));
  }
  return;
}

