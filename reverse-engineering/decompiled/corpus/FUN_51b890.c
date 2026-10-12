/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51b890; label: FUN_0051b890
 */

void FUN_0051b890(int param_1,float *param_2,int param_3,uint param_4)

{
  float fVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  float local_18 [2];
  float local_10;
  undefined4 local_c [2];
  float local_4;
  
  if ((param_3 == 0) || (*(int *)(param_1 + 0xd0) == 0)) {
    *(int *)(param_1 + 0x15c) = param_3;
    *(undefined1 *)(param_1 + 0x13c) = 0xff;
    *(undefined1 *)(param_1 + 0x13d) = 0;
  }
  else if (((*(int *)(param_1 + 0x15c) != param_3) || (*(byte *)(param_1 + 0x160) != param_4)) ||
          (((*(ushort *)(param_1 + 0x166) & 1) != 0 && ((*(ushort *)(param_1 + 0x166) & 4) == 0))))
  {
    uVar2 = *(uint *)(param_3 + param_4 * 4);
    if (uVar2 != 0) {
      if ((uVar2 & 0x98000000) != 0) {
        FUN_0051b7f0(param_1);
        return;
      }
      if ((*(uint *)(param_1 + 500) & uVar2) == 0) {
        return;
      }
    }
    if ((*(int *)(param_1 + 0x15c) != param_3) || (*(byte *)(param_1 + 0x160) != param_4)) {
      *(char *)(param_1 + 0x160) = (char)param_4;
      *(int *)(param_1 + 0x15c) = param_3;
      *(undefined1 *)(param_1 + 0x139) = 0;
      iVar4 = (uint)*(byte *)(param_3 + 0x10) * 0x5c + *(int *)(*(int *)(param_1 + 0x158) + 0x7c);
      local_18[0] = *param_2 - *(float *)(iVar4 + 4);
      local_10 = param_2[2] - *(float *)(iVar4 + 0xc);
      FUN_005b3620(local_c,local_18,-(int)*(short *)(param_3 + 0x12));
      fVar1 = *(float *)(param_3 + 0x1c);
      *(ushort *)(param_1 + 0x166) = *(ushort *)(param_1 + 0x166) & 0xfffb;
      *(float *)(param_1 + 0x168) = local_4 / fVar1;
      *(undefined4 *)(param_1 + 0x16c) = local_c[0];
    }
    if (((*(ushort *)(param_1 + 0x166) & 1) != 0) && ((*(ushort *)(param_1 + 0x166) & 4) == 0)) {
      if ((*(char *)(param_1 + 0x13c) != -1) &&
         (uVar3 = __allshl(), (uVar3 & *(ushort *)(*(int *)(param_1 + 0x15c) + 0x14)) == 0)) {
        *(undefined1 *)(param_1 + 0x13c) = 0xff;
      }
      if (*(char *)(param_1 + 0x13c) == -1) {
        FUN_0051b7f0(param_1);
      }
      *(ushort *)(param_1 + 0x166) = *(ushort *)(param_1 + 0x166) | 4;
      return;
    }
  }
  return;
}

