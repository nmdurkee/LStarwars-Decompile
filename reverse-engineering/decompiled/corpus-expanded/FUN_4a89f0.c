/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a89f0; label: FUN_004a89f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a89f0(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  int *piVar5;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(char *)(unaff_ESI + 0x107f) < '\x02') {
    iVar1 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x1e0);
    if (iVar1 != -1) {
      for (iVar3 = FUN_0062c350(0x40a00000,_DAT_00925018); 0 < iVar3; iVar3 = iVar3 + -1) {
        iVar4 = FUN_0054fa60();
        fVar2 = (float)iVar4 * 1.5259022e-05;
        local_c = *(float *)(unaff_ESI + 0x80) +
                  fVar2 * (*(float *)(unaff_ESI + 0x98) - *(float *)(unaff_ESI + 0x80));
        local_8 = (*(float *)(unaff_ESI + 0x9c) - *(float *)(unaff_ESI + 0x84)) * fVar2 +
                  *(float *)(unaff_ESI + 0x84);
        local_4 = (*(float *)(unaff_ESI + 0xa0) - *(float *)(unaff_ESI + 0x88)) * fVar2 +
                  *(float *)(unaff_ESI + 0x88);
        FUN_00684c90(iVar1,&local_c,1,0,0);
      }
    }
  }
  else if ((*(int *)(unaff_ESI + 0xcd0) != 0) && (*(char *)(unaff_ESI + 0x280) == -1)) {
    piVar5 = &DAT_0093d7f0;
    do {
      iVar1 = *piVar5;
      if ((((iVar1 != 0) && ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) &&
          (*(int *)(iVar1 + 0xcd0) != 0)) &&
         (((*(uint *)(iVar1 + 0x1f0) & *(uint *)(unaff_ESI + 0x1e8)) != 0 ||
           (*(uint *)(iVar1 + 500) & *(uint *)(unaff_ESI + 0x1ec)) != 0 &&
          (*(float *)(unaff_ESI + 0x1018) <= 0.0)))) {
        FUN_00438230(iVar1);
      }
      piVar5 = piVar5 + 1;
    } while ((int)piVar5 < 0x93d7f8);
    return;
  }
  return;
}

