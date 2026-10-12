/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55ac80; label: FUN_0055ac80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055ac80(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 4) != 0)) && (unaff_EDI != 0)) {
    iVar1 = FUN_004f1ff0(*(int *)(param_1 + 4));
    iVar2 = FUN_004f1ff0();
    if (iVar2 + iVar1 <= DAT_00802724) {
      FUN_004f1ec0(*(undefined4 *)(param_1 + 4));
      return;
    }
    *(ushort *)(param_1 + 8) = *(ushort *)(param_1 + 8) | 1;
  }
  return;
}

