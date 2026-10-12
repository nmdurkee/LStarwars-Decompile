/* Ghidra pseudocode, not original source.
 * ev_6614b6c0ec400e98b17ca3318749993ac398f4a5e7c651bffc9aeb30b42772d2
 * Entry: 0x509bc0; label: FUN_00509bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00509bc0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar2 = DAT_00800944;
  if (DAT_00800944 != 0) {
    iVar3 = DAT_00800944 * 0xe0;
    iVar1 = DAT_00800944 * 0x38;
    if ((code *)(&PTR_FUN_00800ab8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7] != (code *)0x0)
    {
      (*(code *)(&PTR_FUN_00800ab8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7])
                (&DAT_00921440 + iVar1);
    }
    iVar4 = DAT_00800944;
    FUN_005097d0(&DAT_00921440 + iVar1);
    iVar4 = iVar4 + -1;
    (&DAT_009214f4)[iVar2 * 0x38] = 0;
    (&DAT_009214f8)[iVar2 * 0x38] = 1;
    *(undefined4 *)(iVar3 + 0x9214fc) = 0;
    (&DAT_00921454)[iVar2 * 0x70] = 0xffff;
    (&DAT_00921440)[iVar4 * 0x38] = 0;
    bVar5 = DAT_00800940 == -1;
    DAT_00800944 = iVar4;
    (&DAT_009214f8)[iVar4 * 0x38] = 1;
    (&DAT_009214f4)[iVar4 * 0x38] = 1;
    (&DAT_009214f0)[iVar4 * 0x38] = 0;
    (&DAT_00921500)[iVar4 * 0x38] = 0;
    if (bVar5) {
      DAT_00800940 = DAT_00800958;
    }
    if (iVar4 == 0) {
      FUN_006d6b30(0xffffffff);
    }
    _DAT_00921d60 = 0;
    _DAT_00921d5c = 0;
    DAT_00921d44 = 0;
  }
  return;
}

