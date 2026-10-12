/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f2580; label: FUN_005f2580
 */

void FUN_005f2580(void)

{
  int *piVar1;
  
  if (-1 < DAT_0080bbb0) {
    piVar1 = (int *)((int)DAT_0080bbb4 + 0x24 + DAT_0080bbb0 * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  DAT_0080bbb4 = &DAT_00978480;
  DAT_0080bbb0 = FUN_005c51c0("postEffect.outFramebuffer",0);
  if (-1 < DAT_0080bbb8) {
    piVar1 = (int *)((int)DAT_0080bbbc + 0x24 + DAT_0080bbb8 * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  DAT_0080bbbc = &DAT_00978480;
  DAT_0080bbb8 = FUN_005c51c0("postEffect.colorBuffer",0);
  if (-1 < DAT_0080bbc0) {
    piVar1 = (int *)((int)DAT_0080bbc4 + 0x24 + DAT_0080bbc0 * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  DAT_0080bbc4 = &DAT_00978480;
  DAT_0080bbc0 = FUN_005c51c0("postEffect.normalBuffer",0);
  if (-1 < DAT_0080bbc8) {
    piVar1 = (int *)((int)DAT_0080bbcc + 0x24 + DAT_0080bbc8 * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  DAT_0080bbcc = &DAT_00978480;
  DAT_0080bbc8 = FUN_005c51c0("postEffect.velocityBuffer",0);
  if (-1 < DAT_0080bbd0) {
    piVar1 = (int *)((int)DAT_0080bbd4 + 0x24 + DAT_0080bbd0 * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  DAT_0080bbd4 = &DAT_00978480;
  DAT_0080bbd0 = FUN_005c51c0("postEffect.depthRTBuffer",0);
  if (-1 < DAT_0080bbd8) {
    piVar1 = (int *)((int)DAT_0080bbdc + 0x24 + DAT_0080bbd8 * 0x28);
    *piVar1 = *piVar1 + -1;
  }
  DAT_0080bbdc = &DAT_00978480;
  DAT_0080bbd8 = FUN_005c51c0("postEffect.depthBuffer",0);
  DAT_00973830 = FUN_00605a10();
  DAT_00973834 = FUN_00605a10();
  return;
}

