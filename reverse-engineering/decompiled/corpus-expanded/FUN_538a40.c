/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x538a40; label: FUN_00538a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00538a40(void)

{
  int iVar1;
  void *unaff_ESI;
  
  if (unaff_ESI != (void *)0x0) {
    iVar1 = FUN_004f1440((int)unaff_ESI + 0x18);
    while (iVar1 != 0) {
      FUN_00532220(iVar1);
      iVar1 = FUN_004f1440((int)unaff_ESI + 0x18);
    }
    FUN_004f1410(DAT_009238e4 + 0x4874);
    _memset(unaff_ESI,0,0x240);
    FUN_004f1310(DAT_009238e4 + 0x486c);
  }
  return;
}

