/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d7960; label: FUN_006d7960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006d7960(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x4e10) == '\0') {
    *(undefined1 *)(in_ECX + 0x4e10) = 1;
    uVar1 = FUN_006d5990();
    *(undefined4 *)(in_ECX + 0x68b0) = uVar1;
  }
  return 1;
}

