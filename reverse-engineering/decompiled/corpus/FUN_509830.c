/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x509830; label: FUN_00509830
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00509830(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  short sVar6;
  undefined4 *puVar7;
  int iVar8;
  
  puVar7 = (undefined4 *)0x0;
  FUN_006d6b30(1);
  iVar2 = DAT_00800944;
  iVar4 = 0;
  _DAT_00921d90 = param_1;
  iVar8 = -1;
  if (0 < DAT_0080094c) {
    piVar5 = &DAT_00800aa8;
    do {
      iVar8 = iVar4;
      if (*piVar5 == param_1) break;
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 7;
      iVar8 = -1;
    } while (iVar4 < DAT_0080094c);
  }
  *(undefined4 *)(DAT_00800944 * 0xe0 + 0x9214fc) = 0;
  uVar1 = (&DAT_00921454)[iVar2 * 0x70];
  if ((&DAT_00921454)[iVar2 * 0x70] != -1) {
    iVar4 = (short)(&DAT_00921454)[iVar2 * 0x70] * 0x1c;
    if (*(short *)(&DAT_00800abc + iVar4) != -1) {
      *(undefined2 *)(&DAT_00800abc + iVar4) = (&DAT_00921448)[iVar2 * 0x70];
    }
    if (*(short *)(&DAT_00800abe + iVar4) != -1) {
      *(undefined2 *)(&DAT_00800abe + iVar4) = (&DAT_0092144a)[iVar2 * 0x70];
    }
  }
  if (iVar8 == -1) {
    (&DAT_00921454)[iVar2 * 0x70] = 0xffff;
  }
  else {
    iVar4 = iVar2 + 1;
    if (9 < iVar2 + 1) {
      iVar4 = iVar2;
    }
    sVar6 = (short)iVar8;
    param_1._0_1_ = (undefined1)uVar1;
    iVar8 = iVar4 * 0xe0;
    puVar7 = &DAT_00921440 + iVar4 * 0x38;
    iVar2 = (&DAT_00800aa8)[sVar6 * 7];
    DAT_00800944 = iVar4;
    *puVar7 = 0;
    (&DAT_00921444)[iVar4 * 0x38] = 0;
    (&DAT_0092144c)[iVar4 * 0x70] = 0;
    (&DAT_0092144e)[iVar4 * 0x70] = 0;
    (&DAT_00921450)[iVar4 * 0x70] = 0;
    (&DAT_00921452)[iVar4 * 0x70] = 0;
    (&DAT_0092151c)[iVar4 * 0x38] = 0;
    *(undefined4 *)(&DAT_009214cc + iVar4 * 0x70) = 0;
    (&DAT_009214f8)[iVar4 * 0x38] = 1;
    (&DAT_009214f4)[iVar4 * 0x38] = 1;
    (&DAT_009214f0)[iVar4 * 0x38] = 0;
    (&DAT_00921500)[iVar4 * 0x38] = 0;
    (&DAT_00921490)[iVar4 * 0x38] = 0;
    (&DAT_00921456)[iVar8] = (undefined1)param_1;
    (&DAT_00921454)[iVar4 * 0x70] = sVar6;
    DAT_00921d24 = 1;
    if ((iVar2 != -1) && ((code *)(&PTR_LAB_00800ab0)[sVar6 * 7] != (code *)0x0)) {
      (*(code *)(&PTR_LAB_00800ab0)[sVar6 * 7])(puVar7);
    }
    (&DAT_00921452)[iVar4 * 0x70] = (&DAT_009214cc)[iVar4 * 0x70] + -1;
    DAT_00921d24 = 0;
    if ((param_2 < (short)(&DAT_0092144e)[iVar4 * 0x70]) ||
       ((short)((&DAT_009214cc)[iVar4 * 0x70] + -1) < param_2)) {
      (&DAT_0092144a)[iVar4 * 0x70] = 0;
    }
    else {
      (&DAT_0092144a)[iVar4 * 0x70] = (short)param_2;
    }
    pcVar3 = (code *)(&PTR_FUN_00800aac)[(short)(&DAT_00921454)[iVar4 * 0x70] * 7];
    (&DAT_00921448)[iVar4 * 0x70] = 0;
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(puVar7);
    }
    if (*(short *)(&DAT_00800abc + (short)(&DAT_00921454)[iVar4 * 0x70] * 0x1c) != -1) {
      (&DAT_00921448)[iVar4 * 0x70] =
           *(short *)(&DAT_00800abc + (short)(&DAT_00921454)[iVar4 * 0x70] * 0x1c);
    }
    sVar6 = (&DAT_0092144c)[iVar4 * 0x70];
    if (((short)(&DAT_00921448)[iVar4 * 0x70] < sVar6) ||
       (sVar6 = (&DAT_00921450)[iVar4 * 0x70], sVar6 < (short)(&DAT_00921448)[iVar4 * 0x70])) {
      (&DAT_00921448)[iVar4 * 0x70] = sVar6;
    }
    sVar6 = (&DAT_0092144e)[iVar4 * 0x70];
    if ((param_2 < sVar6) || ((short)(&DAT_00921452)[iVar4 * 0x70] < param_2)) {
      if (*(short *)(&DAT_00800abe + (short)(&DAT_00921454)[iVar4 * 0x70] * 0x1c) != -1) {
        (&DAT_0092144a)[iVar4 * 0x70] =
             *(short *)(&DAT_00800abe + (short)(&DAT_00921454)[iVar4 * 0x70] * 0x1c);
      }
      if (((short)(&DAT_0092144a)[iVar4 * 0x70] < sVar6) ||
         (sVar6 = (&DAT_00921452)[iVar4 * 0x70], sVar6 < (short)(&DAT_0092144a)[iVar4 * 0x70])) {
        (&DAT_0092144a)[iVar4 * 0x70] = sVar6;
      }
      *puVar7 = 0;
      (&DAT_00921457)[iVar8] = 0xff;
      (&DAT_00921444)[iVar4 * 0x38] = 0;
      (&DAT_0092145c)[iVar4 * 0x38] = 0;
      (&DAT_00921458)[iVar4 * 0x38] = 0;
    }
    else {
      *puVar7 = 0;
      (&DAT_0092144a)[iVar4 * 0x70] = (short)param_2;
      (&DAT_00921444)[iVar4 * 0x38] = 0;
      (&DAT_00921457)[iVar8] = 0xff;
      (&DAT_0092145c)[iVar4 * 0x38] = 0;
      (&DAT_00921458)[iVar4 * 0x38] = 0;
    }
  }
  _DAT_00921d5c = 0;
  _DAT_00921d60 = 0;
  DAT_00921d44 = 0;
  return puVar7;
}

