/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d5ce0; label: FUN_006d5ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d5ce0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    if (param_1 < 0) {
      return;
    }
    iVar2 = param_1 * 0x17c + 0x4ea2;
  }
  else {
    iVar2 = param_3 * 0x80 + 0x6358;
  }
  iVar2 = iVar2 + DAT_02975144;
  iVar1 = 0;
  do {
    *(undefined1 *)(iVar2 + iVar1 * 4) = 0;
    *(undefined2 *)(iVar2 + 2 + iVar1 * 4) = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return;
}

