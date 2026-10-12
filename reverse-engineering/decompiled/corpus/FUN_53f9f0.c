/* Ghidra analysis pseudocode, not original source.
 * ev_b277bc71922b23f31a72f43f26143bcec8a2b6e78604417b28dcc98660b92d0f
 * Entry: 0x53f9f0; label: FUN_0053f9f0
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

