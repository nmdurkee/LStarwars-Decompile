/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522920; label: FUN_00522920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00522920(void)

{
  int iVar1;
  
  iVar1 = FUN_004f1440(DAT_009238e4 + 0x486c);
  if (iVar1 != 0) {
    FUN_004f1410(DAT_009238e4 + 0x486c,iVar1);
    FUN_004f1310(DAT_009238e4 + 0x4874,iVar1);
  }
  return iVar1;
}

