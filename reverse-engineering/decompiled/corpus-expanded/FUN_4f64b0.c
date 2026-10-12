/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f64b0; label: FUN_004f64b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f64b0(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int unaff_ESI;
  int unaff_EDI;
  short asStack_28 [18];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)asStack_28;
  asStack_28[1] = 0;
  iVar4 = 0;
  do {
    sVar1 = (*(short *)((int)&DAT_00916fde + iVar4) + *(short *)((int)asStack_28 + iVar4 + 2)) * 2;
    sVar3 = (*(short *)((int)&DAT_00916fe0 + iVar4) + sVar1) * 2;
    *(short *)((int)asStack_28 + iVar4 + 4) = sVar1;
    sVar1 = *(short *)((int)&DAT_00916fe2 + iVar4);
    *(short *)((int)asStack_28 + iVar4 + 6) = sVar3;
    sVar2 = *(short *)((int)&DAT_00916fe4 + iVar4);
    sVar1 = (sVar1 + sVar3) * 2;
    *(short *)((int)asStack_28 + iVar4 + 8) = sVar1;
    *(short *)((int)asStack_28 + iVar4 + 10) = (sVar2 + sVar1) * 2;
    iVar4 = iVar4 + 8;
  } while (iVar4 < 0x1f);
  iVar4 = 0;
  if (0 < param_1) {
    do {
      *(short *)(unaff_EDI + iVar4 * 2) = asStack_28[*(byte *)(unaff_ESI + iVar4)];
      asStack_28[*(byte *)(unaff_ESI + iVar4)] = asStack_28[*(byte *)(unaff_ESI + iVar4)] + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1);
  }
  __security_check_cookie(local_4 ^ (uint)asStack_28);
  return;
}

