/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x487270; label: FUN_00487270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00487270(void)

{
  short sVar1;
  int iVar2;
  int in_ECX;
  int unaff_EDI;
  
  sVar1 = *(short *)(in_ECX + 0x1064);
  if (sVar1 == DAT_007f1814) {
LAB_004873a3:
    iVar2 = 0x70;
  }
  else if (sVar1 == DAT_007f1850) {
    iVar2 = 0x83;
  }
  else {
    if (DAT_007f39e4 == 0) goto LAB_004873bd;
    if (*(char *)(*(int *)(*(int *)(in_ECX + 0x54) + 0x24) + 0x116) == '\f') {
      iVar2 = FUN_0062f1a0(in_ECX + 8);
      if (iVar2 != 3) {
        iVar2 = FUN_0062f1a0(in_ECX + 8);
        if (iVar2 != 0x17) {
          iVar2 = 0xc3;
          goto LAB_004873a8;
        }
      }
      iVar2 = 0xc4;
    }
    else {
      if ((sVar1 == DAT_007f1934) || (sVar1 == DAT_007f1938)) goto LAB_004873a3;
      if (sVar1 == DAT_007f193c) {
        iVar2 = 0x83;
      }
      else if ((sVar1 == DAT_007f1940) || (sVar1 == DAT_007f1aa4)) {
        iVar2 = 0x84;
      }
      else if (sVar1 == DAT_007f1944) {
        iVar2 = 0x86;
      }
      else if (sVar1 == DAT_007f1948) {
        iVar2 = 0xc0;
      }
      else if ((sVar1 == DAT_007f194c) || (sVar1 == DAT_007f1950)) {
LAB_00487375:
        iVar2 = 0xc1;
      }
      else if (sVar1 == DAT_007f1954) {
        iVar2 = 0xc2;
        if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x50) + 0xc) + 0x308) == 0) goto LAB_00487375;
      }
      else if (sVar1 == DAT_007f19bc) {
        iVar2 = 0xc1;
      }
      else {
        if (sVar1 != DAT_007f1920) goto LAB_004873bd;
        iVar2 = 0xc0;
      }
    }
  }
LAB_004873a8:
  if (*(int *)(*(int *)(*(int *)(unaff_EDI + 0x50) + 0xc) + iVar2 * 4) != 0) {
    *(short *)(unaff_EDI + 0x7aa) = (short)iVar2;
    return;
  }
LAB_004873bd:
  *(undefined2 *)(unaff_EDI + 0x7aa) = 0x6c;
  return;
}

