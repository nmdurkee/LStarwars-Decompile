/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x6057c0; label: FUN_006057c0
 */

undefined4 FUN_006057c0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_005e5310(param_1);
  if (0xf < (uint)((iVar1 + -0x2855050) / 0x30)) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 0x28);
}

