/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x5686a0; label: FUN_005686a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005686a0(void)

{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(PTR_DAT_00802c54 + 0x50c8) != 0) && (0 < *(int *)(PTR_DAT_00802c54 + 0x50c0))) {
    iVar1 = *(int *)(PTR_DAT_00802c54 + 0x50c8);
    iVar2 = 0;
    if (0 < *(int *)(PTR_DAT_00802c54 + 0x50c0)) {
      do {
        *(undefined2 *)(iVar1 + 0x102) = 0xffff;
        *(undefined2 *)(iVar1 + 0x104) = 0xffff;
        if ((*(byte *)(iVar1 + 0x98) & 4) != 0) {
          FUN_00568580(iVar1);
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x114;
      } while (iVar2 < *(int *)(PTR_DAT_00802c54 + 0x50c0));
    }
  }
  return;
}

