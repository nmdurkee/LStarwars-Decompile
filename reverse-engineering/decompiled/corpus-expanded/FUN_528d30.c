/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x528d30; label: FUN_00528d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00528d30(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (((param_2 != 0) && (*(int *)(DAT_009238e4 + 0x371b0) != 0)) &&
     (iVar1 = FUN_004f1440(DAT_009238e4 + 0x383c0), iVar1 != 0)) {
    while (iVar2 != *(int *)(param_2 + 0xc)) {
      iVar2 = iVar2 + 1;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar1);
      if (iVar1 == 0) {
        return;
      }
    }
    *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x6c) = iVar1;
    *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x8f) = 1;
  }
  return;
}

