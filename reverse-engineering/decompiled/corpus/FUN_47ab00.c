/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x47ab00; label: FUN_0047ab00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047ab00(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 local_84 [64];
  undefined1 local_44 [64];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_90;
  if ((in_ECX == -1) &&
     ((param_2 == -1 ||
      (in_ECX = (int)*(char *)(param_2 * 0x9c + 0x86 + DAT_00951354), in_ECX == -1))))
  goto LAB_0047af4d;
  uVar1 = FUN_006e6b90();
  iVar2 = FUN_0059b6a0(in_ECX * 0x1c + DAT_00956290,5,4);
  iVar3 = FUN_0059b6a0(in_ECX * 0x1c + DAT_00956290,5,5);
  if (in_ECX == 0) {
    iVar4 = (int)DAT_00880ff8;
  }
  else if (in_ECX == 1) {
    iVar4 = (int)DAT_00881000;
  }
  else if (in_ECX == 2) {
    iVar4 = (int)DAT_00881008;
  }
  else if (in_ECX == 3) {
    iVar4 = (int)DAT_00881010;
  }
  else {
    iVar4 = (int)DAT_00881018;
    if (in_ECX != 4) {
      iVar4 = (int)DAT_00881020;
    }
  }
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + iVar4 * 4),0,_DAT_007f92ec,0x3f800000,_DAT_007f92f0,
               _DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,DAT_00879b1c,0x3fd9999a,1,0,0
               ,uVar1);
  if (param_3 == 0) {
    local_8c = 0xbecccccd;
    local_88 = *(undefined4 *)(&DAT_0086e454 + in_ECX * 0xc);
    local_90 = _DAT_007f92e4 + 0.125;
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008806f8 * 4),0x3ecccccd,local_90,0x3f800000,
                 _DAT_007f92e8,_DAT_007f92e8,_DAT_007f92e8,0,0xbf,0,0x7f,0x3f333333,1,0,0,uVar1);
    FUN_0054bb30(*(undefined4 *)(&DAT_0086e458 + in_ECX * 0xc),local_84);
    FUN_0050c780(local_84,0x3ecccccd,_DAT_007f92e4,0x3f800000,_DAT_007f92f0,_DAT_007f92f0,
                 _DAT_007f92f0,0,0xff,0xff,0xff,uVar1);
  }
  else if (param_3 == 1) {
    if (iVar2 == -1) goto LAB_0047af4d;
    local_88 = (&DAT_0086e0fc)[iVar2 * 3];
    local_8c = 0;
  }
  else if (param_3 == 2) {
    if (iVar3 == -1) goto LAB_0047af4d;
    local_88 = (&DAT_0086e0fc)[iVar3 * 3];
    local_8c = 0;
  }
  else {
    local_88 = 0;
    local_8c = 0;
    if (param_3 == -1) {
      iVar4 = 0;
      iVar5 = 0;
      if (iVar2 != -1) {
        local_90 = (float)(uint)*(ushort *)(DAT_00951354 + 0x84 + iVar2 * 0x9c);
        iVar4 = 1;
        if ((float)(&DAT_0086e0fc)[iVar2 * 3] < (float)(int)local_90) {
          iVar4 = 1;
          iVar5 = 1;
        }
      }
      if (iVar3 != -1) {
        local_90 = (float)(uint)*(ushort *)(iVar3 * 0x9c + 0x84 + DAT_00951354);
        iVar4 = iVar4 + 1;
        if ((float)(&DAT_0086e0fc)[iVar3 * 3] < (float)(int)local_90) {
          iVar5 = iVar5 + 1;
        }
      }
      if ((DAT_0093b31c != 0) && (iVar4 = iVar4 + 1, (&DAT_0086e45c)[in_ECX * 0xc] != '\0')) {
        iVar5 = iVar5 + 1;
      }
      FUN_00478d20(0xd3,0,_DAT_007f92e4,param_1,iVar5,iVar4);
      goto LAB_0047af4d;
    }
  }
  local_90 = _DAT_007f92e4 + 0.125;
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008806f4 * 4),local_8c,local_90,0x3f800000,
               _DAT_007f92e8,_DAT_007f92e8,_DAT_007f92e8,0,0xbf,0,0x7f,0x3f333333,1,0,0,uVar1);
  FUN_0054bbc0(local_88,1,1,1,local_44);
  FUN_0050c780(local_44,local_8c,_DAT_007f92e4,0x3f800000,_DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,
               0,0xff,0xff,0xff,uVar1);
LAB_0047af4d:
  __security_check_cookie(local_4 ^ (uint)&local_90);
  return;
}

