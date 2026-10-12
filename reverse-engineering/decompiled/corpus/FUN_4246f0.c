/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x4246f0; label: FUN_004246f0
 */

void FUN_004246f0(undefined4 *param_1,undefined4 *param_2)

{
  if (DAT_0087b6c8 == '\0') {
    if (DAT_0087b6c9 != '\0') {
      *param_1 = 1;
      *param_2 = 1;
      return;
    }
  }
  else if (DAT_0087b6c9 == '\0') {
    *param_1 = 0;
    *param_2 = 1;
    return;
  }
  *param_1 = 0;
  *param_2 = 2;
  return;
}

