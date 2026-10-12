/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x55ac80; label: FUN_0055ac80
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

