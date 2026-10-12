/* Ghidra pseudocode, not original source.
 * ev_a2aea1d641189bbcca45d714e231c7fbe07e1298025184ba29836f60d860e436
 * Entry: 0x5e77e0; label: FUN_005e77e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e77e0(void)

{
  int iVar1;
  char *in_ECX;
  
  if ((*in_ECX != '\0') && (in_ECX[1] != '\0')) {
    iVar1 = *(int *)(in_ECX + 0x154);
    *(undefined4 *)(in_ECX + 0x154) = *(undefined4 *)(in_ECX + 0x150);
    *(int *)(in_ECX + 0x150) = iVar1;
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined1 *)(iVar1 + 0x10) = 0;
    in_ECX[0x160] = '\0';
    in_ECX[0x161] = '\0';
    in_ECX[0x162] = '\0';
    in_ECX[0x163] = '\0';
    in_ECX[0x164] = '\0';
    in_ECX[0x165] = '\0';
    in_ECX[0x166] = '\0';
    in_ECX[0x167] = '\0';
  }
  return;
}

