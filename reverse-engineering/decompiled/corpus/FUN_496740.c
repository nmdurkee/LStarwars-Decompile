/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x496740; label: FUN_00496740
 */

void FUN_00496740(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (&DAT_0093d7f0)[iVar2];
    if (iVar1 == 0) {
      (&DAT_0087b6c4)[iVar2] = 0xffff;
      (&DAT_0087b6c8)[iVar2] = 0;
    }
    else {
      (&DAT_0087b6c4)[iVar2] = *(undefined2 *)(iVar1 + 0x1064);
      (&DAT_0087b6c8)[iVar2] = (byte)(*(uint *)(iVar1 + 0x1fc) >> 7) & 1;
    }
    (&DAT_0087b6ca)[iVar2] = 0;
    (&DAT_0087b6cc)[iVar2] = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  return;
}

