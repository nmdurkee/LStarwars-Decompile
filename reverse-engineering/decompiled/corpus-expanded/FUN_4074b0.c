/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x4074b0; label: FUN_004074b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004074b0(float param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  float local_c [3];
  
  iVar4 = (int)param_1;
  uVar6 = (uint)(*(float *)((int)param_1 + 0x168) <= 0.5);
  iVar1 = *(int *)(*(int *)((int)param_1 + 0x158) + 0x7c);
  iVar2 = *(int *)((int)param_1 + 0x15c);
  iVar7 = (uint)*(byte *)(iVar2 + 0x10 + uVar6) * 0x5c;
  iVar5 = (uint)*(byte *)((uVar6 == 0) + 0x10 + iVar2) * 0x5c + iVar1;
  iVar8 = iVar7 + iVar1;
  local_c[0] = *(float *)(iVar7 + 4 + iVar1) - *(float *)(iVar5 + 4);
  local_c[1] = 0.0;
  local_c[2] = *(float *)(iVar8 + 0xc) - *(float *)(iVar5 + 0xc);
  param_1 = *(float *)(iVar5 + 0x10) - *(float *)((int)param_1 + 0x120);
  if (param_1 < 0.0) {
    param_1 = 0.0;
  }
  FUN_005b3830(local_c,local_c,param_1 / *(float *)(iVar2 + 0x1c));
  iVar1 = iVar4 + 0x104;
  FUN_005b37d0(iVar1,(float *)(iVar5 + 4),local_c);
  local_c[0] = *(float *)(iVar4 + 0x16c);
  local_c[1] = 0.0;
  local_c[2] = 0.0;
  FUN_005b3620(local_c,local_c,(int)*(short *)(*(int *)(iVar4 + 0x15c) + 0x12));
  FUN_005b37d0(iVar1,iVar1,local_c);
  *(undefined4 *)(iVar4 + 0x110) = 0;
  fVar9 = (float10)FUN_005b3cf0(param_2 + 0x17,iVar1,local_c);
  if (_DAT_00801c6c * _DAT_00801c6c <= (float)fVar9) goto LAB_0040761c;
  iVar1 = *(int *)(iVar4 + 0x15c);
  if (*(int *)(iVar4 + 0x1d0) == iVar1) {
    fVar3 = *(float *)(iVar8 + 0x10) / *(float *)(iVar1 + 0x1c);
    if (uVar6 == 0) {
      if (*(float *)(iVar4 + 0x1dc) <= fVar3) goto LAB_00407642;
    }
    else if (1.0 - fVar3 <= *(float *)(iVar4 + 0x1dc)) goto LAB_00407642;
LAB_0040761c:
    *(undefined1 *)(iVar4 + 0x139) = 0;
  }
  else {
LAB_00407642:
    if (*(byte *)(iVar4 + 0x160) == uVar6) {
      return 0;
    }
    if (*(char *)(iVar4 + 0x139) == '\0') {
      if (*(char *)(iVar1 + 0x16) == '\0') {
        *(undefined1 *)(iVar4 + 0x139) = 1;
      }
    }
    else if ((*(char *)(iVar4 + 0x139) == '\x01') && (*(char *)(iVar1 + 0x16) != '\0')) {
      FUN_0043cbb0(*param_2,iVar8,0,0);
    }
  }
  *(ushort *)((int)param_2 + 0x292) = *(ushort *)((int)param_2 + 0x292) | 0x2000;
  return 1;
}

