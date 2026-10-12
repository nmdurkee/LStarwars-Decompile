/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e8fe0; label: FUN_005e8fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e8fe0(void)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x54)) {
    do {
      FUN_005e8be0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x54));
  }
  *(undefined4 *)(in_ECX + 0xd8) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  return;
}

