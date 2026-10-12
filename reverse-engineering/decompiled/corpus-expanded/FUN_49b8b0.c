/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49b8b0; label: FUN_0049b8b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049b8b0(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined1 extraout_AH;
  int iVar3;
  int unaff_EDI;
  float10 fVar4;
  float local_4;
  
  fVar4 = (float10)FUN_004999e0();
  local_4 = (float)fVar4;
  if (1.0 < local_4) {
    local_4 = 1.0;
  }
  fVar1 = local_4 * 0.75 + 0.75;
  if (fVar1 <= *(float *)(unaff_EDI + 0xdcc)) {
    uVar2 = 0x40400000;
  }
  else {
    uVar2 = 0x41000000;
  }
  fVar4 = (float10)FUN_0054fb40(*(undefined4 *)(unaff_EDI + 0xdcc),fVar1,uVar2);
  *(float *)(unaff_EDI + 0xdcc) = (float)fVar4;
  iVar3 = 0;
  do {
    FUN_0054fa60();
    *(undefined1 *)(unaff_EDI + 0xe28 + iVar3) = extraout_AH;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}

