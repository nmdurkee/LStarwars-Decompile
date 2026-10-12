/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403e70; label: FUN_00403e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00403e70(void)

{
  int iVar1;
  uint uVar2;
  int *in_EDX;
  int unaff_ESI;
  
  uVar2 = (uint)*(byte *)(in_EDX + 0x1f);
  iVar1 = 0;
  if (uVar2 != 0) {
    do {
      if (*in_EDX == unaff_ESI) break;
      iVar1 = iVar1 + 1;
      in_EDX = in_EDX + 5;
    } while (iVar1 < (int)uVar2);
  }
  return iVar1 < (int)uVar2;
}

