/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f9f0; label: FUN_0053f9f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053f9f0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f7fb0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00757894);
    if (iVar1 == 0) {
      *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) | 2;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007614f4);
    if (iVar1 == 0) {
      *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) | 4;
      return;
    }
    iVar1 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),
                         &PTR_u_ERROR_DS_COULDNT_CONTACT_FSMO_007614f0);
    if (iVar1 == 0) {
      *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) | 4;
      *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) ^ 4;
    }
  }
  return;
}

