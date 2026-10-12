/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x509ab0; label: FUN_00509ab0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00509ab0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = DAT_00800944;
  if (DAT_00800944 != 0) {
    iVar4 = DAT_00800944 * 0xe0;
    iVar2 = DAT_00800944 * 0x38;
    if ((code *)(&PTR_LAB_00800ab8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7] != (code *)0x0)
    {
      (*(code *)(&PTR_LAB_00800ab8)[(short)(&DAT_00921454)[DAT_00800944 * 0x70] * 7])
                (&DAT_00921440 + iVar2);
    }
    iVar5 = DAT_00800944;
    FUN_005097d0(&DAT_00921440 + iVar2);
    iVar5 = iVar5 + -1;
    (&DAT_00921454)[iVar3 * 0x70] = 0xffff;
    (&DAT_009214f4)[iVar3 * 0x38] = 0;
    (&DAT_009214f8)[iVar3 * 0x38] = 1;
    *(undefined4 *)(iVar4 + 0x9214fc) = 0;
    (&DAT_009214f8)[iVar5 * 0x38] = 1;
    (&DAT_00921440)[iVar5 * 0x38] = 0;
    (&DAT_009214f4)[iVar5 * 0x38] = 1;
    sVar1 = (&DAT_00921454)[iVar5 * 0x70];
    DAT_00800944 = iVar5;
    (&DAT_009214f0)[iVar5 * 0x38] = 0;
    (&DAT_00921500)[iVar5 * 0x38] = 0;
    if ((sVar1 != -1) && ((code *)(&PTR_FUN_00800aac)[sVar1 * 7] != (code *)0x0)) {
      (*(code *)(&PTR_FUN_00800aac)[sVar1 * 7])(&DAT_00921440 + iVar5 * 0x38);
      iVar5 = DAT_00800944;
    }
    if (DAT_00800940 == -1) {
      DAT_00800940 = DAT_00800958;
    }
    _DAT_00921d5c = 0;
    _DAT_00921d60 = 0;
    DAT_00921d44 = 0;
    if (iVar5 == 0) {
      FUN_006d6b30(0xffffffff);
    }
  }
  return;
}

