/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51c430; label: FUN_0051c430
 */

uint FUN_0051c430(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_8;
  
  iVar4 = param_2;
  if ((param_4 == *(int *)(param_2 + 400)) && (param_5 == *(int *)(param_2 + 0x194))) {
    return (*(uint *)(param_2 + 0x1e8) >> 1 | *(uint *)(param_2 + 0x1e8)) >> 5 & 1;
  }
  *(uint *)(param_2 + 0x1e8) = *(uint *)(param_2 + 0x1e8) & 0xffffff9f;
  *(int *)(param_2 + 400) = param_4;
  *(int *)(param_2 + 0x194) = param_5;
  bVar1 = *(byte *)(param_5 + 0x10);
  bVar2 = *(byte *)(param_4 + 0x10);
  iVar5 = *(int *)(param_2 + 0x158);
  if (bVar2 == bVar1) {
    iVar7 = *(int *)(iVar5 + 0x7c);
    iVar8 = (uint)*(byte *)(param_4 + 0x11) * 0x5c + iVar7;
    iVar6 = (uint)bVar2 * 0x5c + iVar7;
    iVar7 = (uint)*(byte *)(param_5 + 0x11) * 0x5c + iVar7;
    param_2 = FUN_005be590((int)*(short *)(param_4 + 0x12),0x8000);
    local_8 = FUN_005be590((int)*(short *)(param_5 + 0x12),0x8000);
  }
  else if (bVar2 == *(byte *)(param_5 + 0x11)) {
    iVar7 = *(int *)(iVar5 + 0x7c);
    iVar8 = (uint)*(byte *)(param_4 + 0x11) * 0x5c + iVar7;
    iVar6 = (uint)bVar2 * 0x5c + iVar7;
    iVar7 = (uint)bVar1 * 0x5c + iVar7;
    param_2 = FUN_005be590((int)*(short *)(param_4 + 0x12),0x8000);
    local_8 = (int)*(short *)(param_5 + 0x12);
  }
  else {
    bVar3 = *(byte *)(param_4 + 0x11);
    if (bVar3 == bVar1) {
      param_2 = (int)*(short *)(param_4 + 0x12);
      iVar7 = *(int *)(iVar5 + 0x7c);
      iVar8 = (uint)bVar2 * 0x5c + iVar7;
      iVar6 = (uint)bVar3 * 0x5c + iVar7;
      iVar7 = (uint)*(byte *)(param_5 + 0x11) * 0x5c + iVar7;
      local_8 = FUN_005be590((int)*(short *)(param_5 + 0x12),0x8000);
    }
    else {
      if (bVar3 != *(byte *)(param_5 + 0x11)) {
        return 0;
      }
      iVar7 = *(int *)(iVar5 + 0x7c);
      local_8 = (int)*(short *)(param_5 + 0x12);
      iVar8 = (uint)bVar2 * 0x5c + iVar7;
      iVar6 = (uint)bVar3 * 0x5c + iVar7;
      iVar7 = (uint)*(byte *)(param_5 + 0x10) * 0x5c + iVar7;
      param_2 = (int)*(short *)(param_4 + 0x12);
    }
  }
  iVar5 = FUN_0051b1f0(param_1,iVar7 + 4,iVar5,param_4,1,param_4,*(undefined1 *)(iVar4 + 0x13c),
                       *(undefined1 *)(param_3 + 0x28d),0,0,1);
  if (iVar5 != 0) {
    return 0;
  }
  iVar5 = FUN_0051c150(param_5,param_2,local_8,iVar6,iVar7,iVar4 + 0x198);
  *(uint *)(iVar4 + 0x1e8) =
       *(uint *)(iVar4 + 0x1e8) ^ (iVar5 << 5 ^ *(uint *)(iVar4 + 0x1e8)) & 0x20;
  iVar5 = FUN_0051c150(param_4,local_8,param_2,iVar6,iVar8,iVar4 + 0x1a4);
  *(uint *)(iVar4 + 0x1e8) =
       *(uint *)(iVar4 + 0x1e8) ^ (iVar5 << 6 ^ *(uint *)(iVar4 + 0x1e8)) & 0x40;
  return (*(uint *)(iVar4 + 0x1e8) >> 1 | *(uint *)(iVar4 + 0x1e8)) >> 5 & 1;
}

