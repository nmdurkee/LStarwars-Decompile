/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x5892e0; label: FUN_005892e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005892e0(void)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar3;
  
  iVar2 = FUN_004f7fb0();
  if (iVar2 != 0) {
    fVar3 = (float10)FUN_004f28e0(*(undefined4 *)(unaff_ESI + 0x510));
    iVar2 = FUN_004f7fb0();
    if (iVar2 != 0) {
      uVar1 = FUN_004f29a0(*(undefined4 *)(unaff_ESI + 0x510));
      *(float *)(DAT_00954404 + 0xbc + unaff_EDI * 4) = (float)fVar3;
      *(undefined1 *)(DAT_00954404 + 0xcc + unaff_EDI) = uVar1;
      _DAT_0095440c = _DAT_0095440c | 0x10;
    }
  }
  return;
}

