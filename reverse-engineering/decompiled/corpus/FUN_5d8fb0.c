/* Ghidra analysis pseudocode, not original source.
 * ev_9ed4b282d32238c814980953de36df9d2275b9d092f0f2c421c4dfd559b0e3dc
 * Entry: 0x5d8fb0; label: FUN_005d8fb0
 */

void FUN_005d8fb0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if ((*(int *)(param_1 + 0x14) == 0) || (DAT_0080ba14 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  *(uint *)(param_1 + 0x28) =
       *(uint *)(param_1 + 0x28) ^ (iVar1 << 4 ^ *(uint *)(param_1 + 0x28)) & 0x10;
  if ((*(byte *)(param_1 + 0x28) & 0x10) != 0) {
    DAT_00973988 = param_1;
    if (DAT_00973984 == 0) {
      FUN_005d86f0();
    }
    FUN_005d8950();
    uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x14) + 0x1c);
    while (uVar2 = uVar2 - 1, -1 < (int)uVar2) {
      FUN_005d8e20(*(undefined4 *)(param_1 + 0x14));
    }
  }
  return;
}

