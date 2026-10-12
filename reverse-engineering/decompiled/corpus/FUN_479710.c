/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x479710; label: FUN_00479710
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479710(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  char *pcVar5;
  float10 extraout_ST0;
  float local_88;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_88;
  iVar1 = in_ECX * 0x9c + DAT_00951354;
  uVar4 = FUN_006e6b90();
  if ((&DAT_0086e0f8)[in_ECX * 0xc] == '\0') {
    if ((&DAT_0086e0f9)[in_ECX * 0xc] == '\0') {
      cVar2 = *(char *)(iVar1 + 0x86);
      if ((cVar2 == -1) || (*(char *)(iVar1 + 0x87) == -1)) goto LAB_00479966;
      local_88 = _DAT_007f92f0;
      FUN_00478b00(0,_DAT_007f92e4,10,(float)extraout_ST0);
      _sprintf(local_84,"%s, %s %i",
               *(undefined4 *)(DAT_00926c20 + *(short *)(DAT_00956290 + cVar2 * 0x1c) * 4),
               *(undefined4 *)(DAT_00926c20 + DAT_00880690 * 4),
               *(char *)(in_ECX * 0x9c + 0x87 + DAT_00951354) + 1);
      goto LAB_004798f3;
    }
    local_88 = _DAT_007f92f0;
    FUN_00478b00(0,_DAT_007f92e4,10,(float)extraout_ST0);
    pcVar5 = *(char **)(DAT_00926c20 + *(short *)(iVar1 + 0x78) * 4);
  }
  else {
    local_88 = _DAT_007f92e8;
    if ((*(short *)(iVar1 + 0x8a) != -1) &&
       (iVar3 = *(int *)(*(short *)(iVar1 + 0x8a) * 0x4c + DAT_0093b274), iVar3 != -1)) {
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + iVar3 * 4),0,_DAT_007f92e4,0x3f800000,
                   _DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,
                   DAT_00879b1c,0x3fd9999a,1,0,0,uVar4);
    }
    _sprintf(local_84,"(%s)",*(undefined4 *)(DAT_00926c20 + *(short *)(iVar1 + 0x78) * 4));
LAB_004798f3:
    pcVar5 = local_84;
  }
  if ((0.0 < local_88) && (pcVar5 != (char *)0x0)) {
    FUN_0050d910(pcVar5,0,_DAT_007f92ec,0x3f800000,local_88,local_88,local_88,0,DAT_007f92f4,
                 DAT_007f92f8,DAT_00879b1c,0x3fd9999a,1,0,0,uVar4);
  }
LAB_00479966:
  __security_check_cookie(local_4 ^ (uint)&local_88);
  return;
}

