/* Ghidra pseudocode, not original source.
 * ev_a5c3a3c7ef2e1a12e467fd0202ed50a9ce8374cc5ec0bfb4f993dbf776f2abbe
 * Entry: 0x41ab00; label: FUN_0041ab00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

