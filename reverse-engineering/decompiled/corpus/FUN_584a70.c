/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x584a70; label: FUN_00584a70
 */

int FUN_00584a70(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  *unaff_ESI = 0;
  iVar1 = FUN_004f7fb0(param_1);
  while (iVar1 != 0) {
    uVar2 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    if (uVar2 < 0x20) {
      *unaff_ESI = *unaff_ESI | 1 << ((byte)uVar2 & 0x1f);
      iVar3 = iVar3 + 1;
    }
    iVar1 = FUN_004f7fb0(param_1);
  }
  return iVar3;
}

