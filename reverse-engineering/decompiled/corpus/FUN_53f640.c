/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53f640; label: FUN_0053f640
 */

void FUN_0053f640(int *param_1,int param_2,uint param_3,uint param_4,float param_5)

{
  short sVar1;
  int extraout_EDX;
  int iVar2;
  uint uVar3;
  
  *(undefined1 *)(param_2 + 1) = 0xff;
  if (param_1 == (int *)0x0) {
    return;
  }
  if (0x3f < param_3) {
    return;
  }
  iVar2 = param_3 * 0x13c + *param_1;
  uVar3 = (uint)*(ushort *)(iVar2 + 0x30);
  if (*(char *)(iVar2 + 0x33) == '\0') {
    if ((int)uVar3 < (int)param_4) {
      param_4 = uVar3;
    }
LAB_0053f68d:
    if (-1 < (int)param_4) goto LAB_0053f693;
  }
  else {
    uVar3 = uVar3 + 1;
    if ((int)param_4 <= (int)uVar3) goto LAB_0053f68d;
  }
  param_4 = 0;
LAB_0053f693:
  if (0.0 <= param_5) {
    if (1.0 < param_5) {
      param_5 = 1.0;
    }
  }
  else {
    param_5 = 0.0;
  }
  sVar1 = (short)param_4 + 1;
  *(short *)(param_2 + 0x28) = sVar1;
  *(float *)(param_2 + 4) = param_5;
  *(byte *)(param_2 + 1) = (byte)param_3;
  *(short *)(param_2 + 2) = (short)param_4;
  if (((int)sVar1 == uVar3) && (*(char *)(iVar2 + 0x33) != '\0')) {
    *(undefined2 *)(param_2 + 0x28) = 0;
  }
  *(undefined1 *)(param_2 + 0x2a) = 1;
  *(undefined1 *)(param_2 + 0x2b) = 0;
  *(int *)(param_2 + 0x34) = 1 << ((byte)param_3 & 0x1f);
  FUN_0053e900();
  *(undefined4 *)(extraout_EDX + 0x14) = DAT_009242e0;
  *(undefined4 *)(extraout_EDX + 0x18) = DAT_009242e4;
  *(undefined4 *)(extraout_EDX + 0x1c) = DAT_009242e8;
  FUN_0053eb80(extraout_EDX + 8);
  return;
}

