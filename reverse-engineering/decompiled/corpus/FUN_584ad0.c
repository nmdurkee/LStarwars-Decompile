/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x584ad0; label: FUN_00584ad0
 */

int FUN_00584ad0(int param_1)

{
  int iVar1;
  uint *unaff_ESI;
  int iVar2;
  
  iVar2 = 0;
  *unaff_ESI = 0;
  iVar1 = FUN_004f7fb0(param_1);
  while (iVar1 != 0) {
    iVar1 = FUN_0055bac0(DAT_00954404,*(undefined4 *)(param_1 + 0x510));
    if (iVar1 != -1) {
      *unaff_ESI = *unaff_ESI | 1 << ((byte)iVar1 & 0x1f);
      iVar2 = iVar2 + 1;
    }
    iVar1 = FUN_004f7fb0(param_1);
  }
  return iVar2;
}

