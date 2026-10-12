/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x525b80; label: FUN_00525b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00525b80(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar1 != 0;
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1)) {
      for (iVar2 = FUN_004f1440(*(int *)(DAT_009238e4 + 0x4868) + 0x18); iVar2 != 0;
          iVar2 = FUN_004f1460(*(int *)(DAT_009238e4 + 0x4868) + 0x18,iVar2)) {
        if (*(int *)(iVar2 + 0xb0) == unaff_EDI) {
          *(undefined4 *)(iVar2 + 0xb0) = 0;
          break;
        }
      }
    }
    FUN_004f1410(DAT_009238e4 + 0x31b8c);
    FUN_004f1310(DAT_009238e4 + 0x31b84);
  }
  return;
}

