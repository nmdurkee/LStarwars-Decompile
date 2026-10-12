/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x530e50; label: FUN_00530e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00530e50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
  while (iVar1 = iVar2, iVar1 != 0) {
    iVar2 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar1);
    if ((((*(int *)(iVar1 + 0x30) == param_1) || (*(int *)(iVar1 + 0x34) == param_1)) &&
        (FUN_00524900(iVar1 + 0x18,(int *)(iVar1 + 0x28),*(undefined4 *)(DAT_009238e4 + 0x4868),0),
        *(int *)(iVar1 + 0x28) == 0)) && (FUN_00530dd0(), iVar1 == *(int *)(DAT_009238e4 + 0x3cbe0))
       ) {
      *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = 0;
    }
  }
  return;
}

