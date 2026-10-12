/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41ab00; label: FUN_0041ab00
 */

void FUN_0041ab00(void)

{
  int iVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x1048) = 0;
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) | 1 << ((&DAT_007f26fc)[iVar1 / 0x5556] & 0x1f);
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) | 1 << ((&DAT_007f26f8)[iVar1 / 0x5556] & 0x1f);
  iVar1 = FUN_0054fa60();
  *(uint *)(unaff_ESI + 0x1048) =
       *(uint *)(unaff_ESI + 0x1048) | 1 << ((&DAT_007f26f4)[iVar1 / 0x5556] & 0x1f);
  return;
}

