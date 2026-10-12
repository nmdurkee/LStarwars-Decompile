/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d54c0; label: FUN_004d54c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004d54c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((((*(uint *)(iVar1 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0)) &&
          (*(char *)(iVar1 + 0x28b) == '\0')) &&
         ((((*(uint *)(*(int *)(*(int *)(iVar1 + 0x54) + 0x24) + 0x90) & 0x1000000) != 0 &&
           (0.0 < *(float *)(iVar1 + 0xd80))) &&
          ((0.0 < *(float *)(iVar1 + 0xd8c) && (*(int *)(iVar1 + 0xd14) == param_1)))))) {
        return iVar1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10d8;
    } while (iVar2 < DAT_0093d500);
  }
  return 0;
}

