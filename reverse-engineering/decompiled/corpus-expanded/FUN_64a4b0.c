/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64a4b0; label: FUN_0064a4b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064a4b0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  undefined1 *puVar4;
  
  DAT_0081020c = param_1;
  DAT_0291f664 = (void *)(*param_2 + 0xfU & 0xfffffff0);
  *param_2 = (int)DAT_0291f664;
  *param_2 = *param_2 + DAT_0081020c * 0x220;
  if (DAT_0291f664 != (void *)0x0) {
    _memset(DAT_0291f664,0,DAT_0081020c * 0x220);
  }
  DAT_008102d8 = 0;
  _memset(&DAT_02913a58,0,0xbc00);
  puVar4 = &DAT_02913af8;
  do {
    iVar1 = 0;
    puVar3 = (undefined2 *)(puVar4 + -0x10);
    do {
      *puVar3 = 0xffff;
      puVar4[iVar1] = 0xff;
      iVar1 = iVar1 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar1 < 8);
    puVar4 = puVar4 + 0x178;
  } while ((int)puVar4 < 0x291f6f8);
  DAT_02920a94 = 0;
  _memset(&DAT_0291f7a8,0,0x10e0);
  puVar2 = &DAT_0291f7b4;
  do {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 0x1b;
  } while ((int)puVar2 < 0x2920894);
  DAT_0291f688 = 0xffffffff;
  DAT_0291f68c = 0xffffffff;
  DAT_0291f690 = 0xffffffff;
  DAT_0291f694 = 0xffffffff;
  _DAT_0291f698 = 0xffffffff;
  _DAT_0291f69c = 0xffffffff;
  _DAT_0291f6a0 = 0xffffffff;
  _DAT_0291f6a4 = 0xffffffff;
  _DAT_0291f6a8 = 0xffffffff;
  _DAT_0291f6ac = 0xffffffff;
  _DAT_0291f6b0 = 0xffffffff;
  _DAT_0291f6b4 = 0xffffffff;
  _DAT_0291f6b8 = 0xffffffff;
  _DAT_0291f6bc = 0xffffffff;
  _DAT_0291f6c0 = 0xffffffff;
  _DAT_0291f6c4 = 0xffffffff;
  _DAT_0291f6c8 = 0xffffffff;
  _DAT_0291f6cc = 0xffffffff;
  _DAT_0291f6d0 = 0xffffffff;
  _DAT_0291f6d4 = 0xffffffff;
  _DAT_0291f6d8 = 0xffffffff;
  _DAT_0291f6dc = 0xffffffff;
  _DAT_0291f6e0 = 0xffffffff;
  _DAT_0291f6e4 = 0xffffffff;
  _DAT_0291f6e8 = 0xffffffff;
  _DAT_0291f6ec = 0xffffffff;
  _DAT_0291f6f0 = 0xffffffff;
  _DAT_0291f6f4 = 0xffffffff;
  _DAT_0291f6f8 = 0xffffffff;
  _DAT_0291f6fc = 0xffffffff;
  _DAT_0291f700 = 0xffffffff;
  _DAT_0291f704 = 0xffffffff;
  DAT_02920a98 = 0;
  _DAT_0292089c = 0;
  _DAT_02913a2c = 0;
  DAT_029208a0 = 0;
  DAT_02913a30 = 0;
  DAT_029208a4 = 0;
  DAT_02913a34 = 0;
  _DAT_029208a8 = 0;
  _DAT_02913a38 = 0;
  _DAT_029208ac = 0;
  _DAT_02913a3c = 0;
  _DAT_029208b0 = 0;
  _DAT_02913a40 = 0;
  _DAT_029208b4 = 0;
  _DAT_02913a44 = 0;
  _DAT_029208b8 = 0;
  _DAT_02913a48 = 0;
  DAT_029208d0 = 0;
  DAT_029208d4 = 0;
  DAT_029208d8 = 0;
  DAT_029208dc = 0;
  _DAT_029208e0 = 0;
  _DAT_029208e4 = 0;
  _DAT_029208e8 = 0;
  _DAT_029208ec = 0;
  _DAT_029208f0 = 0;
  _DAT_029208f4 = 0;
  _DAT_029208f8 = 0;
  _DAT_029208fc = 0;
  _DAT_02920900 = 0;
  _DAT_02920904 = 0;
  _DAT_02920908 = 0;
  _DAT_0292090c = 0;
  _DAT_02920910 = 0;
  _DAT_02920914 = 0;
  _DAT_02920918 = 0;
  _DAT_0292091c = 0;
  _DAT_02920920 = 0;
  _DAT_02920924 = 0;
  _DAT_02920928 = 0;
  _DAT_0292092c = 0;
  _DAT_02920930 = 0;
  _DAT_02920934 = 0;
  _DAT_02920938 = 0;
  _DAT_0292093c = 0;
  _DAT_02920940 = 0;
  _DAT_02920944 = 0;
  DAT_0291f780 = 0;
  _DAT_02920948 = 0;
  _DAT_0292094c = 0;
  return;
}

