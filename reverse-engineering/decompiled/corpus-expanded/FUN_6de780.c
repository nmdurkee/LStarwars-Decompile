/* Ghidra pseudocode, not original source.
 * ev_ed8379466d952c1ee28599ad459362d78654b4c0ec0ca4c18c489e481aca6c51
 * Entry: 0x6de780; label: FUN_006de780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006de780(void)

{
  undefined4 *puVar1;
  
  _DAT_0297ad2c = 1;
  for (puVar1 = DAT_0297ad38; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    (*(code *)puVar1[2])();
  }
  _DAT_0297ad2c = 0;
  return 1;
}

