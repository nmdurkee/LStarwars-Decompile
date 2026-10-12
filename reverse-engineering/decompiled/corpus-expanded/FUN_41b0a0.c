/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41b0a0; label: FUN_0041b0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b0a0(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  if (DAT_00876580 == 0) {
    if (DAT_007f39e4 == 0) {
      FUN_00407b60(param_1);
    }
    else {
      FUN_004cbe50();
    }
  }
  else {
    FUN_00481740();
  }
  iVar2 = FUN_0055e470((int)*(short *)(param_1 + 0x1064));
  *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) & 0xfffeffff;
  *(uint *)(param_1 + 0xef0) =
       *(uint *)(param_1 + 0xef0) ^ (iVar2 << 0x17 ^ *(uint *)(param_1 + 0xef0)) & 0x800000;
  *(undefined4 *)(param_1 + 0x3f8) = 0;
  *(undefined4 *)(param_1 + 0x3fc) = 0;
  if ((DAT_0093b2a4 == 0) || ((*(uint *)(param_1 + 0x1f8) & 0x400) != 0)) {
    if (DAT_00923888 == (code *)0x0) goto LAB_0041b179;
    if (*(int *)(param_1 + 0xcbc) == 0) {
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x54) + 0xc);
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 0xcbc) + 4);
    }
    bVar1 = (*DAT_00923888)(uVar3);
    if (bVar1 == 0xff) goto LAB_0041b179;
    if (0x3f < bVar1) goto LAB_0041b161;
    uVar6 = __allshl();
    *(int *)(param_1 + 0x3f8) = (int)uVar6;
    uVar3 = (int)((ulonglong)uVar6 >> 0x20);
  }
  else {
LAB_0041b161:
    *(undefined4 *)(param_1 + 0x3f8) = DAT_00802528;
    uVar3 = DAT_0080252c;
  }
  *(undefined4 *)(param_1 + 0x3fc) = uVar3;
LAB_0041b179:
  *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) | 2;
  *(undefined4 *)(param_1 + 0xed4) = 0x4e6e6b28;
  *(undefined4 *)(param_1 + 0xed8) = 0x4e6e6b28;
  *(undefined1 *)(param_1 + 0x378) = 0;
  if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0) {
    uVar4 = *(uint *)(param_1 + 0xeec) & 0xfffffffb;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xeec) | 4;
  }
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xc7ffe6c0;
  *(undefined4 *)(param_1 + 0x1028) = 0x4e6e6b28;
  *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) & 0x31f7e95c;
  *(undefined4 *)(param_1 + 0x102c) = 0x4e6e6b28;
  *(uint *)(param_1 + 0xef8) = *(uint *)(param_1 + 0xef8) & 0xfffffffc;
  *(uint *)(param_1 + 0xeec) = uVar4;
  *(undefined4 *)(param_1 + 0xf14) = 0;
  *(uint *)(param_1 + 0xeec) = uVar4 & 0x25fffc27 | 8;
  if ((*(uint *)(param_1 + 0x1f8) & 0x400) == 0) {
    uVar5 = *(uint *)(param_1 + 0xef4) | 0x40000;
  }
  else {
    uVar5 = *(uint *)(param_1 + 0xef4) & 0xfffbffff;
  }
  *(uint *)(param_1 + 0xef4) = uVar5;
  *(undefined4 *)(param_1 + 0x104c) = 0;
  uVar3 = _DAT_00855f74;
  *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) & 0xefffffff;
  *(undefined4 *)(param_1 + 0x4b8) = uVar3;
  if (*(float *)(param_1 + 0x4b8) <= 0.0) {
    uVar5 = *(uint *)(param_1 + 0x4b0) & 0xf3ffffff;
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x4b0) & 0xf7ffffff | 0x4000000;
  }
  *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) & 0xfe5fffff;
  *(undefined4 *)(param_1 + 0xec8) = 0x3f800000;
  *(uint *)(param_1 + 0x4b0) = uVar5;
  *(uint *)(param_1 + 0xeec) = uVar4 & 0x25f3fc27 | 8;
  if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x8000000) == 0) {
    uVar4 = uVar4 & 0x25e3fc27 | 8;
  }
  else {
    uVar4 = uVar4 & 0x25f3fc27 | 0x100008;
  }
  *(byte *)(param_1 + 0x7c5) = *(byte *)(param_1 + 0x7c5) & 0xfd;
  *(undefined4 *)(param_1 + 0xec4) = 0;
  *(uint *)(param_1 + 0x4b0) = *(uint *)(param_1 + 0x4b0) & 0xffffafff;
  *(undefined4 *)(param_1 + 0x3a8) = 0x4e6e6b28;
  *(undefined4 *)(param_1 + 0x3b8) = 0x4e6e6b28;
  *(undefined4 *)(param_1 + 0x454) = 0;
  *(uint *)(param_1 + 0xeec) = uVar4;
  *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) & 0xfadff7fe;
  *(undefined4 *)(param_1 + 0xecc) = 0;
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xfeffffff;
  *(undefined4 *)(param_1 + 0xec0) = 0;
  *(undefined4 *)(param_1 + 0x39c) = 0;
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  *(undefined4 *)(param_1 + 0x3ac) = 0;
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  *(undefined4 *)(param_1 + 0x2ac) = 0;
  *(undefined4 *)(param_1 + 0xeb0) = 0;
  *(undefined4 *)(param_1 + 0xeb4) = 0;
  *(undefined4 *)(param_1 + 0x10a4) = 0;
  *(undefined4 *)(param_1 + 0x10a8) = 0;
  *(undefined4 *)(param_1 + 0xeb8) = 0;
  *(undefined4 *)(param_1 + 0xebc) = 0;
  _memset((void *)(param_1 + 0xf3c),0,0x68);
  *(undefined1 *)(param_1 + 0x107d) = 0;
  *(undefined4 *)(param_1 + 0xfd8) = 0;
  *(undefined4 *)(param_1 + 0x3bc) = 0;
  *(undefined4 *)(param_1 + 0x298) = 0;
  *(undefined4 *)(param_1 + 0x2a0) = 0;
  *(undefined4 *)(param_1 + 0x2a4) = 0;
  if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x4000) == 0) ||
     ((*(char *)(param_1 + 0x280) != -1 && (*(int *)(param_1 + 0xcd0) == 0)))) {
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xfffffffd;
  }
  else {
    *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) | 2;
  }
  if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x90) & 0x2000) == 0) {
    *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0x7fffffff;
  }
  else {
    *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) | 0x80000000;
  }
  *(uint *)(param_1 + 0x1fc) = *(uint *)(param_1 + 0x1fc) & 0xffe7f7ff;
  *(uint *)(param_1 + 0xef4) = *(uint *)(param_1 + 0xef4) & 0xfffffffb;
  *(undefined4 *)(param_1 + 0x1034) = 0x3f800000;
  *(uint *)(param_1 + 0xef0) = *(uint *)(param_1 + 0xef0) & 0xfbbfffff;
  *(uint *)(param_1 + 0xef8) = *(uint *)(param_1 + 0xef8) & 0xfffffff3;
  *(undefined4 *)(param_1 + 0x1038) = 0;
  *(undefined4 *)(param_1 + 0x10b4) = 0;
  *(undefined1 *)(param_1 + 0x1083) = 0;
  *(undefined4 *)(param_1 + 0x10cc) = 0;
  FUN_00414ad0(param_1);
  return;
}

