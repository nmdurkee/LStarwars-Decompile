/* Ghidra pseudocode, not original source.
 * ev_b786d52b0c6475300075d44c367bc307b08211d5064c161e2619fa192a4bae5f
 * Entry: 0x56fb70; label: FUN_0056fb70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056fb70(int param_1)

{
  float fVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  char *pcVar4;
  int iVar5;
  int unaff_ESI;
  float10 fVar6;
  
  iVar5 = 0;
  if (*(ushort *)(PTR_PTR_008033b0 + 8) != 0) {
    pcVar4 = (char *)(*(int *)PTR_PTR_008033b0 + 0xc);
    do {
      if (*pcVar4 == *(char *)(unaff_ESI + 0x14)) goto LAB_0056fba0;
      iVar5 = iVar5 + 1;
      pcVar4 = pcVar4 + 0x38;
    } while (iVar5 < (int)(uint)*(ushort *)(PTR_PTR_008033b0 + 8));
  }
  iVar5 = 0;
LAB_0056fba0:
  *(char *)(unaff_ESI + 0x25) = (char)iVar5;
  FUN_0067a6d0();
  fVar6 = (float10)FUN_005506f0(0,unaff_ESI + 8,0x40a00000,0xffffffff);
  fVar1 = (float)fVar6;
  *(float *)(unaff_ESI + 0x1c) = fVar1;
  if (fVar1 != 2e+06) {
    if (*(float *)(unaff_ESI + 0xc) < fVar1 == (*(float *)(unaff_ESI + 0xc) == fVar1)) {
      FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x20,unaff_ESI + 0x22);
    }
    else {
      *(undefined4 *)(unaff_ESI + 0x1c) = 0x49f42400;
    }
  }
  *(byte *)(unaff_ESI + 0x17) = *(byte *)(unaff_ESI + 0x17) & 0xe7 | 7;
  if (*(char *)(*(int *)PTR_PTR_008033b0 + 0xd + (uint)*(byte *)(unaff_ESI + 0x25) * 0x38) == '\0')
  {
    *(undefined1 *)(unaff_ESI + 0x16) = 0;
  }
  else {
    iVar5 = FUN_0054fa60();
    *(char *)(unaff_ESI + 0x16) =
         (char)(iVar5 / ((int)(0xffff / (ulonglong)
                                        (longlong)
                                        (int)(uint)*(byte *)(*(int *)PTR_PTR_008033b0 + 0xd +
                                                            (uint)*(byte *)(unaff_ESI + 0x25) * 0x38
                                                            )) + 1));
  }
  if (*(int *)(param_1 + 0x13c) == 0) {
    uVar2 = 0xff;
  }
  else {
    uVar2 = FUN_005d92b0(*(int *)(param_1 + 0x13c),unaff_ESI + 8);
  }
  *(undefined1 *)(unaff_ESI + 0x24) = uVar2;
  uVar3 = FUN_0054fa60();
  *(undefined4 *)(unaff_ESI + 0x28) = 0;
  *(undefined2 *)(unaff_ESI + 0x26) = uVar3;
  *(byte *)(unaff_ESI + 0x17) = *(byte *)(unaff_ESI + 0x17) & 0xbf | 0x20;
  return;
}

