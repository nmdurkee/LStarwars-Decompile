/* Ghidra pseudocode, not original source.
 * ev_ed8379466d952c1ee28599ad459362d78654b4c0ec0ca4c18c489e481aca6c51
 * Entry: 0x6de800; label: FUN_006de800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006de800(void)

{
  undefined4 *puVar1;
  
  _DAT_0297ad2c = 1;
  DAT_0297ad74 = DAT_0297ad74 + 1;
  puVar1 = DAT_0297ad48;
  if (DAT_0297ad40 != 0) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      (*(code *)puVar1[2])();
    }
    _DAT_0297ad2c = 0;
    return 1;
  }
  _DAT_0297ad2c = 0;
  return 1;
}

